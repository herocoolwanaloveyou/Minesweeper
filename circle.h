#pragma once
class circle
{
public:
	circle() ;
	~circle() ;
	circle(int x, int y, int r);
	float dientich();
	float chuvi();
	void goDown(int d);
	void goUp(int d);
	void goLeft(int d);
	void goRight(int d);
	int x, y, r;
	int x1, y1, x2, y2;
	void draw(CClientDC* pDC);
};

