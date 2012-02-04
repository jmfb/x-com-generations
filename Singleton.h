#pragma once

namespace XCom
{

template <typename T>
class Singleton
{
protected:
	Singleton()
	{
	}
	virtual ~Singleton()
	{
	}

private:
	class Deleter
	{
	public:
		Deleter()
			: mPointer(0)
		{
		}
		~Deleter()
		{
			Free();
		}
		void Free()
		{
			delete static_cast<Singleton<T>*>(mPointer);
			mPointer = 0;
		}
		void Set(T* pointer)
		{
			Free();
			mPointer = pointer;
		}
		bool IsNull() const
		{
			return mPointer == 0;
		}
		T& Get()
		{
			return *mPointer;
		}
	private:
		T* mPointer;
	};

	friend class Deleter;

public:
	static T& Get()
	{
		Deleter& deleter = InternalGetDeleter();
		if (deleter.IsNull())
			deleter.Set(new T());
		return deleter.Get();
	}
	
	static void Free()
	{
		InternalGetDeleter().Free();
	}

private:
	static Deleter& InternalGetDeleter()
	{
		static Deleter deleter;
		return deleter;
	}
	
private:	
	Singleton(const Singleton<T>& rhs);
	Singleton<T>& operator=(const Singleton<T>& rhs);		
};

}
