#include "DateTime.h"

namespace XCom
{

DateTime::DateTime(IDateTimeUtilityPtr dateTimeUtility)
	: mDateTimeUtility(dateTimeUtility)
{
	mValue = mDateTimeUtility->GetNow();
}

void DateTime::SetNow()
{
	mValue = mDateTimeUtility->GetNow();
}

bool DateTime::TestInterval(unsigned long interval)
{
	auto now = mDateTimeUtility->GetNow();
	auto duration = now - mValue;
	auto in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
	if (in_ms.count() >= interval)
	{
		mValue = now;
		return true;
	}
	return false;
}

std::chrono::high_resolution_clock::time_point DateTime::GetValue() const
{
	return mValue;
}

}
