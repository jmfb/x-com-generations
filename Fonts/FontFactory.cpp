#include "FontFactory.h"
#include "../Error.h"
#include "FontNormal.h"
#include "FontLarge.h"
#include "FontTime.h"
#include "FontSmall.h"
#include "FontArrow.h"
#include "FontUpDown.h"

namespace XCom
{

const BaseFont& FontFactory::GetFont(FontType type)
{
	static FontNormal normal;
	static FontLarge large;
	static FontTime time;
	static FontSmall small;
	static FontArrow arrow;
	static FontUpDown updown;
	
	switch(type)
	{
	case FONT_NORMAL:
		return normal;
	case FONT_LARGE:
		return large;
	case FONT_TIME:
		return time;
	case FONT_SMALL:
		return small;
	case FONT_ARROW:
		return arrow;
	case FONT_UPDOWN:
		return updown;
	}
	RaiseError(0, "", "Invalid font type requested from factory.");
}

}
