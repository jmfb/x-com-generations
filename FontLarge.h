#pragma once
#include "BaseFont.h"

namespace XCom
{

class FontLarge : public BaseFont
{
public:
	virtual unsigned long GetHeight() const;
	
private:
	FontLarge();
	FontLarge(const FontLarge& rhs);
	~FontLarge();
	
	FontLarge& operator=(const FontLarge& rhs);
	
	friend class FontFactory;
};

}
