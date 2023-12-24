#include "pch.h"
#include "Hcn.h"

Hcn::Hcn()
{
	x1 = x2 = y1 = y2 = 0;
}

Hcn::Hcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void Hcn::Vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}

int Hcn::kttronghinh(CPoint p)
{
	if (p.x > x1 && p.x<x2 && p.y>y1 && p.y < y2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
