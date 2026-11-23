#include "encoding_registration.hpp"
#include "encoding_registrar.hpp"

#include "duckdb_cpp.hpp"

#include <algorithm>
#include <cctype>
#include <cstring>
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

//! A conversion table, shared by every name it is registered under. The indexes are built on first use.
class EncodingTable {
public:
	EncodingTable(const map_entry_encoding *map, size_t map_size, size_t lookup_bytes, size_t max_output_bytes)
	    : map(map), map_size(map_size), lookup_bytes(lookup_bytes), max_output_bytes(max_output_bytes) {
	}

	const EncodingIndex &GetIndex() {
		std::call_once(index_flag, [&]() { index = std::make_unique<EncodingIndex>(map, map_size); });
		return *index;
	}

	const ReverseIndex &GetReverseIndex() {
		std::call_once(reverse_flag, [&]() { reverse = std::make_unique<ReverseIndex>(map, map_size); });
		return *reverse;
	}

public:
	const map_entry_encoding *map;
	size_t map_size;
	//! The maximum number of input bytes that make up a single character
	size_t lookup_bytes;
	//! The maximum number of UTF-8 bytes produced for one byte sequence of the encoding
	size_t max_output_bytes;

private:
	std::once_flag index_flag;
	std::unique_ptr<EncodingIndex> index;
	std::once_flag reverse_flag;
	std::unique_ptr<ReverseIndex> reverse;
};

using EncodingTablePtr = std::shared_ptr<EncodingTable>;

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
	const auto map = table.map;
	const auto lookup_bytes = table.lookup_bytes;
	size_t pos = 0;
	size_t out = 0;
	while (pos < input_size) {
		const size_t available = input_size - pos;
		if (available < lookup_bytes && !is_last) {
			// Not enough bytes to check; the caller hands the remaining bytes back with the next ones
			break;
		}
		const char *current = input + pos;
		const auto first = static_cast<uint8_t>(*current);
		// Prefer the longest matching byte sequence
		const map_entry_encoding *match = nullptr;
		size_t match_len = 1;
		if (index.HasMultiByte(first)) {
			const auto candidates = map + index.multi_begin[first];
			const size_t candidate_count = index.multi_end[first] - index.multi_begin[first];
			for (size_t len = std::min(lookup_bytes, available); len > 1; len--) {
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
			output[out++] = *current;
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

	std::string buffer;
	for (cxx::idx_t row = 0; row < count; row++) {
		if (!blobs.IsValid(row) || !is_last.IsValid(row)) {
			struct_mask.SetInvalid(row);
			decoded_mask.SetInvalid(row);
			consumed_mask.SetInvalid(row);
			continue;
		}
		const auto &blob = blobs.Data<cxx::blob_t>()[blobs.SelAt(row)];
		const bool last = is_last.Data<bool>()[is_last.SelAt(row)];
		buffer.resize(std::max<size_t>(blob.size() * table.max_output_bytes, 1));
		size_t consumed = 0;
		size_t written = 0;
		DecodePrefix(table, blob.data(), blob.size(), last, &buffer[0], consumed, written);
		decoded.AssignStringUnsafe(row, std::string_view(buffer.data(), written));
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
	decode_all.SetName(function_name).SetSchema(SCHEMA).SetExecCallback(DecodeAllExec);
	decode_all.GetSignature().AddParameter("data", blob).SetReturnType(varchar);
	decode_all.SetUserData<EncodingFunctionData>(EncodingFunctionData {table, name});
	registrar.extension.Register(decode_all);

	auto decode_stream = cxx::ScalarFunction::Create(factory);
	decode_stream.SetName(function_name).SetSchema(SCHEMA).SetExecCallback(DecodeStreamExec);
	decode_stream.GetSignature().AddParameter("data", blob).AddParameter("is_last", boolean).SetReturnType(
	    stream_result);
	decode_stream.SetUserData<EncodingFunctionData>(EncodingFunctionData {table, name});
	registrar.extension.Register(decode_stream);

	auto encode = cxx::ScalarFunction::Create(factory);
	encode.SetName(function_name).SetSchema(SCHEMA).SetExecCallback(EncodeExec);
	encode.GetSignature().AddParameter("string", varchar).SetReturnType(blob);
	encode.SetUserData<EncodingFunctionData>(EncodingFunctionData {table, name});
	registrar.extension.Register(encode);

	std::lock_guard<std::mutex> guard(RegisteredLock());
	Registered()[function_name] = {function_name, table->lookup_bytes, table->max_output_bytes, table->map_size};
}

void RegisterGeneratedEncoding(EncodingRegistrar &registrar, const char *name, size_t max_bytes_per_byte,
                               size_t lookup_bytes, const map_entry_encoding *map, size_t map_size,
                               const char *const *aliases, size_t alias_count) {
	auto table = std::make_shared<EncodingTable>(map, map_size, lookup_bytes, max_bytes_per_byte);
	RegisterName(registrar, name, table);
	for (size_t i = 0; i < alias_count; i++) {
		RegisterName(registrar, aliases[i], table);
	}
}

} // namespace duckdb_encodings
} // namespace duckdb
