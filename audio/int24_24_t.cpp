/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int24_24_t.h>



audio::int24_24_t::int24_24_t(const audio::int8_8_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 8);
}

audio::int24_24_t::int24_24_t(const audio::int8_16_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 8);
}

audio::int24_24_t::int24_24_t(const audio::int16_16_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 16);
}
audio::int24_24_t::int24_24_t(const audio::int16_32_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 16);
}

audio::int24_24_t::int24_24_t(const audio::int24_24_t& _val) {
	m_data[0] = _val.m_data[0];
	m_data[1] = _val.m_data[1];
	m_data[2] = _val.m_data[2];
}

audio::int24_24_t::int24_24_t(const audio::int24_32_t& _val) {
	set(int32_t(_val.get()), 24);
}

audio::int24_24_t::int24_24_t(const audio::int32_32_t& _val) {
	int32_t val = _val.get() >> 8;
	set(val, 24);
}

audio::int24_24_t::int24_24_t(const audio::int32_64_t& _val) {
	int64_t val = _val.get() >> 8;
	set(int32_t(val), 24);
}

audio::int24_24_t::int24_24_t(const audio::int64_64_t& _val) {
	int64_t val = _val.get() >> (32+8);
	set(int32_t(val), 24);
}

audio::int24_24_t::int24_24_t(const audio::float_t& _val) {
	float val = _val.get() * float(INT24_MAX);
	set(int32_t(val), 24);
}

audio::int24_24_t::int24_24_t(const audio::double_t& _val) {
	double val = _val.get() * double(INT24_MAX);
	set(int32_t(val), 24);
}

// set operator
audio::int24_24_t::int24_24_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int24_24_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (24-_flotingPointPosition);
	val = std::avg(int64_t(INT24_MIN), val, int64_t(INT24_MAX));
	m_data[0] = (val & 0x000000ff);
	m_data[1] = (val & 0x0000ff00) >> 8;
	m_data[2] = (val & 0x00ff0000) >> 16;
}

void audio::int24_24_t::set(int32_t _value) {
	m_data[0] = (_value & 0x000000ff);
	m_data[1] = (_value & 0x0000ff00) >> 8;
	m_data[2] = (_value & 0x00ff0000) >> 16;
}

int32_t audio::int24_24_t::get() const {
	int32_t val = 0;
	val += int32_t(m_data[0]);
	val += int32_t(m_data[1]) << 8;
	val += (int32_t(m_data[2]) << 24) >> 8;
	return val;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int24_24_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":0.24=";
	_os << etk::to_string(double(_obj.get())/double(INT24_MAX));
	_os << "]";
	return _os;
}
