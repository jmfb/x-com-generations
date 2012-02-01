#include "FontSmall.h"

namespace XCom
{

const unsigned FONTSMALL_HEIGHT = 5;

const unsigned char FONTSMALL_A[] = {
    2, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
};
const unsigned char FONTSMALL_B[] = {
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
};
const unsigned char FONTSMALL_C[] = {
    2, 1, 0, 0, 
    1, 0, 0, 0, 
    1, 0, 0, 0, 
    1, 0, 0, 0, 
    2, 1, 0, 0, 
};
const unsigned char FONTSMALL_D[] = {
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
};
const unsigned char FONTSMALL_E[] = {
    1, 1, 0, 0, 
    1, 0, 0, 0, 
    1, 1, 0, 0, 
    1, 0, 0, 0, 
    1, 1, 0, 0, 
};
const unsigned char FONTSMALL_F[] = {
    1, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 1, 0, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
};
const unsigned char FONTSMALL_G[] = {
    2, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 1, 0, 0, 
};
const unsigned char FONTSMALL_H[] = {
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
};
const unsigned char FONTSMALL_I[] = {
    1, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
    1, 0, 0, 
};
const unsigned char FONTSMALL_N[] = {
    1, 0, 0, 1, 0, 0, 
    1, 1, 0, 1, 0, 0, 
    1, 0, 1, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
    1, 0, 0, 1, 0, 0, 
};
const unsigned char FONTSMALL_O[] = {
    2, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 2, 0, 0, 
};
const unsigned char FONTSMALL_P[] = {
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
    1, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 
};
const unsigned char FONTSMALL_R[] = {
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
};
const unsigned char FONTSMALL_S[] = {
    2, 1, 1, 0, 0, 
    1, 0, 0, 0, 0, 
    2, 1, 2, 0, 0, 
    0, 0, 1, 0, 0, 
    1, 1, 2, 0, 0, 
};
const unsigned char FONTSMALL_T[] = {
    1, 1, 1, 0, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
    0, 1, 0, 0, 0, 
};
const unsigned char FONTSMALL_U[] = {
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    1, 0, 1, 0, 0, 
    2, 1, 2, 0, 0, 
};

FontSmall::FontSmall()
{
    Register('A', sizeof(FONTSMALL_A), FONTSMALL_A);
    Register('B', sizeof(FONTSMALL_B), FONTSMALL_B);
    Register('C', sizeof(FONTSMALL_C), FONTSMALL_C);
    Register('D', sizeof(FONTSMALL_D), FONTSMALL_D);
    Register('E', sizeof(FONTSMALL_E), FONTSMALL_E);
    Register('F', sizeof(FONTSMALL_F), FONTSMALL_F);
    Register('G', sizeof(FONTSMALL_G), FONTSMALL_G);
    Register('H', sizeof(FONTSMALL_H), FONTSMALL_H);
    Register('I', sizeof(FONTSMALL_I), FONTSMALL_I);
    Register('N', sizeof(FONTSMALL_N), FONTSMALL_N);
    Register('O', sizeof(FONTSMALL_O), FONTSMALL_O);
    Register('P', sizeof(FONTSMALL_P), FONTSMALL_P);
    Register('R', sizeof(FONTSMALL_R), FONTSMALL_R);
    Register('S', sizeof(FONTSMALL_S), FONTSMALL_S);
    Register('T', sizeof(FONTSMALL_T), FONTSMALL_T);
    Register('U', sizeof(FONTSMALL_U), FONTSMALL_U);
}

FontSmall::~FontSmall()
{
	//nothing
}

unsigned long FontSmall::GetHeight() const
{
	return FONTSMALL_HEIGHT;
}

}
