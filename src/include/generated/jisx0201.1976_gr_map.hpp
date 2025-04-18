//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/jisx0201.1976_gr_map.hpp
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

class Jisx0201_1976_grToUtf {
public:
	Jisx0201_1976_grToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "JISX0201.1976_GR";
	const idx_t size = 158;
	static const map_entry JISX0201_1976_GR_to_utf8[];
	static void Register(const DBConfig &config) {
		const Jisx0201_1976_grToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&JISX0201_1976_GR_to_utf8),
		                                generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
