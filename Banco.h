#pragma once
#include"Omin.h"
#include"Hcn.h"
#include<ctime>
#include "Hcn_color.h"
#include "background.h"
#pragma once
#include"Omin.h"
#include"Hcn.h"
#include<ctime>
#include "Hcn_color.h"
#include "background.h"
#include <mmsystem.h>
#include <Windows.h>
#include "circle_color.h"
#pragma comment(lib,"winmm.lib")
#define COT 20
#define DAI 40
#define XDAU 50
#define YDAU 50
class Banco
{
public:
	int SOLUONG = 0;
	int SOLANGIUP = 100;
	int THOIGIAN = 600;
	Omin ds[COT][COT];
	bool khoidong = true;
	int dk = 0;
	int thang = 0;
	background background;
	Banco();
	int LEVEL=1;
	void mucdode();
	void mucdokho();
	void mucdotrungbinh();
	void khoitaomin();
	void Vehinh(CClientDC* pdc);
	int tinhdiem();
	void vediem(CClientDC* pdc);
	void vesomin(CClientDC* pdc);
	void vesocodacam(CClientDC* pdc);
	void vesolantrogiup(CClientDC* pdc);
	void vethoigian(CClientDC* pdc);
	void velever(CClientDC* pdc);
	void vebangmotacachchoi(CClientDC* pdc);
	void vekhung(CClientDC* pdc);
	void vebanghuongdan(CClientDC* pdc);
	void vebangthongbaoketqua(CClientDC* pdc);
	void ThongBaoKetQua(CClientDC* pdc);
	void Bambanco(CClientDC* pdc, CPoint p);
	void Camcobanco(CClientDC* pdc, CPoint p);
	void mo8oxungquanh(int mi, int mj, CClientDC* pdc);
	void motatcaomin(CClientDC* pdc);
	void dongtatcaomin(CClientDC* pdc);
	void trogiup(CClientDC* pdc);
	int ktthang();
	void tenmang(CClientDC* pdc);
	void resetbanco();
};


