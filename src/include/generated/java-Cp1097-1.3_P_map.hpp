//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/java-Cp1097-1.3_P_map.hpp
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

class Java_cp1097_1_3_pToUtf {
public:
	Java_cp1097_1_3_pToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "java-Cp1097-1.3_P";
	// Generated from: java-Cp1097-1.3_P.ucm
	static constexpr map_entry java_Cp1097_1_3_P_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},         {1, "\x01", 1, "\x01"},         {1, "\x02", 1, "\x02"},
	    {1, "\x03", 1, "\x03"},         {1, "\x04", 2, "\xC2\x9C"},     {1, "\x05", 1, "\x09"},
	    {1, "\x06", 2, "\xC2\x86"},     {1, "\x07", 1, "\x7F"},         {1, "\x08", 2, "\xC2\x97"},
	    {1, "\x09", 2, "\xC2\x8D"},     {1, "\x0A", 2, "\xC2\x8E"},     {1, "\x0B", 1, "\x0B"},
	    {1, "\x0C", 1, "\x0C"},         {1, "\x0D", 1, "\x0D"},         {1, "\x0E", 1, "\x0E"},
	    {1, "\x0F", 1, "\x0F"},         {1, "\x10", 1, "\x10"},         {1, "\x11", 1, "\x11"},
	    {1, "\x12", 1, "\x12"},         {1, "\x13", 1, "\x13"},         {1, "\x14", 2, "\xC2\x9D"},
	    {1, "\x15", 2, "\xC2\x85"},     {1, "\x16", 1, "\x08"},         {1, "\x17", 2, "\xC2\x87"},
	    {1, "\x18", 1, "\x18"},         {1, "\x19", 1, "\x19"},         {1, "\x1A", 2, "\xC2\x92"},
	    {1, "\x1B", 2, "\xC2\x8F"},     {1, "\x1C", 1, "\x1C"},         {1, "\x1D", 1, "\x1D"},
	    {1, "\x1E", 1, "\x1E"},         {1, "\x1F", 1, "\x1F"},         {1, "\x20", 2, "\xC2\x80"},
	    {1, "\x21", 2, "\xC2\x81"},     {1, "\x22", 2, "\xC2\x82"},     {1, "\x23", 2, "\xC2\x83"},
	    {1, "\x24", 2, "\xC2\x84"},     {1, "\x25", 1, "\x0A"},         {1, "\x26", 1, "\x17"},
	    {1, "\x27", 1, "\x1B"},         {1, "\x28", 2, "\xC2\x88"},     {1, "\x29", 2, "\xC2\x89"},
	    {1, "\x2A", 2, "\xC2\x8A"},     {1, "\x2B", 2, "\xC2\x8B"},     {1, "\x2C", 2, "\xC2\x8C"},
	    {1, "\x2D", 1, "\x05"},         {1, "\x2E", 1, "\x06"},         {1, "\x2F", 1, "\x07"},
	    {1, "\x30", 2, "\xC2\x90"},     {1, "\x31", 2, "\xC2\x91"},     {1, "\x32", 1, "\x16"},
	    {1, "\x33", 2, "\xC2\x93"},     {1, "\x34", 2, "\xC2\x94"},     {1, "\x35", 2, "\xC2\x95"},
	    {1, "\x36", 2, "\xC2\x96"},     {1, "\x37", 1, "\x04"},         {1, "\x38", 2, "\xC2\x98"},
	    {1, "\x39", 2, "\xC2\x99"},     {1, "\x3A", 2, "\xC2\x9A"},     {1, "\x3B", 2, "\xC2\x9B"},
	    {1, "\x3C", 1, "\x14"},         {1, "\x3D", 1, "\x15"},         {1, "\x3E", 2, "\xC2\x9E"},
	    {1, "\x40", 1, "\x20"},         {1, "\x41", 2, "\xC2\xA0"},     {1, "\x42", 2, "\xD8\x8C"},
	    {1, "\x43", 2, "\xD9\x8B"},     {1, "\x44", 3, "\xEF\xBA\x81"}, {1, "\x45", 3, "\xEF\xBA\x82"},
	    {1, "\x46", 3, "\xEF\xA3\xBA"}, {1, "\x47", 3, "\xEF\xBA\x8D"}, {1, "\x48", 3, "\xEF\xBA\x8E"},
	    {1, "\x49", 3, "\xEF\xA3\xBB"}, {1, "\x4A", 2, "\xC2\xA4"},     {1, "\x4B", 1, "\x2E"},
	    {1, "\x4C", 1, "\x3C"},         {1, "\x4D", 1, "\x28"},         {1, "\x4E", 1, "\x2B"},
	    {1, "\x4F", 1, "\x7C"},         {1, "\x50", 1, "\x26"},         {1, "\x51", 3, "\xEF\xBA\x80"},
	    {1, "\x52", 3, "\xEF\xBA\x83"}, {1, "\x53", 3, "\xEF\xBA\x84"}, {1, "\x54", 3, "\xEF\xA3\xB9"},
	    {1, "\x55", 3, "\xEF\xBA\x85"}, {1, "\x56", 3, "\xEF\xBA\x8B"}, {1, "\x57", 3, "\xEF\xBA\x8F"},
	    {1, "\x58", 3, "\xEF\xBA\x91"}, {1, "\x59", 3, "\xEF\xAD\x96"}, {1, "\x5A", 1, "\x21"},
	    {1, "\x5B", 1, "\x24"},         {1, "\x5C", 1, "\x2A"},         {1, "\x5D", 1, "\x29"},
	    {1, "\x5E", 1, "\x3B"},         {1, "\x5F", 2, "\xC2\xAC"},     {1, "\x60", 1, "\x2D"},
	    {1, "\x61", 1, "\x2F"},         {1, "\x62", 3, "\xEF\xAD\x98"}, {1, "\x63", 3, "\xEF\xBA\x95"},
	    {1, "\x64", 3, "\xEF\xBA\x97"}, {1, "\x65", 3, "\xEF\xBA\x99"}, {1, "\x66", 3, "\xEF\xBA\x9B"},
	    {1, "\x67", 3, "\xEF\xBA\x9D"}, {1, "\x68", 3, "\xEF\xBA\x9F"}, {1, "\x69", 3, "\xEF\xAD\xBA"},
	    {1, "\x6A", 2, "\xD8\x9B"},     {1, "\x6B", 1, "\x2C"},         {1, "\x6C", 1, "\x25"},
	    {1, "\x6D", 1, "\x5F"},         {1, "\x6E", 1, "\x3E"},         {1, "\x6F", 1, "\x3F"},
	    {1, "\x70", 3, "\xEF\xAD\xBC"}, {1, "\x71", 3, "\xEF\xBA\xA1"}, {1, "\x72", 3, "\xEF\xBA\xA3"},
	    {1, "\x73", 3, "\xEF\xBA\xA5"}, {1, "\x74", 3, "\xEF\xBA\xA7"}, {1, "\x75", 3, "\xEF\xBA\xA9"},
	    {1, "\x76", 3, "\xEF\xBA\xAB"}, {1, "\x77", 3, "\xEF\xBA\xAD"}, {1, "\x78", 3, "\xEF\xBA\xAF"},
	    {1, "\x79", 1, "\x60"},         {1, "\x7A", 1, "\x3A"},         {1, "\x7B", 1, "\x23"},
	    {1, "\x7C", 1, "\x40"},         {1, "\x7D", 1, "\x27"},         {1, "\x7E", 1, "\x3D"},
	    {1, "\x7F", 1, "\x22"},         {1, "\x80", 3, "\xEF\xAE\x8A"}, {1, "\x81", 1, "\x61"},
	    {1, "\x82", 1, "\x62"},         {1, "\x83", 1, "\x63"},         {1, "\x84", 1, "\x64"},
	    {1, "\x85", 1, "\x65"},         {1, "\x86", 1, "\x66"},         {1, "\x87", 1, "\x67"},
	    {1, "\x88", 1, "\x68"},         {1, "\x89", 1, "\x69"},         {1, "\x8A", 2, "\xC2\xAB"},
	    {1, "\x8B", 2, "\xC2\xBB"},     {1, "\x8C", 3, "\xEF\xBA\xB1"}, {1, "\x8D", 3, "\xEF\xBA\xB3"},
	    {1, "\x8E", 3, "\xEF\xBA\xB5"}, {1, "\x8F", 3, "\xEF\xBA\xB7"}, {1, "\x90", 3, "\xEF\xBA\xB9"},
	    {1, "\x91", 1, "\x6A"},         {1, "\x92", 1, "\x6B"},         {1, "\x93", 1, "\x6C"},
	    {1, "\x94", 1, "\x6D"},         {1, "\x95", 1, "\x6E"},         {1, "\x96", 1, "\x6F"},
	    {1, "\x97", 1, "\x70"},         {1, "\x98", 1, "\x71"},         {1, "\x99", 1, "\x72"},
	    {1, "\x9A", 3, "\xEF\xBA\xBB"}, {1, "\x9B", 3, "\xEF\xBA\xBD"}, {1, "\x9C", 3, "\xEF\xBA\xBF"},
	    {1, "\x9D", 3, "\xEF\xBB\x81"}, {1, "\x9E", 3, "\xEF\xBB\x83"}, {1, "\x9F", 3, "\xEF\xBB\x85"},
	    {1, "\xA0", 3, "\xEF\xBB\x87"}, {1, "\xA1", 1, "\x7E"},         {1, "\xA2", 1, "\x73"},
	    {1, "\xA3", 1, "\x74"},         {1, "\xA4", 1, "\x75"},         {1, "\xA5", 1, "\x76"},
	    {1, "\xA6", 1, "\x77"},         {1, "\xA7", 1, "\x78"},         {1, "\xA8", 1, "\x79"},
	    {1, "\xA9", 1, "\x7A"},         {1, "\xAA", 3, "\xEF\xBB\x89"}, {1, "\xAB", 3, "\xEF\xBB\x8A"},
	    {1, "\xAC", 3, "\xEF\xBB\x8B"}, {1, "\xAD", 3, "\xEF\xBB\x8C"}, {1, "\xAE", 3, "\xEF\xBB\x8D"},
	    {1, "\xAF", 3, "\xEF\xBB\x8E"}, {1, "\xB0", 3, "\xEF\xBB\x8F"}, {1, "\xB1", 3, "\xEF\xBB\x90"},
	    {1, "\xB2", 3, "\xEF\xBB\x91"}, {1, "\xB3", 3, "\xEF\xBB\x93"}, {1, "\xB4", 3, "\xEF\xBB\x95"},
	    {1, "\xB5", 3, "\xEF\xBB\x97"}, {1, "\xB6", 3, "\xEF\xAE\x8E"}, {1, "\xB7", 3, "\xEF\xBB\x9B"},
	    {1, "\xB8", 3, "\xEF\xAE\x92"}, {1, "\xB9", 3, "\xEF\xAE\x94"}, {1, "\xBA", 1, "\x5B"},
	    {1, "\xBB", 1, "\x5D"},         {1, "\xBC", 3, "\xEF\xBB\x9D"}, {1, "\xBD", 3, "\xEF\xBB\x9F"},
	    {1, "\xBE", 3, "\xEF\xBB\xA1"}, {1, "\xBF", 2, "\xC3\x97"},     {1, "\xC0", 1, "\x7B"},
	    {1, "\xC1", 1, "\x41"},         {1, "\xC2", 1, "\x42"},         {1, "\xC3", 1, "\x43"},
	    {1, "\xC4", 1, "\x44"},         {1, "\xC5", 1, "\x45"},         {1, "\xC6", 1, "\x46"},
	    {1, "\xC7", 1, "\x47"},         {1, "\xC8", 1, "\x48"},         {1, "\xC9", 1, "\x49"},
	    {1, "\xCA", 2, "\xC2\xAD"},     {1, "\xCB", 3, "\xEF\xBB\xA3"}, {1, "\xCC", 3, "\xEF\xBB\xA5"},
	    {1, "\xCD", 3, "\xEF\xBB\xA7"}, {1, "\xCE", 3, "\xEF\xBB\xAD"}, {1, "\xCF", 3, "\xEF\xBB\xA9"},
	    {1, "\xD0", 1, "\x7D"},         {1, "\xD1", 1, "\x4A"},         {1, "\xD2", 1, "\x4B"},
	    {1, "\xD3", 1, "\x4C"},         {1, "\xD4", 1, "\x4D"},         {1, "\xD5", 1, "\x4E"},
	    {1, "\xD6", 1, "\x4F"},         {1, "\xD7", 1, "\x50"},         {1, "\xD8", 1, "\x51"},
	    {1, "\xD9", 1, "\x52"},         {1, "\xDA", 3, "\xEF\xBB\xAB"}, {1, "\xDB", 3, "\xEF\xBB\xAC"},
	    {1, "\xDC", 3, "\xEF\xAE\xA4"}, {1, "\xDD", 3, "\xEF\xAF\xBC"}, {1, "\xDE", 3, "\xEF\xAF\xBD"},
	    {1, "\xDF", 3, "\xEF\xAF\xBE"}, {1, "\xE0", 1, "\x5C"},         {1, "\xE1", 2, "\xD8\x9F"},
	    {1, "\xE2", 1, "\x53"},         {1, "\xE3", 1, "\x54"},         {1, "\xE4", 1, "\x55"},
	    {1, "\xE5", 1, "\x56"},         {1, "\xE6", 1, "\x57"},         {1, "\xE7", 1, "\x58"},
	    {1, "\xE8", 1, "\x59"},         {1, "\xE9", 1, "\x5A"},         {1, "\xEA", 2, "\xD9\x80"},
	    {1, "\xEB", 2, "\xDB\xB0"},     {1, "\xEC", 2, "\xDB\xB1"},     {1, "\xED", 2, "\xDB\xB2"},
	    {1, "\xEE", 2, "\xDB\xB3"},     {1, "\xEF", 2, "\xDB\xB4"},     {1, "\xF0", 1, "\x30"},
	    {1, "\xF1", 1, "\x31"},         {1, "\xF2", 1, "\x32"},         {1, "\xF3", 1, "\x33"},
	    {1, "\xF4", 1, "\x34"},         {1, "\xF5", 1, "\x35"},         {1, "\xF6", 1, "\x36"},
	    {1, "\xF7", 1, "\x37"},         {1, "\xF8", 1, "\x38"},         {1, "\xF9", 1, "\x39"},
	    {1, "\xFA", 2, "\xDB\xB5"},     {1, "\xFB", 2, "\xDB\xB6"},     {1, "\xFC", 2, "\xDB\xB7"},
	    {1, "\xFD", 2, "\xDB\xB8"},     {1, "\xFE", 2, "\xDB\xB9"},     {1, "\xFF", 2, "\xC2\x9F"},
	};
	static void Register(const DBConfig &config) {
		const Java_cp1097_1_3_pToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&java_Cp1097_1_3_P_to_utf8),
		                                std::size(java_Cp1097_1_3_P_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
