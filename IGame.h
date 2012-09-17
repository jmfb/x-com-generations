////////////////////////////////////////////////////////////////////////////////
// Filename:    IGame.h
// Description: ...
//
// Created:     2012-09-16 21:23:46
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <memory>

namespace XCom
{
	class IGame
	{
	public:
		virtual ~IGame() = default;
		
		virtual void RenderScene() = 0;
		virtual void Quit() = 0;
	};

	typedef std::shared_ptr<IGame> IGamePtr;
}

