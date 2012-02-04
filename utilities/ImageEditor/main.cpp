#define _WIN32_WINNT 0x0501
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commdlg.h>
#include "resource.h"
#include "Image.h"

const unsigned long IMAGE_SCALE = 10;
const std::string defaultFile = "untitled.xmg";

Image* gImage = 0;
std::string lastFile = defaultFile;
COLORREF gColor = 0;
HINSTANCE gInstance = NULL;

LRESULT __stdcall WinProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
void OnPaint(HWND hwnd, HDC hdc);
bool GetFileName(HWND hwnd, bool save, std::string& file);
bool GetImagePoint(LPARAM lparam, unsigned long& ix, unsigned long& iy);

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
	static bool drawing = false;
	static bool erasing = false;
	unsigned long ix = 0;
	unsigned long iy = 0;
	
	switch(msg)
	{
	case WM_CREATE:
		gImage = new Image();
		gImage->New(32, 35);
		break;
	
	case WM_DESTROY:
		delete gImage;
		gImage = 0;
		::PostQuitMessage(0);
		break;
		
	case WM_CLOSE:
		if (gImage->IsDirty())
		{
			int cmd = ::MessageBox(hwnd, "Save changes to image?", "Save Changes", MB_YESNOCANCEL);
			switch(cmd)
			{
			case IDYES:
				if (lastFile != defaultFile || GetFileName(hwnd, true, lastFile))
					gImage->Save(lastFile);
				else
					return 0;	//Cancel close because save was cancelled
				break;
			case IDNO:
				//nothing
				break;
			case IDCANCEL:
				return 0;	//By not calling DefWindowProc, DestroyWindow will not get called
			}
		}
		break;
		
	case WM_COMMAND:
		if (HIWORD(wparam) == 0)
		{
			switch(LOWORD(wparam))
			{
			case ID_FILE_NEW:
				//TODO: get dimensions from a popup
				gImage->New(32, 35);
				lastFile = defaultFile;
				::InvalidateRect(hwnd, NULL, TRUE);
				break;
			case ID_FILE_OPEN:
				if (GetFileName(hwnd, false, lastFile))
				{
					gImage->Load(lastFile);
					::InvalidateRect(hwnd, NULL, TRUE);
				}
				break;
			case ID_FILE_SAVE:
				if (lastFile != defaultFile || GetFileName(hwnd, true, lastFile))
					gImage->Save(lastFile);
				break;
			case ID_FILE_SAVEAS:
				if (GetFileName(hwnd, true, lastFile))
					gImage->Save(lastFile);
				break;
			case ID_FILE_EXIT:
				::PostMessage(hwnd, WM_CLOSE, 0, 0);
				break;
			case ID_EDIT_COLOR:
				{
					CHOOSECOLOR cc = {0};
					static COLORREF customColors[16] = {0};
					cc.lStructSize = sizeof(cc);
					cc.hwndOwner = hwnd;
					cc.hInstance = NULL;
					cc.rgbResult = gColor;
					cc.lpCustColors = customColors;
					cc.Flags = CC_RGBINIT|CC_FULLOPEN|CC_ANYCOLOR;
					if (::ChooseColor(&cc))
						gColor = cc.rgbResult;
				}
				break;
			}
		}
		break;
		
	case WM_PAINT:
		{
			PAINTSTRUCT ps = {0};
			HDC hdc = ::BeginPaint(hwnd, &ps);
			OnPaint(hwnd, hdc);
			::EndPaint(hwnd, &ps);
		}
		break;
		
	case WM_LBUTTONDOWN:
		if (!drawing)
		{
			::SetCapture(hwnd);
			drawing = true;
			erasing = false;
			if (GetImagePoint(lparam, ix, iy))
			{
				if ((wparam & MK_SHIFT) == MK_SHIFT)
					gImage->Fill(ix, iy, gColor);
				else
					gImage->SetPixel(ix, iy, gColor);
				::InvalidateRect(hwnd, NULL, FALSE);
			}
		}
		break;

	case WM_RBUTTONDOWN:
		if (!drawing)
		{
			::SetCapture(hwnd);
			drawing = true;
			erasing = true;
			if (GetImagePoint(lparam, ix, iy))
			{
				if ((wparam & MK_SHIFT) == MK_SHIFT)
					gImage->ClearFill(ix, iy);
				else
					gImage->ClearPixel(ix, iy);
				::InvalidateRect(hwnd, NULL, FALSE);
			}
		}
		break;
		
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		if (drawing)
		{
			::ReleaseCapture();
			drawing = false;
			erasing = false;
		}
		break;
		
	case WM_MOUSEMOVE:
		if (drawing && GetImagePoint(lparam, ix, iy))
		{
			if (erasing)
				gImage->ClearPixel(ix, iy);
			else
				gImage->SetPixel(ix, iy, gColor);
			::InvalidateRect(hwnd, NULL, FALSE);
		}
		break;
	}
	return ::DefWindowProc(hwnd, msg, wparam, lparam);
}

bool GetImagePoint(LPARAM lparam, unsigned long& ix, unsigned long& iy)
{
	unsigned long x = LOWORD(lparam);
	unsigned long y = HIWORD(lparam);
	ix = x / (IMAGE_SCALE + 1);
	iy = y / (IMAGE_SCALE + 1);
	return ix < gImage->GetWidth() && iy < gImage->GetHeight();
}

void OnPaint(HWND hwnd, HDC hdc)
{
	unsigned long width = gImage->GetWidth() * (IMAGE_SCALE + 1) + 1;
	unsigned long height = gImage->GetHeight() * (IMAGE_SCALE + 1) + 1;
	for (unsigned long ix = 0; ix <= gImage->GetWidth(); ++ix)
	{
		unsigned long x = ix * (IMAGE_SCALE + 1);
		::MoveToEx(hdc, x, 0, NULL);
		::LineTo(hdc, x, height);
	}
	for (unsigned long iy = 0; iy <= gImage->GetHeight(); ++iy)
	{
		unsigned long y = iy * (IMAGE_SCALE + 1);
		::MoveToEx(hdc, 0, y, NULL);
		::LineTo(hdc, width, y);
	}
	for (unsigned long ix = 0; ix < gImage->GetWidth(); ++ix)
	{
		for (unsigned long iy = 0; iy < gImage->GetHeight(); ++iy)
		{
			unsigned long x = ix * (IMAGE_SCALE + 1) + 1;
			unsigned long y = iy * (IMAGE_SCALE + 1) + 1;
			auto pixel = gImage->GetPixel(ix, iy);
			RECT rect = { x, y, x + IMAGE_SCALE, y + IMAGE_SCALE };
			if (pixel.first)
			{
				HBRUSH brush = ::CreateSolidBrush(pixel.second);
				::FillRect(hdc, &rect, brush);
				::DeleteObject(brush);
			}
			else
			{
				//Draw an X through transparent pixels to distinguish them from white
				::FillRect(hdc, &rect, ::GetSysColorBrush(COLOR_WINDOW));
				::MoveToEx(hdc, x, y, NULL);
				::LineTo(hdc, x + IMAGE_SCALE, y + IMAGE_SCALE);
				::MoveToEx(hdc, x, y + IMAGE_SCALE, NULL);
				::LineTo(hdc, x + IMAGE_SCALE, y);
			}
		}
	}
}

bool GetFileName(HWND hwnd, bool save, std::string& file)
{
	char fileBuffer[MAX_PATH + 1] = "";
	if (file.size() <= MAX_PATH)
		::strcpy(fileBuffer, file.c_str());
	OPENFILENAME ofn = {0};
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.hInstance = gInstance;
	ofn.lpstrFilter = "X-Com Images\0*.xmg\0\0";
	ofn.lpstrFile = fileBuffer;
	ofn.nMaxFile = MAX_PATH + 1;
	ofn.Flags = save ? (OFN_OVERWRITEPROMPT) : (OFN_FILEMUSTEXIST);
	ofn.lpstrDefExt = "xmg";
	if (save)
	{
		if (::GetSaveFileName(&ofn))
		{
			file = ofn.lpstrFile;
			return true;
		}
	}
	else
	{
		if (::GetOpenFileName(&ofn))
		{
			file = ofn.lpstrFile;
			return true;
		}
	}
	return false;
}
