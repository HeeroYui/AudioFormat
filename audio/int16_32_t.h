/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT16_32_T_H__
#define __AUDIO_TYPE_INT16_32_T_H__

namespace audio {
	class int16_32_t{
		private:
			int32_t m_data;
		public:
			int16_32_t() {}
			// transformation operator:
			int16_32_t(const audio::int8_8_t& _val);
			int16_32_t(const audio::int8_16_t& _val);
			int16_32_t(const audio::int16_16_t& _val);
			int16_32_t(const audio::int16_32_t& _val);
			int16_32_t(const audio::int24_24_t& _val);
			int16_32_t(const audio::int24_32_t& _val);
			int16_32_t(const audio::int32_32_t& _val);
			int16_32_t(const audio::int32_64_t& _val);
			int16_32_t(const audio::int64_64_t& _val);
			int16_32_t(const audio::float_t& _val);
			int16_32_t(const audio::double_t& _val);
			// set operator
			int16_32_t(int32_t _value, int32_t _flotingPointPosition);
			void set(int32_t _value, int32_t _flotingPointPosition);
			int32_t get() const {
				return m_data;
			}
	};
}

#endif

