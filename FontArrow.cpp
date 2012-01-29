#include "FontArrow.h"

namespace XCom
{

const unsigned long FONTARROW_HEIGHT = 8;

const unsigned char FONTARROW_UP[] = {
    0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
};
const unsigned char FONTARROW_DOWN[] = {
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, 0,
};

FontArrow::FontArrow()
{
    Register('U', sizeof(FONTARROW_UP), FONTARROW_UP);
    Register('D', sizeof(FONTARROW_DOWN), FONTARROW_DOWN);
}

FontArrow::~FontArrow()
{
	//nothing
}

unsigned long FontArrow::GetHeight() const
{
	return FONTARROW_HEIGHT;
}

}
