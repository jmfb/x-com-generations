#include "FontUpDown.h"

namespace XCom
{

const unsigned long FONTUPDOWN_HEIGHT = 8;

const unsigned char FONTUPDOWN_UP[] = {
    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5,
    2, 5, 5, 5, 5, 4, 5, 5, 5, 5, 6,
    2, 5, 5, 5, 4, 1, 4, 5, 5, 5, 6,
    2, 5, 5, 4, 1, 1, 1, 4, 5, 5, 6,
    2, 5, 4, 1, 1, 1, 1, 1, 4, 5, 6,
    2, 4, 1, 1, 1, 1, 1, 1, 1, 4, 6,
    2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6,
    5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
};

const unsigned char FONTUPDOWN_DOWN[] = {
    1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5,
    2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6,
    2, 4, 1, 1, 1, 1, 1, 1, 1, 4, 6,
    2, 5, 4, 1, 1, 1, 1, 1, 4, 5, 6,
    2, 5, 5, 4, 1, 1, 1, 4, 5, 5, 6,
    2, 5, 5, 5, 4, 1, 4, 5, 5, 5, 6,
    2, 5, 5, 5, 5, 4, 5, 5, 5, 5, 6,
    5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
};

FontUpDown::FontUpDown()
{
    Register('U', sizeof(FONTUPDOWN_UP), FONTUPDOWN_UP);
    Register('D', sizeof(FONTUPDOWN_DOWN), FONTUPDOWN_DOWN);
}

FontUpDown::~FontUpDown()
{
	//nothing
}

unsigned long FontUpDown::GetHeight() const
{
	return FONTUPDOWN_HEIGHT;
}

}
