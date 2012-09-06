#pragma once
#include "IImage.h"
#include <UnitTest/UnitTest.h>

namespace XCom
{

class Image : public IImage
{
public:
	Image(UnitTest::IFactoryPtr factory);
	Image(const Image& rhs) = delete;
	~Image();
	
	Image& operator=(const Image& rhs) = delete;
	
	virtual void Load(const std::string& file);

	virtual unsigned long GetWidth() const;
	virtual unsigned long GetHeight() const;
	virtual const unsigned char* GetData() const;
	
private:
	void FreeImage();
	
private:
	UnitTest::IFactoryPtr mFactory;
	unsigned long mWidth;
	unsigned long mHeight;
	unsigned char* mImage;
};

}
