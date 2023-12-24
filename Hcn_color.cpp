#include "pch.h"
#include "Hcn_color.h"
Hcn_color::Hcn_color(int mx1, int my1, int mx2, int my2, int mr, int mg, int mb,int mrv,int mgv,int mbv)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
	r = mr;
	g = mg;
	b = mb;
	rv = mrv;
	gv = mgv;
	bv = mbv;

};
void Hcn_color::Vehinh(CClientDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(rv, gv, bv));
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush myBrush(RGB(r, g, b));
	CBrush* pOldBrush = pDC->SelectObject(&myBrush);
	pDC->Rectangle(x1, y1, x2, y2);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}