/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/double_t.hpp>


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


void audio::double_t::set(double _value) {
	m_data = _value;
}

double audio::double_t::get() const {
	return m_data;
}

float audio::double_t::getFloat() const {
	return m_data;
}

double audio::double_t::getDouble() const {
	return m_data;
}

const audio::double_t& audio::double_t::operator= (const audio::double_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::double_t::operator== (const audio::double_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::double_t::operator!= (const audio::double_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::double_t::operator< (const audio::double_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::double_t::operator<= (const audio::double_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::double_t::operator> (const audio::double_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::double_t::operator>= (const audio::double_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::double_t& audio::double_t::operator+= (const audio::double_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::double_t audio::double_t::operator+ (const audio::double_t& _obj) const {
	audio::double_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::double_t& audio::double_t::operator-= (const audio::double_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::double_t audio::double_t::operator- (const audio::double_t& _obj) const {
	audio::double_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::double_t& audio::double_t::operator*= (const audio::double_t& _obj) {
	m_data *= _obj.m_data;
	return *this;
}

audio::double_t audio::double_t::operator* (const audio::double_t& _obj) const {
	audio::double_t tmpp(m_data);
	tmpp.m_data *= _obj.m_data;
	return tmpp;
}

const audio::double_t& audio::double_t::operator/= (const audio::double_t& _obj) {
	m_data /= _obj.m_data;
	return *this;
}

audio::double_t audio::double_t::operator/ (const audio::double_t& _obj) const{
	audio::double_t tmpp(m_data);
	tmpp.m_data /= _obj.m_data;
	return tmpp;
}

audio::double_t& audio::double_t::operator++() {
	m_data += 1.0f;
	return *this;
}

audio::double_t audio::double_t::operator++(int _unused) {
	audio::double_t result(m_data);
	m_data += 1.0f;
	return result;
}

audio::double_t& audio::double_t::operator--() {
	m_data -= 1.0f;
	return *this;
}

audio::double_t audio::double_t::operator--(int _unused) {
	audio::double_t result(m_data);
	m_data -= 1.0f;
	return result;
}

etk::Stream& audio::operator <<(etk::Stream& _os, const audio::double_t& _obj) {
	_os << "[" << etk::toString(_obj.get()) << ":d]";
	return _os;
}
