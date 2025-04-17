//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-21427_p100-1999_map.hpp
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

class Ibm_21427_p100_1999ToUtf {
public:
	Ibm_21427_p100_1999ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-21427_P100-1999";
	const idx_t size = 20265;
	static const map_entry ibm_21427_P100_1999_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_21427_p100_1999ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_21427_P100_1999_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
