////////////////////////////////////////////////////////////////////////////////
// Filename:    Game.h
// Description: ...
//
// Created:     2012-09-16 21:24:52
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "IGame.h"
#include <UnitTest/UnitTest.h>

namespace XCom
{
	class Game : public IGame
	{
	public:
		Game(UnitTest::IFactoryPtr factory);
		Game(const Game& rhs) = delete;
		virtual ~Game() noexcept(true) = default;

		Game& operator=(const Game& rhs) = delete;

		void RenderScene() final;
		void Quit() final;

	private:
		friend class GameTest;
		UnitTest::IFactoryPtr factory;
	};
}

