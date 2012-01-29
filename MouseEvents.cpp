#include "MouseEvents.h"
#include "Error.h"
#include "Mouse.h"

namespace XCom
{

MouseEvents* MouseEvents::mThis = 0;

MouseEvents::MouseEvents()
	: mFocus(0)
{
	mThis = this;
}

MouseEvents::~MouseEvents()
{
	mThis = 0;
}

MouseEvents& MouseEvents::Get()
{
	CheckError(mThis == 0, 0, "", "Mouse Events entity does not exist.");
	return *mThis;
}

void MouseEvents::OnKeyDown(char ch)
{
	if (mFocus)
		mFocus->OnKeyDown(ch);
}

void MouseEvents::OnMouseMove(bool leftButton, bool rightButton)
{
	if (mFocus)
	{
		auto pos = Mouse::Get().GetPosition();
		mFocus->OnMouseMove(pos.first, pos.second, leftButton, rightButton);
	}
}

void MouseEvents::OnLButtonDown()
{
	if (mFocus)
	{
		auto pos = Mouse::Get().GetPosition();
		mFocus->OnLeftButtonDown(pos.first, pos.second);
	}
}

void MouseEvents::OnLButtonUp()
{
	if (mFocus)
	{
		auto pos = Mouse::Get().GetPosition();
		mFocus->OnLeftButtonUp(pos.first, pos.second);
	}
}

void MouseEvents::OnRButtonDown()
{
	if (mFocus)
	{
		auto pos = Mouse::Get().GetPosition();
		mFocus->OnRightButtonDown(pos.first, pos.second);
	}
}

void MouseEvents::OnRButtonUp()
{
	if (mFocus)
	{
		auto pos = Mouse::Get().GetPosition();
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
	mFocus = mStack.top();
	mStack.pop();
}

bool MouseEvents::HasFocus(const IMouseTarget* target) const
{
	return mFocus == target || (mFocus != 0 && mFocus->IsChild(target));
}

}
