////////////////////////////////////////////////////////////////////////////////
// Filename:    ScrollMovement.cpp
// Description: This file implements all ScrollMovement member functions.
//
// Created:     2012-09-29 13:40:32
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#include "ScrollMovement.h"
#include "IScrollMovementCalculator.h"
#include "IDateTimeUtility.h"
#include <cmath>

namespace XCom
{
	ScrollMovement::ScrollMovement(UnitTest::IFactoryPtr factory)
		: factory(factory)
	{
	}
	
	void ScrollMovement::SetPosition(int value)
	{
		initialPosition = value;
		positionChange = 0;
	}

	void ScrollMovement::SetPeriod(std::chrono::milliseconds value)
	{
		period = value;
	}

	void ScrollMovement::ChangeDestination(int value)
	{
		auto now = factory->Resolve<IDateTimeUtility>()->GetNow();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);

		if (duration >= period)
		{
			initialPosition += positionChange;
			positionChange = 0;
		}

		if (positionChange == 0)
		{
			positionChange = value;
			initialVelocity = 0;
			start = now;
		}
		else
		{
			auto calculator = factory->Resolve<IScrollMovementCalculator>();
			calculator->Initialize(
				duration,
				period,
				initialPosition,
				positionChange,
				initialVelocity);
			auto velocity = calculator->GetVelocity();
			auto position = calculator->GetPosition();

			auto finalPosition = initialPosition + positionChange + value;
			initialPosition = static_cast<int>(position);
			positionChange = finalPosition - initialPosition;
			initialVelocity = velocity;
			start = now;
		}
	}

	int ScrollMovement::GetCurrentPosition() const
	{
		if (positionChange == 0)
			return initialPosition;
		auto now = factory->Resolve<IDateTimeUtility>()->GetNow();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
		if (duration >= period)
			return initialPosition + positionChange;

		auto calculator = factory->Resolve<IScrollMovementCalculator>();
		calculator->Initialize(
			duration,
			period,
			initialPosition,
			positionChange,
			initialVelocity);
		auto position = calculator->GetPosition();

		return static_cast<int>(position);
	}
}

