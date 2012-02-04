#include "IdleMap.h"

namespace XCom
{

IdleMap::IdleMap()
	: mNextId(1)
{
}

IdleMap::~IdleMap()
{
}

unsigned long IdleMap::Register(IdleHandler* handler)
{
	unsigned long idleId = mNextId++;
	mHandlerMap[idleId] = handler;
	return idleId;
}

void IdleMap::Unregister(unsigned long idleId)
{
	mHandlerMap.erase(idleId);
}

void IdleMap::OnIdle()
{
	for (auto iter = mHandlerMap.begin(), end = mHandlerMap.end(); iter != end; ++iter)
		iter->second->OnIdle();
}

}
