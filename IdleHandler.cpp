#include "IdleHandler.h"
#include "FactoryInject.h"

namespace XCom
{

IdleHandler::IdleHandler()
{
	mIdleId = 0;
}

void IdleHandler::RegisterForIdle()
{
	mIdleId = UnitTest::Inject<IIdleMap>::Resolve()->Register(this);
}

void IdleHandler::UnregisterFromIdle()
{
	UnitTest::Inject<IIdleMap>::Resolve()->Unregister(mIdleId);
	mIdleId = 0;
}

}

