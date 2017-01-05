/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>

/**
 * @brief Audio library namespace
 */
namespace audio {
	class int8_8_t;
	class int8_16_t;
	class int16_16_t;
	class int16_32_t;
	class int24_24_t;
	class int24_32_t;
	class int32_32_t;
	class int32_64_t;
	class int64_64_t;
	class float_t;
	class double_t;
}

#define INT24_MIN 0xFFFFFFFFFF800000LL
#define INT24_MAX 0x00000000007FFFFFLL

#define INT40_MIN 0xFFFFFF8000000000LL
#define INT40_MAX 0x0000007FFFFFFFFFLL

#define INT56_MIN 0xFFFF800000000000LL
#define INT56_MAX 0x00007FFFFFFFFFFFLL

#include <audio/int8_8_t.hpp>
#include <audio/int8_16_t.hpp>
#include <audio/int16_16_t.hpp>
#include <audio/int16_32_t.hpp>
#include <audio/int24_24_t.hpp>
#include <audio/int24_32_t.hpp>
#include <audio/int32_32_t.hpp>
#include <audio/int32_64_t.hpp>
#include <audio/int64_64_t.hpp>
#include <audio/float_t.hpp>
#include <audio/double_t.hpp>
