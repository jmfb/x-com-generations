#pragma once
#include "BaseFont.h"

namespace XCom
{

class FontNormal : public BaseFont
{
public:
	virtual unsigned long GetHeight() const;
	
private:
	FontNormal();
	FontNormal(const FontNormal& rhs);
	~FontNormal();
	
	FontNormal& operator=(const FontNormal& rhs);
	
	friend class FontFactory;
};

}
