#pragma once
#include "WindowsInclude.h"
#include <memory>

namespace XCom
{

class IApplication
{
public:
	virtual ~IApplication()
	{
	}
	
	virtual int Run(HINSTANCE instance, char* command, int show) = 0;
	virtual void Quit() = 0;
	virtual void DrawPixels(unsigned char* data) = 0;
	virtual HWND GetWindowHandle() const = 0;
	virtual LRESULT CallbackWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) = 0;
};

typedef std::shared_ptr<IApplication> IApplicationPtr;

}
