//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// encodings_dataset.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

// The generated dataset (src/encodings_dataset.cpp) deliberately doesn't include any DuckDB headers, so that compiler
// caches can reuse it across changes to DuckDB's headers.
#include <cstddef>

namespace duckdb {
namespace duckdb_encodings {

//! The conversion tables of all encodings and the names they are registered under, see scripts/converter.py
extern const size_t ENCODINGS_DATASET_SIZE;
extern const unsigned char ENCODINGS_DATASET[];

} // namespace duckdb_encodings
} // namespace duckdb
