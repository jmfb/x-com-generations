#pragma once
#include <typeinfo>
#include <functional>
#include <map>
#include "IFactory.h"
#include "Inject.h"

namespace UnitTest
{

// Factory interface implementation.  This class implements the DoRegister and
// DoResolve virtual functions using a map of std::type_info to std::function
// objects that will perform the actual interface resolution.  During construction
// this class will register the IFactory interface with this instance.
class Factory : public IFactory
{
public:
	Factory()
	{
		RegisterObject<IFactory>(*this);
	}
	
private:
	virtual void DoRegister(const std::type_info& type, std::function<void*()> resolver)
	{
		mMap[&type] = resolver;
	}
	
	virtual void DoUnregister(const std::type_info& type)
	{
		mMap.erase(&type);
	}
	
	virtual void* DoResolve(const std::type_info& type) const
	{
		auto iter = mMap.find(&type);
		if (iter == mMap.end())
			return 0;
		return (iter->second)();
	}

	// TypeInfoCompare predicate class.  Used to compare two std::type_info
	// pointers via the before member function.  This is needed because
	// std::type_info is not copyable and typeid(T) is not gauranteed to always
	// return an instance of std::type_info with the same address.
	class TypeInfoCompare
	{
	public:
		bool operator()(const std::type_info* lhs, const std::type_info* rhs) const
		{
			return lhs->before(*rhs);
		}
	};

	std::map<const std::type_info*, std::function<void*()>, TypeInfoCompare> mMap;
};

// Inject<IFactory> specialization that returns the Factory class as a singleton.
//
// Example:
//	//All calls to resolve will return the same instance of the factory.
//	std::shared_ptr<IFactory> factory = Inject<IFactory>::Resolve();
template <>
class Inject<IFactory>
{
public:
	static std::shared_ptr<IFactory> Resolve()
	{
		static std::shared_ptr<IFactory> instance(new Factory());
		return instance;
	}
};

}
