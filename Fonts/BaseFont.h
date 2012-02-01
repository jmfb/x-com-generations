#pragma once
#include "FontChar.h"
#include <map>

namespace XCom
{

class BaseFont
{
public:
	virtual unsigned long GetHeight() const = 0;
	
	const FontChar& GetChar(char ch) const;
	
protected:
	void Register(char ch, unsigned long size, const unsigned char* data);
	
private:
	typedef std::map<char, FontChar> FontCharMap;
	FontCharMap mCharMap;
};

}
