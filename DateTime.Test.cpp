#include "DateTime.h"
#include "TimePointStream.h"
#include <UnitTest/UnitTest.h>
#include <ctime>
using UnitTest::Assert;

namespace XCom
{

TEST_CLASS(DateTimeTest)
{
public:
	DateTimeTest()
	{
	}

	TEST_METHOD(Constructor)
	{
		auto now = std::chrono::high_resolution_clock::now();
		UnitTest::Mock<IDateTimeUtility> mockUtility;
		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);

		DateTime dateTime(mockUtility.GetObject());
		Assert.AreEqual(now, dateTime.GetValue(), "Value");

		mockUtility.Verify();
	}

	TEST_METHOD(SetNow)
	{
		auto now = std::chrono::high_resolution_clock::now();
		auto then = now + std::chrono::milliseconds(10);
		UnitTest::Mock<IDateTimeUtility> mockUtility;
		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);

		DateTime dateTime(mockUtility.GetObject());
		Assert.AreEqual(now, dateTime.GetValue(), "Value(now)");
		mockUtility.Verify();

		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(then);
		dateTime.SetNow();
		Assert.AreEqual(then, dateTime.GetValue(), "Value(then)");
		mockUtility.Verify();
	}

	TEST_METHOD(TestIntervalTrue)
	{
		const unsigned long interval = 100;
		auto now = std::chrono::high_resolution_clock::now();
		auto then = now + std::chrono::milliseconds(interval);
		UnitTest::Mock<IDateTimeUtility> mockUtility;
		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);

		DateTime dateTime(mockUtility.GetObject());
		Assert.AreEqual(now, dateTime.GetValue(), "Value(before)");
		mockUtility.Verify();

		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(then);
		bool result = dateTime.TestInterval(interval);
		Assert.IsTrue(result, "result");
		Assert.AreEqual(then, dateTime.GetValue(), "Value(after)");
		mockUtility.Verify();
	}

	TEST_METHOD(TestIntervalFalse)
	{
		const unsigned long interval = 100;
		auto now = std::chrono::high_resolution_clock::now();
		auto then = now + std::chrono::milliseconds(interval - 1);
		UnitTest::Mock<IDateTimeUtility> mockUtility;
		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);

		DateTime dateTime(mockUtility.GetObject());
		Assert.AreEqual(now, dateTime.GetValue(), "Value(before)");
		mockUtility.Verify();

		mockUtility.Setup(&IDateTimeUtility::GetNow).Returns(then);
		bool result = dateTime.TestInterval(interval);
		Assert.IsFalse(result, "result");
		Assert.AreEqual(now, dateTime.GetValue(), "Value(after)");
		mockUtility.Verify();
	}
};

}
