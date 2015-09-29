// MFCRandSeatView.h : interface of the CMFCRandSeatView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCRANDSEATVIEW_H__81C9E9E1_F38C_4B95_AF6F_2C68153C253B__INCLUDED_)
#define AFX_MFCRANDSEATVIEW_H__81C9E9E1_F38C_4B95_AF6F_2C68153C253B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCRandSeatView : public CView
{
protected: // create from serialization only
	CMFCRandSeatView();
	DECLARE_DYNCREATE(CMFCRandSeatView)

// Attributes
public:
	CMFCRandSeatDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCRandSeatView)
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
	CString GetExcelDriver();
	void ReatExcel();
	virtual ~CMFCRandSeatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCRandSeatView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCRandSeatView.cpp
inline CMFCRandSeatDoc* CMFCRandSeatView::GetDocument()
   { return (CMFCRandSeatDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCRANDSEATVIEW_H__81C9E9E1_F38C_4B95_AF6F_2C68153C253B__INCLUDED_)
