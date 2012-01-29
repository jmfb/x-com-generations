#pragma once
#include "BaseScreen.h"
#include "ControlButton.h"

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
	
	ControlButton mNewGame;
	ControlButton mLoadGame;
	ControlButton mQuit;
};

}
