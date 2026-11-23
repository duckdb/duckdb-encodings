//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// encoding_registration.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace duckdb {

namespace duckdb_encodings {

//! What registering an encoding needs: see encoding_registrar.hpp.
struct EncodingRegistrar;

//! Registers all encodings of the dataset under all of their names.
void RegisterEncodings(EncodingRegistrar &registrar);

//! An encoding registered by this extension.
struct RegisteredEncoding {
	std::string name;
	size_t max_input_bytes;
	size_t max_output_bytes;
	size_t map_size;
};

//! The encodings registered so far.
std::vector<RegisteredEncoding> GetRegisteredEncodings();

} // namespace duckdb_encodings
} // namespace duckdb
