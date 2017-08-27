/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <audio/types.hpp>

namespace audio {
	class float_t {
		private:
			float m_data;
		public:
			float_t() {}
			float_t(float _value) :
			  m_data(_value) {
				// nothing to do
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
			void set(float _value);
			float get() const;
			float getFloat() const;
			double getDouble() const;
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const float_t& operator= (const float_t& _obj);
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool operator== (const float_t& _obj) const;
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool operator!= (const float_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::float_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::float_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::float_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::float_t& _obj) const;
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const float_t& operator+= (const float_t& _obj);
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			float_t operator+ (const float_t& _obj) const;
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const float_t& operator-= (const float_t& _obj);
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			float_t operator- (const float_t& _obj) const;
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const float_t& operator*= (const float_t& _obj);
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			float_t operator* (const float_t& _obj) const;
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const float_t& operator/= (const float_t& _obj);
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			float_t operator/ (const float_t& _obj) const;
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			float_t& operator++();
			float_t operator++(int _unused);
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			float_t& operator--();
			float_t operator--(int _unused);
	};
	etk::Stream& operator <<(etk::Stream& _os, const audio::float_t& _obj);
}

