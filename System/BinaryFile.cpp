#include "BinaryFile.h"
#include "../Error.h"

namespace XCom
{

BinaryFile::BinaryFile()
{
}

BinaryFile::~BinaryFile()
{
}

void BinaryFile::Open(const std::string& filename)
{
	mIn.open(filename.c_str(), std::ios::binary);
	CheckError(!mIn.is_open(), 0, filename, "Could not open file.");
}

void BinaryFile::Read(void* data, unsigned long size)
{
	mIn.read(reinterpret_cast<char*>(data), size);
}

}
