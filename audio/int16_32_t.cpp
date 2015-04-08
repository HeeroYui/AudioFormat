/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int16_32_t.h>


audio::int16_32_t::int16_32_t(const audio::int8_8_t& _val) {
	m_data = int32_t(_val.get()) << 8;
}

audio::int16_32_t::int16_32_t(const audio::int8_16_t& _val) {
	m_data = int32_t(_val.get()) << 8;
}

audio::int16_32_t::int16_32_t(const audio::int16_16_t& _val) {
	m_data = _val.get();
}

audio::int16_32_t::int16_32_t(const audio::int16_32_t& _val) {
	m_data = _val.m_data;
}

audio::int16_32_t::int16_32_t(const audio::int24_24_t& _val) {
	m_data = int32_t(_val.get() >> 8);
}

audio::int16_32_t::int16_32_t(const audio::int24_32_t& _val) {
	m_data = int32_t(_val.get() >> 8);;
}

audio::int16_32_t::int16_32_t(const audio::int32_32_t& _val) {
	m_data = int32_t(_val.get() >> 16);
}

audio::int16_32_t::int16_32_t(const audio::int32_64_t& _val) {
	m_data = int32_t(std::avg(int64_t(INT56_MIN),
	                          _val.get(),
	                          int64_t(INT56_MAX)
	                          ) >> 16
	                 );
}

audio::int16_32_t::int16_32_t(const audio::int64_64_t& _val) {
	m_data = int32_t(_val.get() >> 56);
}

audio::int16_32_t::int16_32_t(const audio::float_t& _val) {
	m_data = int32_t(std::avg(float(INT16_MIN),
	                          _val.get(),
	                          float(INT16_MAX)
	                          ) * float(INT16_MAX)
	                 );
}

audio::int16_32_t::int16_32_t(const audio::double_t& _val) {
	m_data = int32_t(std::avg(double(INT16_MIN),
	                          _val.get(),
	                          double(INT16_MAX)
	                          ) * double(INT16_MAX)
	                 );
}

audio::int16_32_t::int16_32_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int16_32_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (15-_flotingPointPosition);
	m_data = std::avg(int64_t(INT32_MIN), val, int64_t(INT32_MAX));
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int16_32_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":8.16=";
	_os << etk::to_string(double(_obj.get())/double(INT16_MAX));
	_os << "]";
	return _os;
}
