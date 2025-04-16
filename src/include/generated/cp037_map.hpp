//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/cp037_map.hpp
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

class Cp037ToUtf {
public:
	Cp037ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 2;
	const string name = "cp037";
	// Generated from: glibc-IBM037-2.1.2.ucm
	const map<vector<uint8_t>, vector<uint8_t>> cp037_to_utf8 = {
	    {{0x00}, {0x00}},       {{0x01}, {0x01}},       {{0x02}, {0x02}},       {{0x03}, {0x03}},
	    {{0x04}, {0xC2, 0x9C}}, {{0x05}, {0x09}},       {{0x06}, {0xC2, 0x86}}, {{0x07}, {0x7F}},
	    {{0x08}, {0xC2, 0x97}}, {{0x09}, {0xC2, 0x8D}}, {{0x0A}, {0xC2, 0x8E}}, {{0x0B}, {0x0B}},
	    {{0x0C}, {0x0C}},       {{0x0D}, {0x0D}},       {{0x0E}, {0x0E}},       {{0x0F}, {0x0F}},
	    {{0x10}, {0x10}},       {{0x11}, {0x11}},       {{0x12}, {0x12}},       {{0x13}, {0x13}},
	    {{0x14}, {0xC2, 0x9D}}, {{0x15}, {0xC2, 0x85}}, {{0x16}, {0x08}},       {{0x17}, {0xC2, 0x87}},
	    {{0x18}, {0x18}},       {{0x19}, {0x19}},       {{0x1A}, {0xC2, 0x92}}, {{0x1B}, {0xC2, 0x8F}},
	    {{0x1C}, {0x1C}},       {{0x1D}, {0x1D}},       {{0x1E}, {0x1E}},       {{0x1F}, {0x1F}},
	    {{0x20}, {0xC2, 0x80}}, {{0x21}, {0xC2, 0x81}}, {{0x22}, {0xC2, 0x82}}, {{0x23}, {0xC2, 0x83}},
	    {{0x24}, {0xC2, 0x84}}, {{0x25}, {0x0A}},       {{0x26}, {0x17}},       {{0x27}, {0x1B}},
	    {{0x28}, {0xC2, 0x88}}, {{0x29}, {0xC2, 0x89}}, {{0x2A}, {0xC2, 0x8A}}, {{0x2B}, {0xC2, 0x8B}},
	    {{0x2C}, {0xC2, 0x8C}}, {{0x2D}, {0x05}},       {{0x2E}, {0x06}},       {{0x2F}, {0x07}},
	    {{0x30}, {0xC2, 0x90}}, {{0x31}, {0xC2, 0x91}}, {{0x32}, {0x16}},       {{0x33}, {0xC2, 0x93}},
	    {{0x34}, {0xC2, 0x94}}, {{0x35}, {0xC2, 0x95}}, {{0x36}, {0xC2, 0x96}}, {{0x37}, {0x04}},
	    {{0x38}, {0xC2, 0x98}}, {{0x39}, {0xC2, 0x99}}, {{0x3A}, {0xC2, 0x9A}}, {{0x3B}, {0xC2, 0x9B}},
	    {{0x3C}, {0x14}},       {{0x3D}, {0x15}},       {{0x3E}, {0xC2, 0x9E}}, {{0x3F}, {0x1A}},
	    {{0x40}, {0x20}},       {{0x41}, {0xC2, 0xA0}}, {{0x42}, {0xC3, 0xA2}}, {{0x43}, {0xC3, 0xA4}},
	    {{0x44}, {0xC3, 0xA0}}, {{0x45}, {0xC3, 0xA1}}, {{0x46}, {0xC3, 0xA3}}, {{0x47}, {0xC3, 0xA5}},
	    {{0x48}, {0xC3, 0xA7}}, {{0x49}, {0xC3, 0xB1}}, {{0x4A}, {0xC2, 0xA2}}, {{0x4B}, {0x2E}},
	    {{0x4C}, {0x3C}},       {{0x4D}, {0x28}},       {{0x4E}, {0x2B}},       {{0x4F}, {0x7C}},
	    {{0x50}, {0x26}},       {{0x51}, {0xC3, 0xA9}}, {{0x52}, {0xC3, 0xAA}}, {{0x53}, {0xC3, 0xAB}},
	    {{0x54}, {0xC3, 0xA8}}, {{0x55}, {0xC3, 0xAD}}, {{0x56}, {0xC3, 0xAE}}, {{0x57}, {0xC3, 0xAF}},
	    {{0x58}, {0xC3, 0xAC}}, {{0x59}, {0xC3, 0x9F}}, {{0x5A}, {0x21}},       {{0x5B}, {0x24}},
	    {{0x5C}, {0x2A}},       {{0x5D}, {0x29}},       {{0x5E}, {0x3B}},       {{0x5F}, {0xC2, 0xAC}},
	    {{0x60}, {0x2D}},       {{0x61}, {0x2F}},       {{0x62}, {0xC3, 0x82}}, {{0x63}, {0xC3, 0x84}},
	    {{0x64}, {0xC3, 0x80}}, {{0x65}, {0xC3, 0x81}}, {{0x66}, {0xC3, 0x83}}, {{0x67}, {0xC3, 0x85}},
	    {{0x68}, {0xC3, 0x87}}, {{0x69}, {0xC3, 0x91}}, {{0x6A}, {0xC2, 0xA6}}, {{0x6B}, {0x2C}},
	    {{0x6C}, {0x25}},       {{0x6D}, {0x5F}},       {{0x6E}, {0x3E}},       {{0x6F}, {0x3F}},
	    {{0x70}, {0xC3, 0xB8}}, {{0x71}, {0xC3, 0x89}}, {{0x72}, {0xC3, 0x8A}}, {{0x73}, {0xC3, 0x8B}},
	    {{0x74}, {0xC3, 0x88}}, {{0x75}, {0xC3, 0x8D}}, {{0x76}, {0xC3, 0x8E}}, {{0x77}, {0xC3, 0x8F}},
	    {{0x78}, {0xC3, 0x8C}}, {{0x79}, {0x60}},       {{0x7A}, {0x3A}},       {{0x7B}, {0x23}},
	    {{0x7C}, {0x40}},       {{0x7D}, {0x27}},       {{0x7E}, {0x3D}},       {{0x7F}, {0x22}},
	    {{0x80}, {0xC3, 0x98}}, {{0x81}, {0x61}},       {{0x82}, {0x62}},       {{0x83}, {0x63}},
	    {{0x84}, {0x64}},       {{0x85}, {0x65}},       {{0x86}, {0x66}},       {{0x87}, {0x67}},
	    {{0x88}, {0x68}},       {{0x89}, {0x69}},       {{0x8A}, {0xC2, 0xAB}}, {{0x8B}, {0xC2, 0xBB}},
	    {{0x8C}, {0xC3, 0xB0}}, {{0x8D}, {0xC3, 0xBD}}, {{0x8E}, {0xC3, 0xBE}}, {{0x8F}, {0xC2, 0xB1}},
	    {{0x90}, {0xC2, 0xB0}}, {{0x91}, {0x6A}},       {{0x92}, {0x6B}},       {{0x93}, {0x6C}},
	    {{0x94}, {0x6D}},       {{0x95}, {0x6E}},       {{0x96}, {0x6F}},       {{0x97}, {0x70}},
	    {{0x98}, {0x71}},       {{0x99}, {0x72}},       {{0x9A}, {0xC2, 0xAA}}, {{0x9B}, {0xC2, 0xBA}},
	    {{0x9C}, {0xC3, 0xA6}}, {{0x9D}, {0xC2, 0xB8}}, {{0x9E}, {0xC3, 0x86}}, {{0x9F}, {0xC2, 0xA4}},
	    {{0xA0}, {0xC2, 0xB5}}, {{0xA1}, {0x7E}},       {{0xA2}, {0x73}},       {{0xA3}, {0x74}},
	    {{0xA4}, {0x75}},       {{0xA5}, {0x76}},       {{0xA6}, {0x77}},       {{0xA7}, {0x78}},
	    {{0xA8}, {0x79}},       {{0xA9}, {0x7A}},       {{0xAA}, {0xC2, 0xA1}}, {{0xAB}, {0xC2, 0xBF}},
	    {{0xAC}, {0xC3, 0x90}}, {{0xAD}, {0xC3, 0x9D}}, {{0xAE}, {0xC3, 0x9E}}, {{0xAF}, {0xC2, 0xAE}},
	    {{0xB0}, {0x5E}},       {{0xB1}, {0xC2, 0xA3}}, {{0xB2}, {0xC2, 0xA5}}, {{0xB3}, {0xC2, 0xB7}},
	    {{0xB4}, {0xC2, 0xA9}}, {{0xB5}, {0xC2, 0xA7}}, {{0xB6}, {0xC2, 0xB6}}, {{0xB7}, {0xC2, 0xBC}},
	    {{0xB8}, {0xC2, 0xBD}}, {{0xB9}, {0xC2, 0xBE}}, {{0xBA}, {0x5B}},       {{0xBB}, {0x5D}},
	    {{0xBC}, {0xC2, 0xAF}}, {{0xBD}, {0xC2, 0xA8}}, {{0xBE}, {0xC2, 0xB4}}, {{0xBF}, {0xC3, 0x97}},
	    {{0xC0}, {0x7B}},       {{0xC1}, {0x41}},       {{0xC2}, {0x42}},       {{0xC3}, {0x43}},
	    {{0xC4}, {0x44}},       {{0xC5}, {0x45}},       {{0xC6}, {0x46}},       {{0xC7}, {0x47}},
	    {{0xC8}, {0x48}},       {{0xC9}, {0x49}},       {{0xCA}, {0xC2, 0xAD}}, {{0xCB}, {0xC3, 0xB4}},
	    {{0xCC}, {0xC3, 0xB6}}, {{0xCD}, {0xC3, 0xB2}}, {{0xCE}, {0xC3, 0xB3}}, {{0xCF}, {0xC3, 0xB5}},
	    {{0xD0}, {0x7D}},       {{0xD1}, {0x4A}},       {{0xD2}, {0x4B}},       {{0xD3}, {0x4C}},
	    {{0xD4}, {0x4D}},       {{0xD5}, {0x4E}},       {{0xD6}, {0x4F}},       {{0xD7}, {0x50}},
	    {{0xD8}, {0x51}},       {{0xD9}, {0x52}},       {{0xDA}, {0xC2, 0xB9}}, {{0xDB}, {0xC3, 0xBB}},
	    {{0xDC}, {0xC3, 0xBC}}, {{0xDD}, {0xC3, 0xB9}}, {{0xDE}, {0xC3, 0xBA}}, {{0xDF}, {0xC3, 0xBF}},
	    {{0xE0}, {0x5C}},       {{0xE1}, {0xC3, 0xB7}}, {{0xE2}, {0x53}},       {{0xE3}, {0x54}},
	    {{0xE4}, {0x55}},       {{0xE5}, {0x56}},       {{0xE6}, {0x57}},       {{0xE7}, {0x58}},
	    {{0xE8}, {0x59}},       {{0xE9}, {0x5A}},       {{0xEA}, {0xC2, 0xB2}}, {{0xEB}, {0xC3, 0x94}},
	    {{0xEC}, {0xC3, 0x96}}, {{0xED}, {0xC3, 0x92}}, {{0xEE}, {0xC3, 0x93}}, {{0xEF}, {0xC3, 0x95}},
	    {{0xF0}, {0x30}},       {{0xF1}, {0x31}},       {{0xF2}, {0x32}},       {{0xF3}, {0x33}},
	    {{0xF4}, {0x34}},       {{0xF5}, {0x35}},       {{0xF6}, {0x36}},       {{0xF7}, {0x37}},
	    {{0xF8}, {0x38}},       {{0xF9}, {0x39}},       {{0xFA}, {0xC2, 0xB3}}, {{0xFB}, {0xC3, 0x9B}},
	    {{0xFC}, {0xC3, 0x9C}}, {{0xFD}, {0xC3, 0x99}}, {{0xFE}, {0xC3, 0x9A}}, {{0xFF}, {0xC2, 0x9F}},
	};
	static void Register(const DBConfig &config) {
		const Cp037ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                generated_function.cp037_to_utf8);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
