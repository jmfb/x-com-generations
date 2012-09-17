////////////////////////////////////////////////////////////////////////////////
// Filename:    ScreenManager.cpp
// Description: ...
//
// Created:     2012-09-16 21:45:24
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "ScreenManager.h"
#include "../Mouse/MouseEvents.h"
#include "ScreenMainMenu.h"
#include "ScreenTestControls.h"
#include "ScreenTestBattle.h"
#include "../FactoryInject.h"

namespace XCom
{

void ScreenManager::Render() const
{
	if (mActiveScreen)
		mActiveScreen->Render();
}

void ScreenManager::Set(ScreenType type, long param)
{
	if (mActiveScreen)
	{
		mActiveScreen->OnKillFocus();
		UnitTest::Inject<IMouseEvents>::Resolve()->ReleaseFocus();
	}

	mActiveScreen = FindScreen(type);
	if (mActiveScreen)
	{
		UnitTest::Inject<IMouseEvents>::Resolve()->CaptureFocus(mActiveScreen);
		mActiveScreen->OnSetFocus(param);
	}
}

BaseScreen* ScreenManager::FindScreen(ScreenType type)
{
	static ScreenMainMenu mainMenu;
	static ScreenTestControls testControls;
	static ScreenTestBattle testBattle;
	switch(type)
	{
	case SCREEN_MAIN_MENU:
		return &mainMenu;
	case SCREEN_TEST:
		return &testControls;
	case SCREEN_BATTLE_TEST:
		return &testBattle;
	default:
		return 0;
	}
	return 0;
}

}
