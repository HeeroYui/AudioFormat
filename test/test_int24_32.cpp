/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>


TEST(TestInt24_32, basicConstructorBase) {
	audio::int24_32_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt24_32, basicConstructorSetOne) {
	audio::int24_32_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), ((1<<24)));
}

TEST(TestInt24_32, basicConstructorSetLessOne) {
	audio::int24_32_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), (-(1<<24)));
}

TEST(TestInt24_32, basicOperatorEqual) {
	audio::int24_32_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt24_32, basicOperatorPlus) {
	audio::int24_32_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt24_32, basicOperatorMinus) {
	audio::int24_32_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt24_32, basicOperatorMultiplication) {
	audio::int24_32_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::int24_32_t(3,5);
	typeBase *= audio::int24_32_t(3,1);
	EXPECT_EQ(typeBase.get(), audio::int24_32_t(9,6).get());
}

TEST(TestInt24_32, basicOperatorCompareEquality) {
	audio::int24_32_t typeBase1(-12, 5);
	audio::int24_32_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt24_32, basicOperatorCompareInEquality) {
	audio::int24_32_t typeBase1(-12, 5);
	audio::int24_32_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt24_32, basicOperatorCompareMinor) {
	audio::int24_32_t typeBase1(-12, 5);
	audio::int24_32_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt24_32, basicOperatorCompareEqualityMinor) {
	audio::int24_32_t typeBase1(-12, 5);
	audio::int24_32_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestInt24_32, basicOperatorCompareMajor) {
	audio::int24_32_t typeBase1(-12, 5);
	audio::int24_32_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestInt24_32, basicOperatorCompareEqualityMajor) {
	audio::int24_32_t typeBase1(-12, 5);
	audio::int24_32_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt24_32, basicOperatorLiteralPlus) {
	audio::int24_32_t out;
	out = audio::int24_32_t(-13, 5) + audio::int24_32_t(12, 5);
	EXPECT_EQ(out.get(), audio::int24_32_t(-1,5).get());
}

TEST(TestInt24_32, basicOperatorLiteralMinus) {
	audio::int24_32_t out;
	out = audio::int24_32_t(-13, 5) - audio::int24_32_t(12, 5);
	EXPECT_EQ(out.get(), audio::int24_32_t(-25,5).get());
}

TEST(TestInt24_32, basicOperatorLiteralMultiplication) {
	audio::int24_32_t out;
	out = audio::int24_32_t(-5, 3) * audio::int24_32_t(3, 3);
	EXPECT_EQ(out.get(), audio::int24_32_t(-15,6).get());
}

TEST(TestInt24_32, basicOperatorDividing) {
	audio::int24_32_t out(-15, 2);
	out /= audio::int24_32_t(3, 2);
	EXPECT_EQ(out.get(), audio::int24_32_t(-5,0).get());
}

TEST(TestInt24_32, basicOperatorLiteralDividing) {
	audio::int24_32_t out;
	out = audio::int24_32_t(-15, 2) / audio::int24_32_t(3, 2);
	EXPECT_EQ(out.get(), audio::int24_32_t(-5,0).get());
}

TEST(TestInt24_32, basicOperatorIncrementPost) {
	audio::int24_32_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::int24_32_t(11, 0).get());
}

TEST(TestInt24_32, basicOperatorIncrementPre) {
	audio::int24_32_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::int24_32_t(11, 0).get());
}

TEST(TestInt24_32, basicOperatorDecrementPost) {
	audio::int24_32_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::int24_32_t(9, 0).get());
}

TEST(TestInt24_32, basicOperatorDecrementPre) {
	audio::int24_32_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::int24_32_t(9, 0).get());
}


#define RESULT_VALUE (5242880)

TEST(TestInt24_32, basicConstructorInt8_8) {
	audio::int24_32_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt8_16) {
	audio::int24_32_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt16_16) {
	audio::int24_32_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt24_24) {
	audio::int24_32_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt24_32) {
	audio::int24_32_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt16_32) {
	audio::int24_32_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt32_32) {
	audio::int24_32_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt32_64) {
	audio::int24_32_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorInt64_64) {
	audio::int24_32_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt24_32, basicConstructorFloat) {
	audio::int24_32_t out(audio::float_t(5,4));
	EXPECT_EQ(5242879.0f, out.get());
}
TEST(TestInt24_32, basicConstructorDouble) {
	audio::int24_32_t out(audio::double_t(5,4));
	EXPECT_EQ(5242879.0, out.get());
}


