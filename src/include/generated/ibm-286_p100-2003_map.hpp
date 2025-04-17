//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-286_p100-2003_map.hpp
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

class Ibm_286_p100_2003ToUtf {
public:
	Ibm_286_p100_2003ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-286_P100-2003";
	const idx_t size = 155;
	static const map_entry ibm_286_P100_2003_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_286_p100_2003ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_286_P100_2003_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
