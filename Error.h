#pragma once
#include <string>
#include <exception>

#define ReportUnhandled() \
	XCom::Error::ReportUnhandledEx(__FILE__, __LINE__, __PRETTY_FUNCTION__)

//NOTE: GetLastError must be called before the string arguments are converted to std::string.
//		I have not investigated what, but something clears the error code in that scenario.
//		The do/while loop construct is just to enforce clients to put a semicolon after the macro usage.
#define CheckWindowsError(error, location) \
	do \
	{ \
		auto code = ::GetLastError(); \
		XCom::Error::CheckWindowsErrorEx(error, code, __FILE__, __LINE__, __PRETTY_FUNCTION__, location); \
	} \
	while (false)

#define CheckError(error, code, location, description) \
	XCom::Error::CheckErrorEx(error, __FILE__, __LINE__, static_cast<unsigned long>(code), __PRETTY_FUNCTION__, location, description)

#define RaiseError(code, location, description) \
	throw XCom::Error(__FILE__, __LINE__, static_cast<unsigned long>(code), __PRETTY_FUNCTION__, location, description)

namespace XCom
{

class Error : public std::exception
{
public:
	Error();
	Error(
		const std::string& file,
		unsigned long line,
		unsigned long code,
		const std::string& function,
		const std::string& location,
		const std::string& description);
	Error(const Error& rhs);
	virtual ~Error() throw();

	Error& operator=(const Error& rhs);

	enum class Codes : unsigned long
	{
		UnhandledException = 0xC0000005,
		NullPointer = 1
	};

	const std::string& GetFile() const;
	unsigned long GetLine() const;
	unsigned long GetCode() const;
	const std::string& GetFunction() const;
	const std::string& GetLocation() const;
	const std::string& GetDescription() const;

	void Report() const;
	std::string ToString() const;

	static void ReportUnhandledEx(const std::string& file, unsigned long line, const std::string& function);
	static void CheckWindowsErrorEx(bool isError, unsigned long code, const std::string& file, unsigned long line, const std::string& function, const std::string& location);
	static void CheckErrorEx(bool isError, const std::string& file, unsigned long line, unsigned long code, const std::string& function, const std::string& location, const std::string& description);
	static std::string GetWindowsErrorDescription(unsigned long code);
	static std::string GetDisplayErrorDescription(unsigned long code);

	const char* what() const throw() override;

private:
	std::string mFile;
	unsigned long mLine;
	unsigned long mCode;
	std::string mFunction;
	std::string mLocation;
	std::string mDescription;
};

}
