#pragma once
#include "BaseFont.h"

namespace XCom
{

enum FontType
{
	FONT_NORMAL,
	FONT_LARGE,
	FONT_TIME,
	FONT_SMALL,
	FONT_ARROW,
	FONT_UPDOWN
};

class FontFactory
{
public:
	static const BaseFont& GetFont(FontType type);
};

}
