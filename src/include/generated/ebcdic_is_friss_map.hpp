//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ebcdic_is_friss_map.hpp
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

class Ebcdic_is_frissToUtf {
public:
	Ebcdic_is_frissToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "EBCDIC_IS_FRISS";
	const idx_t size = 145;
	static const map_entry EBCDIC_IS_FRISS_to_utf8[];
	static void Register(const DBConfig &config) {
		const Ebcdic_is_frissToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&EBCDIC_IS_FRISS_to_utf8), generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
