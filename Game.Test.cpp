////////////////////////////////////////////////////////////////////////////////
// Filename:    Game.Test.cpp
// Description: ...
//
// Created:     2012-09-16 21:57:01
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "FactoryInject.h"
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace XCom
{
	TEST_CLASS(GameTest)
	{
	public:
		GameTest()
		{
		}

		void BeginTest() final
		{
			factory.RegisterObject(mockScreenManager);
			factory.RegisterObject(mockApplication);
			factory.RegisterObject(mockMouse);
		}
	
		void EndTest() final
		{
			mockScreenManager.Verify();
			mockApplication.Verify();
			mockMouse.Verify();
		}

		TEST_METHOD(Constructor)
		{
			Game game(&factory);
			Assert.AreEqual((&factory).get(), game.factory.get());
		}

		TEST_METHOD(RenderSceneValid)
		{
			auto sceneRendered = false;
			mockScreenManager.Setup(&IScreenManager::Render)
				.Callback([&sceneRendered]()
				{
					sceneRendered = true;
				});
			mockMouse.Setup(&IMouse::Render)
				.Callback([&sceneRendered]()
				{
					Assert.IsTrue(sceneRendered, "Scene must be rendered before mouse.");
				});
			Game game(&factory);
			game.RenderScene();
		}

		TEST_METHOD(QuitValid)
		{
			mockApplication.Setup(&IApplication::Quit);
			Game game(&factory);
			game.Quit();
		}

	private:
		UnitTest::Factory factory;
		UnitTest::Mock<IScreenManager> mockScreenManager;
		UnitTest::Mock<IApplication> mockApplication;
		UnitTest::Mock<IMouse> mockMouse;
	};
}

