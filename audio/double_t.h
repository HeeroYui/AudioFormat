/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once
#include <audio/types.h>

namespace audio {
	class double_t {
		private:
			double m_data;
		public:
			double_t() {}
			double_t(double _value) :
			  m_data(_value) {
				// nothing to do
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
			void set(double _value);
			double get() const;
			float getFloat() const;
			double getDouble() const;
			/* ****************************************************
			 *    = assigment
			 *****************************************************/
			const double_t& operator= (const double_t& _obj);
			/* ****************************************************
			 *    == operator
			 *****************************************************/
			bool operator== (const double_t& _obj) const;
			/* ****************************************************
			 *    != operator
			 *****************************************************/
			bool operator!= (const double_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator< (const audio::double_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator<= (const audio::double_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator> (const audio::double_t& _obj) const;
			/* ****************************************************
			 *    < operator
			 *****************************************************/
			bool operator>= (const audio::double_t& _obj) const;
			/* ****************************************************
			 *    += operator
			 *****************************************************/
			const double_t& operator+= (const double_t& _obj);
			/* ****************************************************
			 *    + operator
			 *****************************************************/
			double_t operator+ (const double_t& _obj) const;
			/* ****************************************************
			 *    -= operator
			 *****************************************************/
			const double_t& operator-= (const double_t& _obj);
			/* ****************************************************
			 *    - operator
			 *****************************************************/
			double_t operator- (const double_t& _obj) const;
			/* ****************************************************
			 *    *= operator
			 *****************************************************/
			const double_t& operator*= (const double_t& _obj);
			/* ****************************************************
			 *    * operator
			 *****************************************************/
			double_t operator* (const double_t& _obj) const;
			/* ****************************************************
			 *    /= operator
			 *****************************************************/
			const double_t& operator/= (const double_t& _obj);
			/* ****************************************************
			 *    / operator
			 *****************************************************/
			double_t operator/ (const double_t& _obj) const;
			/* ****************************************************
			 *    ++ operator
			 *****************************************************/
			double_t& operator++();
			double_t operator++(int _unused);
			/* ****************************************************
			 *    -- operator
			 *****************************************************/
			double_t& operator--();
			double_t operator--(int _unused);
	};
	std::ostream& operator <<(std::ostream& _os, const audio::double_t& _obj);
}
