//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/cp737_map.hpp
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

class Cp737ToUtf {
public:
	Cp737ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "CP737";
	const idx_t size = 256;
	static const map_entry CP737_to_utf8[];
	static void Register(const DBConfig &config) {
		const Cp737ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&CP737_to_utf8), generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
