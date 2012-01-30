#include "ControlEllipsis.h"
#include "Font.h"
#include <string>

namespace XCom
{

ControlEllipsis::ControlEllipsis()
	: mBuddy(0), mRightEdge(0), mScheme(SCHEME_WHITE), mEnabled(false)
{
}

ControlEllipsis::~ControlEllipsis()
{
}

void ControlEllipsis::Init(
	BaseScreen* parent,
	ControlText* buddy,
	unsigned long rightEdge,
	bool enabled,
	ColorSchemeType scheme)
{
	mBuddy = buddy;
	mRightEdge = rightEdge;
	mScheme = scheme;
	mEnabled = enabled;
	parent->AddObject(this);
}

void ControlEllipsis::Enable(bool enabled)
{
	mEnabled = enabled;
}

void ControlEllipsis::Render() const
{
	if (mEnabled)
	{
		unsigned long leftEdge = mBuddy->GetRightEdge();
		Font font(mBuddy->GetFont());
		font.Render(
			leftEdge - 1,
			mBuddy->GetY(),
			std::string((mRightEdge - leftEdge) / (font.Measure(".") - 1), '.'),
			ColorScheme::Get(mScheme));
	}
}

}
