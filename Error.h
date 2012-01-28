#pragma once
#include <string>

#define ReportUnhandled() Error::ReportUnhandledEx(__FILE__, __LINE__, __PRETTY_FUNCTION__)
#define CheckWindowsError(error, location) Error::CheckWindowsErrorEx(error, __FILE__, __LINE__, __PRETTY_FUNCTION__, location)
#define CheckError(error, code, location, description) Error::CheckErrorEx(error, __FILE__, __LINE__, code, __PRETTY_FUNCTION__, location, description)

namespace XCom
{

class Error
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
	~Error();

	Error& operator=(const Error& rhs);
	
	enum Codes
	{
		UNHANDLED_EXCEPTION = 0xC0000005
	};
	
	unsigned long GetCode() const;
	void Report() const;
	std::string ToString() const;
	
	static void ReportUnhandledEx(const std::string& file, unsigned long line, const std::string& function);
	static void CheckWindowsErrorEx(bool isError, const std::string& file, unsigned long line, const std::string& function, const std::string& location);
	static void CheckErrorEx(bool isError, const std::string& file, unsigned long line, unsigned long code, const std::string& function, const std::string& location, const std::string& description);
	static std::string GetWindowsErrorDescription(unsigned long code);
	static std::string GetDisplayErrorDescription(unsigned long code);
	
private:
	std::string mFile;
	unsigned long mLine;
	unsigned long mCode;
	std::string mFunction;
	std::string mLocation;
	std::string mDescription;
};

}
