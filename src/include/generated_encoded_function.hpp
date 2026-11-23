//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated_encoded_function.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/main/config.hpp"
#include "duckdb/function/encoding_function.hpp"

namespace duckdb {
namespace duckdb_encodings {

//! Registers all encodings of the dataset under all of their names
void RegisterEncodings(const DBConfig &config);

class GeneratedEncodedFunction {
public:
	static void Decode(CSVEncoderBuffer &encoded_buffer, char *target_buffer, idx_t &target_buffer_current_position,
	                   const idx_t target_buffer_size, char *remaining_bytes_buffer, idx_t &remaining_bytes_size,
	                   EncodingFunction *encoding_function);

	static bool KeyLess(const char *a, size_t a_len, const char *b, size_t b_len);

	static const map_entry_encoding *FindEntry(const map_entry_encoding *map, size_t map_size, const char *search_key,
	                                           size_t search_len);
};

} // namespace duckdb_encodings

} // namespace duckdb
