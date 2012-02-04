#pragma once
#include <string>

namespace XCom
{

class Image
{
public:
	Image();
	Image(const Image& rhs);
	~Image();
	
	Image& operator=(const Image& rhs);
	
	void Load(const std::string& file);

	unsigned long GetWidth() const;
	unsigned long GetHeight() const;
	const unsigned char* GetData() const;
	
private:
	void FreeImage();
	
private:
	unsigned long mWidth;
	unsigned long mHeight;
	unsigned char* mImage;
};

}
