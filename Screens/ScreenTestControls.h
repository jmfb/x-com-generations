#pragma once
#include "BaseScreen.h"
#include "../Controls/ControlBackground.h"
#include "../Controls/ControlBar.h"
#include "../Controls/ControlBorder.h"
#include "../Controls/ControlButton.h"
#include "../Controls/ControlEdit.h"
#include "../Controls/ControlEllipsis.h"
#include "../Controls/ControlImage.h"
#include "../Controls/ControlList.h"
#include "../Controls/ControlText.h"
#include "../Controls/ControlUpDown.h"

namespace XCom
{

class ScreenTestControls : public BaseScreen
{
public:
	ScreenTestControls();
	~ScreenTestControls();

	virtual void OnButton(unsigned long id);
	
private:
	ControlBackground mBackground;
	ControlBar mBar;
	ControlBorder mBorder;
	ControlButton mButton;
	ControlEdit mEdit;
	ControlEllipsis mEllipsis;
	ControlImage mImage;
	ControlList mList;
	ControlText mText;
	ControlUpDown mUpDown;
	unsigned long mValue;
	
private:
	ScreenTestControls(const ScreenTestControls& rhs);
	ScreenTestControls& operator=(const ScreenTestControls& rhs);
};

}
