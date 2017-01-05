/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/int8_16_t.hpp>


audio::int8_16_t::int8_16_t(const audio::int8_8_t& _val) {
	m_data = int16_t(_val.get())<<1;
}

audio::int8_16_t::int8_16_t(const audio::int8_16_t& _val) {
	m_data = _val.m_data;
}

audio::int8_16_t::int8_16_t(const audio::int16_16_t& _val) {
	m_data = int16_t(_val.get() >> 7);
}

audio::int8_16_t::int8_16_t(const audio::int16_32_t& _val) {
	m_data = int16_t(std::avg(int32_t(INT24_MIN),
	                          _val.get(),
	                          int32_t(INT24_MAX)
	                          ) >> 8
	                 );
}

audio::int8_16_t::int8_16_t(const audio::int24_24_t& _val) {
	m_data = int16_t(_val.get() >> 15);
}

audio::int8_16_t::int8_16_t(const audio::int24_32_t& _val) {
	m_data = int16_t(_val.get() >> 16);
}

audio::int8_16_t::int8_16_t(const audio::int32_32_t& _val) {
	m_data = int16_t(_val.get() >> 23);
}

audio::int8_16_t::int8_16_t(const audio::int32_64_t& _val) {
	m_data = int16_t(std::avg(int64_t(INT40_MIN),
	                          _val.get(),
	                          int64_t(INT40_MAX)
	                          ) >> 24
	                 );
}

audio::int8_16_t::int8_16_t(const audio::int64_64_t& _val) {
	m_data = int16_t(_val.get() >> 55);
}

audio::int8_16_t::int8_16_t(const audio::float_t& _val) {
	m_data = int16_t(std::avg(float(INT8_MIN),
	                          _val.get(),
	                          float(INT8_MAX)
	                          ) * (float(INT8_MAX) * 2.0f + 1.0f)
	                 );
}

audio::int8_16_t::int8_16_t(const audio::double_t& _val) {
	m_data = int16_t(std::avg(double(INT8_MIN),
	                          _val.get(),
	                          double(INT8_MAX)
	                          ) * (double(INT8_MAX) * 2.0 + 1.0)
	                 );
}

audio::int8_16_t::int8_16_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int8_16_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (8-_flotingPointPosition);
	m_data = std::avg(int64_t(INT16_MIN), val, int64_t(INT16_MAX));
}

void audio::int8_16_t::set(int16_t _value) {
	m_data = _value;
}

int16_t audio::int8_16_t::get() const {
	return m_data;
}

float audio::int8_16_t::getFloat() const {
	return getDouble();
}

double audio::int8_16_t::getDouble() const {
	return double(m_data)/double(INT8_MAX)*0.5;
}

const audio::int8_16_t& audio::int8_16_t::operator= (const audio::int8_16_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::int8_16_t::operator== (const audio::int8_16_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::int8_16_t::operator!= (const audio::int8_16_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::int8_16_t::operator< (const audio::int8_16_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::int8_16_t::operator<= (const audio::int8_16_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::int8_16_t::operator> (const audio::int8_16_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::int8_16_t::operator>= (const audio::int8_16_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::int8_16_t& audio::int8_16_t::operator+= (const audio::int8_16_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::int8_16_t audio::int8_16_t::operator+ (const audio::int8_16_t& _obj) const {
	audio::int8_16_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::int8_16_t& audio::int8_16_t::operator-= (const audio::int8_16_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::int8_16_t audio::int8_16_t::operator- (const audio::int8_16_t& _obj) const {
	audio::int8_16_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::int8_16_t& audio::int8_16_t::operator*= (const audio::int8_16_t& _obj) {
	int16_t tmp = int16_t(m_data) * int16_t(_obj.m_data);
	m_data = int8_t(tmp >> 8);
	return *this;
}

audio::int8_16_t audio::int8_16_t::operator* (const audio::int8_16_t& _obj) const {
	audio::int8_16_t tmpp(m_data);
	tmpp *= _obj;
	return tmpp;
}

const audio::int8_16_t& audio::int8_16_t::operator/= (const audio::int8_16_t& _obj) {
	int32_t tmp = (int32_t(m_data) << 8) / int32_t(_obj.m_data);
	m_data = int16_t(tmp);
	return *this;
}

audio::int8_16_t audio::int8_16_t::operator/ (const audio::int8_16_t& _obj) const{
	audio::int8_16_t tmpp(m_data);
	tmpp /= _obj;
	return tmpp;
}

audio::int8_16_t& audio::int8_16_t::operator++() {
	m_data += (1<<8);
	return *this;
}

audio::int8_16_t audio::int8_16_t::operator++(int _unused) {
	audio::int8_16_t result(m_data);
	m_data += (1<<8);
	return result;
}

audio::int8_16_t& audio::int8_16_t::operator--() {
	m_data -= (1<<8);
	return *this;
}

audio::int8_16_t audio::int8_16_t::operator--(int _unused) {
	audio::int8_16_t result(m_data);
	m_data -= (1<<8);
	return result;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int8_16_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":7.8=";
	_os << etk::to_string(double(_obj.get())/double(INT8_MAX)*0.5);
	_os << "]";
	return _os;
}
