#pragma once
#include <UnitTest/UnitTest.h>
#include "DateTimeUtility.h"
#include "DateTime.h"
#include "Mouse/Mouse.h"
#include "Mouse/MouseEvents.h"
#include "System/System.h"
#include "Application.h"
#include "Graphics/GraphicsBuffer.h"
#include "Graphics/Palette.h"
#include "System/BinaryFile.h"
#include "Graphics/Image.h"
#include "Game.h"
#include "Screens/ScreenManager.h"
#include "IdleMap.h"
#include "ScrollMovementCalculator.h"
#include "ScrollMovement.h"

namespace UnitTest
{
	INJECT(XCom::IDateTimeUtility, XCom::DateTimeUtility, Instance, ());
	INJECT(XCom::IDateTime, XCom::DateTime, Instance, (XCom::IDateTimeUtility*));
	INJECT(XCom::ISystem, XCom::System, Instance, ());
	INJECT(XCom::IMouse, XCom::Mouse, Singleton, (IFactory*));
	INJECT(XCom::IMouseEvents, XCom::MouseEvents, Singleton, (IFactory*));
	INJECT(XCom::IApplication, XCom::Application, Singleton, ());
	INJECT(XCom::IGraphicsBuffer, XCom::GraphicsBuffer, Singleton, ());
	INJECT(XCom::IPalette, XCom::Palette, Instance, ());
	INJECT(XCom::IBinaryFile, XCom::BinaryFile, Instance, ());
	INJECT(XCom::IImage, XCom::Image, Instance, (IFactory*));
	INJECT(XCom::IGame, XCom::Game, Singleton, (IFactory*));
	INJECT(XCom::IScreenManager, XCom::ScreenManager, Singleton, ());
	INJECT(XCom::IIdleMap, XCom::IdleMap, Singleton, ());
	INJECT(XCom::IScrollMovementCalculator, XCom::ScrollMovementCalculator, Instance, ());
	INJECT(XCom::IScrollMovement, XCom::ScrollMovement, Instance, (IFactory*));
}

