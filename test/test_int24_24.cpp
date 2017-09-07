/**
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <test-debug/debug.hpp>
#include <etest/etest.hpp>
#include <audio/types.hpp>


TEST(TestInt24_24, basicConstructorBase) {
	audio::int24_24_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt24_24, basicConstructorSetOne) {
	audio::int24_24_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), ((1<<23)-1));
}

TEST(TestInt24_24, basicConstructorSetLessOne) {
	audio::int24_24_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), (-(1<<23)));
}
/*
TEST(TestInt24_24, basicOperatorEqual) {
	audio::int24_24_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt24_24, basicOperatorPlus) {
	audio::int24_24_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt24_24, basicOperatorMinus) {
	audio::int24_24_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt24_24, basicOperatorMultiplication) {
	audio::int24_24_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::float_t(0.6);
	typeBase *= audio::float_t(0.3);
	EXPECT_EQ(typeBase.get(), audio::int24_24_t(audio::float_t(0.18)).get());
}
*/


#define RESULT_VALUE (2621440)

TEST(TestInt24_24, basicConstructorInt8_8) {
	audio::int24_24_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt8_16) {
	audio::int24_24_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt16_16) {
	audio::int24_24_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt24_24) {
	audio::int24_24_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt24_32) {
	audio::int24_24_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt16_32) {
	audio::int24_24_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt32_32) {
	audio::int24_24_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt32_64) {
	audio::int24_24_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorInt64_64) {
	audio::int24_24_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorFloat) {
	audio::int24_24_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_24, basicConstructorDouble) {
	audio::int24_24_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}

