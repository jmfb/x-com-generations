#include "FontNormal.h"

namespace XCom
{

const unsigned long FONTNORMAL_HEIGHT = 9;

const unsigned char FONTNORMAL_SPACE[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_TAB[] = {
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
};

const unsigned char FONTNORMAL_0[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_1[] = {
    6, 5, 5, 6, 0, 
    5, 1, 1, 5, 0, 
    6, 5, 1, 5, 0, 
    6, 5, 1, 5, 0, 
    6, 5, 1, 5, 0, 
    6, 5, 1, 5, 0, 
    5, 1, 1, 1, 5, 
    6, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_2[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_3[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 1, 5, 
    0, 5, 1, 1, 2, 6, 
    0, 6, 5, 5, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_4[] = {
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    0, 0, 0, 5, 1, 5, 
    0, 0, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_5[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_6[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_7[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    0, 0, 0, 5, 1, 5, 
    0, 0, 0, 5, 1, 5, 
    0, 0, 0, 5, 1, 5, 
    0, 0, 0, 5, 1, 5, 
    0, 0, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_8[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 2, 1, 1, 2, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_9[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    0, 0, 0, 5, 1, 5, 
    0, 0, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_A[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_B[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_C[] = {
    6, 5, 5, 5, 6, 
    5, 2, 1, 1, 5, 
    5, 1, 5, 5, 6, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 5, 6, 
    5, 2, 1, 1, 5, 
    6, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_D[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_E[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 5, 0, 
    5, 1, 5, 5, 6, 0, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_F[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 5, 0, 
    5, 1, 5, 5, 6, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    6, 5, 6, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_G[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_H[] = {
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_I[] = {
    6, 5, 5, 5, 6, 
    5, 1, 1, 1, 5, 
    6, 5, 1, 5, 6, 
    0, 5, 1, 5, 0, 
    0, 5, 1, 5, 0, 
    6, 5, 1, 5, 6, 
    5, 1, 1, 1, 5, 
    6, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_J[] = {
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 1, 5, 6, 
    0, 0, 0, 5, 1, 5, 0, 
    6, 5, 6, 5, 1, 5, 0, 
    5, 1, 5, 5, 1, 5, 0, 
    5, 2, 1, 1, 2, 5, 0, 
    6, 5, 5, 5, 5, 6, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_K[] = {
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 1, 5, 6, 
    5, 1, 1, 5, 6, 0, 
    5, 1, 5, 1, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_L[] = {
    6, 5, 6, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_M[] = {
    6, 5, 6, 0, 6, 5, 6, 
    5, 1, 5, 6, 5, 1, 5, 
    5, 1, 1, 5, 1, 1, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 1, 5, 5, 5, 1, 5, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 0, 5, 1, 5, 
    6, 5, 6, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_N[] = {
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 5, 1, 5, 
    5, 1, 5, 1, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_O[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_P[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 5, 0, 0, 0, 
    6, 5, 6, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_Q[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 1, 2, 5, 
    5, 2, 1, 2, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_R[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_S[] = {
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_T[] = {
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 1, 5, 5, 6, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_U[] = {
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_V[] = {
    6, 5, 6, 0, 6, 5, 6, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 6, 5, 1, 5, 
    6, 5, 1, 5, 1, 5, 6, 
    0, 6, 5, 1, 5, 6, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_W[] = {
    6, 5, 6, 0, 6, 5, 6, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 5, 5, 1, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 1, 1, 5, 1, 1, 5, 
    5, 1, 5, 6, 5, 1, 5, 
    6, 5, 6, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_X[] = {
    6, 5, 6, 0, 6, 5, 6, 
    5, 1, 5, 6, 5, 1, 5, 
    6, 5, 1, 5, 1, 5, 6, 
    0, 6, 5, 1, 5, 6, 0, 
    0, 6, 5, 1, 5, 6, 0, 
    6, 5, 1, 5, 1, 5, 6, 
    5, 1, 5, 6, 5, 1, 5, 
    6, 5, 6, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_Y[] = {
    6, 5, 6, 0, 6, 5, 6, 
    5, 1, 5, 0, 5, 1, 5, 
    5, 1, 5, 6, 5, 1, 5, 
    6, 5, 1, 5, 1, 5, 6, 
    0, 6, 5, 1, 5, 6, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_Z[] = {
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    0, 6, 5, 1, 5, 6, 
    6, 5, 1, 5, 6, 0, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};

const unsigned char FONTNORMAL_a[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 2, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 2, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_b[] = {
    6, 5, 6, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 2, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 2, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_c[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    6, 5, 5, 5, 6, 
    5, 2, 1, 1, 5, 
    5, 1, 5, 5, 6, 
    5, 1, 5, 5, 6, 
    5, 2, 1, 1, 5, 
    6, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_d[] = {
    0, 0, 0, 6, 5, 6, 
    0, 0, 0, 5, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    5, 2, 1, 2, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 2, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_e[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    5, 1, 1, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_f[] = {
    6, 5, 5, 5, 6, 
    5, 2, 1, 1, 5, 
    5, 1, 5, 5, 6, 
    5, 1, 1, 1, 5, 
    5, 1, 5, 5, 6, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_g[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 2, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 2, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_h[] = {
    6, 5, 6, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 2, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_i[] = {
    6, 5, 6, 
    5, 1, 5, 
    5, 5, 5, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    6, 5, 6, 
    0, 0, 0, 
};
const unsigned char FONTNORMAL_j[] = {
    0, 0, 6, 5, 6, 
    0, 0, 5, 1, 5, 
    0, 6, 5, 5, 6, 
    0, 5, 1, 1, 5, 
    0, 6, 5, 1, 5, 
    0, 0, 5, 1, 5, 
    6, 5, 5, 1, 5, 
    5, 1, 1, 2, 5, 
    6, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_k[] = {
    6, 5, 6, 0, 0, 0, 
    5, 1, 5, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 1, 5, 6, 
    5, 1, 1, 5, 6, 0, 
    5, 1, 5, 1, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_l[] = {
    6, 5, 6, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    6, 5, 6, 
    0, 0, 0, 
};
const unsigned char FONTNORMAL_m[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 2, 1, 2, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    6, 5, 6, 5, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_n[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 1, 2, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_o[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 5, 1, 1, 5, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 5, 1, 1, 5, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_p[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 1, 2, 1, 2, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 2, 1, 2, 5, 
    5, 1, 5, 5, 5, 6, 
    6, 5, 6, 0, 0, 0, 
};
const unsigned char FONTNORMAL_q[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 2, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 2, 1, 5, 
    6, 5, 5, 5, 1, 5, 
    0, 0, 0, 6, 5, 6, 
};
const unsigned char FONTNORMAL_r[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 1, 2, 1, 1, 5, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    6, 5, 6, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_s[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 2, 1, 1, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    5, 5, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_t[] = {
    6, 5, 6, 0, 0, 0, 
    5, 1, 5, 0, 0, 0, 
    5, 1, 5, 5, 6, 0, 
    5, 1, 1, 1, 5, 0, 
    5, 1, 5, 5, 5, 6, 
    5, 1, 5, 5, 6, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_u[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_v[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    6, 5, 6, 0, 6, 5, 6, 
    5, 1, 5, 6, 5, 1, 5, 
    5, 1, 5, 6, 5, 1, 5, 
    6, 5, 1, 5, 1, 5, 6, 
    0, 6, 5, 1, 5, 6, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_w[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    6, 5, 6, 5, 6, 5, 6, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 1, 5, 1, 5, 1, 5, 
    5, 2, 1, 2, 1, 2, 5, 
    6, 5, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_x[] = {
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    6, 5, 6, 5, 6, 
    5, 1, 5, 1, 5, 
    6, 5, 1, 5, 6, 
    6, 5, 1, 5, 6, 
    5, 1, 5, 1, 5, 
    6, 5, 6, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_y[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 6, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 5, 
    5, 2, 1, 1, 1, 5, 
    5, 5, 5, 5, 1, 5, 
    5, 1, 1, 1, 2, 5, 
    6, 5, 5, 5, 5, 6, 
};
const unsigned char FONTNORMAL_z[] = {
    0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 1, 5, 6, 
    6, 5, 1, 5, 5, 6, 
    5, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 
};

const unsigned char FONTNORMAL_LT[] = {
    0, 0, 0, 0, 0, 
    0, 0, 6, 5, 6, 
    0, 6, 5, 1, 5, 
    6, 5, 1, 2, 5, 
    5, 1, 2, 2, 5, 
    6, 5, 1, 2, 5, 
    0, 6, 5, 1, 5, 
    0, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_GT[] = {
    0, 0, 0, 0, 0, 
    6, 5, 6, 0, 0, 
    5, 1, 5, 6, 0, 
    5, 2, 1, 5, 6, 
    5, 2, 2, 1, 5, 
    5, 2, 1, 5, 6, 
    5, 1, 5, 6, 0, 
    6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_COMMA[] = {
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    6, 5, 5, 6, 
    5, 1, 2, 5, 
    6, 5, 1, 5, 
    5, 1, 5, 6, 
    6, 5, 6, 0, 
};
const unsigned char FONTNORMAL_PERIOD[] = {
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    6, 5, 6, 
    5, 1, 5, 
    6, 5, 6, 
    0, 0, 0, 
};
const unsigned char FONTNORMAL_SLASH[] = {
    0, 0, 0, 0, 0, 6, 5, 6, 
    0, 0, 0, 0, 6, 5, 1, 5, 
    0, 0, 0, 6, 5, 1, 5, 6, 
    0, 0, 6, 5, 1, 5, 6, 0, 
    0, 6, 5, 1, 5, 6, 0, 0, 
    6, 5, 1, 5, 6, 0, 0, 0, 
    5, 1, 5, 6, 0, 0, 0, 0, 
    6, 5, 6, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_BACKSLASH[] = {
    6, 5, 6, 0, 0, 0, 0, 0, 
    5, 1, 5, 6, 0, 0, 0, 0, 
    6, 5, 1, 5, 6, 0, 0, 0, 
    0, 6, 5, 1, 5, 6, 0, 0, 
    0, 0, 6, 5, 1, 5, 6, 0, 
    0, 0, 0, 6, 5, 1, 5, 6, 
    0, 0, 0, 0, 6, 5, 1, 5, 
    0, 0, 0, 0, 0, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_PIPE[] = {
    6, 5, 6, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    6, 5, 6, 0, 0, 
};
const unsigned char FONTNORMAL_BANG[] = {
    6, 5, 6, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    5, 1, 5, 
    6, 5, 6, 
    5, 1, 5, 
    6, 5, 6, 
    0, 0, 0, 
};
const unsigned char FONTNORMAL_AT[] = {
    6, 6, 5, 5, 5, 5, 6, 0, 
    6, 5, 1, 1, 1, 1, 5, 6, 
    5, 1, 5, 5, 5, 5, 1, 5, 
    6, 5, 2, 1, 1, 5, 1, 5, 
    0, 5, 1, 5, 1, 5, 1, 5, 
    0, 5, 1, 5, 1, 5, 1, 5, 
    0, 5, 2, 1, 1, 1, 5, 6, 
    0, 6, 5, 5, 5, 5, 6, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_POUND[] = {
    0, 6, 5, 6, 6, 5, 6, 0, 
    6, 5, 1, 5, 5, 1, 5, 6, 
    5, 1, 1, 1, 1, 1, 1, 5, 
    6, 5, 1, 5, 5, 1, 5, 6, 
    6, 5, 1, 5, 5, 1, 5, 6, 
    5, 1, 1, 1, 1, 1, 1, 5, 
    6, 5, 1, 5, 5, 1, 5, 6, 
    0, 6, 5, 6, 6, 5, 6, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_DOLLAR[] = {
    0, 0, 6, 5, 6, 0, 0, 
    6, 5, 5, 1, 5, 5, 6, 
    5, 2, 1, 1, 1, 1, 5, 
    5, 1, 5, 1, 5, 5, 6, 
    5, 2, 1, 1, 1, 2, 5, 
    6, 5, 5, 1, 5, 1, 5, 
    5, 1, 1, 1, 1, 2, 5, 
    6, 5, 5, 1, 5, 5, 6, 
    0, 0, 6, 5, 6, 0, 0, 
};
const unsigned char FONTNORMAL_PERCENT[] = {
    6, 5, 5, 6, 0, 6, 5, 6, 
    5, 1, 1, 5, 6, 5, 1, 5, 
    5, 1, 1, 5, 5, 1, 5, 6, 
    6, 5, 5, 5, 1, 5, 6, 0, 
    0, 6, 5, 1, 5, 5, 5, 6, 
    6, 5, 1, 5, 5, 1, 1, 5, 
    5, 1, 5, 6, 5, 1, 1, 5, 
    6, 5, 6, 0, 6, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_HAT[] = {
    0, 0, 6, 5, 6, 0, 0, 
    0, 6, 5, 1, 5, 6, 0, 
    6, 5, 1, 1, 1, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 1, 5, 5, 6, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 6, 5, 6, 0, 0, 
};
const unsigned char FONTNORMAL_AND[] = {
    0, 6, 5, 5, 6, 0, 0, 0, 
    6, 5, 1, 1, 5, 6, 0, 0, 
    5, 1, 5, 5, 1, 5, 0, 0, 
    6, 5, 1, 1, 5, 6, 5, 6, 
    5, 1, 5, 5, 1, 5, 1, 5, 
    5, 1, 5, 5, 5, 1, 5, 6, 
    6, 5, 1, 1, 1, 5, 1, 5, 
    0, 6, 5, 5, 5, 6, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_SPLAT[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 6, 5, 6, 6, 5, 6, 0, 
    0, 5, 1, 5, 5, 1, 5, 0, 
    6, 5, 5, 1, 1, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 1, 1, 5, 5, 6, 
    0, 5, 1, 5, 5, 1, 5, 0, 
    0, 6, 5, 6, 6, 5, 6, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_OPEN_PAREN[] = {
    6, 5, 5, 6, 
    5, 2, 1, 5, 
    5, 1, 5, 6, 
    5, 1, 5, 0, 
    5, 1, 5, 0, 
    5, 1, 5, 0, 
    5, 1, 5, 6, 
    5, 2, 1, 5, 
    6, 5, 5, 6, 
};
const unsigned char FONTNORMAL_CLOSE_PAREN[] = {
    6, 5, 5, 6, 
    5, 1, 2, 5, 
    6, 5, 1, 5, 
    0, 5, 1, 5, 
    0, 5, 1, 5, 
    0, 5, 1, 5, 
    6, 5, 1, 5, 
    5, 1, 2, 5, 
    6, 5, 5, 6, 
};
const unsigned char FONTNORMAL_MINUS[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_UNDERSCORE[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 5, 6, 
};
const unsigned char FONTNORMAL_EQUAL[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 5, 5, 5, 6, 
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_PLUS[] = {
    0, 0, 0, 0, 0, 0, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    6, 5, 5, 1, 5, 5, 6, 
    5, 1, 1, 1, 1, 1, 5, 
    6, 5, 5, 1, 5, 5, 6, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_TILDE[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 6, 5, 5, 6, 6, 5, 6, 
    6, 5, 1, 1, 5, 5, 1, 5, 
    5, 1, 5, 5, 1, 1, 5, 6, 
    6, 5, 6, 6, 5, 5, 6, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_OPEN_CURLY[] = {
    0, 6, 5, 5, 6, 
    0, 5, 2, 1, 5, 
    0, 5, 1, 5, 6, 
    6, 5, 1, 5, 0, 
    5, 1, 2, 6, 0, 
    6, 5, 1, 5, 0, 
    0, 5, 1, 5, 6, 
    0, 5, 2, 1, 5, 
    0, 6, 5, 5, 6, 
};
const unsigned char FONTNORMAL_CLOSE_CURLY[] = {
    6, 5, 5, 6, 0, 
    5, 1, 2, 5, 0, 
    6, 5, 1, 5, 0, 
    0, 5, 1, 5, 6, 
    0, 6, 2, 1, 5, 
    0, 5, 1, 5, 6, 
    6, 5, 1, 5, 0, 
    5, 1, 2, 5, 0, 
    6, 5, 5, 6, 0, 
};
const unsigned char FONTNORMAL_OPEN_SQUARE[] = {
    6, 5, 5, 5, 6, 
    5, 1, 1, 1, 5, 
    5, 1, 5, 5, 6, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 0, 0, 
    5, 1, 5, 5, 6, 
    5, 1, 1, 1, 5, 
    6, 5, 5, 5, 6, 
};
const unsigned char FONTNORMAL_CLOSE_SQUARE[] = {
    6, 5, 5, 5, 6, 
    5, 1, 1, 1, 5, 
    6, 5, 5, 1, 5, 
    0, 0, 5, 1, 5, 
    0, 0, 5, 1, 5, 
    0, 0, 5, 1, 5, 
    6, 5, 5, 1, 5, 
    5, 1, 1, 1, 5, 
    6, 5, 5, 5, 6, 
};
const unsigned char FONTNORMAL_QUESTION[] = {
    0, 6, 5, 5, 5, 6, 0, 
    6, 5, 1, 1, 1, 5, 6, 
    5, 1, 5, 5, 5, 1, 5, 
    6, 5, 6, 6, 5, 1, 5, 
    0, 0, 6, 5, 1, 5, 6, 
    0, 0, 5, 1, 5, 6, 0, 
    0, 0, 6, 5, 6, 0, 0, 
    0, 0, 5, 1, 5, 0, 0, 
    0, 0, 6, 5, 6, 0, 0, 
};
const unsigned char FONTNORMAL_COLON[] = {
    0, 0, 0, 
    0, 0, 0, 
    6, 5, 6, 
    5, 1, 5, 
    6, 5, 6, 
    6, 5, 6, 
    5, 1, 5, 
    6, 5, 6, 
    0, 0, 0, 
};
const unsigned char FONTNORMAL_SEMICOLON[] = {
    0, 0, 0, 0, 
    0, 0, 0, 0, 
    0, 6, 5, 6, 
    0, 5, 1, 5, 
    0, 6, 5, 6, 
    0, 6, 5, 6, 
    6, 5, 1, 5, 
    5, 2, 5, 6, 
    6, 5, 6, 0, 
};
const unsigned char FONTNORMAL_DOUBLE_QUOTE[] = {
    6, 5, 6, 5, 6, 
    5, 1, 5, 1, 5, 
    5, 1, 5, 1, 5, 
    6, 5, 6, 5, 6, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 
};
const unsigned char FONTNORMAL_SINGLE_QUOTE[] = {
    6, 5, 6, 
    5, 1, 5, 
    5, 1, 5, 
    6, 5, 6, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0, 
};

FontNormal::FontNormal()
{
    Register(' ', sizeof(FONTNORMAL_SPACE), FONTNORMAL_SPACE);
    Register('\t', sizeof(FONTNORMAL_TAB), FONTNORMAL_TAB);
    
    Register('0', sizeof(FONTNORMAL_0), FONTNORMAL_0);
    Register('1', sizeof(FONTNORMAL_1), FONTNORMAL_1);
    Register('2', sizeof(FONTNORMAL_2), FONTNORMAL_2);
    Register('3', sizeof(FONTNORMAL_3), FONTNORMAL_3);
    Register('4', sizeof(FONTNORMAL_4), FONTNORMAL_4);
    Register('5', sizeof(FONTNORMAL_5), FONTNORMAL_5);
    Register('6', sizeof(FONTNORMAL_6), FONTNORMAL_6);
    Register('7', sizeof(FONTNORMAL_7), FONTNORMAL_7);
    Register('8', sizeof(FONTNORMAL_8), FONTNORMAL_8);
    Register('9', sizeof(FONTNORMAL_9), FONTNORMAL_9);
    
    Register('A', sizeof(FONTNORMAL_A), FONTNORMAL_A);
    Register('B', sizeof(FONTNORMAL_B), FONTNORMAL_B);
    Register('C', sizeof(FONTNORMAL_C), FONTNORMAL_C);
    Register('D', sizeof(FONTNORMAL_D), FONTNORMAL_D);
    Register('E', sizeof(FONTNORMAL_E), FONTNORMAL_E);
    Register('F', sizeof(FONTNORMAL_F), FONTNORMAL_F);
    Register('G', sizeof(FONTNORMAL_G), FONTNORMAL_G);
    Register('H', sizeof(FONTNORMAL_H), FONTNORMAL_H);
    Register('I', sizeof(FONTNORMAL_I), FONTNORMAL_I);
    Register('J', sizeof(FONTNORMAL_J), FONTNORMAL_J);
    Register('K', sizeof(FONTNORMAL_K), FONTNORMAL_K);
    Register('L', sizeof(FONTNORMAL_L), FONTNORMAL_L);
    Register('M', sizeof(FONTNORMAL_M), FONTNORMAL_M);
    Register('N', sizeof(FONTNORMAL_N), FONTNORMAL_N);
    Register('O', sizeof(FONTNORMAL_O), FONTNORMAL_O);
    Register('P', sizeof(FONTNORMAL_P), FONTNORMAL_P);
    Register('Q', sizeof(FONTNORMAL_Q), FONTNORMAL_Q);
    Register('R', sizeof(FONTNORMAL_R), FONTNORMAL_R);
    Register('S', sizeof(FONTNORMAL_S), FONTNORMAL_S);
    Register('T', sizeof(FONTNORMAL_T), FONTNORMAL_T);
    Register('U', sizeof(FONTNORMAL_U), FONTNORMAL_U);
    Register('V', sizeof(FONTNORMAL_V), FONTNORMAL_V);
    Register('W', sizeof(FONTNORMAL_W), FONTNORMAL_W);
    Register('X', sizeof(FONTNORMAL_X), FONTNORMAL_X);
    Register('Y', sizeof(FONTNORMAL_Y), FONTNORMAL_Y);
    Register('Z', sizeof(FONTNORMAL_Z), FONTNORMAL_Z);

    Register('a', sizeof(FONTNORMAL_a), FONTNORMAL_a);
    Register('b', sizeof(FONTNORMAL_b), FONTNORMAL_b);
    Register('c', sizeof(FONTNORMAL_c), FONTNORMAL_c);
    Register('d', sizeof(FONTNORMAL_d), FONTNORMAL_d);
    Register('e', sizeof(FONTNORMAL_e), FONTNORMAL_e);
    Register('f', sizeof(FONTNORMAL_f), FONTNORMAL_f);
    Register('g', sizeof(FONTNORMAL_g), FONTNORMAL_g);
    Register('h', sizeof(FONTNORMAL_h), FONTNORMAL_h);
    Register('i', sizeof(FONTNORMAL_i), FONTNORMAL_i);
    Register('j', sizeof(FONTNORMAL_j), FONTNORMAL_j);
    Register('k', sizeof(FONTNORMAL_k), FONTNORMAL_k);
    Register('l', sizeof(FONTNORMAL_l), FONTNORMAL_l);
    Register('m', sizeof(FONTNORMAL_m), FONTNORMAL_m);
    Register('n', sizeof(FONTNORMAL_n), FONTNORMAL_n);
    Register('o', sizeof(FONTNORMAL_o), FONTNORMAL_o);
    Register('p', sizeof(FONTNORMAL_p), FONTNORMAL_p);
    Register('q', sizeof(FONTNORMAL_q), FONTNORMAL_q);
    Register('r', sizeof(FONTNORMAL_r), FONTNORMAL_r);
    Register('s', sizeof(FONTNORMAL_s), FONTNORMAL_s);
    Register('t', sizeof(FONTNORMAL_t), FONTNORMAL_t);
    Register('u', sizeof(FONTNORMAL_u), FONTNORMAL_u);
    Register('v', sizeof(FONTNORMAL_v), FONTNORMAL_v);
    Register('w', sizeof(FONTNORMAL_w), FONTNORMAL_w);
    Register('x', sizeof(FONTNORMAL_x), FONTNORMAL_x);
    Register('y', sizeof(FONTNORMAL_y), FONTNORMAL_y);
    Register('z', sizeof(FONTNORMAL_z), FONTNORMAL_z);

    Register('<', sizeof(FONTNORMAL_LT), FONTNORMAL_LT);
    Register('>', sizeof(FONTNORMAL_GT), FONTNORMAL_GT);
    Register(',', sizeof(FONTNORMAL_COMMA), FONTNORMAL_COMMA);
    Register('.', sizeof(FONTNORMAL_PERIOD), FONTNORMAL_PERIOD);
    Register('/', sizeof(FONTNORMAL_SLASH), FONTNORMAL_SLASH);
    Register('\\', sizeof(FONTNORMAL_BACKSLASH), FONTNORMAL_BACKSLASH);
    Register('|', sizeof(FONTNORMAL_PIPE), FONTNORMAL_PIPE);
    Register('!', sizeof(FONTNORMAL_BANG), FONTNORMAL_BANG);
    Register('@', sizeof(FONTNORMAL_AT), FONTNORMAL_AT);
    Register('#', sizeof(FONTNORMAL_POUND), FONTNORMAL_POUND);
    Register('$', sizeof(FONTNORMAL_DOLLAR), FONTNORMAL_DOLLAR);
    Register('%', sizeof(FONTNORMAL_PERCENT), FONTNORMAL_PERCENT);
    Register('^', sizeof(FONTNORMAL_HAT), FONTNORMAL_HAT);
    Register('&', sizeof(FONTNORMAL_AND), FONTNORMAL_AND);
    Register('*', sizeof(FONTNORMAL_SPLAT), FONTNORMAL_SPLAT);
    Register('(', sizeof(FONTNORMAL_OPEN_PAREN), FONTNORMAL_OPEN_PAREN);
    Register(')', sizeof(FONTNORMAL_CLOSE_PAREN), FONTNORMAL_CLOSE_PAREN);
    Register('-', sizeof(FONTNORMAL_MINUS), FONTNORMAL_MINUS);
    Register('_', sizeof(FONTNORMAL_UNDERSCORE), FONTNORMAL_UNDERSCORE);
    Register('=', sizeof(FONTNORMAL_EQUAL), FONTNORMAL_EQUAL);
    Register('+', sizeof(FONTNORMAL_PLUS), FONTNORMAL_PLUS);
    Register('~', sizeof(FONTNORMAL_TILDE), FONTNORMAL_TILDE);
    Register('{', sizeof(FONTNORMAL_OPEN_CURLY), FONTNORMAL_OPEN_CURLY);
    Register('}', sizeof(FONTNORMAL_CLOSE_CURLY), FONTNORMAL_CLOSE_CURLY);
    Register('[', sizeof(FONTNORMAL_OPEN_SQUARE), FONTNORMAL_OPEN_SQUARE);
    Register(']', sizeof(FONTNORMAL_CLOSE_SQUARE), FONTNORMAL_CLOSE_SQUARE);
    Register('?', sizeof(FONTNORMAL_QUESTION), FONTNORMAL_QUESTION);
    Register(':', sizeof(FONTNORMAL_COLON), FONTNORMAL_COLON);
    Register(';', sizeof(FONTNORMAL_SEMICOLON), FONTNORMAL_SEMICOLON);
    Register('"', sizeof(FONTNORMAL_DOUBLE_QUOTE), FONTNORMAL_DOUBLE_QUOTE);
    Register('\'', sizeof(FONTNORMAL_SINGLE_QUOTE), FONTNORMAL_SINGLE_QUOTE);
}

FontNormal::~FontNormal()
{
	//nothing
}

unsigned long FontNormal::GetHeight() const
{
	return FONTNORMAL_HEIGHT;
}

}
