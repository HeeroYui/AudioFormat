#!/usr/bin/python
import monkModule as module
import monkTools as tools

def get_desc():
	return "audio : Audio basic foramt description"


def create():
	myModule = module.Module(__file__, 'audio', 'LIBRARY')
	# set documentation properties:
	myModule.set_website("http://heeroyui.github.io/audio/")
	myModule.set_website_sources("http://github.com/heeroyui/audio/")
	myModule.set_path(tools.get_current_path(__file__) + "/audio/")
	myModule.set_path_general_doc(tools.get_current_path(__file__) + "/doc/")
	# return the created description:
	return myModule

