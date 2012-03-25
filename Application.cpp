#include "Application.h"
#include "Error.h"
#include "constants.h"
#include "Mouse/MouseEvents.h"
#include "IdleMap.h"
#include "Screens/ScreenManager.h"
#include "Game.h"
#include "Graphics/GraphicsBuffer.h"
#include "FactoryInject.h"

namespace XCom
{

Application::Application()
	: mInstance(NULL),
	mShowWindowCommand(0),
	mWindowAtom(0),
	mWindowHandle(NULL),
	mWindowDC(NULL),
	mOpenGLContext(NULL),
	mPaused(false)
{
}

Application::~Application()
{
}

int Application::Run(HINSTANCE instance, char* command, int show)
{
	mInstance = instance;
	mCommandLine = command;
	mShowWindowCommand = show;
	
	int retval = ERROR_SUCCESS;
	try
	{
		CreateWindowAtom();
		CreateWindowHandle();
		retval = RunMessageLoop();
	}
	catch (const Error& error)
	{
		error.Report();
		retval = error.GetCode();
	}
	catch (...)
	{
		ReportUnhandled();
		retval = Error::UNHANDLED_EXCEPTION;
	}
	return retval;
}

void Application::Quit()
{
	::PostMessage(mWindowHandle, WM_CLOSE, 0, 0);
}

void Application::DrawPixels(unsigned char* data)
{
	::glRasterPos2i(0, 0);
	::glDrawPixels(CLIENT_WIDTH, CLIENT_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, data);
}

HWND Application::GetWindowHandle() const
{
	return mWindowHandle;
}

void Application::CreateWindowAtom()
{
    //Register the window class
    WNDCLASSEX cls;
    cls.cbSize = sizeof(cls);
    cls.style = CS_OWNDC;
    cls.lpfnWndProc = &Application::StaticWindowProc;
    cls.cbClsExtra = 0;
    cls.cbWndExtra = 0;
    cls.hInstance = mInstance;
    cls.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	cls.hCursor = ::LoadCursor(NULL, IDC_ARROW);
    cls.hbrBackground = NULL;
    cls.lpszMenuName = NULL;
    cls.lpszClassName = "xcom_wnd";
    cls.hIconSm = cls.hIcon;
    
    mWindowAtom = ::RegisterClassEx(&cls);
	CheckWindowsError(mWindowAtom == 0, "RegisterClassEx");
}

void Application::CreateWindowHandle()
{
	unsigned long style = WS_OVERLAPPEDWINDOW & ~(WS_OVERLAPPED | WS_THICKFRAME | WS_MAXIMIZEBOX);
	RECT rect = {0, 0, CLIENT_WIDTH, CLIENT_HEIGHT};
	::AdjustWindowRectEx(&rect, style, FALSE, WS_EX_WINDOWEDGE);

    HWND hwnd = ::CreateWindowEx(
        WS_EX_WINDOWEDGE,
        MAKEINTRESOURCE(mWindowAtom),
        "X-Com: UFO Defense",
		style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        mInstance,
        NULL);
	CheckWindowsError(hwnd == NULL, "CreateWindowEx");
	CheckError(mWindowHandle == NULL, 0, "CreateWindowEx", "Window handle member was still null.");

    //Show the window
    ::ShowWindow(mWindowHandle, mShowWindowCommand);
}

int Application::RunMessageLoop()
{
    try
    {
        for (MSG msg;;)
        {
			//Peek to see if there are messages to process
            if (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
            {
                switch(::GetMessage(&msg, NULL, 0, 0))
                {
                case -1:
					CheckWindowsError(true, "GetMessage");

                case 0:
                    return(msg.wParam);
                }

                ::TranslateMessage(&msg);
                ::DispatchMessage(&msg);
            }
            else if (!mPaused)
            {
                //render another frame
				IdleMap::Get().OnIdle();
				OnPaint(false);
				
				//NOTE: This doesn't seem necessary, but leaving in to
				//reduce the CPU usage.
				::Sleep(1);
            }
			else
			{
				//We have no messages in the queue and we are not the active window
				::Sleep(1);
			}
        }
    }
    catch (const Error& error)
    {
		error.Report();
		return error.GetCode() ? error.GetCode() : -1;
    }
    catch (...)
    {
        ReportUnhandled();
        return Error::UNHANDLED_EXCEPTION;
    }
}

LRESULT Application::CallbackWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch(msg)
	{
	case WM_CREATE:
		OnCreate(hwnd);
		return 0;
	
	case WM_SIZE:
		OnSize();
		return 0;
	
    case WM_ACTIVATE:
        mPaused = (LOWORD(wparam) == WA_INACTIVE);
        break;
		
	case WM_SETCURSOR:
		if (OnSetCursor(lparam))
			return TRUE;
		break;
	
    case WM_PAINT:
		OnPaint(true);
        return 0;

	case WM_KEYDOWN:
		switch(wparam)
		{
		case VK_UP:
			OnArrowKey(ARROW_UP);
			return 0;
		case VK_DOWN:
			OnArrowKey(ARROW_DOWN);
			return 0;
		case VK_LEFT:
			OnArrowKey(ARROW_LEFT);
			return 0;
		case VK_RIGHT:
			OnArrowKey(ARROW_RIGHT);
			return 0;
		}
		break;
		
    case WM_CHAR:
		OnKeyDown(static_cast<char>(wparam));
        return 0;

    case WM_MOUSEMOVE:
        OnMouseMove(wparam);
        return 0;

    case WM_LBUTTONDOWN:
        OnLButtonDown();
        return 0;

    case WM_LBUTTONUP:
        OnLButtonUp();
        return 0;

    case WM_RBUTTONDOWN:
        OnRButtonDown();
        return 0;

    case WM_RBUTTONUP:
        OnRButtonUp();
        return 0;
	
	case WM_DESTROY:
		OnDestroy();
		return 0;
	}
    return ::DefWindowProc(hwnd, msg, wparam, lparam);
}

void Application::OnCreate(HWND hwnd)
{
	CheckError(hwnd == NULL, 0, "", "Window handle was null from window procedure.");
	CheckError(mWindowHandle != NULL, 0, "", "Window handle member was already set.");
	mWindowHandle = hwnd;

    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(pfd),
        1,
        PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        24,
        0,0,0,0,0,0,
        0,0,
        0,0,0,0,0,
        32,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0,0,0
    };
	
	//make sure to remove the window border
	//TODO: add back in for full screen mode
	//::SetWindowPos(mWindowHandle, NULL, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_NOZORDER|SWP_FRAMECHANGED);

	//make sure the window is the foreground window and has keyboard focus
	::SetForegroundWindow(mWindowHandle);
	::SetFocus(mWindowHandle);

	//setup OpenGL in the window's device context
	mWindowDC = ::GetDC(mWindowHandle);
	::SetPixelFormat(mWindowDC, ::ChoosePixelFormat(mWindowDC, &pfd), &pfd);
	mOpenGLContext = ::wglCreateContext(mWindowDC);
	::wglMakeCurrent(mWindowDC, mOpenGLContext);

	//Setup pixel operations to be on byte boundaries
	::glPixelStorei(GL_PACK_ALIGNMENT, 1);
	::glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	//Set the main menu screen
	ScreenManager::Get().Set(SCREEN_MAIN_MENU);
}

void Application::OnSize()
{
	//Set the viewport to the entire window
	::glViewport(0, 0, CLIENT_WIDTH, CLIENT_HEIGHT);
	::glLoadIdentity();

	//Set the x and y ranges to that of the game height and width
	::glOrtho(0.0f, CLIENT_WIDTH, 0.0f, CLIENT_HEIGHT, 1.0f, -1.0f);
}

bool Application::OnSetCursor(LPARAM lparam)
{
	//We draw our own cursor in the client region
	if ((lparam & HTCLIENT) == HTCLIENT)
	{
		::SetCursor(NULL);
		return true;
	}
	return false;
}

void Application::OnPaint(bool validate)
{
	//Render the game screen and re-validate the window
	Game::Get().RenderScene();
	UnitTest::Inject<IGraphicsBuffer>::Resolve()->Commit();
    ::glFlush();
    ::SwapBuffers(::wglGetCurrentDC());
	if (validate)
		::ValidateRect(mWindowHandle, NULL);
}

void Application::OnKeyDown(char ch)
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnKeyDown(ch);
}

void Application::OnArrowKey(ArrowKey key)
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnArrowKey(key);
}

void Application::OnMouseMove(WPARAM wparam)
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnMouseMove((wparam & MK_LBUTTON) == MK_LBUTTON, (wparam & MK_RBUTTON) == MK_RBUTTON);
}

void Application::OnLButtonDown()
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnLButtonDown();
}

void Application::OnLButtonUp()
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnLButtonUp();
}

void Application::OnRButtonDown()
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnRButtonDown();
}

void Application::OnRButtonUp()
{
	UnitTest::Inject<IMouseEvents>::Resolve()->OnRButtonUp();
}

void Application::OnDestroy()
{
	//Cleanup the OpenGL resources
	::wglMakeCurrent(mWindowDC, NULL);
	::wglDeleteContext(mOpenGLContext);
	
	//Terminate the message loop
	::PostQuitMessage(0);
}

LRESULT __stdcall Application::StaticWindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	return UnitTest::Inject<IApplication>::Resolve()->CallbackWindowProc(hwnd, msg, wparam, lparam);
}

}
