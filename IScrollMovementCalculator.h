////////////////////////////////////////////////////////////////////////////////
// Filename:    IScrollMovementCalculator.h
// Description: This file defines the IScrollMovementCalculator interface.
//
// Created:     2012-09-30 21:55:16
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <chrono>
#include <memory>

namespace XCom
{
	class IScrollMovementCalculator
	{
	public:
		virtual ~IScrollMovementCalculator()
		{
		}
		virtual void Initialize(
			std::chrono::milliseconds duration,
			std::chrono::milliseconds period,
			int initialPosition,
			int positionChange,
			double initialVelocity) = 0;
		virtual double GetPosition() const = 0;
		virtual double GetVelocity() const = 0;
	};

	typedef std::shared_ptr<IScrollMovementCalculator> IScrollMovementCalculatorPtr;
}

