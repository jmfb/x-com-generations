#include "../../Graphics/Color.h"
#include "../../UnitTest/UnitTest.h"

namespace XCom
{

TEST_CLASS(ColorTest)
{
public:
	ColorTest()
	{
	}
	
	static void AssertColor(
		unsigned char red,
		unsigned char green,
		unsigned char blue,
		const Color& color)
	{
		const auto& data = color.GetData();
		Assert.AreEqual(red, data[0], "Red");
		Assert.AreEqual(green, data[1], "Green");
		Assert.AreEqual(blue, data[2], "Blue");
	}
	
	TEST_METHOD(DefaultConstructor)
	{
		Color color;
		AssertColor(0, 0, 0, color);
	}
	
	TEST_METHOD(MemberwiseConstructor)
	{
		const unsigned char red = 1;
		const unsigned char green = 2;
		const unsigned char blue = 3;
		Color color(red, green, blue);
		AssertColor(red, green, blue, color);
	}
	
	TEST_METHOD(CopyConstructor)
	{
		const unsigned char red = 1;
		const unsigned char green = 2;
		const unsigned char blue = 3;
		Color color(red, green, blue);
		Color copy(color);
		AssertColor(red, green, blue, copy);
	}
	
	TEST_METHOD(CopyAssignmentOperator)
	{
		const unsigned char red = 1;
		const unsigned char green = 2;
		const unsigned char blue = 3;
		Color color(red, green, blue);
		Color copy;
		copy = color;
		AssertColor(red, green, blue, copy);
	}
	
	TEST_METHOD(Set)
	{
		const unsigned char red = 1;
		const unsigned char green = 2;
		const unsigned char blue = 3;
		Color color;
		color.Set(red, green, blue);
		AssertColor(red, green, blue, color);
	}
};

}
