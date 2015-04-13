/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */


#include <audio/Time.h>
#include <audio/Duration.h>
#include <audio/debug.h>

audio::Time::Time(int64_t _valSec, int64_t _valNano) {
	m_data = std11::chrono::steady_clock::time_point(std11::chrono::seconds(_valSec));
	m_data += std11::chrono::nanoseconds(_valNano);
}
audio::Time::Time(const std11::chrono::steady_clock::time_point& _val) {
	m_data = _val;
}

audio::Time audio::Time::now() {
	return audio::Time(std11::chrono::steady_clock::now());
}

const audio::Time& audio::Time::operator= (const audio::Time& _obj) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::Time::operator== (const audio::Time& _obj) const {
	return m_data == _obj.m_data;
}

bool audio::Time::operator!= (const audio::Time& _obj) const {
	return m_data != _obj.m_data;
}

bool audio::Time::operator< (const audio::Time& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::Time::operator<= (const audio::Time& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::Time::operator> (const audio::Time& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::Time::operator>= (const audio::Time& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::Time& audio::Time::operator+= (const audio::Duration& _obj) {
	#if defined(__TARGET_OS__MacOs) || defined(__TARGET_OS__IOs)
		std11::chrono::microseconds ms = std11::chrono::duration_cast<std11::chrono::microseconds>(_obj.get());
		m_data += ms;
	#else
		m_data += _obj.get();
	#endif
	return *this;
}

audio::Time audio::Time::operator+ (const audio::Duration& _obj) const {
	audio::Time time(m_data);
	time += _obj;
	return time;
}

const audio::Time& audio::Time::operator-= (const audio::Duration& _obj) {
	#if defined(__TARGET_OS__MacOs) || defined(__TARGET_OS__IOs)
		std11::chrono::microseconds ms = std11::chrono::duration_cast<std11::chrono::microseconds>(_obj.get());
		m_data -= ms;
	#else
		m_data -= _obj.get();
	#endif
	return *this;
}

audio::Time audio::Time::operator- (const audio::Duration& _obj) const {
	audio::Time time(m_data);
	time -= _obj;
	return time;
}

audio::Duration audio::Time::operator- (const audio::Time& _obj) const {
	std11::chrono::nanoseconds ns = std11::chrono::duration_cast<std11::chrono::nanoseconds>(m_data.time_since_epoch());
	std11::chrono::nanoseconds ns2 = std11::chrono::duration_cast<std11::chrono::nanoseconds>(_obj.m_data.time_since_epoch());
	audio::Duration duration(ns);
	audio::Duration duration2(ns2);
	return duration - duration2;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::Time& _obj) {
	std11::chrono::nanoseconds ns = std11::chrono::duration_cast<std11::chrono::nanoseconds>(_obj.get().time_since_epoch());
	int64_t totalSecond = ns.count()/1000000000;
	int64_t millisecond = (ns.count()%1000000000)/1000000;
	int64_t microsecond = (ns.count()%1000000)/1000;
	int64_t nanosecond = ns.count()%1000;
	//_os << totalSecond << "s " << millisecond << "ms " << microsecond << "µs " << nanosecond << "ns";
	int32_t second = totalSecond % 60;
	int32_t minute = (totalSecond/60)%60;
	int32_t hour = (totalSecond/3600)%24;
	int32_t day = (totalSecond/(24*3600))%365;
	int32_t year = totalSecond/(24*3600*365);
	bool start = false;
	if (year != 0) {
		start = true;
		_os << year << "y ";
	}
	if (day != 0 || start == true) {
		start = true;
		_os << day << "d ";
	}
	if (hour != 0 || start == true) {
		start = true;
		_os << hour << "h ";
	}
	if (minute != 0 || start == true) {
		start = true;
		_os << minute << ":";
	}
	if (second != 0 || start == true) {
		start = true;
		_os << second << "s ";
	}
	if (millisecond != 0 || start == true) {
		start = true;
		_os << millisecond << "ms ";
	}
	if (microsecond != 0 || start == true) {
		start = true;
		_os << microsecond << "us ";
	}
	_os << nanosecond << "ns ";
	return _os;
}
