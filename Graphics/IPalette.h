#pragma once
#include <memory>
#include <string>
#include "Color.h"

namespace XCom
{

class IPalette
{
public:
	virtual ~IPalette()
	{
	}
	
	virtual void Load(const std::string& file) = 0;
	virtual void Move(unsigned long source, unsigned long size, unsigned long destination) = 0;
	
	virtual Color operator[](unsigned long index) const = 0;
};

typedef std::shared_ptr<IPalette> IPalettePtr;

}
