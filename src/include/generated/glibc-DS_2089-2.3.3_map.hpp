//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/glibc-DS_2089-2.3.3_map.hpp
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

class Glibc_ds_2089_2_3_3ToUtf {
public:
	Glibc_ds_2089_2_3_3ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 2;
	const string name = "glibc-DS_2089-2.3.3";
	// Generated from: glibc-DS_2089-2.3.3.ucm
	static constexpr map_entry glibc_DS_2089_2_3_3_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},     {1, "\x01", 1, "\x01"},     {1, "\x02", 1, "\x02"}, {1, "\x03", 1, "\x03"},
	    {1, "\x04", 1, "\x04"},     {1, "\x05", 1, "\x05"},     {1, "\x06", 1, "\x06"}, {1, "\x07", 1, "\x07"},
	    {1, "\x08", 1, "\x08"},     {1, "\x09", 1, "\x09"},     {1, "\x0A", 1, "\x0A"}, {1, "\x0B", 1, "\x0B"},
	    {1, "\x0C", 1, "\x0C"},     {1, "\x0D", 1, "\x0D"},     {1, "\x0E", 1, "\x0E"}, {1, "\x0F", 1, "\x0F"},
	    {1, "\x10", 1, "\x10"},     {1, "\x11", 1, "\x11"},     {1, "\x12", 1, "\x12"}, {1, "\x13", 1, "\x13"},
	    {1, "\x14", 1, "\x14"},     {1, "\x15", 1, "\x15"},     {1, "\x16", 1, "\x16"}, {1, "\x17", 1, "\x17"},
	    {1, "\x18", 1, "\x18"},     {1, "\x19", 1, "\x19"},     {1, "\x1A", 1, "\x1A"}, {1, "\x1B", 1, "\x1B"},
	    {1, "\x1C", 1, "\x1C"},     {1, "\x1D", 1, "\x1D"},     {1, "\x1E", 1, "\x1E"}, {1, "\x1F", 1, "\x1F"},
	    {1, "\x20", 1, "\x20"},     {1, "\x21", 1, "\x21"},     {1, "\x22", 1, "\x22"}, {1, "\x23", 1, "\x23"},
	    {1, "\x24", 1, "\x24"},     {1, "\x25", 1, "\x25"},     {1, "\x26", 1, "\x26"}, {1, "\x27", 1, "\x27"},
	    {1, "\x28", 1, "\x28"},     {1, "\x29", 1, "\x29"},     {1, "\x2A", 1, "\x2A"}, {1, "\x2B", 1, "\x2B"},
	    {1, "\x2C", 1, "\x2C"},     {1, "\x2D", 1, "\x2D"},     {1, "\x2E", 1, "\x2E"}, {1, "\x2F", 1, "\x2F"},
	    {1, "\x30", 1, "\x30"},     {1, "\x31", 1, "\x31"},     {1, "\x32", 1, "\x32"}, {1, "\x33", 1, "\x33"},
	    {1, "\x34", 1, "\x34"},     {1, "\x35", 1, "\x35"},     {1, "\x36", 1, "\x36"}, {1, "\x37", 1, "\x37"},
	    {1, "\x38", 1, "\x38"},     {1, "\x39", 1, "\x39"},     {1, "\x3A", 1, "\x3A"}, {1, "\x3B", 1, "\x3B"},
	    {1, "\x3C", 1, "\x3C"},     {1, "\x3D", 1, "\x3D"},     {1, "\x3E", 1, "\x3E"}, {1, "\x3F", 1, "\x3F"},
	    {1, "\x40", 1, "\x40"},     {1, "\x41", 1, "\x41"},     {1, "\x42", 1, "\x42"}, {1, "\x43", 1, "\x43"},
	    {1, "\x44", 1, "\x44"},     {1, "\x45", 1, "\x45"},     {1, "\x46", 1, "\x46"}, {1, "\x47", 1, "\x47"},
	    {1, "\x48", 1, "\x48"},     {1, "\x49", 1, "\x49"},     {1, "\x4A", 1, "\x4A"}, {1, "\x4B", 1, "\x4B"},
	    {1, "\x4C", 1, "\x4C"},     {1, "\x4D", 1, "\x4D"},     {1, "\x4E", 1, "\x4E"}, {1, "\x4F", 1, "\x4F"},
	    {1, "\x50", 1, "\x50"},     {1, "\x51", 1, "\x51"},     {1, "\x52", 1, "\x52"}, {1, "\x53", 1, "\x53"},
	    {1, "\x54", 1, "\x54"},     {1, "\x55", 1, "\x55"},     {1, "\x56", 1, "\x56"}, {1, "\x57", 1, "\x57"},
	    {1, "\x58", 1, "\x58"},     {1, "\x59", 1, "\x59"},     {1, "\x5A", 1, "\x5A"}, {1, "\x5B", 2, "\xC3\x86"},
	    {1, "\x5C", 2, "\xC3\x98"}, {1, "\x5D", 2, "\xC3\x85"}, {1, "\x5E", 1, "\x5E"}, {1, "\x5F", 1, "\x5F"},
	    {1, "\x60", 1, "\x60"},     {1, "\x61", 1, "\x61"},     {1, "\x62", 1, "\x62"}, {1, "\x63", 1, "\x63"},
	    {1, "\x64", 1, "\x64"},     {1, "\x65", 1, "\x65"},     {1, "\x66", 1, "\x66"}, {1, "\x67", 1, "\x67"},
	    {1, "\x68", 1, "\x68"},     {1, "\x69", 1, "\x69"},     {1, "\x6A", 1, "\x6A"}, {1, "\x6B", 1, "\x6B"},
	    {1, "\x6C", 1, "\x6C"},     {1, "\x6D", 1, "\x6D"},     {1, "\x6E", 1, "\x6E"}, {1, "\x6F", 1, "\x6F"},
	    {1, "\x70", 1, "\x70"},     {1, "\x71", 1, "\x71"},     {1, "\x72", 1, "\x72"}, {1, "\x73", 1, "\x73"},
	    {1, "\x74", 1, "\x74"},     {1, "\x75", 1, "\x75"},     {1, "\x76", 1, "\x76"}, {1, "\x77", 1, "\x77"},
	    {1, "\x78", 1, "\x78"},     {1, "\x79", 1, "\x79"},     {1, "\x7A", 1, "\x7A"}, {1, "\x7B", 2, "\xC3\xA6"},
	    {1, "\x7C", 2, "\xC3\xB8"}, {1, "\x7D", 2, "\xC3\xA5"}, {1, "\x7E", 1, "\x7E"}, {1, "\x7F", 1, "\x7F"},
	};
	static void Register(const DBConfig &config) {
		const Glibc_ds_2089_2_3_3ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&glibc_DS_2089_2_3_3_to_utf8),
		                                std::size(glibc_DS_2089_2_3_3_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
