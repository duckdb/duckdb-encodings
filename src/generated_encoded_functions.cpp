#include "generated_encoded_function.hpp"
#include "encodings_dataset.hpp"

#include "duckdb/common/exception.hpp"
#include "duckdb/execution/operator/csv_scanner/encode/csv_encoder.hpp"
#include "zstd.h"

#include <algorithm>
#include <cstring>

namespace duckdb {
namespace duckdb_encodings {

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

//! A conversion table, unpacked from the dataset
struct ConversionTable {
	//! The entries, sorted by key; their keys and values point into `bytes`
	vector<map_entry_encoding> entries;
	vector<char> bytes;
	unique_ptr<EncodingIndex> index;
};

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
	string name;
};

//! The encodings dataset. All tables are compressed together, so a table is unpacked the first time one of its names is
//! used: the frame is decompressed, the table is expanded, and the decompressed frame is dropped again.
class EncodingsDataset {
public:
	EncodingsDataset() {
		Parse();
	}

	const vector<TableRecord> &Records() const {
		return records;
	}
	const vector<EncodingName> &Names() const {
		return names;
	}
	//! The entry of the handle array that identifies the table (see GetTable): it is what a registered encoding
	//! points its conversion map at, and is never read as a map
	const map_entry_encoding *Handle(idx_t table) const {
		return &handles[table];
	}

	const ConversionTable &GetTable(const map_entry_encoding *handle) {
		const auto table = NumericCast<idx_t>(handle - handles.data());
		D_ASSERT(table < tables.size());
		lock_guard<mutex> guard(lock);
		if (!tables[table]) {
			tables[table] = Unpack(records[table]);
		}
		return *tables[table];
	}

private:
	static uint32_t ReadU32(const unsigned char *&pos, const unsigned char *end) {
		if (end - pos < 4) {
			throw InternalException("Corrupt encodings dataset");
		}
		uint32_t result;
		memcpy(&result, pos, sizeof(result)); // the dataset is little endian, like every platform DuckDB supports
		pos += sizeof(result);
		return result;
	}

	void Parse() {
		const auto end = ENCODINGS_DATASET + ENCODINGS_DATASET_SIZE;
		auto pos = ENCODINGS_DATASET;
		if (ENCODINGS_DATASET_SIZE < 8 || memcmp(pos, "DKENC001", 8) != 0) {
			throw InternalException("Corrupt encodings dataset");
		}
		pos += 8;
		const auto table_count = ReadU32(pos, end);
		const auto name_count = ReadU32(pos, end);
		content_size = ReadU32(pos, end);
		for (idx_t i = 0; i < table_count; i++) {
			TableRecord record;
			record.offset = ReadU32(pos, end);
			record.size = ReadU32(pos, end);
			record.map_size = ReadU32(pos, end);
			const auto sizes = ReadU32(pos, end);
			record.lookup_bytes = sizes & 0xff;
			record.max_output_bytes = (sizes >> 8) & 0xff;
			records.push_back(record);
		}
		for (idx_t i = 0; i < name_count; i++) {
			EncodingName name;
			name.table = ReadU32(pos, end);
			if (end - pos < 2 || name.table >= table_count) {
				throw InternalException("Corrupt encodings dataset");
			}
			uint16_t length;
			memcpy(&length, pos, sizeof(length));
			pos += sizeof(length);
			if (static_cast<idx_t>(end - pos) < length) {
				throw InternalException("Corrupt encodings dataset");
			}
			name.name = string(reinterpret_cast<const char *>(pos), length);
			pos += length;
			names.push_back(std::move(name));
		}
		frame = pos;
		frame_size = NumericCast<idx_t>(end - pos);
		handles.resize(table_count);
		tables.resize(table_count);
	}

	static uint64_t ReadVarint(const unsigned char *&pos, const unsigned char *end) {
		uint64_t result = 0;
		for (uint32_t shift = 0; shift < 64; shift += 7) {
			if (pos == end) {
				break;
			}
			const auto byte = *pos++;
			result |= static_cast<uint64_t>(byte & 0x7f) << shift;
			if (!(byte & 0x80)) {
				return result;
			}
		}
		throw InternalException("Corrupt encodings dataset");
	}

	static int64_t ReadSignedVarint(const unsigned char *&pos, const unsigned char *end) {
		const auto value = ReadVarint(pos, end);
		return (value & 1) ? -static_cast<int64_t>((value + 1) >> 1) : static_cast<int64_t>(value >> 1);
	}

	static idx_t WriteUTF8(uint32_t value, char *target) {
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

	unique_ptr<ConversionTable> Unpack(const TableRecord &record) const {
		vector<unsigned char> content(content_size);
		const auto decompressed = duckdb_zstd::ZSTD_decompress(content.data(), content.size(), frame, frame_size);
		if (duckdb_zstd::ZSTD_isError(decompressed) || decompressed != content_size ||
		    static_cast<idx_t>(record.offset) + record.size > content_size) {
			throw InternalException("Corrupt encodings dataset");
		}

		auto result = make_uniq<ConversionTable>();
		const auto end = content.data() + record.offset + record.size;
		auto pos = static_cast<const unsigned char *>(content.data() + record.offset);
		const auto key_deltas_size = ReadU32(pos, end);
		const auto key_lengths = pos;
		if (static_cast<idx_t>(end - pos) < static_cast<idx_t>(record.map_size) + key_deltas_size) {
			throw InternalException("Corrupt encodings dataset");
		}
		auto key_deltas = key_lengths + record.map_size;
		auto value_deltas = key_deltas + key_deltas_size;
		const auto key_deltas_end = value_deltas;

		// Every entry has a key of up to 8 bytes and a UTF-8 value of up to 4 bytes
		result->bytes.resize(static_cast<idx_t>(record.map_size) * 12);
		result->entries.reserve(record.map_size);
		auto target = result->bytes.data();
		int64_t key = 0;
		int64_t value = 0;
		for (idx_t i = 0; i < record.map_size; i++) {
			const auto key_length = key_lengths[i];
			key += ReadSignedVarint(key_deltas, key_deltas_end);
			value += ReadSignedVarint(value_deltas, end);
			if (key_length == 0 || key_length > 8 || value < 0 || value > 0x10FFFF) {
				throw InternalException("Corrupt encodings dataset");
			}
			map_entry_encoding entry;
			entry.key_len = key_length;
			entry.key = target;
			for (idx_t byte = 0; byte < key_length; byte++) {
				*target++ = static_cast<char>((static_cast<uint64_t>(key) >> (8 * (key_length - 1 - byte))) & 0xff);
			}
			entry.value = target;
			entry.value_len = WriteUTF8(static_cast<uint32_t>(value), target);
			target += entry.value_len;
			result->entries.push_back(entry);
		}
		result->index = make_uniq<EncodingIndex>(result->entries.data(), result->entries.size());
		return result;
	}

private:
	vector<TableRecord> records;
	vector<EncodingName> names;
	const unsigned char *frame = nullptr;
	idx_t frame_size = 0;
	//! The size of the frame once decompressed
	idx_t content_size = 0;
	vector<map_entry_encoding> handles;

	mutex lock;
	vector<unique_ptr<ConversionTable>> tables;
};

static EncodingsDataset &GetDataset() {
	static EncodingsDataset dataset;
	return dataset;
}

void GeneratedEncodedFunction::Decode(CSVEncoderBuffer &encoded_buffer, char *target_buffer,
                                      idx_t &target_buffer_current_position, const idx_t target_buffer_size,
                                      char *remaining_bytes_buffer, idx_t &remaining_bytes_size,
                                      EncodingFunction *encoding_function) {
	const auto &table = GetDataset().GetTable(encoding_function->conversion_map);
	const auto &index = *table.index;
	const auto map = table.entries.data();
	const auto encoded_buffer_ptr = encoded_buffer.Ptr();
	const idx_t lookup_bytes = encoding_function->GetLookupBytes();
	const idx_t encoded_buffer_size = encoded_buffer.actual_encoded_buffer_size;
	while (encoded_buffer.cur_pos < encoded_buffer_size) {
		const idx_t available = encoded_buffer_size - encoded_buffer.cur_pos;
		if (available < lookup_bytes && !encoded_buffer.last_buffer) {
			// Not enough bytes to check; the remaining bytes are carried over to the next buffer by the caller
			return;
		}
		const char *current = &encoded_buffer_ptr[encoded_buffer.cur_pos];
		const auto first = static_cast<uint8_t>(*current);
		// Prefer the longest matching byte sequence
		const map_entry_encoding *match = nullptr;
		idx_t match_len = 1;
		if (index.HasMultiByte(first)) {
			const auto candidates = map + index.multi_begin[first];
			const size_t candidate_count = index.multi_end[first] - index.multi_begin[first];
			for (idx_t len = std::min<idx_t>(lookup_bytes, available); len > 1; len--) {
				match = FindEntry(candidates, candidate_count, current, len);
				if (match) {
					match_len = len;
					break;
				}
			}
		}
		if (!match) {
			match = index.single[first];
		}
		if (!match) {
			// No mapping for this byte: pass it through unchanged
			encoded_buffer.cur_pos++;
			if (target_buffer_current_position == target_buffer_size) {
				// The target buffer is full: hand the byte to the next chunk instead of writing past the end
				remaining_bytes_buffer[0] = *current;
				remaining_bytes_size = 1;
				return;
			}
			target_buffer[target_buffer_current_position++] = *current;
			continue;
		}
		encoded_buffer.cur_pos += match_len;
		for (idx_t byte_pos = 0; byte_pos < match->value_len; ++byte_pos) {
			if (target_buffer_current_position == target_buffer_size) {
				// The target buffer is full: store the rest of this character for the next chunk
				remaining_bytes_size = match->value_len - byte_pos;
				for (idx_t remaining_pos = 0; remaining_pos < remaining_bytes_size; ++remaining_pos) {
					remaining_bytes_buffer[remaining_pos] = static_cast<char>(match->value[byte_pos + remaining_pos]);
				}
				return;
			}
			target_buffer[target_buffer_current_position++] = match->value[byte_pos];
		}
	}
}

bool GeneratedEncodedFunction::KeyLess(const char *a, size_t a_len, const char *b, size_t b_len) {
	const size_t min_len = std::min(a_len, b_len);
	const int cmp = std::memcmp(a, b, min_len);
	if (cmp != 0) {
		return cmp < 0;
	}
	return a_len < b_len;
}

struct MapEntryComparator {
	bool operator()(const map_entry_encoding &entry, const std::pair<const char *, size_t> &key) const {
		return GeneratedEncodedFunction::KeyLess(entry.key, entry.key_len, key.first, key.second);
	}
};

const map_entry_encoding *GeneratedEncodedFunction::FindEntry(const map_entry_encoding *map, size_t map_size,
                                                              const char *search_key, size_t search_len) {
	const auto it =
	    std::lower_bound(map, map + map_size, std::make_pair(search_key, search_len), MapEntryComparator {});
	if (it != map + map_size && it->key_len == search_len && std::memcmp(it->key, search_key, search_len) == 0) {
		return it;
	}
	return nullptr;
}

void RegisterEncodings(const DBConfig &config) {
	auto &dataset = GetDataset();
	for (auto &name : dataset.Names()) {
		auto &record = dataset.Records()[name.table];
		config.RegisterEncodeFunction(EncodingFunction(name.name, GeneratedEncodedFunction::Decode,
		                                               record.max_output_bytes, record.lookup_bytes,
		                                               dataset.Handle(name.table), record.map_size));
	}
}

} // namespace duckdb_encodings
} // namespace duckdb
