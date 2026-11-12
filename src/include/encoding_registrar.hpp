//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// encoding_registrar.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb_cpp.hpp"

namespace duckdb {
namespace duckdb_encodings {

//! What registering an encoding needs: the loading extension, and a factory of its database to create the encodings
//! through.
struct EncodingRegistrar {
	cxx::Extension &extension;
	cxx::Factory &factory;
};

} // namespace duckdb_encodings
} // namespace duckdb
