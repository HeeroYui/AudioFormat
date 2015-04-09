/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/float_t.h>


audio::float_t::float_t(const audio::int8_8_t& _val) {
	m_data = float(_val.get()) / (float(INT8_MAX) + 1.0f);
}

audio::float_t::float_t(const audio::int8_16_t& _val) {
	m_data = float(_val.get()) / (float(INT8_MAX) * 2.0f + 1.0f);
}

audio::float_t::float_t(const audio::int16_16_t& _val) {
	m_data = float(_val.get()) / (float(INT16_MAX) + 1.0f);
}

audio::float_t::float_t(const audio::int16_32_t& _val) {
	m_data = float(_val.get()) / (float(INT16_MAX) * 2.0f + 1.0f);
}

audio::float_t::float_t(const audio::int24_24_t& _val) {
	m_data = float(_val.get()) / (float(INT24_MAX) + 1.0f);
}

audio::float_t::float_t(const audio::int24_32_t& _val) {
	m_data = float(_val.get()) / (float(INT24_MAX) * 2.0f + 1.0f);
}

audio::float_t::float_t(const audio::int32_32_t& _val) {
	m_data = float(_val.get()) / (float(INT32_MAX) + 1.0f);
}

audio::float_t::float_t(const audio::int32_64_t& _val) {
	m_data = float(_val.get()) / (float(INT32_MAX) * 2.0f + 1.0f);
}

audio::float_t::float_t(const audio::int64_64_t& _val) {
	m_data = float(_val.get()) / (float(INT64_MAX) + 1.0f);
}

audio::float_t::float_t(const audio::float_t& _val) {
	m_data = _val.m_data;
}

audio::float_t::float_t(const audio::double_t& _val) {
	m_data = float(_val.get());
}

audio::float_t::float_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::float_t::set(int64_t _value, int32_t _flotingPointPosition) {
	m_data = float(_value << (31-_flotingPointPosition)) / (float(INT32_MAX)+1.0f);
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::float_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":f]";
	return _os;
}

