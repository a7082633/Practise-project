// MFC_RUSSIAView.h : interface of the CMFC_RUSSIAView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_RUSSIAVIEW_H__B1922623_45F6_409E_8BD3_04EA96D7DD08__INCLUDED_)
#define AFX_MFC_RUSSIAVIEW_H__B1922623_45F6_409E_8BD3_04EA96D7DD08__INCLUDED_

#include "RussiaGame.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_RUSSIAView : public CView
{
protected: // create from serialization only
	CMFC_RUSSIAView();
	DECLARE_DYNCREATE(CMFC_RUSSIAView)

// Attributes
public:
	CMFC_RUSSIADoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_RUSSIAView)
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
	CImageList m_imageList;
	HICON icon;
	void TrayDelete();
	void ShowMyWindow();
	void HideWindow();
	void TrayAdd();
	void OnDrawMem(CDC *pDC);
	CRussiaGame Game;
	virtual ~CMFC_RUSSIAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_RUSSIAView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg LRESULT OnTrayNotify(WPARAM uID, LPARAM lEvent);
	afx_msg void OnGameAspeed();
	afx_msg void OnGameExit();
	afx_msg void OnGameNew();
	afx_msg void OnGamePause();
	afx_msg void OnGameRestart();
	afx_msg void OnGameResume();
	afx_msg void OnGameSspeed();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_RUSSIAView.cpp
inline CMFC_RUSSIADoc* CMFC_RUSSIAView::GetDocument()
   { return (CMFC_RUSSIADoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_RUSSIAVIEW_H__B1922623_45F6_409E_8BD3_04EA96D7DD08__INCLUDED_)
