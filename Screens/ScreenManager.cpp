#include "ScreenManager.h"
#include "../Mouse/MouseEvents.h"
#include "ScreenMainMenu.h"
#include "ScreenTestControls.h"
#include "ScreenTestBattle.h"

namespace XCom
{

ScreenManager::ScreenManager()
	: mActiveScreen(0)
{
}

ScreenManager::~ScreenManager()
{
}

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
		MouseEvents::Get().ReleaseFocus();
	}
	
	mActiveScreen = FindScreen(type);
	if (mActiveScreen)
	{
		MouseEvents::Get().CaptureFocus(mActiveScreen);
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
