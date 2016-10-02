/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once
#include <audio/types.hpp>

namespace audio {
	/**
	 * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
	 * |31|30|29|28|27|26|25|24|23|22|21|20|19|18|17|16|15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
	 * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
	 */
	class int8_8_t {
		private:
			int8_t m_data;
		public:
			int8_8_t() {}
			int8_8_t(int8_t _value) :
			  m_data(_value) {
				// nothing to do
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
			void set(int8_t _value);
			int8_t get() const;
			float getFloat() const;
			double getDouble() const;
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const int8_8_t& operator= (const int8_8_t& _obj);
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool  operator== (const int8_8_t& _obj) const;
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool  operator!= (const int8_8_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::int8_8_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::int8_8_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::int8_8_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::int8_8_t& _obj) const;
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const int8_8_t& operator+= (const int8_8_t& _obj);
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			int8_8_t operator+ (const int8_8_t& _obj) const;
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const int8_8_t& operator-= (const int8_8_t& _obj);
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			int8_8_t operator- (const int8_8_t& _obj) const;
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const int8_8_t& operator*= (const int8_8_t& _obj);
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			int8_8_t operator* (const int8_8_t& _obj) const;
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const int8_8_t& operator/= (const int8_8_t& _obj);
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			int8_8_t operator/ (const int8_8_t& _obj) const;
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			int8_8_t& operator++();
			int8_8_t operator++(int _unused);
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			int8_8_t& operator--();
			int8_8_t operator--(int _unused);
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int8_8_t& _obj);
}

