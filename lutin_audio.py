#!/usr/bin/python
import lutinModule as module
import lutinTools as tools
import lutinDebug as debug

def get_desc():
	return "audio : Basic audio types"


def create(target):
	myModule = module.Module(__file__, 'audio', 'LIBRARY')
	myModule.add_src_file([
		'audio/debug.cpp',
		'audio/channel.cpp',
		'audio/format.cpp',
		'audio/int8_8_t.cpp',
		'audio/int8_16_t.cpp',
		'audio/int16_16_t.cpp',
		'audio/int16_32_t.cpp',
		'audio/int24_24_t.cpp',
		'audio/int24_32_t.cpp',
		'audio/int32_32_t.cpp',
		'audio/int32_64_t.cpp',
		'audio/int64_64_t.cpp',
		'audio/float_t.cpp',
		'audio/double_t.cpp'
		])
	myModule.add_module_depend(['etk'])
	myModule.add_export_path(tools.get_current_path(__file__))
	return myModule

