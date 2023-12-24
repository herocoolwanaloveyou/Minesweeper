#include "pch.h"
#include "Min.h"

Min::Min()
{
}

Min::Min(int x, int y, int d)
{
	this->x = x;
	this->y = y;
	this->d = d;
}

void Min::Vehinh(CClientDC* pdc)
{
    CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
    CPen* pOldPen = pdc->SelectObject(&pen);
    CBrush myBrush(RGB(0, 0, 0));
    CBrush* pOldBrush = pdc->SelectObject(&myBrush);
    circle* tron = new circle(x, y, 4.5 * d);
    tron->draw(pdc);
    pdc->Rectangle(x - 0.5 * d, y - 6 * d, x + 0.5 * d, y + 6 * d);
    pdc->Rectangle(x - 6 * d, y - 6 * d, x - 6 * d + 5, y - 6 * d + 5);
    pdc->Rectangle(x + 6 * d, y - 6 * d, x + 6 * d - 5, y - 6 * d + 5);
    pdc->Rectangle(x - 6 * d, y - 0.5 * d, x + 6 * d, y + 0.5 * d);
    pdc->Rectangle(x - 6 * d, y + 6 * d, x - 6 * d + 5, y + 6 * d - 5);
    pdc->Rectangle(x + 6 * d, y + 6 * d, x + 6 * d - 5, y + 6 * d - 5);
    pdc->SelectObject(pOldPen);
    pdc->SelectObject(pOldBrush);
}
