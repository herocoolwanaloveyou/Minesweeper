#include "pch.h"
#include "Omin.h"
#include "Hcn_color.h"
#include <mmsystem.h>
#include <Windows.h>
#pragma comment(lib,"winmm.lib")
Omin::Omin()
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

Omin::Omin(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void Omin::Vehinh(CClientDC* pdc)
{
	if (mo == 0)//neu o min chua mo thi to mau nen mau xam
	{
		Hcn_color(x1, y1, x2, y2, r, g, b, 102, 102, 250).Vehinh(pdc);
		if (camco == true)
		{
			Hcn_color(x1, y1, x2, y2, 0, 102, 102, 102, 102, 250).Vehinh(pdc);
			Co* co = new Co((x1 + x2) / 2 - 1, (y1 + y2) / 2 - 7, 1);
			co->Vehinh(pdc);
		}
	}
	else
	{
		CString  strmin, strso;
		LOGFONT lf;
		CFont newFont;

		::ZeroMemory(&lf, sizeof(LOGFONT));
		lf.lfHeight = 35; // Kích thước chữ in ra
		lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
		newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
		CFont* pOldFont = pdc->SelectObject(&newFont); // C
		if (giatri > 0)
		{
			Hcn_color(x1, y1, x2, y2, 255, 255, 255, 102, 102, 250).Vehinh(pdc);
			strso.Format(_T("%d"), giatri);
			switch (giatri)
			{
			case 1: pdc->SetTextColor(RGB(0, 153, 0)); break;
			case 2: pdc->SetTextColor(RGB(0, 0, 153)); break;
			case 3: pdc->SetTextColor(RGB(153, 0, 0)); break;
			case 4: pdc->SetTextColor(RGB(76, 0, 153)); break;
			case 5: pdc->SetTextColor(RGB(153, 76, 0)); break;
			case 6: pdc->SetTextColor(RGB(0, 153, 153)); break;
			case 7: pdc->SetTextColor(RGB(0, 0, 0)); break;
			case 8: pdc->SetTextColor(RGB(64, 64, 64)); break;
			}
			pdc->TextOutW((x1 + x2) / 2 - 10, (y1 + y2) / 2 - 16, strso);
			pdc->SelectObject(pOldFont); // Phục hồi font trước đó
			newFont.DeleteObject(); // Xóa font mới
		}
		else
		{
			if (giatri == -1)
			{
				Hcn_color(x1, y1, x2, y2, 255, 51, 51, 102, 102, 250).Vehinh(pdc);
				Min* min = new Min((x1 + x2) / 2, (y1 + y2) / 2, 3);
				min->Vehinh(pdc);
			}
			else
			{
				Hcn_color(x1, y1, x2, y2, 153, 255, 255, 102, 102, 250).Vehinh(pdc);
			}
		}
	}
}

int Omin::Bamomin(CClientDC* pdc, CPoint p)
{
	if (kttronghinh(p) == 1&& mo == 0)
	{
		PlaySound(TEXT("click-button-140881.wav"), NULL, SND_FILENAME | SND_ASYNC);
		mo = 1;//mo o min
		return 1;
	}
	else
	{
		return 0;
	}
}

int Omin::Datco(CClientDC* pdc, CPoint P)
{
	if (kttronghinh(P) == 1 && mo == 0)
	{
		camco = !camco;
		return 1;
	}
	else
	{
		return 0;
	}
}
