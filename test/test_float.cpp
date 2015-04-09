/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>

TEST(TestFloat, basicConstructorBase) {
	audio::float_t typeBase(25.0f);
	EXPECT_EQ(typeBase.get(), 25.0f);
}

TEST(TestFloat, basicConstructorSetOne) {
	audio::float_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), 1.0f);
}

TEST(TestFloat, basicConstructorSetLessOne) {
	audio::float_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), -1.0f);
}

TEST(TestFloat, basicOperatorEqual) {
	audio::float_t typeBase;
	typeBase = 35.0f;
	EXPECT_EQ(typeBase.get(), 35.0f);
}

TEST(TestFloat, basicOperatorPlus) {
	audio::float_t typeBase(35.0f);
	typeBase += 35.0f;
	EXPECT_EQ(typeBase.get(), 70.0f);
}

TEST(TestFloat, basicOperatorMinus) {
	audio::float_t typeBase(55.0f);
	typeBase -= 35.0f;
	EXPECT_EQ(typeBase.get(), 20.0f);
	typeBase -= 35.0f;
	EXPECT_EQ(typeBase.get(), -15.0f);
}

TEST(TestFloat, basicOperatorMultiplication) {
	audio::float_t typeBase(-1, 0);
	typeBase *= 35.0f;
	EXPECT_EQ(typeBase.get(), -35.0f);
	typeBase = 0.6f;
	typeBase *= 0.3f;
	EXPECT_EQ(typeBase.get(), 0.18f);
}

TEST(TestFloat, basicOperatorCompareEquality) {
	audio::float_t typeBase1(-12, 5);
	audio::float_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestFloat, basicOperatorCompareInEquality) {
	audio::float_t typeBase1(-12, 5);
	audio::float_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestFloat, basicOperatorCompareMinor) {
	audio::float_t typeBase1(-12, 5);
	audio::float_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestFloat, basicOperatorCompareEqualityMinor) {
	audio::float_t typeBase1(-12, 5);
	audio::float_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestFloat, basicOperatorCompareMajor) {
	audio::float_t typeBase1(-12, 5);
	audio::float_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestFloat, basicOperatorCompareEqualityMajor) {
	audio::float_t typeBase1(-12, 5);
	audio::float_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestFloat, basicOperatorLiteralPlus) {
	audio::float_t out;
	out = audio::float_t(-13, 5) + audio::float_t(12, 5);
	EXPECT_EQ(out.get(), audio::float_t(-1,5).get());
}

TEST(TestFloat, basicOperatorLiteralMinus) {
	audio::float_t out;
	out = audio::float_t(-13, 5) - audio::float_t(12, 5);
	EXPECT_EQ(out.get(), audio::float_t(-25,5).get());
}

TEST(TestFloat, basicOperatorLiteralMultiplication) {
	audio::float_t out;
	out = audio::float_t(-5, 3) * audio::float_t(3, 3);
	EXPECT_EQ(out.get(), audio::float_t(-15,6).get());
}

TEST(TestFloat, basicOperatorDividing) {
	audio::float_t out(-15, 2);
	out /= audio::float_t(3, 2);
	EXPECT_EQ(out.get(), audio::float_t(-5,0).get());
}

TEST(TestFloat, basicOperatorLiteralDividing) {
	audio::float_t out;
	out = audio::float_t(-15, 2) / audio::float_t(3, 2);
	EXPECT_EQ(out.get(), audio::float_t(-5,0).get());
}

TEST(TestFloat, basicOperatorIncrementPost) {
	audio::float_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::float_t(11, 0).get());
}

TEST(TestFloat, basicOperatorIncrementPre) {
	audio::float_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::float_t(11, 0).get());
}

TEST(TestFloat, basicOperatorDecrementPost) {
	audio::float_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::float_t(9, 0).get());
}

TEST(TestFloat, basicOperatorDecrementPre) {
	audio::float_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::float_t(9, 0).get());
}

#define RESULT_VALUE (0.3125)

TEST(TestFloat, basicConstructorInt8_8) {
	audio::float_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorInt8_16) {
	audio::float_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(int32_t(RESULT_VALUE*1000.0f)+1, int32_t(out.get()*1000.0f));
}
TEST(TestFloat, basicConstructorInt16_16) {
	audio::float_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorInt24_24) {
	audio::float_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorInt24_32) {
	audio::float_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(int32_t(RESULT_VALUE*1000.0f), int32_t(out.get()*1000.0f));
}
TEST(TestFloat, basicConstructorInt16_32) {
	audio::float_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(int32_t(RESULT_VALUE*1000.0f), int32_t(out.get()*1000.0f));
}
TEST(TestFloat, basicConstructorInt32_32) {
	audio::float_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorInt32_64) {
	audio::float_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorInt64_64) {
	audio::float_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorFloat) {
	audio::float_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestFloat, basicConstructorDouble) {
	audio::float_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}


