////////////////////////////////////////////////////////////////////////////////
// Filename:    IdleMap.Test.cpp
// Description: ...
//
// Created:     2012-09-16 22:22:08
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "IdleMap.h"
#include "Error.h"
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace XCom
{
	TEST_CLASS(IdleMapTest)
	{
	public:
		IdleMapTest()
		{
		}

		void EndTest() final
		{
			mockIdleHandler.Verify();
		}
		
		TEST_METHOD(Constructor)
		{
			IdleMap idleMap;
			Assert.AreEqual(1ul, idleMap.nextId, "nextId");
			Assert.IsTrue(idleMap.handlerMap.empty(), "handlerMap");
		}

		TEST_METHOD(RegisterNull)
		{
			IdleMap idleMap;
			Assert.ThrowsType<Error>([&idleMap]()
			{
				idleMap.Register(nullptr);
			}, "null argument");
		}

		TEST_METHOD(RegisterValid)
		{
			const auto nextId = 123ul;
			IdleMap idleMap;
			idleMap.nextId = nextId;
			auto result = idleMap.Register(mockIdleHandler.GetObject().get());
			Assert.AreEqual(nextId, result, "result");
			Assert.AreEqual(nextId + 1, idleMap.nextId, "nextId");
			auto iter = idleMap.handlerMap.find(nextId);
			Assert.IsTrue(iter != idleMap.handlerMap.end(), "handlerMap[nextId]");
			Assert.AreEqual(mockIdleHandler.GetObject().get(), iter->second, "handlerMap[nextId].second");
		}

		TEST_METHOD(UnregisterInvalid)
		{
			const auto validId = 123ul;
			const auto invalidId = 999ul;
			IdleMap idleMap;
			idleMap.handlerMap[validId] = nullptr;
			idleMap.Unregister(invalidId);
			Assert.AreEqual(1ull, idleMap.handlerMap.size(), "size");
		}

		TEST_METHOD(UnregisterValid)
		{
			const auto validId = 123ul;
			const auto otherId = 999ul;
			IdleMap idleMap;
			idleMap.handlerMap[validId] = nullptr;
			idleMap.handlerMap[otherId] = nullptr;
			idleMap.Unregister(validId);
			Assert.AreEqual(1ull, idleMap.handlerMap.size(), "size");
			auto iter = idleMap.handlerMap.find(validId);
			Assert.IsTrue(iter == idleMap.handlerMap.end(), "handlerMap[validId]");
		}

		TEST_METHOD(OnIdleEmpty)
		{
			IdleMap idleMap;
			idleMap.OnIdle();
		}

		TEST_METHOD(OnIdleValid)
		{
			IdleMap idleMap;
			mockIdleHandler.Setup(&IdleHandler::OnIdle);
			idleMap.handlerMap[1] = mockIdleHandler.GetObject().get();
			idleMap.OnIdle();
		}

	private:
		UnitTest::Mock<IdleHandler> mockIdleHandler;
	};
}

