//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/iso-8859_6-1999_map.hpp
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

class Iso_8859_6_1999ToUtf {
public:
	Iso_8859_6_1999ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 2;
	const string name = "iso-8859_6-1999";
	const idx_t size = 211;
	static const map_entry iso_8859_6_1999_to_utf8[];
	static void Register(const DBConfig &config) {
		const Iso_8859_6_1999ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&iso_8859_6_1999_to_utf8), generated_function.size);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
