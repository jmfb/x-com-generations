#include "FontChar.h"
#include "../Graphics/GraphicsBuffer.h"

namespace XCom
{

FontChar::FontChar()
	: mWidth(0), mHeight(0), mData(0)
{
}

FontChar::FontChar(unsigned long height, unsigned long count, const unsigned char* data)
	: mWidth(count / height), mHeight(height), mData(data)
{
}

FontChar::FontChar(const FontChar& rhs)
	: mWidth(rhs.mWidth), mHeight(rhs.mHeight), mData(rhs.mData)
{
}

FontChar::~FontChar()
{
	//nothing (we do not own the buffer)
}

FontChar& FontChar::operator=(const FontChar& rhs)
{
	if (this != &rhs)
	{
		mWidth = rhs.mWidth;
		mHeight = rhs.mHeight;
		mData = rhs.mData;
	}
	return *this;
}

unsigned long FontChar::GetWidth() const
{
	return mWidth;
}

const unsigned char* FontChar::GetData() const
{
	return mData;
}

void FontChar::Render(unsigned long x, unsigned long y, const ColorScheme& scheme) const
{
	GraphicsBuffer::Get().DrawChar(scheme, x, y, mData, mWidth, mHeight);
}

}
