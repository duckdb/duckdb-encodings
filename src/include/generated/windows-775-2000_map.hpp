//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/windows-775-2000_map.hpp
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

class Windows_775_2000ToUtf {
public:
	Windows_775_2000ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "windows-775-2000";
	// Generated from: windows-775-2000.ucm
	static constexpr map_entry windows_775_2000_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},         {1, "\x01", 3, "\xE2\x98\xBA"}, {1, "\x02", 3, "\xE2\x98\xBB"},
	    {1, "\x03", 3, "\xE2\x99\xA5"}, {1, "\x04", 3, "\xE2\x99\xA6"}, {1, "\x05", 3, "\xE2\x99\xA3"},
	    {1, "\x06", 3, "\xE2\x99\xA0"}, {1, "\x07", 3, "\xE3\x83\xBB"}, {1, "\x08", 3, "\xE2\x97\x98"},
	    {1, "\x09", 3, "\xE2\x97\x8B"}, {1, "\x0A", 3, "\xE2\x97\x99"}, {1, "\x0B", 3, "\xE2\x99\x82"},
	    {1, "\x0C", 3, "\xE2\x99\x80"}, {1, "\x0D", 3, "\xE2\x99\xAA"}, {1, "\x0E", 3, "\xE2\x99\xAB"},
	    {1, "\x0F", 3, "\xE2\x98\xBC"}, {1, "\x10", 3, "\xE2\x96\xBA"}, {1, "\x11", 3, "\xE2\x97\x84"},
	    {1, "\x12", 3, "\xE2\x86\x95"}, {1, "\x13", 3, "\xE2\x80\xBC"}, {1, "\x14", 1, "\x14"},
	    {1, "\x15", 1, "\x15"},         {1, "\x16", 3, "\xE2\x96\xAC"}, {1, "\x17", 3, "\xE2\x86\xA8"},
	    {1, "\x18", 3, "\xE2\x86\x91"}, {1, "\x19", 3, "\xE2\x86\x93"}, {1, "\x1A", 3, "\xE2\x86\x92"},
	    {1, "\x1B", 3, "\xE2\x86\x90"}, {1, "\x1C", 3, "\xE2\x88\x9F"}, {1, "\x1D", 3, "\xE2\x86\x94"},
	    {1, "\x1E", 3, "\xE2\x96\xB2"}, {1, "\x1F", 3, "\xE2\x96\xBC"}, {1, "\x20", 3, "\xE3\x80\x80"},
	    {1, "\x21", 3, "\xEF\xBC\x81"}, {1, "\x22", 3, "\xEF\xBC\x82"}, {1, "\x23", 3, "\xEF\xBC\x83"},
	    {1, "\x24", 3, "\xEF\xBC\x84"}, {1, "\x25", 3, "\xEF\xBC\x85"}, {1, "\x26", 3, "\xEF\xBC\x86"},
	    {1, "\x27", 3, "\xEF\xBC\x87"}, {1, "\x28", 3, "\xEF\xBC\x88"}, {1, "\x29", 3, "\xEF\xBC\x89"},
	    {1, "\x2A", 3, "\xEF\xBC\x8A"}, {1, "\x2B", 3, "\xEF\xBC\x8B"}, {1, "\x2C", 3, "\xEF\xBC\x8C"},
	    {1, "\x2D", 3, "\xEF\xBC\x8D"}, {1, "\x2E", 3, "\xEF\xBC\x8E"}, {1, "\x2F", 3, "\xEF\xBC\x8F"},
	    {1, "\x30", 3, "\xEF\xBC\x90"}, {1, "\x31", 3, "\xEF\xBC\x91"}, {1, "\x32", 3, "\xEF\xBC\x92"},
	    {1, "\x33", 3, "\xEF\xBC\x93"}, {1, "\x34", 3, "\xEF\xBC\x94"}, {1, "\x35", 3, "\xEF\xBC\x95"},
	    {1, "\x36", 3, "\xEF\xBC\x96"}, {1, "\x37", 3, "\xEF\xBC\x97"}, {1, "\x38", 3, "\xEF\xBC\x98"},
	    {1, "\x39", 3, "\xEF\xBC\x99"}, {1, "\x3A", 3, "\xEF\xBC\x9A"}, {1, "\x3B", 3, "\xEF\xBC\x9B"},
	    {1, "\x3C", 3, "\xEF\xBC\x9C"}, {1, "\x3D", 3, "\xEF\xBC\x9D"}, {1, "\x3E", 3, "\xEF\xBC\x9E"},
	    {1, "\x3F", 1, "\x3F"},         {1, "\x40", 3, "\xEF\xBC\xA0"}, {1, "\x41", 3, "\xEF\xBC\xA1"},
	    {1, "\x42", 3, "\xEF\xBC\xA2"}, {1, "\x43", 3, "\xEF\xBC\xA3"}, {1, "\x44", 3, "\xEF\xBC\xA4"},
	    {1, "\x45", 3, "\xEF\xBC\xA5"}, {1, "\x46", 3, "\xEF\xBC\xA6"}, {1, "\x47", 3, "\xEF\xBC\xA7"},
	    {1, "\x48", 3, "\xEF\xBC\xA8"}, {1, "\x49", 3, "\xEF\xBC\xA9"}, {1, "\x4A", 3, "\xEF\xBC\xAA"},
	    {1, "\x4B", 3, "\xEF\xBC\xAB"}, {1, "\x4C", 3, "\xEF\xBC\xAC"}, {1, "\x4D", 3, "\xEF\xBC\xAD"},
	    {1, "\x4E", 3, "\xEF\xBC\xAE"}, {1, "\x4F", 3, "\xEF\xBC\xAF"}, {1, "\x50", 3, "\xEF\xBC\xB0"},
	    {1, "\x51", 3, "\xEF\xBC\xB1"}, {1, "\x52", 3, "\xEF\xBC\xB2"}, {1, "\x53", 3, "\xEF\xBC\xB3"},
	    {1, "\x54", 3, "\xEF\xBC\xB4"}, {1, "\x55", 3, "\xEF\xBC\xB5"}, {1, "\x56", 3, "\xEF\xBC\xB6"},
	    {1, "\x57", 3, "\xEF\xBC\xB7"}, {1, "\x58", 3, "\xEF\xBC\xB8"}, {1, "\x59", 3, "\xEF\xBC\xB9"},
	    {1, "\x5A", 3, "\xEF\xBC\xBA"}, {1, "\x5B", 3, "\xEF\xBC\xBB"}, {1, "\x5C", 3, "\xEF\xBC\xBC"},
	    {1, "\x5D", 3, "\xEF\xBC\xBD"}, {1, "\x5E", 3, "\xEF\xBC\xBE"}, {1, "\x5F", 3, "\xEF\xBC\xBF"},
	    {1, "\x60", 3, "\xEF\xBD\x80"}, {1, "\x61", 3, "\xEF\xBD\x81"}, {1, "\x62", 3, "\xEF\xBD\x82"},
	    {1, "\x63", 3, "\xEF\xBD\x83"}, {1, "\x64", 3, "\xEF\xBD\x84"}, {1, "\x65", 3, "\xEF\xBD\x85"},
	    {1, "\x66", 3, "\xEF\xBD\x86"}, {1, "\x67", 3, "\xEF\xBD\x87"}, {1, "\x68", 3, "\xEF\xBD\x88"},
	    {1, "\x69", 3, "\xEF\xBD\x89"}, {1, "\x6A", 3, "\xEF\xBD\x8A"}, {1, "\x6B", 3, "\xEF\xBD\x8B"},
	    {1, "\x6C", 3, "\xEF\xBD\x8C"}, {1, "\x6D", 3, "\xEF\xBD\x8D"}, {1, "\x6E", 3, "\xEF\xBD\x8E"},
	    {1, "\x6F", 3, "\xEF\xBD\x8F"}, {1, "\x70", 3, "\xEF\xBD\x90"}, {1, "\x71", 3, "\xEF\xBD\x91"},
	    {1, "\x72", 3, "\xEF\xBD\x92"}, {1, "\x73", 3, "\xEF\xBD\x93"}, {1, "\x74", 3, "\xEF\xBD\x94"},
	    {1, "\x75", 3, "\xEF\xBD\x95"}, {1, "\x76", 3, "\xEF\xBD\x96"}, {1, "\x77", 3, "\xEF\xBD\x97"},
	    {1, "\x78", 3, "\xEF\xBD\x98"}, {1, "\x79", 3, "\xEF\xBD\x99"}, {1, "\x7A", 3, "\xEF\xBD\x9A"},
	    {1, "\x7B", 3, "\xEF\xBD\x9B"}, {1, "\x7C", 3, "\xEF\xBD\x9C"}, {1, "\x7D", 3, "\xEF\xBD\x9D"},
	    {1, "\x7E", 3, "\xEF\xBD\x9E"}, {1, "\x7F", 3, "\xE2\x8C\x82"}, {1, "\x80", 2, "\xC4\x86"},
	    {1, "\x81", 2, "\xC3\xBC"},     {1, "\x82", 2, "\xC3\xA9"},     {1, "\x83", 2, "\xC4\x81"},
	    {1, "\x84", 2, "\xC3\xA4"},     {1, "\x85", 2, "\xC4\xA3"},     {1, "\x86", 2, "\xC3\xA5"},
	    {1, "\x87", 2, "\xC4\x87"},     {1, "\x88", 2, "\xC5\x82"},     {1, "\x89", 2, "\xC4\x93"},
	    {1, "\x8A", 2, "\xC5\x96"},     {1, "\x8B", 2, "\xC5\x97"},     {1, "\x8C", 2, "\xC4\xAB"},
	    {1, "\x8D", 2, "\xC5\xB9"},     {1, "\x8E", 2, "\xC3\x84"},     {1, "\x8F", 2, "\xC3\x85"},
	    {1, "\x90", 2, "\xC3\x89"},     {1, "\x91", 2, "\xC3\xA6"},     {1, "\x92", 2, "\xC3\x86"},
	    {1, "\x93", 2, "\xC5\x8D"},     {1, "\x94", 2, "\xC3\xB6"},     {1, "\x95", 2, "\xC4\xA2"},
	    {1, "\x96", 2, "\xC2\xA2"},     {1, "\x97", 2, "\xC5\x9A"},     {1, "\x98", 2, "\xC5\x9B"},
	    {1, "\x99", 2, "\xC3\x96"},     {1, "\x9A", 2, "\xC3\x9C"},     {1, "\x9B", 2, "\xC3\xB8"},
	    {1, "\x9C", 2, "\xC2\xA3"},     {1, "\x9D", 2, "\xC3\x98"},     {1, "\x9E", 2, "\xC3\x97"},
	    {1, "\x9F", 2, "\xC2\xA4"},     {1, "\xA0", 2, "\xC4\x80"},     {1, "\xA1", 2, "\xC4\xAA"},
	    {1, "\xA2", 2, "\xC3\xB3"},     {1, "\xA3", 2, "\xC5\xBB"},     {1, "\xA4", 2, "\xC5\xBC"},
	    {1, "\xA5", 2, "\xC5\xBA"},     {1, "\xA6", 3, "\xE2\x80\x9D"}, {1, "\xA7", 2, "\xC2\xA6"},
	    {1, "\xA8", 2, "\xC2\xA9"},     {1, "\xA9", 2, "\xC2\xAE"},     {1, "\xAA", 2, "\xC2\xAC"},
	    {1, "\xAB", 2, "\xC2\xBD"},     {1, "\xAC", 2, "\xC2\xBC"},     {1, "\xAD", 2, "\xC5\x81"},
	    {1, "\xAE", 3, "\xE3\x80\x8A"}, {1, "\xAF", 3, "\xE3\x80\x8B"}, {1, "\xB0", 3, "\xE2\x96\x91"},
	    {1, "\xB1", 3, "\xE2\x96\x92"}, {1, "\xB2", 3, "\xE2\x96\x93"}, {1, "\xB3", 3, "\xE2\x94\x82"},
	    {1, "\xB4", 3, "\xE2\x94\xA4"}, {1, "\xB5", 2, "\xC4\x84"},     {1, "\xB6", 2, "\xC4\x8C"},
	    {1, "\xB7", 2, "\xC4\x98"},     {1, "\xB8", 2, "\xC4\x96"},     {1, "\xB9", 3, "\xE2\x95\xA3"},
	    {1, "\xBA", 3, "\xE2\x95\x91"}, {1, "\xBB", 3, "\xE2\x95\x97"}, {1, "\xBC", 3, "\xE2\x95\x9D"},
	    {1, "\xBD", 2, "\xC4\xAE"},     {1, "\xBE", 2, "\xC5\xA0"},     {1, "\xBF", 3, "\xE2\x94\x90"},
	    {1, "\xC0", 3, "\xE2\x94\x94"}, {1, "\xC1", 3, "\xE2\x94\xB4"}, {1, "\xC2", 3, "\xE2\x94\xAC"},
	    {1, "\xC3", 3, "\xE2\x94\x9C"}, {1, "\xC4", 3, "\xE2\x94\x80"}, {1, "\xC5", 3, "\xE2\x94\xBC"},
	    {1, "\xC6", 2, "\xC5\xB2"},     {1, "\xC7", 2, "\xC5\xAA"},     {1, "\xC8", 3, "\xE2\x95\x9A"},
	    {1, "\xC9", 3, "\xE2\x95\x94"}, {1, "\xCA", 3, "\xE2\x95\xA9"}, {1, "\xCB", 3, "\xE2\x95\xA6"},
	    {1, "\xCC", 3, "\xE2\x95\xA0"}, {1, "\xCD", 3, "\xE2\x95\x90"}, {1, "\xCE", 3, "\xE2\x95\xAC"},
	    {1, "\xCF", 2, "\xC5\xBD"},     {1, "\xD0", 2, "\xC4\x85"},     {1, "\xD1", 2, "\xC4\x8D"},
	    {1, "\xD2", 2, "\xC4\x99"},     {1, "\xD3", 2, "\xC4\x97"},     {1, "\xD4", 2, "\xC4\xAF"},
	    {1, "\xD5", 2, "\xC5\xA1"},     {1, "\xD6", 2, "\xC5\xB3"},     {1, "\xD7", 2, "\xC5\xAB"},
	    {1, "\xD8", 2, "\xC5\xBE"},     {1, "\xD9", 3, "\xE2\x94\x98"}, {1, "\xDA", 3, "\xE2\x94\x8C"},
	    {1, "\xDB", 3, "\xE2\x96\x88"}, {1, "\xDC", 3, "\xE2\x96\x84"}, {1, "\xDD", 3, "\xE2\x96\x8C"},
	    {1, "\xDE", 3, "\xE2\x96\x90"}, {1, "\xDF", 3, "\xE2\x96\x80"}, {1, "\xE0", 2, "\xC3\x93"},
	    {1, "\xE1", 2, "\xCE\xB2"},     {1, "\xE2", 2, "\xC5\x8C"},     {1, "\xE3", 2, "\xC5\x83"},
	    {1, "\xE4", 2, "\xC3\xB5"},     {1, "\xE5", 2, "\xC3\x95"},     {1, "\xE6", 2, "\xC2\xB5"},
	    {1, "\xE7", 2, "\xC5\x84"},     {1, "\xE8", 2, "\xC4\xB6"},     {1, "\xE9", 2, "\xC4\xB7"},
	    {1, "\xEA", 2, "\xC4\xBB"},     {1, "\xEB", 2, "\xC4\xBC"},     {1, "\xEC", 2, "\xC5\x86"},
	    {1, "\xED", 2, "\xC4\x92"},     {1, "\xEE", 2, "\xC5\x85"},     {1, "\xEF", 3, "\xE2\x80\x99"},
	    {1, "\xF0", 2, "\xC2\xAD"},     {1, "\xF1", 2, "\xC2\xB1"},     {1, "\xF2", 3, "\xE2\x80\x9C"},
	    {1, "\xF3", 2, "\xC2\xBE"},     {1, "\xF4", 2, "\xC2\xB6"},     {1, "\xF5", 2, "\xC2\xA7"},
	    {1, "\xF6", 2, "\xC3\xB7"},     {1, "\xF7", 3, "\xE2\x80\x9E"}, {1, "\xF8", 3, "\xE2\x88\x98"},
	    {1, "\xF9", 3, "\xE2\x88\x99"}, {1, "\xFA", 2, "\xC2\xB7"},     {1, "\xFB", 2, "\xC2\xB9"},
	    {1, "\xFC", 2, "\xC2\xB3"},     {1, "\xFD", 2, "\xC2\xB2"},     {1, "\xFE", 3, "\xE2\x96\xA0"},
	    {1, "\xFF", 2, "\xC2\xA0"},
	};
	static void Register(const DBConfig &config) {
		const Windows_775_2000ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&windows_775_2000_to_utf8),
		                                std::size(windows_775_2000_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
