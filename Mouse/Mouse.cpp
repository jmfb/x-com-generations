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

Mouse::Mouse(ISystemPtr system)
	: mSystem(system), mVisible(true), mPreviousPosition(0, 0)
{
}

Mouse::~Mouse()
{
}

void Mouse::Show(bool visible)
{
	mVisible = visible;
	if (visible)
		mSystem->SetCursorPosition(mSystem->ConvertPositionFromClient(Application::Get().GetWindowHandle(), mPreviousPosition));
	else
		mPreviousPosition = mSystem->ConvertPositionToClient(Application::Get().GetWindowHandle(), mSystem->GetCursorPosition());
}

void Mouse::Render()
{
	if (mVisible)
	{
		auto pos = GetPosition();
		GraphicsBuffer::Get().DrawImage(pos.first, pos.second, CURSOR_IMAGE, CURSOR_WIDTH, CURSOR_HEIGHT, 0, 0, CURSOR_WIDTH, CURSOR_HEIGHT, 2, 251);
	}
}

Position Mouse::GetPosition() const
{
	auto position = mSystem->ConvertPositionToClient(Application::Get().GetWindowHandle(), mSystem->GetCursorPosition());
	return std::make_pair(
		(position.first * GAME_WIDTH) / CLIENT_WIDTH,
		GAME_HEIGHT - ((position.second * GAME_HEIGHT) / CLIENT_HEIGHT) - 1);
}

bool Mouse::GetVisible() const
{
	return mVisible;
}

Position Mouse::GetPreviousPosition() const
{
	return mPreviousPosition;
}

}
