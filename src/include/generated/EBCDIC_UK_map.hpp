//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/EBCDIC_UK_map.hpp
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

class Ebcdic_ukToUtf {
public:
	Ebcdic_ukToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "EBCDIC_UK";
	// Generated from: glibc-EBCDIC_UK-2.1.2.ucm
	static constexpr map_entry EBCDIC_UK_to_utf8[] = {
	    {1, "\x00", 1, "\x00"},         {1, "\x01", 1, "\x01"},     {1, "\x02", 1, "\x02"},
	    {1, "\x03", 1, "\x03"},         {1, "\x04", 2, "\xC2\x9C"}, {1, "\x05", 1, "\x09"},
	    {1, "\x06", 2, "\xC2\x86"},     {1, "\x07", 1, "\x7F"},     {1, "\x08", 2, "\xC2\x97"},
	    {1, "\x09", 2, "\xC2\x8D"},     {1, "\x0A", 2, "\xC2\x8E"}, {1, "\x0B", 1, "\x0B"},
	    {1, "\x0C", 1, "\x0C"},         {1, "\x0D", 1, "\x0D"},     {1, "\x0E", 1, "\x0E"},
	    {1, "\x0F", 1, "\x0F"},         {1, "\x10", 1, "\x10"},     {1, "\x11", 1, "\x11"},
	    {1, "\x12", 1, "\x12"},         {1, "\x13", 1, "\x13"},     {1, "\x14", 2, "\xC2\x9D"},
	    {1, "\x15", 2, "\xC2\x85"},     {1, "\x16", 1, "\x08"},     {1, "\x17", 2, "\xC2\x87"},
	    {1, "\x18", 1, "\x18"},         {1, "\x19", 1, "\x19"},     {1, "\x1A", 2, "\xC2\x92"},
	    {1, "\x1B", 2, "\xC2\x8F"},     {1, "\x1C", 1, "\x1C"},     {1, "\x1D", 1, "\x1D"},
	    {1, "\x1E", 1, "\x1E"},         {1, "\x1F", 1, "\x1F"},     {1, "\x20", 2, "\xC2\x80"},
	    {1, "\x21", 2, "\xC2\x81"},     {1, "\x22", 2, "\xC2\x82"}, {1, "\x23", 2, "\xC2\x83"},
	    {1, "\x24", 2, "\xC2\x84"},     {1, "\x25", 1, "\x0A"},     {1, "\x26", 1, "\x17"},
	    {1, "\x27", 1, "\x1B"},         {1, "\x28", 2, "\xC2\x88"}, {1, "\x29", 2, "\xC2\x89"},
	    {1, "\x2A", 2, "\xC2\x8A"},     {1, "\x2B", 2, "\xC2\x8B"}, {1, "\x2C", 2, "\xC2\x8C"},
	    {1, "\x2D", 1, "\x05"},         {1, "\x2E", 1, "\x06"},     {1, "\x2F", 1, "\x07"},
	    {1, "\x30", 2, "\xC2\x90"},     {1, "\x31", 2, "\xC2\x91"}, {1, "\x32", 1, "\x16"},
	    {1, "\x33", 2, "\xC2\x93"},     {1, "\x34", 2, "\xC2\x94"}, {1, "\x35", 2, "\xC2\x95"},
	    {1, "\x36", 2, "\xC2\x96"},     {1, "\x37", 1, "\x04"},     {1, "\x38", 2, "\xC2\x98"},
	    {1, "\x39", 2, "\xC2\x99"},     {1, "\x3A", 2, "\xC2\x9A"}, {1, "\x3B", 2, "\xC2\x9B"},
	    {1, "\x3C", 1, "\x14"},         {1, "\x3D", 1, "\x15"},     {1, "\x3E", 2, "\xC2\x9E"},
	    {1, "\x3F", 1, "\x1A"},         {1, "\x40", 1, "\x20"},     {1, "\x4A", 1, "\x24"},
	    {1, "\x4B", 1, "\x2E"},         {1, "\x4C", 1, "\x3C"},     {1, "\x4D", 1, "\x28"},
	    {1, "\x4E", 1, "\x2B"},         {1, "\x4F", 1, "\x7C"},     {1, "\x50", 1, "\x26"},
	    {1, "\x5A", 1, "\x21"},         {1, "\x5B", 2, "\xC2\xA3"}, {1, "\x5C", 1, "\x2A"},
	    {1, "\x5D", 1, "\x29"},         {1, "\x5E", 1, "\x3B"},     {1, "\x5F", 2, "\xC2\xAC"},
	    {1, "\x60", 1, "\x2D"},         {1, "\x61", 1, "\x2F"},     {1, "\x6A", 2, "\xC2\xA6"},
	    {1, "\x6B", 1, "\x2C"},         {1, "\x6C", 1, "\x25"},     {1, "\x6D", 1, "\x5F"},
	    {1, "\x6E", 1, "\x3E"},         {1, "\x6F", 1, "\x3F"},     {1, "\x79", 1, "\x60"},
	    {1, "\x7A", 1, "\x3A"},         {1, "\x7B", 1, "\x23"},     {1, "\x7C", 1, "\x40"},
	    {1, "\x7D", 1, "\x27"},         {1, "\x7E", 1, "\x3D"},     {1, "\x7F", 1, "\x22"},
	    {1, "\x81", 1, "\x61"},         {1, "\x82", 1, "\x62"},     {1, "\x83", 1, "\x63"},
	    {1, "\x84", 1, "\x64"},         {1, "\x85", 1, "\x65"},     {1, "\x86", 1, "\x66"},
	    {1, "\x87", 1, "\x67"},         {1, "\x88", 1, "\x68"},     {1, "\x89", 1, "\x69"},
	    {1, "\x91", 1, "\x6A"},         {1, "\x92", 1, "\x6B"},     {1, "\x93", 1, "\x6C"},
	    {1, "\x94", 1, "\x6D"},         {1, "\x95", 1, "\x6E"},     {1, "\x96", 1, "\x6F"},
	    {1, "\x97", 1, "\x70"},         {1, "\x98", 1, "\x71"},     {1, "\x99", 1, "\x72"},
	    {1, "\xA1", 3, "\xE2\x80\xBE"}, {1, "\xA2", 1, "\x73"},     {1, "\xA3", 1, "\x74"},
	    {1, "\xA4", 1, "\x75"},         {1, "\xA5", 1, "\x76"},     {1, "\xA6", 1, "\x77"},
	    {1, "\xA7", 1, "\x78"},         {1, "\xA8", 1, "\x79"},     {1, "\xA9", 1, "\x7A"},
	    {1, "\xC0", 1, "\x7B"},         {1, "\xC1", 1, "\x41"},     {1, "\xC2", 1, "\x42"},
	    {1, "\xC3", 1, "\x43"},         {1, "\xC4", 1, "\x44"},     {1, "\xC5", 1, "\x45"},
	    {1, "\xC6", 1, "\x46"},         {1, "\xC7", 1, "\x47"},     {1, "\xC8", 1, "\x48"},
	    {1, "\xC9", 1, "\x49"},         {1, "\xD0", 1, "\x7D"},     {1, "\xD1", 1, "\x4A"},
	    {1, "\xD2", 1, "\x4B"},         {1, "\xD3", 1, "\x4C"},     {1, "\xD4", 1, "\x4D"},
	    {1, "\xD5", 1, "\x4E"},         {1, "\xD6", 1, "\x4F"},     {1, "\xD7", 1, "\x50"},
	    {1, "\xD8", 1, "\x51"},         {1, "\xD9", 1, "\x52"},     {1, "\xE0", 1, "\x5C"},
	    {1, "\xE2", 1, "\x53"},         {1, "\xE3", 1, "\x54"},     {1, "\xE4", 1, "\x55"},
	    {1, "\xE5", 1, "\x56"},         {1, "\xE6", 1, "\x57"},     {1, "\xE7", 1, "\x58"},
	    {1, "\xE8", 1, "\x59"},         {1, "\xE9", 1, "\x5A"},     {1, "\xF0", 1, "\x30"},
	    {1, "\xF1", 1, "\x31"},         {1, "\xF2", 1, "\x32"},     {1, "\xF3", 1, "\x33"},
	    {1, "\xF4", 1, "\x34"},         {1, "\xF5", 1, "\x35"},     {1, "\xF6", 1, "\x36"},
	    {1, "\xF7", 1, "\x37"},         {1, "\xF8", 1, "\x38"},     {1, "\xF9", 1, "\x39"},
	    {1, "\xFF", 2, "\xC2\x9F"},
	};
	static void Register(const DBConfig &config) {
		const Ebcdic_ukToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                reinterpret_cast<uintptr_t>(&EBCDIC_UK_to_utf8), std::size(EBCDIC_UK_to_utf8));
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
