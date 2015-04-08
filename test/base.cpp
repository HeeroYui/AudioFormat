/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include "debug.h"
#include <gtest/gtest.h>
#include <audio/types.h>



TEST(TestBase, type_int8_8_t) {
	audio::int8_8_t typeBase(16, 8);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT8_MIN, 8);
	EXPECT_EQ(typeBase.get(), INT8_MIN);
	typeBase.set(INT8_MAX, 8);
	EXPECT_EQ(typeBase.get(), INT8_MAX);
	typeBase.set(INT8_MAX+200, 8);
	EXPECT_EQ(typeBase.get(), INT8_MAX);
	typeBase.set(INT8_MIN-200, 8);
	EXPECT_EQ(typeBase.get(), INT8_MIN);
	typeBase.set(-125);
	EXPECT_EQ(typeBase.get(), -125);
}

TEST(TestBase, type_int8_16_t) {
	audio::int8_16_t typeBase(16, 8);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT16_MIN, 8);
	EXPECT_EQ(typeBase.get(), INT16_MIN);
	typeBase.set(INT16_MAX, 8);
	EXPECT_EQ(typeBase.get(), INT16_MAX);
	typeBase.set(INT16_MAX+200, 8);
	EXPECT_EQ(typeBase.get(), INT16_MAX);
	typeBase.set(INT16_MIN-200, 8);
	EXPECT_EQ(typeBase.get(), INT16_MIN);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}


TEST(TestBase, type_int16_16_t) {
	audio::int16_16_t typeBase(16, 16);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT16_MIN, 16);
	EXPECT_EQ(typeBase.get(), INT16_MIN);
	typeBase.set(INT16_MAX, 16);
	EXPECT_EQ(typeBase.get(), INT16_MAX);
	typeBase.set(INT16_MAX+200, 16);
	EXPECT_EQ(typeBase.get(), INT16_MAX);
	typeBase.set(INT16_MIN-200, 16);
	EXPECT_EQ(typeBase.get(), INT16_MIN);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}

TEST(TestBase, type_int16_32_t) {
	audio::int16_32_t typeBase(16, 16);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT32_MIN, 16);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(INT32_MAX, 16);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MAX)+200, 16);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MIN)-200, 16);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}


TEST(TestBase, type_int24_24_t) {
	audio::int24_24_t typeBase(16, 24);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT24_MIN, 24);
	EXPECT_EQ(typeBase.get(), INT24_MIN);
	typeBase.set(INT24_MAX, 24);
	EXPECT_EQ(typeBase.get(), INT24_MAX);
	typeBase.set(int64_t(INT24_MAX)+200, 24);
	EXPECT_EQ(typeBase.get(), INT24_MAX);
	typeBase.set(int64_t(INT24_MIN)-200, 24);
	EXPECT_EQ(typeBase.get(), INT24_MIN);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}


TEST(TestBase, type_int24_32_t) {
	audio::int24_32_t typeBase(16, 24);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT32_MIN, 24);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(INT32_MAX, 24);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MAX)+200, 24);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MIN)-200, 24);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}

TEST(TestBase, type_int32_32_t) {
	audio::int32_32_t typeBase(16, 32);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT32_MIN, 32);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(INT32_MAX, 32);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MAX)+200, 32);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MIN)-200, 32);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}

TEST(TestBase, type_int32_64_t) {
	audio::int32_64_t typeBase(16, 32);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT64_MIN, 32);
	EXPECT_EQ(typeBase.get(), INT64_MIN);
	typeBase.set(INT64_MAX, 32);
	EXPECT_EQ(typeBase.get(), INT64_MAX);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}

TEST(TestBase, type_int64_64_t) {
	audio::int64_64_t typeBase(16, 64);
	EXPECT_EQ(typeBase.get(), 16);
	typeBase.set(INT64_MIN, 64);
	EXPECT_EQ(typeBase.get(), INT64_MIN);
	typeBase.set(INT64_MAX, 64);
	EXPECT_EQ(typeBase.get(), INT64_MAX);
	typeBase.set(-250);
	EXPECT_EQ(typeBase.get(), -250);
}

TEST(TestBase, type_float_t) {
	audio::float_t typeBase(16, 1);
	EXPECT_EQ(typeBase.get(), 16.0);
	typeBase.set(INT32_MIN, 1);
	EXPECT_EQ(typeBase.get(), INT32_MIN);
	typeBase.set(INT32_MAX, 1);
	EXPECT_EQ(typeBase.get(), INT32_MAX);
	typeBase.set(int64_t(INT32_MAX)+200, 1);
	EXPECT_EQ(typeBase.get(), 2.147483840e+09f); // Note : floating point error
	typeBase.set(int64_t(INT32_MIN)-200, 1);
	EXPECT_EQ(typeBase.get(), -2.147483904e+09f); // Note : floating point error
	typeBase.set(-250.0f);
	EXPECT_EQ(typeBase.get(), -250.0f);
}

TEST(TestBase, type_double_t) {
	audio::double_t typeBase(16, 1);
	EXPECT_EQ(int64_t(typeBase.get()), 16LL);
	EXPECT_EQ(typeBase.get(), 16.00000000745058); // Note : double point error
	typeBase.set(-250.0);
	EXPECT_EQ(typeBase.get(), -250.0);
}
