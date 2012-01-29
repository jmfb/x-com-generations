#pragma once
#include "Color.h"

namespace XCom
{

enum ColorSchemeIndex
{
	COLOR_LIGHTER = 1,
	COLOR_LIGHT = 2,
	COLOR_BASE = 3,
	COLOR_LIGHTDARK = 4,
	COLOR_DARK = 5,
	COLOR_DARKER = 6,
	
	COLOR_SCHEME_SIZE = 6
};

enum ColorSchemeType
{
	SCHEME_WHITE,
	SCHEME_AQUA,
	SCHEME_GREEN,
	SCHEME_BLUE,
	SCHEME_DARK_YELLOW,
	SCHEME_PURPLE,
	SCHEME_YELLOW,
	SCHEME_LIGHT_MAGENTA
};

class ColorScheme
{
public:
	ColorScheme();
	ColorScheme(unsigned long palette, unsigned long index, unsigned long size);
	ColorScheme(const ColorScheme& rhs);
	~ColorScheme();
	
	ColorScheme& operator=(const ColorScheme& rhs);
	
	const Color& operator[](unsigned long index) const;
	Color& operator[](unsigned long index);
	
	ColorScheme GetInverse() const;
	
	static const ColorScheme& Get(ColorSchemeType type);
	
private:
	Color mScheme[COLOR_SCHEME_SIZE];
};

}
