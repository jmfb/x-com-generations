#include "Game.h"
#include "Screens/ScreenManager.h"
#include "Application.h"
#include "FactoryInject.h"

namespace XCom
{

Game::Game()
{
}

Game::~Game()
{
}

void Game::RenderScene()
{
	ScreenManager::Get().Render();
	UnitTest::Inject<IMouse>::Resolve()->Render();
}

void Game::Quit()
{
	UnitTest::Inject<IApplication>::Resolve()->Quit();
}

}
