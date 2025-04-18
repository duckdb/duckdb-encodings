//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-941_p13a-2001_map.hpp
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

class Ibm_941_p13a_2001ToUtf {
public:
	Ibm_941_p13a_2001ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-941_P13A-2001";
	const idx_t size = 9604;
	static const map_entry ibm_941_P13A_2001_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_941_p13a_2001ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_941_P13A_2001_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
