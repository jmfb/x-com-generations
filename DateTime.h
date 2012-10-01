#pragma once
#include "IDateTimeUtility.h"
#include "IDateTime.h"

namespace XCom
{
	class DateTime : public IDateTime
	{
	public:
		DateTime(IDateTimeUtilityPtr dateTimeUtility);
		DateTime(const DateTime& rhs) = delete;
		~DateTime() noexcept(true) = default;

		DateTime& operator=(const DateTime& rhs) = delete;
		
		void SetNow() override;
		bool TestInterval(unsigned long interval) override;
		std::chrono::high_resolution_clock::time_point GetValue() const override;
	
	private:
		IDateTimeUtilityPtr dateTimeUtility;
		std::chrono::high_resolution_clock::time_point value;
	};
}

