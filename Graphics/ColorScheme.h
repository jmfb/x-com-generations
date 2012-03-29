#pragma once
#include <array>
#include "Color.h"
#include "IPalette.h"
#include "IGraphicsBuffer.h"
#include "ColorSchemeIndex.h"
#include "ColorSchemeType.h"

namespace XCom
{

class ColorScheme
{
public:
	ColorScheme();
	ColorScheme(const IPalette& palette, unsigned long index, unsigned long size);
	ColorScheme(const ColorScheme& rhs) = default;
	~ColorScheme();
	
	ColorScheme& operator=(const ColorScheme& rhs) = default;
	
	const Color& operator[](unsigned long index) const;
	Color& operator[](unsigned long index);
	
	ColorScheme GetInverse() const;
	
	static const ColorScheme& Get(IGraphicsBufferPtr graphics, ColorSchemeType type);
	
private:
	std::array<Color, COLOR_SCHEME_SIZE> mScheme;
};

}
