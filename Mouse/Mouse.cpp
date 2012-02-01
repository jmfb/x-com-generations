#include "Mouse.h"
#include "../Error.h"
#include "../Graphics/GraphicsBuffer.h"

namespace XCom
{

Mouse* Mouse::mThis = 0;

const unsigned char CURSOR_IMAGE[Mouse::CURSOR_SIZE] = {
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

Mouse::Mouse(unsigned long gameWidth, unsigned long gameHeight, unsigned long targetWidth, unsigned long targetHeight, HWND& windowHandle)
	: mGameWidth(gameWidth), mGameHeight(gameHeight),
	mTargetWidth(targetWidth), mTargetHeight(targetHeight),
	mWindowHandle(windowHandle),
	mVisible(true), mX(0), mY(0)
{
	mThis = this;
}

Mouse::~Mouse()
{
	mThis = 0;
}

Mouse& Mouse::Get()
{
	CheckError(mThis == 0, 0, "", "Mouse entity does not exist.");
	return *mThis;
}

void Mouse::Show(bool visible)
{
	mVisible = visible;
	if (visible)
	{
		//Restore the old position when showing
		POINT pt = { mX, mY };
		::ClientToScreen(mWindowHandle, &pt);
		::SetCursorPos(pt.x, pt.y);
	}
	else
	{
		//Store the current position when hiding
		POINT pt = {0};
		::GetCursorPos(&pt);
		::ScreenToClient(mWindowHandle, &pt);
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
	::ScreenToClient(mWindowHandle, &pt);
	return std::make_pair(
		(pt.x * mGameWidth) / mTargetWidth,
		mGameHeight - ((pt.y * mGameHeight) / mTargetHeight) - 1);
}

}
