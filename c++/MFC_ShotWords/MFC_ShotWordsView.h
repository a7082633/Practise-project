// MFC_ShotWordsView.h : interface of the CMFC_ShotWordsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_SHOTWORDSVIEW_H__7CA7BFF5_11EB_4458_93B6_19AA1F1E002E__INCLUDED_)
#define AFX_MFC_SHOTWORDSVIEW_H__7CA7BFF5_11EB_4458_93B6_19AA1F1E002E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_ShotWordsView : public CView
{
protected: // create from serialization only
	CMFC_ShotWordsView();
	DECLARE_DYNCREATE(CMFC_ShotWordsView)

// Attributes
public:
	CMFC_ShotWordsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ShotWordsView)
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
	virtual ~CMFC_ShotWordsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_ShotWordsView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_ShotWordsView.cpp
inline CMFC_ShotWordsDoc* CMFC_ShotWordsView::GetDocument()
   { return (CMFC_ShotWordsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SHOTWORDSVIEW_H__7CA7BFF5_11EB_4458_93B6_19AA1F1E002E__INCLUDED_)
