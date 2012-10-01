////////////////////////////////////////////////////////////////////////////////
// Filename:    IScrollMovement.h
// Description: This file defines the IScrollMovement interface.
//
// Created:     2012-09-30 22:15:56
// Author:      Jacob Buysse
////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <chrono>
#include <memory>

namespace XCom
{
	class IScrollMovement
	{
	public:
		virtual ~IScrollMovement()
		{
		}

		virtual void SetPosition(int value) = 0;
		virtual void SetPeriod(std::chrono::milliseconds value) = 0;
		virtual void ChangeDestination(int value) = 0;

		virtual int GetCurrentPosition() const = 0;
	};

	typedef std::shared_ptr<IScrollMovement> IScrollMovementPtr;
}

