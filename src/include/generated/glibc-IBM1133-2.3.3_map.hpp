//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/glibc-IBM1133-2.3.3_map.hpp
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

class Glibc_ibm1133_2_3_3ToUtf {
public:
	Glibc_ibm1133_2_3_3ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "glibc-IBM1133-2.3.3";
	// Generated from: glibc-IBM1133-2.3.3.ucm
	static constexpr map_entry glibc_IBM1133_2_3_3_to_utf8[] = {
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
	    {1, "\x7E", 1, "\x7E"},         {1, "\x7F", 1, "\x7F"},         {1, "\x80", 2, "\xC2\x80"},
	    {1, "\x81", 2, "\xC2\x81"},     {1, "\x82", 2, "\xC2\x82"},     {1, "\x83", 2, "\xC2\x83"},
	    {1, "\x84", 2, "\xC2\x84"},     {1, "\x85", 2, "\xC2\x85"},     {1, "\x86", 2, "\xC2\x86"},
	    {1, "\x87", 2, "\xC2\x87"},     {1, "\x88", 2, "\xC2\x88"},     {1, "\x89", 2, "\xC2\x89"},
	    {1, "\x8A", 2, "\xC2\x8A"},     {1, "\x8B", 2, "\xC2\x8B"},     {1, "\x8C", 2, "\xC2\x8C"},
	    {1, "\x8D", 2, "\xC2\x8D"},     {1, "\x8E", 2, "\xC2\x8E"},     {1, "\x8F", 2, "\xC2\x8F"},
	    {1, "\x90", 2, "\xC2\x90"},     {1, "\x91", 2, "\xC2\x91"},     {1, "\x92", 2, "\xC2\x92"},
	    {1, "\x93", 2, "\xC2\x93"},     {1, "\x94", 2, "\xC2\x94"},     {1, "\x95", 2, "\xC2\x95"},
	    {1, "\x96", 2, "\xC2\x96"},     {1, "\x97", 2, "\xC2\x97"},     {1, "\x98", 2, "\xC2\x98"},
	    {1, "\x99", 2, "\xC2\x99"},     {1, "\x9A", 2, "\xC2\x9A"},     {1, "\x9B", 2, "\xC2\x9B"},
	    {1, "\x9C", 2, "\xC2\x9C"},     {1, "\x9D", 2, "\xC2\x9D"},     {1, "\x9E", 2, "\xC2\x9E"},
	    {1, "\x9F", 2, "\xC2\x9F"},     {1, "\xA1", 3, "\xE0\xBA\x81"}, {1, "\xA2", 3, "\xE0\xBA\x82"},
	    {1, "\xA3", 3, "\xE0\xBA\x84"}, {1, "\xA4", 3, "\xE0\xBA\x87"}, {1, "\xA5", 3, "\xE0\xBA\x88"},
	    {1, "\xA6", 3, "\xE0\xBA\xAA"}, {1, "\xA7", 3, "\xE0\xBA\x8A"}, {1, "\xA8", 3, "\xE0\xBA\x8D"},
	    {1, "\xA9", 3, "\xE0\xBA\x94"}, {1, "\xAA", 3, "\xE0\xBA\x95"}, {1, "\xAB", 3, "\xE0\xBA\x96"},
	    {1, "\xAC", 3, "\xE0\xBA\x97"}, {1, "\xAD", 3, "\xE0\xBA\x99"}, {1, "\xAE", 3, "\xE0\xBA\x9A"},
	    {1, "\xAF", 3, "\xE0\xBA\x9B"}, {1, "\xB0", 3, "\xE0\xBA\x9C"}, {1, "\xB1", 3, "\xE0\xBA\x9D"},
	    {1, "\xB2", 3, "\xE0\xBA\x9E"}, {1, "\xB3", 3, "\xE0\xBA\x9F"}, {1, "\xB4", 3, "\xE0\xBA\xA1"},
	    {1, "\xB5", 3, "\xE0\xBA\xA2"}, {1, "\xB6", 3, "\xE0\xBA\xA3"}, {1, "\xB7", 3, "\xE0\xBA\xA5"},
	    {1, "\xB8", 3, "\xE0\xBA\xA7"}, {1, "\xB9", 3, "\xE0\xBA\xAB"}, {1, "\xBA", 3, "\xE0\xBA\xAD"},
	    {1, "\xBB", 3, "\xE0\xBA\xAE"}, {1, "\xBF", 3, "\xE0\xBA\xAF"}, {1, "\xC0", 3, "\xE0\xBA\xB0"},
	    {1, "\xC1", 3, "\xE0\xBA\xB2"}, {1, "\xC2", 3, "\xE0\xBA\xB3"}, {1, "\xC3", 3, "\xE0\xBA\xB4"},
	    {1, "\xC4", 3, "\xE0\xBA\xB5"}, {1, "\xC5", 3, "\xE0\xBA\xB6"}, {1, "\xC6", 3, "\xE0\xBA\xB7"},
	    {1, "\xC7", 3, "\xE0\xBA\xB8"}, {1, "\xC8", 3, "\xE0\xBA\xB9"}, {1, "\xC9", 3, "\xE0\xBA\xBC"},
	    {1, "\xCA", 3, "\xE0\xBA\xB1"}, {1, "\xCB", 3, "\xE0\xBA\xBB"}, {1, "\xCC", 3, "\xE0\xBA\xBD"},
	    {1, "\xD0", 3, "\xE0\xBB\x80"}, {1, "\xD1", 3, "\xE0\xBB\x81"}, {1, "\xD2", 3, "\xE0\xBB\x82"},
	    {1, "\xD3", 3, "\xE0\xBB\x83"}, {1, "\xD4", 3, "\xE0\xBB\x84"}, {1, "\xD5", 3, "\xE0\xBB\x88"},
	    {1, "\xD6", 3, "\xE0\xBB\x89"}, {1, "\xD7", 3, "\xE0\xBB\x8A"}, {1, "\xD8", 3, "\xE0\xBB\x8B"},
	    {1, "\xD9", 3, "\xE0\xBB\x8C"}, {1, "\xDA", 3, "\xE0\xBB\x8D"}, {1, "\xDB", 3, "\xE0\xBB\x86"},
	    {1, "\xDD", 3, "\xE0\xBB\x9C"}, {1, "\xDE", 3, "\xE0\xBB\x9D"}, {1, "\xF0", 3, "\xE0\xBB\x90"},
	    {1, "\xF1", 3, "\xE0\xBB\x91"}, {1, "\xF2", 3, "\xE0\xBB\x92"}, {1, "\xF3", 3, "\xE0\xBB\x93"},
	    {1, "\xF4", 3, "\xE0\xBB\x94"}, {1, "\xF5", 3, "\xE0\xBB\x95"}, {1, "\xF6", 3, "\xE0\xBB\x96"},
	    {1, "\xF7", 3, "\xE0\xBB\x97"}, {1, "\xF8", 3, "\xE0\xBB\x98"}, {1, "\xF9", 3, "\xE0\xBB\x99"},
	    {1, "\xFC", 2, "\xC2\xA2"},     {1, "\xFD", 2, "\xC2\xAC"},     {1, "\xFE", 2, "\xC2\xA6"},
	    {1, "\xFF", 2, "\xC2\xA0"},
	};
	static void Register(const DBConfig &config) {
		const Glibc_ibm1133_2_3_3ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&glibc_IBM1133_2_3_3_to_utf8),
		                                std::size(glibc_IBM1133_2_3_3_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
