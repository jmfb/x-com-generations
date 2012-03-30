#pragma once
#include <fstream>
#include "IBinaryFile.h"

namespace XCom
{

class BinaryFile : public IBinaryFile
{
public:
	BinaryFile();
	BinaryFile(const BinaryFile& rhs) = delete;
	~BinaryFile();
	
	BinaryFile& operator=(const BinaryFile& rhs) = delete;

	virtual void Open(const std::string& filename);
	virtual void Read(void* data, unsigned long size);
	
private:
	std::ifstream mIn;
};

}
