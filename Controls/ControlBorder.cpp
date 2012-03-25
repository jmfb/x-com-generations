#include "ControlBorder.h"
#include "../Graphics/GraphicsBuffer.h"
#include "../FactoryInject.h"

namespace XCom
{

ControlBorder::ControlBorder()
	: mX(0), mY(0), mWidth(0), mHeight(0),
	mScheme(SCHEME_WHITE), mBackground(BACK_TITLE), mPaletteIndex(0)
{
}

ControlBorder::~ControlBorder()
{
}

void ControlBorder::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	unsigned long width, unsigned long height,
	ColorSchemeType scheme,
	BackgroundType background,
	unsigned long paletteIndex)
{
	SetPosition(x, y, width, height);
	SetScheme(scheme);
	mBackground = background;
	mPaletteIndex = paletteIndex;
	parent->AddObject(this);
}

void ControlBorder::SetPosition(unsigned long x, unsigned long y, unsigned long width, unsigned long height)
{
	mX = x;
	mY = y;
	mWidth = width;
	mHeight = height;
}

void ControlBorder::SetScheme(ColorSchemeType scheme)
{
	mScheme = scheme;
}

void ControlBorder::Render() const
{
	auto graphics = UnitTest::Inject<IGraphicsBuffer>::Resolve();
	const ColorScheme& scheme = ColorScheme::Get(mScheme);
	graphics->SetBrush(scheme[COLOR_BASE]);
	graphics->DrawFrame(mX, mY, mWidth, mHeight);
	graphics->DrawFrame(mX + 4, mY - 4, mWidth - 8, mHeight - 8);
	graphics->SetBrush(scheme[COLOR_LIGHT]);
	graphics->DrawFrame(mX + 1, mY - 1, mWidth - 2, mHeight - 2);
	graphics->DrawFrame(mX + 3, mY - 3, mWidth - 6, mHeight - 6);
	graphics->SetBrush(scheme[COLOR_LIGHTER]);
	graphics->DrawFrame(mX + 2, mY - 2, mWidth - 4, mHeight - 4);
	graphics->DrawBackground(mX + 5, mY - 5, mWidth - 10, mHeight - 10, mBackground, mPaletteIndex);
}

}
