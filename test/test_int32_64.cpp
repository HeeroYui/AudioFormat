/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <test-debug/debug.h>
#include <gtest/gtest.h>
#include <audio/types.h>


TEST(TestInt32_64, basicConstructorBase) {
	audio::int32_64_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt32_64, basicConstructorSetOne) {
	audio::int32_64_t typeBase(1, 0);
	EXPECT_EQ(typeBase.get(), ((1LL<<32)));
}

TEST(TestInt32_64, basicConstructorSetLessOne) {
	audio::int32_64_t typeBase(-1, 0);
	EXPECT_EQ(typeBase.get(), (-(1LL<<32)));
}

TEST(TestInt32_64, basicOperatorEqual) {
	audio::int32_64_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt32_64, basicOperatorPlus) {
	audio::int32_64_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt32_64, basicOperatorMinus) {
	audio::int32_64_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt32_64, basicOperatorMultiplication) {
	audio::int32_64_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::double_t(0.6);
	typeBase *= audio::double_t(0.3);
	EXPECT_EQ(typeBase.get(), 773094112LL);
}


TEST(TestInt32_64, basicOperatorCompareEquality) {
	audio::int32_64_t typeBase1(-12, 5);
	audio::int32_64_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt32_64, basicOperatorCompareInEquality) {
	audio::int32_64_t typeBase1(-12, 5);
	audio::int32_64_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt32_64, basicOperatorCompareMinor) {
	audio::int32_64_t typeBase1(-12, 5);
	audio::int32_64_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt32_64, basicOperatorCompareEqualityMinor) {
	audio::int32_64_t typeBase1(-12, 5);
	audio::int32_64_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestInt32_64, basicOperatorCompareMajor) {
	audio::int32_64_t typeBase1(-12, 5);
	audio::int32_64_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestInt32_64, basicOperatorCompareEqualityMajor) {
	audio::int32_64_t typeBase1(-12, 5);
	audio::int32_64_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt32_64, basicOperatorLiteralPlus) {
	audio::int32_64_t out;
	out = audio::int32_64_t(-13, 5) + audio::int32_64_t(12, 5);
	EXPECT_EQ(out.get(), audio::int32_64_t(-1,5).get());
}

TEST(TestInt32_64, basicOperatorLiteralMinus) {
	audio::int32_64_t out;
	out = audio::int32_64_t(-13, 5) - audio::int32_64_t(12, 5);
	EXPECT_EQ(out.get(), audio::int32_64_t(-25,5).get());
}

TEST(TestInt32_64, basicOperatorLiteralMultiplication) {
	audio::int32_64_t out;
	out = audio::int32_64_t(-5, 3) * audio::int32_64_t(3, 3);
	EXPECT_EQ(out.get(), audio::int32_64_t(-15,6).get());
}

TEST(TestInt32_64, basicOperatorDividing) {
	audio::int32_64_t out(-15, 2);
	out /= audio::int32_64_t(3, 2);
	EXPECT_EQ(out.get(), audio::int32_64_t(-5,0).get());
}

TEST(TestInt32_64, basicOperatorLiteralDividing) {
	audio::int32_64_t out;
	out = audio::int32_64_t(-15, 2) / audio::int32_64_t(3, 2);
	EXPECT_EQ(out.get(), audio::int32_64_t(-5,0).get());
}

TEST(TestInt32_64, basicOperatorIncrementPost) {
	audio::int32_64_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::int32_64_t(11, 0).get());
}

TEST(TestInt32_64, basicOperatorIncrementPre) {
	audio::int32_64_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::int32_64_t(11, 0).get());
}

TEST(TestInt32_64, basicOperatorDecrementPost) {
	audio::int32_64_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::int32_64_t(9, 0).get());
}

TEST(TestInt32_64, basicOperatorDecrementPre) {
	audio::int32_64_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::int32_64_t(9, 0).get());
}

#define RESULT_VALUE (1342177280LL)

TEST(TestInt32_64, basicConstructorInt8_8) {
	audio::int32_64_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt8_16) {
	audio::int32_64_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt16_16) {
	audio::int32_64_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt24_24) {
	audio::int32_64_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt24_32) {
	audio::int32_64_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt16_32) {
	audio::int32_64_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt32_32) {
	audio::int32_64_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt32_64) {
	audio::int32_64_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorInt64_64) {
	audio::int32_64_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorFloat) {
	audio::int32_64_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt32_64, basicConstructorDouble) {
	audio::int32_64_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE-1, out.get());
}


