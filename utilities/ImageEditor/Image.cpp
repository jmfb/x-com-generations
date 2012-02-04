#include "Image.h"
#include <fstream>
#include <cstring>

Image::Image()
	: mWidth(0), mHeight(0), mData(0), mDirty(false)
{
}

Image::~Image()
{
	FreeImage();
}

void Image::New(unsigned long width, unsigned long height)
{
	FreeImage();
	mWidth = width;
	mHeight = height;
	unsigned long size = width * height * 4;
	mData = new unsigned char[size];
	::memset(mData, 0, size);
	mDirty = false;	//New images should not prompt save
}

void Image::Load(const std::string& file)
{
	FreeImage();
	std::ifstream in(file.c_str(), std::ios::binary);
	if (in.is_open())
	{
		in.read(reinterpret_cast<char*>(&mWidth), sizeof(mWidth));
		in.read(reinterpret_cast<char*>(&mHeight), sizeof(mHeight));
		unsigned long size = mWidth * mHeight * 4;
		if (size > 0)
		{
			mData = new unsigned char[size];
			in.read(reinterpret_cast<char*>(mData), size);
		}
		mDirty = false;
	}
}

void Image::Save(const std::string& file)
{
	std::ofstream out(file.c_str(), std::ios::binary);
	out.write(reinterpret_cast<char*>(&mWidth), sizeof(mWidth));
	out.write(reinterpret_cast<char*>(&mHeight), sizeof(mHeight));
	out.write(reinterpret_cast<char*>(mData), mWidth * mHeight * 4);
	mDirty = false;
}

unsigned long Image::GetWidth() const
{
	return mWidth;
}

unsigned long Image::GetHeight() const
{
	return mHeight;
}

bool Image::IsDirty() const
{
	return mDirty;
}

std::pair<bool, COLORREF> Image::GetPixel(unsigned long x, unsigned long y) const
{
	unsigned long index = IndexOf(x, y);
	return std::make_pair(mData[index + 3] != 0, RGB(mData[index], mData[index + 1], mData[index + 2]));
}

void Image::SetPixel(unsigned long x, unsigned long y, COLORREF color)
{
	unsigned long index = IndexOf(x, y);
	mData[index] = GetRValue(color);
	mData[index + 1] = GetGValue(color);
	mData[index + 2] = GetBValue(color);
	mData[index + 3] = 1;
	mDirty = true;
}

void Image::ClearPixel(unsigned long x, unsigned long y)
{
	::memset(mData + IndexOf(x, y), 0, 4);
	mDirty = true;
}

void Image::Fill(unsigned long x, unsigned long y, COLORREF color)
{
	auto current = GetPixel(x, y);
	if (!current.first || current.second != color)
	{
		SetPixel(x, y, color);
		if (x > 0 && GetPixel(x - 1, y) == current)
			Fill(x - 1, y, color);
		if ((x + 1) < mWidth && GetPixel(x + 1, y) == current)
			Fill(x + 1, y, color);
		if (y > 0 && GetPixel(x, y - 1) == current)
			Fill(x, y - 1, color);
		if ((y + 1) < mHeight && GetPixel(x, y + 1) == current)
			Fill(x, y + 1, color);
	}
}

void Image::ClearFill(unsigned long x, unsigned long y)
{
	auto current = GetPixel(x, y);
	if (current.first)
	{
		ClearPixel(x, y);
		if (x > 0 && GetPixel(x - 1, y) == current)
			ClearFill(x - 1, y);
		if ((x + 1) < mWidth && GetPixel(x + 1, y) == current)
			ClearFill(x + 1, y);
		if (y > 0 && GetPixel(x, y - 1) == current)
			ClearFill(x, y - 1);
		if ((y + 1) < mHeight && GetPixel(x, y + 1) == current)
			ClearFill(x, y + 1);
	}
}

unsigned long Image::IndexOf(unsigned long x, unsigned long y) const
{
	return (x + ((mHeight - y - 1) * mWidth)) * 4;
}

void Image::FreeImage()
{
	if (mData)
	{
		delete [] mData;
		mData = 0;
	}
	mWidth = 0;
	mHeight = 0;
}
