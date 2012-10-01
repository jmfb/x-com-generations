////////////////////////////////////////////////////////////////////////////////
// Filename:    ScrollMovement.Test.cpp
// Description: This file defines all ScrollMovement unit tests.
//
// Created:     2012-09-29 13:40:32
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "ScrollMovement.h"
#include "IDateTimeUtility.h"
#include "IScrollMovementCalculator.h"
#include "TimePointStream.h"
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace XCom
{
	TEST_CLASS(ScrollMovementTest)
	{
	public:
		ScrollMovementTest()
		{
		}

		virtual void BeginTest()
		{
			factory.RegisterObject(mockDateTimeUtility);
			factory.RegisterObject(mockCalculator);
		}

		virtual void EndTest()
		{
			mockDateTimeUtility.Verify();
			mockCalculator.Verify();
		}

		TEST_METHOD(SetPosition)
		{
			const int value = 123;
			ScrollMovement scroll(&factory);
			scroll.initialPosition = 99999;
			scroll.positionChange = 99999;
			scroll.SetPosition(value);
			Assert.AreEqual(value, scroll.initialPosition, "initialPosition");
			Assert.AreEqual(0, scroll.positionChange, "positionChange");
		}

		TEST_METHOD(SetPeriod)
		{
			const std::chrono::milliseconds value { 123 };
			ScrollMovement scroll(&factory);
			scroll.SetPeriod(value);
			Assert.AreEqual(value.count(), scroll.period.count(), "period");
		}

		TEST_METHOD(ChangeDestinationElapsed)
		{
			auto now = std::chrono::high_resolution_clock::now();
			const std::chrono::milliseconds duration { 123 };
			const std::chrono::milliseconds period { 100 };
			auto start = now - duration;
			const auto previousInitial = 12;
			const auto previousChange = 34;
			const auto positionChange = 56;

			mockDateTimeUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);

			ScrollMovement scroll(&factory);
			scroll.initialPosition = previousInitial;
			scroll.positionChange = previousChange;
			scroll.initialVelocity = 123.45;
			scroll.period = period;
			scroll.start = start;

			scroll.ChangeDestination(positionChange);

			Assert.AreEqual(previousInitial + previousChange, scroll.initialPosition,
				"initialPosition");
			Assert.AreEqual(positionChange, scroll.positionChange, "positionChange");
			Assert.AreEqual(0.0, scroll.initialVelocity, "initialVelocity");
			Assert.AreEqual(now, scroll.start, "start");
		}

		TEST_METHOD(ChangeDestinationCombine)
		{
			auto now = std::chrono::high_resolution_clock::now();
			const std::chrono::milliseconds duration { 12 };
			const std::chrono::milliseconds period { 100 };
			auto start = now - duration;
			const auto previousInitial = 123;
			const auto previousChange = 234;
			const auto positionChange = 345;
			const auto currentPosition = previousInitial + 44;
			const auto previousVelocity = 23.4;
			const auto currentVelocity = 123.45;

			mockDateTimeUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);
			mockCalculator.Setup(&IScrollMovementCalculator::Initialize,
				duration, period, previousInitial, previousChange, previousVelocity);
			mockCalculator.Setup(&IScrollMovementCalculator::GetVelocity)
				.Returns(currentVelocity);
			mockCalculator.Setup(&IScrollMovementCalculator::GetPosition)
				.Returns(currentPosition);

			ScrollMovement scroll(&factory);
			scroll.initialPosition = previousInitial;
			scroll.positionChange = previousChange;
			scroll.initialVelocity = previousVelocity;
			scroll.period = period;
			scroll.start = start;

			scroll.ChangeDestination(positionChange);

			Assert.AreEqual(currentPosition, scroll.initialPosition, "initialPosition");
			Assert.AreEqual(previousInitial + previousChange + positionChange - currentPosition,
				scroll.positionChange, "positionChange");
			Assert.AreEqual(currentVelocity, scroll.initialVelocity, "initialVelocity");
			Assert.AreEqual(now, scroll.start, "start");
		}

		TEST_METHOD(GetCurrentPositionNoChange)
		{
			const auto initialPosition = 123;
			ScrollMovement scroll(&factory);
			scroll.initialPosition = initialPosition;
			auto result = scroll.GetCurrentPosition();
			Assert.AreEqual(initialPosition, result);
		}

		TEST_METHOD(GetCurrentPositionElapsed)
		{
			auto now = std::chrono::high_resolution_clock::now();
			const std::chrono::milliseconds duration { 123 };
			const std::chrono::milliseconds period { 100 };
			auto start = now - duration;
			const auto initialPosition = 12;
			const auto positionChange = 34;

			mockDateTimeUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);

			ScrollMovement scroll(&factory);
			scroll.initialPosition = initialPosition;
			scroll.positionChange = positionChange;
			scroll.period = period;
			scroll.start = start;

			auto result = scroll.GetCurrentPosition();
			Assert.AreEqual(initialPosition + positionChange, result);
		}

		TEST_METHOD(GetCurrentPositionMiddle)
		{
			auto now = std::chrono::high_resolution_clock::now();
			const std::chrono::milliseconds duration { 80 };
			const std::chrono::milliseconds period { 100 };
			auto start = now - duration;
			const auto initialPosition = 123;
			const auto positionChange = 345;
			const auto currentPosition = initialPosition + 44;
			const auto initialVelocity = 123.45;

			mockDateTimeUtility.Setup(&IDateTimeUtility::GetNow).Returns(now);
			mockCalculator.Setup(&IScrollMovementCalculator::Initialize,
				duration, period, initialPosition, positionChange, initialVelocity);
			mockCalculator.Setup(&IScrollMovementCalculator::GetPosition)
				.Returns(currentPosition);

			ScrollMovement scroll(&factory);
			scroll.initialPosition = initialPosition;
			scroll.positionChange = positionChange;
			scroll.initialVelocity = initialVelocity;
			scroll.period = period;
			scroll.start = start;

			auto result = scroll.GetCurrentPosition();
			Assert.AreEqual(currentPosition, result);
		}

	private:
		UnitTest::Factory factory;
		UnitTest::Mock<IDateTimeUtility> mockDateTimeUtility;
		UnitTest::Mock<IScrollMovementCalculator> mockCalculator;
	};
}

