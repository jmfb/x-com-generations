#include "Error.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include "WindowsInclude.h"

namespace XCom
{

Error::Error()
	: mLine(0), mCode(0)
{
}

Error::Error(
	const std::string& file,
	unsigned long line,
	unsigned long code,
	const std::string& function,
	const std::string& location,
	const std::string& description)
	: mFile(file), mLine(line), mCode(code),
	mFunction(function), mLocation(location), mDescription(description)
{
}

Error::Error(const Error& rhs)
	: mFile(rhs.mFile), mLine(rhs.mLine), mCode(rhs.mCode),
	mFunction(rhs.mFunction), mLocation(rhs.mLocation), mDescription(rhs.mDescription)
{
}

Error::~Error() throw()
{
}

Error& Error::operator=(const Error& rhs)
{
	if (this != &rhs)
	{
		mFile = rhs.mFile;
		mLine = rhs.mLine;
		mCode = rhs.mCode;
		mFunction = rhs.mFunction;
		mLocation = rhs.mLocation;
		mDescription = rhs.mDescription;
	}
	return *this;
}

const std::string& Error::GetFile() const
{
	return mFile;
}

unsigned long Error::GetLine() const
{
	return mLine;
}

unsigned long Error::GetCode() const
{
	return mCode;
}

const std::string& Error::GetFunction() const
{
	return mFunction;
}

const std::string& Error::GetLocation() const
{
	return mLocation;
}

const std::string& Error::GetDescription() const
{
	return mDescription;
}

void Error::Report() const
{
	std::string message = ToString();
	std::cout << message << std::endl;
	::MessageBox(NULL, message.c_str(), "Error Report", MB_OK|MB_ICONERROR);
}

std::string Error::ToString() const
{
	std::ostringstream out;
	out << "File:     " << mFile << "(" << mLine << ")" << std::endl;
	if (mCode != 0)
		out << "Code:     " << mCode
			<< " (0x"
			<< std::setw(8)
			<< std::setfill('0')
			<< std::hex
			<< std::setiosflags(std::ios::right | std::ios::uppercase)
			<< mCode
			<< std::resetiosflags(std::ios::right | std::ios::uppercase)
			<< ")" << std::endl;
	if (!mFunction.empty())
		out << "Function: " << mFunction << std::endl;
	if (!mLocation.empty())
		out << "Location: " << mLocation << std::endl;
	if (!mDescription.empty())
		out << mDescription << std::endl;
	return out.str();
}

void Error::ReportUnhandledEx(const std::string& file, unsigned long line, const std::string& function)
{
	Error(file, line, static_cast<unsigned long>(Codes::UnhandledException), function, "", "Unhandled exception.").Report();
}

void Error::CheckWindowsErrorEx(bool isError, unsigned long code, const std::string& file, unsigned long line, const std::string& function, const std::string& location)
{
	if (isError)
		throw Error(file, line, code, function, location, GetWindowsErrorDescription(code));
}

void Error::CheckErrorEx(bool isError, const std::string& file, unsigned long line, unsigned long code, const std::string& function, const std::string& location, const std::string& description)
{
	if (isError)
		throw Error(file, line, code, function, location, description);
}

std::string Error::GetWindowsErrorDescription(unsigned long code)
{
	std::ostringstream out;
    char* buffer = NULL;
    long ret = ::FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM|FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        code,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        reinterpret_cast<char*>(&buffer),
        0,
        NULL);
    if (ret)
    {
        out << buffer << std::endl;
        ::LocalFree(buffer);
        buffer = NULL;
    }
    else
    {
        out << "No description returned from FormatMessage." << std::endl;
    }
	return out.str();
}

std::string Error::GetDisplayErrorDescription(unsigned long code)
{
    switch(code)
    {
    case DISP_CHANGE_SUCCESSFUL:
        return "Successfully changed display settings.";
    case DISP_CHANGE_BADDUALVIEW:
        return "Windows XP: The settings change was unsuccessful because system is DualView capable.";
    case DISP_CHANGE_BADFLAGS:
        return "An invalid set of flags was passed in.";
    case DISP_CHANGE_BADMODE:
        return "The graphics mode is not supported.";
    case DISP_CHANGE_BADPARAM:
        return "An invalid parameter was passed in. This can include an invalid flag or combination of flags.";
    case DISP_CHANGE_FAILED:
        return "The display driver failed the specified graphics mode.";
    case DISP_CHANGE_NOTUPDATED:
        return "Windows NT/2000/XP: Unable to write settings to the registry.";
    case DISP_CHANGE_RESTART:
        return "The computer must be restarted in order for the graphics mode to work.";
    default:
        return "Failed to change display settings: unrecognized failure code.";
    }
}

const char* Error::what() const throw()
{
	return mDescription.c_str();
}

}

