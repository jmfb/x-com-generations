#pragma once
#include <memory>

namespace XCom
{

class IDateTime
{
public:
	virtual void SetNow() = 0;
	virtual bool TestInterval(unsigned long interval) = 0;
};

typedef std::shared_ptr<IDateTime> IDateTimePtr;

}
