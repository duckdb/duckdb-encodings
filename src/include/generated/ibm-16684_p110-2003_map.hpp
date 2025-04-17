//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-16684_p110-2003_map.hpp
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

class Ibm_16684_p110_2003ToUtf {
public:
	Ibm_16684_p110_2003ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 4;
	const string name = "ibm-16684_P110-2003";
	const idx_t size = 22077;
	static const map_entry ibm_16684_P110_2003_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ibm_16684_p110_2003ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_16684_P110_2003_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
