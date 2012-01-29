#include "Game.h"
#include "Error.h"
#include "Mouse.h"
#include "ScreenManager.h"

namespace XCom
{

Game* Game::mThis = 0;

Game::Game(const std::function<void()>& quit)
	: mQuit(quit)
{
	mThis = this;
}

Game::~Game()
{
	mThis = 0;
}

Game& Game::Get()
{
	CheckError(mThis == 0, 0, "", "Game instance does not exist.");
	return *mThis;
}

void Game::RenderScene()
{
	ScreenManager::Get().Render();
	Mouse::Get().Render();
}

void Game::Quit()
{
	mQuit();
}

}
