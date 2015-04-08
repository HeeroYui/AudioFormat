/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int24_32_t.h>


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



audio::int24_32_t::int24_32_t(const audio::int8_8_t& _val) {
	m_data = int32_t(_val.get()) << 16;
}

audio::int24_32_t::int24_32_t(const audio::int8_16_t& _val) {
	m_data = int32_t(_val.get()) << 16;
}

audio::int24_32_t::int24_32_t(const audio::int16_16_t& _val) {
	m_data = _val.get() << 8;
}

audio::int24_32_t::int24_32_t(const audio::int16_32_t& _val) {
	m_data = int32_t(std::avg(int32_t(INT24_MIN),
	                          _val.get(),
	                          int32_t(INT24_MAX)
	                          ) << 8
	                 );
}

audio::int24_32_t::int24_32_t(const audio::int24_24_t& _val) {
	m_data = _val.get();
}

audio::int24_32_t::int24_32_t(const audio::int24_32_t& _val) {
	m_data = _val.m_data;
}

audio::int24_32_t::int24_32_t(const audio::int32_32_t& _val) {
	m_data = int32_t(_val.get() >> 8);
}

audio::int24_32_t::int24_32_t(const audio::int32_64_t& _val) {
	m_data = int32_t(std::avg(int64_t(INT40_MIN),
	                          _val.get(),
	                          int64_t(INT40_MAX)
	                          ) >> 8
	                 );
}

audio::int24_32_t::int24_32_t(const audio::int64_64_t& _val) {
	m_data = int32_t(_val.get() >> 40);
}

audio::int24_32_t::int24_32_t(const audio::float_t& _val) {
	m_data = int32_t(std::avg(float(INT8_MIN),
	                          _val.get(),
	                          float(INT8_MAX)
	                          ) * float(INT24_MAX)
	                 );
}

audio::int24_32_t::int24_32_t(const audio::double_t& _val) {
	m_data = int32_t(std::avg(-1.0,
	                          _val.get(),
	                          1.0
	                          ) * double(INT24_MAX)
	                 );
}

audio::int24_32_t::int24_32_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int24_32_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (24-_flotingPointPosition);
	m_data = std::avg(int64_t(INT32_MIN), val, int64_t(INT32_MAX));
}


std::ostream& audio::operator <<(std::ostream& _os, const audio::int24_32_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << "8:24=";
	_os << etk::to_string(double(_obj.get())/double(INT24_MAX));
	_os << "]";
	return _os;
}
