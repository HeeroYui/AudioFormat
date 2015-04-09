/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/int16_16_t.h>
#include <audio/debug.h>

audio::int16_16_t::int16_16_t(const audio::int8_8_t& _val) {
	m_data = int16_t(_val.get()) << 8;
}

audio::int16_16_t::int16_16_t(const audio::int8_16_t& _val) {
	m_data = std::avg(int16_t(INT8_MIN),
	                  _val.get(),
	                  int16_t(INT8_MAX)
	                  ) << 7;
}

audio::int16_16_t::int16_16_t(const audio::int16_16_t& _val) {
	m_data = _val.m_data;
}

audio::int16_16_t::int16_16_t(const audio::int16_32_t& _val) {
	m_data = int16_t(std::avg(int32_t(INT16_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT16_MAX)
	                          )
	                 );
}

audio::int16_16_t::int16_16_t(const audio::int24_24_t& _val) {
	m_data = int16_t(_val.get() >> 8);
}

audio::int16_16_t::int16_16_t(const audio::int24_32_t& _val) {
	m_data = int16_t(std::avg(int32_t(INT24_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT24_MAX)
	                          ) >> 8
	                 );
}

audio::int16_16_t::int16_16_t(const audio::int32_32_t& _val) {
	m_data = int16_t(_val.get() >> 16);
}

audio::int16_16_t::int16_16_t(const audio::int32_64_t& _val) {
	m_data = int16_t(std::avg(int64_t(INT32_MIN),
	                          _val.get() >> 1,
	                          int64_t(INT32_MAX)
	                          ) >> 16
	                 );
}

audio::int16_16_t::int16_16_t(const audio::int64_64_t& _val) {
	m_data = int16_t(_val.get() >> 48);
}

audio::int16_16_t::int16_16_t(const audio::float_t& _val) {
	m_data = int16_t(std::avg(-1.0f,
	                          _val.get(),
	                          0.999969482f
	                          ) * (float(INT16_MAX)+1)
	                 );
}

audio::int16_16_t::int16_16_t(const audio::double_t& _val) {
	m_data = int16_t(std::avg(-1.0,
	                          _val.get(),
	                          0.999969482
	                          ) * (double(INT16_MAX)+1)
	                 );
}

audio::int16_16_t::int16_16_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int16_16_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (15-_flotingPointPosition);
	m_data = std::avg(int64_t(INT16_MIN), val, int64_t(INT16_MAX));
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int16_16_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":0.15=";
	_os << etk::to_string(double(_obj.get())/(double(INT16_MAX)+1));
	_os << "]";
	return _os;
}

