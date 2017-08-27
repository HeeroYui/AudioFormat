/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/int16_32_t.hpp>


audio::int16_32_t::int16_32_t(const audio::int8_8_t& _val) {
	m_data = int32_t(_val.get()) << 9;
}

audio::int16_32_t::int16_32_t(const audio::int8_16_t& _val) {
	m_data = int32_t(_val.get()) << 8;
}

audio::int16_32_t::int16_32_t(const audio::int16_16_t& _val) {
	m_data = _val.get() << 1;
}

audio::int16_32_t::int16_32_t(const audio::int16_32_t& _val) {
	m_data = _val.m_data;
}

audio::int16_32_t::int16_32_t(const audio::int24_24_t& _val) {
	m_data = int32_t(_val.get() >> 7);
}

audio::int16_32_t::int16_32_t(const audio::int24_32_t& _val) {
	m_data = int32_t(_val.get() >> 8);
}

audio::int16_32_t::int16_32_t(const audio::int32_32_t& _val) {
	m_data = int32_t(_val.get() >> 15);
}

audio::int16_32_t::int16_32_t(const audio::int32_64_t& _val) {
	m_data = int32_t(etk::avg(int64_t(INT56_MIN),
	                          _val.get(),
	                          int64_t(INT56_MAX)
	                          ) >> 16
	                 );
}

audio::int16_32_t::int16_32_t(const audio::int64_64_t& _val) {
	m_data = int32_t(_val.get() >> 47);
}

audio::int16_32_t::int16_32_t(const audio::float_t& _val) {
	m_data = int32_t(etk::avg(float(INT16_MIN),
	                          _val.get(),
	                          float(INT16_MAX)
	                          ) * (float(INT16_MAX) * 2.0f+1.0f)
	                 );
}

audio::int16_32_t::int16_32_t(const audio::double_t& _val) {
	m_data = int32_t(etk::avg(double(INT16_MIN),
	                          _val.get(),
	                          double(INT16_MAX)
	                          ) * (double(INT16_MAX) * 2.0+1.0)
	                 );
}

audio::int16_32_t::int16_32_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int16_32_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (16-_flotingPointPosition);
	m_data = etk::avg(int64_t(INT32_MIN), val, int64_t(INT32_MAX));
}

void audio::int16_32_t::set(int32_t _value) {
	m_data = _value;
}

int32_t audio::int16_32_t::get() const {
	return m_data;
}

float audio::int16_32_t::getFloat() const {
	return getDouble();
}

double audio::int16_32_t::getDouble() const {
	return double(m_data)/double(INT16_MAX)*0.5;
}

const audio::int16_32_t& audio::int16_32_t::operator= (const audio::int16_32_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::int16_32_t::operator== (const audio::int16_32_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::int16_32_t::operator!= (const audio::int16_32_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::int16_32_t::operator< (const audio::int16_32_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::int16_32_t::operator<= (const audio::int16_32_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::int16_32_t::operator> (const audio::int16_32_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::int16_32_t::operator>= (const audio::int16_32_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::int16_32_t& audio::int16_32_t::operator+= (const audio::int16_32_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::int16_32_t audio::int16_32_t::operator+ (const audio::int16_32_t& _obj) const {
	audio::int16_32_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::int16_32_t& audio::int16_32_t::operator-= (const audio::int16_32_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::int16_32_t audio::int16_32_t::operator- (const audio::int16_32_t& _obj) const {
	audio::int16_32_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::int16_32_t& audio::int16_32_t::operator*= (const audio::int16_32_t& _obj) {
	int64_t tmp = int64_t(m_data) * int64_t(_obj.m_data) + (1<<15);
	m_data = int32_t(tmp >> 16);
	return *this;
}

audio::int16_32_t audio::int16_32_t::operator* (const audio::int16_32_t& _obj) const {
	audio::int16_32_t tmpp(m_data);
	tmpp *= _obj;
	return tmpp;
}

const audio::int16_32_t& audio::int16_32_t::operator/= (const audio::int16_32_t& _obj) {
	int64_t tmp = (int64_t(m_data) << 16) / int64_t(_obj.m_data);
	m_data = int32_t(tmp);
	return *this;
}

audio::int16_32_t audio::int16_32_t::operator/ (const audio::int16_32_t& _obj) const{
	audio::int16_32_t tmpp(m_data);
	tmpp /= _obj;
	return tmpp;
}

audio::int16_32_t& audio::int16_32_t::operator++() {
	m_data += (1<<16);
	return *this;
}

audio::int16_32_t audio::int16_32_t::operator++(int _unused) {
	audio::int16_32_t result(m_data);
	m_data += (1<<16);
	return result;
}

audio::int16_32_t& audio::int16_32_t::operator--() {
	m_data -= (1<<16);
	return *this;
}

audio::int16_32_t audio::int16_32_t::operator--(int _unused) {
	audio::int16_32_t result(m_data);
	m_data -= (1<<16);
	return result;
}

etk::Stream& audio::operator <<(etk::Stream& _os, const audio::int16_32_t& _obj) {
	_os << "[" << etk::toString(_obj.get()) << ":7.16=";
	_os << etk::toString(double(_obj.get())/double(INT16_MAX)*0.5);
	_os << "]";
	return _os;
}
