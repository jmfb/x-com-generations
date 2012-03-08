#pragma once
#include <string>
#include <vector>
#include "Any.h"
#include "ReturnValue.h"

namespace UnitTest
{

class CallData
{
public:
	CallData(unsigned long offset)
		: mOffset(offset), mExpectedCalls(1), mActualCalls(0)
	{
	}
	
	CallData(const CallData& rhs) = default;
	CallData(CallData&& rhs) = default;
	CallData& operator=(const CallData& rhs) = default;
	
	CallData& operator=(CallData&& rhs)
	{
		if (this != &rhs)
		{
			mOffset = std::move(rhs.mOffset);
			mArguments = std::move(rhs.mArguments);
			mExpectedCalls = std::move(rhs.mExpectedCalls);
			mActualCalls = std::move(rhs.mActualCalls);
			mThrowValue = std::move(rhs.mThrowValue);
			mReturnValue = std::move(rhs.mReturnValue);
		}
		return *this;
	}
	
	template <typename A>
	CallData& operator()(A argument)
	{
		mArguments.push_back(Any(argument));
		return *this;
	}
	template <typename R>
	CallData& DefaultReturnValue()
	{
		ReturnValue<R>::SetDefaultValue(mReturnValue);
		return *this;
	}
	
	unsigned long mOffset;
	std::vector<Any> mArguments;
	unsigned long mExpectedCalls;
	unsigned long mActualCalls;
	Any mThrowValue;
	Any mReturnValue;
};

}
