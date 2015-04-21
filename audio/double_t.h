/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_DOUBLE_T_H__
#define __AUDIO_TYPE_DOUBLE_T_H__

namespace audio {
	class double_t {
		private:
			double m_data;
		public:
			double_t() {}
			double_t(double _value) {
				m_data = _value;
			}
			// transformation operator:
			double_t(const audio::int8_8_t& _val);
			double_t(const audio::int8_16_t& _val);
			double_t(const audio::int16_16_t& _val);
			double_t(const audio::int16_32_t& _val);
			double_t(const audio::int24_24_t& _val);
			double_t(const audio::int24_32_t& _val);
			double_t(const audio::int32_32_t& _val);
			double_t(const audio::int32_64_t& _val);
			double_t(const audio::int64_64_t& _val);
			double_t(const audio::float_t& _val);
			double_t(const audio::double_t& _val);
			// set operator
			double_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(double _value) {
				m_data = _value;
			}
			double get() const {
				return m_data;
			}
			float getFloat() const {
				return m_data;
			}
			double getDouble() const {
				return m_data;
			}
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const double_t& operator= (const double_t& _obj ) {
				m_data = _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const double_t& _obj) const {
				return _obj.m_data == m_data;
			}
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const double_t& _obj) const {
				return _obj.m_data != m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::double_t& _obj) const {
				return m_data < _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::double_t& _obj) const {
				return m_data <= _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::double_t& _obj) const {
				return m_data > _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::double_t& _obj) const {
				return m_data >= _obj.m_data;
			}
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const double_t& operator+= (const double_t& _obj) {
				m_data += _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			double_t operator+ (const double_t& _obj) const {
				double_t tmpp(m_data);
				tmpp.m_data += _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const double_t& operator-= (const double_t& _obj) {
				m_data -= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			double_t operator- (const double_t& _obj) const {
				double_t tmpp(m_data);
				tmpp.m_data -= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const double_t& operator*= (const double_t& _obj) {
				m_data *= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			double_t operator* (const double_t& _obj) const {
				double_t tmpp(m_data);
				tmpp.m_data *= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const double_t& operator/= (const double_t& _obj) {
				m_data /= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			double_t operator/ (const double_t& _obj) const{
				double_t tmpp(m_data);
				tmpp.m_data /= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			double_t& operator++() {
				m_data += 1.0f;
				return *this;
			}
			double_t operator++(int _unused) {
				double_t result(m_data);
				m_data += 1.0f;
				return result;
			}
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			double_t& operator--() {
				m_data -= 1.0f;
				return *this;
			}
			double_t operator--(int _unused) {
				double_t result(m_data);
				m_data -= 1.0f;
				return result;
			}
	};
	std::ostream& operator <<(std::ostream& _os, const audio::double_t& _obj);
}

#endif

