// MFC_WUZIView.h : interface of the CMFC_WUZIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_WUZIVIEW_H__9399DF74_EB78_4CFC_97C4_293CEC3A3641__INCLUDED_)
#define AFX_MFC_WUZIVIEW_H__9399DF74_EB78_4CFC_97C4_293CEC3A3641__INCLUDED_

#include "Wuzi.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_WUZIView : public CView
{
protected: // create from serialization only
	CMFC_WUZIView();
	DECLARE_DYNCREATE(CMFC_WUZIView)

// Attributes
public:
	CMFC_WUZIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_WUZIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnDrawMem(CDC *pDC);
	void ClearChess();
	int Check(int x,int y);
	CWuzi wuzi;
	virtual ~CMFC_WUZIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_WUZIView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_WUZIView.cpp
inline CMFC_WUZIDoc* CMFC_WUZIView::GetDocument()
   { return (CMFC_WUZIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_WUZIVIEW_H__9399DF74_EB78_4CFC_97C4_293CEC3A3641__INCLUDED_)
