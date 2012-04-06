#include "../../Graphics/Image.h"
#include "../../UnitTest/UnitTest.h"
#include "../../System/IBinaryFile.h"
#include <queue>
#include <iostream>

namespace XCom
{

TEST_CLASS(ImageTest)
{
public:
	ImageTest()
	{
	}
	
	virtual void BeginTest()
	{
		mFactory.RegisterObject(mMockFile);
	}
	
	virtual void EndTest()
	{
		mMockFile.Verify();
	}
	
	TEST_METHOD(Constructor)
	{
		Image image(&mFactory);
		Assert.AreEqual(0ul, image.GetWidth(), "Width");
		Assert.AreEqual(0ul, image.GetHeight(), "Height");
		Assert.IsNull(image.GetData(), "Data");
	}
	
	TEST_METHOD(LoadEmptyImage)
	{
		const std::string& filename = "filename";
		mMockFile.Setup(&IBinaryFile::Open, filename);
		mMockFile.Setup(&IBinaryFile::ReadLong, UnitTest::Any::Match)
			.Callback([](unsigned long& value)
			{
				std::cout << "Callback(ReadLong) Empty" << std::endl;
				value = 0;
			})
			.Expects(2);
		
		Image image(&mFactory);
		image.Load(filename);
		Assert.AreEqual(0ul, image.GetWidth(), "Width");
		Assert.AreEqual(0ul, image.GetHeight(), "Height");
		Assert.IsNull(image.GetData(), "Data");
	}
	
	TEST_METHOD(LoadValidImage)
	{
		const std::string& filename = "filename";
		const unsigned long height = 2;
		const unsigned long width = 3;
		const unsigned long size = height * width * 4;
		void* imageData = nullptr;
		std::queue<unsigned long> nextValue;
		nextValue.push(width);
		nextValue.push(height);
		mMockFile.Setup(&IBinaryFile::Open, filename);
		mMockFile.Setup(&IBinaryFile::ReadLong, UnitTest::Any::Match)
			.Callback([&](unsigned long& value)
			{
				value = nextValue.front();
				std::cout << "Callback(ReadLong): value = " << value << std::endl;
				nextValue.pop();
			})
			.Expects(2);
		mMockFile.Setup(&IBinaryFile::Read, UnitTest::Any::Match, size)
			.Callback([&](void* data, unsigned long size){ imageData = data; });
		
		Image image(&mFactory);
		image.Load(filename);
		Assert.AreEqual(width, image.GetWidth(), "Width");
		Assert.AreEqual(height, image.GetHeight(), "Height");
		Assert.IsNotNull(imageData, "imageData");
		Assert.AreEqual(imageData, image.GetData(), "Data");
	}
	
private:
	UnitTest::Factory mFactory;
	UnitTest::Mock<IBinaryFile> mMockFile;
};

}
