#include "Background.h"
#include "../Error.h"
#include "../constants.h"
#include <fstream>

namespace XCom
{

const unsigned long BACK_WIDTH = GAME_WIDTH;
const unsigned long BACK_HEIGHT = GAME_HEIGHT;
const unsigned long BACK_SIZE = BACK_WIDTH * BACK_HEIGHT;

Background::Background()
	: mData(0)
{
	mData = new unsigned char[BACK_SIZE];
}

Background::~Background()
{
	delete [] mData;
}

void Background::Load(const std::string& file)
{
	std::ifstream in(file.c_str(), std::ios::binary);
	CheckError(!in.is_open(), 0, file, "Could not open background image.");
	for (unsigned long y = 0; y < BACK_HEIGHT; ++y)
		in.read(reinterpret_cast<char*>(mData) + (BACK_HEIGHT - y - 1) * BACK_WIDTH, BACK_WIDTH);
}

const unsigned char* Background::GetData() const
{
	return mData;
}

}
