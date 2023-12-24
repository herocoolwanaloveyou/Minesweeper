
// DoMinView.cpp : implementation of the CDoMinView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DoMin.h"
#endif

#include "DoMinDoc.h"
#include "DoMinView.h"
#include <mmsystem.h> 
#include <Windows.h>
#pragma comment(lib,"winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDoMinView

IMPLEMENT_DYNCREATE(CDoMinView, CView)

BEGIN_MESSAGE_MAP(CDoMinView, CView)
	//ON_WM_CONTEXTMENU()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CDoMinView construction/destruction

CDoMinView::CDoMinView() noexcept
{
	// TODO: add construction code here

}

CDoMinView::~CDoMinView()
{
}

BOOL CDoMinView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDoMinView drawing

void CDoMinView::OnDraw(CDC* /*pDC*/)
{
	CDoMinDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	banco.Vehinh(&pdc);
}

/*void CDoMinView::OnContextMenu(CWnd*  pWnd , CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}*/


// CDoMinView diagnostics

#ifdef _DEBUG
void CDoMinView::AssertValid() const
{
	CView::AssertValid();
}

void CDoMinView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDoMinDoc* CDoMinView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDoMinDoc)));
	return (CDoMinDoc*)m_pDocument;
}
#endif //_DEBUG


// CDoMinView message handlers


void CDoMinView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	banco.Bambanco(&pdc, point);
	CView::OnLButtonUp(nFlags, point);
}


void CDoMinView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	banco.Camcobanco(&pdc, point);
	CView::OnRButtonUp(nFlags, point);
}
UINT Demthoigian(LPVOID pParam)
{
	CDoMinView* cview = (CDoMinView*)pParam;
	CClientDC pdc(cview);
	while (cview->banco.THOIGIAN >= -1)
	{
		if (cview->banco.dk == 0)
		{
			return 0;
		}
		cview->banco.vethoigian(&pdc);
		cview->banco.THOIGIAN--;
		Sleep(1000);
	}
	cview->banco.thang = -1;
	cview->banco.dk = 0;
	Sleep(1000);
	cview->banco.motatcaomin(&pdc);
	Sleep(2000);
	cview->banco.ThongBaoKetQua(&pdc);
	return 0;
}

void CDoMinView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC pdc(this);
	if (nChar == 83 && banco.dk == 1)
	{
		banco.trogiup(&pdc);
	}
	if (nChar == 32 && banco.dk == 0 && banco.khoidong == true)
	{
		for (int i = 0; i < COT; i++)
		{
			for (int j = 0; j < COT; j++)
			{
				banco.ds[i][j].mo = 0;
				banco.ds[i][j].datungmoroi = 0;
				banco.ds[i][j].camco = 0;
				banco.ds[i][j].giatri = 0;
			}
		}
		switch (banco.LEVEL)
		{
		case 1: banco.mucdode(); break;
		case 2: banco.mucdotrungbinh(); break;
		case 3: banco.mucdokho(); break;
		Sleep(5000);
		default: exit(0);
		}
		banco.khoitaomin();
		banco.khoidong = false;
		banco.dk = 1;
		//banco.Vehinh(&pdc);
		banco.tenmang(&pdc);
		Sleep(1000);
		banco.Vehinh(&pdc);
		AfxBeginThread(Demthoigian, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
		PlaySound(TEXT("LuluAndShacosQuirkyEncounter-LeagueOfLegends-3767821.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

