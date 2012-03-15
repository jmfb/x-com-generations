#pragma once
#include "IDateTimeUtility.h"
#include "IDateTime.h"

namespace XCom
{

class DateTime : public IDateTime
{
public:
	DateTime(IDateTimeUtilityPtr dateTimeUtility);
	
	virtual void SetNow();
	virtual bool TestInterval(unsigned long interval);

	std::chrono::high_resolution_clock::time_point GetValue() const;
	
private:
	IDateTimeUtilityPtr mDateTimeUtility;
	std::chrono::high_resolution_clock::time_point mValue;	
};

}
