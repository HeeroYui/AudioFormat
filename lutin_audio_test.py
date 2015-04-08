#!/usr/bin/python
import lutinModule as module
import lutinTools as tools
import lutinDebug as debug

def get_desc():
	return "audio_test : Basic audio types test"


def create(target):
	myModule = module.Module(__file__, 'audio_test', 'BINARY')
	myModule.add_src_file([
		'test/debug.cpp',
		'test/main.cpp',
		'test/base.cpp',
		'test/test_int16_16.cpp',
		'test/test_int16_32.cpp',
		'test/test_float.cpp'
		])
	myModule.add_module_depend(['audio', 'gtest'])
	return myModule



