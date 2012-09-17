////////////////////////////////////////////////////////////////////////////////
// Filename:    IIdleMap.h
// Description: ...
//
// Created:     2012-09-16 22:13:54
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once

namespace XCom
{
	class IdleHandler;

	class IIdleMap
	{
	public:
		virtual ~IIdleMap() = default;

		virtual unsigned long Register(IdleHandler* handler) = 0;
		virtual void Unregister(unsigned long idleId) = 0;
		virtual void OnIdle() = 0;
	};
}

