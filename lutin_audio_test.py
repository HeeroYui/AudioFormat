#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools

def get_desc():
	return "audio_test : Basic audio types test"


def create(target):
	myModule = module.Module(__file__, 'audio_test', 'BINARY')
	myModule.add_src_file([
		'test/debug.cpp',
		'test/base.cpp',
		'test/main.cpp',
		'test/test_double.cpp',
		'test/test_float.cpp',
		'test/test_int16_16.cpp',
		'test/test_int16_32.cpp',
		'test/test_int24_24.cpp',
		'test/test_int24_32.cpp',
		'test/test_int32_32.cpp',
		'test/test_int32_64.cpp',
		'test/test_int64_64.cpp',
		'test/test_int8_16.cpp',
		'test/test_int8_8.cpp'
		])
	myModule.add_module_depend(['audio', 'gtest'])
	return myModule



