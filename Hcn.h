#pragma once
class Hcn
{
public:
	int x1, y1, x2, y2;
	Hcn();
	Hcn(int xm1, int my1, int mx2, int my2);
	void Vehinh(CClientDC* pdc);
	int kttronghinh(CPoint p);
};

