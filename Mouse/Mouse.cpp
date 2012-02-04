#include "Mouse.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../Application.h"
#include "../constants.h"

namespace XCom
{

const unsigned char CURSOR_IMAGE[CURSOR_SIZE] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 0, 0, 0, 0, 0, 0, 0,
    1, 2, 3, 0, 0, 0, 0, 0, 0,
    1, 2, 3, 4, 0, 0, 0, 0, 0,
    1, 2, 3, 4, 4, 4, 3, 2, 1,
    1, 2, 3, 4, 4, 3, 2, 1, 0,
    1, 2, 3, 4, 3, 2, 1, 0, 0,
    1, 2, 3, 3, 2, 1, 0, 0, 0,
    1, 2, 3, 2, 1, 0, 0, 0, 0,
    1, 2, 2, 1, 0, 0, 0, 0, 0,
    1, 2, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0,
};

Mouse::Mouse()
	: mVisible(true), mX(0), mY(0)
{
}

Mouse::~Mouse()
{
}

void Mouse::Show(bool visible)
{
	mVisible = visible;
	if (visible)
	{
		//Restore the old position when showing
		POINT pt = { mX, mY };
		::ClientToScreen(Application::Get().GetWindowHandle(), &pt);
		::SetCursorPos(pt.x, pt.y);
	}
	else
	{
		//Store the current position when hiding
		POINT pt = {0};
		::GetCursorPos(&pt);
		::ScreenToClient(Application::Get().GetWindowHandle(), &pt);
		mX = pt.x;
		mY = pt.y;
	}
}

void Mouse::Render()
{
	if (mVisible)
	{
		auto pos = GetPosition();
		GraphicsBuffer::Get().DrawImage(pos.first, pos.second, CURSOR_IMAGE, CURSOR_WIDTH, CURSOR_HEIGHT, 0, 0, CURSOR_WIDTH, CURSOR_HEIGHT, 2, 251);
	}
}

std::pair<unsigned long, unsigned long> Mouse::GetPosition() const
{
	POINT pt = {0};
	::GetCursorPos(&pt);
	::ScreenToClient(Application::Get().GetWindowHandle(), &pt);
	return std::make_pair(
		(pt.x * GAME_WIDTH) / CLIENT_WIDTH,
		GAME_HEIGHT - ((pt.y * GAME_HEIGHT) / CLIENT_HEIGHT) - 1);
}

}
