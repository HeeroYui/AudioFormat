/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/channel.h>
#include <audio/debug.h>

static const char* listValues[] = {
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

static std::vector<std::string> split(const std::string& _input, char _val) {
	std::vector<std::string> list;
	size_t lastStartPos = 0;
	for(size_t iii=0; iii<_input.size(); iii++) {
		if (_input[iii]==_val) {
			list.push_back(std::string(_input, lastStartPos, iii - lastStartPos));
			lastStartPos = iii+1;
		}
	}
	if (lastStartPos<_input.size()) {
		list.push_back(std::string(_input, lastStartPos));
	}
	return list;
}

std::vector<enum audio::channel> audio::getChannelFromString(const std::string& _value) {
	std::vector<enum audio::channel> out;
	std::vector<std::string> listIO = split(_value, ';');
	for (size_t iii=0; iii<listIO.size(); ++iii) {
		int32_t tmpCount = out.size();
		for (int32_t jjj=0; jjj<listValuesSize; ++jjj) {
			if (listIO[iii] == listValues[jjj]) {
				out.push_back(static_cast<enum audio::channel>(jjj));
				break;
			}
		}
		if (tmpCount == out.size()) {
			AUDIO_ERROR("Can not convert : '" << _value << "' ...");
		}
	}
	return out;
}
