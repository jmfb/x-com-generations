#define _WIN32_WINNT 0x0501
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "resource.h"

HINSTANCE gInstance = NULL;
LRESULT __stdcall WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

int __stdcall WinMain(HINSTANCE instance, HINSTANCE previous, char* command, int show)
{
	gInstance = instance;
	
	//Register the main window
    WNDCLASSEX cls;
    cls.cbSize = sizeof(cls);
    cls.style = CS_OWNDC;
    cls.lpfnWndProc = &::WinProc;
    cls.cbClsExtra = 0;
    cls.cbWndExtra = 0;
    cls.hInstance = gInstance;
    cls.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);
	cls.hCursor = ::LoadCursor(NULL, IDC_ARROW);
    cls.hbrBackground = ::GetSysColorBrush(COLOR_WINDOW);
    cls.lpszMenuName = MAKEINTRESOURCE(IDR_MAINFRAME);
    cls.lpszClassName = "image_editor_wnd";
    cls.hIconSm = cls.hIcon;
    ATOM atom = ::RegisterClassEx(&cls);
	
	//Create the main window
    HWND hwnd = ::CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        MAKEINTRESOURCE(atom),
        "X-Com: Image Editor",
		WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        600,
        500,
        NULL,
        NULL,
        gInstance,
        NULL);
    ::ShowWindow(hwnd, show);
	
	//Run the message loop
	for (MSG msg; ; )
	{
		switch(::GetMessage(&msg, NULL, 0, 0))
		{
		case -1:
			continue;
		case 0:
			return(msg.wParam);
		}
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}

LRESULT __stdcall WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch(msg)
	{
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
		
	case WM_COMMAND:
		if (HIWORD(wparam) == 0)
		{
			switch(LOWORD(wparam))
			{
			case ID_FILE_NEW:
				break;
			case ID_FILE_OPEN:
				break;
			case ID_FILE_SAVE:
				break;
			case ID_FILE_SAVEAS:
				break;
			case ID_FILE_EXIT:
				::PostMessage(hwnd, WM_CLOSE, 0, 0);
				break;
			}
		}
		break;
	}
	return ::DefWindowProc(hwnd, msg, wparam, lparam);
}
