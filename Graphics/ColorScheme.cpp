#include "ColorScheme.h"
#include "GraphicsBuffer.h"
#include "../Error.h"
#include <algorithm>
#include "../FactoryInject.h"

namespace XCom
{

ColorScheme::ColorScheme()
{
	//nothing (all black)
}

ColorScheme::ColorScheme(unsigned long palette, unsigned long index, unsigned long size)
{
	const Palette& p = UnitTest::Inject<IGraphicsBuffer>::Resolve()->GetPalette(palette);
	switch(size)
	{
	case 5:
		mScheme[0] = p[index];
		mScheme[1] = p[index + 1];
		mScheme[2] = mScheme[3] = p[index + 2];
		mScheme[4] = p[index + 3];
		mScheme[5] = p[index + 4];
		break;
		
	default:
		for (unsigned long color = 0; color < size; ++color)
			mScheme[color] = p[index + color];
	}
}

ColorScheme::ColorScheme(const ColorScheme& rhs)
{
	operator=(rhs);
}

ColorScheme::~ColorScheme()
{
	//nothing
}

ColorScheme& ColorScheme::operator=(const ColorScheme& rhs)
{
	if (this != &rhs)
		std::copy(rhs.mScheme, rhs.mScheme + COLOR_SCHEME_SIZE, mScheme);
	return *this;
}

const Color& ColorScheme::operator[](unsigned long index) const
{
	return mScheme[index - 1];
}

Color& ColorScheme::operator[](unsigned long index)
{
	return mScheme[index - 1];
}

ColorScheme ColorScheme::GetInverse() const
{
	ColorScheme inverse(*this);
	std::reverse(inverse.mScheme, inverse.mScheme + COLOR_SCHEME_SIZE);
	return inverse;
}

const ColorScheme& ColorScheme::Get(ColorSchemeType type)
{
	static ColorScheme schemes[] = {
        ColorScheme(1, 209, 5),
        ColorScheme(0, 134, 5),
        ColorScheme(0, 240, 5),
        ColorScheme(1, 219, 5),
        ColorScheme(1, 214, 5),
        ColorScheme(1, 247, 5),
        ColorScheme(2, 16, 6),
        ColorScheme(1, 242, 5)
	};
	CheckError(type >= (sizeof(schemes) / sizeof(schemes[0])), 0, "", "Bad color scheme index.");
	return schemes[type];
}

}
