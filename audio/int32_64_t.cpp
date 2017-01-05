/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/int32_64_t.hpp>

audio::int32_64_t::int32_64_t(const audio::int8_8_t& _val) {
	m_data = int64_t(_val.get()) << 25;
}

audio::int32_64_t::int32_64_t(const audio::int8_16_t& _val) {
	m_data = int64_t(_val.get()) << 24;
}

audio::int32_64_t::int32_64_t(const audio::int16_16_t& _val) {
	m_data = int64_t(_val.get()) << 17;
}

audio::int32_64_t::int32_64_t(const audio::int16_32_t& _val) {
	m_data = int64_t(_val.get()) << 16;
}

audio::int32_64_t::int32_64_t(const audio::int24_24_t& _val) {
	m_data = int64_t(_val.get()) << 9;
}

audio::int32_64_t::int32_64_t(const audio::int24_32_t& _val) {
	m_data = int64_t(_val.get() << 8);
}

audio::int32_64_t::int32_64_t(const audio::int32_32_t& _val) {
	m_data = int64_t(_val.get()) << 1;
}

audio::int32_64_t::int32_64_t(const audio::int32_64_t& _val) {
	m_data = _val.m_data;
}

audio::int32_64_t::int32_64_t(const audio::int64_64_t& _val) {
	m_data = int64_t(_val.get() >> 31);
}

audio::int32_64_t::int32_64_t(const audio::float_t& _val) {
	m_data = int64_t(std::avg(float(INT32_MIN),
	                          _val.get(),
	                          float(INT32_MAX)
	                          ) * (float(INT32_MAX) * 2.0f + 1.0f)
	                 );
}

audio::int32_64_t::int32_64_t(const audio::double_t& _val) {
	m_data = int64_t(std::avg(double(INT32_MIN),
	                          _val.get(),
	                          double(INT32_MAX)
	                          ) * (double(INT32_MAX) * 2.0 + 1.0)
	                 );
}

audio::int32_64_t::int32_64_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int32_64_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (32-_flotingPointPosition);
	m_data = std::avg(int64_t(INT64_MIN), val, int64_t(INT64_MAX));
}

void audio::int32_64_t::set(int64_t _value) {
	m_data = _value;
}

int64_t audio::int32_64_t::get() const {
	return m_data;
}

float audio::int32_64_t::getFloat() const {
	return getDouble();
}

double audio::int32_64_t::getDouble() const {
	return double(m_data)/double(INT32_MAX)*0.5;
}

const audio::int32_64_t& audio::int32_64_t::operator= (const audio::int32_64_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::int32_64_t::operator== (const audio::int32_64_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::int32_64_t::operator!= (const audio::int32_64_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::int32_64_t::operator< (const audio::int32_64_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::int32_64_t::operator<= (const audio::int32_64_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::int32_64_t::operator> (const audio::int32_64_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::int32_64_t::operator>= (const audio::int32_64_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::int32_64_t& audio::int32_64_t::operator+= (const audio::int32_64_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::int32_64_t audio::int32_64_t::operator+ (const audio::int32_64_t& _obj) const {
	audio::int32_64_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::int32_64_t& audio::int32_64_t::operator-= (const audio::int32_64_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::int32_64_t audio::int32_64_t::operator- (const audio::int32_64_t& _obj) const {
	audio::int32_64_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::int32_64_t& audio::int32_64_t::operator*= (const audio::int32_64_t& _obj) {
	int64_t tmp = m_data * _obj.m_data;
	m_data = int64_t(tmp >> 32);
	return *this;
}

audio::int32_64_t audio::int32_64_t::operator* (const audio::int32_64_t& _obj) const {
	audio::int32_64_t tmpp(m_data);
	tmpp *= _obj;
	return tmpp;
}

const audio::int32_64_t& audio::int32_64_t::operator/= (const audio::int32_64_t& _obj) {
	int64_t tmp = (int64_t(m_data) << 16) / int64_t(_obj.m_data);
	m_data = int64_t(tmp)<<16;
	return *this;
}

audio::int32_64_t audio::int32_64_t::operator/ (const audio::int32_64_t& _obj) const{
	audio::int32_64_t tmpp(m_data);
	tmpp /= _obj;
	return tmpp;
}

audio::int32_64_t& audio::int32_64_t::operator++() {
	m_data += (1LL<<32);
	return *this;
}

audio::int32_64_t audio::int32_64_t::operator++(int _unused) {
	audio::int32_64_t result(m_data);
	m_data += (1LL<<32);
	return result;
}

audio::int32_64_t& audio::int32_64_t::operator--() {
	m_data -= (1LL<<32);
	return *this;
}

audio::int32_64_t audio::int32_64_t::operator--(int _unused) {
	audio::int32_64_t result(m_data);
	m_data -= (1LL<<32);
	return result;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int32_64_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":31.32=";
	_os << etk::to_string(double(_obj.get())/double(INT32_MAX)*0.5);
	_os << "]";
	return _os;
}
