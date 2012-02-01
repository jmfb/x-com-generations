#pragma once
#include "BaseFont.h"

namespace XCom
{

class FontTime : public BaseFont
{
public:
	virtual unsigned long GetHeight() const;
	
private:
	FontTime();
	FontTime(const FontTime& rhs);
	~FontTime();
	
	FontTime& operator=(const FontTime& rhs);
	
	friend class FontFactory;
};

}
