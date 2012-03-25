#pragma once
#include "WindowsInclude.h"
#include <gl/gl.h>
#include "Singleton.h"
#include "Mouse/ArrowKey.h"
#include <string>
#include "IApplication.h"

namespace XCom
{

class Application : public IApplication
{
public:
	Application();
	Application(const Application& rhs) = delete;
	~Application();

	Application& operator=(const Application& rhs) = delete;
	
	virtual int Run(HINSTANCE instance, char* command, int show);
	virtual void Quit();
	virtual void DrawPixels(unsigned char* data);
	virtual HWND GetWindowHandle() const;
	virtual LRESULT CallbackWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
private:
	void CreateWindowAtom();
	void CreateWindowHandle();
	int RunMessageLoop();
	
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
};

}
