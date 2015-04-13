/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_DURATION_H__
#define __AUDIO_DURATION_H__

#include <etk/types.h>
#include <etk/chrono.h>

namespace audio {
	class Duration {
		private:
			std11::chrono::nanoseconds m_data;
		public:
			Duration() { };
			Duration(int _val); //value in nanosecond
			Duration(int64_t _val); //value in nanosecond
			Duration(int64_t _valSec, int64_t _valNano); //value in second and nanosecond
			Duration(double _val); //value in second
			Duration(std11::chrono::nanoseconds _val);
			Duration(std11::chrono::microseconds _val);
			Duration(std11::chrono::milliseconds _val);
			Duration(std11::chrono::seconds _val);
			~Duration() { };
			int64_t count() const;
			const std11::chrono::nanoseconds& get() const {
				return m_data;
			}
			const Duration& operator= (const Duration& _obj);
			bool operator== (const Duration& _obj) const;
			bool operator!= (const Duration& _obj) const;
			bool operator< (const audio::Duration& _obj) const;
			bool operator<= (const audio::Duration& _obj) const;
			bool operator> (const audio::Duration& _obj) const;
			bool operator>= (const audio::Duration& _obj) const;
			const Duration& operator+= (const Duration& _obj);
			Duration operator+ (const Duration& _obj) const;
			const Duration& operator-= (const Duration& _obj);
			Duration operator- (const Duration& _obj) const;
			Duration& operator++();
			Duration operator++(int _unused);
			Duration& operator--();
			Duration operator--(int _unused);
	};
	std::ostream& operator <<(std::ostream& _os, const audio::Duration& _obj);
}

#endif
