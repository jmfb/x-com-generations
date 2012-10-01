#pragma once
#include <chrono>
#include <memory>

namespace XCom
{
	class IDateTime
	{
	public:
		virtual ~IDateTime() = default;
		
		virtual void SetNow() = 0;
		virtual bool TestInterval(unsigned long interval) = 0;
		virtual std::chrono::high_resolution_clock::time_point GetValue() const = 0;
	};
	
	typedef std::shared_ptr<IDateTime> IDateTimePtr;
}

