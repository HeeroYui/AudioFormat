/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>



TEST(TestInt16_16, basicOperator) {
	audio::int16_16_t typeBase(16);
	audio::int16_16_t out(1, 0);
	
	EXPECT_EQ(out.get(), ((1<<15)-1));
	out *= 16;
	EXPECT_EQ(out.get(), 16);
	out = 1;
	EXPECT_EQ(out.get(), 1);
	out *= typeBase;
	EXPECT_EQ(out.get(), 0);
	out = audio::float_t(0.3);
	APPL_INFO(" data = " << out);
	out += audio::float_t(0.3);
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), audio::int16_16_t(audio::float_t(0.6)).get());
	out *= audio::float_t(0.3);
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), audio::int16_16_t(audio::float_t(0.18)).get());
}
