//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-5471_p100-2006_map.hpp
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

class Ibm_5471_p100_2006ToUtf {
public:
	Ibm_5471_p100_2006ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-5471_P100-2006";
	const idx_t size = 19036;
	static const map_entry ibm_5471_P100_2006_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_5471_p100_2006ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_5471_P100_2006_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
