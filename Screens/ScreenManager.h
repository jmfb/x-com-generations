////////////////////////////////////////////////////////////////////////////////
// Filename:    ScreenManager.h
// Description: ...
//
// Created:     2012-09-16 21:43:45
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "BaseScreen.h"
#include "ScreenType.h"
#include "IScreenManager.h"

namespace XCom
{
	class ScreenManager : public IScreenManager
	{
	public:
		ScreenManager() = default;
		ScreenManager(const ScreenManager& rhs) = delete;
		~ScreenManager() noexcept(true) = default;
	
		ScreenManager& operator=(const ScreenManager& rhs) = delete;
	
		void Render() const final;
		void Set(ScreenType type, long param) final;
	
	private:
		static BaseScreen* FindScreen(ScreenType type);
	
	private:
		BaseScreen* mActiveScreen = nullptr;
	};
}

