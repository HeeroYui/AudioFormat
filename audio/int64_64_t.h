/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once
#include <audio/types.h>

namespace audio {
	class int64_64_t {
		private:
			int64_t m_data;
		public:
			int64_64_t() {}
			int64_64_t(int64_t _value) :
			  m_data(_value) {
				// nothing to do
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
			void set(int64_t _value);
			int64_t get() const;
			float getFloat() const;
			double getDouble() const;
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const int64_64_t& operator= (const int64_64_t& _obj);
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const int64_64_t& _obj) const;
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const int64_64_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::int64_64_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::int64_64_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::int64_64_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::int64_64_t& _obj) const;
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const int64_64_t& operator+= (const int64_64_t& _obj);
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			int64_64_t operator+ (const int64_64_t& _obj) const;
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const int64_64_t& operator-= (const int64_64_t& _obj);
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			int64_64_t operator- (const int64_64_t& _obj) const;
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const int64_64_t& operator*= (const int64_64_t& _obj);
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			int64_64_t operator* (const int64_64_t& _obj) const;
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const int64_64_t& operator/= (const int64_64_t& _obj);
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			int64_64_t operator/ (const int64_64_t& _obj) const;
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			int64_64_t& operator++();
			int64_64_t operator++(int _unused);
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			int64_64_t& operator--();
			int64_64_t operator--(int _unused);
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int64_64_t& _obj);
}

