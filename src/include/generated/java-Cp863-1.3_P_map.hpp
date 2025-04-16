//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/java-Cp863-1.3_P_map.hpp
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

class Java_cp863_1_3_pToUtf {
public:
	Java_cp863_1_3_pToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "java-Cp863-1.3_P";
	// Generated from: java-Cp863-1.3_P.ucm
	static constexpr map_entry java_Cp863_1_3_P_to_utf8[] = {
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
	    {1, "\x7E", 1, "\x7E"},         {1, "\x7F", 1, "\x7F"},         {1, "\x80", 2, "\xC3\x87"},
	    {1, "\x81", 2, "\xC3\xBC"},     {1, "\x82", 2, "\xC3\xA9"},     {1, "\x83", 2, "\xC3\xA2"},
	    {1, "\x84", 2, "\xC3\x82"},     {1, "\x85", 2, "\xC3\xA0"},     {1, "\x86", 2, "\xC2\xB6"},
	    {1, "\x87", 2, "\xC3\xA7"},     {1, "\x88", 2, "\xC3\xAA"},     {1, "\x89", 2, "\xC3\xAB"},
	    {1, "\x8A", 2, "\xC3\xA8"},     {1, "\x8B", 2, "\xC3\xAF"},     {1, "\x8C", 2, "\xC3\xAE"},
	    {1, "\x8D", 3, "\xE2\x80\x97"}, {1, "\x8E", 2, "\xC3\x80"},     {1, "\x8F", 2, "\xC2\xA7"},
	    {1, "\x90", 2, "\xC3\x89"},     {1, "\x91", 2, "\xC3\x88"},     {1, "\x92", 2, "\xC3\x8A"},
	    {1, "\x93", 2, "\xC3\xB4"},     {1, "\x94", 2, "\xC3\x8B"},     {1, "\x95", 2, "\xC3\x8F"},
	    {1, "\x96", 2, "\xC3\xBB"},     {1, "\x97", 2, "\xC3\xB9"},     {1, "\x98", 2, "\xC2\xA4"},
	    {1, "\x99", 2, "\xC3\x94"},     {1, "\x9A", 2, "\xC3\x9C"},     {1, "\x9B", 2, "\xC2\xA2"},
	    {1, "\x9C", 2, "\xC2\xA3"},     {1, "\x9D", 2, "\xC3\x99"},     {1, "\x9E", 2, "\xC3\x9B"},
	    {1, "\x9F", 2, "\xC6\x92"},     {1, "\xA0", 2, "\xC2\xA6"},     {1, "\xA1", 2, "\xC2\xB4"},
	    {1, "\xA2", 2, "\xC3\xB3"},     {1, "\xA3", 2, "\xC3\xBA"},     {1, "\xA4", 2, "\xC2\xA8"},
	    {1, "\xA5", 2, "\xC2\xB8"},     {1, "\xA6", 2, "\xC2\xB3"},     {1, "\xA7", 2, "\xC2\xAF"},
	    {1, "\xA8", 2, "\xC3\x8E"},     {1, "\xA9", 3, "\xE2\x8C\x90"}, {1, "\xAA", 2, "\xC2\xAC"},
	    {1, "\xAB", 2, "\xC2\xBD"},     {1, "\xAC", 2, "\xC2\xBC"},     {1, "\xAD", 2, "\xC2\xBE"},
	    {1, "\xAE", 2, "\xC2\xAB"},     {1, "\xAF", 2, "\xC2\xBB"},     {1, "\xB0", 3, "\xE2\x96\x91"},
	    {1, "\xB1", 3, "\xE2\x96\x92"}, {1, "\xB2", 3, "\xE2\x96\x93"}, {1, "\xB3", 3, "\xE2\x94\x82"},
	    {1, "\xB4", 3, "\xE2\x94\xA4"}, {1, "\xB5", 3, "\xE2\x95\xA1"}, {1, "\xB6", 3, "\xE2\x95\xA2"},
	    {1, "\xB7", 3, "\xE2\x95\x96"}, {1, "\xB8", 3, "\xE2\x95\x95"}, {1, "\xB9", 3, "\xE2\x95\xA3"},
	    {1, "\xBA", 3, "\xE2\x95\x91"}, {1, "\xBB", 3, "\xE2\x95\x97"}, {1, "\xBC", 3, "\xE2\x95\x9D"},
	    {1, "\xBD", 3, "\xE2\x95\x9C"}, {1, "\xBE", 3, "\xE2\x95\x9B"}, {1, "\xBF", 3, "\xE2\x94\x90"},
	    {1, "\xC0", 3, "\xE2\x94\x94"}, {1, "\xC1", 3, "\xE2\x94\xB4"}, {1, "\xC2", 3, "\xE2\x94\xAC"},
	    {1, "\xC3", 3, "\xE2\x94\x9C"}, {1, "\xC4", 3, "\xE2\x94\x80"}, {1, "\xC5", 3, "\xE2\x94\xBC"},
	    {1, "\xC6", 3, "\xE2\x95\x9E"}, {1, "\xC7", 3, "\xE2\x95\x9F"}, {1, "\xC8", 3, "\xE2\x95\x9A"},
	    {1, "\xC9", 3, "\xE2\x95\x94"}, {1, "\xCA", 3, "\xE2\x95\xA9"}, {1, "\xCB", 3, "\xE2\x95\xA6"},
	    {1, "\xCC", 3, "\xE2\x95\xA0"}, {1, "\xCD", 3, "\xE2\x95\x90"}, {1, "\xCE", 3, "\xE2\x95\xAC"},
	    {1, "\xCF", 3, "\xE2\x95\xA7"}, {1, "\xD0", 3, "\xE2\x95\xA8"}, {1, "\xD1", 3, "\xE2\x95\xA4"},
	    {1, "\xD2", 3, "\xE2\x95\xA5"}, {1, "\xD3", 3, "\xE2\x95\x99"}, {1, "\xD4", 3, "\xE2\x95\x98"},
	    {1, "\xD5", 3, "\xE2\x95\x92"}, {1, "\xD6", 3, "\xE2\x95\x93"}, {1, "\xD7", 3, "\xE2\x95\xAB"},
	    {1, "\xD8", 3, "\xE2\x95\xAA"}, {1, "\xD9", 3, "\xE2\x94\x98"}, {1, "\xDA", 3, "\xE2\x94\x8C"},
	    {1, "\xDB", 3, "\xE2\x96\x88"}, {1, "\xDC", 3, "\xE2\x96\x84"}, {1, "\xDD", 3, "\xE2\x96\x8C"},
	    {1, "\xDE", 3, "\xE2\x96\x90"}, {1, "\xDF", 3, "\xE2\x96\x80"}, {1, "\xE0", 2, "\xCE\xB1"},
	    {1, "\xE1", 2, "\xC3\x9F"},     {1, "\xE2", 2, "\xCE\x93"},     {1, "\xE3", 2, "\xCF\x80"},
	    {1, "\xE4", 2, "\xCE\xA3"},     {1, "\xE5", 2, "\xCF\x83"},     {1, "\xE6", 2, "\xC2\xB5"},
	    {1, "\xE7", 2, "\xCF\x84"},     {1, "\xE8", 2, "\xCE\xA6"},     {1, "\xE9", 2, "\xCE\x98"},
	    {1, "\xEA", 2, "\xCE\xA9"},     {1, "\xEB", 2, "\xCE\xB4"},     {1, "\xEC", 3, "\xE2\x88\x9E"},
	    {1, "\xED", 2, "\xCF\x86"},     {1, "\xEE", 2, "\xCE\xB5"},     {1, "\xEF", 3, "\xE2\x88\xA9"},
	    {1, "\xF0", 3, "\xE2\x89\xA1"}, {1, "\xF1", 2, "\xC2\xB1"},     {1, "\xF2", 3, "\xE2\x89\xA5"},
	    {1, "\xF3", 3, "\xE2\x89\xA4"}, {1, "\xF4", 3, "\xE2\x8C\xA0"}, {1, "\xF5", 3, "\xE2\x8C\xA1"},
	    {1, "\xF6", 2, "\xC3\xB7"},     {1, "\xF7", 3, "\xE2\x89\x88"}, {1, "\xF8", 2, "\xC2\xB0"},
	    {1, "\xF9", 3, "\xE2\x88\x99"}, {1, "\xFA", 2, "\xC2\xB7"},     {1, "\xFB", 3, "\xE2\x88\x9A"},
	    {1, "\xFC", 3, "\xE2\x81\xBF"}, {1, "\xFD", 2, "\xC2\xB2"},     {1, "\xFE", 3, "\xE2\x96\xA0"},
	    {1, "\xFF", 2, "\xC2\xA0"},
	};
	static void Register(const DBConfig &config) {
		const Java_cp863_1_3_pToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&java_Cp863_1_3_P_to_utf8),
		                                std::size(java_Cp863_1_3_P_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
