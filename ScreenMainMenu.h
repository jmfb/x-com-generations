#pragma once
#include "BaseScreen.h"
#include "ControlButton.h"
#include "ControlBorder.h"
#include "ControlText.h"

namespace XCom
{

class ScreenMainMenu : public BaseScreen
{
private:
	ScreenMainMenu();
	ScreenMainMenu(const ScreenMainMenu& rhs);
	~ScreenMainMenu();
	
	ScreenMainMenu& operator=(const ScreenMainMenu& rhs);
	
	friend class ScreenManager;
	
	virtual void OnButton(unsigned long id);
	
	ControlBorder mBorder;
	ControlText mTitle;
	ControlText mSubTitle;
	ControlButton mNewGame;
	ControlButton mLoadGame;
	ControlButton mQuit;
};

}
