#include "encoding_registration.hpp"
#include "encoding_registrar.hpp"
#include "encodings_dataset.hpp"

#include "duckdb_cpp.hpp"
#include "zstd.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstring>
#include <limits>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

namespace duckdb {
namespace duckdb_encodings {

//! The schema of the system catalog that holds the functions of the encodings
static const char *const SCHEMA = "encodings";

//! Encoding Map Entry Struct used for byte replacement
struct map_entry_encoding {
	size_t key_len;
	const char *key;
	size_t value_len;
	const char *value;
};

//! Index over a (sorted) conversion map: for every possible first byte, the single-byte entry that starts with it
//! (if any) and the contiguous range of multi-byte entries that start with it. This turns the per-byte binary search
//! over the whole table into a single array lookup for single-byte sequences (e.g. all of ASCII), and a search over
//! only the entries sharing the lead byte otherwise.
struct EncodingIndex {
	const map_entry_encoding *single[256] = {};
	uint32_t multi_begin[256] = {};
	uint32_t multi_end[256] = {};

	EncodingIndex(const map_entry_encoding *map, size_t map_size) {
		for (uint32_t i = 0; i < map_size; i++) {
			const auto &entry = map[i];
			const auto first = static_cast<uint8_t>(entry.key[0]);
			if (entry.key_len == 1) {
				single[first] = &entry;
				continue;
			}
			// The map is sorted by key, so all multi-byte entries with the same first byte are contiguous
			if (multi_end[first] == multi_begin[first]) {
				multi_begin[first] = i;
			}
			multi_end[first] = i + 1;
		}
	}

	bool HasMultiByte(uint8_t first) const {
		return multi_end[first] > multi_begin[first];
	}
};

//! Lookup tables for the common cases of decoding, built on top of the index
struct DecodeTables {
	//! What a byte that starts no multi-byte sequence decodes to: its single-byte entry, or the byte itself if it has
	//! none
	char value[256][4] = {};
	uint8_t length[256] = {};
	//! The ASCII bytes that decode to themselves
	bool ascii_identity[256] = {};
	//! The other ASCII bytes, broadcast to every byte of a word. Runs of ASCII are copied 8 bytes at a time if there
	//! are only a few of them.
	uint64_t ascii_exceptions[4] = {};
	size_t ascii_exception_count = 0;
	bool copy_ascii_words = false;
	//! For a lead byte that starts multi-byte sequences: the offset of its 256 slots in pairs
	uint32_t pair_offset[256] = {};
	//! Per lead byte and second byte: 1 + the index in the map of the two-byte entry, or 0 if there is none
	std::vector<uint32_t> pairs;

	DecodeTables(const EncodingIndex &index, const map_entry_encoding *map) {
		size_t exception_count = 0;
		for (uint32_t byte = 0; byte < 256; byte++) {
			const auto entry = index.single[byte];
			if (entry) {
				std::memcpy(value[byte], entry->value, entry->value_len);
				length[byte] = static_cast<uint8_t>(entry->value_len);
			} else {
				value[byte][0] = static_cast<char>(byte);
				length[byte] = 1;
			}
			if (byte >= 0x80) {
				continue;
			}
			if (!index.HasMultiByte(static_cast<uint8_t>(byte)) && length[byte] == 1 &&
			    static_cast<uint8_t>(value[byte][0]) == byte) {
				ascii_identity[byte] = true;
			} else {
				if (exception_count < 4) {
					ascii_exceptions[exception_count] = 0x0101010101010101ULL * byte;
				}
				exception_count++;
			}
		}
		copy_ascii_words = exception_count <= 4;
		ascii_exception_count = copy_ascii_words ? exception_count : 0;

		pairs.push_back(0);
		for (uint32_t first = 0; first < 256; first++) {
			if (!index.HasMultiByte(static_cast<uint8_t>(first))) {
				continue;
			}
			pair_offset[first] = static_cast<uint32_t>(pairs.size());
			pairs.resize(pairs.size() + 256, 0);
			for (uint32_t i = index.multi_begin[first]; i < index.multi_end[first]; i++) {
				auto &slot = pairs[pair_offset[first] + static_cast<uint8_t>(map[i].key[1])];
				if (map[i].key_len == 2 && slot == 0) {
					slot = i + 1;
				}
			}
		}
	}

	//! Whether all 8 bytes of the word are ASCII that decodes to itself
	bool IsIdentityWord(uint64_t word) const {
		if (word & 0x8080808080808080ULL) {
			return false;
		}
		for (size_t i = 0; i < ascii_exception_count; i++) {
			// Whether a byte of the word equals the exception, see "Determine if a word has a zero byte"
			const auto diff = word ^ ascii_exceptions[i];
			if ((diff - 0x0101010101010101ULL) & ~diff & 0x8080808080808080ULL) {
				return false;
			}
		}
		return true;
	}
};

static bool KeyLess(const char *a, size_t a_len, const char *b, size_t b_len) {
	const size_t min_len = std::min(a_len, b_len);
	const int cmp = std::memcmp(a, b, min_len);
	if (cmp != 0) {
		return cmp < 0;
	}
	return a_len < b_len;
}

//! The inverse of a conversion map: the entries sorted by their UTF-8 value, with a range per first byte. Of several
//! byte sequences that decode to the same value, the smallest is used.
struct ReverseIndex {
	std::vector<const map_entry_encoding *> entries;
	uint32_t begin[256] = {};
	uint32_t end[256] = {};
	size_t max_value_len = 1;

	ReverseIndex(const map_entry_encoding *map, size_t map_size) {
		for (size_t i = 0; i < map_size; i++) {
			entries.push_back(&map[i]);
			max_value_len = std::max(max_value_len, map[i].value_len);
		}
		std::stable_sort(entries.begin(), entries.end(), [](const map_entry_encoding *a, const map_entry_encoding *b) {
			return KeyLess(a->value, a->value_len, b->value, b->value_len);
		});
		for (uint32_t i = 0; i < entries.size(); i++) {
			const auto first = static_cast<uint8_t>(entries[i]->value[0]);
			if (end[first] == begin[first]) {
				begin[first] = i;
			}
			end[first] = i + 1;
		}
	}
};

//===--------------------------------------------------------------------===//
// The dataset
//===--------------------------------------------------------------------===//
//! What the dataset says about a table, see scripts/converter.py for the layout
struct TableRecord {
	uint32_t offset;
	uint32_t size;
	uint32_t map_size;
	uint32_t lookup_bytes;
	uint32_t max_output_bytes;
};

struct EncodingName {
	uint32_t table;
	std::string name;
};

[[noreturn]] static void ThrowCorrupt() {
	throw cxx::InvalidInputException("Corrupt encodings dataset");
}

//! A conversion table of the dataset, shared by every name it is registered under. All tables are compressed together,
//! so a table is unpacked the first time it is needed (when a query that uses it is bound): the frame is decompressed,
//! the table is expanded, and the decompressed frame is dropped again.
class EncodingTable {
public:
	EncodingTable(const TableRecord &record, const unsigned char *frame, size_t frame_size, size_t content_size)
	    : lookup_bytes(record.lookup_bytes), max_output_bytes(record.max_output_bytes), map_size(record.map_size),
	      record(record), frame(frame), frame_size(frame_size), content_size(content_size) {
	}

	//! Unpacks the table and builds the index to decode with, if that has not happened yet
	const EncodingIndex &GetIndex() {
		std::call_once(index_flag, [&]() {
			Unpack();
			index = std::make_unique<EncodingIndex>(entries.data(), entries.size());
			decode_tables = std::make_unique<DecodeTables>(*index, entries.data());
		});
		return *index;
	}

	const DecodeTables &GetDecodeTables() {
		GetIndex();
		return *decode_tables;
	}

	const map_entry_encoding *Map() {
		GetIndex();
		return entries.data();
	}

	//! The index to encode with, built if that has not happened yet
	const ReverseIndex &GetReverseIndex() {
		std::call_once(reverse_flag, [&]() { reverse = std::make_unique<ReverseIndex>(Map(), map_size); });
		return *reverse;
	}

public:
	//! The maximum number of input bytes that make up a single character
	size_t lookup_bytes;
	//! The maximum number of UTF-8 bytes produced for one byte sequence of the encoding
	size_t max_output_bytes;
	size_t map_size;

private:
	static uint64_t ReadVarint(const unsigned char *&pos, const unsigned char *end) {
		uint64_t result = 0;
		for (uint32_t shift = 0; shift < 64 && pos != end; shift += 7) {
			const auto byte = *pos++;
			result |= static_cast<uint64_t>(byte & 0x7f) << shift;
			if (!(byte & 0x80)) {
				return result;
			}
		}
		ThrowCorrupt();
	}

	static int64_t ReadSignedVarint(const unsigned char *&pos, const unsigned char *end) {
		const auto value = ReadVarint(pos, end);
		return (value & 1) ? -static_cast<int64_t>((value + 1) >> 1) : static_cast<int64_t>(value >> 1);
	}

	static size_t WriteUTF8(uint32_t value, char *target) {
		if (value < 0x80) {
			target[0] = static_cast<char>(value);
			return 1;
		}
		if (value < 0x800) {
			target[0] = static_cast<char>(0xC0 | (value >> 6));
			target[1] = static_cast<char>(0x80 | (value & 0x3F));
			return 2;
		}
		if (value < 0x10000) {
			target[0] = static_cast<char>(0xE0 | (value >> 12));
			target[1] = static_cast<char>(0x80 | ((value >> 6) & 0x3F));
			target[2] = static_cast<char>(0x80 | (value & 0x3F));
			return 3;
		}
		target[0] = static_cast<char>(0xF0 | (value >> 18));
		target[1] = static_cast<char>(0x80 | ((value >> 12) & 0x3F));
		target[2] = static_cast<char>(0x80 | ((value >> 6) & 0x3F));
		target[3] = static_cast<char>(0x80 | (value & 0x3F));
		return 4;
	}

	void Unpack() {
		std::vector<unsigned char> content(content_size);
		const auto decompressed = duckdb_zstd::ZSTD_decompress(content.data(), content.size(), frame, frame_size);
		if (duckdb_zstd::ZSTD_isError(decompressed) || decompressed != content_size ||
		    static_cast<size_t>(record.offset) + record.size > content_size || record.size < 4) {
			ThrowCorrupt();
		}

		const auto end = content.data() + record.offset + record.size;
		auto pos = static_cast<const unsigned char *>(content.data() + record.offset);
		uint32_t key_deltas_size;
		std::memcpy(&key_deltas_size, pos, sizeof(key_deltas_size)); // little endian, like every supported platform
		pos += sizeof(key_deltas_size);
		const auto key_lengths = pos;
		if (static_cast<size_t>(end - pos) < static_cast<size_t>(record.map_size) + key_deltas_size) {
			ThrowCorrupt();
		}
		auto key_deltas = key_lengths + record.map_size;
		auto value_deltas = key_deltas + key_deltas_size;
		const auto key_deltas_end = value_deltas;

		// Every entry has a key of up to 8 bytes and a UTF-8 value of up to 4 bytes
		bytes.resize(static_cast<size_t>(record.map_size) * 12);
		entries.reserve(record.map_size);
		auto target = bytes.data();
		int64_t key = 0;
		int64_t value = 0;
		for (size_t i = 0; i < record.map_size; i++) {
			const auto key_length = key_lengths[i];
			key += ReadSignedVarint(key_deltas, key_deltas_end);
			value += ReadSignedVarint(value_deltas, end);
			if (key_length == 0 || key_length > 8 || value < 0 || value > 0x10FFFF) {
				ThrowCorrupt();
			}
			map_entry_encoding entry;
			entry.key_len = key_length;
			entry.key = target;
			for (size_t byte = 0; byte < key_length; byte++) {
				*target++ = static_cast<char>((static_cast<uint64_t>(key) >> (8 * (key_length - 1 - byte))) & 0xff);
			}
			entry.value = target;
			entry.value_len = WriteUTF8(static_cast<uint32_t>(value), target);
			target += entry.value_len;
			entries.push_back(entry);
		}
	}

private:
	TableRecord record;
	const unsigned char *frame;
	size_t frame_size;
	size_t content_size;

	//! The entries, sorted by key; their keys and values point into `bytes`
	std::vector<map_entry_encoding> entries;
	std::vector<char> bytes;
	std::once_flag index_flag;
	std::unique_ptr<EncodingIndex> index;
	std::unique_ptr<DecodeTables> decode_tables;
	std::once_flag reverse_flag;
	std::unique_ptr<ReverseIndex> reverse;
};

using EncodingTablePtr = std::shared_ptr<EncodingTable>;

//! The tables and names of the dataset, shared by all databases the extension is loaded into
class EncodingsDataset {
public:
	EncodingsDataset() {
		const auto end = ENCODINGS_DATASET + ENCODINGS_DATASET_SIZE;
		auto pos = ENCODINGS_DATASET;
		if (ENCODINGS_DATASET_SIZE < 8 || std::memcmp(pos, "DKENC001", 8) != 0) {
			ThrowCorrupt();
		}
		pos += 8;
		const auto table_count = ReadU32(pos, end);
		const auto name_count = ReadU32(pos, end);
		const auto content_size = ReadU32(pos, end);
		std::vector<TableRecord> records;
		for (size_t i = 0; i < table_count; i++) {
			TableRecord record;
			record.offset = ReadU32(pos, end);
			record.size = ReadU32(pos, end);
			record.map_size = ReadU32(pos, end);
			const auto sizes = ReadU32(pos, end);
			record.lookup_bytes = sizes & 0xff;
			record.max_output_bytes = (sizes >> 8) & 0xff;
			records.push_back(record);
		}
		for (size_t i = 0; i < name_count; i++) {
			const auto table = ReadU32(pos, end);
			if (end - pos < 2 || table >= table_count) {
				ThrowCorrupt();
			}
			uint16_t length;
			std::memcpy(&length, pos, sizeof(length));
			pos += sizeof(length);
			if (static_cast<size_t>(end - pos) < length) {
				ThrowCorrupt();
			}
			names.push_back({table, std::string(reinterpret_cast<const char *>(pos), length)});
			pos += length;
		}
		for (auto &record : records) {
			tables.push_back(
			    std::make_shared<EncodingTable>(record, pos, static_cast<size_t>(end - pos), content_size));
		}
	}

	std::vector<EncodingName> names;
	std::vector<EncodingTablePtr> tables;

private:
	static uint32_t ReadU32(const unsigned char *&pos, const unsigned char *end) {
		if (end - pos < 4) {
			ThrowCorrupt();
		}
		uint32_t result;
		std::memcpy(&result, pos, sizeof(result)); // the dataset is little endian, like every supported platform
		pos += sizeof(result);
		return result;
	}
};

static EncodingsDataset &GetDataset() {
	static EncodingsDataset dataset;
	return dataset;
}

//===--------------------------------------------------------------------===//
// Decoding and encoding
//===--------------------------------------------------------------------===//
struct MapEntryComparator {
	bool operator()(const map_entry_encoding &entry, const std::pair<const char *, size_t> &key) const {
		return KeyLess(entry.key, entry.key_len, key.first, key.second);
	}
};

static const map_entry_encoding *FindEntry(const map_entry_encoding *map, size_t map_size, const char *search_key,
                                           size_t search_len) {
	const auto it =
	    std::lower_bound(map, map + map_size, std::make_pair(search_key, search_len), MapEntryComparator {});
	if (it != map + map_size && it->key_len == search_len && std::memcmp(it->key, search_key, search_len) == 0) {
		return it;
	}
	return nullptr;
}

//! Decodes a prefix of the input to UTF-8 into `output`, which has room for input_size * max_output_bytes bytes.
//! Unless is_last is set, an incomplete trailing character is left unconsumed.
static void DecodePrefix(EncodingTable &table, const char *input, size_t input_size, bool is_last, char *output,
                         size_t &consumed, size_t &written) {
	const auto &index = table.GetIndex();
	const auto &tables = table.GetDecodeTables();
	const auto map = table.Map();
	const auto lookup_bytes = table.lookup_bytes;
	// Unless this is the end of the input, a character that starts in the last lookup_bytes - 1 bytes may be
	// incomplete: those bytes are handed back by the caller with the next ones
	size_t decode_end = input_size;
	if (!is_last) {
		decode_end = input_size >= lookup_bytes ? input_size - lookup_bytes + 1 : 0;
	}
	size_t pos = 0;
	size_t out = 0;
	while (pos < decode_end) {
		const char *current = input + pos;
		const auto first = static_cast<uint8_t>(*current);
		if (tables.ascii_identity[first]) {
			// Copy the run of ASCII this starts, 8 bytes at a time if possible
			if (tables.copy_ascii_words) {
				while (pos + 8 <= decode_end) {
					uint64_t word;
					std::memcpy(&word, input + pos, sizeof(word));
					if (!tables.IsIdentityWord(word)) {
						break;
					}
					std::memcpy(output + out, &word, sizeof(word));
					pos += 8;
					out += 8;
				}
			}
			while (pos < decode_end && tables.ascii_identity[static_cast<uint8_t>(input[pos])]) {
				output[out++] = input[pos++];
			}
			continue;
		}
		const map_entry_encoding *match = nullptr;
		size_t match_len = 1;
		if (index.HasMultiByte(first)) {
			// Prefer the longest matching byte sequence
			const size_t available = input_size - pos;
			const auto candidates = map + index.multi_begin[first];
			const size_t candidate_count = index.multi_end[first] - index.multi_begin[first];
			for (size_t len = std::min(lookup_bytes, available); len > 2; len--) {
				match = FindEntry(candidates, candidate_count, current, len);
				if (match) {
					match_len = len;
					break;
				}
			}
			if (!match && available >= 2) {
				const auto pair = tables.pairs[tables.pair_offset[first] + static_cast<uint8_t>(current[1])];
				if (pair) {
					match = map + pair - 1;
					match_len = 2;
				}
			}
		}
		if (!match) {
			// Decode the byte on its own, or pass it through if it has no entry
			const auto length = tables.length[first];
			std::memcpy(output + out, tables.value[first], length);
			out += length;
			pos++;
			continue;
		}
		std::memcpy(output + out, match->value, match->value_len);
		out += match->value_len;
		pos += match_len;
	}
	consumed = pos;
	written = out;
}

//! Encodes UTF-8 input into `output`, which has room for input_size * lookup_bytes bytes. Throws if the input has a
//! character the encoding cannot represent.
static size_t EncodeAll(EncodingTable &table, const std::string &name, const char *input, size_t input_size,
                        char *output) {
	const auto &index = table.GetReverseIndex();
	size_t pos = 0;
	size_t out = 0;
	while (pos < input_size) {
		const auto first = static_cast<uint8_t>(input[pos]);
		const auto bucket_begin = index.entries.begin() + index.begin[first];
		const auto bucket_end = index.entries.begin() + index.end[first];
		const map_entry_encoding *match = nullptr;
		// Prefer the longest matching UTF-8 sequence
		for (size_t len = std::min(index.max_value_len, input_size - pos); len > 0 && !match; len--) {
			const auto it = std::lower_bound(
			    bucket_begin, bucket_end, std::make_pair(input + pos, len),
			    [](const map_entry_encoding *entry, const std::pair<const char *, size_t> &key) {
				    return KeyLess(entry->value, entry->value_len, key.first, key.second);
			    });
			if (it != bucket_end && (*it)->value_len == len && std::memcmp((*it)->value, input + pos, len) == 0) {
				match = *it;
			}
		}
		if (!match) {
			throw cxx::InvalidInputException("Could not encode the character at byte " + std::to_string(pos) + " in " +
			                                 name);
		}
		std::memcpy(output + out, match->key, match->key_len);
		out += match->key_len;
		pos += match->value_len;
	}
	return out;
}

//! The state of one name of an encoding: the table, and the name for error messages.
struct EncodingFunctionData {
	EncodingTablePtr table;
	std::string name;
};

//! Decodes a blob straight into the heap of the result vector. The heap is sized for the worst case, which suits the
//! few large slices of a stream rather than many small rows.
static cxx::varchar_t DecodeIntoHeap(cxx::Arena &heap, EncodingTable &table, const cxx::blob_t &blob, bool is_last,
                                     size_t &consumed) {
	const auto capacity = blob.size() * table.max_output_bytes;
	char inline_buffer[cxx::varchar_t::INLINE_LENGTH];
	char *target =
	    capacity <= sizeof(inline_buffer) ? inline_buffer : reinterpret_cast<char *>(heap.Allocate(capacity));
	size_t written = 0;
	DecodePrefix(table, blob.data(), blob.size(), is_last, target, consumed, written);
	if (written > (std::numeric_limits<uint32_t>::max)()) {
		throw cxx::InvalidInputException("The decoded string exceeds the maximum string length");
	}
	return cxx::varchar_t(target, static_cast<uint32_t>(written));
}

//! Unpacks the table once the query is bound, rather than while it runs
static void BindDecode(cxx::ScalarFunction::BindInput &input) {
	input.GetUserData<EncodingFunctionData>().table->GetIndex();
}

static void BindEncode(cxx::ScalarFunction::BindInput &input) {
	input.GetUserData<EncodingFunctionData>().table->GetReverseIndex();
}

//! system.encodings."<name>"(BLOB) -> VARCHAR: decodes the complete input
static void DecodeAllExec(cxx::ScalarFunction::ExecInput &input) {
	auto &data = input.GetUserData<EncodingFunctionData>();
	auto &table = *data.table;
	const auto count = input.GetRowCount();
	const auto blobs = input.GetArg(0).GetView();
	auto result = input.GetResult();
	auto mask = result.GetValidityMutable();
	mask.SetAllValid(count);

	std::string buffer;
	for (cxx::idx_t row = 0; row < count; row++) {
		if (!blobs.IsValid(row)) {
			mask.SetInvalid(row);
			continue;
		}
		const auto &blob = blobs.Data<cxx::blob_t>()[blobs.SelAt(row)];
		buffer.resize(std::max<size_t>(blob.size() * table.max_output_bytes, 1));
		size_t consumed = 0;
		size_t written = 0;
		DecodePrefix(table, blob.data(), blob.size(), true, &buffer[0], consumed, written);
		result.AssignStringUnsafe(row, std::string_view(buffer.data(), written));
	}
}

//! system.encodings."<name>"(BLOB, BOOLEAN is_last) -> STRUCT(decoded VARCHAR, consumed BIGINT): decodes a prefix of a
//! stream
static void DecodeStreamExec(cxx::ScalarFunction::ExecInput &input) {
	auto &data = input.GetUserData<EncodingFunctionData>();
	auto &table = *data.table;
	const auto count = input.GetRowCount();
	const auto blobs = input.GetArg(0).GetView();
	const auto is_last = input.GetArg(1).GetView();
	auto result = input.GetResult();
	auto decoded = result.GetChild(0);
	auto consumed_vector = result.GetChild(1);
	auto consumed_data = consumed_vector.GetDataMutable<int64_t>();
	auto struct_mask = result.GetValidityMutable();
	auto decoded_mask = decoded.GetValidityMutable();
	auto consumed_mask = consumed_vector.GetValidityMutable();
	struct_mask.SetAllValid(count);
	decoded_mask.SetAllValid(count);
	consumed_mask.SetAllValid(count);

	auto heap = decoded.GetHeap();
	for (cxx::idx_t row = 0; row < count; row++) {
		if (!blobs.IsValid(row) || !is_last.IsValid(row)) {
			struct_mask.SetInvalid(row);
			decoded_mask.SetInvalid(row);
			consumed_mask.SetInvalid(row);
			continue;
		}
		const auto &blob = blobs.Data<cxx::blob_t>()[blobs.SelAt(row)];
		const bool last = is_last.Data<bool>()[is_last.SelAt(row)];
		size_t consumed = 0;
		decoded.SetString(row, DecodeIntoHeap(heap, table, blob, last, consumed));
		consumed_data[row] = static_cast<int64_t>(consumed);
	}
}

//! system.encodings."<name>"(VARCHAR) -> BLOB: encodes the input
static void EncodeExec(cxx::ScalarFunction::ExecInput &input) {
	auto &data = input.GetUserData<EncodingFunctionData>();
	auto &table = *data.table;
	const auto count = input.GetRowCount();
	const auto strings = input.GetArg(0).GetView();
	auto result = input.GetResult();
	auto mask = result.GetValidityMutable();
	mask.SetAllValid(count);

	std::string buffer;
	for (cxx::idx_t row = 0; row < count; row++) {
		if (!strings.IsValid(row)) {
			mask.SetInvalid(row);
			continue;
		}
		const auto &string = strings.Data<cxx::varchar_t>()[strings.SelAt(row)];
		buffer.resize(std::max<size_t>(string.size() * table.lookup_bytes, 1));
		const auto written = EncodeAll(table, data.name, string.data(), string.size(), &buffer[0]);
		result.AssignString(row, std::string_view(buffer.data(), written));
	}
}

//===--------------------------------------------------------------------===//
// Registration
//===--------------------------------------------------------------------===//
static std::mutex &RegisteredLock() {
	static std::mutex lock;
	return lock;
}

//! By name: the extension registers the same encodings in every database it is loaded into
static std::map<std::string, RegisteredEncoding> &Registered() {
	static std::map<std::string, RegisteredEncoding> registered;
	return registered;
}

std::vector<RegisteredEncoding> GetRegisteredEncodings() {
	std::lock_guard<std::mutex> guard(RegisteredLock());
	std::vector<RegisteredEncoding> result;
	for (auto &entry : Registered()) {
		result.push_back(entry.second);
	}
	return result;
}

static std::string Lowercase(const std::string &name) {
	std::string result = name;
	std::transform(result.begin(), result.end(), result.begin(),
	               [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
	return result;
}

//! The functions of an encoding are named after it, in lowercase, in the encodings schema
static void RegisterName(EncodingRegistrar &registrar, const std::string &name, const EncodingTablePtr &table) {
	auto &factory = registrar.factory;
	const auto blob = factory.ParseType("BLOB");
	const auto varchar = factory.ParseType("VARCHAR");
	const auto boolean = factory.ParseType("BOOLEAN");
	const auto stream_result = factory.ParseType("STRUCT(decoded VARCHAR, consumed BIGINT)");
	const auto function_name = Lowercase(name);

	auto decode_all = cxx::ScalarFunction::Create(factory);
	decode_all.SetName(function_name).SetSchema(SCHEMA).SetBindCallback(BindDecode).SetExecCallback(DecodeAllExec);
	decode_all.GetSignature().AddParameter("data", blob).SetReturnType(varchar);
	decode_all.SetUserData<EncodingFunctionData>(EncodingFunctionData {table, name});
	registrar.extension.Register(decode_all);

	auto decode_stream = cxx::ScalarFunction::Create(factory);
	decode_stream.SetName(function_name).SetSchema(SCHEMA).SetBindCallback(BindDecode).SetExecCallback(
	    DecodeStreamExec);
	decode_stream.GetSignature().AddParameter("data", blob).AddParameter("is_last", boolean).SetReturnType(
	    stream_result);
	decode_stream.SetUserData<EncodingFunctionData>(EncodingFunctionData {table, name});
	registrar.extension.Register(decode_stream);

	auto encode = cxx::ScalarFunction::Create(factory);
	encode.SetName(function_name).SetSchema(SCHEMA).SetBindCallback(BindEncode).SetExecCallback(EncodeExec);
	encode.GetSignature().AddParameter("string", varchar).SetReturnType(blob);
	encode.SetUserData<EncodingFunctionData>(EncodingFunctionData {table, name});
	registrar.extension.Register(encode);

	std::lock_guard<std::mutex> guard(RegisteredLock());
	Registered()[function_name] = {function_name, table->lookup_bytes, table->max_output_bytes, table->map_size};
}

void RegisterEncodings(EncodingRegistrar &registrar) {
	auto &dataset = GetDataset();
	for (auto &name : dataset.names) {
		RegisterName(registrar, name.name, dataset.tables[name.table]);
	}
}

} // namespace duckdb_encodings
} // namespace duckdb
