//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/aix-ibm_udcjp-4.3.6_map.hpp
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

class Aix_ibm_udcjp_4_3_6ToUtf {
public:
	Aix_ibm_udcjp_4_3_6ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "aix-IBM_udcJP-4.3.6";
	const idx_t size = 2336;
	static const map_entry aix_IBM_udcJP_4_3_6_to_utf8[];
	static void Register(const DBConfig &config) {
		const Aix_ibm_udcjp_4_3_6ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&aix_IBM_udcJP_4_3_6_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
