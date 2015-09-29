// MFC_MiniCadView.h : interface of the CMFC_MiniCadView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_MINICADVIEW_H__8FE93EAB_45B0_4B44_BDD4_90C837FE630D__INCLUDED_)
#define AFX_MFC_MINICADVIEW_H__8FE93EAB_45B0_4B44_BDD4_90C837FE630D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_MiniCadView : public CView
{
protected: // create from serialization only
	CMFC_MiniCadView();
	DECLARE_DYNCREATE(CMFC_MiniCadView)

// Attributes
public:
	CMFC_MiniCadDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MiniCadView)
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
	COLORREF m_color;
	int m_penw;
	UINT m_nType;
	CPoint m_pEnd;
	CPoint m_pBegin;
	virtual ~CMFC_MiniCadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_MiniCadView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDrawNone();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawEill();
	afx_msg void OnDrawRect();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnUpdateDrawNone(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawEill(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawColor(CCmdUI* pCmdUI);
	afx_msg void OnDrawColor();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBtnL1();
	afx_msg void OnBtnL2();
	afx_msg void OnBtnL3();
	afx_msg void OnUpdateBtnL1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBtnL2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBtnL3(CCmdUI* pCmdUI);
	afx_msg void OnBtnColor();
	afx_msg void OnUpdateBtnColor(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_MiniCadView.cpp
inline CMFC_MiniCadDoc* CMFC_MiniCadView::GetDocument()
   { return (CMFC_MiniCadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINICADVIEW_H__8FE93EAB_45B0_4B44_BDD4_90C837FE630D__INCLUDED_)
