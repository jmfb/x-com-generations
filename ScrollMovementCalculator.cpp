////////////////////////////////////////////////////////////////////////////////
// Filename:    ScrollMovementCalculator.cpp
// Description: This file implements all ScrollMovementCalculator member functions.
//
// Created:     2012-09-30 20:52:06
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "ScrollMovementCalculator.h"

namespace XCom
{
	void ScrollMovementCalculator::Initialize(
		std::chrono::milliseconds duration,
		std::chrono::milliseconds period,
		int initialPosition,
		int positionChange,
		double initialVelocity)
	{
		//t is time as a ratio of duration to period (0 to 1).
		t = static_cast<double>(duration.count()) /
			static_cast<double>(period.count());

		/*
		//Calculation assumes a constant acceleration acceleration leaving
		//the position equation as a third order polynomial.
		auto accelerationAcceleration = -12.0 *
			(static_cast<double>(positionChange) - initialVelocity);

		a = accelerationAcceleration / 6.0;
		b = accelerationAcceleration / -4.0;
		*/

		a = initialVelocity - 2.0 * static_cast<double>(positionChange);
		b = 3.0 * static_cast<double>(positionChange) - 2.0 * initialVelocity;
		c = initialVelocity;
		d = static_cast<double>(initialPosition);
	}

	double ScrollMovementCalculator::GetPosition() const
	{
		return (a * t * t * t) + (b * t * t) + (c * t) + d;
	}
	
	double ScrollMovementCalculator::GetVelocity() const
	{
		return (3.0 * a * t * t) + (2.0 * b * t) + c;
	}
}

