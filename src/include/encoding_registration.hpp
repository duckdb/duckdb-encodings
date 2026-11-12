//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// encoding_registration.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>

// Included by the generated conversion tables. Don't include any DuckDB headers here, so that compiler caches can reuse
// the tables across changes to DuckDB's headers.
namespace duckdb {

namespace duckdb_encodings {

//! What registering an encoding needs: see encoding_registrar.hpp.
struct EncodingRegistrar;

//! Encoding Map Entry Struct used for byte replacement
struct map_entry_encoding {
	size_t key_len;
	const char *key;
	size_t value_len;
	const char *value;
};

//! Registers a generated conversion table under its name and all of its aliases.
void RegisterGeneratedEncoding(EncodingRegistrar &registrar, const char *name, size_t max_bytes_per_byte,
                               size_t lookup_bytes, const map_entry_encoding *map, size_t map_size,
                               const char *const *aliases = nullptr, size_t alias_count = 0);

//! The number of byte sequences in the conversion table of a registered encoding, 0 if it has none (the encodings
//! DuckDB provides itself).
size_t GetEncodingMapSize(const char *name, size_t name_length);

} // namespace duckdb_encodings
} // namespace duckdb
