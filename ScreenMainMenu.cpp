#include "ScreenMainMenu.h"
#include "Game.h"

namespace XCom
{

enum
{
	ID_NEW_GAME,
	ID_LOAD_GAME,
	ID_QUIT
};

ScreenMainMenu::ScreenMainMenu()
{
	//TODO: title, subtitle and border
	
	mNewGame.Init(this, 64, 109, 192, 20, "New Game", SCHEME_AQUA, ID_NEW_GAME);
	mLoadGame.Init(this, 64, 81, 192, 20, "Load Saved Game", SCHEME_AQUA, ID_LOAD_GAME);
	mQuit.Init(this, 64, 53, 192, 20, "Quit", SCHEME_AQUA, ID_QUIT);
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
	}
}

}
