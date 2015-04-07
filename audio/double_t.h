/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_DOUBLE_T_H__
#define __AUDIO_TYPE_DOUBLE_T_H__

namespace audio {
	class double_t {
		private:
			double m_data;
		public:
			double get() const {
				return m_data;
			}
	};
}

#endif

