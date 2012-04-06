#pragma once
#include <string>
#include <memory>
#include <functional>
#include <exception>
#include "TestException.h"
#include "../Error.h"

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
	static void IsNull(const void* value, const std::string& message = "")
	{
		if (value != nullptr)
			TestException::Raise("Assert.IsNull", message);
	}
	static void IsNotNull(const void* value, const std::string& message = "")
	{
		if (value == nullptr)
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
	static void Throws(std::function<void()> action, const std::string& expectedMessage, const std::string& message = "")
	{
		try
		{
			action();
		}
		catch (const TestException& error)
		{
			//re-throw test exceptions (the action has already failed for another testing reason - do not hide that exception)
			throw;
		}
		catch (const XCom::Error& error)
		{
			if (error.GetDescription() == expectedMessage)
				return;
			TestException::Raise("Assert.Throws", "expected", expectedMessage, "actual", error.GetDescription(), message);
		}
		catch (const std::exception& error)
		{
			TestException::Raise("Assert.Throws", "expected", expectedMessage, "actual(std::exception)", error.what(), message);
		}
		catch (...)
		{
			TestException::Raise("Assert.Throws", "expected", expectedMessage, "actual(...)", "unhandled exception", message);
		}
		TestException::Raise("Assert.Throws", "expected", expectedMessage, "actual", "No exception was thrown.", message);
	}
	//TODO: AreSame
	//TODO: AreNotSame
	//TODO: StringAssert helpers
	//TODO: CollectionAssert helpers
};

static const UnitTest::TestAssert Assert = UnitTest::TestAssert();

}
