#!/usr/bin/python
import lutin.debug as debug
import lutin.tools as tools


def get_type():
	return "BINARY"

def get_sub_type():
	return "TEST"

def get_desc():
	return "Basic audio types test"

def get_licence():
	return "MPL-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def configure(target, my_module):
	my_module.add_src_file([
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
	my_module.add_depend([
	    'audio',
	    'etest',
	    'test-debug'
	    ])
	return True



