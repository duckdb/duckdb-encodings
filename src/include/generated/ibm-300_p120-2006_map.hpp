//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-300_p120-2006_map.hpp
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

class Ibm_300_p120_2006ToUtf {
public:
	Ibm_300_p120_2006ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-300_P120-2006";
	const idx_t size = 11635;
	static const map_entry ibm_300_P120_2006_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_300_p120_2006ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_300_P120_2006_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
