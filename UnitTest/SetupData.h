#pragma once
#include "CallData.h"

namespace UnitTest
{

template <typename R>
class SetupData
{
public:
	SetupData(CallData& callData)
		: mCallData(callData)
	{
	}
	
	SetupData<R>& Returns(R returnValue)
	{
		mCallData.mReturnValue.Set<R>(returnValue);
		return *this;
	}
	SetupData<R>& Expects(unsigned long count)
	{
		mCallData.mExpectedCalls = count;
		return *this;
	}
	template <typename E>
	SetupData<R>& Throws(E exception)
	{
		mCallData.mThrowValue = exception;
		return *this;
	}
private:
	CallData& mCallData;
};

template <>
class SetupData<void>
{
public:
	SetupData(CallData& callData)
		: mCallData(callData)
	{
	}
	
	SetupData<void>& Expects(unsigned long count)
	{
		mCallData.mExpectedCalls = count;
		return *this;
	}
	template <typename E>
	SetupData<void>& Throws(E exception)
	{
		mCallData.mThrowValue = exception;
		return *this;
	}
private:
	CallData& mCallData;
};

}
