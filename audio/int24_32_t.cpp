/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/int24_32_t.hpp>


audio::int24_32_t::int24_32_t(const audio::int8_8_t& _val) {
	m_data = int32_t(_val.get()) << 17;
}

audio::int24_32_t::int24_32_t(const audio::int8_16_t& _val) {
	m_data = int32_t(_val.get()) << 16;
}

audio::int24_32_t::int24_32_t(const audio::int16_16_t& _val) {
	m_data = _val.get() << 9;
}

audio::int24_32_t::int24_32_t(const audio::int16_32_t& _val) {
	m_data = int32_t(std::avg(int32_t(INT24_MIN),
	                          _val.get(),
	                          int32_t(INT24_MAX)
	                          ) << 8
	                 );
}

audio::int24_32_t::int24_32_t(const audio::int24_24_t& _val) {
	m_data = _val.get() << 1;
}

audio::int24_32_t::int24_32_t(const audio::int24_32_t& _val) {
	m_data = _val.m_data;
}

audio::int24_32_t::int24_32_t(const audio::int32_32_t& _val) {
	m_data = int32_t(_val.get() >> 7);
}

audio::int24_32_t::int24_32_t(const audio::int32_64_t& _val) {
	m_data = int32_t(std::avg(int64_t(INT40_MIN),
	                          _val.get(),
	                          int64_t(INT40_MAX)
	                          ) >> 8
	                 );
}

audio::int24_32_t::int24_32_t(const audio::int64_64_t& _val) {
	m_data = int32_t(_val.get() >> 39);
}

audio::int24_32_t::int24_32_t(const audio::float_t& _val) {
	m_data = int32_t(std::avg(float(INT8_MIN),
	                          _val.get(),
	                          float(INT8_MAX)
	                          ) * (float(INT24_MAX) * 2.0f + 1.0f)
	                 );
}

audio::int24_32_t::int24_32_t(const audio::double_t& _val) {
	m_data = int32_t(std::avg(-1.0,
	                          _val.get(),
	                          1.0
	                          ) * (double(INT24_MAX) * 2.0 + 1.0)
	                 );
}

audio::int24_32_t::int24_32_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int24_32_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (24-_flotingPointPosition);
	m_data = std::avg(int64_t(INT32_MIN), val, int64_t(INT32_MAX));
}

void audio::int24_32_t::set(int32_t _value) {
	m_data = _value;
}

int32_t audio::int24_32_t::get() const {
	return m_data;
}

float audio::int24_32_t::getFloat() const {
	return getDouble();
}

double audio::int24_32_t::getDouble() const {
	return double(m_data)/double(INT24_MAX)*0.5;
}

const audio::int24_32_t& audio::int24_32_t::operator= (const audio::int24_32_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::int24_32_t::operator== (const audio::int24_32_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::int24_32_t::operator!= (const audio::int24_32_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::int24_32_t::operator< (const audio::int24_32_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::int24_32_t::operator<= (const audio::int24_32_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::int24_32_t::operator> (const audio::int24_32_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::int24_32_t::operator>= (const audio::int24_32_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::int24_32_t& audio::int24_32_t::operator+= (const audio::int24_32_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::int24_32_t audio::int24_32_t::operator+ (const audio::int24_32_t& _obj) const {
	audio::int24_32_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::int24_32_t& audio::int24_32_t::operator-= (const audio::int24_32_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::int24_32_t audio::int24_32_t::operator- (const audio::int24_32_t& _obj) const {
	audio::int24_32_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::int24_32_t& audio::int24_32_t::operator*= (const audio::int24_32_t& _obj) {
	int64_t tmp = int64_t(m_data) * int64_t(_obj.m_data);
	m_data = int32_t(tmp >> 24);
	return *this;
}

audio::int24_32_t audio::int24_32_t::operator* (const audio::int24_32_t& _obj) const {
	audio::int24_32_t tmpp(m_data);
	tmpp *= _obj;
	return tmpp;
}

const audio::int24_32_t& audio::int24_32_t::operator/= (const audio::int24_32_t& _obj) {
	int64_t tmp = (int64_t(m_data) << 24) / int64_t(_obj.m_data);
	m_data = int32_t(tmp);
	return *this;
}

audio::int24_32_t audio::int24_32_t::operator/ (const audio::int24_32_t& _obj) const{
	audio::int24_32_t tmpp(m_data);
	tmpp /= _obj;
	return tmpp;
}

audio::int24_32_t& audio::int24_32_t::operator++() {
	m_data += (1<<24);
	return *this;
}

audio::int24_32_t audio::int24_32_t::operator++(int _unused) {
	audio::int24_32_t result(m_data);
	m_data += (1<<24);
	return result;
}

audio::int24_32_t& audio::int24_32_t::operator--() {
	m_data -= (1<<24);
	return *this;
}

audio::int24_32_t audio::int24_32_t::operator--(int _unused) {
	audio::int24_32_t result(m_data);
	m_data -= (1<<24);
	return result;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int24_32_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":7.24=";
	_os << etk::to_string(double(_obj.get())/double(INT24_MAX)*0.5);
	_os << "]";
	return _os;
}
