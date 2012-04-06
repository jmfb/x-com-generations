#pragma once
#include <memory>
#include <string>

namespace XCom
{

class IImage
{
public:
	virtual ~IImage()
	{
	}
	
	virtual void Load(const std::string& file) = 0;
	virtual unsigned long GetWidth() const = 0;
	virtual unsigned long GetHeight() const = 0;
	virtual const unsigned char* GetData() const = 0;
};

typedef std::shared_ptr<IImage> IImagePtr;

}
