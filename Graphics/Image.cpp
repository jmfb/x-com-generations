#include "Image.h"
#include "../Error.h"
#include "GraphicsBuffer.h"
#include <fstream>
#include <cstring>

namespace XCom
{

Image::Image()
	: mWidth(0), mHeight(0), mImage(0)
{
}

Image::Image(const Image& rhs)
	: mWidth(0), mHeight(0), mImage(0)
{
	operator=(rhs);
}

Image::~Image()
{
	FreeImage();
}

Image& Image::operator=(const Image& rhs)
{
	if (this != &rhs)
	{
		FreeImage();
		mWidth = rhs.mWidth;
		mHeight = rhs.mHeight;
		if (rhs.mImage)
		{
			unsigned long size = mWidth * mHeight * 4;
			mImage = new unsigned char[size];
			::memcpy(mImage, rhs.mImage, size);
		}
	}
	return *this;
}

void Image::Load(const std::string& file)
{
	FreeImage();
	std::ifstream in(file.c_str(), std::ios::binary);
	CheckError(!in.is_open(), 0, file, "Could not load image file.");
	in.read(reinterpret_cast<char*>(&mWidth), sizeof(mWidth));
	in.read(reinterpret_cast<char*>(&mHeight), sizeof(mHeight));
	unsigned long size = mWidth * mHeight * 4;
	if (size > 0)
	{
		mImage = new unsigned char[size];
		in.read(reinterpret_cast<char*>(mImage), size);
	}
}

unsigned long Image::GetWidth() const
{
	return mWidth;
}

unsigned long Image::GetHeight() const
{
	return mHeight;
}

const unsigned char* Image::GetData() const
{
	return mImage;
}

void Image::FreeImage()
{
	if (mImage)
	{
		delete [] mImage;
		mImage = 0;
		mWidth = 0;
		mHeight = 0;
	}
}

}
