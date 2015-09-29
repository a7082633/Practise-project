// MFC_SDIView.h : interface of the CMFC_SDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_SDIVIEW_H__5218941E_B550_4483_A5E1_3F2184E785DB__INCLUDED_)
#define AFX_MFC_SDIVIEW_H__5218941E_B550_4483_A5E1_3F2184E785DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_SDIView : public CView
{
protected: // create from serialization only
	CMFC_SDIView();
	DECLARE_DYNCREATE(CMFC_SDIView)

// Attributes
public:
	CMFC_SDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SDIView)
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
	void SavePicture(CString sSaveFileName);
	virtual ~CMFC_SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_SDIView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_SDIView.cpp
inline CMFC_SDIDoc* CMFC_SDIView::GetDocument()
   { return (CMFC_SDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SDIVIEW_H__5218941E_B550_4483_A5E1_3F2184E785DB__INCLUDED_)
