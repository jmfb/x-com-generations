#pragma once
#include "IdleHandler.h"
#include <map>

namespace XCom
{

class IdleMap
{
public:
	static IdleMap& Get();
	
	unsigned long Register(IdleHandler* handler);
	void Unregister(unsigned long idleId);
	
	void OnIdle();
	
private:
	IdleMap();
	IdleMap(const IdleMap& rhs);
	~IdleMap();
	
	IdleMap& operator=(const IdleMap& rhs);
	
	friend class Application;
	
	static IdleMap* mThis;
	
	unsigned long mNextId;
	typedef std::map<unsigned long, IdleHandler*> HandlerMap;
	HandlerMap mHandlerMap;
};

}
