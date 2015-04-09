/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_FLOAT_T_H__
#define __AUDIO_TYPE_FLOAT_T_H__

namespace audio {
	class float_t {
		private:
			float m_data;
		public:
			float_t() {}
			float_t(float _value) {
				m_data = _value;
			}
			// transformation operator:
			float_t(const audio::int8_8_t& _val);
			float_t(const audio::int8_16_t& _val);
			float_t(const audio::int16_16_t& _val);
			float_t(const audio::int16_32_t& _val);
			float_t(const audio::int24_24_t& _val);
			float_t(const audio::int24_32_t& _val);
			float_t(const audio::int32_32_t& _val);
			float_t(const audio::int32_64_t& _val);
			float_t(const audio::int64_64_t& _val);
			float_t(const audio::float_t& _val);
			float_t(const audio::double_t& _val);
			// set operator
			float_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(float _value) {
				m_data = _value;
			}
			float get() const {
				return m_data;
			}
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const float_t& operator= (const float_t& _obj ) {
				m_data = _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const float_t& _obj) const {
				return _obj.m_data == m_data;
			}
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const float_t& _obj) const {
				return _obj.m_data != m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::float_t& _obj) const {
				return m_data < _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::float_t& _obj) const {
				return m_data <= _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::float_t& _obj) const {
				return m_data > _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::float_t& _obj) const {
				return m_data >= _obj.m_data;
			}
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const float_t& operator+= (const float_t& _obj) {
				m_data += _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			float_t operator+ (const float_t& _obj) const {
				float_t tmpp(m_data);
				tmpp.m_data += _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const float_t& operator-= (const float_t& _obj) {
				m_data -= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			float_t operator- (const float_t& _obj) const {
				float_t tmpp(m_data);
				tmpp.m_data -= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const float_t& operator*= (const float_t& _obj) {
				m_data *= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			float_t operator* (const float_t& _obj) const {
				float_t tmpp(m_data);
				tmpp.m_data *= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const float_t& operator/= (const float_t& _obj) {
				m_data /= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			float_t operator/ (const float_t& _obj) const{
				float_t tmpp(m_data);
				tmpp.m_data /= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			float_t& operator++() {
				m_data += 1.0f;
				return *this;
			}
			float_t operator++(int _unused) {
				float_t result(m_data);
				m_data += 1.0f;
				return result;
			}
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			float_t& operator--() {
				m_data -= 1.0f;
				return *this;
			}
			float_t operator--(int _unused) {
				float_t result(m_data);
				m_data -= 1.0f;
				return result;
			}
	};
	std::ostream& operator <<(std::ostream& _os, const audio::float_t& _obj);
}

#endif

