////////////////////////////////////////////////////////////////////////////////
// Filename:    FactoryInject.Test.cpp
// Description: ...
//
// Created:     2012-09-16 20:35:07
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "FactoryInject.h"
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace UnitTest
{
	TEST_CLASS(FactoryInjectTest)
	{
	public:
		FactoryInjectTest()
		{
		}

		template <typename T>
		static void TestInstance()
		{
			auto instance = Inject<T>::Resolve();
			Assert.IsNotNull(instance.get(), "instance");
			auto nextInstance = Inject<T>::Resolve();
			Assert.AreNotEqual(instance.get(), nextInstance.get(), "nextInstance");
		}

		template <typename T>
		static void TestSingleton()
		{
			auto instance = Inject<T>::Resolve();
			Assert.IsNotNull(instance.get(), "instance");
			auto nextInstance = Inject<T>::Resolve();
			Assert.AreEqual(instance.get(), nextInstance.get(), "nextInstance");
		}

		TEST_METHOD(InjectDateTimeUtility)
		{
			TestInstance<XCom::IDateTimeUtility>();
		}

		TEST_METHOD(InjectDateTime)
		{
			TestInstance<XCom::IDateTime>();
		}

		TEST_METHOD(InjectSystem)
		{
			TestInstance<XCom::ISystem>();
		}

		TEST_METHOD(InjectMouse)
		{
			TestSingleton<XCom::IMouse>();
		}

		TEST_METHOD(InjectMouseEvents)
		{
			TestSingleton<XCom::IMouseEvents>();
		}

		TEST_METHOD(InjectApplication)
		{
			TestSingleton<XCom::IApplication>();
		}

		//NOTE: If you run this test and it fails with "Could not open palette file." it is
		//		because you need to copy the backgrounds, images, and palettes folders from
		//		the project directory to the output directory.  You also need to do this to
		//		run the game and until the IDE supports post-build events that perform the
		//		copy automatically you will need to copy these manually.
		TEST_METHOD(InjectGraphicsBuffer)
		{
			TestSingleton<XCom::IGraphicsBuffer>();
		}

		TEST_METHOD(InjectPalette)
		{
			TestInstance<XCom::IPalette>();
		}

		TEST_METHOD(InjectBinaryFile)
		{
			TestInstance<XCom::IBinaryFile>();
		}

		TEST_METHOD(InjectImage)
		{
			TestInstance<XCom::IImage>();
		}

		TEST_METHOD(InjectGame)
		{
			TestSingleton<XCom::IGame>();
		}

		TEST_METHOD(InjectScreenManager)
		{
			TestSingleton<XCom::IScreenManager>();
		}

		TEST_METHOD(InjectIdleMap)
		{
			TestSingleton<XCom::IIdleMap>();
		}
	};
}

