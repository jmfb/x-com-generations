#pragma once
#include "BaseFont.h"
#include "FontFactory.h"
#include "../Graphics/ColorScheme.h"
#include <string>

namespace XCom
{

class Font
{
public:
	Font(FontType type);
	~Font();
	
	unsigned long GetHeight() const;
	unsigned long Measure(const std::string& str) const;
	void Render(unsigned long x, unsigned long y, const std::string& str, const ColorScheme& scheme) const;
	
private:
	const BaseFont& mFont;
	
private:
	Font(const Font& rhs);
	Font& operator=(const Font& rhs);
};

}
