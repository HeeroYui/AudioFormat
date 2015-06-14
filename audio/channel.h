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
			channel_unknow         = audio_msg::AudioBuffer::CHANNEL_UNKNOW,
			channel_frontLeft      = audio_msg::AudioBuffer::CHANNEL_FRONT_LEFT,
			channel_frontCenter    = audio_msg::AudioBuffer::CHANNEL_FRONT_CENTER,
			channel_frontRight     = audio_msg::AudioBuffer::CHANNEL_FRONT_RIGHT,
			channel_rearLeft       = audio_msg::AudioBuffer::CHANNEL_REAR_LEFT,
			channel_rearCenter     = audio_msg::AudioBuffer::CHANNEL_REAR_CENTER,
			channel_rearRight      = audio_msg::AudioBuffer::CHANNEL_REAR_RIGHT,
			channel_centerLeft     = audio_msg::AudioBuffer::CHANNEL_CENTER_LEFT,
			channel_centerRight    = audio_msg::AudioBuffer::CHANNEL_CENTER_RIGHT,
			channel_topFrontLeft   = audio_msg::AudioBuffer::CHANNEL_TOP_FRONT_LEFT,
			channel_topFrontCenter = audio_msg::AudioBuffer::CHANNEL_TOP_FRONT_CENTER,
			channel_topFrontRight  = audio_msg::AudioBuffer::CHANNEL_TOP_FRONT_RIGHT,
			channel_topRearLeft    = audio_msg::AudioBuffer::CHANNEL_TOP_REAR_LEFT,
			channel_topRearCenter  = audio_msg::AudioBuffer::CHANNEL_TOP_REAR_CENTER,
			channel_topRearRight   = audio_msg::AudioBuffer::CHANNEL_TOP_REAR_RIGHT,
			channel_topCenterLeft  = audio_msg::AudioBuffer::CHANNEL_TOP_CENTER_LEFT,
			channel_topCenterRight = audio_msg::AudioBuffer::CHANNEL_TOP_CENTER_RIGHT,
			channel_lfe            = audio_msg::AudioBuffer::CHANNEL_LFE,
			channel_aux0           = audio_msg::AudioBuffer::CHANNEL_AUX0,
			channel_aux1           = audio_msg::AudioBuffer::CHANNEL_AUX1,
			channel_aux2           = audio_msg::AudioBuffer::CHANNEL_AUX2,
			channel_aux3           = audio_msg::AudioBuffer::CHANNEL_AUX3,
			channel_aux4           = audio_msg::AudioBuffer::CHANNEL_AUX4,
			channel_aux5           = audio_msg::AudioBuffer::CHANNEL_AUX5,
			channel_aux6           = audio_msg::AudioBuffer::CHANNEL_AUX6,
			channel_aux7           = audio_msg::AudioBuffer::CHANNEL_AUX7,
			channel_aux8           = audio_msg::AudioBuffer::CHANNEL_AUX8,
			channel_aux9           = audio_msg::AudioBuffer::CHANNEL_AUX9,
			channel_aux10          = audio_msg::AudioBuffer::CHANNEL_AUX10,
			channel_aux11          = audio_msg::AudioBuffer::CHANNEL_AUX11,
			channel_aux12          = audio_msg::AudioBuffer::CHANNEL_AUX12,
			channel_aux13          = audio_msg::AudioBuffer::CHANNEL_AUX13,
			channel_aux14          = audio_msg::AudioBuffer::CHANNEL_AUX14,
			channel_aux15          = audio_msg::AudioBuffer::CHANNEL_AUX15,
			channel_aux16          = audio_msg::AudioBuffer::CHANNEL_AUX16,
			channel_aux17          = audio_msg::AudioBuffer::CHANNEL_AUX17,
			channel_aux18          = audio_msg::AudioBuffer::CHANNEL_AUX18,
			channel_aux19          = audio_msg::AudioBuffer::CHANNEL_AUX19,
			channel_aux20          = audio_msg::AudioBuffer::CHANNEL_AUX20,
			channel_aux21          = audio_msg::AudioBuffer::CHANNEL_AUX21,
			channel_aux22          = audio_msg::AudioBuffer::CHANNEL_AUX22,
			channel_aux23          = audio_msg::AudioBuffer::CHANNEL_AUX23,
			channel_aux24          = audio_msg::AudioBuffer::CHANNEL_AUX24,
			channel_aux25          = audio_msg::AudioBuffer::CHANNEL_AUX25,
			channel_aux26          = audio_msg::AudioBuffer::CHANNEL_AUX26,
			channel_aux27          = audio_msg::AudioBuffer::CHANNEL_AUX27,
			channel_aux28          = audio_msg::AudioBuffer::CHANNEL_AUX28,
			channel_aux29          = audio_msg::AudioBuffer::CHANNEL_AUX29,
			channel_aux30          = audio_msg::AudioBuffer::CHANNEL_AUX30,
			channel_aux31          = audio_msg::AudioBuffer::CHANNEL_AUX31,
		};
	};
#else
	namespace audio {
		enum channel {
			channel_unknow, //!< Error channel ...
			// normal level
			channel_frontLeft, //!< channel Front Left
			channel_frontCenter, //!< channel Front Center
			channel_frontRight, //!< channel Front Right
			channel_rearLeft, //!< channel rear Left
			channel_rearCenter, //!< channel rear Center
			channel_rearRight, //!< channel rear Right
			channel_centerLeft, //!< channel center Left
			channel_centerRight, //!< channel center Right
			// top level
			channel_topFrontLeft, //!< channel top front left
			channel_topFrontCenter, //!< channel top front center
			channel_topFrontRight, //!< channel top front right
			channel_topRearLeft, //!< channel top rear left
			channel_topRearCenter, //!< channel top rear center
			channel_topRearRight, //!< channel top rear Right
			channel_topCenterLeft, //!< channel top center left
			channel_topCenterRight, //!< channel top center right
			// global elements
			channel_lfe, //!< channel Low frequency
			// Some user auxyliary channel (audio mixing table)
			channel_aux0,
			channel_aux1,
			channel_aux2,
			channel_aux3,
			channel_aux4,
			channel_aux5,
			channel_aux6,
			channel_aux7,
			channel_aux8,
			channel_aux9,
			channel_aux10,
			channel_aux11,
			channel_aux12,
			channel_aux13,
			channel_aux14,
			channel_aux15,
			channel_aux16,
			channel_aux17,
			channel_aux18,
			channel_aux19,
			channel_aux20,
			channel_aux21,
			channel_aux22,
			channel_aux23,
			channel_aux24,
			channel_aux25,
			channel_aux26,
			channel_aux27,
			channel_aux28,
			channel_aux29,
			channel_aux30,
			channel_aux31,
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
