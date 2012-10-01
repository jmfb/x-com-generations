////////////////////////////////////////////////////////////////////////////////
// Filename:    ScrollMovementCalculator.h
// Description: This file declares the ScrollMovementCalculator class.
//
// Created:     2012-09-30 20:52:06
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "IScrollMovementCalculator.h"

namespace XCom
{
	class ScrollMovementCalculator : public IScrollMovementCalculator
	{
	public:
		ScrollMovementCalculator() = default;
		ScrollMovementCalculator(const ScrollMovementCalculator& rhs) = default;
		~ScrollMovementCalculator() = default;

		ScrollMovementCalculator& operator=(const ScrollMovementCalculator& rhs) = default;

		void Initialize(
			std::chrono::milliseconds duration,
			std::chrono::milliseconds period,
			int initialPosition,
			int positionChange,
			double initialVelocity) override;
		double GetPosition() const override;
		double GetVelocity() const override;

	private:
		friend class ScrollMovementCalculatorTest;
		double a = 0.0;
		double b = 0.0;
		double c = 0.0;
		double d = 0.0;
		double t = 0.0;
	};
}

