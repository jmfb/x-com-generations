#include "BaseFont.h"
#include "../Error.h"

namespace XCom
{

const FontChar& BaseFont::GetChar(char ch) const
{
	auto iter = mCharMap.find(ch);
	CheckError(iter == mCharMap.end(), 0, "", "Invalid font character.");
	return iter->second;
}

void BaseFont::Register(char ch, unsigned long size, const unsigned char* data)
{
	mCharMap[ch] = FontChar(GetHeight(), size, data);
}

}
