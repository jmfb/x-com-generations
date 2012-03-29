#pragma once
#include "../Singleton.h"
#include "Color.h"
#include "IPalette.h"
#include "ColorScheme.h"
#include "Background.h"
#include "ImageType.h"
#include "Image.h"
#include "IGraphicsBuffer.h"

namespace XCom
{

class GraphicsBuffer : public IGraphicsBuffer
{
public:
	GraphicsBuffer();
	GraphicsBuffer(const GraphicsBuffer& rhs) = delete;
	~GraphicsBuffer();

	GraphicsBuffer& operator=(const GraphicsBuffer& rhs) = delete;
	
	virtual void SetBrush(const Color& color, PixelOperation operation = Set);
	
	virtual void DrawHorizontalLine(unsigned long x, unsigned long y, unsigned long cx);
	virtual void DrawVerticalLine(unsigned long x, unsigned long y, unsigned long cy);
	virtual void DrawPoint(unsigned long x, unsigned long y);
	virtual void DrawFrame(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy);
	virtual void DrawRect(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy);
	
	virtual void DrawImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long width, unsigned long height,
		unsigned long paletteIndex, unsigned long paletteOffset);
	
	virtual void DrawImageFromFile(
		unsigned long x, unsigned long y,
		ImageType imageIndex);
	
	virtual void DrawMaskedImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long sourceWidth, unsigned long sourceHeight);
	
	virtual void DrawBackground(
		unsigned long x, unsigned long y,
		unsigned long width, unsigned long height,
		BackgroundType backgroundIndex,
		unsigned long paletteIndex);
	
	virtual void DrawPaletteImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long sourceWidth, unsigned long sourceHeight,
		unsigned long paletteIndex);
	
	virtual void DrawChar(
		const ColorScheme& scheme,
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long width, unsigned long height);
	
	virtual const IPalette& GetPalette(unsigned long index) const;

	virtual void Commit();

private:
	void LoadImages();

	enum
	{
		NORMAL_PALETTE_COUNT = 5,
		BACK_PALETTE_COUNT = 1,
		SPECIAL_PALETTE_COUNT = 8,
		PALETTE_COUNT = NORMAL_PALETTE_COUNT + BACK_PALETTE_COUNT + SPECIAL_PALETTE_COUNT
	};

	unsigned long mSize;
	unsigned char* mData;
	unsigned char* mScaledData;
	Color mColor;
	PixelOperation mOperation;
	IPalettePtr mPalettes[PALETTE_COUNT];
	Background mBackgrounds[BACK_COUNT];
	Image mImages[IMAGE_COUNT];
};

}
