//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/macos-520-10.2_map.hpp
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

class Macos_520_10_2ToUtf {
public:
	Macos_520_10_2ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "macos-520-10.2";
	// Generated from: macos-520-10.2.ucm
	static constexpr map_entry macos_520_10_2_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},         {1, "\x01", 1, "\x01"},         {1, "\x02", 1, "\x02"},
	    {1, "\x03", 1, "\x03"},         {1, "\x04", 1, "\x04"},         {1, "\x05", 1, "\x05"},
	    {1, "\x06", 1, "\x06"},         {1, "\x07", 1, "\x07"},         {1, "\x08", 1, "\x08"},
	    {1, "\x09", 1, "\x09"},         {1, "\x0A", 3, "\xE2\x80\xA8"}, {1, "\x0B", 1, "\x0B"},
	    {1, "\x0C", 1, "\x0C"},         {1, "\x0D", 3, "\xE2\x80\xA9"}, {1, "\x0E", 1, "\x0E"},
	    {1, "\x0F", 1, "\x0F"},         {1, "\x10", 1, "\x10"},         {1, "\x11", 1, "\x11"},
	    {1, "\x12", 1, "\x12"},         {1, "\x13", 1, "\x13"},         {1, "\x14", 1, "\x14"},
	    {1, "\x15", 1, "\x15"},         {1, "\x16", 1, "\x16"},         {1, "\x17", 1, "\x17"},
	    {1, "\x18", 1, "\x18"},         {1, "\x19", 1, "\x19"},         {1, "\x1A", 1, "\x1A"},
	    {1, "\x1B", 1, "\x1B"},         {1, "\x1C", 1, "\x1C"},         {1, "\x1D", 1, "\x1D"},
	    {1, "\x1E", 1, "\x1E"},         {1, "\x1F", 1, "\x1F"},         {1, "\x20", 3, "\xE2\x80\x89"},
	    {1, "\x21", 1, "\x21"},         {1, "\x22", 1, "\x22"},         {1, "\x23", 1, "\x23"},
	    {1, "\x24", 1, "\x24"},         {1, "\x25", 1, "\x25"},         {1, "\x26", 1, "\x26"},
	    {1, "\x27", 1, "\x27"},         {1, "\x28", 1, "\x28"},         {1, "\x29", 1, "\x29"},
	    {1, "\x2A", 3, "\xE2\x88\x97"}, {1, "\x2B", 1, "\x2B"},         {1, "\x2C", 1, "\x2C"},
	    {1, "\x2D", 3, "\xE2\x88\x92"}, {1, "\x2E", 1, "\x2E"},         {1, "\x2F", 3, "\xE2\x88\x95"},
	    {1, "\x30", 1, "\x30"},         {1, "\x31", 1, "\x31"},         {1, "\x32", 1, "\x32"},
	    {1, "\x33", 1, "\x33"},         {1, "\x34", 1, "\x34"},         {1, "\x35", 1, "\x35"},
	    {1, "\x36", 1, "\x36"},         {1, "\x37", 1, "\x37"},         {1, "\x38", 1, "\x38"},
	    {1, "\x39", 1, "\x39"},         {1, "\x3A", 3, "\xE2\x88\xB6"}, {1, "\x3B", 1, "\x3B"},
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
	    {1, "\x60", 2, "\xCC\x80"},     {1, "\x61", 1, "\x61"},         {1, "\x62", 1, "\x62"},
	    {1, "\x63", 1, "\x63"},         {1, "\x64", 1, "\x64"},         {1, "\x65", 1, "\x65"},
	    {1, "\x66", 1, "\x66"},         {1, "\x67", 1, "\x67"},         {1, "\x68", 1, "\x68"},
	    {1, "\x69", 1, "\x69"},         {1, "\x6A", 1, "\x6A"},         {1, "\x6B", 1, "\x6B"},
	    {1, "\x6C", 1, "\x6C"},         {1, "\x6D", 1, "\x6D"},         {1, "\x6E", 1, "\x6E"},
	    {1, "\x6F", 1, "\x6F"},         {1, "\x70", 1, "\x70"},         {1, "\x71", 1, "\x71"},
	    {1, "\x72", 1, "\x72"},         {1, "\x73", 1, "\x73"},         {1, "\x74", 1, "\x74"},
	    {1, "\x75", 1, "\x75"},         {1, "\x76", 1, "\x76"},         {1, "\x77", 1, "\x77"},
	    {1, "\x78", 1, "\x78"},         {1, "\x79", 1, "\x79"},         {1, "\x7A", 1, "\x7A"},
	    {1, "\x7B", 1, "\x7B"},         {1, "\x7C", 1, "\x7C"},         {1, "\x7D", 1, "\x7D"},
	    {1, "\x7E", 3, "\xE2\x88\xBC"}, {1, "\x7F", 1, "\x7F"},         {1, "\xA0", 2, "\xC2\xA0"},
	    {1, "\xA2", 2, "\xC2\xA2"},     {1, "\xA3", 2, "\xC2\xA3"},     {1, "\xA4", 2, "\xC2\xA4"},
	    {1, "\xA5", 2, "\xC2\xA5"},     {1, "\xA6", 2, "\xC2\xA6"},     {1, "\xA7", 2, "\xC2\xA7"},
	    {1, "\xA8", 2, "\xC2\xA8"},     {1, "\xA9", 2, "\xC2\xA9"},     {1, "\xAA", 2, "\xC3\x97"},
	    {1, "\xAB", 2, "\xC2\xAB"},     {1, "\xAC", 2, "\xC2\xAC"},     {1, "\xAD", 2, "\xC2\xAD"},
	    {1, "\xAE", 2, "\xC2\xAE"},     {1, "\xAF", 3, "\xE2\x80\xBE"}, {1, "\xB0", 2, "\xC2\xB0"},
	    {1, "\xB1", 2, "\xC2\xB1"},     {1, "\xB2", 2, "\xC2\xB2"},     {1, "\xB3", 2, "\xC2\xB3"},
	    {1, "\xB4", 2, "\xC2\xB4"},     {1, "\xB5", 2, "\xC2\xB5"},     {1, "\xB6", 2, "\xC2\xB6"},
	    {1, "\xB7", 2, "\xC2\xB7"},     {1, "\xB8", 2, "\xC2\xB8"},     {1, "\xB9", 2, "\xC2\xB9"},
	    {1, "\xBA", 2, "\xC3\xB7"},     {1, "\xBB", 2, "\xC2\xBB"},     {1, "\xBC", 2, "\xC2\xBC"},
	    {1, "\xBD", 2, "\xC2\xBD"},     {1, "\xBE", 2, "\xC2\xBE"},     {1, "\xDF", 3, "\xE2\x80\x97"},
	    {1, "\xE0", 2, "\xD7\x90"},     {1, "\xE1", 2, "\xD7\x91"},     {1, "\xE2", 2, "\xD7\x92"},
	    {1, "\xE3", 2, "\xD7\x93"},     {1, "\xE4", 2, "\xD7\x94"},     {1, "\xE5", 2, "\xD7\x95"},
	    {1, "\xE6", 2, "\xD7\x96"},     {1, "\xE7", 2, "\xD7\x97"},     {1, "\xE8", 2, "\xD7\x98"},
	    {1, "\xE9", 2, "\xD7\x99"},     {1, "\xEA", 2, "\xD7\x9A"},     {1, "\xEB", 2, "\xD7\x9B"},
	    {1, "\xEC", 2, "\xD7\x9C"},     {1, "\xED", 2, "\xD7\x9D"},     {1, "\xEE", 2, "\xD7\x9E"},
	    {1, "\xEF", 2, "\xD7\x9F"},     {1, "\xF0", 2, "\xD7\xA0"},     {1, "\xF1", 2, "\xD7\xA1"},
	    {1, "\xF2", 2, "\xD7\xA2"},     {1, "\xF3", 2, "\xD7\xA3"},     {1, "\xF4", 2, "\xD7\xA4"},
	    {1, "\xF5", 2, "\xD7\xA5"},     {1, "\xF6", 2, "\xD7\xA6"},     {1, "\xF7", 2, "\xD7\xA7"},
	    {1, "\xF8", 2, "\xD7\xA8"},     {1, "\xF9", 2, "\xD7\xA9"},     {1, "\xFA", 2, "\xD7\xAA"},
	};
	static void Register(const DBConfig &config) {
		const Macos_520_10_2ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&macos_520_10_2_to_utf8),
		                                std::size(macos_520_10_2_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
