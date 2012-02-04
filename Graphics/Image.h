#pragma once
#include <string>

namespace XCom
{

enum ImageType
{
	IMAGE_RANK_ROOKIE,
	IMAGE_RANK_SQUADDIE,
	IMAGE_RANK_SERGEANT,
	IMAGE_RANK_CAPTAIN,
	IMAGE_RANK_COLONEL,
	IMAGE_RANK_COMMANDER,
	IMAGE_BATTLESCAPE_TEST_CORNER,
	IMAGE_BATTLESCAPE_TEST_FLOOR,
	IMAGE_BATTLESCAPE_TEST_FLOOR_1,
	IMAGE_BATTLESCAPE_TEST_FLOOR_2,
	IMAGE_BATTLESCAPE_TEST_LEFT,
	IMAGE_BATTLESCAPE_TEST_TOP,
	IMAGE_COUNT				//not an image, just the count of total images
};

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
