/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/double_t.h>


audio::double_t::double_t(const audio::int8_8_t& _val) {
	m_data = double(_val.get()) / (double(INT8_MAX) + 1.0);
}

audio::double_t::double_t(const audio::int8_16_t& _val) {
	m_data = double(_val.get()) / (double(INT8_MAX) * 2.0 + 1.0);
}

audio::double_t::double_t(const audio::int16_16_t& _val) {
	m_data = double(_val.get()) / (double(INT16_MAX) + 1.0);
}

audio::double_t::double_t(const audio::int16_32_t& _val) {
	m_data = double(_val.get()) / (double(INT16_MAX) * 2.0 + 1.0);
}

audio::double_t::double_t(const audio::int24_24_t& _val) {
	m_data = double(_val.get()) / (double(INT24_MAX) + 1.0);
}

audio::double_t::double_t(const audio::int24_32_t& _val) {
	m_data = double(_val.get()) / (double(INT24_MAX) * 2.0 + 1.0);
}

audio::double_t::double_t(const audio::int32_32_t& _val) {
	m_data = double(_val.get()) / (double(INT32_MAX) + 1.0);
}

audio::double_t::double_t(const audio::int32_64_t& _val) {
	m_data = double(_val.get()) / (double(INT32_MAX) * 2.0 + 1.0);
}

audio::double_t::double_t(const audio::int64_64_t& _val) {
	m_data = double(_val.get()) / (double(INT64_MAX) + 1.0);
}

audio::double_t::double_t(const audio::float_t& _val) {
	m_data = double(_val.get());
}

audio::double_t::double_t(const audio::double_t& _val) {
	m_data = _val.m_data;
}

audio::double_t::double_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::double_t::set(int64_t _value, int32_t _flotingPointPosition) {
	m_data = double(_value << (31-_flotingPointPosition)) / (double(INT32_MAX)+1.0);
}


std::ostream& audio::operator <<(std::ostream& _os, const audio::double_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":d]";
	return _os;
}
