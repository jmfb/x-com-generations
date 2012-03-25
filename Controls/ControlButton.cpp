#include "ControlButton.h"
#include "../Fonts/Font.h"
#include "../Mouse/MouseEvents.h"
#include "../Mouse/Mouse.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../FactoryInject.h"

namespace XCom
{

ControlButton::ControlButton()
	: mParent(0), mId(0), mX(0), mY(0), mWidth(0), mHeight(0),
	mInterval(0), mScheme(SCHEME_WHITE), mFont(FONT_NORMAL),
	mPushed(false), mDeep(false)
{
	mLastRepeat = UnitTest::Inject<IDateTime>::Resolve();
}

ControlButton::~ControlButton()
{
}

void ControlButton::Init(
	BaseScreen* parent,
	unsigned long x,
	unsigned long y,
	unsigned long width,
	unsigned long height,
	const std::string& text,
	ColorSchemeType scheme,
	unsigned long id)
{
	mId = id;
	SetPosition(x, y, width, height);
	SetText(text);
	SetScheme(scheme);
	mParent = parent;
	mParent->AddObject(this);
	mParent->AddTarget(this);
}

void ControlButton::SetPosition(unsigned long x, unsigned long y, unsigned long width, unsigned long height)
{
	mX = x;
	mY = y;
	mWidth = width;
	mHeight = height;
}

void ControlButton::SetText(const std::string& text)
{
	mText = text;
}

void ControlButton::SetScheme(ColorSchemeType scheme)
{
	mScheme = scheme;
}

void ControlButton::SetPushed(bool pushed)
{
	mPushed = pushed;
	if (mPushed)
		mLastRepeat->SetNow();
}

void ControlButton::SetDeep()
{
	mDeep = true;
}

void ControlButton::SetFont(FontType font)
{
	mFont = font;
}

void ControlButton::Repeat(unsigned long interval)
{
	mInterval = interval;
	RegisterForIdle();
}

void ControlButton::OnIdle()
{
	if (mInterval > 0 && mPushed && mLastRepeat->TestInterval(mInterval))
		mParent->OnButton(mId);
}

void ControlButton::Render() const
{
	RenderButton();

	//Draw the text on the button centered horizontally and vertically
	ColorScheme scheme = ColorScheme::Get(mScheme);
	if (mPushed)
		scheme = scheme.GetInverse();
	Font font(mFont);
	unsigned long x = mX + (mWidth - font.Measure(mText)) / 2;
	unsigned long y = mY - (mHeight - font.GetHeight() + 1) / 2;
	font.Render(x, y, mText, scheme);
}

bool ControlButton::HitTest(unsigned long x, unsigned long y) const
{
	return (x - mX) < mWidth && (mY - y) < mHeight;
}

void ControlButton::OnMouseMove(unsigned long x, unsigned long y, bool leftButton, bool rightButton)
{
	if (!mPushed && !mDeep && leftButton)
		OnLeftButtonDown(x, y);
}

void ControlButton::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	if (!mDeep)
	{
		SetPushed(true);
		UnitTest::Inject<IMouseEvents>::Resolve()->CaptureFocus(this);
		UnitTest::Inject<IMouse>::Resolve()->Show(false);
	}
	else if (!mPushed)
	{
		SetPushed(true);
		mParent->OnButton(mId);
	}
}

void ControlButton::OnLeftButtonUp(unsigned long x, unsigned long y)
{
	if (!mDeep && mPushed)
	{
		SetPushed(false);
		UnitTest::Inject<IMouseEvents>::Resolve()->ReleaseFocus();
		UnitTest::Inject<IMouse>::Resolve()->Show(true);
		mParent->OnButton(mId);
	}
}

void ControlButton::RenderButton() const
{
	ColorScheme scheme = ColorScheme::Get(mScheme);
	if (mPushed)
		scheme = scheme.GetInverse();
	
    auto graphics = UnitTest::Inject<IGraphicsBuffer>::Resolve();
	graphics->SetBrush(scheme[COLOR_LIGHTER]);
    graphics->DrawHorizontalLine(mX, mY, mWidth - 1);
    graphics->DrawVerticalLine(mX, mY, mHeight);
	graphics->SetBrush(scheme[COLOR_LIGHT]);
    graphics->DrawHorizontalLine(mX + 1, mY - 1, mWidth - 3);
    graphics->DrawVerticalLine(mX + 1, mY - 1, mHeight - 2);
	graphics->SetBrush(scheme[COLOR_LIGHTDARK]);
    graphics->DrawRect(mX + 2, mY - 2, mWidth - 4, mHeight - 4);
	graphics->SetBrush(scheme[COLOR_DARK]);
    graphics->DrawHorizontalLine(mX + 2, mY - mHeight + 2, mWidth - 3);
    graphics->DrawVerticalLine(mX + mWidth - 2, mY - 1, mHeight - 2);
	graphics->SetBrush(scheme[COLOR_DARKER]);
    graphics->DrawHorizontalLine(mX + 1, mY - mHeight + 1, mWidth - 1);
    graphics->DrawVerticalLine(mX + mWidth - 1, mY, mHeight);
}

}
