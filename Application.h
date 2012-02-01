#pragma once
#include "WindowsInclude.h"
#include <string>
#include <gl/gl.h>
#include "Graphics/GraphicsBuffer.h"
#include "Game.h"
#include "Mouse/Mouse.h"
#include "Mouse/MouseEvents.h"
#include "IdleMap.h"
#include "Screens/ScreenManager.h"

namespace XCom
{

class Application
{
public:
	Application(HINSTANCE instance, char* command, int show);
	~Application();
	
	int Run();
	
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
	void OnMouseMove(WPARAM wparam);
	void OnLButtonDown();
	void OnLButtonUp();
	void OnRButtonDown();
	void OnRButtonUp();
	void OnDestroy();
	
	static LRESULT __stdcall StaticWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	
private:
	static Application* mThis;
	HINSTANCE mInstance;
	std::string mCommandLine;
	int mShowWindowCommand;
	ATOM mWindowAtom;
	HWND mWindowHandle;
	HDC mWindowDC;
    HGLRC mOpenGLContext;
	bool mPaused;
	Mouse mMouse;
	MouseEvents mMouseEvents;
	GraphicsBuffer mGraphicsBuffer;
	Game mGame;
	IdleMap mIdleMap;
	ScreenManager mScreenManager;
	
private:
	Application(const Application& rhs);
	Application& operator=(const Application& rhs);
};

}
