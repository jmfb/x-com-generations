#pragma once
#include <functional>
#include "Color.h"
#include "Palette.h"
#include "ColorScheme.h"
#include "Background.h"
#include "Image.h"

namespace XCom
{

class GraphicsBuffer
{
public:
	static GraphicsBuffer& Get();
	
	enum PixelOperation
	{
		Set,
		Or
	};
	
	void SetBrush(const Color& color, PixelOperation operation = Set);
	
	void DrawHorizontalLine(unsigned long x, unsigned long y, unsigned long cx);
	void DrawVerticalLine(unsigned long x, unsigned long y, unsigned long cy);
	void DrawPoint(unsigned long x, unsigned long y);
	void DrawFrame(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy);
	void DrawRect(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy);
	
	void DrawImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long width, unsigned long height,
		unsigned long paletteIndex, unsigned long paletteOffset);
	
	void DrawImageFromFile(
		unsigned long x, unsigned long y,
		ImageType imageIndex);
	
	void DrawMaskedImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long sourceWidth, unsigned long sourceHeight);
	
	void DrawBackground(
		unsigned long x, unsigned long y,
		unsigned long width, unsigned long height,
		BackgroundType backgroundIndex,
		unsigned long paletteIndex);
	
	void DrawPaletteImage(
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long imageWidth, unsigned long imageHeight,
		unsigned long sourceX, unsigned long sourceY,
		unsigned long sourceWidth, unsigned long sourceHeight,
		unsigned long paletteIndex);
	
	void DrawChar(
		const ColorScheme& scheme,
		unsigned long x, unsigned long y,
		const unsigned char* image,
		unsigned long width, unsigned long height);
	
	enum
	{
		NORMAL_PALETTE_COUNT = 5,
		BACK_PALETTE_COUNT = 1,
		SPECIAL_PALETTE_COUNT = 8,
		PALETTE_COUNT = NORMAL_PALETTE_COUNT + BACK_PALETTE_COUNT + SPECIAL_PALETTE_COUNT
	};
	
	const Palette& GetPalette(unsigned long index) const;
	
private:
	GraphicsBuffer(
		unsigned long gameWidth,
		unsigned long gameHeight,
		unsigned long targetWidth,
		unsigned long targetHeight,
		const std::function<void(unsigned char*)>& commit);
	GraphicsBuffer(const GraphicsBuffer& rhs);
	~GraphicsBuffer();
	
	GraphicsBuffer& operator=(const GraphicsBuffer& rhs);

	void Commit();
	void LoadImages();
	
	friend class Application;
	
	static GraphicsBuffer* mThis;

	unsigned long mGameWidth;
	unsigned long mGameHeight;
	unsigned long mSize;
	unsigned long mTargetWidth;
	unsigned long mTargetHeight;
	unsigned char* mData;
	unsigned char* mScaledData;
	std::function<void(unsigned char*)> mCommit;
	Color mColor;
	PixelOperation mOperation;
	Palette mPalettes[PALETTE_COUNT];
	Background mBackgrounds[BACK_COUNT];
	Image mImages[IMAGE_COUNT];
};

}
