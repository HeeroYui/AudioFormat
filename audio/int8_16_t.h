/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT8_16_T_H__
#define __AUDIO_TYPE_INT8_16_T_H__

namespace audio {
	class int8_16_t {
		private:
			int16_t m_data;
		public:
			int16_t get() const {
				return m_data;
			}
	};
}

#endif

