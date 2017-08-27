/** @file
 * @author Edouard DUPIN 
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <audio/channel.hpp>
#include <audio/debug.hpp>
#include <etk/stdTools.hpp>

static const char* listValues[] = {
	"unknow",
	"front-left",
	"front-center",
	"front-right",
	"rear-left",
	"rear-center",
	"rear-right",
	"center-right",
	"center-center",
	"top-front-left",
	"top-front-center",
	"top-front-right",
	"top-rear-left",
	"top-rear-center",
	"top-rear-right",
	"top-center-right",
	"top-center-center",
	"lfe",
	"aux0",
	"aux1",
	"aux2",
	"aux3",
	"aux4",
	"aux5",
	"aux6",
	"aux7",
	"aux8",
	"aux9",
	"aux10",
	"aux11",
	"aux12",
	"aux13",
	"aux14",
	"aux15",
	"aux16",
	"aux17",
	"aux18",
	"aux19",
	"aux20",
	"aux21",
	"aux22",
	"aux23",
	"aux24",
	"aux25",
	"aux26",
	"aux27",
	"aux28",
	"aux29",
	"aux30",
	"aux31"
};
static int32_t listValuesSize = sizeof(listValues)/sizeof(char*);


etk::Stream& audio::operator <<(etk::Stream& _os, enum audio::channel _obj) {
	_os << getChannelString(_obj);
	return _os;
}

etk::String audio::getChannelString(enum audio::channel _value) {
	return listValues[_value];
}

etk::String audio::getChannelString(const etk::Vector<enum audio::channel>& _value) {
	etk::String out;
	for (size_t iii=0; iii<_value.size(); ++iii) {
		if (iii != 0) {
			out += ";";
		}
		out += getChannelString(_value[iii]);
	}
	return out;
}


etk::Stream& audio::operator <<(etk::Stream& _os, const etk::Vector<enum audio::channel>& _obj) {
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

etk::Stream& audio::operator <<(etk::Stream& _os, const etk::Vector<etk::Vector<enum audio::channel> >& _obj) {
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

enum audio::channel audio::getChannelFromString(const etk::String& _value) {
	for (int32_t iii=0; iii<listValuesSize; ++iii) {
		if (_value == listValues[iii]) {
			return static_cast<enum audio::channel>(iii);
		}
	}
	AUDIO_ERROR("Can not convert : '" << _value << "' ...");
	return audio::channel_unknow;
}

etk::Vector<enum audio::channel> audio::getListChannelFromString(const etk::String& _value) {
	etk::Vector<enum audio::channel> out;
	etk::Vector<etk::String> list = etk::split(_value, ';');
	for (size_t iii=0; iii<list.size(); ++iii) {
		out.pushBack(getChannelFromString(list[iii]));
	}
	return out;
}

namespace etk {
	template<> etk::String toString<enum audio::channel>(const enum audio::channel& _variable) {
		return listValues[_variable];
	}
	template <> bool from_string<enum audio::channel>(enum audio::channel& _variableRet, const etk::String& _value) {
		for (int32_t iii=0; iii<listValuesSize; ++iii) {
			if (_value == listValues[iii]) {
				_variableRet = static_cast<enum audio::channel>(iii);
				return true;
			}
		}
		_variableRet = audio::channel_unknow;
		return false;
	}
}

etk::Vector<uint8_t> audio::convertChannel(const etk::Vector<enum audio::channel>& _obj) {
	etk::Vector<uint8_t> out;
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		out.pushBack(static_cast<uint8_t>(_obj[iii]));
	}
	return out;
}

etk::Vector<enum audio::channel> audio::convertChannel(const etk::Vector<uint8_t>& _obj) {
	etk::Vector<enum audio::channel> out;
	for (size_t iii=0; iii<_obj.size(); ++iii) {
		out.pushBack(static_cast<enum audio::channel>(_obj[iii]));
	}
	return out;
}
