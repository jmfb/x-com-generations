#pragma once
#include "Color.h"
#include <string>

namespace XCom
{

class Palette
{
public:
	Palette();
	Palette(const Palette& rhs);
	~Palette();
	
	Palette& operator=(const Palette& rhs);
	
	void Load(const std::string& file);
	void Move(unsigned long source, unsigned long size, unsigned long destination);
	
	Color operator[](unsigned long index) const;
	
private:
	unsigned char* mData;
};

}
