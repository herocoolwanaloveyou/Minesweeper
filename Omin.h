#pragma once
#include "Hcn.h"
#include "Co.h"
#include "Min.h"
class Omin :
    public Hcn
{
public:
    int giatri=0;
    int datungmoroi=0;
    bool camco = false;
    int mo = 0;
    Omin();
    Omin(int mx1, int my1, int mx2, int my2);
    void Vehinh(CClientDC* pdc);
    int Bamomin(CClientDC* pdc, CPoint P);
    int Datco(CClientDC* pdc, CPoint P);
    //màu ô mìn khi chưa mở
    int r = 0, g = 51, b= 51;
};

