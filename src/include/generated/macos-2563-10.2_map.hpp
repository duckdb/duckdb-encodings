//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/macos-2563-10.2_map.hpp
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

class Macos_2563_10_2ToUtf {
public:
	Macos_2563_10_2ToUtf() {};
	const idx_t lookup_bytes = 2;
	const idx_t max_bytes_per_byte = 3;
	const string name = "macos-2563-10.2";
	const idx_t size = 13566;
	static const map_entry macos_2563_10_2_to_utf8[];
	static void Register(const DBConfig &config) {
		const Macos_2563_10_2ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&macos_2563_10_2_to_utf8), generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
