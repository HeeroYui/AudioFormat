/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <test-debug/debug.hpp>
#include <etest/etest.hpp>
#include <audio/types.hpp>

TEST(TestInt64_64, basicConstructorBase) {
	audio::int64_64_t typeBase(16);
	EXPECT_EQ(typeBase.get(), 16);
}

TEST(TestInt64_64, basicConstructorSetOne) {
	// only one way to set the maximum value
	int64_t ret = 0x7FFFFFFFFFFFFFFFLL;
	audio::int64_64_t typeBase(0x7FFFFFFFFFFFFFFFLL, 63);
	EXPECT_EQ(typeBase.get(), ret);
}

TEST(TestInt64_64, basicConstructorSetLessOne) {
	audio::int64_64_t typeBase(-1, 0);
	int64_t ret =  (-(1LL<<63));
	EXPECT_EQ(typeBase.get(),ret);
}

TEST(TestInt64_64, basicOperatorEqual) {
	audio::int64_64_t typeBase;
	typeBase = 35;
	EXPECT_EQ(typeBase.get(), 35);
}

TEST(TestInt64_64, basicOperatorPlus) {
	audio::int64_64_t typeBase(35);
	typeBase += 35;
	EXPECT_EQ(typeBase.get(), 70);
}

TEST(TestInt64_64, basicOperatorMinus) {
	audio::int64_64_t typeBase(55);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), 20);
	typeBase -= 35;
	EXPECT_EQ(typeBase.get(), -15);
}

TEST(TestInt64_64, basicOperatorMultiplication) {
	audio::int64_64_t typeBase(-1, 0);
	typeBase *= 35;
	EXPECT_EQ(typeBase.get(), -35);
	typeBase = audio::double_t(0.6);
	typeBase *= audio::double_t(0.3);
	uint64_t ret = 1660206965216520438LL;
	EXPECT_EQ(typeBase.get(), ret);
}

TEST(TestInt64_64, basicOperatorCompareEquality) {
	audio::int64_64_t typeBase1(-12, 5);
	audio::int64_64_t typeBase2(-12, 5);
	bool result = typeBase1 == typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 == typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt64_64, basicOperatorCompareInEquality) {
	audio::int64_64_t typeBase1(-12, 5);
	audio::int64_64_t typeBase2(-12, 5);
	bool result = typeBase1 != typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 != typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt64_64, basicOperatorCompareMinor) {
	audio::int64_64_t typeBase1(-12, 5);
	audio::int64_64_t typeBase2(-12, 5);
	bool result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 < typeBase2;
	EXPECT_EQ(result, true);
}

TEST(TestInt64_64, basicOperatorCompareEqualityMinor) {
	audio::int64_64_t typeBase1(-12, 5);
	audio::int64_64_t typeBase2(-12, 5);
	bool result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(12, 5);
	result = typeBase1 <= typeBase2;
	EXPECT_EQ(result, true);
}


TEST(TestInt64_64, basicOperatorCompareMajor) {
	audio::int64_64_t typeBase1(-12, 5);
	audio::int64_64_t typeBase2(-12, 5);
	bool result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
	typeBase2.set(-15, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 > typeBase2;
	EXPECT_EQ(result, false);
}


TEST(TestInt64_64, basicOperatorCompareEqualityMajor) {
	audio::int64_64_t typeBase1(-12, 5);
	audio::int64_64_t typeBase2(-12, 5);
	bool result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(-15, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, true);
	typeBase2.set(12, 5);
	result = typeBase1 >= typeBase2;
	EXPECT_EQ(result, false);
}

TEST(TestInt64_64, basicOperatorLiteralPlus) {
	audio::int64_64_t out;
	out = audio::int64_64_t(-13, 5) + audio::int64_64_t(12, 5);
	EXPECT_EQ(out.get(), audio::int64_64_t(-1,5).get());
}

TEST(TestInt64_64, basicOperatorLiteralMinus) {
	audio::int64_64_t out;
	out = audio::int64_64_t(-13, 5) - audio::int64_64_t(12, 5);
	EXPECT_EQ(out.get(), audio::int64_64_t(-25,5).get());
}

TEST(TestInt64_64, basicOperatorLiteralMultiplication) {
	audio::int64_64_t out;
	out = audio::int64_64_t(-5, 3) * audio::int64_64_t(3, 3);
	EXPECT_EQ(out.get(), audio::int64_64_t(-15,6).get());
}
/*
TEST(TestInt64_64, basicOperatorDividing) {
	audio::int64_64_t out(-15, 5);
	out /= audio::int64_64_t(3, 2);
	EXPECT_EQ(out.get(), audio::int64_64_t(-5,3).get());
}

TEST(TestInt64_64, basicOperatorLiteralDividing) {
	audio::int64_64_t out;
	out = audio::int64_64_t(-15, 5) / audio::int64_64_t(3, 2);
	EXPECT_EQ(out.get(), audio::int64_64_t(-5,3).get());
}
*/

/*
TEST(TestInt64_64, basicOperatorIncrementPost) {
	audio::int64_64_t out(10, 0);
	out++;
	EXPECT_EQ(out.get(), audio::int64_64_t(11, 0).get());
}

TEST(TestInt64_64, basicOperatorIncrementPre) {
	audio::int64_64_t out(10, 0);
	++out;
	EXPECT_EQ(out.get(), audio::int64_64_t(11, 0).get());
}

TEST(TestInt64_64, basicOperatorDecrementPost) {
	audio::int64_64_t out(10, 0);
	out--;
	EXPECT_EQ(out.get(), audio::int64_64_t(9, 0).get());
}

TEST(TestInt64_64, basicOperatorDecrementPre) {
	audio::int64_64_t out(10, 0);
	--out;
	EXPECT_EQ(out.get(), audio::int64_64_t(9, 0).get());
}
*/

static const uint64_t RESULT_VALUE = (2882303761517117440LL);

TEST(TestInt64_64, basicConstructorInt8_8) {
	audio::int64_64_t out(audio::int8_8_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt8_16) {
	audio::int64_64_t out(audio::int8_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt16_16) {
	audio::int64_64_t out(audio::int16_16_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt24_24) {
	audio::int64_64_t out(audio::int24_24_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt24_32) {
	audio::int64_64_t out(audio::int24_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt16_32) {
	audio::int64_64_t out(audio::int16_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt32_32) {
	audio::int64_64_t out(audio::int32_32_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt32_64) {
	audio::int64_64_t out(audio::int32_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorInt64_64) {
	audio::int64_64_t out(audio::int64_64_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorFloat) {
	audio::int64_64_t out(audio::float_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}
TEST(TestInt64_64, basicConstructorDouble) {
	audio::int64_64_t out(audio::double_t(5,4));
	EXPECT_EQ(RESULT_VALUE, out.get());
}



