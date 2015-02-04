/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>


int32_t audio::getLogId() {
	static int32_t g_val = etk::log::registerInstance("audio");
	return g_val;
}
