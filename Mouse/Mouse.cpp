#include "Mouse.h"
#include "../Graphics/IGraphicsBuffer.h"
#include "../IApplication.h"
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

Mouse::Mouse(UnitTest::IFactoryPtr factory)
	: mFactory(factory), mVisible(true), mPreviousPosition(0, 0)
{
}

Mouse::~Mouse()
{
}

void Mouse::Show(bool visible)
{
	auto application = mFactory->Resolve<IApplication>();
	auto system = mFactory->Resolve<ISystem>();
	mVisible = visible;
	if (visible)
		system->SetCursorPosition(system->ConvertPositionFromClient(application->GetWindowHandle(), mPreviousPosition));
	else
		mPreviousPosition = system->ConvertPositionToClient(application->GetWindowHandle(), system->GetCursorPosition());
}

void Mouse::Render()
{
	if (mVisible)
	{
		auto pos = GetPosition();
		mFactory->Resolve<IGraphicsBuffer>()->DrawImage(pos.first, pos.second, CURSOR_IMAGE, CURSOR_WIDTH, CURSOR_HEIGHT, 0, 0, CURSOR_WIDTH, CURSOR_HEIGHT, 2, 251);
	}
}

Position Mouse::GetPosition() const
{
	auto application = mFactory->Resolve<IApplication>();
	auto system = mFactory->Resolve<ISystem>();
	auto position = system->ConvertPositionToClient(application->GetWindowHandle(), system->GetCursorPosition());
	return Position(
		(position.first * GAME_WIDTH) / CLIENT_WIDTH,
		GAME_HEIGHT - ((position.second * GAME_HEIGHT) / CLIENT_HEIGHT) - 1);
}

bool Mouse::GetVisible() const
{
	return mVisible;
}

void Mouse::SetVisible(bool visible)
{
	mVisible = visible;
}

Position Mouse::GetPreviousPosition() const
{
	return mPreviousPosition;
}

void Mouse::SetPreviousPosition(const Position& position)
{
	mPreviousPosition = position;
}

}
