#include "pch.h"
#include "Co.h"

Co::Co()
{
}

Co::Co(int x, int y, int d)
{
	this->x = x;
	this->y = y;
	this->d = d;
}

void Co::Vehinh(CClientDC* pdc)
{
    CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
    CPen* pOldPen = pdc->SelectObject(&pen);
    CBrush myBrush(RGB(0, 0, 0));
    CBrush* pOldBrush = pdc->SelectObject(&myBrush);
    pdc->Rectangle(x, y, x + d, y + 14 * d);
    pdc->Rectangle(x - 4 * d, y + 14 * d, x + 5 * d, y + 16 * d);
    pdc->Rectangle(x - 7 * d, y + 16 * d, x + 8 * d, y + 18 * d);
    pdc->SelectObject(pOldPen);
    pdc->SelectObject(pOldBrush);
    CPen pen1(PS_SOLID, 1, RGB(255, 0, 0));
    CPen* pOldPen1 = pdc->SelectObject(&pen1);
    CBrush myBrush1(RGB(255, 0, 0));
    CBrush* pOldBrush1 = pdc->SelectObject(&myBrush1);
    CPoint points[3]; // Mảng 3 điểm để vẽ tam giác
    points[0] = CPoint(x-12*d, y-4*d); // Điểm đầu tiên
    points[1] = CPoint(x, y); // Điểm thứ hai
    points[2] = CPoint(x, y-8*d); // Điểm thứ ba
    pdc->Polygon(points, 3); // Vẽ tam giác từ mảng 3 điểm
    pdc->SelectObject(pOldPen1);
    pdc->SelectObject(pOldBrush1);
}
