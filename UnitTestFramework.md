# Introduction #

The unit test framework built for this project consists of three parts:

  * Inversion of Control (IoC) injection framework.
  * Unit test harness framework.
  * Mock object framework.

All of these features can be used by including "UnitTest/UnitTest.h" and using the following examples in the UnitTest namespace.

# Inversion of Control #

Start by declaring your interface.
```
namespace Example
{
	class IFoo
	{
	public:
		virtual ~IFoo()
		{
		}

		virtual bool Func(int value) const = 0;
	};
	typedef std::shared_ptr<IFoo> IFooPtr;
}
```

It is recommended that you put all of your code into your own namespace to reduce name collisions but it is not required.  Your interface should have a virtual destructor since smart pointers will delete the class via the interface.  In addition you can put your abstract functions here.  For ease of use later it is also recommended you create a smart pointer typedef for your interface.

Next, declare your class that implements the interface.
```
namespace Example
{
	class Foo : public IFoo
	{
	public:
		virtual bool Func(int value) const
		{
			return value == 69;
		}
	};
}
```

You will note that there is nothing special needed when declaring this class.

Next is the injection logic.
```
namespace UnitTest
{
	INJECT(Example::IFoo, Example::Foo, Instance, ());
}
```

The injection logic goes in the UnitTest namespace because the INJECT macro expands into a template specialization of the Inject class for the given interface.  The parameters to INJECT are as follows:
| **Parameter** | **Value** | **Description** |
|:--------------|:----------|:----------------|
| Interface | Example::IFoo | This is the interface whose implementation is being injected. |
| Class | Example::Foo | This is the class that implements the interface. |
| Lifetime | Instance | This parameter can be "Instance" or "Singleton".  If instance, each request to resolve will result in a new instance.  If singleton, each request to resolve will return the same instance. |
| Constructor | () | This is a signature that will be used to select which class constructor to use.  Each argument, if present, must be an interface pointer that can also be injected. |

Here is an example of the two possible usages.
```
void InjectFooExample()
{
	auto factory = UnitTest::Inject<UnitTest::IFactory>::Resolve();
	auto foo1 = factory->Resolve<Example::IFoo>();
	auto b1 = foo1->Func(69);

	auto foo2 = UnitTest::Inject<Example::IFoo>::Resolve();
	auto b2 = foo2->Func(0);
}
```

Each injected interface is registered with the IFactory singleton and can be resolved via the interface.  Alternatively, a client can use the Inject class directly to resolve the interface but this does require the client to include the INJECT macros that have been defined (whereas the IFactory method does not).

And finally, here is an example of a second class where IFoo would be injected.
```
namespace Example
{
	class IBar
	{
	public:
		virtual ~Bar()
		{
		}
		virtual int Func(int value) const = 0;
	};

	typedef std::shared_ptr<IBar> IBarPtr;

	class Bar : public IBar
	{
	public:
		Bar(IFooPtr foo)
			: mFoo(foo)
		{
		}
		virtual int Func(int value) const
		{
			return mFoo->Func(value) ? value : -value;
		}
	private:
		IFooPtr mFoo;
	};
}
namespace UnitTest
{
	INJECT(Example::IBar, Example::Bar, Singleton, (IFoo*));
}
```

# Test Harness #

First, declare your test class and unit tests.
```
namespace Example
{
	TEST_CLASS(BarTest)
	{
	public:
		BarTest()
		{
		}
		static void InitializeTests()
		{
		}
		static void TerminateTests()
		{
		}
		virtual void BeginTest()
		{
		}
		virtual void EndTest()
		{
		}
		TEST_METHOD(FuncWhenFooTrue)
		{
			const int value = 55;
			UnitTest::Mock<IFoo> mockFoo;
			mockFoo.Setup(&IFoo::Func, value).Returns(true);
			Bar bar(mockFoo.GetObject());
			int result = bar.Func(value);
			Assert.AreEqual(value, result);
			mockFoo.Verify();
		}
	};
}
```

You will most likely want to put your test class in the same namespace as the class you are testing.  Recommended naming convention is the name of the class followed by "Test".  You must define the default constructor (this is needed by part of the auto-registration mechanism used for unit test discovery).  You may optionally define any of the following functions:
| **Function** | **When Called** |
|:-------------|:----------------|
| InitializeTests | Called once before any unit tests in this class are called in order to initialize any static variables. |
| TerminateTests | Called once after all unit tests in this class have finished in order to clean up any static variables. |
| BeginTest | Called once before each unit test is run to initialize any non-static member variables. |
| EndTest | Called once after each unit test is run to clean up any non-static member variables. |
Note: If any of these functions fail, the unit tests will also be marked as failed even if they passed.

Test classes are defined using the TEST\_CLASS macro.  This macro expands into a class for getting the name of the test class and declares the named test class derived from the TestClass template class which will perform auto-registration used for unit test discovery.

Test methods are defined using the TEST\_METHOD macro.  This macro expands into a class for getting the name of the unit test and executing it given an instance of the test class.  It subsequently begins the method definition with the void() signature.

Next, you can run unit tests with the following code.  Note that you could hook up the unit test results into another unit test framework system by implementing a different ITestRun implementation.
```
int main(int argc, char** argv)
{
	UnitTest::TestRunWriter writer(std::cout);
	UnitTest::TestRunner::RunTests(writer);
	return 0;
}
```

# Mock Objects #

You may have noticed the Mock usage in the previous example.  The Mock template class allows you to "mock" the implementation of a given interface by creating placeholder functions for virtual function calls on the interface at run time.

Calls to Setup take a member function pointer to either the interface or a base interface.  This will be followed by N parameters where N is the number of arguments to the member function.  Each parameter must be convertible to the corresponding argument type or the enum value UnitTest::Any::Match.  These parameters are used for argument list matching.  The return value from Setup is a SetupData class that can be used to further define the mock usage using the following functions which can all be chained.
| **Function** | **Description** |
|:-------------|:----------------|
| Returns | Sets the return value to the function.  This function is only present if the return value of the function is not void. |
| Expects | Sets the number of calls this function should expect.  The default value is 1. |
| Throws | Sets the exception that will be thrown when the function is invoked. |
| Callback | Sets a callback function (usually a lambda expression) to be called with the actual function arguments when the function is invoked.  The parameters of the callback function must be convertible from the actual function parameters.  Note that if "Throws" was specified the callback will occur prior to the exception being thrown. |

```
TEST_METHOD(Func)
{
	UnitTest::Mock<IFoo> mockFoo;
	mockFoo.Setup(&IFoo::Func, 55)
		.Returns(true)
		.Expects(2)
		.Callback([](int value){ std::cout << "Callback " << value << std::endl; })
		.Throws(UnitTest::TestException("exception"));
	SomeFuncThatDoesAllOfThis(mockFoo.GetObject());
	mockFoo.Verify();
}
```

The GetObject function returns a smart pointer to the mocked interface where the deleter object has been replaced with an empty lambda.  This allows the fake interface to be used by clients expecting the smart pointer but without causing the eventual call to delete on the fake interface.

The Verify function verifies that all functions calls that were expected were called and the correct number of times.  This is not done in the Mock destructor automatically since it would violate the design principle of "never throw from a destructor".

If a function is called that is not mocked then an exception will be thrown stating there was no mock implementation for the function at offset X where X is the index into the v-table of the function that was called.  This is as much information that is discernible from an errant function call at run time.

## Internal Implementation of Mock Class ##

The mock class uses a few tricks to get run time interfaces to work.

First is the layout of classes that contain a v-table.  This framework will work with any compiler where the v-table is the first item of the class and the v-table is a series of normal function pointers.

Second is the layout of class member functions.  This framework will work with any compiler where the member function is generated as a normal function with an additional first parameter that is the "this" pointer to the class.

Thirdly is a compiler template expansion limitation for recursive template expansion.  The "Const.h" file contains a constant for the maximum number of virtual functions in a class which is currently set at 50.  This is needed because there is no current way to get the offset of a function in the v-table for a class at compile time so a run time call must be made with placeholders in place for all possible index values.