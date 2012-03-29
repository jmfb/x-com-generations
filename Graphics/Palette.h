#pragma once
#include "IPalette.h"

namespace XCom
{

class Palette : public IPalette
{
public:
	Palette();
	Palette(const Palette& rhs) = delete;
	~Palette();
	
	Palette& operator=(const Palette& rhs) = delete;
	
	virtual void Load(const std::string& file);
	virtual void Move(unsigned long source, unsigned long size, unsigned long destination);
	
	virtual Color operator[](unsigned long index) const;
	
private:
	unsigned char* mData;
};

}
