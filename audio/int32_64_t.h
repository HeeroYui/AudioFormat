/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT32_64_T_H__
#define __AUDIO_TYPE_INT32_64_T_H__

namespace audio {
	class int32_64_t {
		private:
			int64_t m_data;
		public:
			int64_t get() const {
				return m_data;
			}
	};
}

#endif

