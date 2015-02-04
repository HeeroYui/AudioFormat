/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_CORE_FORMAT_H__
#define __AUDIO_CORE_FORMAT_H__

#include <string>

namespace audio {
	enum format {
		format_unknow,
		format_int8, //!< Signed 8 bits
		format_int16, //!< Signed 16 bits
		format_int16_on_int32, //!< Signed 16 bits on 32bits data (16 bit fixpoint value)
		format_int24, //!< Signed 24 bits
		format_int32, //!< Signed 32 bits
		format_float, //!< Floating point (single precision)
		format_double //!< Floating point (double precision)
	};
	std::string getFormatString(enum audio::format);
	enum audio::format getFormatFromString(const std::string& _value);
	std::ostream& operator <<(std::ostream& _os, enum audio::format _obj);
	std::ostream& operator <<(std::ostream& _os, const std::vector<enum audio::format>& _obj);
};


#endif

