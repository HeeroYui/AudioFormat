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
		'audio/format.cpp'
		])
	
	myModule.add_module_depend(['etk'])
	myModule.add_export_path(tools.get_current_path(__file__))
	
	# add the currrent module at the 
	return myModule









