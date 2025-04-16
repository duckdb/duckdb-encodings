//===----------------------------------------------------------------------===//
//
//                         DuckDB - Encodings
//
// generated/cp861_map.hpp
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

class Cp861ToUtf {
public:
	Cp861ToUtf() {};
	const idx_t lookup_bytes = 1;
	const idx_t max_bytes_per_byte = 3;
	const string name = "cp861";
	// Generated from: glibc-IBM861-2.1.2.ucm
	const map<vector<uint8_t>, vector<uint8_t>> cp861_to_utf8 = {
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
	    {{0x25}, {0x25}},
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
	    {{0x80}, {0xC3, 0x87}},
	    {{0x81}, {0xC3, 0xBC}},
	    {{0x82}, {0xC3, 0xA9}},
	    {{0x83}, {0xC3, 0xA2}},
	    {{0x84}, {0xC3, 0xA4}},
	    {{0x85}, {0xC3, 0xA0}},
	    {{0x86}, {0xC3, 0xA5}},
	    {{0x87}, {0xC3, 0xA7}},
	    {{0x88}, {0xC3, 0xAA}},
	    {{0x89}, {0xC3, 0xAB}},
	    {{0x8A}, {0xC3, 0xA8}},
	    {{0x8B}, {0xC3, 0x90}},
	    {{0x8C}, {0xC3, 0xB0}},
	    {{0x8D}, {0xC3, 0x9E}},
	    {{0x8E}, {0xC3, 0x84}},
	    {{0x8F}, {0xC3, 0x85}},
	    {{0x90}, {0xC3, 0x89}},
	    {{0x91}, {0xC3, 0xA6}},
	    {{0x92}, {0xC3, 0x86}},
	    {{0x93}, {0xC3, 0xB4}},
	    {{0x94}, {0xC3, 0xB6}},
	    {{0x95}, {0xC3, 0xBE}},
	    {{0x96}, {0xC3, 0xBB}},
	    {{0x97}, {0xC3, 0x9D}},
	    {{0x98}, {0xC3, 0xBD}},
	    {{0x99}, {0xC3, 0x96}},
	    {{0x9A}, {0xC3, 0x9C}},
	    {{0x9B}, {0xC3, 0xB8}},
	    {{0x9C}, {0xC2, 0xA3}},
	    {{0x9D}, {0xC3, 0x98}},
	    {{0x9E}, {0xE2, 0x82, 0xA7}},
	    {{0x9F}, {0xC6, 0x92}},
	    {{0xA0}, {0xC3, 0xA1}},
	    {{0xA1}, {0xC3, 0xAD}},
	    {{0xA2}, {0xC3, 0xB3}},
	    {{0xA3}, {0xC3, 0xBA}},
	    {{0xA4}, {0xC3, 0x81}},
	    {{0xA5}, {0xC3, 0x8D}},
	    {{0xA6}, {0xC3, 0x93}},
	    {{0xA7}, {0xC3, 0x9A}},
	    {{0xA8}, {0xC2, 0xBF}},
	    {{0xA9}, {0xE2, 0x8C, 0x90}},
	    {{0xAA}, {0xC2, 0xAC}},
	    {{0xAB}, {0xC2, 0xBD}},
	    {{0xAC}, {0xC2, 0xBC}},
	    {{0xAD}, {0xC2, 0xA1}},
	    {{0xAE}, {0xC2, 0xAB}},
	    {{0xAF}, {0xC2, 0xBB}},
	    {{0xB0}, {0xE2, 0x96, 0x91}},
	    {{0xB1}, {0xE2, 0x96, 0x92}},
	    {{0xB2}, {0xE2, 0x96, 0x93}},
	    {{0xB3}, {0xE2, 0x94, 0x82}},
	    {{0xB4}, {0xE2, 0x94, 0xA4}},
	    {{0xB5}, {0xE2, 0x95, 0xA1}},
	    {{0xB6}, {0xE2, 0x95, 0xA2}},
	    {{0xB7}, {0xE2, 0x95, 0x96}},
	    {{0xB8}, {0xE2, 0x95, 0x95}},
	    {{0xB9}, {0xE2, 0x95, 0xA3}},
	    {{0xBA}, {0xE2, 0x95, 0x91}},
	    {{0xBB}, {0xE2, 0x95, 0x97}},
	    {{0xBC}, {0xE2, 0x95, 0x9D}},
	    {{0xBD}, {0xE2, 0x95, 0x9C}},
	    {{0xBE}, {0xE2, 0x95, 0x9B}},
	    {{0xBF}, {0xE2, 0x94, 0x90}},
	    {{0xC0}, {0xE2, 0x94, 0x94}},
	    {{0xC1}, {0xE2, 0x94, 0xB4}},
	    {{0xC2}, {0xE2, 0x94, 0xAC}},
	    {{0xC3}, {0xE2, 0x94, 0x9C}},
	    {{0xC4}, {0xE2, 0x94, 0x80}},
	    {{0xC5}, {0xE2, 0x94, 0xBC}},
	    {{0xC6}, {0xE2, 0x95, 0x9E}},
	    {{0xC7}, {0xE2, 0x95, 0x9F}},
	    {{0xC8}, {0xE2, 0x95, 0x9A}},
	    {{0xC9}, {0xE2, 0x95, 0x94}},
	    {{0xCA}, {0xE2, 0x95, 0xA9}},
	    {{0xCB}, {0xE2, 0x95, 0xA6}},
	    {{0xCC}, {0xE2, 0x95, 0xA0}},
	    {{0xCD}, {0xE2, 0x95, 0x90}},
	    {{0xCE}, {0xE2, 0x95, 0xAC}},
	    {{0xCF}, {0xE2, 0x95, 0xA7}},
	    {{0xD0}, {0xE2, 0x95, 0xA8}},
	    {{0xD1}, {0xE2, 0x95, 0xA4}},
	    {{0xD2}, {0xE2, 0x95, 0xA5}},
	    {{0xD3}, {0xE2, 0x95, 0x99}},
	    {{0xD4}, {0xE2, 0x95, 0x98}},
	    {{0xD5}, {0xE2, 0x95, 0x92}},
	    {{0xD6}, {0xE2, 0x95, 0x93}},
	    {{0xD7}, {0xE2, 0x95, 0xAB}},
	    {{0xD8}, {0xE2, 0x95, 0xAA}},
	    {{0xD9}, {0xE2, 0x94, 0x98}},
	    {{0xDA}, {0xE2, 0x94, 0x8C}},
	    {{0xDB}, {0xE2, 0x96, 0x88}},
	    {{0xDC}, {0xE2, 0x96, 0x84}},
	    {{0xDD}, {0xE2, 0x96, 0x8C}},
	    {{0xDE}, {0xE2, 0x96, 0x90}},
	    {{0xDF}, {0xE2, 0x96, 0x80}},
	    {{0xE0}, {0xCE, 0xB1}},
	    {{0xE1}, {0xC3, 0x9F}},
	    {{0xE2}, {0xCE, 0x93}},
	    {{0xE3}, {0xCF, 0x80}},
	    {{0xE4}, {0xCE, 0xA3}},
	    {{0xE5}, {0xCF, 0x83}},
	    {{0xE6}, {0xC2, 0xB5}},
	    {{0xE7}, {0xCF, 0x84}},
	    {{0xE8}, {0xCE, 0xA6}},
	    {{0xE9}, {0xCE, 0x98}},
	    {{0xEA}, {0xCE, 0xA9}},
	    {{0xEB}, {0xCE, 0xB4}},
	    {{0xEC}, {0xE2, 0x88, 0x9E}},
	    {{0xED}, {0xCF, 0x86}},
	    {{0xEE}, {0xCE, 0xB5}},
	    {{0xEF}, {0xE2, 0x88, 0xA9}},
	    {{0xF0}, {0xE2, 0x89, 0xA1}},
	    {{0xF1}, {0xC2, 0xB1}},
	    {{0xF2}, {0xE2, 0x89, 0xA5}},
	    {{0xF3}, {0xE2, 0x89, 0xA4}},
	    {{0xF4}, {0xE2, 0x8C, 0xA0}},
	    {{0xF5}, {0xE2, 0x8C, 0xA1}},
	    {{0xF6}, {0xC3, 0xB7}},
	    {{0xF7}, {0xE2, 0x89, 0x88}},
	    {{0xF8}, {0xC2, 0xB0}},
	    {{0xF9}, {0xE2, 0x88, 0x99}},
	    {{0xFA}, {0xC2, 0xB7}},
	    {{0xFB}, {0xE2, 0x88, 0x9A}},
	    {{0xFC}, {0xE2, 0x81, 0xBF}},
	    {{0xFD}, {0xC2, 0xB2}},
	    {{0xFE}, {0xE2, 0x96, 0xA0}},
	    {{0xFF}, {0xC2, 0xA0}},
	};
	static void Register(const DBConfig &config) {
		const Cp861ToUtf generated_function;
		const EncodingFunction function(generated_function.name, GeneratedEncodedFunction::Decode,
		                                generated_function.max_bytes_per_byte, generated_function.lookup_bytes,
		                                generated_function.cp861_to_utf8);
		config.RegisterEncodeFunction(function);
	}
};
} // namespace duckdb_encodings
} // namespace duckdb
