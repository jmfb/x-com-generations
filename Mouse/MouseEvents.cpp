#include "MouseEvents.h"
#include "../Error.h"

namespace XCom
{

MouseEvents::MouseEvents(UnitTest::IFactoryPtr factory)
	: mMouse(factory->Resolve<IMouse>()), mFocus(0)
{
}

MouseEvents::~MouseEvents()
{
}

void MouseEvents::OnKeyDown(char ch)
{
	if (mFocus)
		mFocus->OnKeyDown(ch);
}

void MouseEvents::OnArrowKey(ArrowKey key)
{
	if (mFocus)
		mFocus->OnArrowKey(key);
}

void MouseEvents::OnMouseMove(bool leftButton, bool rightButton)
{
	if (mFocus)
	{
		auto pos = mMouse->GetPosition();
		mFocus->OnMouseMove(pos.first, pos.second, leftButton, rightButton);
	}
}

void MouseEvents::OnLButtonDown()
{
	if (mFocus)
	{
		auto pos = mMouse->GetPosition();
		mFocus->OnLeftButtonDown(pos.first, pos.second);
	}
}

void MouseEvents::OnLButtonUp()
{
	if (mFocus)
	{
		auto pos = mMouse->GetPosition();
		mFocus->OnLeftButtonUp(pos.first, pos.second);
	}
}

void MouseEvents::OnRButtonDown()
{
	if (mFocus)
	{
		auto pos = mMouse->GetPosition();
		mFocus->OnRightButtonDown(pos.first, pos.second);
	}
}

void MouseEvents::OnRButtonUp()
{
	if (mFocus)
	{
		auto pos = mMouse->GetPosition();
		mFocus->OnRightButtonUp(pos.first, pos.second);
	}
}

void MouseEvents::CaptureFocus(IMouseTarget* target)
{
	mStack.push(mFocus);
	mFocus = target;
}

void MouseEvents::ReleaseFocus()
{
	CheckError(mStack.empty(), 0, "mStack.empty()", "ReleaseFocus was called without a matching call to CaptureFocus.");
	mFocus = mStack.top();
	mStack.pop();
}

bool MouseEvents::HasFocus(const IMouseTarget* target) const
{
	return mFocus == target || (mFocus != 0 && mFocus->IsChild(target));
}

IMouseTarget* MouseEvents::GetFocus() const
{
	return mFocus;
}

void MouseEvents::SetFocus(IMouseTarget* focus)
{
	mFocus = focus;
}

const std::stack<IMouseTarget*>& MouseEvents::GetStack() const
{
	return mStack;
}

std::stack<IMouseTarget*>& MouseEvents::GetStack()
{
	return mStack;
}

}
