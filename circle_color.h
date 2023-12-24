#pragma once
#include "circle.h"
class circle_color :
    public circle
{
public:
    circle_color() {};
    circle_color(int mx, int my, int mr, int rd, int g, int b, int mrv, int mgv, int mbv);
    void draw(CClientDC* pDC);
    int rd, g, b;
    int rv, gv, bv;
};

