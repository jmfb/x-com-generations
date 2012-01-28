#include <windows.h>
#include "Application.h"

int __stdcall WinMain(HINSTANCE instance, HINSTANCE previous, char* command, int show)
{
	return XCom::Application(instance, command, show).Run();
}
