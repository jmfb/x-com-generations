#pragma once
#include "BaseFont.h"

namespace XCom
{

class FontArrow : public BaseFont
{
public:
	virtual unsigned long GetHeight() const;
	
private:
	FontArrow();
	FontArrow(const FontArrow& rhs);
	~FontArrow();
	
	FontArrow& operator=(const FontArrow& rhs);
	
	friend class FontFactory;
};

}
