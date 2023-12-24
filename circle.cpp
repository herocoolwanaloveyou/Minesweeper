#include "pch.h"
#include "circle.h"
circle::circle()
{

}
circle::~circle()
{

}
circle::circle(int x, int y, int r)
{
	this->x = x;
	this->y = y;
	this->r = r;
	x1 = x - r;
	y1 = y + r;
	x2 = x + r;
	y2 = y - r;
}
float circle::dientich()
{
	return (float)3.14 *r*r;
}
float circle::chuvi()
{
	return (float)3.14 * 2 * r;
}
void circle::goDown(int d)
{
	y -= d;
}
void circle::goUp(int d)
{
	y += d;
}
void circle::goLeft(int d)
{
	x -= d;
}
void circle::goRight(int d)
{
	x += d;
}
void circle::draw(CClientDC* pDC)
{
	pDC->Ellipse(x1, y1, x2, y2);
}