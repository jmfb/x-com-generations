#include "ScreenMainMenu.h"
#include "../Game.h"
#include "ScreenManager.h"

namespace XCom
{

enum
{
	ID_NEW_GAME,
	ID_LOAD_GAME,
	ID_QUIT,
	ID_TEST,
	ID_BATTLE
};

ScreenMainMenu::ScreenMainMenu()
{
	mBorder.Init(this, 32, 179, 256, 160, SCHEME_AQUA, BACK_TITLE, 0);
	
	mTitle.Init(this, X_CENTER, 154, "X-Com", FONT_LARGE, SCHEME_YELLOW);
	mSubTitle.Init(this, X_CENTER, 138, "UFO Defense", FONT_NORMAL, SCHEME_YELLOW);
	
	mNewGame.Init(this, 64, 109, 192, 20, "New Game", SCHEME_AQUA, ID_NEW_GAME);
	mLoadGame.Init(this, 64, 81, 192, 20, "Load Saved Game", SCHEME_AQUA, ID_LOAD_GAME);
	mQuit.Init(this, 64, 53, 192, 20, "Quit", SCHEME_AQUA, ID_QUIT);
	mTest.Init(this, 10, 190, 40, 20, "Test", SCHEME_AQUA, ID_TEST);
	mBattleTest.Init(this, 10, 170, 40, 20, "Battle", SCHEME_AQUA, ID_BATTLE);
}

ScreenMainMenu::~ScreenMainMenu()
{
}

void ScreenMainMenu::OnButton(unsigned long id)
{
	switch(id)
	{
	case ID_NEW_GAME:
		//TODO:
		break;
	case ID_LOAD_GAME:
		//TODO:
		break;
	case ID_QUIT:
		Game::Get().Quit();
		break;
	case ID_TEST:
		ScreenManager::Get().Set(SCREEN_TEST);
		break;
	case ID_BATTLE:
		ScreenManager::Get().Set(SCREEN_BATTLE_TEST);
		break;
	}
}

}
