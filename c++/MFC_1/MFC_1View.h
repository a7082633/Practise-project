// MFC_1View.h : interface of the CMFC_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_1VIEW_H__384BCD1E_6198_4788_B9B5_790BDC02DD96__INCLUDED_)
#define AFX_MFC_1VIEW_H__384BCD1E_6198_4788_B9B5_790BDC02DD96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_1View : public CView
{
protected: // create from serialization only
	CMFC_1View();
	DECLARE_DYNCREATE(CMFC_1View)

// Attributes
public:
	CMFC_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_1View)
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
	virtual ~CMFC_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_1View)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_1View.cpp
inline CMFC_1Doc* CMFC_1View::GetDocument()
   { return (CMFC_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_1VIEW_H__384BCD1E_6198_4788_B9B5_790BDC02DD96__INCLUDED_)
