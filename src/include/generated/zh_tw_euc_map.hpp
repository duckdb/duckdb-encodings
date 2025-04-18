//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/zh_tw_euc_map.hpp
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

class Zh_tw_eucToUtf {
public:
	Zh_tw_eucToUtf() {};
	const idx_t lookup_bytes = 4;
	const idx_t max_bytes_per_byte = 3;
	const string name = "zh_TW_euc";
	const idx_t size = 17839;
	static const map_entry zh_TW_euc_to_utf8[];
	static void Register(const DBConfig &config) {
		const Zh_tw_eucToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&zh_TW_euc_to_utf8), generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
