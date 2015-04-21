/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/types.h>

#ifndef __AUDIO_TYPE_INT16_16_T_H__
#define __AUDIO_TYPE_INT16_16_T_H__

#include <audio/debug.h>

namespace audio {
	/**
	 * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
	 * |15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
	 * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
	 * |BS|                  < 1.0                     |
	 * +--+--------------------------------------------+
	 */
	class int16_16_t{
		private:
			int16_t m_data;
		public:
			int16_16_t() {}
			int16_16_t(int16_t _value) {
				m_data = _value;
			}
			// transformation operator:
			int16_16_t(const audio::int8_8_t& _val);
			int16_16_t(const audio::int8_16_t& _val);
			int16_16_t(const audio::int16_16_t& _val);
			int16_16_t(const audio::int16_32_t& _val);
			int16_16_t(const audio::int24_24_t& _val);
			int16_16_t(const audio::int24_32_t& _val);
			int16_16_t(const audio::int32_32_t& _val);
			int16_16_t(const audio::int32_64_t& _val);
			int16_16_t(const audio::int64_64_t& _val);
			int16_16_t(const audio::float_t& _val);
			int16_16_t(const audio::double_t& _val);
			// set operator
			int16_16_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(int16_t _value) {
				m_data = _value;
			}
			int16_t get() const {
				return m_data;
			}
			float getFloat() const {
				return getDouble();
			}
			double getDouble() const {
				return double(m_data)/(double(INT16_MAX)+1);
			}
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const int16_16_t& operator= (const int16_16_t& _obj ) {
				m_data = _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const int16_16_t& _obj) const {
				return _obj.m_data == m_data;
			}
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const int16_16_t& _obj) const {
				return _obj.m_data != m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::int16_16_t& _obj) const {
				return m_data < _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::int16_16_t& _obj) const {
				return m_data <= _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::int16_16_t& _obj) const {
				return m_data > _obj.m_data;
			}
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::int16_16_t& _obj) const {
				return m_data >= _obj.m_data;
			}
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const int16_16_t& operator+= (const int16_16_t& _obj) {
				m_data += _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			int16_16_t operator+ (const int16_16_t& _obj) const {
				int16_16_t tmpp(m_data);
				tmpp.m_data += _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const int16_16_t& operator-= (const int16_16_t& _obj) {
				m_data -= _obj.m_data;
				return *this;
			}
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			int16_16_t operator- (const int16_16_t& _obj) const {
				int16_16_t tmpp(m_data);
				tmpp.m_data -= _obj.m_data;
				return tmpp;
			}
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const int16_16_t& operator*= (const int16_16_t& _obj) {
				int32_t tmp = int32_t(m_data) * int32_t(_obj.m_data);
				m_data = int16_t(tmp >> 15);
				return *this;
			}
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			int16_16_t operator* (const int16_16_t& _obj) const {
				int16_16_t tmpp(m_data);
				tmpp *= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const int16_16_t& operator/= (const int16_16_t& _obj) {
				int32_t tmp = (int32_t(m_data) << 15) / int32_t(_obj.m_data);
				m_data = int16_t(tmp);
				return *this;
			}
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			int16_16_t operator/ (const int16_16_t& _obj) const{
				int16_16_t tmpp(m_data);
				tmpp /= _obj;
				return tmpp;
			}
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			int16_16_t& operator++() {
				AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
				return *this;
			}
			int16_16_t operator++(int _unused) {
				AUDIO_CRITICAL("INCREMENT ++  a type that can not be > 0");
				int16_16_t result(m_data);
				return result;
			}
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			int16_16_t& operator--() {
				AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
				return *this;
			}
			int16_16_t operator--(int _unused) {
				AUDIO_CRITICAL("DECREMENT --  a type that can not be > 0");
				int16_16_t result(m_data);
				return result;
			}
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int16_16_t& _obj);
}

#include <audio/debugRemove.h>

#endif

