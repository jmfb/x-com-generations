#pragma once
#include "UnitTest/UnitTest.h"
#include "DateTimeUtility.h"
#include "DateTime.h"

namespace UnitTest
{
	INJECT(XCom::IDateTimeUtility, XCom::DateTimeUtility, Instance, ());
	INJECT(XCom::IDateTime, XCom::DateTime, Instance, (XCom::IDateTimeUtility*));
}
