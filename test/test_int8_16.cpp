/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>

TEST(TestInt8_16, basicConstructorBase) {
	audio::int8_16_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt8_16, basicConstructorSetOne) {
	audio::int8_16_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), ((1LL<<8)));
}

TEST(TestInt8_16, basicConstructorSetLessOne) {
	audio::int8_16_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), (-(1LL<<8)));
}

TEST(TestInt8_16, basicOperatorEqual) {
	audio::int8_16_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt8_16, basicOperatorPlus) {
	audio::int8_16_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt8_16, basicOperatorMinus) {
	audio::int8_16_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt8_16, basicOperatorMultiplication) {
	audio::int8_16_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::double_t(0.6);
	typeBase *= audio::double_t(0.3);
	EXPECT_EQ(typeBase.get(), audio::int8_16_t(audio::double_t(0.18)).get());
}


TEST(TestInt8_16, basicOperatorCompareEquality) {
	audio::int8_16_t typeBase1(-12, 5);
	audio::int8_16_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt8_16, basicOperatorCompareInEquality) {
	audio::int8_16_t typeBase1(-12, 5);
	audio::int8_16_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt8_16, basicOperatorCompareMinor) {
	audio::int8_16_t typeBase1(-12, 5);
	audio::int8_16_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt8_16, basicOperatorCompareEqualityMinor) {
	audio::int8_16_t typeBase1(-12, 5);
	audio::int8_16_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestInt8_16, basicOperatorCompareMajor) {
	audio::int8_16_t typeBase1(-12, 5);
	audio::int8_16_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestInt8_16, basicOperatorCompareEqualityMajor) {
	audio::int8_16_t typeBase1(-12, 5);
	audio::int8_16_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt8_16, basicOperatorLiteralPlus) {
	audio::int8_16_t out;
	out = audio::int8_16_t(-13, 5) + audio::int8_16_t(12, 5);
	EXPECT_EQ(out.get(), audio::int8_16_t(-1,5).get());
}

TEST(TestInt8_16, basicOperatorLiteralMinus) {
	audio::int8_16_t out;
	out = audio::int8_16_t(-13, 5) - audio::int8_16_t(12, 5);
	EXPECT_EQ(out.get(), audio::int8_16_t(-25,5).get());
}

TEST(TestInt8_16, basicOperatorLiteralMultiplication) {
	audio::int8_16_t out;
	out = audio::int8_16_t(-5, 3) * audio::int8_16_t(3, 3);
	EXPECT_EQ(out.get(), audio::int8_16_t(-15,6).get());
}

TEST(TestInt8_16, basicOperatorDividing) {
	audio::int8_16_t out(-15, 2);
	out /= audio::int8_16_t(3, 2);
	EXPECT_EQ(out.get(), audio::int8_16_t(-5,0).get());
}

TEST(TestInt8_16, basicOperatorLiteralDividing) {
	audio::int8_16_t out;
	out = audio::int8_16_t(-15, 2) / audio::int8_16_t(3, 2);
	EXPECT_EQ(out.get(), audio::int8_16_t(-5,0).get());
}

TEST(TestInt8_16, basicOperatorIncrementPost) {
	audio::int8_16_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::int8_16_t(11, 0).get());
}

TEST(TestInt8_16, basicOperatorIncrementPre) {
	audio::int8_16_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::int8_16_t(11, 0).get());
}

TEST(TestInt8_16, basicOperatorDecrementPost) {
	audio::int8_16_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::int8_16_t(9, 0).get());
}

TEST(TestInt8_16, basicOperatorDecrementPre) {
	audio::int8_16_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::int8_16_t(9, 0).get());
}



#define RESULT_VALUE (80)

TEST(TestInt8_16, basicConstructorInt8_8) {
	audio::int8_16_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt8_16) {
	audio::int8_16_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt16_16) {
	audio::int8_16_t out(audio::int16_16_t(5,4));
	APPL_INFO(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt24_24) {
	audio::int8_16_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt24_32) {
	audio::int8_16_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt16_32) {
	audio::int8_16_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt32_32) {
	audio::int8_16_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt32_64) {
	audio::int8_16_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorInt64_64) {
	audio::int8_16_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorFloat) {
	audio::int8_16_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt8_16, basicConstructorDouble) {
	audio::int8_16_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}

