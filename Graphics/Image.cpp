#include "Image.h"
#include "../System/IBinaryFile.h"

namespace XCom
{

Image::Image(UnitTest::IFactoryPtr factory)
	: mFactory(factory), mWidth(0), mHeight(0), mImage(0)
{
}

Image::~Image()
{
	FreeImage();
}

void Image::Load(const std::string& file)
{
	FreeImage();
	auto in = mFactory->Resolve<IBinaryFile>();
	in->Open(file);
	in->ReadLong(mWidth);
	in->ReadLong(mHeight);
	unsigned long size = mWidth * mHeight * 4;
	if (size > 0)
	{
		mImage = new unsigned char[size];
		in->Read(mImage, size);
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
