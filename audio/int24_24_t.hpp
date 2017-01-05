/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once
#include <audio/types.hpp>

namespace audio {
	/**
	 * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
	 * |23|22|21|20|19|18|17|16|15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
	 * +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
	 * |BS|                                  < 1.0                             |
	 * +--+--------------------------------------------------------------------+
	 */
	class int24_24_t {
		private:
			uint8_t m_data[3];
		public:
			int24_24_t() {}
			int24_24_t(int32_t _value) {
				set(_value);
			}
			// transformation operator:
			int24_24_t(const audio::int8_8_t& _val);
			int24_24_t(const audio::int8_16_t& _val);
			int24_24_t(const audio::int16_16_t& _val);
			int24_24_t(const audio::int16_32_t& _val);
			int24_24_t(const audio::int24_24_t& _val);
			int24_24_t(const audio::int24_32_t& _val);
			int24_24_t(const audio::int32_32_t& _val);
			int24_24_t(const audio::int32_64_t& _val);
			int24_24_t(const audio::int64_64_t& _val);
			int24_24_t(const audio::float_t& _val);
			int24_24_t(const audio::double_t& _val);
			// set operator
			int24_24_t(int64_t _value, int32_t _flotingPointPosition);
			void set(int64_t _value, int32_t _flotingPointPosition);
			void set(int32_t _value);
			int32_t get() const;
	};
	std::ostream& operator <<(std::ostream& _os, const audio::int24_24_t& _obj);
}

