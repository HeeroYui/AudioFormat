/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/int16_16_t.h>
#include <audio/debug.h>

audio::int16_16_t::int16_16_t(const audio::int8_8_t& _val) {
	m_data = int16_t(_val.get()) << 8;
}

audio::int16_16_t::int16_16_t(const audio::int8_16_t& _val) {
	m_data = std::avg(int16_t(INT8_MIN),
	                  _val.get(),
	                  int16_t(INT8_MAX)
	                  ) << 7;
}

audio::int16_16_t::int16_16_t(const audio::int16_16_t& _val) {
	m_data = _val.m_data;
}

audio::int16_16_t::int16_16_t(const audio::int16_32_t& _val) {
	m_data = int16_t(std::avg(int32_t(INT16_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT16_MAX)
	                          )
	                 );
}

audio::int16_16_t::int16_16_t(const audio::int24_24_t& _val) {
	m_data = int16_t(_val.get() >> 8);
}

audio::int16_16_t::int16_16_t(const audio::int24_32_t& _val) {
	m_data = int16_t(std::avg(int32_t(INT24_MIN),
	                          _val.get() >> 1,
	                          int32_t(INT24_MAX)
	                          ) >> 8
	                 );
}

audio::int16_16_t::int16_16_t(const audio::int32_32_t& _val) {
	m_data = int16_t(_val.get() >> 16);
}

audio::int16_16_t::int16_16_t(const audio::int32_64_t& _val) {
	m_data = int16_t(std::avg(int64_t(INT32_MIN),
	                          _val.get() >> 1,
	                          int64_t(INT32_MAX)
	                          ) >> 16
	                 );
}

audio::int16_16_t::int16_16_t(const audio::int64_64_t& _val) {
	m_data = int16_t(_val.get() >> 48);
}

audio::int16_16_t::int16_16_t(const audio::float_t& _val) {
	m_data = int16_t(std::avg(-1.0f,
	                          _val.get(),
	                          0.999969482f
	                          ) * (float(INT16_MAX)+1)
	                 );
}

audio::int16_16_t::int16_16_t(const audio::double_t& _val) {
	m_data = int16_t(std::avg(-1.0,
	                          _val.get(),
	                          0.999969482
	                          ) * (double(INT16_MAX)+1)
	                 );
}

audio::int16_16_t::int16_16_t(int64_t _value, int32_t _flotingPointPosition) {
	set(_value, _flotingPointPosition);
}

void audio::int16_16_t::set(int64_t _value, int32_t _flotingPointPosition) {
	int64_t val = _value << (15-_flotingPointPosition);
	m_data = std::avg(int64_t(INT16_MIN), val, int64_t(INT16_MAX));
}

void audio::int16_16_t::set(int16_t _value) {
	m_data = _value;
}

int16_t audio::int16_16_t::get() const {
	return m_data;
}

float audio::int16_16_t::getFloat() const {
	return getDouble();
}

double audio::int16_16_t::getDouble() const {
	return double(m_data)/(double(INT16_MAX)+1);
}

const audio::int16_16_t& audio::int16_16_t::operator= (const audio::int16_16_t& _obj ) {
	m_data = _obj.m_data;
	return *this;
}

bool audio::int16_16_t::operator== (const audio::int16_16_t& _obj) const {
	return _obj.m_data == m_data;
}

bool audio::int16_16_t::operator!= (const audio::int16_16_t& _obj) const {
	return _obj.m_data != m_data;
}

bool audio::int16_16_t::operator< (const audio::int16_16_t& _obj) const {
	return m_data < _obj.m_data;
}

bool audio::int16_16_t::operator<= (const audio::int16_16_t& _obj) const {
	return m_data <= _obj.m_data;
}

bool audio::int16_16_t::operator> (const audio::int16_16_t& _obj) const {
	return m_data > _obj.m_data;
}

bool audio::int16_16_t::operator>= (const audio::int16_16_t& _obj) const {
	return m_data >= _obj.m_data;
}

const audio::int16_16_t& audio::int16_16_t::operator+= (const audio::int16_16_t& _obj) {
	m_data += _obj.m_data;
	return *this;
}

audio::int16_16_t audio::int16_16_t::operator+ (const audio::int16_16_t& _obj) const {
	audio::int16_16_t tmpp(m_data);
	tmpp.m_data += _obj.m_data;
	return tmpp;
}

const audio::int16_16_t& audio::int16_16_t::operator-= (const audio::int16_16_t& _obj) {
	m_data -= _obj.m_data;
	return *this;
}

audio::int16_16_t audio::int16_16_t::operator- (const audio::int16_16_t& _obj) const {
	audio::int16_16_t tmpp(m_data);
	tmpp.m_data -= _obj.m_data;
	return tmpp;
}

const audio::int16_16_t& audio::int16_16_t::operator*= (const audio::int16_16_t& _obj) {
	int32_t tmp = int32_t(m_data) * int32_t(_obj.m_data);
	m_data = int16_t(tmp >> 15);
	return *this;
}

audio::int16_16_t audio::int16_16_t::operator* (const audio::int16_16_t& _obj) const {
	audio::int16_16_t tmpp(m_data);
	tmpp *= _obj;
	return tmpp;
}

const audio::int16_16_t& audio::int16_16_t::operator/= (const audio::int16_16_t& _obj) {
	int32_t tmp = (int32_t(m_data) << 15) / int32_t(_obj.m_data);
	m_data = int16_t(tmp);
	return *this;
}

audio::int16_16_t audio::int16_16_t::operator/ (const audio::int16_16_t& _obj) const{
	audio::int16_16_t tmpp(m_data);
	tmpp /= _obj;
	return tmpp;
}

audio::int16_16_t& audio::int16_16_t::operator++() {
	AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
	return *this;
}

audio::int16_16_t audio::int16_16_t::operator++(int _unused) {
	AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
	audio::int16_16_t result(m_data);
	return result;
}

audio::int16_16_t& audio::int16_16_t::operator--() {
	AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
	return *this;
}

audio::int16_16_t audio::int16_16_t::operator--(int _unused) {
	AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
	audio::int16_16_t result(m_data);
	return result;
}

std::ostream& audio::operator <<(std::ostream& _os, const audio::int16_16_t& _obj) {
	_os << "[" << etk::to_string(_obj.get()) << ":0.15=";
	_os << etk::to_string(double(_obj.get())/(double(INT16_MAX)+1));
	_os << "]";
	return _os;
}

