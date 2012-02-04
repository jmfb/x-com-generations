#pragma once
#include "WindowsInclude.h"
#include <gl/gl.h>
#include "Singleton.h"
#include "Mouse/ArrowKey.h"
#include <string>

namespace XCom
{

class Application : public Singleton<Application>
{
private:
	Application();
	~Application();
	
	friend class Singleton<Application>;
	
public:
	int Run(HINSTANCE instance, char* command, int show);
	void Quit();
	void DrawPixels(unsigned char* data);
	HWND GetWindowHandle();
	
private:
	void CreateWindowAtom();
	void CreateWindowHandle();
	int RunMessageLoop();
	LRESULT CallbackWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
	void OnCreate(HWND hwnd);
	void OnSize();
	bool OnSetCursor(LPARAM lparam);
	void OnPaint(bool validate);
	void OnKeyDown(char ch);
	void OnArrowKey(ArrowKey key);
	void OnMouseMove(WPARAM wparam);
	void OnLButtonDown();
	void OnLButtonUp();
	void OnRButtonDown();
	void OnRButtonUp();
	void OnDestroy();
	
	static LRESULT __stdcall StaticWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
private:
	HINSTANCE mInstance;
	std::string mCommandLine;
	int mShowWindowCommand;
	ATOM mWindowAtom;
	HWND mWindowHandle;
	HDC mWindowDC;
    HGLRC mOpenGLContext;
	bool mPaused;
	
private:
	Application(const Application& rhs);
	Application& operator=(const Application& rhs);
};

}
