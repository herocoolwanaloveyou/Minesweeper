#include "pch.h"
#include "circle_color.h"
circle_color::circle_color(int mx, int my, int mr, int mrd, int mg, int mb,int mrv,int mgv,int mbv)
{
	x = mx;
	y = my;
	r = mr;
	rd = mrd;
	g = mg;
	b = mb;
	rv = mrv;
	gv = mgv;
	bv = mbv;
}
void circle_color::draw(CClientDC* pDC)
{
	CPen pen(PS_SOLID, 1, RGB(rv, gv, bv));
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush myBrush(RGB(rd, g, b));
	CBrush* pOldBrush = pDC->SelectObject(&myBrush);
	pDC->Ellipse(x-r, y+r, x+r, y-r);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}