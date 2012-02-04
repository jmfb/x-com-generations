#include "Game.h"
#include "Mouse/Mouse.h"
#include "Screens/ScreenManager.h"
#include "Application.h"

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
	Mouse::Get().Render();
}

void Game::Quit()
{
	Application::Get().Quit();
}

}
