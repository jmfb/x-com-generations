////////////////////////////////////////////////////////////////////////////////
// Filename:    IdleMap.cpp
// Description: ...
//
// Created:     2012-09-16 22:17:14
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "IdleMap.h"
#include "Error.h"

namespace XCom
{
	unsigned long IdleMap::Register(IdleHandler* handler)
	{
		CheckError(handler == nullptr, Error::Codes::NullPointer, "handler", "null argument");
		auto idleId = nextId++;
		handlerMap[idleId] = handler;
		return idleId;
	}
	
	void IdleMap::Unregister(unsigned long idleId)
	{
		handlerMap.erase(idleId);
	}
	
	void IdleMap::OnIdle()
	{
		for (auto& handler: handlerMap)
			handler.second->OnIdle();
	}
}

