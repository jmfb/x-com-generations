#pragma once
#include "BaseFont.h"

namespace XCom
{

class FontSmall : public BaseFont
{
public:
	virtual unsigned long GetHeight() const;
	
private:
	FontSmall();
	FontSmall(const FontSmall& rhs);
	~FontSmall();
	
	FontSmall& operator=(const FontSmall& rhs);
	
	friend class FontFactory;
};

}
