#include "GraphicsBuffer.h"
#include "Error.h"
#include <cstring>

namespace XCom
{

GraphicsBuffer* GraphicsBuffer::mThis = 0;

GraphicsBuffer::GraphicsBuffer(
	unsigned long gameWidth,
	unsigned long gameHeight,
	unsigned long targetWidth,
	unsigned long targetHeight,
	const std::function<void(unsigned char*)>& commit)
	: mGameWidth(gameWidth), mGameHeight(gameHeight), mSize(gameWidth * gameHeight * Color::COLOR_BYTES),
	mTargetWidth(targetWidth), mTargetHeight(targetHeight),
	mData(0), mScaledData(0),
	mCommit(commit), mOperation(Set)
{
	mThis = this;
	mData = new unsigned char[mSize];
	mScaledData = new unsigned char[mTargetWidth * mTargetHeight * Color::COLOR_BYTES];
	::memset(mData, 0, mSize);

	//Load the standard 5 palettes
	mPalettes[0].Load("./palettes/palette_0.dat");
	mPalettes[1].Load("./palettes/palette_1.dat");
	mPalettes[2].Load("./palettes/palette_2.dat");
	mPalettes[3].Load("./palettes/palette_3.dat");
	mPalettes[4].Load("./palettes/palette_4.dat");
	
	//Load the back palette
	mPalettes[5].Load("./palettes/backpals.dat");
	
	//The back palette contains 8 color bars that should be located at
	//position 224 for some of the background images
	for (unsigned long index = 0; index < 8; ++index)
	{
		mPalettes[6 + index] = mPalettes[5];
		mPalettes[6 + index].Move(index * 16, 16, 224);
	}
}

GraphicsBuffer::~GraphicsBuffer()
{
	mThis = 0;
	delete [] mData;
	delete [] mScaledData;
}

GraphicsBuffer& GraphicsBuffer::Get()
{
	CheckError(mThis == 0, 0, "", "GraphicsBuffer::Get called when there was no instance.");
	return *mThis;
}

void GraphicsBuffer::SetBrush(const Color& color, PixelOperation operation)
{
	mColor = color;
	mOperation = operation;
}

void GraphicsBuffer::DrawHorizontalLine(unsigned long x, unsigned long y, unsigned long cx)
{
	for (unsigned long index = 0; index < cx; ++index)
		DrawPoint(x + index, y);
}

void GraphicsBuffer::DrawVerticalLine(unsigned long x, unsigned long y, unsigned long cy)
{
	for (unsigned long index = 0; index < cy; ++index)
		DrawPoint(x, y - index);
}

void GraphicsBuffer::DrawPoint(unsigned long x, unsigned long y)
{
	if (x < mGameWidth && y < mGameHeight)
	{
		unsigned long index = (x + (y * mGameWidth)) * Color::COLOR_BYTES;
		for (unsigned long part = 0; part < Color::COLOR_BYTES; ++part)
			switch(mOperation)
			{
			case Set:
				mData[index + part] = mColor.GetData()[part];
				break;
			case Or:
				mData[index + part] |= mColor.GetData()[part];
				break;
			}
	}
}

void GraphicsBuffer::DrawFrame(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy)
{
	DrawHorizontalLine(x, y, cx);
	DrawHorizontalLine(x, y - cy + 1, cx);
	DrawVerticalLine(x, y, cy);
	DrawVerticalLine(x + cx - 1, y, cy);
}

void GraphicsBuffer::DrawRect(unsigned long x, unsigned long y, unsigned long cx, unsigned long cy)
{
	for (unsigned long index = 0; index < cy; ++index)
		DrawHorizontalLine(x, y - index, cx);
}

//Screen
//======
// (mGameHeight)
//    ^   (x,y)
//    |     +-------->(width)
//    |     |#########
//    |     v#########
//    | (height)
//    +------------------->(mGameWidth)
//  (0,0)
//
//Image
//=====
// (imageHeight)
//   ^       (height)
//   |          ^#########
//   |          |#########
//   |          +-------->(width)
//   |  (sourceX,sourceY)
//   +------------------------->(imageWidth)
// (0,0)
//
//NOTE: The source image is vertically inverted when drawn to the screen.
//		The source image area is clipped to the source image.
//		The destination area is clipped to the screen.
void GraphicsBuffer::DrawImage(
	unsigned long x, unsigned long y,
	const unsigned char* image,
	unsigned long imageWidth, unsigned long imageHeight,
	unsigned long sourceX, unsigned long sourceY,
	unsigned long width, unsigned long height,
	unsigned long paletteIndex, unsigned long paletteOffset)
{
	for (unsigned long ix = 0; ix < width; ++ix)
	{
		for (unsigned long iy = 0; iy < height; ++iy)
		{
			if ((sourceX + ix) < imageWidth && (sourceY + iy) < imageHeight)
			{
				unsigned long sourceIndex = sourceX + ix + ((imageHeight - sourceY - iy - 1) * imageWidth);
				if (image[sourceIndex])
				{
					SetBrush(mPalettes[paletteIndex][image[sourceIndex] + paletteOffset], Set);
					DrawPoint(x + ix, y - iy);
				}
			}
		}
	}
}

void GraphicsBuffer::DrawChar(
	const ColorScheme& scheme,
	unsigned long x, unsigned long y,
	const unsigned char* image,
	unsigned long width, unsigned long height)
{
	for (unsigned long ix = 0; ix < width; ++ix)
	{
		for (unsigned long iy = 0; iy < height; ++iy)
		{
			unsigned char colorIndex = image[ix + iy * width];
			if (colorIndex)
			{
				SetBrush(scheme[colorIndex], Set);
				DrawPoint(x + ix, y - iy);
			}
		}
	}
}

void GraphicsBuffer::Commit()
{
	for (unsigned long dx = 0; dx < mTargetWidth; ++dx)
	{
		for (unsigned long dy = 0; dy < mTargetHeight; ++dy)
		{
			unsigned long sx = (dx * mGameWidth) / mTargetWidth;
			unsigned long sy = (dy * mGameHeight) / mTargetHeight;
			unsigned long di = (dx + (dy * mTargetWidth)) * Color::COLOR_BYTES;
			unsigned long si = (sx + (sy * mGameWidth)) * Color::COLOR_BYTES;
			::memcpy(mScaledData + di, mData + si, Color::COLOR_BYTES);
		}
	}
	mCommit(mScaledData);
    ::memset(mData, 0, mSize);
}

const Palette& GraphicsBuffer::GetPalette(unsigned long index) const
{
	return mPalettes[index];
}

}
