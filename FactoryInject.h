#pragma once
#include "UnitTest/UnitTest.h"
#include "DateTimeUtility.h"
#include "DateTime.h"
#include "Mouse/Mouse.h"
#include "Mouse/MouseEvents.h"
#include "System/System.h"
#include "Application.h"
#include "Graphics/GraphicsBuffer.h"

namespace UnitTest
{
	INJECT(XCom::IDateTimeUtility, XCom::DateTimeUtility, Instance, ());
	INJECT(XCom::IDateTime, XCom::DateTime, Instance, (XCom::IDateTimeUtility*));
	INJECT(XCom::ISystem, XCom::System, Instance, ());
	INJECT(XCom::IMouse, XCom::Mouse, Singleton, (IFactory*));
	INJECT(XCom::IMouseEvents, XCom::MouseEvents, Singleton, ());
	INJECT(XCom::IApplication, XCom::Application, Singleton, ());
	INJECT(XCom::IGraphicsBuffer, XCom::GraphicsBuffer, Singleton, ());
}
