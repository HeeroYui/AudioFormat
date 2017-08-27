/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/float_t.hpp>


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

void audio::float_t::set(float _value) {
	m_data = _value;
}

float audio::float_t::get() const {
	return m_data;
}

float audio::float_t::getFloat() const {
	return m_data;
}

double audio::float_t::getDouble() const {
	return m_data;
}

const audio::float_t& audio::float_t::operator= (const audio::float_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::float_t::operator== (const audio::float_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::float_t::operator!= (const audio::float_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::float_t::operator< (const audio::float_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::float_t::operator<= (const audio::float_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::float_t::operator> (const audio::float_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::float_t::operator>= (const audio::float_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::float_t& audio::float_t::operator+= (const audio::float_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::float_t audio::float_t::operator+ (const audio::float_t& _obj) const {
	audio::float_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::float_t& audio::float_t::operator-= (const audio::float_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::float_t audio::float_t::operator- (const audio::float_t& _obj) const {
	audio::float_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::float_t& audio::float_t::operator*= (const audio::float_t& _obj) {
	m_data *= _obj.m_data;
	return *this;
}

audio::float_t audio::float_t::operator* (const audio::float_t& _obj) const {
	audio::float_t tmpp(m_data);
	tmpp.m_data *= _obj.m_data;
	return tmpp;
}

const audio::float_t& audio::float_t::operator/= (const audio::float_t& _obj) {
	m_data /= _obj.m_data;
	return *this;
}

audio::float_t audio::float_t::operator/ (const audio::float_t& _obj) const{
	audio::float_t tmpp(m_data);
	tmpp.m_data /= _obj.m_data;
	return tmpp;
}

audio::float_t& audio::float_t::operator++() {
	m_data += 1.0f;
	return *this;
}

audio::float_t audio::float_t::operator++(int _unused) {
	audio::float_t result(m_data);
	m_data += 1.0f;
	return result;
}

audio::float_t& audio::float_t::operator--() {
	m_data -= 1.0f;
	return *this;
}

audio::float_t audio::float_t::operator--(int _unused) {
	audio::float_t result(m_data);
	m_data -= 1.0f;
	return result;
}

etk::Stream& audio::operator <<(etk::Stream& _os, const audio::float_t& _obj) {
	_os << "[" << etk::toString(_obj.get()) << ":f]";
	return _os;
}

