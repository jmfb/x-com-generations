#pragma once
#include "ColorScheme.h"

namespace XCom
{

class FontChar
{
public:
	FontChar();
	FontChar(unsigned long height, unsigned long count, const unsigned char* data);
	FontChar(const FontChar& rhs);
	~FontChar();
	
	FontChar& operator=(const FontChar& rhs);
	
	unsigned long GetWidth() const;
	const unsigned char* GetData() const;
	void Render(unsigned long x, unsigned long y, const ColorScheme& scheme) const;

private:
	unsigned long mWidth;
	unsigned long mHeight;
	const unsigned char* mData;
};

}
