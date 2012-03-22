#include <windows.h>
#include "Application.h"
#include "Error.h"
#include <exception>
#include <iostream>

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
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
		return -1;
	}
	catch (...)
	{
		ReportUnhandled();
		return XCom::Error::UNHANDLED_EXCEPTION;
	}
}
