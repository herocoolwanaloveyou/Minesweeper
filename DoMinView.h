
// DoMinView.h : interface of the CDoMinView class
//

#pragma once
#include "Hcn.h"
#include "Omin.h"
#include "Banco.h"
class CDoMinView : public CView
{
protected: // create from serialization only
	CDoMinView() noexcept;
	DECLARE_DYNCREATE(CDoMinView)

// Attributes
public:
	CDoMinDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CDoMinView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	Banco banco;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in DoMinView.cpp
inline CDoMinDoc* CDoMinView::GetDocument() const
   { return reinterpret_cast<CDoMinDoc*>(m_pDocument); }
#endif

