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
	for (size_t iii=0; iii<list.size(); ++iii) {
		out.push_back(getFormatFromString(list[iii]));
	}
	return out;
}

uint32_t audio::getFormatBytes(audio::format _format) {
	switch(_format) {
		case audio::format_int8:
			return sizeof(int8_t);
		case audio::format_int8_on_int16:
		case audio::format_int16:
			return sizeof(int16_t);
		case audio::format_int16_on_int32:
		case audio::format_int24:
		case audio::format_int32:
			return sizeof(int32_t);
		case audio::format_int32_on_int64:
		case  audio::format_int64:
			return sizeof(int64_t);
		case audio::format_float:
			return sizeof(float);
		case audio::format_double:
			return sizeof(double);
	}
	AUDIO_ERROR("undefined format : " << _format);
	return 0;
}


namespace etk {
	template<> std::string to_string<enum audio::format>(const enum audio::format& _variable) {
		return listValues[_variable];
	}
	template <> bool from_string<enum audio::format>(enum audio::format& _variableRet, const std::string& _value) {
		for (int32_t iii=0; iii<listValuesSize; ++iii) {
			if (_value == listValues[iii]) {
				_variableRet = static_cast<enum audio::format>(iii);
				return true;
			}
		}
		_variableRet = audio::format_unknow;
		return false;
	}
}

std::vector<uint8_t> audio::convertFormat(const std::vector<enum audio::format>& _obj) {
	std::vector<uint8_t> out;
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		out.push_back(static_cast<uint8_t>(_obj[iii]));
	}
	return out;
}

std::vector<enum audio::format> audio::convertFormat(const std::vector<uint8_t>& _obj) {
	std::vector<enum audio::format> out;
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		out.push_back(static_cast<enum audio::format>(_obj[iii]));
	}
	return out;
}

uint8_t audio::convertFormat(enum audio::format _obj) {
	return static_cast<uint8_t>(_obj);
}

enum audio::format audio::convertFormat(uint8_t _obj) {
	return static_cast<enum audio::format>(_obj);
}
