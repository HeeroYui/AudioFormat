/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>


TEST(TestInt32_32, basicConstructorBase) {
	audio::int32_32_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt32_32, basicConstructorSetOne) {
	audio::int32_32_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), ((1LL<<31)-1));
}

TEST(TestInt32_32, basicConstructorSetLessOne) {
	audio::int32_32_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), (-(1LL<<31)));
}

TEST(TestInt32_32, basicOperatorEqual) {
	audio::int32_32_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt32_32, basicOperatorPlus) {
	audio::int32_32_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt32_32, basicOperatorMinus) {
	audio::int32_32_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt32_32, basicOperatorMultiplication) {
	audio::int32_32_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::double_t(0.6);
	typeBase *= audio::double_t(0.3);
	EXPECT_EQ(typeBase.get(), audio::int32_32_t(audio::double_t(0.18)).get());
}


TEST(TestInt32_32, basicOperatorCompareEquality) {
	audio::int32_32_t typeBase1(-12, 5);
	audio::int32_32_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt32_32, basicOperatorCompareInEquality) {
	audio::int32_32_t typeBase1(-12, 5);
	audio::int32_32_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt32_32, basicOperatorCompareMinor) {
	audio::int32_32_t typeBase1(-12, 5);
	audio::int32_32_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt32_32, basicOperatorCompareEqualityMinor) {
	audio::int32_32_t typeBase1(-12, 5);
	audio::int32_32_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestInt32_32, basicOperatorCompareMajor) {
	audio::int32_32_t typeBase1(-12, 5);
	audio::int32_32_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestInt32_32, basicOperatorCompareEqualityMajor) {
	audio::int32_32_t typeBase1(-12, 5);
	audio::int32_32_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt32_32, basicOperatorLiteralPlus) {
	audio::int32_32_t out;
	out = audio::int32_32_t(-13, 5) + audio::int32_32_t(12, 5);
	EXPECT_EQ(out.get(), audio::int32_32_t(-1,5).get());
}

TEST(TestInt32_32, basicOperatorLiteralMinus) {
	audio::int32_32_t out;
	out = audio::int32_32_t(-13, 5) - audio::int32_32_t(12, 5);
	EXPECT_EQ(out.get(), audio::int32_32_t(-25,5).get());
}

TEST(TestInt32_32, basicOperatorLiteralMultiplication) {
	audio::int32_32_t out;
	out = audio::int32_32_t(-5, 3) * audio::int32_32_t(3, 3);
	EXPECT_EQ(out.get(), audio::int32_32_t(-15,6).get());
}

TEST(TestInt32_32, basicOperatorDividing) {
	audio::int32_32_t out(-15, 5);
	out /= audio::int32_32_t(3, 2);
	EXPECT_EQ(out.get(), audio::int32_32_t(-5,3).get());
}

TEST(TestInt32_32, basicOperatorLiteralDividing) {
	audio::int32_32_t out;
	out = audio::int32_32_t(-15, 5) / audio::int32_32_t(3, 2);
	EXPECT_EQ(out.get(), audio::int32_32_t(-5,3).get());
}
/*
TEST(TestInt32_32, basicOperatorIncrementPost) {
	audio::int32_32_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::int32_32_t(11, 0).get());
}

TEST(TestInt32_32, basicOperatorIncrementPre) {
	audio::int32_32_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::int32_32_t(11, 0).get());
}

TEST(TestInt32_32, basicOperatorDecrementPost) {
	audio::int32_32_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::int32_32_t(9, 0).get());
}

TEST(TestInt32_32, basicOperatorDecrementPre) {
	audio::int32_32_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::int32_32_t(9, 0).get());
}
*/


#define RESULT_VALUE (671088640)

TEST(TestInt32_32, basicConstructorInt8_8) {
	audio::int32_32_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt8_16) {
	audio::int32_32_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt16_16) {
	audio::int32_32_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt24_24) {
	audio::int32_32_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt24_32) {
	audio::int32_32_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt16_32) {
	audio::int32_32_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt32_32) {
	audio::int32_32_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt32_64) {
	audio::int32_32_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorInt64_64) {
	audio::int32_32_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorFloat) {
	audio::int32_32_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_32, basicConstructorDouble) {
	audio::int32_32_t out(audio::double_t(5,4));
	EXPECT_EQ(671088639, out.get());
}

