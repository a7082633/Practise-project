// MFC_SnakeView.h : interface of the CMFC_SnakeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_SNAKEVIEW_H__24E7BD56_544B_40FF_9206_B021B332E21D__INCLUDED_)
#define AFX_MFC_SNAKEVIEW_H__24E7BD56_544B_40FF_9206_B021B332E21D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_SnakeView : public CView
{
protected: // create from serialization only
	CMFC_SnakeView();
	DECLARE_DYNCREATE(CMFC_SnakeView)

// Attributes
public:
	CMFC_SnakeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SnakeView)
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
	virtual ~CMFC_SnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_SnakeView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_SnakeView.cpp
inline CMFC_SnakeDoc* CMFC_SnakeView::GetDocument()
   { return (CMFC_SnakeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SNAKEVIEW_H__24E7BD56_544B_40FF_9206_B021B332E21D__INCLUDED_)
