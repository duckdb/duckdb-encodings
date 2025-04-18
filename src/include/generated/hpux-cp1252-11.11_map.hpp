//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/hpux-cp1252-11.11_map.hpp
//
//
//===----------------------------------------------------------------------===//

// !!!!!!!
// WARNING: this file is autogenerated by scripts/converter.py, manual changes will be overwritten
// !!!!!!!

#pragma once

#include "duckdb/main/config.hpp"
#include "duckdb/function/encoding_function.hpp"
#include "generated_encoded_function.hpp"

namespace duckdb {
namespace duckdb_encodings {

class Hpux_cp1252_11_11ToUtf {
public:
	Hpux_cp1252_11_11ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "hpux-cp1252-11.11";
	const idx_t size = 251;
	static const map_entry hpux_cp1252_11_11_to_utf8[];
	static void Register(const DBConfig &config) {
		const Hpux_cp1252_11_11ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&hpux_cp1252_11_11_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
