////////////////////////////////////////////////////////////////////////////////
// Filename:    IScreenManager.h
// Description: ...
//
// Created:     2012-09-16 21:41:54
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "ScreenType.h"
#include <memory>

namespace XCom
{
	class IScreenManager
	{
	public:
		virtual ~IScreenManager() = default;

		virtual void Render() const = 0;
		virtual void Set(ScreenType type, long param = 0) = 0;
	};

	typedef std::shared_ptr<IScreenManager> IScreenManagerPtr;
}

