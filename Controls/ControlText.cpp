#include "ControlText.h"
#include "../Fonts/Font.h"
#include "../constants.h"

namespace XCom
{

ControlText::ControlText()
	: mX(0), mY(0), mFont(FONT_NORMAL), mScheme(SCHEME_WHITE)
{
}

ControlText::~ControlText()
{
}

void ControlText::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	const std::string& text,
	FontType font,
	ColorSchemeType scheme)
{
	SetText(text);
	SetFont(font);
	SetPosition(x, y);
	SetScheme(scheme);
	parent->AddObject(this);
}

void ControlText::SetPosition(unsigned long x, unsigned long y)
{
	if (x == X_CENTER)
		Center(y);
	else
	{
		mX = x;
		mY = y;
	}
}

void ControlText::SetText(const std::string& text)
{
	mText = text;
}

void ControlText::SetFont(FontType font)
{
	mFont = font;
}

void ControlText::SetScheme(ColorSchemeType scheme)
{
	mScheme = scheme;
}

void ControlText::Center(unsigned long y)
{
	Font font(mFont);
	mX = (GAME_WIDTH - font.Measure(mText)) / 2;
	mY = y;
}

void ControlText::ReCenter(unsigned long width)
{
	Font font(mFont);
	mX += (width - font.Measure(mText)) / 2;
}

unsigned long ControlText::GetY() const
{
	return mY;
}

unsigned long ControlText::GetRightEdge() const
{
	Font font(mFont);
	return mX + font.Measure(mText);
}

FontType ControlText::GetFont() const
{
	return mFont;
}

const std::string& ControlText::GetText() const
{
	return mText;
}

void ControlText::Render() const
{
	Font(mFont).Render(mX, mY, mText, ColorScheme::Get(mScheme));
}

}
