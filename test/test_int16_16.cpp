/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <test-debug/debug.hpp>
#include <gtest/gtest.h>
#include <audio/types.hpp>



TEST(TestInt16_16, basicConstructorBase) {
	audio::int16_16_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt16_16, basicConstructorSetOne) {
	audio::int16_16_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), ((1<<15)-1));
}

TEST(TestInt16_16, basicConstructorSetLessOne) {
	audio::int16_16_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), (-(1<<15)));
}

TEST(TestInt16_16, basicOperatorEqual) {
	audio::int16_16_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt16_16, basicOperatorPlus) {
	audio::int16_16_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt16_16, basicOperatorMinus) {
	audio::int16_16_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt16_16, basicOperatorMultiplication) {
	audio::int16_16_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::double_t(0.6);
	typeBase *= audio::double_t(0.3);
	EXPECT_EQ(typeBase.get(), audio::int16_16_t(audio::double_t(0.1799856)).get());
}


TEST(TestInt16_16, basicOperatorCompareEquality) {
	audio::int16_16_t typeBase1(-12, 5);
	audio::int16_16_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt16_16, basicOperatorCompareInEquality) {
	audio::int16_16_t typeBase1(-12, 5);
	audio::int16_16_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt16_16, basicOperatorCompareMinor) {
	audio::int16_16_t typeBase1(-12, 5);
	audio::int16_16_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt16_16, basicOperatorCompareEqualityMinor) {
	audio::int16_16_t typeBase1(-12, 5);
	audio::int16_16_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestInt16_16, basicOperatorCompareMajor) {
	audio::int16_16_t typeBase1(-12, 5);
	audio::int16_16_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestInt16_16, basicOperatorCompareEqualityMajor) {
	audio::int16_16_t typeBase1(-12, 5);
	audio::int16_16_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt16_16, basicOperatorLiteralPlus) {
	audio::int16_16_t out;
	out = audio::int16_16_t(-13, 5) + audio::int16_16_t(12, 5);
	EXPECT_EQ(out.get(), audio::int16_16_t(-1,5).get());
}

TEST(TestInt16_16, basicOperatorLiteralMinus) {
	audio::int16_16_t out;
	out = audio::int16_16_t(-13, 5) - audio::int16_16_t(12, 5);
	EXPECT_EQ(out.get(), audio::int16_16_t(-25,5).get());
}

TEST(TestInt16_16, basicOperatorLiteralMultiplication) {
	audio::int16_16_t out;
	out = audio::int16_16_t(-5, 3) * audio::int16_16_t(3, 3);
	EXPECT_EQ(out.get(), audio::int16_16_t(-15,6).get());
}

TEST(TestInt16_16, basicOperatorDividing) {
	audio::int16_16_t out(-15, 5);
	out /= audio::int16_16_t(3, 2);
	EXPECT_EQ(out.get(), audio::int16_16_t(-5,3).get());
}

TEST(TestInt16_16, basicOperatorLiteralDividing) {
	audio::int16_16_t out;
	out = audio::int16_16_t(-15, 5) / audio::int16_16_t(3, 2);
	EXPECT_EQ(out.get(), audio::int16_16_t(-5,3).get());
}
/*
TEST(TestInt16_16, basicOperatorIncrementPost) {
	audio::int16_16_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::int16_16_t(11, 0).get());
}

TEST(TestInt16_16, basicOperatorIncrementPre) {
	audio::int16_16_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::int16_16_t(11, 0).get());
}

TEST(TestInt16_16, basicOperatorDecrementPost) {
	audio::int16_16_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::int16_16_t(9, 0).get());
}

TEST(TestInt16_16, basicOperatorDecrementPre) {
	audio::int16_16_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::int16_16_t(9, 0).get());
}
*/


#define RESULT_VALUE (10240)

TEST(TestInt16_16, basicConstructorInt8_8) {
	audio::int16_16_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt8_16) {
	audio::int16_16_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt16_16) {
	audio::int16_16_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt24_24) {
	audio::int16_16_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt24_32) {
	audio::int16_16_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt16_32) {
	audio::int16_16_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt32_32) {
	audio::int16_16_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt32_64) {
	audio::int16_16_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorInt64_64) {
	audio::int16_16_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorFloat) {
	audio::int16_16_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt16_16, basicConstructorDouble) {
	audio::int16_16_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
