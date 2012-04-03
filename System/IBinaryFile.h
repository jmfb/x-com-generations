#pragma once
#include <memory>
#include <string>

namespace XCom
{

class IBinaryFile
{
public:
	virtual ~IBinaryFile()
	{
	}
	
	virtual void Open(const std::string& filename) = 0;
	virtual void Read(void* data, unsigned long size) = 0;
	virtual void Read(unsigned long& data) = 0;
};

typedef std::shared_ptr<IBinaryFile> IBinaryFilePtr;

}
