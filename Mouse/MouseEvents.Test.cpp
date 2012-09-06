#include "MouseEvents.h"
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace XCom
{

TEST_CLASS(MouseEventsTest)
{
public:
	MouseEventsTest()
	{
	}

	virtual void BeginTest()
	{
		mFactory.RegisterObject(mMockMouse);
	}

	virtual void EndTest()
	{
		mMockMouse.Verify();
		mMockTarget.Verify();
	}

	TEST_METHOD(Constructor)
	{
		MouseEvents instance(&mFactory);
		Assert.IsNull(instance.GetFocus(), "Focus");
		Assert.IsTrue(instance.GetStack().empty(), "Stack");
	}

	TEST_METHOD(OnKeyDownNull)
	{
		const char ch = 'F';
		MouseEvents instance(&mFactory);
		instance.OnKeyDown(ch);
	}

	TEST_METHOD(OnKeyDownValid)
	{
		const char ch = 'F';
		mMockTarget.Setup(&IMouseTarget::OnKeyDown, ch);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnKeyDown(ch);
	}

	TEST_METHOD(OnArrowKeyNull)
	{
		const ArrowKey key = ARROW_UP;
		MouseEvents instance(&mFactory);
		instance.OnArrowKey(key);
	}

	TEST_METHOD(OnArrowKeyValid)
	{
		const ArrowKey key = ARROW_UP;
		mMockTarget.Setup(&IMouseTarget::OnArrowKey, key);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnArrowKey(key);
	}

	TEST_METHOD(OnMouseMoveNull)
	{
		const bool leftButton = false;
		const bool rightButton = true;
		MouseEvents instance(&mFactory);
		instance.OnMouseMove(leftButton, rightButton);
	}

	TEST_METHOD(OnMouseMoveValid)
	{
		const bool leftButton = false;
		const bool rightButton = true;
		const unsigned long x = 10;
		const unsigned long y = 20;
		const Position position(x, y);
		mMockMouse.Setup(&IMouse::GetPosition).Returns(position);
		mMockTarget.Setup(&IMouseTarget::OnMouseMove, x, y, leftButton, rightButton);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnMouseMove(leftButton, rightButton);
	}

	TEST_METHOD(OnLButtonDownNull)
	{
		MouseEvents instance(&mFactory);
		instance.OnLButtonDown();
	}

	TEST_METHOD(OnLButtonDownValid)
	{
		const unsigned long x = 10;
		const unsigned long y = 20;
		const Position position(x, y);
		mMockMouse.Setup(&IMouse::GetPosition).Returns(position);
		mMockTarget.Setup(&IMouseTarget::OnLeftButtonDown, x, y);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnLButtonDown();
	}

	TEST_METHOD(OnLButtonUpNull)
	{
		MouseEvents instance(&mFactory);
		instance.OnLButtonUp();
	}

	TEST_METHOD(OnLButtonUpValid)
	{
		const unsigned long x = 10;
		const unsigned long y = 20;
		const Position position(x, y);
		mMockMouse.Setup(&IMouse::GetPosition).Returns(position);
		mMockTarget.Setup(&IMouseTarget::OnLeftButtonUp, x, y);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnLButtonUp();
	}

	TEST_METHOD(OnRButtonDownNull)
	{
		MouseEvents instance(&mFactory);
		instance.OnRButtonDown();
	}

	TEST_METHOD(OnRButtonDownValid)
	{
		const unsigned long x = 10;
		const unsigned long y = 20;
		const Position position(x, y);
		mMockMouse.Setup(&IMouse::GetPosition).Returns(position);
		mMockTarget.Setup(&IMouseTarget::OnRightButtonDown, x, y);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnRButtonDown();
	}

	TEST_METHOD(OnRButtonUpNull)
	{
		MouseEvents instance(&mFactory);
		instance.OnRButtonUp();
	}

	TEST_METHOD(OnRButtonUpValid)
	{
		const unsigned long x = 10;
		const unsigned long y = 20;
		const Position position(x, y);
		mMockMouse.Setup(&IMouse::GetPosition).Returns(position);
		mMockTarget.Setup(&IMouseTarget::OnRightButtonUp, x, y);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		instance.OnRButtonUp();
	}

	TEST_METHOD(CaptureFocus)
	{
		UnitTest::Mock<IMouseTarget> mMockFocus;
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockFocus.GetObject().get());
		instance.CaptureFocus(mMockTarget.GetObject().get());
		Assert.AreEqual(mMockTarget.GetObject().get(), instance.GetFocus(), "Focus");
		Assert.IsFalse(instance.GetStack().empty(), "Stack.Empty");
		Assert.AreEqual(mMockFocus.GetObject().get(), instance.GetStack().top(), "Stack.Top");
	}

	TEST_METHOD(ReleaseFocusEmpty)
	{
		MouseEvents instance(&mFactory);
		Assert.Throws([&]{ instance.ReleaseFocus(); }, "ReleaseFocus was called without a matching call to CaptureFocus.");
	}

	TEST_METHOD(ReleaseFocusValid)
	{
		MouseEvents instance(&mFactory);
		instance.GetStack().push(mMockTarget.GetObject().get());
		instance.ReleaseFocus();
		Assert.AreEqual(mMockTarget.GetObject().get(), instance.GetFocus(), "Focus");
		Assert.IsTrue(instance.GetStack().empty(), "Stack.Empty");
	}

	TEST_METHOD(HasFocusEqual)
	{
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		bool result = instance.HasFocus(mMockTarget.GetObject().get());
		Assert.IsTrue(result, "Result");
	}

	TEST_METHOD(HasFocusNull)
	{
		MouseEvents instance(&mFactory);
		bool result = instance.HasFocus(mMockTarget.GetObject().get());
		Assert.IsFalse(result, "Result");
	}

	TEST_METHOD(HasFocusIsChild)
	{
		UnitTest::Mock<IMouseTarget> mockOther;
		mMockTarget.Setup(&IMouseTarget::IsChild, mockOther.GetObject().get()).Returns(true);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		bool result = instance.HasFocus(mockOther.GetObject().get());
		Assert.IsTrue(result, "Result");
	}

	TEST_METHOD(HasFocusIsNotChild)
	{
		UnitTest::Mock<IMouseTarget> mockOther;
		mMockTarget.Setup(&IMouseTarget::IsChild, mockOther.GetObject().get()).Returns(false);
		MouseEvents instance(&mFactory);
		instance.SetFocus(mMockTarget.GetObject().get());
		bool result = instance.HasFocus(mockOther.GetObject().get());
		Assert.IsFalse(result, "Result");
	}

private:
	UnitTest::Factory mFactory;
	UnitTest::Mock<IMouse> mMockMouse;
	UnitTest::Mock<IMouseTarget> mMockTarget;
};

}
