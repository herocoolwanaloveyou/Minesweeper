#include "pch.h"
#include "background.h"

background::background()
{
	ref = begin_ref;
	for (int i = 0; i < COT + 20; i++)
	{
		ref = !ref;
		for (int j = 0; j < COT + 30; j++)
		{
			ref = !ref;
			if (ref == true)
			{
				ds[i][j] = Hcn_color(XDAU - DAI + j * DAI, YDAU - DAI + i * DAI, XDAU - DAI + j * DAI + DAI, YDAU - DAI + i * DAI + DAI, 64, 64, 64, 102, 102, 250);
			}
			else
			{
				ds[i][j] = Hcn_color(XDAU - DAI + j * DAI, YDAU - DAI + i * DAI, XDAU - DAI + j * DAI + DAI, YDAU - DAI + i * DAI + DAI, 128, 128, 128, 102, 102, 250);
			}
		}
	}
}

void background::Vehinh(CClientDC* pdc)
{
	for (int i = 0; i < COT + 20; i++)
	{
		for (int j = 0; j < COT + 30; j++)
		{
			ds[i][j].Vehinh(pdc);
		}
	}
}
