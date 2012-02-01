#include "FontTime.h"

namespace XCom
{

const unsigned long FONTTIME_HEIGHT = 7;

const unsigned char FONTTIME_SPACE[] = {
    0, 0, 
    0, 0, 
    0, 0, 
    0, 0, 
    0, 0, 
    0, 0, 
    0, 0, 
};

const unsigned char FONTTIME_0[] = {
    2, 1, 1, 2, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    2, 1, 1, 2, 0, 0, 
};
const unsigned char FONTTIME_1[] = {
    0, 1, 0, 0, 0, 
    1, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
    1, 1, 1, 0, 0, 
};
const unsigned char FONTTIME_3[] = {
    1, 1, 2, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 1, 2, 0, 0, 
    0, 0, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
};
const unsigned char FONTTIME_5[] = {
    1, 1, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 0, 
    1, 1, 1, 2, 0, 0, 
    0, 0, 0, 1, 0, 0, 
    0, 0, 0, 1, 0, 0, 
    0, 0, 0, 1, 0, 0, 
    1, 1, 1, 2, 0, 0, 
};

const unsigned char FONTTIME_D[] = {
    1, 1, 1, 2, 0, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 1, 1, 2, 0, 0, 0, 
};
const unsigned char FONTTIME_H[] = {
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 1, 1, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
};
const unsigned char FONTTIME_M[] = {
    1, 0, 0, 0, 1, 0, 0, 
    1, 1, 0, 1, 1, 0, 0, 
    1, 0, 1, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
    1, 0, 0, 0, 1, 0, 0, 
};
const unsigned char FONTTIME_S[] = {
    2, 1, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 0, 
    2, 1, 1, 2, 0, 0, 
    0, 0, 0, 1, 0, 0, 
    0, 0, 0, 1, 0, 0, 
    1, 1, 1, 2, 0, 0, 
};

const unsigned char FONTTIME_a[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    2, 1, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 1, 0, 0, 
};
const unsigned char FONTTIME_c[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    2, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
    2, 1, 1, 0, 0, 
};
const unsigned char FONTTIME_e[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    2, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
    1, 0, 0, 0, 0, 
    2, 1, 1, 0, 0, 
};
const unsigned char FONTTIME_i[] = {
    1, 0, 0, 
    0, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
};
const unsigned char FONTTIME_n[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
};
const unsigned char FONTTIME_o[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    2, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 2, 0, 0, 
};
const unsigned char FONTTIME_r[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    2, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
};
const unsigned char FONTTIME_s[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    2, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 
    2, 1, 2, 0, 0, 
    0, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
};
const unsigned char FONTTIME_u[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 2, 0, 0, 
};
const unsigned char FONTTIME_y[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 1, 0, 0, 
    0, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
};

FontTime::FontTime()
{
    Register(' ', sizeof(FONTTIME_SPACE), FONTTIME_SPACE);

    Register('0', sizeof(FONTTIME_0), FONTTIME_0);
    Register('1', sizeof(FONTTIME_1), FONTTIME_1);
    Register('3', sizeof(FONTTIME_3), FONTTIME_3);
    Register('5', sizeof(FONTTIME_5), FONTTIME_5);

    Register('D', sizeof(FONTTIME_D), FONTTIME_D);
    Register('H', sizeof(FONTTIME_H), FONTTIME_H);
    Register('M', sizeof(FONTTIME_M), FONTTIME_M);
    Register('S', sizeof(FONTTIME_S), FONTTIME_S);

    Register('a', sizeof(FONTTIME_a), FONTTIME_a);
    Register('c', sizeof(FONTTIME_c), FONTTIME_c);
    Register('e', sizeof(FONTTIME_e), FONTTIME_e);
    Register('i', sizeof(FONTTIME_i), FONTTIME_i);
    Register('n', sizeof(FONTTIME_n), FONTTIME_n);
    Register('o', sizeof(FONTTIME_o), FONTTIME_o);
    Register('r', sizeof(FONTTIME_r), FONTTIME_r);
    Register('s', sizeof(FONTTIME_s), FONTTIME_s);
    Register('u', sizeof(FONTTIME_u), FONTTIME_u);
    Register('y', sizeof(FONTTIME_y), FONTTIME_y);
}

FontTime::~FontTime()
{
	//nothing
}

unsigned long FontTime::GetHeight() const
{
	return FONTTIME_HEIGHT;
}

}
