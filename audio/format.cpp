/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */

#include <audio/debug.h>
#include <audio/format.h>

static const char* listValues[] = {
	"unknow",
	"int8",
	"int8-on-int16",
	"int16",
	"int16-on-int32",
	"int24",
	"int32",
	"int32-on-int64",
	"int64",
	"float",
	"double"
};
static int32_t listValuesSize = sizeof(listValues)/sizeof(char*);

std::ostream& audio::operator <<(std::ostream& _os, enum audio::format _obj) {
	_os << getFormatString(_obj);
	return _os;
}

std::ostream& audio::operator <<(std::ostream& _os, const std::vector<enum audio::format>& _obj) {
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

std::string audio::getFormatString(enum audio::format _value) {
	return listValues[_value];
}


enum audio::format audio::getFormatFromString(const std::string& _value) {
	for (int32_t iii=0; iii<listValuesSize; ++iii) {
		if (_value == listValues[iii]) {
			return static_cast<enum audio::format>(iii);
		}
	}
	return format_unknow;
}

std::vector<enum audio::format> audio::getListFormatFromString(const std::string& _value) {
	std::vector<enum audio::format> out;
	std::vector<std::string> list = etk::split(_value, ';');
	for (auto &it : list) {
		out.push_back(getFormatFromString(it));
	}
	return out;
}

uint32_t audio::getFormatBytes(audio::format _format) {
	if (_format == audio::format_int8) {
		return sizeof(int8_t);
	} else if (_format == audio::format_int16) {
		return sizeof(int16_t);
	} else if (_format == audio::format_int16_on_int32) {
		return sizeof(int32_t);
	} else if (_format == audio::format_int24) {
		return sizeof(int32_t);
	} else if (_format == audio::format_int32) {
		return sizeof(int32_t);
	} else if (_format == audio::format_float) {
		return sizeof(float);
	} else if (_format == audio::format_double) {
		return sizeof(double);
	}
	AUDIO_ERROR("undefined format : " << _format);
	return 0;
}