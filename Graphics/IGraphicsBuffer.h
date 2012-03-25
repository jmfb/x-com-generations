#pragma once
#include "Color.h"
#include "ColorScheme.h"
#include "Palette.h"
#include "ImageType.h"
#include "Background.h"
#include <memory>

namespace XCom
{

class IGraphicsBuffer
{
public:
	virtual ~IGraphicsBuffer()
	{
	}
	
	enum PixelOperation
	{
		Set,
		Or
	};

	virtual void SetBrush(const Color& color, PixelOperation operation = Set) = 0;
	
	virtual void DrawHorizontalLine(unsigned long x, unsigned long y, unsigned long cx) = 0;
	virtual void DrawVerticalLine(unsigned long x, unsigned long y, unsigned long cy) = 0;
	virtual void DrawPoint(unsigned long x, unsigned long y) = 0;
	virtual void DrawFrame(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy) = 0;
	virtual void DrawRect(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy) = 0;
	
	virtual void DrawImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long width, unsigned long height,
		unsigned long paletteIndex, unsigned long paletteOffset) = 0;
	
	virtual void DrawImageFromFile(
		unsigned long x, unsigned long y,
		ImageType imageIndex) = 0;
	
	virtual void DrawMaskedImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long sourceWidth, unsigned long sourceHeight) = 0;
	
	virtual void DrawBackground(
		unsigned long x, unsigned long y,
		unsigned long width, unsigned long height,
		BackgroundType backgroundIndex,
		unsigned long paletteIndex) = 0;
	
	virtual void DrawPaletteImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long sourceWidth, unsigned long sourceHeight,
		unsigned long paletteIndex) = 0;
	
	virtual void DrawChar(
		const ColorScheme& scheme,
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long width, unsigned long height) = 0;
	
	virtual const Palette& GetPalette(unsigned long index) const = 0;

	virtual void Commit() = 0;
};

typedef std::shared_ptr<IGraphicsBuffer> IGraphicsBufferPtr;

}
