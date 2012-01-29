#pragma once

namespace XCom
{

class IdleHandler
{
public:
	IdleHandler();
	
	virtual void OnIdle() = 0;
	
	void RegisterForIdle();
	void UnregisterFromIdle();
	
private:
	unsigned long mIdleId;
};

}
