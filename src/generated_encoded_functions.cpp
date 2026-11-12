#include "encoding_registration.hpp"
#include "encoding_registrar.hpp"

#include "duckdb_cpp.hpp"

#include <algorithm>
#include <cstring>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

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

//! A conversion table, shared by every name it is registered under. The index is built on first use.
class EncodingTable {
public:
	EncodingTable(const map_entry_encoding *map, size_t map_size, size_t lookup_bytes)
	    : map(map), map_size(map_size), lookup_bytes(lookup_bytes) {
	}

	const EncodingIndex &GetIndex() {
		std::call_once(index_flag, [&]() { index = std::unique_ptr<EncodingIndex>(new EncodingIndex(map, map_size)); });
		return *index;
	}

public:
	const map_entry_encoding *map;
	size_t map_size;
	size_t lookup_bytes;

private:
	std::once_flag index_flag;
	std::unique_ptr<EncodingIndex> index;
};

using EncodingTablePtr = std::shared_ptr<EncodingTable>;

static bool KeyLess(const char *a, size_t a_len, const char *b, size_t b_len) {
	const size_t min_len = std::min(a_len, b_len);
	const int cmp = std::memcmp(a, b, min_len);
	if (cmp != 0) {
		return cmp < 0;
	}
	return a_len < b_len;
}

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

static void Decode(cxx::EncodingFunction::DecodeInput &input) {
	auto &table = *input.GetUserData<EncodingTablePtr>();
	const auto &index = table.GetIndex();
	const auto map = table.map;
	const auto lookup_bytes = table.lookup_bytes;

	const auto encoded = input.GetInput();
	const auto output = input.GetOutput();
	const auto target = output.first;
	const auto target_size = output.second;
	const auto is_last = input.IsLast();

	cxx::idx_t pos = 0;
	cxx::idx_t written = 0;
	while (pos < encoded.size()) {
		const cxx::idx_t available = encoded.size() - pos;
		if (available < lookup_bytes && !is_last) {
			// Not enough bytes to check; the remaining bytes are carried over to the next buffer by the engine
			break;
		}
		const char *current = encoded.data() + pos;
		const auto first = static_cast<uint8_t>(*current);
		// Prefer the longest matching byte sequence
		const map_entry_encoding *match = nullptr;
		cxx::idx_t match_len = 1;
		if (index.HasMultiByte(first)) {
			const auto candidates = map + index.multi_begin[first];
			const size_t candidate_count = index.multi_end[first] - index.multi_begin[first];
			for (cxx::idx_t len = std::min<cxx::idx_t>(lookup_bytes, available); len > 1; len--) {
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
			if (written == target_size) {
				break;
			}
			target[written++] = *current;
			pos++;
			continue;
		}
		if (target_size - written < match->value_len) {
			// The character does not fit: the engine hands it to the next chunk
			break;
		}
		std::memcpy(target + written, match->value, match->value_len);
		written += match->value_len;
		pos += match_len;
	}
	input.SetResult(pos, written);
}

static std::mutex &RegisteredLock() {
	static std::mutex lock;
	return lock;
}

static std::vector<RegisteredEncoding> &Registered() {
	static std::vector<RegisteredEncoding> registered;
	return registered;
}

std::vector<RegisteredEncoding> GetRegisteredEncodings() {
	std::lock_guard<std::mutex> guard(RegisteredLock());
	return Registered();
}

static void RegisterName(EncodingRegistrar &registrar, const std::string &name, size_t max_bytes_per_byte,
                         size_t lookup_bytes, const std::shared_ptr<EncodingTable> &table) {
	auto function = cxx::EncodingFunction::Create(registrar.factory);
	function.SetName(name).SetMaxInputBytes(lookup_bytes).SetMaxOutputBytes(max_bytes_per_byte);
	function.SetDecodeCallback(Decode);
	function.SetUserData<EncodingTablePtr>(table);
	registrar.extension.Register(function);
	std::lock_guard<std::mutex> guard(RegisteredLock());
	Registered().push_back({name, lookup_bytes, max_bytes_per_byte, table->map_size});
}

void RegisterGeneratedEncoding(EncodingRegistrar &registrar, const char *name, size_t max_bytes_per_byte,
                               size_t lookup_bytes, const map_entry_encoding *map, size_t map_size,
                               const char *const *aliases, size_t alias_count) {
	auto table = std::make_shared<EncodingTable>(map, map_size, lookup_bytes);
	RegisterName(registrar, name, max_bytes_per_byte, lookup_bytes, table);
	for (size_t i = 0; i < alias_count; i++) {
		RegisterName(registrar, aliases[i], max_bytes_per_byte, lookup_bytes, table);
	}
}

} // namespace duckdb_encodings
} // namespace duckdb
