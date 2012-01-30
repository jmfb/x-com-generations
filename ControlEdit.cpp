#include "ControlEdit.h"
#include "MouseEvents.h"
#include "Mouse.h"
#include "Font.h"

namespace XCom
{

ControlEdit::ControlEdit()
	: mParent(0), mWidth(0), mStyle(EDIT_NORMAL), mId(0), mInEdit(false), mCursorBlink(false)
{
}

ControlEdit::~ControlEdit()
{
}

void ControlEdit::Init(
	BaseScreen* parent,
	unsigned long x, unsigned long y,
	unsigned long width,
	EditStyle style,
	const std::string& text,
	FontType font,
	ColorSchemeType scheme,
	unsigned long id)
{
	ControlText::Init(parent, x, y, text, font, scheme);
	mParent = parent;
	mWidth = width;
	mStyle = style;
	mId = id;
	mParent->AddTarget(this);
}

void ControlEdit::BeginEdit()
{
	if (!mInEdit)
	{
		mInEdit = true;
		MouseEvents::Get().CaptureFocus(this);
		Mouse::Get().Show(false);
	}
}

bool ControlEdit::HitTest(unsigned long x, unsigned long y) const
{
	return (x - mX) < mWidth && (mY - y) < Font(mFont).GetHeight();
}

void ControlEdit::OnLeftButtonDown(unsigned long x, unsigned long y)
{
	if (mStyle == EDIT_CLICK && !mInEdit)
		BeginEdit();
}

void ControlEdit::OnKeyDown(char ch)
{
	if (mInEdit)
	{
		switch(ch)
		{
		//Invalid characters that can be typed - ignore
		case VK_ESCAPE:
		case 0x0a:
		case VK_TAB:
		case '`':
			break;
		
		//Backspace - delete the last character
		case VK_BACK:
			if (!mText.empty())
				mText.erase(mText.end() - 1);
			break;
			
		//Enter - finish editing and notify parent
		case VK_RETURN:
			MouseEvents::Get().ReleaseFocus();
			Mouse::Get().Show(true);
			mInEdit = false;
			mParent->OnButton(mId);
			break;
		
		//Typed a normal character, append if space available on screen
		default:
			if (Font(mFont).Measure((mText + ch) + "*") <= mWidth)
				mText += ch;
		}
	}
}

void ControlEdit::Render() const
{
	ControlText::Render();
	if (mInEdit && mLastCursorBlink.TestInterval(250))
		mCursorBlink = !mCursorBlink;
	if (mInEdit && mCursorBlink)
		Font(mFont).Render(GetRightEdge(), mY, "*", ColorScheme::Get(mScheme));
}

}
