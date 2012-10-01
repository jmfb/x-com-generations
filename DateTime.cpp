#include "DateTime.h"

namespace XCom
{
	DateTime::DateTime(IDateTimeUtilityPtr dateTimeUtility)
		: dateTimeUtility(dateTimeUtility)
	{
		value = dateTimeUtility->GetNow();
	}

	void DateTime::SetNow()
	{
		value = dateTimeUtility->GetNow();
	}

	bool DateTime::TestInterval(unsigned long interval)
	{
		auto now = dateTimeUtility->GetNow();
		auto duration = now - value;
		auto in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
		if (in_ms.count() >= interval)
		{
			value = now;
			return true;
		}
		return false;
	}

	std::chrono::high_resolution_clock::time_point DateTime::GetValue() const
	{
		return value;
	}
}

