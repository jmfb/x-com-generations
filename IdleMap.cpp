#include "IdleMap.h"
#include "Error.h"

namespace XCom
{

IdleMap* IdleMap::mThis = 0;

IdleMap::IdleMap()
	: mNextId(1)
{
	mThis = this;
}

IdleMap::~IdleMap()
{
	mThis = 0;
}

IdleMap& IdleMap::Get()
{
	CheckError(mThis == 0, 0, "", "Idle map entity does not exist.");
	return *mThis;
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
