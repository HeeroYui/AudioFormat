/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT24_24_T_H__
#define __AUDIO_TYPE_INT24_24_T_H__

namespace audio {
	class int24_24_t {
		private:
			int8_t m_data[3];
		public:
			int24_24_t() {}
			// transformation operator:
			int24_24_t(const audio::int8_8_t& _val);
			int24_24_t(const audio::int8_16_t& _val);
			int24_24_t(const audio::int16_16_t& _val);
			int24_24_t(const audio::int16_32_t& _val);
			int24_24_t(const audio::int24_24_t& _val);
			int24_24_t(const audio::int24_32_t& _val);
			int24_24_t(const audio::int32_32_t& _val);
			int24_24_t(const audio::int32_64_t& _val);
			int24_24_t(const audio::int64_64_t& _val);
			int24_24_t(const audio::float_t& _val);
			int24_24_t(const audio::double_t& _val);
			// set operator
			int24_24_t(int32_t _value, int32_t _flotingPointPosition);
			void set(int32_t _value, int32_t _flotingPointPosition);
			int32_t get() const;
	};
}

#endif

