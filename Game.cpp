////////////////////////////////////////////////////////////////////////////////
// Filename:    Game.cpp
// Description: ...
//
// Created:     2012-09-16 21:26:17
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "FactoryInject.h"

namespace XCom
{
	Game::Game(UnitTest::IFactoryPtr factory)
		: factory(factory)
	{
	}
	
	void Game::RenderScene()
	{
		factory->Resolve<IScreenManager>()->Render();
		factory->Resolve<IMouse>()->Render();
	}

	void Game::Quit()
	{
		factory->Resolve<IApplication>()->Quit();
	}
}

