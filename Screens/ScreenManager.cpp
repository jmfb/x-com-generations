#include "ScreenManager.h"
#include "../Error.h"
#include "../Mouse/MouseEvents.h"
#include "ScreenMainMenu.h"

namespace XCom
{

ScreenManager* ScreenManager::mThis = 0;

ScreenManager::ScreenManager()
	: mActiveScreen(0)
{
	mThis = this;
}

ScreenManager::~ScreenManager()
{
	mThis = 0;
}

ScreenManager& ScreenManager::Get()
{
	CheckError(mThis == 0, 0, "", "Screen manager entity does not exist.");
	return *mThis;
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
	switch(type)
	{
	case SCREEN_MAIN_MENU:
		return &mainMenu;
	default:
		return 0;
	}
	return 0;
}

}
