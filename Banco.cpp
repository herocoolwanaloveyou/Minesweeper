#include "pch.h"
#include "Banco.h"
Banco::Banco()
{
	//Khoi tao toa do ban co
	PlaySound(TEXT("Braum-LeagueOfLegends-3767810.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			ds[i][j] = Omin(XDAU + j * DAI, YDAU + i * DAI, XDAU + j * DAI + DAI, YDAU + i * DAI + DAI);
		}
	}
}

void Banco::mucdode()
{
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			ds[i][j].r = 0;
			ds[i][j].g = 51;
			ds[i][j].b = 51;         
		}
	}
	SOLUONG = 40;
	SOLANGIUP = 5;
	THOIGIAN = 600;
}

void Banco::mucdokho()
{
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			ds[i][j].r = 51;
			ds[i][j].g = 0;
			ds[i][j].b = 51;
		}
	}
	SOLUONG = 80;
	SOLANGIUP = 3;
	THOIGIAN = 480;
}

void Banco::mucdotrungbinh()
{ 
	for (int i = 0; i < COT; i++)
	{	 
		for (int j = 0; j < COT; j++)
		{
			ds[i][j].r = 0;
			ds[i][j].g = 25;
			ds[i][j].b = 51;
		}
	}
	SOLUONG = 60;  
	SOLANGIUP = 4;
	THOIGIAN = 540;
}

void Banco::khoitaomin()
{
	//xoá đi các ô mìn trước đó
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			ds[i][j].giatri = 0;
		}
	}
	//Khoi tao gia tri min
	int dem = 0;
	srand(time(NULL));
	int i, j;
	while (dem < SOLUONG)
	{
		i = ((double)rand() / RAND_MAX) * COT;
		j = ((double)rand() / RAND_MAX) * COT;
		if (ds[i][j].giatri != -1)
		{
			ds[i][j].giatri = -1;
			//ds[i][j].mo = 1;
			dem++;
		}
	}
	//Tinh so luong min xung quanh
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri != -1)
			{
				if (ds[i - 1][j].giatri == -1 && i > 0)
				{
					ds[i][j].giatri++;
				}
				if (ds[i + 1][j].giatri == -1 && i < COT - 1)
				{
					ds[i][j].giatri++;
				}
				if (ds[i][j - 1].giatri == -1 && j > 0)
				{
					ds[i][j].giatri++;
				}
				if (ds[i][j + 1].giatri == -1 && j < COT - 1)
				{
					ds[i][j].giatri++;
				}
				if (ds[i - 1][j - 1].giatri == -1 && i > 0 && j > 0)
				{
					ds[i][j].giatri++;
				}
				if (ds[i - 1][j + 1].giatri == -1 && i > 0 && j < COT - 1)
				{
					ds[i][j].giatri++;
				}
				if (ds[i + 1][j + 1].giatri == -1 && i < COT - 1 && j < COT - 1)
				{
					ds[i][j].giatri++;
				}
				if (ds[i + 1][j - 1].giatri == -1 && i < COT - 1 && j > 0)
				{
					ds[i][j].giatri++;
				}
			}
		}
	}
}

void Banco::Vehinh(CClientDC* pdc)
{
	background.Vehinh(pdc);
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			ds[i][j].Vehinh(pdc);
		}
	}
	if (dk != 0)
	{   
		vediem(pdc);
		vesomin(pdc);
		vesocodacam(pdc);
		vesolantrogiup(pdc);
		vethoigian(pdc);
		vebangmotacachchoi(pdc);
		velever(pdc);
	}

	if (dk == 0 && thang == 0)
	{
		vebanghuongdan(pdc);
	}
}

int Banco::tinhdiem()
{
	int diem = 0;
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].mo == 1 && ds[i][j].giatri > 0)
			{
				diem += ds[i][j].giatri;
			}
		}
	}
	return diem;
}

void Banco::vediem(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI, YDAU - DAI + 1 * DAI, XDAU - DAI + 25 * DAI, YDAU - DAI + 4 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	Hcn_color(XDAU - DAI + 22 * DAI + 0.25 * DAI, YDAU - DAI + 1 * DAI + DAI, XDAU - DAI + 25 * DAI - 0.25 * DAI, YDAU - DAI + 4 * DAI - DAI, 255, 255, 255, 255, 255, 255).Vehinh(pdc);

	CString  ghidiem;
	LOGFONT lf;
	CFont newFont;
	ghidiem.Format(_T("SCORE:%d"), tinhdiem());
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + XDAU - DAI + 25 * DAI) / 2 - 10 - 0.9 * DAI, (YDAU - DAI + 1 * DAI + YDAU - DAI + 4 * DAI) / 2 - 10, ghidiem);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
}

void Banco::vesomin(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI, YDAU - DAI + 1 * DAI + 4 * DAI, XDAU - DAI + 25 * DAI, YDAU - DAI + 4 * DAI + 4 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	Hcn_color(XDAU - DAI + 22 * DAI + 0.25 * DAI, YDAU - DAI + 1 * DAI + 4 * DAI + DAI, XDAU - DAI + 25 * DAI - 0.25 * DAI, YDAU - DAI + 4 * DAI + 4 * DAI - DAI, 255, 255, 255, 255, 255, 255).Vehinh(pdc);
	CString  somin;
	LOGFONT lf;
	CFont newFont;
	somin.Format(_T("  MINES:%d"), SOLUONG);
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + XDAU - DAI + 25 * DAI) / 2 - 8 - DAI, (YDAU - DAI + 1 * DAI + YDAU - DAI + 4 * DAI + 4 * DAI + 4 * DAI) / 2 - 10, somin);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
}

void Banco::vesocodacam(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI, YDAU - DAI + 1 * DAI + 8 * DAI, XDAU - DAI + 25 * DAI, YDAU - DAI + 4 * DAI + 8 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	Hcn_color(XDAU - DAI + 22 * DAI + 0.25 * DAI, YDAU - DAI + 1 * DAI + 8 * DAI + DAI, XDAU - DAI + 25 * DAI - 0.25 * DAI, YDAU - DAI + 4 * DAI + 8 * DAI - DAI, 255, 255, 255, 255, 255, 255).Vehinh(pdc);
	int soco = 0;
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].camco == 1 && ds[i][j].mo == 0)
			{
				soco++;
			}
		}
	}
	CString  Soco;
	LOGFONT lf;
	CFont newFont;
	Soco.Format(_T("FLAG:%d"), soco);
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + XDAU - DAI + 25 * DAI) / 2 - 10 - 0.5 * DAI, (YDAU - DAI + 1 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 10, Soco);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
}

void Banco::vesolantrogiup(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI, YDAU - DAI + 1 * DAI + 12 * DAI, XDAU - DAI + 25 * DAI, YDAU - DAI + 4 * DAI + 12 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	Hcn_color(XDAU - DAI + 22 * DAI + 0.25 * DAI, YDAU - DAI + 1 * DAI + 12 * DAI + DAI, XDAU - DAI + 25 * DAI - 0.25 * DAI, YDAU - DAI + 4 * DAI + 12 * DAI - DAI, 255, 255, 255, 255, 255, 255).Vehinh(pdc);
	CString  Solantrogiup;
	LOGFONT lf;
	CFont newFont;
	Solantrogiup.Format(_T("HELP:%d"), SOLANGIUP);
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + XDAU - DAI + 25 * DAI) / 2 - 10 - 0.5 * DAI, (YDAU - DAI + 1 * DAI + YDAU - DAI + 4 * DAI + 24 * DAI) / 2 - 10, Solantrogiup);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới

}

void Banco::vethoigian(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI, YDAU - DAI + 1 * DAI + 16 * DAI, XDAU - DAI + 25 * DAI, YDAU - DAI + 4 * DAI + 16 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	Hcn_color(XDAU - DAI + 22 * DAI + 0.25 * DAI, YDAU - DAI + 1 * DAI + 16 * DAI + DAI, XDAU - DAI + 25 * DAI - 0.25 * DAI, YDAU - DAI + 4 * DAI + 16 * DAI - DAI, 255, 255, 255, 255, 255, 255).Vehinh(pdc);
	CString  thoigian;
	LOGFONT lf;
	CFont newFont;
	if (THOIGIAN >= 0)
	{
		thoigian.Format(_T("TIME:%d%d:%d%d"), THOIGIAN / 60 / 10, THOIGIAN / 60 % 10, THOIGIAN % 60 / 10, THOIGIAN % 60 % 10);
	}
	else
	{
		thoigian.Format(_T(" TIME OUT"));
	}
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + XDAU - DAI + 25 * DAI) / 2 - 10 - 0.8 * DAI, (YDAU - DAI + 1 * DAI + YDAU - DAI + 4 * DAI + 32 * DAI) / 2 - 10, thoigian);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
}

void Banco::velever(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI+5*DAI+3*DAI, YDAU - DAI + 1 * DAI, XDAU - DAI + 25 * DAI + 5 * DAI + 3 * DAI, YDAU - DAI + 4 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	Hcn_color(XDAU - DAI + 22 * DAI + 0.25 * DAI + 5 * DAI + 3 * DAI, YDAU - DAI + 1 * DAI + DAI, XDAU - DAI + 25 * DAI - 0.25 * DAI + 5 * DAI + 3 * DAI, YDAU - DAI + 4 * DAI - DAI, 255, 255, 255, 255, 255, 255).Vehinh(pdc);

	CString  lever;
	LOGFONT lf;
	CFont newFont;
	lever.Format(_T("STATE: %d"), LEVEL);
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + XDAU - DAI + 25 * DAI + 5 * DAI + 5 * DAI) / 2 - 10 - 0.6 * DAI + 3 * DAI, (YDAU - DAI + 1 * DAI + YDAU - DAI + 4 * DAI) / 2 - 10, lever);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
}

void Banco::vebangmotacachchoi(CClientDC* pdc)
{
	Hcn_color(XDAU - DAI + 22 * DAI + 5 * DAI, YDAU - DAI + 1 * DAI + 4 * DAI, XDAU - DAI + 25 * DAI + 11 * DAI, YDAU - DAI + 4 * DAI + 16 * DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	CString moomin, datco, batdau1,batdau2, trogiup;
	LOGFONT lf;
	CFont newFont;
	moomin.Format(_T(" LEFT CLICK TO DISCLOSE THE GRID CELL"));
	datco.Format(_T("      RIGHT CLICK TO MARK BY A FLAG"));
	batdau1.Format(_T(" PRESS THE SPACE BAR TO START GAME"));
	batdau2.Format(_T("                 OR THE NEXT STATE"));
	trogiup.Format(_T("     PRESS THE S KEY FOR ASSISTANCE"));
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->SetBkColor(RGB(0, 102, 102));
	Co((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2 - 4 * DAI+2.5*DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 4 * DAI - 2 * DAI, 3).Vehinh(pdc);
	Min((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2 - 4 * DAI + 6.5 * DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 4 * DAI - 2 * DAI+12, 6).Vehinh(pdc);
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2-4*DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2-4*DAI, moomin);
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2 - 4 * DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 4 * DAI + DAI, datco);
	Hcn_color(XDAU - DAI + 22 * DAI + 5 * DAI + DAI, YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI, XDAU - DAI + 22 * DAI + 5 * DAI + DAI + 7 * DAI, YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI + DAI, 0, 0, 0, 0, 0, 0).Vehinh(pdc);
	pdc->SetTextColor(RGB(255, 255, 255));
	pdc->SetBkColor(RGB(0, 0, 0));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + DAI+ XDAU - DAI + 22 * DAI + 5 * DAI + DAI + 7 * DAI) / 2-0.75*DAI , (YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI+ YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI + DAI) / 2 -0.25*DAI, _T("SPACE"));
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->SetBkColor(RGB(0, 102, 102));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2 - 4 * DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 4 * DAI + 2 * DAI+2*DAI, batdau1);
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2 - 4 * DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 4 * DAI + 3 * DAI + 2 * DAI, batdau2);
	Hcn_color(XDAU - DAI + 22 * DAI + 5 * DAI + DAI+3*DAI, YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI+5*DAI-DAI, XDAU - DAI + 22 * DAI + 5 * DAI + DAI + 7 * DAI-3*DAI, YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI + DAI+5*DAI-DAI, 0, 0, 0, 0, 0, 0).Vehinh(pdc);
	pdc->SetTextColor(RGB(255, 255, 255));
	pdc->SetBkColor(RGB(0, 0, 0));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + DAI + XDAU - DAI + 22 * DAI + 5 * DAI + DAI + 7 * DAI) / 2 - 0.5 * DAI+0.35*DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI + YDAU - DAI + 1 * DAI + 4 * DAI + 5.5 * DAI + DAI) / 2 - 0.25 * DAI+5*DAI-DAI, _T("S"));
	pdc->SetTextColor(RGB(0, 25, 51));
	pdc->SetBkColor(RGB(0, 102, 102));
	pdc->TextOutW((XDAU - DAI + 22 * DAI + 5 * DAI + XDAU - DAI + 25 * DAI + 10 * DAI) / 2 - 4 * DAI, (YDAU - DAI + 1 * DAI + 4 * DAI + YDAU - DAI + 4 * DAI + 16 * DAI) / 2 - 4 * DAI + 4 * DAI + 2 * DAI+2*DAI-DAI+DAI, trogiup);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
	pdc->SetBkColor(RGB(255, 255, 255));
}

void Banco::vekhung(CClientDC* pdc)
{
	Hcn_color(XDAU + 4 * DAI, YDAU + 4 * DAI, XDAU + (COT - 1) * DAI - 3 * DAI, YDAU + (COT - 1) * DAI - 5 * DAI, 0, 51, 102, 0, 0, 0).Vehinh(pdc);
	Hcn_color(XDAU + 4.5 * DAI, YDAU + 4.5 * DAI, XDAU + (COT - 1) * DAI - 3.5 * DAI, YDAU + (COT - 1) * DAI - 5.5 * DAI, 0, 102, 102, 0, 0, 0).Vehinh(pdc);
	Hcn_color(XDAU + 4 * DAI + 2 * DAI, YDAU + 4 * DAI, XDAU + 4 * DAI + 10 * DAI, YDAU + 4 * DAI + DAI, 0, 102, 102, 0, 102, 102).Vehinh(pdc);
	circle_color(XDAU + 4.5 * DAI, YDAU + 4.5 * DAI, 0.5 * DAI, 0, 51, 102, 0, 51, 102).draw(pdc);
	circle_color(XDAU + 4.5 * DAI + 11 * DAI, YDAU + 4.5 * DAI, 0.5 * DAI, 0, 51, 102, 0, 51, 102).draw(pdc);
	circle_color(XDAU + 4.5 * DAI, YDAU + 4.5 * DAI + 9 * DAI, 0.5 * DAI, 0, 51, 102, 0, 51, 102).draw(pdc);
	circle_color(XDAU + 4.5 * DAI + 11 * DAI, YDAU + 4.5 * DAI + 9 * DAI, 0.5 * DAI, 0, 51, 102, 0, 51, 102).draw(pdc);
	circle_color(XDAU + 4.5 * DAI + 1.5 * DAI, YDAU + 4.5 * DAI - 0.25 * DAI, 0.25 * DAI, 0, 51, 102, 0, 51, 102).draw(pdc);
	circle_color(XDAU + 4.5 * DAI + 1.5 * DAI + 8 * DAI, YDAU + 4.5 * DAI - 0.25 * DAI, 0.25 * DAI, 0, 51, 102, 0, 51, 102).draw(pdc);
}

void Banco::vebanghuongdan(CClientDC* pdc)
{
	vekhung(pdc);
	CString min1, min2, co1, co2, co3, batdau, trogiup,start;
	LOGFONT lf;
	CFont newFont;
	min1 = _T("DISCLOSE ALL GRID CELLS");
	min2 = _T("   AND AVOID THE MINES");
	co1 = _T("   MARK WITH A FLAG ALL");
	co2 = _T("GRID CELL WHERE YOU THINK");
	co3 = _T("        THERE'S A MINE");
	start=_T("  SPACE TO START GAME");
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 30; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD;// Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(255, 255, 0));
	pdc->SetBkColor(RGB(0, 102, 102));
	pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 30 - 2 * DAI - 20+30, min1);
	pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 2 * DAI - 20+30, min2);
	pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 30 - 2 * DAI+30, co1);
	pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3.75 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 60 - 2 * DAI+30, co2);
	pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 90 - 2 * DAI+30, co3);
	pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 120 - 2 * DAI + 30+20, start);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
}
void Banco::vebangthongbaoketqua(CClientDC* pdc)
{
	vekhung(pdc);
	CString win, lose,nextlevel,core;
	LOGFONT lf;
	CFont newFont;
	win.Format(_T("  YOU WIN")); 
	lose.Format(_T("  YOU LOSE"));
	nextlevel.Format(_T("PRESS THE SPACE BAR TO THE NEXT STATE"));
	core.Format(_T("SCORES: %d"), tinhdiem());
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 60; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	if (thang == 1)
	{
		pdc->SetTextColor(RGB(102, 102, 0));
		pdc->SetBkColor(RGB(0, 102, 102));
		pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 60 - 2 * DAI-0.25*DAI, win);
		PlaySound(TEXT("Am-thanh-chien-thang-www_tiengdong_com.wav"), NULL, SND_FILENAME | SND_ASYNC);
		LEVEL++;
		khoidong = true;
		thang = 0;
		pdc->SelectObject(pOldFont); // Phục hồi font trước đó
		newFont.DeleteObject(); // Xóa font mới
		LOGFONT lf2;
		CFont newFont;
		::ZeroMemory(&lf2, sizeof(LOGFONT));
		lf2.lfHeight = 20; // Kích thước chữ in ra
		lf2.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
		lf2.lfItalic = TRUE;
		newFont.CreateFontIndirect(&lf2); // Tạo một font mới dựa trên LOGFONT
		CFont* pOldFont = pdc->SelectObject(&newFont);
		pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI-DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 60 - 2 * DAI - 0.25 * DAI+2*DAI,nextlevel);
		pdc->SelectObject(pOldFont); // Phục hồi font trước đó
		newFont.DeleteObject(); // Xóa font mới

	}
	else if (thang == -1)
	{
		pdc->SetTextColor(RGB(51, 0, 0));
		pdc->SetBkColor(RGB(0, 102, 102));
		pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 60 - 2 * DAI - 0.25 * DAI, lose);
		PlaySound(TEXT("Am-thanh-that-bai-www_tiengdong_com.wav"), NULL, SND_FILENAME | SND_ASYNC);
		pdc->SelectObject(pOldFont); // Phục hồi font trước đó
		newFont.DeleteObject(); // Xóa font mới
		LOGFONT lf2;
		CFont newFont;
		::ZeroMemory(&lf2, sizeof(LOGFONT));
		lf2.lfHeight = 30; // Kích thước chữ in ra
		lf2.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
		lf2.lfItalic = TRUE;
		newFont.CreateFontIndirect(&lf2); // Tạo một font mới dựa trên LOGFONT
		CFont* pOldFont = pdc->SelectObject(&newFont);
		pdc->TextOutW((XDAU + 4 * DAI + XDAU + (COT - 1) * DAI - 5 * DAI) / 2 - 3 * DAI - DAI+3.5*DAI, (YDAU + 4 * DAI + YDAU + (COT - 1) * DAI - 5 * DAI) / 2 + 60 - 2 * DAI - 0.25 * DAI + 2 * DAI, core);
		pdc->SelectObject(pOldFont); // Phục hồi font trước đó
		newFont.DeleteObject(); // Xóa font mới
		Sleep(5000);
		if (AfxMessageBox(_T("DO YOU WANT NEW GAME?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			resetbanco();
			Vehinh(pdc);
			PlaySound(TEXT("Braum-LeagueOfLegends-3767810.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
		}
		else
		{
			exit(0);
		}
	}

}
     
void Banco::ThongBaoKetQua(CClientDC* pdc)
{
	vediem(pdc);
	vesocodacam(pdc);
	vesolantrogiup(pdc);
	if (dk == 0)
	{
		vebangthongbaoketqua(pdc);
	}
}     

int Banco::ktthang()
{
	int i = 0, j = 0, dem = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].mo == 1)
			{
				dem++;
			}
		}
	}
	if (dem == COT * COT - SOLUONG && thang == 0)
	{
		thang = 1;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Banco::tenmang(CClientDC* pdc)
{
	Hcn_color(XDAU,YDAU,XDAU+20*DAI,YDAU+20*DAI, 160, 160, 160, 0, 102, 102).Vehinh(pdc);
	CString  level;
	LOGFONT lf;
	CFont newFont;
	level.Format(_T("STATE: %d"), LEVEL);
	::ZeroMemory(&lf, sizeof(LOGFONT));
	lf.lfHeight = 20; // Kích thước chữ in ra
	lf.lfWeight = FW_BOLD; // Độ dày của nét chữ (tùy chọn: FW_NORMAL, FW_BOLD, ...)
	lf.lfItalic = TRUE;
	newFont.CreateFontIndirect(&lf); // Tạo một font mới dựa trên LOGFONT
	CFont* pOldFont = pdc->SelectObject(&newFont); // C
	pdc->SetTextColor(RGB(255,255, 255));
	pdc->SetBkColor(RGB(160, 160, 160));
	pdc->TextOutW(XDAU +10*DAI, YDAU+10*DAI, level);
	pdc->SelectObject(pOldFont); // Phục hồi font trước đó
	newFont.DeleteObject(); // Xóa font mới
	pdc->SetTextColor(RGB(0,0, 0));
	pdc->SetBkColor(RGB(255, 255, 255));

}



void Banco::resetbanco()
{
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			ds[i][j].giatri = 0;
			ds[i][j].mo = 0;
			ds[i][j].camco = 0;
		}
	}
	LEVEL = 1;
	khoidong = true;
	thang = 0;
	dk = 0;
}

void Banco::Camcobanco(CClientDC* pdc, CPoint p)
{
	if (dk == 0)
	{
		return;
	}
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].Datco(pdc, p) == 1)
			{
				ds[i][j].Vehinh(pdc);
				PlaySound(TEXT("switch-click-and-beep-001a-11602.wav"), NULL, SND_FILENAME | SND_ASYNC);
				vesocodacam(pdc);
			}
		}
	}
}

void Banco::mo8oxungquanh(int mi, int mj, CClientDC* pdc)
{
	int inho, jnho, ilon, jlon;
	inho = mi - 1;
	jnho = mj - 1;
	ilon = mi + 1;
	jlon = mj + 1;
	if (inho < 0)
	{
		inho = 0;
	}
	if (jnho < 0)
	{
		jnho = 0;
	}
	if (ilon > COT - 1)
	{
		ilon = COT - 1;
	}
	if (jlon > COT - 1)
	{
		jlon = COT - 1;
	}
	ds[mi][mj].mo = 1;
	ds[mi][mj].Vehinh(pdc);
	for (int i = inho; i <= ilon; i++)
	{
		for (int j = jnho; j <= jlon; j++)
		{
			if (ds[i][j].mo == 0 && ds[i][j].giatri != 0)
			{
				ds[i][j].mo = 1;
				ds[i][j].Vehinh(pdc);
			}
		}
	}
	if (ds[ilon][mj].giatri == 0 && ds[ilon][mj].datungmoroi == 0)
	{
		ds[ilon][mj].datungmoroi = 1;
		mo8oxungquanh(ilon, mj, pdc);
	}
	if (ds[inho][mj].giatri == 0 && ds[inho][mj].datungmoroi == 0)
	{
		ds[inho][mj].datungmoroi = 1;
		mo8oxungquanh(inho, mj, pdc);
	}
	if (ds[mi][jlon].giatri == 0 && ds[mi][jlon].datungmoroi == 0)
	{
		ds[mi][jlon].datungmoroi = 1;
		mo8oxungquanh(mi, jlon, pdc);
	}
	if (ds[mi][jnho].giatri == 0 && ds[mi][jnho].datungmoroi == 0)
	{
		ds[mi][jnho].datungmoroi = 1;
		mo8oxungquanh(mi, jnho, pdc);
	}
}

void Banco::motatcaomin(CClientDC* pdc)
{
	PlaySound(TEXT("Tieng-min-no-www_tiengdong_com.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri == -1)
			{
				ds[i][j].mo = 1;
				ds[i][j].Vehinh(pdc);
			}
		}
	}
}

void Banco::dongtatcaomin(CClientDC* pdc)
{
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri == -1)
			{
				ds[i][j].mo = 0;
				ds[i][j].Vehinh(pdc);
			}
		}
	}
}

void Banco::trogiup(CClientDC* pdc)
{
	if (SOLANGIUP == 0)
	{
		return;
	}
	else
	{
		SOLANGIUP--;
		vesolantrogiup(pdc);
	}
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri == -1)
			{
				ds[i][j].mo = 1;
				ds[i][j].Vehinh(pdc);
			}
		}
	}
	Sleep(1000);
	for (int i = 0; i < COT; i++)
	{
		for (int j = 0; j < COT; j++)
		{
			if (ds[i][j].giatri == -1)
			{
				ds[i][j].mo = 0;
				ds[i][j].Vehinh(pdc);
			}
		}
	}
}

void Banco::Bambanco(CClientDC* pdc, CPoint p)
{
	if (dk == 0)
	{
		return;
	}
	int i = 0, j = 0;
	for (i = 0; i < COT; i++)
	{
		for (j = 0; j < COT; j++)
		{
			if (ds[i][j].Bamomin(pdc, p) == 1)
			{
				ds[i][j].Vehinh(pdc);
				if (ds[i][j].giatri == -1)//nguoi choi bam trung min
				{
					thang = -1;
					dk = 0;
					Sleep(1000);
					motatcaomin(pdc);
					Sleep(2000);
				}
				if (ds[i][j].giatri == 0)//mo cac o 0 lan can
				{
					mo8oxungquanh(i, j, pdc);
				}
				//kiem tra thang
				if (ktthang() == 1)
				{
					dk = 0;
				}
				ThongBaoKetQua(pdc);
			}
		}
	}
}
