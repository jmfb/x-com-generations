#pragma once
#include <string>
#include <memory>
#include "TestException.h"

namespace UnitTest
{

class TestAssert
{
public:
	static void IsTrue(bool condition, const std::string& message = "")
	{
		if (!condition)
			TestException::Raise("Assert.IsTrue", message);
	}
	static void IsFalse(bool condition, const std::string& message = "")
	{
		if (condition)
			TestException::Raise("Assert.IsFalse", message);
	}
	static void IsNull(void* value, const std::string& message = "")
	{
		if (value != 0)
			TestException::Raise("Assert.IsNull", message);
	}
	static void IsNotNull(void* value, const std::string& message = "")
	{
		if (value == 0)
			TestException::Raise("Assert.IsNotNull", message);
	}
	template <typename T1, typename T2>
	static void AreEqual(const T1& expected, const T2& actual, const std::string& message = "")
	{
		if (!(expected == actual))
			TestException::Raise("Assert.AreEqual", "expected", expected, "actual", actual, message);
	}
	template <typename T1, typename T2>
	static void AreNotEqual(const T1& notExpected, const T2& actual, const std::string& message = "")
	{
		if (notExpected == actual)
			TestException::Raise("Assert.AreNotEqual", "notExpected", notExpected, "actual", actual, message);
	}
	static void Fail(const std::string& message = "")
	{
		TestException::Raise("Assert.Fail", message);
	}
	static void Inconclusive(const std::string& message = "")
	{
		TestException::Raise("Assert.Inconclusive", message);
	}
	//TODO: AreSame
	//TODO: AreNotSame
	//TODO: StringAssert helpers
	//TODO: CollectionAssert helpers
	//TODO: Throws helpers
};

static const UnitTest::TestAssert Assert = UnitTest::TestAssert();

}
