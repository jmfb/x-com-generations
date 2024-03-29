#include "Error.h"
#include "WindowsInclude.h"
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace XCom
{

TEST_CLASS(ErrorTest)
{
public:
	ErrorTest()
	{
	}

	TEST_METHOD(DefaultConstructor)
	{
		Error error;
		Assert.AreEqual("", error.GetFile(), "File");
		Assert.AreEqual(0ul, error.GetLine(), "Line");
		Assert.AreEqual(0ul, error.GetCode(), "Code");
		Assert.AreEqual("", error.GetFunction(), "Function");
		Assert.AreEqual("", error.GetLocation(), "Location");
		Assert.AreEqual("", error.GetDescription(), "Description");
	}

	TEST_METHOD(MemberwiseConstructor)
	{
		const std::string file = "file";
		const unsigned long line = 1;
		const unsigned long code = 2;
		const std::string function = "function";
		const std::string location = "location";
		const std::string description = "description";
		Error error(file, line, code, function, location, description);
		Assert.AreEqual(file, error.GetFile(), "File");
		Assert.AreEqual(line, error.GetLine(), "Line");
		Assert.AreEqual(code, error.GetCode(), "Code");
		Assert.AreEqual(function, error.GetFunction(), "Function");
		Assert.AreEqual(location, error.GetLocation(), "Location");
		Assert.AreEqual(description, error.GetDescription(), "Description");
	}

	TEST_METHOD(CopyConstructor)
	{
		const std::string file = "file";
		const unsigned long line = 1;
		const unsigned long code = 2;
		const std::string function = "function";
		const std::string location = "location";
		const std::string description = "description";
		Error source(file, line, code, function, location, description);
		Error error(source);
		Assert.AreEqual(file, error.GetFile(), "File");
		Assert.AreEqual(line, error.GetLine(), "Line");
		Assert.AreEqual(code, error.GetCode(), "Code");
		Assert.AreEqual(function, error.GetFunction(), "Function");
		Assert.AreEqual(location, error.GetLocation(), "Location");
		Assert.AreEqual(description, error.GetDescription(), "Description");
	}

	TEST_METHOD(CopyAssignmentOperator)
	{
		const std::string file = "file";
		const unsigned long line = 1;
		const unsigned long code = 2;
		const std::string function = "function";
		const std::string location = "location";
		const std::string description = "description";
		Error source(file, line, code, function, location, description);
		Error error;
		error = source;
		Assert.AreEqual(file, error.GetFile(), "File");
		Assert.AreEqual(line, error.GetLine(), "Line");
		Assert.AreEqual(code, error.GetCode(), "Code");
		Assert.AreEqual(function, error.GetFunction(), "Function");
		Assert.AreEqual(location, error.GetLocation(), "Location");
		Assert.AreEqual(description, error.GetDescription(), "Description");
	}

	TEST_METHOD(Report)
	{
		//TODO: need to mock usage of cout and MessageBox calls
	}

	TEST_METHOD(ToStringWithJustFileLine)
	{
		Error error("file", 1, 0, "", "", "");
		Assert.AreEqual("File:     file(1)\n", error.ToString());
	}

	TEST_METHOD(ToStringWithCode)
	{
		Error error("file", 1, 0x0a, "", "", "");
		Assert.AreEqual("File:     file(1)\nCode:     10 (0x0000000A)\n", error.ToString());
	}

	TEST_METHOD(ToStringWithFunction)
	{
		Error error("file", 1, 0, "function", "", "");
		Assert.AreEqual("File:     file(1)\nFunction: function\n", error.ToString());
	}

	TEST_METHOD(ToStringWithLocation)
	{
		Error error("file", 1, 0, "", "location", "");
		Assert.AreEqual("File:     file(1)\nLocation: location\n", error.ToString());
	}

	TEST_METHOD(ToStringWithDescription)
	{
		Error error("file", 1, 0, "", "", "description");
		Assert.AreEqual("File:     file(1)\ndescription\n", error.ToString());
	}

	TEST_METHOD(ToStringWithAll)
	{
		Error error("file", 1, 0x0a, "function", "location", "description");
		Assert.AreEqual("File:     file(1)\nCode:     10 (0x0000000A)\n"
			"Function: function\nLocation: location\ndescription\n", error.ToString());
	}

	TEST_METHOD(ReportUnhandledEx)
	{
		//TODO: need to mock usage of Report
	}

	TEST_METHOD(ReportUnhandledMacro)
	{
		//TODO: need to test ReportHandledEx to test macro
	}

	TEST_METHOD(CheckWindowsErrorExThrow)
	{
		const std::string file = "file";
		const unsigned long line = 1;
		const unsigned long code = 2;
		const std::string function = "function";
		const std::string location = "location";
		const std::string description = XCom::Error::GetWindowsErrorDescription(code);
		try
		{
			::SetLastError(code);
			Error::CheckWindowsErrorEx(true, ::GetLastError(), file, line, function, location);
			Assert.Fail("Should have thrown.");
		}
		catch (const Error& error)
		{
			Assert.AreEqual(file, error.GetFile(), "File");
			Assert.AreEqual(line, error.GetLine(), "Line");
			Assert.AreEqual(code, error.GetCode(), "Code");
			Assert.AreEqual(function, error.GetFunction(), "Function");
			Assert.AreEqual(location, error.GetLocation(), "Location");
			Assert.AreEqual(description, error.GetDescription(), "Description");
		}
	}

	TEST_METHOD(CheckWindowsErrorExNoThrow)
	{
		Error::CheckWindowsErrorEx(false, 0, "", 0, "", "");
	}

	TEST_METHOD(CheckWindowsErrorMacro)
	{
		const std::string file = __FILE__;
		const unsigned long line = __LINE__ + 8;
		const unsigned long code = 2;
		const std::string function = __PRETTY_FUNCTION__;
		const std::string location = "location";
		const std::string description = XCom::Error::GetWindowsErrorDescription(code);
		try
		{
			::SetLastError(code);
			CheckWindowsError(true, location);
			Assert.Fail("Should have thrown.");
		}
		catch (const Error &error)
		{
			Assert.AreEqual(file, error.GetFile(), "File");
			Assert.AreEqual(line, error.GetLine(), "Line");
			Assert.AreEqual(code, error.GetCode(), "Code");
			Assert.AreEqual(function, error.GetFunction(), "Function");
			Assert.AreEqual(location, error.GetLocation(), "Location");
			Assert.AreEqual(description, error.GetDescription(), "Description");
		}
	}

	TEST_METHOD(CheckErrorExThrow)
	{
		const std::string file = "file";
		const unsigned long line = 1;
		const unsigned long code = 2;
		const std::string function = "function";
		const std::string location = "location";
		const std::string description = "description";
		try
		{
			Error::CheckErrorEx(true, file, line, code, function, location, description);
			Assert.Fail("Should have thrown.");
		}
		catch (const Error& error)
		{
			Assert.AreEqual(file, error.GetFile(), "File");
			Assert.AreEqual(line, error.GetLine(), "Line");
			Assert.AreEqual(code, error.GetCode(), "Code");
			Assert.AreEqual(function, error.GetFunction(), "Function");
			Assert.AreEqual(location, error.GetLocation(), "Location");
			Assert.AreEqual(description, error.GetDescription(), "Description");
		}
	}

	TEST_METHOD(CheckErrorExNoThrow)
	{
		Error::CheckErrorEx(false, "", 0, 0, "", "", "");
	}

	TEST_METHOD(CheckErrorMacro)
	{
		const std::string file = __FILE__;
		const unsigned long line = __LINE__ + 7;
		const unsigned long code = 2;
		const std::string function = __PRETTY_FUNCTION__;
		const std::string location = "location";
		const std::string description = "description";
		try
		{
			CheckError(true, code, location, description);
			Assert.Fail("Should have thrown.");
		}
		catch (const Error &error)
		{
			Assert.AreEqual(file, error.GetFile(), "File");
			Assert.AreEqual(line, error.GetLine(), "Line");
			Assert.AreEqual(code, error.GetCode(), "Code");
			Assert.AreEqual(function, error.GetFunction(), "Function");
			Assert.AreEqual(location, error.GetLocation(), "Location");
			Assert.AreEqual(description, error.GetDescription(), "Description");
		}
	}

	TEST_METHOD(RaiseErrorMacro)
	{
		const std::string file = __FILE__;
		const unsigned long line = __LINE__ + 7;
		const unsigned long code = 2;
		const std::string function = __PRETTY_FUNCTION__;
		const std::string location = "location";
		const std::string description = "description";
		try
		{
			RaiseError(code, location, description);
			Assert.Fail("Should have thrown.");
		}
		catch (const Error &error)
		{
			Assert.AreEqual(file, error.GetFile(), "File");
			Assert.AreEqual(line, error.GetLine(), "Line");
			Assert.AreEqual(code, error.GetCode(), "Code");
			Assert.AreEqual(function, error.GetFunction(), "Function");
			Assert.AreEqual(location, error.GetLocation(), "Location");
			Assert.AreEqual(description, error.GetDescription(), "Description");
		}
	}

	TEST_METHOD(GetWindowsErrorDescriptionValid)
	{
		Assert.AreEqual("The operation completed successfully.\r\n\n",
			Error::GetWindowsErrorDescription(0), "ErrorCode 0.");
	}

	TEST_METHOD(GetWindowsErrorDescriptionInvalid)
	{
		Assert.AreEqual("No description returned from FormatMessage.\n",
			Error::GetWindowsErrorDescription(-1), "ErrorCode -1.");
	}

	TEST_METHOD(GetDisplayErrorDescription)
	{
		Assert.AreEqual("Successfully changed display settings.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_SUCCESSFUL), "DISP_CHANGE_SUCCESSFUL");
		Assert.AreEqual("Windows XP: The settings change was unsuccessful because system is DualView capable.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_BADDUALVIEW), "DISP_CHANGE_BADDUALVIEW");
		Assert.AreEqual("An invalid set of flags was passed in.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_BADFLAGS), "DISP_CHANGE_BADFLAGS");
		Assert.AreEqual("The graphics mode is not supported.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_BADMODE), "DISP_CHANGE_BADMODE");
		Assert.AreEqual("An invalid parameter was passed in. This can include an invalid flag or combination of flags.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_BADPARAM), "DISP_CHANGE_BADPARAM");
		Assert.AreEqual("The display driver failed the specified graphics mode.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_FAILED), "DISP_CHANGE_FAILED");
		Assert.AreEqual("Windows NT/2000/XP: Unable to write settings to the registry.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_NOTUPDATED), "DISP_CHANGE_NOTUPDATED");
		Assert.AreEqual("The computer must be restarted in order for the graphics mode to work.",
			Error::GetDisplayErrorDescription(DISP_CHANGE_RESTART), "DISP_CHANGE_RESTART");
		Assert.AreEqual("Failed to change display settings: unrecognized failure code.",
			Error::GetDisplayErrorDescription(12345), "Default");
	}
};

}
