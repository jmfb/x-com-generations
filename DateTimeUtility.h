#pragma once
#include "IDateTimeUtility.h"

namespace XCom
{

class DateTimeUtility : public IDateTimeUtility
{
public:
	virtual std::chrono::high_resolution_clock::time_point GetNow() const;
};

}
