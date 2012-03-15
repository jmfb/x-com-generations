#pragma once
#include <chrono>
#include <memory>

namespace XCom
{

class IDateTimeUtility
{
public:
	virtual std::chrono::high_resolution_clock::time_point GetNow() const = 0;
};

typedef std::shared_ptr<IDateTimeUtility> IDateTimeUtilityPtr;

}
