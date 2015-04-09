/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/int24_24_t.h>
#include <audio/debug.h>



audio::int24_24_t::int24_24_t(const audio::int8_8_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 7);
}

audio::int24_24_t::int24_24_t(const audio::int8_16_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 8);
}

audio::int24_24_t::int24_24_t(const audio::int16_16_t& _val) {
	int32_t val = _val.get();
	set(int32_t(val), 15);
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
	set(_val.get(), 24);
}

audio::int24_24_t::int24_24_t(const audio::int32_32_t& _val) {
	int64_t val = _val.get() >> 8;
	set(val, 23);
}

audio::int24_24_t::int24_24_t(const audio::int32_64_t& _val) {
	int64_t val = _val.get() >> 8;
	set(int32_t(val), 24);
}

audio::int24_24_t::int24_24_t(const audio::int64_64_t& _val) {
	int64_t val = _val.get() >> (32+8);
	set(int32_t(val), 23);
}

audio::int24_24_t::int24_24_t(const audio::float_t& _val) {
	float val = _val.get() * (float(INT24_MAX)+1);
	set(int32_t(val), 23);
}

audio::int24_24_t::int24_24_t(const audio::double_t& _val) {
	double val = _val.get() * (double(INT24_MAX)+1);
	set(int32_t(val), 23);
}

// set operator
audio::int24_24_t::int24_24_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int24_24_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val;
	if (_flotingPointPosition > 23) {
		val = _value >> (-23+_flotingPointPosition);
	} else {
		val = _value << (23-_flotingPointPosition);
	}
	//AUDIO_INFO(" _value=" << _value << " _flotingPointPosition=" << _flotingPointPosition << " val=" << val);
	val = std::avg(int64_t(INT24_MIN), val, int64_t(INT24_MAX));
	m_data[0] = (val & 0x00000000000000ffLL);
	m_data[1] = (val & 0x000000000000ff00LL) >> 8;
	m_data[2] = (val & 0x0000000000ff0000LL) >> 16;
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
	_os << "[" << etk::to_string(_obj.get()) << ":0.23=";
	_os << etk::to_string(double(_obj.get())/double(INT24_MAX));
	_os << "]";
	return _os;
}
