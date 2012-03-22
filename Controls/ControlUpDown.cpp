#include "ControlUpDown.h"
#include "../Fonts/Font.h"
#include "../Mouse/MouseEvents.h"
#include "../Mouse/Mouse.h"
#include "../FactoryInject.h"

namespace XCom
{

ControlUpDown::ControlUpDown()
	: mParent(0), mX(0), mY(0), mId(0), mEnabled(false), mState(STATE_NONE)
{
	mLastUpdate = UnitTest::Inject<IDateTime>::Resolve();
}

ControlUpDown::~ControlUpDown()
{
}

void ControlUpDown::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	ColorSchemeType scheme,
	unsigned long id)
{
	mParent = parent;
	mX = x;
	mY = y;
	mId = id;
	mScheme = ColorScheme::Get(scheme);
	mInverse = mScheme.GetInverse();
	mEnabled = false;
	mState = STATE_NONE;
}

bool ControlUpDown::HitTest(unsigned long x, unsigned long y) const
{
	return (x - mX) < 23 && (mY - y) < 8;
}

void ControlUpDown::OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton)
{
	if (leftButton && mLastUpdate->TestInterval(100))
		OnLeftButtonDown(x, y);
}

void ControlUpDown::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	if (x < mX + 11)
	{
		mState = STATE_UP;
		mLastUpdate->SetNow();
		mParent->OnButton(mId);
	}
	else if (x > mX + 11)
	{
		mState = STATE_DOWN;
		mLastUpdate->SetNow();
		mParent->OnButton(mId);
	}
	else
	{
		mState = STATE_NONE;
	}
}

void ControlUpDown::OnLeftButtonUp(unsigned long x, unsigned long y)
{
	mState = STATE_NONE;
}

void ControlUpDown::Render() const
{
	Font font(FONT_UPDOWN);
	font.Render(mX, mY, "U", mState == STATE_UP ? mInverse : mScheme);
	font.Render(mX + 12, mY, "D", mState == STATE_DOWN ? mInverse : mScheme);
}

void ControlUpDown::OnIdle()
{
	if (mEnabled && mState != STATE_NONE)
	{
		auto pos = UnitTest::Inject<IMouse>::Resolve()->GetPosition();
		if (HitTest(pos.first, pos.second) && MouseEvents::Get().HasFocus(this))
		{
			if (mLastUpdate->TestInterval(100))
				mParent->OnButton(mId);
		}
		else
			mState = STATE_NONE;
	}
}

void ControlUpDown::Enable(bool enabled)
{
	if (mEnabled != enabled)
	{
		mEnabled = enabled;
		if (mEnabled)
		{
			mParent->AddObject(this);
			mParent->AddTarget(this);
			RegisterForIdle();
		}
		else
		{
			UnregisterFromIdle();
			mParent->RemoveObject(this);
			mParent->RemoveTarget(this);
		}
	}
}

UpDownState ControlUpDown::GetState() const
{
	return mState;
}

}
