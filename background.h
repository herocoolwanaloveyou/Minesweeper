#pragma once
#include "Hcn_color.h"
#define COT 20
#define DAI 40
#define XDAU -30
#define YDAU -30
class background
{
public:
	background();
	Hcn_color ds[COT + 20][COT + 30];
	void Vehinh(CClientDC* pdc);
	bool begin_ref = true;
	bool ref;
};

