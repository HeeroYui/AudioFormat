/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>
#include <etk/Stream.hpp>

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

extern const int64_t INT24_MIN;
extern const int64_t INT24_MAX;

extern const int64_t INT40_MIN;
extern const int64_t INT40_MAX;

extern const int64_t INT56_MIN;
extern const int64_t INT56_MAX;

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
