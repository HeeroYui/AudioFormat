/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT24_32_T_H__
#define __AUDIO_TYPE_INT24_32_T_H__

namespace audio {
	class int24_32_t {
		private:
			int32_t m_data;
		public:
			int32_t get() const {
				return m_data;
			}
	};
}

#endif

