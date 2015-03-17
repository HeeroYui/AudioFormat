/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_FORMAT_H__
#define __AUDIO_FORMAT_H__

#include <string>

#ifdef ETK_EXTERN_FRAMEWORK_ROS
	#include <ros/ros.h>
	#include "audio_msg/AudioBuffer.h"
	namespace audio {
		enum format {
			format_unknow         = audio_msg::AudioBuffer::FORMAT_UNKNOW,
			format_int8           = audio_msg::AudioBuffer::FORMAT_INT8,
			format_int8_on_int16  = audio_msg::AudioBuffer::FORMAT_INT8_ON_INT16,
			format_int16          = audio_msg::AudioBuffer::FORMAT_INT16,
			format_int16_on_int32 = audio_msg::AudioBuffer::FORMAT_INT16_ON_INT32,
			format_int24          = audio_msg::AudioBuffer::FORMAT_INT24,
			format_int32          = audio_msg::AudioBuffer::FORMAT_INT32,
			format_int32_on_int64 = audio_msg::AudioBuffer::FORMAT_INT32_ON_INT64,
			format_int64          = audio_msg::AudioBuffer::FORMAT_INT64,
			format_float          = audio_msg::AudioBuffer::FORMAT_FLOAT,
			format_double         = audio_msg::AudioBuffer::FORMAT_DOUBLE
		};
	};
#else
	namespace audio {
		enum format {
			format_unknow,
			format_int8, //!< Signed 8 bits
			format_int8_on_int16, //!< Signed 8 bits on 16 bits data (8 bit fixpoint value)
			format_int16, //!< Signed 16 bits
			format_int16_on_int32, //!< Signed 16 bits on 32 bits data (16 bit fixpoint value)
			format_int24, //!< Signed 24 bits on 32 bits (lower)
			format_int32, //!< Signed 32 bits
			format_int32_on_int64, //!< Signed 32 bits on 64 bits data (32 bit fixpoint value)
			format_int64, //!< Signed 64 bits
			format_float, //!< Floating point 32 bits (single precision)
			format_double //!< Floating point 64 bits (double precision)
		};
	};
#endif

namespace audio {
	std::string getFormatString(enum audio::format _format);
	enum audio::format getFormatFromString(const std::string& _value);
	std::vector<enum audio::format> getListFormatFromString(const std::string& _value);
	std::ostream& operator <<(std::ostream& _os, enum audio::format _obj);
	std::ostream& operator <<(std::ostream& _os, const std::vector<enum audio::format>& _obj);
	uint32_t getFormatBytes(enum audio::format _format);
	// For ROS Interface:
	std::vector<uint8_t> convertFormat(const std::vector<enum audio::format>& _obj);
	std::vector<enum audio::format> convertFormat(const std::vector<uint8_t>& _obj);
	uint8_t convertFormat(enum audio::format _obj);
	enum audio::format convertFormat(uint8_t _obj);
};


#endif

