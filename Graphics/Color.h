#pragma once
#include "../constants.h"
#include <array>
#include <iostream>

namespace XCom
{

class Color
{
public:
	Color();
	Color(unsigned char red, unsigned char green, unsigned char blue);
	Color(const Color& rhs);
	~Color();
	
	Color& operator=(const Color& rhs);
	
	typedef std::array<unsigned char, COLOR_BYTES> ColorArray;
	
	void Set(unsigned char red, unsigned char green, unsigned char blue);
	
	const ColorArray& GetData() const;
	
	bool operator==(const Color& rhs) const;
	
private:
	ColorArray mData;
};

}

inline std::ostream& operator<<(std::ostream& out, const XCom::Color& rhs)
{
	auto data = rhs.GetData();
	return out << "{R:" << static_cast<unsigned long>(data[0])
		<< ",G:" << static_cast<unsigned long>(data[1])
		<< ",B:" << static_cast<unsigned long>(data[2])
		<< "}";
}
