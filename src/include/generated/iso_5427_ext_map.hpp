//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/iso_5427_ext_map.hpp
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

class Iso_5427_extToUtf {
public:
	Iso_5427_extToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 2;
	const string name = "ISO_5427_EXT";
	const idx_t size = 76;
	static const map_entry ISO_5427_EXT_to_utf8[];
	static void Register(const DBConfig &config) {
		const Iso_5427_extToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ISO_5427_EXT_to_utf8), generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
