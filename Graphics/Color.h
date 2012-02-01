#pragma once
#include <array>

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
	
	enum
	{
		COLOR_BYTES = 3
	};
	
	typedef std::array<unsigned char, COLOR_BYTES> ColorArray;
	
	void Set(unsigned char red, unsigned char green, unsigned blue);
	
	const ColorArray& GetData() const;
	
private:
	ColorArray mData;
};

}
