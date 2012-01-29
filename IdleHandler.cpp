#include "IdleHandler.h"
#include "IdleMap.h"

namespace XCom
{

IdleHandler::IdleHandler()
{
	mIdleId = 0;
}

void IdleHandler::RegisterForIdle()
{
	mIdleId = IdleMap::Get().Register(this);
}

void IdleHandler::UnregisterFromIdle()
{
	IdleMap::Get().Unregister(mIdleId);
	mIdleId = 0;
}

}
