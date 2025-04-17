//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/glibc-jus_i.b1.002-2.3.3_map.hpp
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

class Glibc_jus_i_b1_002_2_3_3ToUtf {
public:
	Glibc_jus_i_b1_002_2_3_3ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 2;
	const string name = "glibc-JUS_I.B1.002-2.3.3";
	const idx_t size = 128;
	static const map_entry glibc_JUS_I_B1_002_2_3_3_to_utf8[];
	static void Register(const DBConfig &config) {
		const Glibc_jus_i_b1_002_2_3_3ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&glibc_JUS_I_B1_002_2_3_3_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
