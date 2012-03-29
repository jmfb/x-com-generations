#include "ColorScheme.h"
#include <algorithm>
#include "../Error.h"

namespace XCom
{

ColorScheme::ColorScheme()
{
	//nothing (all black)
}

ColorScheme::ColorScheme(const IPalette& palette, unsigned long index, unsigned long size)
{
	switch(size)
	{
	case 5:
		mScheme[0] = palette[index];
		mScheme[1] = palette[index + 1];
		mScheme[2] = mScheme[3] = palette[index + 2];
		mScheme[4] = palette[index + 3];
		mScheme[5] = palette[index + 4];
		break;
		
	case 6:
		for (unsigned long color = 0; color < size; ++color)
			mScheme[color] = palette[index + color];
		break;
		
	default:
		RaiseError(0, "size", "Palette size must be 5 or 6.");
	}
}

ColorScheme::~ColorScheme()
{
	//nothing
}

const Color& ColorScheme::operator[](unsigned long index) const
{
	CheckError(index == 0 || index > COLOR_SCHEME_SIZE, 0, "index", "Index out of range.");
	return mScheme[index - 1];
}

Color& ColorScheme::operator[](unsigned long index)
{
	CheckError(index == 0 || index > COLOR_SCHEME_SIZE, 0, "index", "Index out of range.");
	return mScheme[index - 1];
}

ColorScheme ColorScheme::GetInverse() const
{
	ColorScheme inverse(*this);
	std::reverse(inverse.mScheme.begin(), inverse.mScheme.end());
	return inverse;
}

const ColorScheme& ColorScheme::Get(IGraphicsBufferPtr graphics, ColorSchemeType type)
{
	static ColorScheme schemes[] = {
        ColorScheme(graphics->GetPalette(1), 209, 5),
        ColorScheme(graphics->GetPalette(0), 134, 5),
        ColorScheme(graphics->GetPalette(0), 240, 5),
        ColorScheme(graphics->GetPalette(1), 219, 5),
        ColorScheme(graphics->GetPalette(1), 214, 5),
        ColorScheme(graphics->GetPalette(1), 247, 5),
        ColorScheme(graphics->GetPalette(2), 16, 6),
        ColorScheme(graphics->GetPalette(1), 242, 5)
	};
	CheckError(type >= (sizeof(schemes) / sizeof(schemes[0])), 0, "type", "Bad color scheme index.");
	return schemes[type];
}

}
