/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <string>
#include <etk/types.hpp>
#include <chrono>

namespace audio {
	class Duration;
	class Time {
		private:
			std::chrono::steady_clock::time_point m_data;
		public:
			Time() {};
			//Time(const audio::Duration& _val) {}; //value in second
			Time(int64_t _valSec, int64_t _valNano);
			Time(const std::chrono::steady_clock::time_point& _val);
			~Time() {};
			const std::chrono::steady_clock::time_point& get() const {
				return m_data;
			}
			static Time now();
			const Time& operator= (const audio::Time& _obj );
			bool operator== (const audio::Time& _obj) const;
			bool operator!= (const audio::Time& _obj) const;
			bool operator< (const audio::Time& _obj) const;
			bool operator<= (const audio::Time& _obj) const;
			bool operator> (const audio::Time& _obj) const;
			bool operator>= (const audio::Time& _obj) const;
			const Time& operator+= (const audio::Duration& _obj);
			Time operator+ (const audio::Duration& _obj) const;
			const Time& operator-= (const audio::Duration& _obj);
			Time operator- (const audio::Duration& _obj) const;
			Duration operator- (const audio::Time& _obj) const;
	};
	std::ostream& operator <<(std::ostream& _os, const audio::Time& _obj);
}

