#include "../../DateTimeUtility.h"
#include "../../UnitTest/UnitTest.h"

TEST_CLASS(DateTimeUtilityTest)
{
public:
	DateTimeUtilityTest()
	{
	}
	
	TEST_METHOD(GetNow)
	{
		auto before = std::chrono::high_resolution_clock::now();
		XCom::DateTimeUtility utility;
		auto result = utility.GetNow();
		auto after = std::chrono::high_resolution_clock::now();
		Assert.IsTrue(result >= before, "Result cannot be before earlier time.");
		Assert.IsTrue(result <= after, "Result cannot be after later time.");
	}
};
