#pragma once
#include "Any.h"

namespace UnitTest
{

template <typename R>
class ReturnValue
{
public:
	ReturnValue()
		: mValue(R())
	{
	}
	
	void Set(const Any& value)
	{
		mValue = value.GetValue<R>();
	}
	R Get()
	{
		return mValue;
	}
	static void SetDefaultValue(Any& value)
	{
		value = R();
	}
private:
	R mValue;
};

template <typename R>
class ReturnValue<R&>
{
public:
	ReturnValue()
		: mValue(&mDefaultValue)
	{
	}
	
	void Set(const Any& value)
	{
		mValue = &value.GetValue<R&>();
	}
	R& Get()
	{
		return *mValue;
	}
	static void SetDefaultValue(Any& value)
	{
		value = static_cast<R&>(mDefaultValue);
	}
private:
	static R mDefaultValue;
	R* mValue;
};

template <typename R>
R ReturnValue<R&>::mDefaultValue = R();

template <typename R>
class ReturnValue<const R&>
{
public:
	ReturnValue()
		: mValue(&mDefaultValue)
	{
	}
	
	void Set(const Any& value)
	{
		mValue = &value.GetValue<const R&>();
	}
	const R& Get()
	{
		return *mValue;
	}
	static void SetDefaultValue(Any& value)
	{
		value = static_cast<const R&>(mDefaultValue);
	}
private:
	static R mDefaultValue;
	const R* mValue;
};

template <typename R>
R ReturnValue<const R&>::mDefaultValue = R();

template <>
class ReturnValue<void>
{
public:
	void Set(const Any& value)
	{
	}
	static void SetDefaultValue(Any& value)
	{
	}
};

}
