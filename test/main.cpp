/** @file
 * @author Edouard DUPIN 
 * @copyright 2015, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <test-debug/debug.hpp>
#include <etest/etest.hpp>
#include <etk/etk.hpp>
#include <etk/os/FSNode.hpp>
extern "C" {
	#include <math.h>
}
#include <ethread/Thread.hpp>
#include <audio/types.hpp>



int main(int _argc, const char** _argv) {
	etest::init(_argc, _argv);
	for (int32_t iii=0; iii<_argc ; ++iii) {
		etk::String data = _argv[iii];
		if (    data == "-h"
		     || data == "--help") {
			TEST_INFO("Help : ");
			TEST_INFO("    ./xxx ---");
			exit(0);
		}
	}
	return RUN_ALL_TESTS();
}


