/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/channel.h>
#include <audio/debug.h>
#include <etk/stdTools.h>

static const char* listValues[] = {
	"unknow",
	"front-left",
	"front-center",
	"front-right",
	"rear-left",
	"rear-center",
	"rear-right",
	"surround-left",
	"surround-right",
	"sub-woofer",
	"lfe"
};
static int32_t listValuesSize = sizeof(listValues)/sizeof(char*);


std::ostream& audio::operator <<(std::ostream& _os, enum audio::channel _obj) {
	_os << getChannelString(_obj);
	return _os;
}

std::string audio::getChannelString(enum audio::channel _value) {
	return listValues[_value];
}

std::string audio::getChannelString(const std::vector<enum audio::channel>& _value) {
	std::string out;
	for (size_t iii=0; iii<_value.size(); ++iii) {
		if (iii != 0) {
			out += ";";
		}
		out += getChannelString(_value[iii]);
	}
	return out;
}


std::ostream& audio::operator <<(std::ostream& _os, const std::vector<enum audio::channel>& _obj) {
	_os << std::string("{");
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		if (iii!=0) {
			_os << std::string(";");
		}
		_os << _obj[iii];
	}
	_os << std::string("}");
	return _os;
}

std::ostream& audio::operator <<(std::ostream& _os, const std::vector<std::vector<enum audio::channel>>& _obj) {
	_os << std::string("{");
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		if (iii!=0) {
			_os << std::string(";");
		}
		_os << _obj[iii];
	}
	_os << std::string("}");
	return _os;
}

enum audio::channel audio::getChannelFromString(const std::string& _value) {
	for (int32_t iii=0; iii<listValuesSize; ++iii) {
		if (_value == listValues[iii]) {
			return static_cast<enum audio::channel>(iii);
		}
	}
	AUDIO_ERROR("Can not convert : '" << _value << "' ...");
	return audio::channel_unknow;
}

std::vector<enum audio::channel> audio::getListChannelFromString(const std::string& _value) {
	std::vector<enum audio::channel> out;
	std::vector<std::string> list = etk::split(_value, ';');
	for (auto &it : list) {
		out.push_back(getChannelFromString(it));
	}
	return out;
}
