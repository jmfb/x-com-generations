#include "DateTime.h"

namespace XCom
{

const unsigned long MAX_TIME_OF_DAY = 24 * 60 * 60 * 1000;

DateTime::DateTime()
{
	SetNow();
}

DateTime::DateTime(const DateTime& rhs)
	: mValue(rhs.mValue)
{
}

DateTime::~DateTime()
{
}

DateTime& DateTime::operator=(const DateTime& rhs)
{
	if (this != &rhs)
		mValue = rhs.mValue;
	return *this;
}

void DateTime::SetNow()
{
	::GetLocalTime(&mValue);
}

unsigned long DateTime::GetElapsedTime() const
{
	unsigned long start = GetTimeOfDay();
	unsigned long end = DateTime().GetTimeOfDay();
	return end < start ? MAX_TIME_OF_DAY - start + end : end - start;
}

bool DateTime::TestInterval(unsigned long interval)
{
	if (GetElapsedTime() >= interval)
	{
		SetNow();
		return true;
	}
	return false;
}

unsigned long DateTime::GetTimeOfDay() const
{
	return (((((mValue.wHour * 60) + mValue.wMinute) * 60) + mValue.wSecond) * 1000) + mValue.wMilliseconds;
}

}
