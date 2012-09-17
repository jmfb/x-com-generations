////////////////////////////////////////////////////////////////////////////////
// Filename:    IdleMap.h
// Description: ...
//
// Created:     2012-09-16 22:17:08
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Singleton.h"
#include "IdleHandler.h"
#include "IIdleMap.h"
#include <map>

namespace XCom
{
	class IdleMap : public IIdleMap
	{
	public:
		IdleMap() = default;
		IdleMap(const IdleMap& rhs) = delete;
		virtual ~IdleMap() noexcept(true) = default;
	
		IdleMap& operator=(const IdleMap& rhs) = delete;
	
		unsigned long Register(IdleHandler* handler) final;
		void Unregister(unsigned long idleId) final;
		void OnIdle() final;
	
	private:
		friend class IdleMapTest;
		unsigned long nextId = 1;
		std::map<unsigned long, IdleHandler*> handlerMap;
	};
}

