#include <windows.h>
#include "Application.h"
#include "Error.h"

int __stdcall WinMain(HINSTANCE instance, HINSTANCE previous, char* command, int show)
{
	try
	{
		return XCom::Application::Get().Run(instance, command, show);
	}
	catch (const XCom::Error& error)
	{
		error.Report();
		return error.GetCode();
	}
	catch (...)
	{
		ReportUnhandled();
		return XCom::Error::UNHANDLED_EXCEPTION;
	}
}
