#include "Mouse.h"
#include "../IApplication.h"
#include "../System/ISystem.h"
#include "../Graphics/IGraphicsBuffer.h"
using UnitTest::Assert;

namespace XCom
{

TEST_CLASS(MouseTest)
{
public:
	MouseTest()
	{
	}

	virtual void BeginTest()
	{
		mFactory.RegisterObject(mMockApplication);
		mFactory.RegisterObject(mMockSystem);
		mFactory.RegisterObject(mMockGraphics);
	}

	virtual void EndTest()
	{
		mMockApplication.Verify();
		mMockSystem.Verify();
		mMockGraphics.Verify();
	}

	TEST_METHOD(Constructor)
	{
		Mouse mouse(&mFactory);
		Assert.IsTrue(mouse.GetVisible(), "Visible");
		Assert.AreEqual(Position(0, 0), mouse.GetPreviousPosition(), "PreviousPosition");
	}

	TEST_METHOD(ShowTrue)
	{
		const Position position(111, 222);
		const Position convertedPosition(333, 444);
		const HWND windowHandle = reinterpret_cast<HWND>(0x12345678);
		mMockApplication.Setup(&IApplication::GetWindowHandle).Returns(windowHandle);
		mMockSystem.Setup(&ISystem::ConvertPositionFromClient, windowHandle, position).Returns(convertedPosition);
		mMockSystem.Setup(&ISystem::SetCursorPosition, convertedPosition);

		Mouse mouse(&mFactory);
		mouse.SetPreviousPosition(position);
		mouse.Show(true);
		Assert.IsTrue(mouse.GetVisible(), "Visible");
	}

	TEST_METHOD(ShowFalse)
	{
		const Position position(111, 222);
		const Position convertedPosition(333, 444);
		const HWND windowHandle = reinterpret_cast<HWND>(0x12345678);
		mMockApplication.Setup(&IApplication::GetWindowHandle).Returns(windowHandle);
		mMockSystem.Setup(&ISystem::GetCursorPosition).Returns(position);
		mMockSystem.Setup(&ISystem::ConvertPositionToClient, windowHandle, position).Returns(convertedPosition);

		Mouse mouse(&mFactory);
		mouse.Show(false);
		Assert.IsFalse(mouse.GetVisible(), "Visible");
		Assert.AreEqual(convertedPosition, mouse.GetPreviousPosition(), "PreviousPosition");
	}

	void SetupGetPosition(const Position& position)
	{
		const HWND windowHandle = reinterpret_cast<HWND>(0x12345678);
		const Position originalPosition(30, 40);
		const unsigned long x = (position.first * CLIENT_WIDTH) / GAME_WIDTH;
		const unsigned long y = ((GAME_HEIGHT - position.second - 1) * CLIENT_HEIGHT) / GAME_HEIGHT;
		const Position convertedPosition(x, y);
		mMockApplication.Setup(&IApplication::GetWindowHandle).Returns(windowHandle);
		mMockSystem.Setup(&ISystem::GetCursorPosition).Returns(originalPosition);
		mMockSystem.Setup(&ISystem::ConvertPositionToClient, windowHandle, originalPosition).Returns(convertedPosition);
	}

	TEST_METHOD(RenderWhenNotVisible)
	{
		Mouse mouse(&mFactory);
		mouse.SetVisible(false);
		mouse.Render();
	}

	TEST_METHOD(RenderWhenVisible)
	{
		const unsigned long x = 10;
		const unsigned long y = 20;
		SetupGetPosition(Position(x, y));
		mMockGraphics.Setup(&IGraphicsBuffer::DrawImage, x, y,
			UnitTest::Any::Match, CURSOR_WIDTH, CURSOR_HEIGHT,
			0, 0, CURSOR_WIDTH, CURSOR_HEIGHT,
			2, 251);

		Mouse mouse(&mFactory);
		mouse.Render();
	}

	TEST_METHOD(GetPosition)
	{
		const Position position(10, 20);
		SetupGetPosition(position);

		Mouse mouse(&mFactory);
		auto result = mouse.GetPosition();
		Assert.AreEqual(position, result);
	}

private:
	UnitTest::Factory mFactory;
	UnitTest::Mock<IApplication> mMockApplication;
	UnitTest::Mock<ISystem> mMockSystem;
	UnitTest::Mock<IGraphicsBuffer> mMockGraphics;
};

}
