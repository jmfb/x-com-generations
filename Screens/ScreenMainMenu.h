#pragma once
#include "BaseScreen.h"
#include "../Controls/ControlButton.h"
#include "../Controls/ControlBorder.h"
#include "../Controls/ControlText.h"

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
	ControlButton mTest;
	ControlButton mBattleTest;
};

}
