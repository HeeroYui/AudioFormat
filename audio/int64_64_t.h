/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT64_64_T_H__
#define __AUDIO_TYPE_INT64_64_T_H__

#include <audio/debug.h>

namespace audio {
	class int64_64_t {
		private:
			int64_t m_data;
		public:
			int64_64_t() {}
			int64_64_t(int64_t _value) {
				m_data = _value;
			}
			// transformation operator:
			int64_64_t(const audio::int8_8_t& _val);
			int64_64_t(const audio::int8_16_t& _val);
			int64_64_t(const audio::int16_16_t& _val);
			int64_64_t(const audio::int16_32_t& _val);
			int64_64_t(const audio::int24_24_t& _val);
			int64_64_t(const audio::int24_32_t& _val);
			int64_64_t(const audio::int32_32_t& _val);
			int64_64_t(const audio::int32_64_t& _val);
			int64_64_t(const audio::int64_64_t& _val);
			int64_64_t(const audio::float_t& _val);
			int64_64_t(const audio::double_t& _val);
			// set operator
			int64_64_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value) {
				m_data = _value;
			}
			int64_t get() const {
				return m_data;
			}
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const int64_64_t& operator= (const int64_64_t& _obj ) {
				m_data = _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const int64_64_t& _obj) const {
				return _obj.m_data == m_data;
			}
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const int64_64_t& _obj) const {
				return _obj.m_data != m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::int64_64_t& _obj) const {
				return m_data < _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::int64_64_t& _obj) const {
				return m_data <= _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::int64_64_t& _obj) const {
				return m_data > _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::int64_64_t& _obj) const {
				return m_data >= _obj.m_data;
			}
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const int64_64_t& operator+= (const int64_64_t& _obj) {
				m_data += _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			int64_64_t operator+ (const int64_64_t& _obj) const {
				int64_64_t tmpp(m_data);
				tmpp.m_data += _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const int64_64_t& operator-= (const int64_64_t& _obj) {
				m_data -= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			int64_64_t operator- (const int64_64_t& _obj) const {
				int64_64_t tmpp(m_data);
				tmpp.m_data -= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const int64_64_t& operator*= (const int64_64_t& _obj) {
				if (    m_data > INT32_MAX
				     || m_data < INT32_MIN) {
					if (    _obj.m_data > INT32_MAX
					     || _obj.m_data < INT32_MIN) {
						int64_t tmp = (m_data >> 31) * (_obj.m_data >> 31);
						m_data = tmp >> 1;
					} else {
						int64_t tmp = (m_data >> 31) * (_obj.m_data);
						m_data = tmp >> 32;
					}
				} else {
					if (    _obj.m_data > INT32_MAX
					     || _obj.m_data < INT32_MIN) {
						int64_t tmp = (m_data) * (_obj.m_data >> 32);
						m_data = tmp >> 31;
					} else {
						int64_t tmp = (m_data >> 24) * (_obj.m_data >> 24);
						m_data = tmp >> 16;
					}
				}
				return *this;
			}
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			int64_64_t operator* (const int64_64_t& _obj) const {
				int64_64_t tmpp(m_data);
				tmpp *= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const int64_64_t& operator/= (const int64_64_t& _obj) {
				// TODO: Does not work
				int64_t tmp = (m_data) / (_obj.m_data);
				m_data = tmp << 63;
				return *this;
			}
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			int64_64_t operator/ (const int64_64_t& _obj) const{
				int64_64_t tmpp(m_data);
				tmpp /= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			int64_64_t& operator++() {
				AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
				return *this;
			}
			int64_64_t operator++(int _unused) {
				AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
				int64_64_t result(m_data);
				return result;
			}
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			int64_64_t& operator--() {
				AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
				return *this;
			}
			int64_64_t operator--(int _unused) {
				AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
				int64_64_t result(m_data);
				return result;
			}
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int64_64_t& _obj);
}

#include <audio/debugRemove.h>

#endif

