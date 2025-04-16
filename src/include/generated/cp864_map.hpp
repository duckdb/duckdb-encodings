//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/cp864_map.hpp
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

class Cp864ToUtf {
public:
	Cp864ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "cp864";
	// Generated from: glibc-IBM864-2.1.2.ucm
	const map<vector<uint8_t>, vector<uint8_t>> cp864_to_utf8 = {
	    {{0x00}, {0x00}},
	    {{0x01}, {0x01}},
	    {{0x02}, {0x02}},
	    {{0x03}, {0x03}},
	    {{0x04}, {0x04}},
	    {{0x05}, {0x05}},
	    {{0x06}, {0x06}},
	    {{0x07}, {0x07}},
	    {{0x08}, {0x08}},
	    {{0x09}, {0x09}},
	    {{0x0A}, {0x0A}},
	    {{0x0B}, {0x0B}},
	    {{0x0C}, {0x0C}},
	    {{0x0D}, {0x0D}},
	    {{0x0E}, {0x0E}},
	    {{0x0F}, {0x0F}},
	    {{0x10}, {0x10}},
	    {{0x11}, {0x11}},
	    {{0x12}, {0x12}},
	    {{0x13}, {0x13}},
	    {{0x14}, {0x14}},
	    {{0x15}, {0x15}},
	    {{0x16}, {0x16}},
	    {{0x17}, {0x17}},
	    {{0x18}, {0x18}},
	    {{0x19}, {0x19}},
	    {{0x1A}, {0x1A}},
	    {{0x1B}, {0x1B}},
	    {{0x1C}, {0x1C}},
	    {{0x1D}, {0x1D}},
	    {{0x1E}, {0x1E}},
	    {{0x1F}, {0x1F}},
	    {{0x20}, {0x20}},
	    {{0x21}, {0x21}},
	    {{0x22}, {0x22}},
	    {{0x23}, {0x23}},
	    {{0x24}, {0x24}},
	    {{0x26}, {0x26}},
	    {{0x27}, {0x27}},
	    {{0x28}, {0x28}},
	    {{0x29}, {0x29}},
	    {{0x2A}, {0x2A}},
	    {{0x2B}, {0x2B}},
	    {{0x2C}, {0x2C}},
	    {{0x2D}, {0x2D}},
	    {{0x2E}, {0x2E}},
	    {{0x2F}, {0x2F}},
	    {{0x30}, {0x30}},
	    {{0x31}, {0x31}},
	    {{0x32}, {0x32}},
	    {{0x33}, {0x33}},
	    {{0x34}, {0x34}},
	    {{0x35}, {0x35}},
	    {{0x36}, {0x36}},
	    {{0x37}, {0x37}},
	    {{0x38}, {0x38}},
	    {{0x39}, {0x39}},
	    {{0x3A}, {0x3A}},
	    {{0x3B}, {0x3B}},
	    {{0x3C}, {0x3C}},
	    {{0x3D}, {0x3D}},
	    {{0x3E}, {0x3E}},
	    {{0x3F}, {0x3F}},
	    {{0x40}, {0x40}},
	    {{0x41}, {0x41}},
	    {{0x42}, {0x42}},
	    {{0x43}, {0x43}},
	    {{0x44}, {0x44}},
	    {{0x45}, {0x45}},
	    {{0x46}, {0x46}},
	    {{0x47}, {0x47}},
	    {{0x48}, {0x48}},
	    {{0x49}, {0x49}},
	    {{0x4A}, {0x4A}},
	    {{0x4B}, {0x4B}},
	    {{0x4C}, {0x4C}},
	    {{0x4D}, {0x4D}},
	    {{0x4E}, {0x4E}},
	    {{0x4F}, {0x4F}},
	    {{0x50}, {0x50}},
	    {{0x51}, {0x51}},
	    {{0x52}, {0x52}},
	    {{0x53}, {0x53}},
	    {{0x54}, {0x54}},
	    {{0x55}, {0x55}},
	    {{0x56}, {0x56}},
	    {{0x57}, {0x57}},
	    {{0x58}, {0x58}},
	    {{0x59}, {0x59}},
	    {{0x5A}, {0x5A}},
	    {{0x5B}, {0x5B}},
	    {{0x5C}, {0x5C}},
	    {{0x5D}, {0x5D}},
	    {{0x5E}, {0x5E}},
	    {{0x5F}, {0x5F}},
	    {{0x60}, {0x60}},
	    {{0x61}, {0x61}},
	    {{0x62}, {0x62}},
	    {{0x63}, {0x63}},
	    {{0x64}, {0x64}},
	    {{0x65}, {0x65}},
	    {{0x66}, {0x66}},
	    {{0x67}, {0x67}},
	    {{0x68}, {0x68}},
	    {{0x69}, {0x69}},
	    {{0x6A}, {0x6A}},
	    {{0x6B}, {0x6B}},
	    {{0x6C}, {0x6C}},
	    {{0x6D}, {0x6D}},
	    {{0x6E}, {0x6E}},
	    {{0x6F}, {0x6F}},
	    {{0x70}, {0x70}},
	    {{0x71}, {0x71}},
	    {{0x72}, {0x72}},
	    {{0x73}, {0x73}},
	    {{0x74}, {0x74}},
	    {{0x75}, {0x75}},
	    {{0x76}, {0x76}},
	    {{0x77}, {0x77}},
	    {{0x78}, {0x78}},
	    {{0x79}, {0x79}},
	    {{0x7A}, {0x7A}},
	    {{0x7B}, {0x7B}},
	    {{0x7C}, {0x7C}},
	    {{0x7D}, {0x7D}},
	    {{0x7E}, {0x7E}},
	    {{0x7F}, {0x7F}},
	    {{0x80}, {0xC2, 0xB0}},
	    {{0x81}, {0xC2, 0xB7}},
	    {{0x82}, {0xE2, 0x88, 0x99}},
	    {{0x83}, {0xE2, 0x88, 0x9A}},
	    {{0x84}, {0xE2, 0x96, 0x92}},
	    {{0x85}, {0xE2, 0x94, 0x80}},
	    {{0x86}, {0xE2, 0x94, 0x82}},
	    {{0x87}, {0xE2, 0x94, 0xBC}},
	    {{0x88}, {0xE2, 0x94, 0xA4}},
	    {{0x89}, {0xE2, 0x94, 0xAC}},
	    {{0x8A}, {0xE2, 0x94, 0x9C}},
	    {{0x8B}, {0xE2, 0x94, 0xB4}},
	    {{0x8C}, {0xE2, 0x94, 0x90}},
	    {{0x8D}, {0xE2, 0x94, 0x8C}},
	    {{0x8E}, {0xE2, 0x94, 0x94}},
	    {{0x8F}, {0xE2, 0x94, 0x98}},
	    {{0x90}, {0xCE, 0xB2}},
	    {{0x91}, {0xE2, 0x88, 0x9E}},
	    {{0x92}, {0xCF, 0x86}},
	    {{0x93}, {0xC2, 0xB1}},
	    {{0x94}, {0xC2, 0xBD}},
	    {{0x95}, {0xC2, 0xBC}},
	    {{0x96}, {0xE2, 0x89, 0x88}},
	    {{0x97}, {0xC2, 0xAB}},
	    {{0x98}, {0xC2, 0xBB}},
	    {{0x99}, {0xEF, 0xBB, 0xB7}},
	    {{0x9A}, {0xEF, 0xBB, 0xB8}},
	    {{0x9D}, {0xEF, 0xBB, 0xBB}},
	    {{0x9E}, {0xEF, 0xBB, 0xBC}},
	    {{0xA0}, {0xC2, 0xA0}},
	    {{0xA1}, {0xC2, 0xAD}},
	    {{0xA2}, {0xEF, 0xBA, 0x82}},
	    {{0xA3}, {0xC2, 0xA3}},
	    {{0xA4}, {0xC2, 0xA4}},
	    {{0xA5}, {0xEF, 0xBA, 0x84}},
	    {{0xA8}, {0xEF, 0xBA, 0x8E}},
	    {{0xA9}, {0xEF, 0xBA, 0x8F}},
	    {{0xAA}, {0xEF, 0xBA, 0x95}},
	    {{0xAB}, {0xEF, 0xBA, 0x99}},
	    {{0xAC}, {0xD8, 0x8C}},
	    {{0xAD}, {0xEF, 0xBA, 0x9D}},
	    {{0xAE}, {0xEF, 0xBA, 0xA1}},
	    {{0xAF}, {0xEF, 0xBA, 0xA5}},
	    {{0xB0}, {0xD9, 0xA0}},
	    {{0xB1}, {0xD9, 0xA1}},
	    {{0xB2}, {0xD9, 0xA2}},
	    {{0xB3}, {0xD9, 0xA3}},
	    {{0xB4}, {0xD9, 0xA4}},
	    {{0xB5}, {0xD9, 0xA5}},
	    {{0xB6}, {0xD9, 0xA6}},
	    {{0xB7}, {0xD9, 0xA7}},
	    {{0xB8}, {0xD9, 0xA8}},
	    {{0xB9}, {0xD9, 0xA9}},
	    {{0xBA}, {0xEF, 0xBB, 0x91}},
	    {{0xBB}, {0xD8, 0x9B}},
	    {{0xBC}, {0xEF, 0xBA, 0xB1}},
	    {{0xBD}, {0xEF, 0xBA, 0xB5}},
	    {{0xBE}, {0xEF, 0xBA, 0xB9}},
	    {{0xBF}, {0xD8, 0x9F}},
	    {{0xC0}, {0xC2, 0xA2}},
	    {{0xC5}, {0xEF, 0xBB, 0x8A}},
	    {{0xC7}, {0xEF, 0xBA, 0x8D}},
	    {{0xC8}, {0xEF, 0xBA, 0x91}},
	    {{0xC9}, {0xEF, 0xBA, 0x93}},
	    {{0xCA}, {0xEF, 0xBA, 0x97}},
	    {{0xCB}, {0xEF, 0xBA, 0x9B}},
	    {{0xCC}, {0xEF, 0xBA, 0x9F}},
	    {{0xCD}, {0xEF, 0xBA, 0xA3}},
	    {{0xCE}, {0xEF, 0xBA, 0xA7}},
	    {{0xCF}, {0xEF, 0xBA, 0xA9}},
	    {{0xD0}, {0xEF, 0xBA, 0xAB}},
	    {{0xD1}, {0xEF, 0xBA, 0xAD}},
	    {{0xD2}, {0xEF, 0xBA, 0xAF}},
	    {{0xD3}, {0xEF, 0xBA, 0xB3}},
	    {{0xD4}, {0xEF, 0xBA, 0xB7}},
	    {{0xD5}, {0xEF, 0xBA, 0xBB}},
	    {{0xD6}, {0xEF, 0xBA, 0xBF}},
	    {{0xD7}, {0xEF, 0xBB, 0x81}},
	    {{0xD8}, {0xEF, 0xBB, 0x85}},
	    {{0xD9}, {0xEF, 0xBB, 0x8B}},
	    {{0xDA}, {0xEF, 0xBB, 0x8F}},
	    {{0xDB}, {0xC2, 0xA6}},
	    {{0xDC}, {0xC2, 0xAC}},
	    {{0xDD}, {0xC3, 0xB7}},
	    {{0xDE}, {0xC3, 0x97}},
	    {{0xDF}, {0xEF, 0xBB, 0x89}},
	    {{0xE0}, {0xD9, 0x80}},
	    {{0xE1}, {0xEF, 0xBB, 0x93}},
	    {{0xE2}, {0xEF, 0xBB, 0x97}},
	    {{0xE3}, {0xEF, 0xBB, 0x9B}},
	    {{0xE4}, {0xEF, 0xBB, 0x9F}},
	    {{0xE5}, {0xEF, 0xBB, 0xA3}},
	    {{0xE6}, {0xEF, 0xBB, 0xA7}},
	    {{0xE7}, {0xEF, 0xBB, 0xAB}},
	    {{0xE8}, {0xEF, 0xBB, 0xAD}},
	    {{0xE9}, {0xEF, 0xBB, 0xAF}},
	    {{0xEA}, {0xEF, 0xBB, 0xB3}},
	    {{0xEB}, {0xEF, 0xBA, 0xBD}},
	    {{0xEC}, {0xEF, 0xBB, 0x8C}},
	    {{0xED}, {0xEF, 0xBB, 0x8E}},
	    {{0xEE}, {0xEF, 0xBB, 0x8D}},
	    {{0xEF}, {0xEF, 0xBB, 0xA1}},
	    {{0xF0}, {0xEF, 0xB9, 0xBD}},
	    {{0xF1}, {0xD9, 0x91}},
	    {{0xF2}, {0xEF, 0xBB, 0xA5}},
	    {{0xF3}, {0xEF, 0xBB, 0xA9}},
	    {{0xF4}, {0xEF, 0xBB, 0xAC}},
	    {{0xF5}, {0xEF, 0xBB, 0xB0}},
	    {{0xF6}, {0xEF, 0xBB, 0xB2}},
	    {{0xF7}, {0xEF, 0xBB, 0x90}},
	    {{0xF8}, {0xEF, 0xBB, 0x95}},
	    {{0xF9}, {0xEF, 0xBB, 0xB5}},
	    {{0xFA}, {0xEF, 0xBB, 0xB6}},
	    {{0xFB}, {0xEF, 0xBB, 0x9D}},
	    {{0xFC}, {0xEF, 0xBB, 0x99}},
	    {{0xFD}, {0xEF, 0xBB, 0xB1}},
	    {{0xFE}, {0xE2, 0x96, 0xA0}},
	};
	static void Register(const DBConfig &config) {
		const Cp864ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                generated_function.cp864_to_utf8);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
