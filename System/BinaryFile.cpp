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
	CheckError(!mIn.is_open(), 0, "mIn.is_open()", "Must call Open before Read.");
	CheckError(data == nullptr, 0, "data", "Data pointer must be non-null.");
	CheckError(size == 0, 0, "size == 0", "Size value must be non-zero.");
	CheckError(size > (1 << (10 + 10 + 2)), 0, "size > 4MB", "Size value sanity check (4MB).");
	mIn.read(reinterpret_cast<char*>(data), size);
}

void BinaryFile::Read(unsigned long& data)
{
	CheckError(!mIn.is_open(), 0, "", "Must call Open before Read.");

	constexpr unsigned long size = sizeof(unsigned long);
	unsigned char buffer[size] = {0};
	mIn.read(reinterpret_cast<char*>(buffer), size);
	
	//Convert the buffer using little-endian logic for how it was stored in the file
	//NOTE: little endian is how Windows operates and how binary files were originally generated.
	data = 0;
	for (unsigned long index = 0; index < size; ++index)
		data |= buffer[index] << (index * 8);
}

}
