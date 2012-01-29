#pragma once
#include "BaseFont.h"

namespace XCom
{

class FontUpDown : public BaseFont
{
public:
	virtual unsigned long GetHeight() const;

private:
	FontUpDown();
	FontUpDown(const FontUpDown& rhs);
	~FontUpDown();
	
	FontUpDown& operator=(const FontUpDown& rhs);
	
	friend class FontFactory;
};

}
