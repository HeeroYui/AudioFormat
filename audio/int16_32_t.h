/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT16_32_T_H__
#define __AUDIO_TYPE_INT16_32_T_H__

namespace audio {
	class int16_32_t{
		private:
			int32_t m_data;
		public:
			int16_32_t() {}
			int16_32_t(int32_t _value) {
				m_data = _value;
			}
			// transformation operator:
			int16_32_t(const audio::int8_8_t& _val);
			int16_32_t(const audio::int8_16_t& _val);
			int16_32_t(const audio::int16_16_t& _val);
			int16_32_t(const audio::int16_32_t& _val);
			int16_32_t(const audio::int24_24_t& _val);
			int16_32_t(const audio::int24_32_t& _val);
			int16_32_t(const audio::int32_32_t& _val);
			int16_32_t(const audio::int32_64_t& _val);
			int16_32_t(const audio::int64_64_t& _val);
			int16_32_t(const audio::float_t& _val);
			int16_32_t(const audio::double_t& _val);
			// set operator
			int16_32_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(int32_t _value) {
				m_data = _value;
			}
			int32_t get() const {
				return m_data;
			}
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const int16_32_t& operator= (const int16_32_t& _obj ) {
				m_data = _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const int16_32_t& _obj) const {
				return _obj.m_data == m_data;
			}
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const int16_32_t& _obj) const {
				return _obj.m_data != m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::int16_32_t& _obj) const {
				return m_data < _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::int16_32_t& _obj) const {
				return m_data <= _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::int16_32_t& _obj) const {
				return m_data > _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::int16_32_t& _obj) const {
				return m_data >= _obj.m_data;
			}
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const int16_32_t& operator+= (const int16_32_t& _obj) {
				m_data += _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			int16_32_t operator+ (const int16_32_t& _obj) const {
				int16_32_t tmpp(m_data);
				tmpp.m_data += _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const int16_32_t& operator-= (const int16_32_t& _obj) {
				m_data -= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			int16_32_t operator- (const int16_32_t& _obj) const {
				int16_32_t tmpp(m_data);
				tmpp.m_data -= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const int16_32_t& operator*= (const int16_32_t& _obj) {
				int64_t tmp = int64_t(m_data) * int64_t(_obj.m_data) + (1<<14);
				m_data = int32_t(tmp >> 15);
				return *this;
			}
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			int16_32_t operator* (const int16_32_t& _obj) const {
				int16_32_t tmpp(m_data);
				tmpp *= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const int16_32_t& operator/= (const int16_32_t& _obj) {
				int64_t tmp = (int64_t(m_data) << 15) / int64_t(_obj.m_data);
				m_data = int32_t(tmp);
				return *this;
			}
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			int16_32_t operator/ (const int16_32_t& _obj) const{
				int16_32_t tmpp(m_data);
				tmpp /= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			int16_32_t& operator++() {
				m_data += (1<<16);
				return *this;
			}
			int16_32_t operator++(int _unused) {
				int16_32_t result(m_data);
				result.m_data += (1<<16);
				return result;
			}
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			int16_32_t& operator--() {
				m_data -= (1<<16);
				return *this;
			}
			int16_32_t operator--(int _unused) {
				int16_32_t result(m_data);
				result.m_data -= (1<<16);
				return result;
			}
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int16_32_t& _obj);
}

#endif

