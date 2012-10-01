////////////////////////////////////////////////////////////////////////////////
// Filename:    ScrollMovement.h
// Description: This file declares the ScrollMovement class.
//
// Created:     2012-09-29 13:40:32
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <chrono>
#include "IScrollMovement.h"
#include <UnitTest/UnitTest.h>

namespace XCom
{
	class ScrollMovement : public IScrollMovement
	{
	public:
		ScrollMovement(UnitTest::IFactoryPtr factory);
		ScrollMovement(const ScrollMovement& rhs) = delete;
		~ScrollMovement() = default;

		ScrollMovement& operator=(const ScrollMovement& rhs) = delete;

		void SetPosition(int value) override;
		void SetPeriod(std::chrono::milliseconds value) override;
		void ChangeDestination(int value) override;

		int GetCurrentPosition() const override;

	private:
		friend class ScrollMovementTest;
		UnitTest::IFactoryPtr factory;
		int initialPosition = 0;
		int positionChange = 0;
		double initialVelocity = 0.0;
		std::chrono::milliseconds period { 0 };
		std::chrono::high_resolution_clock::time_point start;
	};
}

