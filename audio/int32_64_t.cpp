/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int32_64_t.h>


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



audio::int32_64_t::int32_64_t(const audio::int8_8_t& _val) {
	m_data = int64_t(_val.get()) << 24;
}

audio::int32_64_t::int32_64_t(const audio::int8_16_t& _val) {
	m_data = int64_t(_val.get()) << 24;
}

audio::int32_64_t::int32_64_t(const audio::int16_16_t& _val) {
	m_data = int64_t(_val.get()) << 16;
}

audio::int32_64_t::int32_64_t(const audio::int16_32_t& _val) {
	m_data = int64_t(_val.get()) << 16;
}

audio::int32_64_t::int32_64_t(const audio::int24_24_t& _val) {
	m_data = int64_t(_val.get()) << 8;
}

audio::int32_64_t::int32_64_t(const audio::int24_32_t& _val) {
	m_data = int64_t(_val.get() << 8);
}

audio::int32_64_t::int32_64_t(const audio::int32_32_t& _val) {
	m_data = int64_t(_val.get());
}

audio::int32_64_t::int32_64_t(const audio::int32_64_t& _val) {
	m_data = _val.m_data;
}

audio::int32_64_t::int32_64_t(const audio::int64_64_t& _val) {
	m_data = int64_t(_val.get() >> 32);
}

audio::int32_64_t::int32_64_t(const audio::float_t& _val) {
	m_data = int64_t(std::avg(float(INT32_MIN),
	                          _val.get(),
	                          float(INT32_MAX)
	                          ) * float(INT32_MAX) * 2.0f
	                 );
}

audio::int32_64_t::int32_64_t(const audio::double_t& _val) {
	m_data = int64_t(std::avg(double(INT32_MIN),
	                          _val.get(),
	                          double(INT32_MIN)
	                          ) * double(INT32_MAX) * 2.0
	                 );
}

audio::int32_64_t::int32_64_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int32_64_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (32-_flotingPointPosition);
	m_data = std::avg(int64_t(INT64_MIN), val, int64_t(INT64_MAX));
}


std::ostream& audio::operator <<(std::ostream& _os, const audio::int32_64_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":31.32=";
	_os << etk::to_string(double(_obj.get())/double(INT32_MAX)*0.5);
	_os << "]";
	return _os;
}
