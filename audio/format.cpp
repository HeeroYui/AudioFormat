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
	"int16",
	"int16_on_int32",
	"int24",
	"int32",
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