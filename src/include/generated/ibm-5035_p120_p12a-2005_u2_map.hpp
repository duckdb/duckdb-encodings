//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-5035_p120_p12a-2005_u2_map.hpp
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

class Ibm_5035_p120_p12a_2005_u2ToUtf {
public:
	Ibm_5035_p120_p12a_2005_u2ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-5035_P120_P12A-2005_U2";
	const idx_t size = 11861;
	static const map_entry ibm_5035_P120_P12A_2005_U2_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_5035_p120_p12a_2005_u2ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_5035_P120_P12A_2005_U2_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
