/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/debug.hpp>
#include <audio/format.hpp>
#include <etk/stdTools.hpp>

static const char* listValues[] = {
	"unknow",
	"int8",
	"int8-on-int16",
	"int16",
	"int16-on-int32",
	"int24",
	"int24-on-int32",
	"int32",
	"int32-on-int64",
	"int64",
	"float",
	"double"
};
static int32_t listValuesSize = sizeof(listValues)/sizeof(char*);

etk::Stream& audio::operator <<(etk::Stream& _os, enum audio::format _obj) {
	_os << getFormatString(_obj);
	return _os;
}

etk::Stream& audio::operator <<(etk::Stream& _os, const etk::Vector<enum audio::format>& _obj) {
	_os << etk::String("{");
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		if (iii!=0) {
			_os << etk::String(";");
		}
		_os << _obj[iii];
	}
	_os << etk::String("}");
	return _os;
}

etk::String audio::getFormatString(enum audio::format _value) {
	return listValues[_value];
}


enum audio::format audio::getFormatFromString(const etk::String& _value) {
	for (int32_t iii=0; iii<listValuesSize; ++iii) {
		if (_value == listValues[iii]) {
			return static_cast<enum audio::format>(iii);
		}
	}
	return format_unknow;
}

etk::Vector<enum audio::format> audio::getListFormatFromString(const etk::String& _value) {
	etk::Vector<enum audio::format> out;
	etk::Vector<etk::String> list = etk::split(_value, ';');
	for (size_t iii=0; iii<list.size(); ++iii) {
		out.pushBack(getFormatFromString(list[iii]));
	}
	return out;
}

uint32_t audio::getFormatBytes(audio::format _format) {
	switch(_format) {
		case audio::format_unknow:
			return 1;
		case audio::format_int8:
			return sizeof(int8_t);
		case audio::format_int8_on_int16:
		case audio::format_int16:
			return sizeof(int16_t);
		case audio::format_int24:
			return 3;
		case audio::format_int16_on_int32:
		case audio::format_int24_on_int32:
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
	template<> etk::String toString<enum audio::format>(const enum audio::format& _variable) {
		return listValues[_variable];
	}
	template <> bool from_string<enum audio::format>(enum audio::format& _variableRet, const etk::String& _value) {
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

etk::Vector<uint8_t> audio::convertFormat(const etk::Vector<enum audio::format>& _obj) {
	etk::Vector<uint8_t> out;
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		out.pushBack(static_cast<uint8_t>(_obj[iii]));
	}
	return out;
}

etk::Vector<enum audio::format> audio::convertFormat(const etk::Vector<uint8_t>& _obj) {
	etk::Vector<enum audio::format> out;
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		out.pushBack(static_cast<enum audio::format>(_obj[iii]));
	}
	return out;
}

uint8_t audio::convertFormat(enum audio::format _obj) {
	return static_cast<uint8_t>(_obj);
}

enum audio::format audio::convertFormat(uint8_t _obj) {
	return static_cast<enum audio::format>(_obj);
}
