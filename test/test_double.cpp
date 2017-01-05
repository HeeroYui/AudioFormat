/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <test-debug/debug.hpp>
#include <gtest/gtest.h>
#include <audio/types.hpp>


TEST(TestDouble, basicConstructorBase) {
	audio::double_t typeBase(25.0);
	EXPECT_EQ(typeBase.get(), 25.0);
}

TEST(TestDouble, basicConstructorSetOne) {
	audio::double_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), 1.0);
}

TEST(TestDouble, basicConstructorSetLessOne) {
	audio::double_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), -1.0);
}

TEST(TestDouble, basicOperatorEqual) {
	audio::double_t typeBase;
	typeBase = 35.0;
	EXPECT_EQ(typeBase.get(), 35.0);
}

TEST(TestDouble, basicOperatorPlus) {
	audio::double_t typeBase(35.0);
	typeBase += 35.0;
	EXPECT_EQ(typeBase.get(), 70.0);
}

TEST(TestDouble, basicOperatorMinus) {
	audio::double_t typeBase(55.0);
	typeBase -= 35.0;
	EXPECT_EQ(typeBase.get(), 20.0);
	typeBase -= 35.0;
	EXPECT_EQ(typeBase.get(), -15.0);
}

TEST(TestDouble, basicOperatorMultiplication) {
	audio::double_t typeBase(-1, 0);
	typeBase *= 35.0;
	EXPECT_EQ(typeBase.get(), -35.0);
	typeBase = 0.6;
	typeBase *= 0.3;
	EXPECT_EQ(typeBase.get(), 0.18);
}


TEST(TestDouble, basicOperatorCompareEquality) {
	audio::double_t typeBase1(-12, 5);
	audio::double_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestDouble, basicOperatorCompareInEquality) {
	audio::double_t typeBase1(-12, 5);
	audio::double_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestDouble, basicOperatorCompareMinor) {
	audio::double_t typeBase1(-12, 5);
	audio::double_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestDouble, basicOperatorCompareEqualityMinor) {
	audio::double_t typeBase1(-12, 5);
	audio::double_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestDouble, basicOperatorCompareMajor) {
	audio::double_t typeBase1(-12, 5);
	audio::double_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestDouble, basicOperatorCompareEqualityMajor) {
	audio::double_t typeBase1(-12, 5);
	audio::double_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestDouble, basicOperatorLiteralPlus) {
	audio::double_t out;
	out = audio::double_t(-13, 5) + audio::double_t(12, 5);
	EXPECT_EQ(out.get(), audio::double_t(-1,5).get());
}

TEST(TestDouble, basicOperatorLiteralMinus) {
	audio::double_t out;
	out = audio::double_t(-13, 5) - audio::double_t(12, 5);
	EXPECT_EQ(out.get(), audio::double_t(-25,5).get());
}

TEST(TestDouble, basicOperatorLiteralMultiplication) {
	audio::double_t out;
	out = audio::double_t(-5, 3) * audio::double_t(3, 3);
	EXPECT_EQ(out.get(), audio::double_t(-15,6).get());
}

TEST(TestDouble, basicOperatorDividing) {
	audio::double_t out(-15, 2);
	out /= audio::double_t(3, 2);
	EXPECT_EQ(out.get(), audio::double_t(-5,0).get());
}

TEST(TestDouble, basicOperatorLiteralDividing) {
	audio::double_t out;
	out = audio::double_t(-15, 2) / audio::double_t(3, 2);
	EXPECT_EQ(out.get(), audio::double_t(-5,0).get());
}

TEST(TestDouble, basicOperatorIncrementPost) {
	audio::double_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::double_t(11, 0).get());
}

TEST(TestDouble, basicOperatorIncrementPre) {
	audio::double_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::double_t(11, 0).get());
}

TEST(TestDouble, basicOperatorDecrementPost) {
	audio::double_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::double_t(9, 0).get());
}

TEST(TestDouble, basicOperatorDecrementPre) {
	audio::double_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::double_t(9, 0).get());
}


#define RESULT_VALUE (0.3125)

TEST(TestDouble, basicConstructorInt8_8) {
	audio::float_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorInt8_16) {
	audio::float_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(int32_t(RESULT_VALUE*1000.0f)+1, int32_t(out.get()*1000.0f));
}
TEST(TestDouble, basicConstructorInt16_16) {
	audio::float_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorInt24_24) {
	audio::float_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorInt24_32) {
	audio::float_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(int32_t(RESULT_VALUE*1000.0f), int32_t(out.get()*1000.0f));
}
TEST(TestDouble, basicConstructorInt16_32) {
	audio::float_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(int32_t(RESULT_VALUE*1000.0f), int32_t(out.get()*1000.0f));
}
TEST(TestDouble, basicConstructorInt32_32) {
	audio::float_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorInt32_64) {
	audio::float_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorInt64_64) {
	audio::float_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorFloat) {
	audio::float_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestDouble, basicConstructorDouble) {
	audio::float_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}


