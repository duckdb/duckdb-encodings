//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-932_p12a_p12a-2000_u2_map.hpp
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

class Ibm_932_p12a_p12a_2000_u2ToUtf {
public:
	Ibm_932_p12a_p12a_2000_u2ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-932_P12A_P12A-2000_U2";
	const idx_t size = 9341;
	static const map_entry ibm_932_P12A_P12A_2000_U2_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_932_p12a_p12a_2000_u2ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_932_P12A_P12A_2000_U2_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
