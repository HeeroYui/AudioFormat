/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_DEBUG_H__
#define __AUDIO_DEBUG_H__

#include <etk/log.h>

namespace audio {
	int32_t getLogId();
};
// TODO : Review this problem of multiple intanciation of "std::stringbuf sb"
#define AUDIO_BASE(info,data) TK_LOG_BASE(audio::getLogId(),info,data)

#define AUDIO_CRITICAL(data)      AUDIO_BASE(1, data)
#define AUDIO_ERROR(data)         AUDIO_BASE(2, data)
#define AUDIO_WARNING(data)       AUDIO_BASE(3, data)
#ifdef DEBUG
	#define AUDIO_INFO(data)          AUDIO_BASE(4, data)
	#define AUDIO_DEBUG(data)         AUDIO_BASE(5, data)
	#define AUDIO_VERBOSE(data)       AUDIO_BASE(6, data)
	#define AUDIO_TODO(data)          AUDIO_BASE(4, "TODO : " << data)
#else
	#define AUDIO_INFO(data)          do { } while(false)
	#define AUDIO_DEBUG(data)         do { } while(false)
	#define AUDIO_VERBOSE(data)       do { } while(false)
	#define AUDIO_TODO(data)          do { } while(false)
#endif

#define AUDIO_ASSERT(cond,data) \
	do { \
		if (!(cond)) { \
			AUDIO_CRITICAL(data); \
			assert(!#cond); \
		} \
	} while (0)

#endif

