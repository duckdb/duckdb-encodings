//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-951_p100-1995_map.hpp
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

class Ibm_951_p100_1995ToUtf {
public:
	Ibm_951_p100_1995ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-951_P100-1995";
	const idx_t size = 10104;
	static const map_entry ibm_951_P100_1995_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_951_p100_1995ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_951_P100_1995_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
