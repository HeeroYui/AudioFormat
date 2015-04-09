/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int64_64_t.h>


/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int16_32_t.h>


/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int16_32_t.h>



audio::int64_64_t::int64_64_t(const audio::int8_8_t& _val) {
	m_data = int64_t(_val.get()) << 56;
}

audio::int64_64_t::int64_64_t(const audio::int8_16_t& _val) {
	m_data = int64_t(std::avg(int32_t(INT8_MIN),
	                          int32_t(_val.get())>>1,
	                          int32_t(INT8_MAX)
	                          )) << 56;
}

audio::int64_64_t::int64_64_t(const audio::int16_16_t& _val) {
	m_data = int64_t(_val.get()) << 48;
}

audio::int64_64_t::int64_64_t(const audio::int16_32_t& _val) {
	m_data = int64_t(std::avg(int32_t(INT16_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT16_MAX)
	                          )) << 48;
}

audio::int64_64_t::int64_64_t(const audio::int24_24_t& _val) {
	m_data = int64_t(_val.get()) << 40;
}

audio::int64_64_t::int64_64_t(const audio::int24_32_t& _val) {
	m_data = int64_t(std::avg(int32_t(INT24_MIN),
	                          _val.get()>>1,
	                          int32_t(INT24_MAX)
	                          )) << 40;
}

audio::int64_64_t::int64_64_t(const audio::int32_32_t& _val) {
	m_data = int64_t(_val.get()) << 32;
}

audio::int64_64_t::int64_64_t(const audio::int32_64_t& _val) {
	m_data = int64_t(std::avg(int64_t(INT32_MIN),
	                          _val.get()>>1,
	                          int64_t(INT32_MAX)
	                          )) << 32;
}

audio::int64_64_t::int64_64_t(const audio::int64_64_t& _val) {
	m_data = _val.m_data;
}

audio::int64_64_t::int64_64_t(const audio::float_t& _val) {
	m_data = int64_t(std::avg(-1.0f,
	                          _val.get(),
	                          1.0f
	                          ) * (float(INT64_MAX) + 1.0f)
	                 );
}

audio::int64_64_t::int64_64_t(const audio::double_t& _val) {
	m_data = int64_t(std::avg(-1.0,
	                          _val.get(),
	                          1.0
	                          ) * (double(INT64_MAX) + 1.0f)
	                 );
}

audio::int64_64_t::int64_64_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int64_64_t::set(int64_t _value, int32_t _flotingPointPosition) {
	// TODO: do it better with int128_t elements
	int64_t val = _value << (63-_flotingPointPosition);
	m_data = std::avg(int64_t(INT64_MIN), val, int64_t(INT64_MAX));
}


std::ostream& audio::operator <<(std::ostream& _os, const audio::int64_64_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":0.63=";
	_os << etk::to_string(double(_obj.get())/double(INT64_MAX));
	_os << "]";
	return _os;
}
