#pragma once
#include "UnitTest/UnitTest.h"
#include "DateTimeUtility.h"
#include "DateTime.h"
#include "Mouse/Mouse.h"
#include "System/System.h"

namespace UnitTest
{
	INJECT(XCom::IDateTimeUtility, XCom::DateTimeUtility, Instance, ());
	INJECT(XCom::IDateTime, XCom::DateTime, Instance, (XCom::IDateTimeUtility*));
	INJECT(XCom::ISystem, XCom::System, Instance, ());
	INJECT(XCom::IMouse, XCom::Mouse, Singleton, (XCom::ISystem*));
}
