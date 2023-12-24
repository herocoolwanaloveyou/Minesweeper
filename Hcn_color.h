#pragma once
#include "pch.h"
#include "Hcn.h"
class Hcn_color :
    public Hcn
{
public:
    Hcn_color() {};
    Hcn_color(int mx1, int my1, int mx2, int my2, int mr, int mg, int mb, int mrv, int mgv, int mbv);
    void Vehinh(CClientDC* pDC);
    int r, g, b;
    int rv, gv, bv;
};

