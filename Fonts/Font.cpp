#include "Font.h"

namespace XCom
{

Font::Font(FontType type)
	: mFont(FontFactory::GetFont(type))
{
	//nothing
}

Font::~Font()
{
	//nothing
}

unsigned long Font::GetHeight() const
{
	return mFont.GetHeight();
}

unsigned long Font::Measure(const std::string& str) const
{
	unsigned long width = 0;
	for (auto iter = str.begin(), end = str.end(); iter != end; ++iter)
		width += mFont.GetChar(*iter).GetWidth() - 1;
	return width ? width + 1 : 0;
}

void Font::Render(unsigned long x, unsigned long y, const std::string& str, const ColorScheme& scheme) const
{
	if (!str.empty())
	{
		unsigned long xpos = x;
		for (auto iter = str.begin(), end = str.end(); iter != end; ++iter)
		{
			const FontChar& ch = mFont.GetChar(*iter);
			ch.Render(xpos, y, scheme);
			xpos += ch.GetWidth() - 1;
		}
	}
}

}
