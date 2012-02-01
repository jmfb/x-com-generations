#include "Palette.h"
#include "../Error.h"
#include <cstring>
#include <fstream>

namespace XCom
{

const unsigned long PALETTE_ENTRIES = 256;
const unsigned long PALETTE_SIZE = PALETTE_ENTRIES * Color::COLOR_BYTES;

Palette::Palette()
	: mData(0)
{
	mData = new unsigned char[PALETTE_SIZE];
	::memset(mData, 0, PALETTE_SIZE);
}

Palette::Palette(const Palette& rhs)
	: mData(0)
{
	mData = new unsigned char[PALETTE_SIZE];
	::memcpy(mData, rhs.mData, PALETTE_SIZE);
}

Palette::~Palette()
{
	delete [] mData;
}

Palette& Palette::operator=(const Palette& rhs)
{
	if (this != &rhs)
		::memcpy(mData, rhs.mData, PALETTE_SIZE);
	return *this;
}

void Palette::Load(const std::string& file)
{
	std::ifstream in(file.c_str(), std::ios::binary);
	CheckError(!in.is_open(), 0, file, "Could not open palette file.");
	in.read(reinterpret_cast<char*>(mData), PALETTE_SIZE);
}

void Palette::Move(unsigned long source, unsigned long size, unsigned long destination)
{
	::memmove(mData + destination * Color::COLOR_BYTES, mData + source * Color::COLOR_BYTES, size * Color::COLOR_BYTES);
}

Color Palette::operator[](unsigned long index) const
{
	unsigned long position = index * Color::COLOR_BYTES;
	return Color(mData[position] << 2, mData[position + 1] << 2, mData[position + 2] << 2);
}

}
