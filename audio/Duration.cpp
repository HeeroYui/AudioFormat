/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */


#include <audio/Time.hpp>
#include <audio/Duration.hpp>
#include <audio/debug.hpp>

audio::Duration::Duration(int _val) {
	m_data = std::chrono::nanoseconds(_val);
}

audio::Duration::Duration(int64_t _valSec, int64_t _valNano) {
	m_data = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(_valSec));
	m_data += std::chrono::nanoseconds(_valNano);
}

audio::Duration::Duration(int64_t _val) {
	m_data = std::chrono::nanoseconds(_val);
}

audio::Duration::Duration(double _val) {
	m_data = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::seconds(int64_t(_val)));
	m_data += std::chrono::nanoseconds(int64_t(((_val - int64_t(_val)) * 1000000000.0)));
}

audio::Duration::Duration(std::chrono::nanoseconds _val) {
	m_data = std::chrono::duration_cast<std::chrono::nanoseconds>(_val);
}

audio::Duration::Duration(std::chrono::microseconds _val) {
	m_data = std::chrono::duration_cast<std::chrono::nanoseconds>(_val);
}

audio::Duration::Duration(std::chrono::milliseconds _val) {
	m_data = std::chrono::duration_cast<std::chrono::nanoseconds>(_val);
}

audio::Duration::Duration(std::chrono::seconds _val) {
	m_data = std::chrono::duration_cast<std::chrono::nanoseconds>(_val);
}

int64_t audio::Duration::count() const {
	return m_data.count();
}

const audio::Duration& audio::Duration::operator= (const audio::Duration& _obj) {
	m_data = _obj.m_data;
	return *this;
}
bool audio::Duration::operator== (const audio::Duration& _obj) const {
	return _obj.m_data == m_data;
}
bool audio::Duration::operator!= (const audio::Duration& _obj) const {
	return _obj.m_data != m_data;
}
bool audio::Duration::operator< (const audio::Duration& _obj) const {
	return m_data < _obj.m_data;
}
bool audio::Duration::operator<= (const audio::Duration& _obj) const {
	return m_data <= _obj.m_data;
}
bool audio::Duration::operator> (const audio::Duration& _obj) const {
	return m_data > _obj.m_data;
}
bool audio::Duration::operator>= (const audio::Duration& _obj) const {
	return m_data >= _obj.m_data;
}
const audio::Duration& audio::Duration::operator+= (const audio::Duration& _obj) {
	m_data += _obj.m_data;
	return *this;
}
audio::Duration audio::Duration::operator+ (const audio::Duration& _obj) const {
	audio::Duration tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}
const audio::Duration& audio::Duration::operator-= (const audio::Duration& _obj) {
	m_data -= _obj.m_data;
	return *this;
}
audio::Duration audio::Duration::operator- (const audio::Duration& _obj) const {
	audio::Duration tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

audio::Duration& audio::Duration::operator++() {
	m_data += std::chrono::nanoseconds(1);
	return *this;
}
audio::Duration audio::Duration::operator++(int _unused) {
	audio::Duration result(m_data);
	m_data += std::chrono::nanoseconds(1);
	return result;
}
audio::Duration& audio::Duration::operator--() {
	m_data -= std::chrono::nanoseconds(1);
	return *this;
}
audio::Duration audio::Duration::operator--(int _unused) {
	m_data -= std::chrono::nanoseconds(1);
	audio::Duration result(m_data);
	return result;
}


std::ostream& audio::operator <<(std::ostream& _os, const audio::Duration& _obj) {
	int64_t totalSecond = _obj.count()/1000000000;
	int64_t millisecond = (_obj.count()%1000000000)/1000000;
	int64_t microsecond = (_obj.count()%1000000)/1000;
	int64_t nanosecond = _obj.count()%1000;
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


