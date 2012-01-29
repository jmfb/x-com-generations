#pragma once
#include "WindowsInclude.h"

namespace XCom
{

class DateTime
{
public:
	DateTime();
	DateTime(const DateTime& rhs);
	~DateTime();
	
	DateTime& operator=(const DateTime& rhs);
	
	void SetNow();
	unsigned long GetElapsedTime() const;
	bool TestInterval(unsigned long interval);

	unsigned long GetTimeOfDay() const;

private:
	SYSTEMTIME mValue;	
};

}
