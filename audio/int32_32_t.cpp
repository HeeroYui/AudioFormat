/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/int32_32_t.h>

audio::int32_32_t::int32_32_t(const audio::int8_8_t& _val) {
	m_data = int32_t(_val.get()) << 24;
}

audio::int32_32_t::int32_32_t(const audio::int8_16_t& _val) {
	m_data = int32_t(std::avg(int32_t(INT8_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT8_MAX)
	                          ) << 24
	                 );
}

audio::int32_32_t::int32_32_t(const audio::int16_16_t& _val) {
	m_data = int32_t(_val.get()) << 16;
}

audio::int32_32_t::int32_32_t(const audio::int16_32_t& _val) {
	m_data = int32_t(std::avg(int32_t(INT16_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT16_MAX)
	                          ) << 16
	                 );
}

audio::int32_32_t::int32_32_t(const audio::int24_24_t& _val) {
	m_data = int32_t(_val.get() << 8);
}

audio::int32_32_t::int32_32_t(const audio::int24_32_t& _val) {
	m_data = int32_t(std::avg(int32_t(INT24_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT24_MAX)
	                          ) << 8
	                 );
}

audio::int32_32_t::int32_32_t(const audio::int32_32_t& _val) {
	m_data = _val.m_data;
}

audio::int32_32_t::int32_32_t(const audio::int32_64_t& _val) {
	m_data = int32_t(std::avg(int64_t(INT32_MIN),
	                          _val.get() >> 1,
	                          int64_t(INT32_MAX)
	                          )
	                 );
}

audio::int32_32_t::int32_32_t(const audio::int64_64_t& _val) {
	m_data = int32_t(_val.get() >> 32);
}

audio::int32_32_t::int32_32_t(const audio::float_t& _val) {
	m_data = int32_t(std::avg(-1.0f,
	                          _val.get(),
	                          1.0f
	                          ) * float(INT32_MAX)
	                 );
}

audio::int32_32_t::int32_32_t(const audio::double_t& _val) {
	m_data = int32_t(std::avg(-1.0,
	                          _val.get(),
	                          1.0
	                          ) * double(INT32_MAX)
	                 );
}

audio::int32_32_t::int32_32_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int32_32_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (31-_flotingPointPosition);
	m_data = std::avg(int64_t(INT32_MIN), val, int64_t(INT32_MAX));
}

void audio::int32_32_t::set(int32_t _value) {
	m_data = _value;
}

int32_t audio::int32_32_t::get() const {
	return m_data;
}

float audio::int32_32_t::getFloat() const {
	return getDouble();
}

double audio::int32_32_t::getDouble() const {
	return double(m_data)/double(INT16_MAX);
}

const audio::int32_32_t& audio::int32_32_t::operator= (const audio::int32_32_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::int32_32_t::operator== (const audio::int32_32_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::int32_32_t::operator!= (const audio::int32_32_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::int32_32_t::operator< (const audio::int32_32_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::int32_32_t::operator<= (const audio::int32_32_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::int32_32_t::operator> (const audio::int32_32_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::int32_32_t::operator>= (const audio::int32_32_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::int32_32_t& audio::int32_32_t::operator+= (const audio::int32_32_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::int32_32_t audio::int32_32_t::operator+ (const audio::int32_32_t& _obj) const {
	audio::int32_32_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::int32_32_t& audio::int32_32_t::operator-= (const audio::int32_32_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::int32_32_t audio::int32_32_t::operator- (const audio::int32_32_t& _obj) const {
	audio::int32_32_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::int32_32_t& audio::int32_32_t::operator*= (const audio::int32_32_t& _obj) {
	int64_t tmp = int64_t(m_data) * int64_t(_obj.m_data);
	m_data = int32_t(tmp >> 31);
	return *this;
}

audio::int32_32_t audio::int32_32_t::operator* (const audio::int32_32_t& _obj) const {
	audio::int32_32_t tmpp(m_data);
	tmpp *= _obj;
	return tmpp;
}

const audio::int32_32_t& audio::int32_32_t::operator/= (const audio::int32_32_t& _obj) {
	int64_t tmp = (int64_t(m_data) << 31) / int64_t(_obj.m_data);
	m_data = int32_t(tmp);
	return *this;
}

audio::int32_32_t audio::int32_32_t::operator/ (const audio::int32_32_t& _obj) const{
	audio::int32_32_t tmpp(m_data);
	tmpp /= _obj;
	return tmpp;
}

audio::int32_32_t& audio::int32_32_t::operator++() {
	AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
	return *this;
}

audio::int32_32_t audio::int32_32_t::operator++(int _unused) {
	AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
	audio::int32_32_t result(m_data);
	return result;
}

audio::int32_32_t& audio::int32_32_t::operator--() {
	AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
	return *this;
}

audio::int32_32_t audio::int32_32_t::operator--(int _unused) {
	AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
	audio::int32_32_t result(m_data);
	return result;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int32_32_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":0.31=";
	_os << etk::to_string(double(_obj.get())/double(INT16_MAX));
	_os << "]";
	return _os;
}
