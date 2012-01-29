#include "Color.h"

namespace XCom
{

Color::Color()
{
	Set(0, 0, 0);
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
{
	Set(red, green, blue);
}

Color::Color(const Color& rhs)
{
	operator=(rhs);
}

Color::~Color()
{
}

Color& Color::operator=(const Color& rhs)
{
	if (this != &rhs)
		mData = rhs.mData;
	return *this;
}

void Color::Set(unsigned char red, unsigned char green, unsigned blue)
{
	mData[0] = red;
	mData[1] = green;
	mData[2] = blue;
}

const Color::ColorArray& Color::GetData() const
{
	return mData;
}

}
