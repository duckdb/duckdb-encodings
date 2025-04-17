//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/java-cp1025-1.3_p_map.hpp
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

class Java_cp1025_1_3_pToUtf {
public:
	Java_cp1025_1_3_pToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "java-Cp1025-1.3_P";
	const idx_t size = 254;
	static const map_entry java_Cp1025_1_3_P_to_utf8[];
	static void Register(const DBConfig &config) {
		const Java_cp1025_1_3_pToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&java_Cp1025_1_3_P_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
