// MFCTestView.h : interface of the CMFCTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCTESTVIEW_H__2B769600_9BE6_4353_8F5B_2EE1A629C0E0__INCLUDED_)
#define AFX_MFCTESTVIEW_H__2B769600_9BE6_4353_8F5B_2EE1A629C0E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCTestView : public CView
{
protected: // create from serialization only
	CMFCTestView();
	DECLARE_DYNCREATE(CMFCTestView)

// Attributes
public:
	CMFCTestDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTestView)
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
	virtual ~CMFCTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCTestView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCTestView.cpp
inline CMFCTestDoc* CMFCTestView::GetDocument()
   { return (CMFCTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTESTVIEW_H__2B769600_9BE6_4353_8F5B_2EE1A629C0E0__INCLUDED_)
