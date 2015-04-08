/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>



TEST(TestInt32_64, basicOperator) {
	audio::int32_64_t typeBase(16);
	audio::int32_64_t out(1, 0);
	
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), (int64_t(INT32_MAX)+1)*2);
	out *= 16;
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), 16);
	out = 1;
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), 1);
	out *= typeBase;
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), 0);
	out = audio::double_t(0.3);
	APPL_INFO(" data = " << out);
	out += audio::double_t(0.3);
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), audio::int32_64_t(audio::double_t(0.6)).get());
	out *= audio::double_t(0.3);
	APPL_INFO(" data = " << out);
	EXPECT_EQ(out.get(), audio::int32_64_t(audio::double_t(0.18)).get());
}


