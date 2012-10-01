////////////////////////////////////////////////////////////////////////////////
// Filename:    ScrollMovementCalculator.Test.cpp
// Description: This file defines all ScrollMovementCalculator unit tests.
//
// Created:     2012-09-30 20:52:06
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "ScrollMovementCalculator.h"
#include <cmath>
#include <UnitTest/UnitTest.h>
using UnitTest::Assert;

namespace XCom
{
	TEST_CLASS(ScrollMovementCalculatorTest)
	{
	public:
		ScrollMovementCalculatorTest()
		{
		}
	
		TEST_METHOD(InitialPosition)
		{
			const std::chrono::milliseconds duration { 0 };
			const std::chrono::milliseconds period { 1000 };
			const auto initialPosition = 123;
			const auto positionChange = 456;
			const auto initialVelocity = 1.23;
			calculator.Initialize(
				duration,
				period,
				initialPosition,
				positionChange,
				initialVelocity);
			auto position = static_cast<int>(calculator.GetPosition());
			auto velocity = calculator.GetVelocity();
			Assert.AreEqual(initialPosition, position, "position");
			Assert.AreEqual(initialVelocity, velocity, "velocity");
		}
	
		TEST_METHOD(MiddlePosition)
		{
			const std::chrono::milliseconds duration { 500 };
			const std::chrono::milliseconds period { 1000 };
			const auto initialPosition = 123;
			const auto positionChange = 456;
			const auto initialVelocity = 1.23;
			calculator.Initialize(
				duration,
				period,
				initialPosition,
				positionChange,
				initialVelocity);
			auto position = static_cast<int>(calculator.GetPosition());
			auto velocity = calculator.GetVelocity();
			Assert.IsTrue(position > initialPosition &&
				position < (initialPosition + positionChange), "position");
			Assert.IsTrue(velocity > 0.0, "velocity");
		}
	
		TEST_METHOD(FinalPosition)
		{
			const std::chrono::milliseconds duration { 1000 };
			const std::chrono::milliseconds period { 1000 };
			const auto initialPosition = 123;
			const auto positionChange = 456;
			const auto initialVelocity = 1.23;
			calculator.Initialize(
				duration,
				period,
				initialPosition,
				positionChange,
				initialVelocity);
			auto position = static_cast<int>(calculator.GetPosition());
			auto velocity = calculator.GetVelocity();
			Assert.AreEqual(initialPosition + positionChange, position, "position");
			Assert.IsTrue(std::abs(velocity) < 0.00001, "velocity");
		}

	private:
		ScrollMovementCalculator calculator;
	};
}

