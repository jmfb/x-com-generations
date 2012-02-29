#pragma once
#include "ITestRun.h"
#include "TestRepository.h"

namespace UnitTest
{

class TestRunner
{
public:
	static void RunTests(ITestRun& testRun)
	{
		auto& repository = TestRepository::GetInstance();
		unsigned long classCount = repository.GetCount();
		unsigned long methodCount = 0;
		for (unsigned long index = 0; index < classCount; ++index)
			methodCount += repository.Get(index).GetCount();
		testRun.OnInitialize(classCount, methodCount);
		
		unsigned long passedCount = 0;
		unsigned long failedCount = 0;
		for (unsigned long index = 0; index < classCount; ++index)
		{
			auto& factory = repository.Get(index);
			unsigned long count = factory.GetCount();
			testRun.OnBeginClass(factory.GetTestClassName(), count);
			
			if (!InitializeTests(testRun, factory))
				failedCount += count + 1;
			else
				for (unsigned long index = 0; index < count; ++index)
					if (RunTestMethod(testRun, factory, index))
						++passedCount;
					else
						++failedCount;
			
			if (!TerminateTests(testRun, factory))
				++failedCount;
				
			testRun.OnEndClass();
		}
		
		testRun.OnTerminate(passedCount, failedCount);
	}
	
private:
	static bool InitializeTests(ITestRun& testRun, ITestClassFactory& factory)
	{
		bool success = false;
		std::string reason;
		testRun.OnBeginMethod("[InitializeTests]");
		try
		{
			factory.InitializeTests();
			success = true;
		}
		catch (const std::exception& error)
		{
			reason = error.what();
		}
		catch (...)
		{
			reason = "Unhandled exception.";
		}
		testRun.OnEndMethod(success, reason);
		return success;
	}
	
	static bool TerminateTests(ITestRun& testRun, ITestClassFactory& factory)
	{
		bool success = false;
		std::string reason;
		testRun.OnBeginMethod("[TerminateTests]");
		try
		{
			factory.TerminateTests();
			success = true;
		}
		catch (const std::exception& error)
		{
			reason = error.what();
		}
		catch (...)
		{
			reason = "Unhandled exception.";
		}
		testRun.OnEndMethod(success, reason);
		return success;
	}
	
	static bool RunTestMethod(ITestRun& testRun, ITestClassFactory& factory, unsigned long index)
	{
		bool success = false;
		std::string reason;
		auto& mfactory = factory.Get(index);
		testRun.OnBeginMethod(mfactory.GetTestMethodName());
		try
		{
			auto instance = factory.CreateInstance();
			try
			{
				instance->BeginTest();
				mfactory.CreateInstance(instance.get())->Execute();
			}
			catch (...)
			{
				instance->EndTest();
				throw;
			}
			instance->EndTest();
			success = true;
		}
		catch (const std::exception& error)
		{
			reason = error.what();
		}
		catch (...)
		{
			reason = "Unhandled exception.";
		}
		testRun.OnEndMethod(success, reason);
		return success;
	}
};

}
