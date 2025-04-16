//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/ibm-1040_P100-1995_map.hpp
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

class Ibm_1040_p100_1995ToUtf {
public:
	Ibm_1040_p100_1995ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "ibm-1040_P100-1995";
	// Generated from: ibm-1040_P100-1995.ucm
	static constexpr map_entry ibm_1040_P100_1995_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},         {1, "\x01", 3, "\xE2\x95\x94"}, {1, "\x02", 3, "\xE2\x95\x97"},
	    {1, "\x03", 3, "\xE2\x95\x9A"}, {1, "\x04", 3, "\xE2\x95\x9D"}, {1, "\x05", 3, "\xE2\x95\x91"},
	    {1, "\x06", 3, "\xE2\x95\x90"}, {1, "\x07", 3, "\xEF\xBF\xAC"}, {1, "\x08", 1, "\x08"},
	    {1, "\x09", 3, "\xEF\xBF\xAE"}, {1, "\x0A", 1, "\x0A"},         {1, "\x0B", 3, "\xE3\x80\xBF"},
	    {1, "\x0C", 1, "\x0C"},         {1, "\x0D", 1, "\x0D"},         {1, "\x0E", 3, "\xEF\xBF\xAD"},
	    {1, "\x0F", 3, "\xE2\x98\xBC"}, {1, "\x10", 3, "\xE2\x95\xAC"}, {1, "\x11", 1, "\x11"},
	    {1, "\x12", 3, "\xE2\x86\x95"}, {1, "\x13", 1, "\x13"},         {1, "\x14", 3, "\xE2\x96\x93"},
	    {1, "\x15", 3, "\xE2\x95\xA9"}, {1, "\x16", 3, "\xE2\x95\xA6"}, {1, "\x17", 3, "\xE2\x95\xA3"},
	    {1, "\x18", 1, "\x18"},         {1, "\x19", 3, "\xE2\x95\xA0"}, {1, "\x1A", 3, "\xE2\x96\x91"},
	    {1, "\x1B", 3, "\xE2\x86\xB5"}, {1, "\x1C", 3, "\xEF\xBF\xAA"}, {1, "\x1D", 3, "\xEF\xBF\xA8"},
	    {1, "\x1E", 3, "\xEF\xBF\xAB"}, {1, "\x1F", 3, "\xEF\xBF\xA9"}, {1, "\x20", 1, "\x20"},
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
	    {1, "\x3F", 3, "\xEF\xBC\x9F"}, {1, "\x40", 3, "\xEF\xBC\xA0"}, {1, "\x41", 3, "\xEF\xBC\xA1"},
	    {1, "\x42", 3, "\xEF\xBC\xA2"}, {1, "\x43", 3, "\xEF\xBC\xA3"}, {1, "\x44", 3, "\xEF\xBC\xA4"},
	    {1, "\x45", 3, "\xEF\xBC\xA5"}, {1, "\x46", 3, "\xEF\xBC\xA6"}, {1, "\x47", 3, "\xEF\xBC\xA7"},
	    {1, "\x48", 3, "\xEF\xBC\xA8"}, {1, "\x49", 3, "\xEF\xBC\xA9"}, {1, "\x4A", 3, "\xEF\xBC\xAA"},
	    {1, "\x4B", 3, "\xEF\xBC\xAB"}, {1, "\x4C", 3, "\xEF\xBC\xAC"}, {1, "\x4D", 3, "\xEF\xBC\xAD"},
	    {1, "\x4E", 3, "\xEF\xBC\xAE"}, {1, "\x4F", 3, "\xEF\xBC\xAF"}, {1, "\x50", 3, "\xEF\xBC\xB0"},
	    {1, "\x51", 3, "\xEF\xBC\xB1"}, {1, "\x52", 3, "\xEF\xBC\xB2"}, {1, "\x53", 3, "\xEF\xBC\xB3"},
	    {1, "\x54", 3, "\xEF\xBC\xB4"}, {1, "\x55", 3, "\xEF\xBC\xB5"}, {1, "\x56", 3, "\xEF\xBC\xB6"},
	    {1, "\x57", 3, "\xEF\xBC\xB7"}, {1, "\x58", 3, "\xEF\xBC\xB8"}, {1, "\x59", 3, "\xEF\xBC\xB9"},
	    {1, "\x5A", 3, "\xEF\xBC\xBA"}, {1, "\x5B", 3, "\xEF\xBC\xBB"}, {1, "\x5C", 3, "\xE2\x82\xA9"},
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
	    {1, "\x7E", 3, "\xE2\x80\xBE"}, {1, "\x7F", 1, "\x1A"},         {1, "\x80", 2, "\xC2\xA2"},
	    {1, "\xC0", 3, "\xEF\xBE\xA0"}, {1, "\xC1", 3, "\xEF\xBE\xA1"}, {1, "\xC2", 3, "\xEF\xBE\xA2"},
	    {1, "\xC3", 3, "\xEF\xBE\xA3"}, {1, "\xC4", 3, "\xEF\xBE\xA4"}, {1, "\xC5", 3, "\xEF\xBE\xA5"},
	    {1, "\xC6", 3, "\xEF\xBE\xA6"}, {1, "\xC7", 3, "\xEF\xBE\xA7"}, {1, "\xC8", 3, "\xEF\xBE\xA8"},
	    {1, "\xC9", 3, "\xEF\xBE\xA9"}, {1, "\xCA", 3, "\xEF\xBE\xAA"}, {1, "\xCB", 3, "\xEF\xBE\xAB"},
	    {1, "\xCC", 3, "\xEF\xBE\xAC"}, {1, "\xCD", 3, "\xEF\xBE\xAD"}, {1, "\xCE", 3, "\xEF\xBE\xAE"},
	    {1, "\xCF", 3, "\xEF\xBE\xAF"}, {1, "\xD0", 3, "\xEF\xBE\xB0"}, {1, "\xD1", 3, "\xEF\xBE\xB1"},
	    {1, "\xD2", 3, "\xEF\xBE\xB2"}, {1, "\xD3", 3, "\xEF\xBE\xB3"}, {1, "\xD4", 3, "\xEF\xBE\xB4"},
	    {1, "\xD5", 3, "\xEF\xBE\xB5"}, {1, "\xD6", 3, "\xEF\xBE\xB6"}, {1, "\xD7", 3, "\xEF\xBE\xB7"},
	    {1, "\xD8", 3, "\xEF\xBE\xB8"}, {1, "\xD9", 3, "\xEF\xBE\xB9"}, {1, "\xDA", 3, "\xEF\xBE\xBA"},
	    {1, "\xDB", 3, "\xEF\xBE\xBB"}, {1, "\xDC", 3, "\xEF\xBE\xBC"}, {1, "\xDD", 3, "\xEF\xBE\xBD"},
	    {1, "\xDE", 3, "\xEF\xBE\xBE"}, {1, "\xDF", 2, "\xC2\xA6"},     {1, "\xE2", 3, "\xEF\xBF\x82"},
	    {1, "\xE3", 3, "\xEF\xBF\x83"}, {1, "\xE4", 3, "\xEF\xBF\x84"}, {1, "\xE5", 3, "\xEF\xBF\x85"},
	    {1, "\xE6", 3, "\xEF\xBF\x86"}, {1, "\xE7", 3, "\xEF\xBF\x87"}, {1, "\xEA", 3, "\xEF\xBF\x8A"},
	    {1, "\xEB", 3, "\xEF\xBF\x8B"}, {1, "\xEC", 3, "\xEF\xBF\x8C"}, {1, "\xED", 3, "\xEF\xBF\x8D"},
	    {1, "\xEE", 3, "\xEF\xBF\x8E"}, {1, "\xEF", 3, "\xEF\xBF\x8F"}, {1, "\xF2", 3, "\xEF\xBF\x92"},
	    {1, "\xF3", 3, "\xEF\xBF\x93"}, {1, "\xF4", 3, "\xEF\xBF\x94"}, {1, "\xF5", 3, "\xEF\xBF\x95"},
	    {1, "\xF6", 3, "\xEF\xBF\x96"}, {1, "\xF7", 3, "\xEF\xBF\x97"}, {1, "\xFA", 3, "\xEF\xBF\x9A"},
	    {1, "\xFB", 3, "\xEF\xBF\x9B"}, {1, "\xFC", 3, "\xEF\xBF\x9C"}, {1, "\xFD", 2, "\xC2\xAC"},
	    {1, "\xFE", 3, "\xEF\xBC\xBC"}, {1, "\xFF", 3, "\xEF\xBD\x9E"},
	};
	static void Register(const DBConfig &config) {
		const Ibm_1040_p100_1995ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&ibm_1040_P100_1995_to_utf8),
		                                std::size(ibm_1040_P100_1995_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
