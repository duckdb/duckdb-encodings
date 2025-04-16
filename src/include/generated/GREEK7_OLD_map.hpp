//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/GREEK7_OLD_map.hpp
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

class Greek7_oldToUtf {
public:
	Greek7_oldToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "GREEK7_OLD";
	// Generated from: glibc-GREEK7_OLD-2.1.2.ucm
	static constexpr map_entry GREEK7_OLD_to_utf8[] = {
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
	    {1, "\x21", 1, "\x21"},         {1, "\x22", 1, "\x22"},         {1, "\x23", 2, "\xC2\xA3"},
	    {1, "\x24", 1, "\x24"},         {1, "\x25", 1, "\x25"},         {1, "\x26", 1, "\x26"},
	    {1, "\x27", 1, "\x27"},         {1, "\x28", 1, "\x28"},         {1, "\x29", 1, "\x29"},
	    {1, "\x2A", 1, "\x2A"},         {1, "\x2B", 1, "\x2B"},         {1, "\x2C", 1, "\x2C"},
	    {1, "\x2D", 1, "\x2D"},         {1, "\x2E", 1, "\x2E"},         {1, "\x2F", 1, "\x2F"},
	    {1, "\x30", 1, "\x30"},         {1, "\x31", 1, "\x31"},         {1, "\x32", 1, "\x32"},
	    {1, "\x33", 1, "\x33"},         {1, "\x34", 1, "\x34"},         {1, "\x35", 1, "\x35"},
	    {1, "\x36", 1, "\x36"},         {1, "\x37", 1, "\x37"},         {1, "\x38", 1, "\x38"},
	    {1, "\x39", 1, "\x39"},         {1, "\x3A", 1, "\x3A"},         {1, "\x3B", 1, "\x3B"},
	    {1, "\x3C", 1, "\x3C"},         {1, "\x3D", 1, "\x3D"},         {1, "\x3E", 1, "\x3E"},
	    {1, "\x3F", 1, "\x3F"},         {1, "\x40", 2, "\xC2\xB4"},     {1, "\x41", 2, "\xCE\xB1"},
	    {1, "\x42", 2, "\xCE\xB2"},     {1, "\x43", 2, "\xCF\x88"},     {1, "\x44", 2, "\xCE\xB4"},
	    {1, "\x45", 2, "\xCE\xB5"},     {1, "\x46", 2, "\xCF\x86"},     {1, "\x47", 2, "\xCE\xB3"},
	    {1, "\x48", 2, "\xCE\xB7"},     {1, "\x49", 2, "\xCE\xB9"},     {1, "\x4A", 2, "\xCE\xBE"},
	    {1, "\x4B", 2, "\xCE\xBA"},     {1, "\x4C", 2, "\xCE\xBB"},     {1, "\x4D", 2, "\xCE\xBC"},
	    {1, "\x4E", 2, "\xCE\xBD"},     {1, "\x4F", 2, "\xCE\xBF"},     {1, "\x50", 2, "\xCF\x80"},
	    {1, "\x51", 2, "\xCD\xBA"},     {1, "\x52", 2, "\xCF\x81"},     {1, "\x53", 2, "\xCF\x83"},
	    {1, "\x54", 2, "\xCF\x84"},     {1, "\x55", 2, "\xCE\xB8"},     {1, "\x56", 2, "\xCF\x89"},
	    {1, "\x57", 2, "\xCF\x82"},     {1, "\x58", 2, "\xCF\x87"},     {1, "\x59", 2, "\xCF\x85"},
	    {1, "\x5A", 2, "\xCE\xB6"},     {1, "\x5B", 3, "\xE1\xBF\x8F"}, {1, "\x5C", 3, "\xE1\xBE\xBF"},
	    {1, "\x5D", 3, "\xE1\xBF\x8E"}, {1, "\x5E", 1, "\x7E"},         {1, "\x5F", 1, "\x5F"},
	    {1, "\x60", 1, "\x60"},         {1, "\x61", 2, "\xCE\x91"},     {1, "\x62", 2, "\xCE\x92"},
	    {1, "\x63", 2, "\xCE\xA8"},     {1, "\x64", 2, "\xCE\x94"},     {1, "\x65", 2, "\xCE\x95"},
	    {1, "\x66", 2, "\xCE\xA6"},     {1, "\x67", 2, "\xCE\x93"},     {1, "\x68", 2, "\xCE\x97"},
	    {1, "\x69", 2, "\xCE\x99"},     {1, "\x6A", 2, "\xCE\x9E"},     {1, "\x6B", 2, "\xCE\x9A"},
	    {1, "\x6C", 2, "\xCE\x9B"},     {1, "\x6D", 2, "\xCE\x9C"},     {1, "\x6E", 2, "\xCE\x9D"},
	    {1, "\x6F", 2, "\xCE\x9F"},     {1, "\x70", 2, "\xCE\xA0"},     {1, "\x72", 2, "\xCE\xA1"},
	    {1, "\x73", 2, "\xCE\xA3"},     {1, "\x74", 2, "\xCE\xA4"},     {1, "\x75", 2, "\xCE\x98"},
	    {1, "\x76", 2, "\xCE\xA9"},     {1, "\x77", 2, "\xC2\xB7"},     {1, "\x78", 2, "\xCE\xA7"},
	    {1, "\x79", 2, "\xCE\xA5"},     {1, "\x7A", 2, "\xCE\x96"},     {1, "\x7B", 3, "\xE1\xBF\x9F"},
	    {1, "\x7C", 3, "\xE1\xBF\xBE"}, {1, "\x7D", 3, "\xE1\xBF\x9E"}, {1, "\x7E", 2, "\xC2\xA8"},
	    {1, "\x7F", 1, "\x7F"},
	};
	static void Register(const DBConfig &config) {
		const Greek7_oldToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&GREEK7_OLD_to_utf8),
		                                std::size(GREEK7_OLD_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
