//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// encoding_registration.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/function/map_entry_encoding.hpp"

// Included by the generated conversion tables. Don't include any other DuckDB headers here, so that compiler caches
// can reuse the tables across changes to DuckDB's headers.
namespace duckdb {

struct DBConfig;

namespace duckdb_encodings {

//! Registers a generated conversion table under its name and all of its aliases.
void RegisterGeneratedEncoding(const DBConfig &config, const char *name, size_t max_bytes_per_byte, size_t lookup_bytes,
                               const map_entry_encoding *map, size_t map_size, const char *const *aliases = nullptr,
                               size_t alias_count = 0);

} // namespace duckdb_encodings
} // namespace duckdb
