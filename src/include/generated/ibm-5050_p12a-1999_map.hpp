//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-5050_p12a-1999_map.hpp
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

class Ibm_5050_p12a_1999ToUtf {
public:
	Ibm_5050_p12a_1999ToUtf() {};
	const idx_t lookup_bytes = 3;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-5050_P12A-1999";
	const idx_t size = 9371;
	static const map_entry ibm_5050_P12A_1999_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_5050_p12a_1999ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_5050_P12A_1999_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
