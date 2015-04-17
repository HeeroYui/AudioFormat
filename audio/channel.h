/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#ifndef __AUDIO_CHANNEL_H__
#define __AUDIO_CHANNEL_H__

#include <string>
#include <vector>
#include <etk/types.h>

#ifdef ETK_EXTERN_FRAMEWORK_ROS
	#include <ros/ros.h>
	#include "audio_msg/AudioBuffer.h"
	namespace audio {
		enum channel {
			channel_unknow        = audio_msg::AudioBuffer::CHANNEL_UNKNOW,
			channel_frontLeft     = audio_msg::AudioBuffer::CHANNEL_FRONT_LEFT,
			channel_frontCenter   = audio_msg::AudioBuffer::CHANNEL_FRONT_CENTER,
			channel_frontRight    = audio_msg::AudioBuffer::CHANNEL_FRONT_RIGHT,
			channel_rearLeft      = audio_msg::AudioBuffer::CHANNEL_REAR_LEFT,
			channel_rearCenter    = audio_msg::AudioBuffer::CHANNEL_REAR_CENTER,
			channel_rearRight     = audio_msg::AudioBuffer::CHANNEL_REAR_RIGHT,
			channel_surroundLeft  = audio_msg::AudioBuffer::CHANNEL_SURROUND_LEFT,
			channel_surroundRight = audio_msg::AudioBuffer::CHANNEL_SURROUND_RIGHT,
			channel_subWoofer     = audio_msg::AudioBuffer::CHANNEL_SUBWOOFER,
			channel_lfe           = audio_msg::AudioBuffer::CHANNEL_LFE
		};
	};
#else
	namespace audio {
		enum channel {
			channel_unknow, //!< Error channel ...
			channel_frontLeft, //!< channel Front Left
			channel_frontCenter, //!< channel Front Center
			channel_frontRight, //!< channel Front Right
			channel_rearLeft, //!< channel rear Left
			channel_rearCenter, //!< channel rear Center
			channel_rearRight, //!< channel rear Right
			channel_surroundLeft, //!< channel surround Left
			channel_surroundRight, //!< channel surround Right
			channel_subWoofer, //!< channel Sub-woofer
			channel_lfe, //!< channel Low frequency
		};
	};
#endif
namespace audio {
	std::string getChannelString(enum audio::channel _obj);
	std::string getChannelString(const std::vector<enum audio::channel>& _obj);
	enum audio::channel getChannelFromString(const std::string& _value);
	std::vector<enum audio::channel> getListChannelFromString(const std::string& _value);
	std::ostream& operator <<(std::ostream& _os, enum audio::channel _obj);
	std::ostream& operator <<(std::ostream& _os, const std::vector<enum audio::channel>& _obj);
	std::ostream& operator <<(std::ostream& _os, const std::vector<std::vector<enum audio::channel> >& _obj);
	// For ROS Interface:
	std::vector<uint8_t> convertChannel(const std::vector<enum audio::channel>& _obj);
	std::vector<enum audio::channel> convertChannel(const std::vector<uint8_t>& _obj);
};


#endif
