#pragma once
#include "Singleton.h"
#include "IdleHandler.h"
#include <map>

namespace XCom
{

class IdleMap : public Singleton<IdleMap>
{
private:
	IdleMap();
	~IdleMap();
	
	friend class Singleton<IdleMap>;

public:
	unsigned long Register(IdleHandler* handler);
	void Unregister(unsigned long idleId);
	
	void OnIdle();
	
private:
	unsigned long mNextId;
	typedef std::map<unsigned long, IdleHandler*> HandlerMap;
	HandlerMap mHandlerMap;
	
private:
	IdleMap(const IdleMap& rhs);
	IdleMap& operator=(const IdleMap& rhs);
};

}
