//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/hpux-cp874-11.11_map.hpp
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

class Hpux_cp874_11_11ToUtf {
public:
	Hpux_cp874_11_11ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "hpux-cp874-11.11";
	// Generated from: hpux-cp874-11.11.ucm
	static constexpr map_entry hpux_cp874_11_11_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},         {1, "\x01", 1, "\x01"},         {1, "\x02", 1, "\x02"},
	    {1, "\x03", 1, "\x03"},         {1, "\x04", 1, "\x04"},         {1, "\x05", 1, "\x05"},
	    {1, "\x06", 1, "\x06"},         {1, "\x07", 1, "\x07"},         {1, "\x08", 1, "\x08"},
	    {1, "\x09", 1, "\x09"},         {1, "\x0A", 1, "\x0A"},         {1, "\x0B", 1, "\x0B"},
	    {1, "\x0C", 1, "\x0C"},         {1, "\x0D", 1, "\x0D"},         {1, "\x0E", 1, "\x0E"},
	    {1, "\x0F", 1, "\x0F"},         {1, "\x10", 1, "\x10"},         {1, "\x11", 1, "\x11"},
	    {1, "\x12", 1, "\x12"},         {1, "\x13", 1, "\x13"},         {1, "\x14", 1, "\x14"},
	    {1, "\x15", 1, "\x15"},         {1, "\x16", 1, "\x16"},         {1, "\x17", 1, "\x17"},
	    {1, "\x18", 1, "\x18"},         {1, "\x19", 1, "\x19"},         {1, "\x1A", 1, "\x1A"},
	    {1, "\x1B", 1, "\x1B"},         {1, "\x1C", 1, "\x1C"},         {1, "\x1D", 1, "\x1D"},
	    {1, "\x1E", 1, "\x1E"},         {1, "\x1F", 1, "\x1F"},         {1, "\x20", 1, "\x20"},
	    {1, "\x21", 1, "\x21"},         {1, "\x22", 1, "\x22"},         {1, "\x23", 1, "\x23"},
	    {1, "\x24", 1, "\x24"},         {1, "\x25", 1, "\x25"},         {1, "\x26", 1, "\x26"},
	    {1, "\x27", 1, "\x27"},         {1, "\x28", 1, "\x28"},         {1, "\x29", 1, "\x29"},
	    {1, "\x2A", 1, "\x2A"},         {1, "\x2B", 1, "\x2B"},         {1, "\x2C", 1, "\x2C"},
	    {1, "\x2D", 1, "\x2D"},         {1, "\x2E", 1, "\x2E"},         {1, "\x2F", 1, "\x2F"},
	    {1, "\x30", 1, "\x30"},         {1, "\x31", 1, "\x31"},         {1, "\x32", 1, "\x32"},
	    {1, "\x33", 1, "\x33"},         {1, "\x34", 1, "\x34"},         {1, "\x35", 1, "\x35"},
	    {1, "\x36", 1, "\x36"},         {1, "\x37", 1, "\x37"},         {1, "\x38", 1, "\x38"},
	    {1, "\x39", 1, "\x39"},         {1, "\x3A", 1, "\x3A"},         {1, "\x3B", 1, "\x3B"},
	    {1, "\x3C", 1, "\x3C"},         {1, "\x3D", 1, "\x3D"},         {1, "\x3E", 1, "\x3E"},
	    {1, "\x3F", 1, "\x3F"},         {1, "\x40", 1, "\x40"},         {1, "\x41", 1, "\x41"},
	    {1, "\x42", 1, "\x42"},         {1, "\x43", 1, "\x43"},         {1, "\x44", 1, "\x44"},
	    {1, "\x45", 1, "\x45"},         {1, "\x46", 1, "\x46"},         {1, "\x47", 1, "\x47"},
	    {1, "\x48", 1, "\x48"},         {1, "\x49", 1, "\x49"},         {1, "\x4A", 1, "\x4A"},
	    {1, "\x4B", 1, "\x4B"},         {1, "\x4C", 1, "\x4C"},         {1, "\x4D", 1, "\x4D"},
	    {1, "\x4E", 1, "\x4E"},         {1, "\x4F", 1, "\x4F"},         {1, "\x50", 1, "\x50"},
	    {1, "\x51", 1, "\x51"},         {1, "\x52", 1, "\x52"},         {1, "\x53", 1, "\x53"},
	    {1, "\x54", 1, "\x54"},         {1, "\x55", 1, "\x55"},         {1, "\x56", 1, "\x56"},
	    {1, "\x57", 1, "\x57"},         {1, "\x58", 1, "\x58"},         {1, "\x59", 1, "\x59"},
	    {1, "\x5A", 1, "\x5A"},         {1, "\x5B", 1, "\x5B"},         {1, "\x5C", 1, "\x5C"},
	    {1, "\x5D", 1, "\x5D"},         {1, "\x5E", 1, "\x5E"},         {1, "\x5F", 1, "\x5F"},
	    {1, "\x60", 1, "\x60"},         {1, "\x61", 1, "\x61"},         {1, "\x62", 1, "\x62"},
	    {1, "\x63", 1, "\x63"},         {1, "\x64", 1, "\x64"},         {1, "\x65", 1, "\x65"},
	    {1, "\x66", 1, "\x66"},         {1, "\x67", 1, "\x67"},         {1, "\x68", 1, "\x68"},
	    {1, "\x69", 1, "\x69"},         {1, "\x6A", 1, "\x6A"},         {1, "\x6B", 1, "\x6B"},
	    {1, "\x6C", 1, "\x6C"},         {1, "\x6D", 1, "\x6D"},         {1, "\x6E", 1, "\x6E"},
	    {1, "\x6F", 1, "\x6F"},         {1, "\x70", 1, "\x70"},         {1, "\x71", 1, "\x71"},
	    {1, "\x72", 1, "\x72"},         {1, "\x73", 1, "\x73"},         {1, "\x74", 1, "\x74"},
	    {1, "\x75", 1, "\x75"},         {1, "\x76", 1, "\x76"},         {1, "\x77", 1, "\x77"},
	    {1, "\x78", 1, "\x78"},         {1, "\x79", 1, "\x79"},         {1, "\x7A", 1, "\x7A"},
	    {1, "\x7B", 1, "\x7B"},         {1, "\x7C", 1, "\x7C"},         {1, "\x7D", 1, "\x7D"},
	    {1, "\x7E", 1, "\x7E"},         {1, "\x7F", 1, "\x7F"},         {1, "\x80", 3, "\xE2\x82\xAC"},
	    {1, "\x85", 3, "\xE2\x80\xA6"}, {1, "\x91", 3, "\xE2\x80\x98"}, {1, "\x92", 3, "\xE2\x80\x99"},
	    {1, "\x93", 3, "\xE2\x80\x9C"}, {1, "\x94", 3, "\xE2\x80\x9D"}, {1, "\x95", 3, "\xE2\x80\xA2"},
	    {1, "\x96", 3, "\xE2\x80\x93"}, {1, "\x97", 3, "\xE2\x80\x94"}, {1, "\xA0", 2, "\xC2\xA0"},
	    {1, "\xA1", 3, "\xE0\xB8\x81"}, {1, "\xA2", 3, "\xE0\xB8\x82"}, {1, "\xA3", 3, "\xE0\xB8\x83"},
	    {1, "\xA4", 3, "\xE0\xB8\x84"}, {1, "\xA5", 3, "\xE0\xB8\x85"}, {1, "\xA6", 3, "\xE0\xB8\x86"},
	    {1, "\xA7", 3, "\xE0\xB8\x87"}, {1, "\xA8", 3, "\xE0\xB8\x88"}, {1, "\xA9", 3, "\xE0\xB8\x89"},
	    {1, "\xAA", 3, "\xE0\xB8\x8A"}, {1, "\xAB", 3, "\xE0\xB8\x8B"}, {1, "\xAC", 3, "\xE0\xB8\x8C"},
	    {1, "\xAD", 3, "\xE0\xB8\x8D"}, {1, "\xAE", 3, "\xE0\xB8\x8E"}, {1, "\xAF", 3, "\xE0\xB8\x8F"},
	    {1, "\xB0", 3, "\xE0\xB8\x90"}, {1, "\xB1", 3, "\xE0\xB8\x91"}, {1, "\xB2", 3, "\xE0\xB8\x92"},
	    {1, "\xB3", 3, "\xE0\xB8\x93"}, {1, "\xB4", 3, "\xE0\xB8\x94"}, {1, "\xB5", 3, "\xE0\xB8\x95"},
	    {1, "\xB6", 3, "\xE0\xB8\x96"}, {1, "\xB7", 3, "\xE0\xB8\x97"}, {1, "\xB8", 3, "\xE0\xB8\x98"},
	    {1, "\xB9", 3, "\xE0\xB8\x99"}, {1, "\xBA", 3, "\xE0\xB8\x9A"}, {1, "\xBB", 3, "\xE0\xB8\x9B"},
	    {1, "\xBC", 3, "\xE0\xB8\x9C"}, {1, "\xBD", 3, "\xE0\xB8\x9D"}, {1, "\xBE", 3, "\xE0\xB8\x9E"},
	    {1, "\xBF", 3, "\xE0\xB8\x9F"}, {1, "\xC0", 3, "\xE0\xB8\xA0"}, {1, "\xC1", 3, "\xE0\xB8\xA1"},
	    {1, "\xC2", 3, "\xE0\xB8\xA2"}, {1, "\xC3", 3, "\xE0\xB8\xA3"}, {1, "\xC4", 3, "\xE0\xB8\xA4"},
	    {1, "\xC5", 3, "\xE0\xB8\xA5"}, {1, "\xC6", 3, "\xE0\xB8\xA6"}, {1, "\xC7", 3, "\xE0\xB8\xA7"},
	    {1, "\xC8", 3, "\xE0\xB8\xA8"}, {1, "\xC9", 3, "\xE0\xB8\xA9"}, {1, "\xCA", 3, "\xE0\xB8\xAA"},
	    {1, "\xCB", 3, "\xE0\xB8\xAB"}, {1, "\xCC", 3, "\xE0\xB8\xAC"}, {1, "\xCD", 3, "\xE0\xB8\xAD"},
	    {1, "\xCE", 3, "\xE0\xB8\xAE"}, {1, "\xCF", 3, "\xE0\xB8\xAF"}, {1, "\xD0", 3, "\xE0\xB8\xB0"},
	    {1, "\xD1", 3, "\xE0\xB8\xB1"}, {1, "\xD2", 3, "\xE0\xB8\xB2"}, {1, "\xD3", 3, "\xE0\xB8\xB3"},
	    {1, "\xD4", 3, "\xE0\xB8\xB4"}, {1, "\xD5", 3, "\xE0\xB8\xB5"}, {1, "\xD6", 3, "\xE0\xB8\xB6"},
	    {1, "\xD7", 3, "\xE0\xB8\xB7"}, {1, "\xD8", 3, "\xE0\xB8\xB8"}, {1, "\xD9", 3, "\xE0\xB8\xB9"},
	    {1, "\xDA", 3, "\xE0\xB8\xBA"}, {1, "\xDF", 3, "\xE0\xB8\xBF"}, {1, "\xE0", 3, "\xE0\xB9\x80"},
	    {1, "\xE1", 3, "\xE0\xB9\x81"}, {1, "\xE2", 3, "\xE0\xB9\x82"}, {1, "\xE3", 3, "\xE0\xB9\x83"},
	    {1, "\xE4", 3, "\xE0\xB9\x84"}, {1, "\xE5", 3, "\xE0\xB9\x85"}, {1, "\xE6", 3, "\xE0\xB9\x86"},
	    {1, "\xE7", 3, "\xE0\xB9\x87"}, {1, "\xE8", 3, "\xE0\xB9\x88"}, {1, "\xE9", 3, "\xE0\xB9\x89"},
	    {1, "\xEA", 3, "\xE0\xB9\x8A"}, {1, "\xEB", 3, "\xE0\xB9\x8B"}, {1, "\xEC", 3, "\xE0\xB9\x8C"},
	    {1, "\xED", 3, "\xE0\xB9\x8D"}, {1, "\xEE", 3, "\xE0\xB9\x8E"}, {1, "\xEF", 3, "\xE0\xB9\x8F"},
	    {1, "\xF0", 3, "\xE0\xB9\x90"}, {1, "\xF1", 3, "\xE0\xB9\x91"}, {1, "\xF2", 3, "\xE0\xB9\x92"},
	    {1, "\xF3", 3, "\xE0\xB9\x93"}, {1, "\xF4", 3, "\xE0\xB9\x94"}, {1, "\xF5", 3, "\xE0\xB9\x95"},
	    {1, "\xF6", 3, "\xE0\xB9\x96"}, {1, "\xF7", 3, "\xE0\xB9\x97"}, {1, "\xF8", 3, "\xE0\xB9\x98"},
	    {1, "\xF9", 3, "\xE0\xB9\x99"}, {1, "\xFA", 3, "\xE0\xB9\x9A"}, {1, "\xFB", 3, "\xE0\xB9\x9B"},
	};
	static void Register(const DBConfig &config) {
		const Hpux_cp874_11_11ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&hpux_cp874_11_11_to_utf8),
		                                std::size(hpux_cp874_11_11_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
