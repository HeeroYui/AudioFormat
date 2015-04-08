/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT8_8_T_H__
#define __AUDIO_TYPE_INT8_8_T_H__

#include <audio/debug.h>

namespace audio {
	class int8_8_t {
		private:
			int8_t m_data;
		public:
			int8_8_t() {}
			int8_8_t(int8_t _value) {
				m_data = _value;
			}
			// transformation operator:
			int8_8_t(const audio::int8_8_t& _val);
			int8_8_t(const audio::int8_16_t& _val);
			int8_8_t(const audio::int16_16_t& _val);
			int8_8_t(const audio::int16_32_t& _val);
			int8_8_t(const audio::int24_24_t& _val);
			int8_8_t(const audio::int24_32_t& _val);
			int8_8_t(const audio::int32_32_t& _val);
			int8_8_t(const audio::int32_64_t& _val);
			int8_8_t(const audio::int64_64_t& _val);
			int8_8_t(const audio::float_t& _val);
			int8_8_t(const audio::double_t& _val);
			// set operator
			int8_8_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(int8_t _value) {
				m_data = _value;
			}
			int8_t get() const {
				return m_data;
			}
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const int8_8_t& operator= (const int8_8_t& _obj ) {
				m_data = _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const int8_8_t& _obj) const {
				return _obj.m_data == m_data;
			}
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const int8_8_t& _obj) const {
				return _obj.m_data != m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::int8_8_t& _obj) const {
				return m_data < _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::int8_8_t& _obj) const {
				return m_data <= _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::int8_8_t& _obj) const {
				return m_data > _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::int8_8_t& _obj) const {
				return m_data >= _obj.m_data;
			}
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const int8_8_t& operator+= (const int8_8_t& _obj) {
				m_data += _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			int8_8_t operator+ (const int8_8_t& _obj) const {
				int8_8_t tmpp(m_data);
				tmpp.m_data += _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const int8_8_t& operator-= (const int8_8_t& _obj) {
				m_data -= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			int8_8_t operator- (const int8_8_t& _obj) const {
				int8_8_t tmpp(m_data);
				tmpp.m_data -= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const int8_8_t& operator*= (const int8_8_t& _obj) {
				int16_t tmp = int16_t(m_data) * int16_t(_obj.m_data);
				m_data = int8_t(tmp >> 8);
				return *this;
			}
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			int8_8_t operator* (const int8_8_t& _obj) const {
				int8_8_t tmpp(m_data);
				tmpp *= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const int8_8_t& operator/= (const int8_8_t& _obj) {
				int16_t tmp = (int16_t(m_data) << 8) / int16_t(_obj.m_data);
				m_data = int8_t(tmp);
				return *this;
			}
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			int8_8_t operator/ (const int8_8_t& _obj) const{
				int8_8_t tmpp(m_data);
				tmpp /= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			int8_8_t& operator++() {
				AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
				return *this;
			}
			int8_8_t operator++(int _unused) {
				AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
				int8_8_t result(m_data);
				return result;
			}
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			int8_8_t& operator--() {
				AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
				return *this;
			}
			int8_8_t operator--(int _unused) {
				AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
				int8_8_t result(m_data);
				return result;
			}
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int8_8_t& _obj);
}

#include <audio/debugRemove.h>

#endif

