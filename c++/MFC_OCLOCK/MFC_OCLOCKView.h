// MFC_OCLOCKView.h : interface of the CMFC_OCLOCKView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFC_OCLOCKVIEW_H__73BE9673_3132_4901_A6F3_2F1D947E7895__INCLUDED_)
#define AFX_MFC_OCLOCKVIEW_H__73BE9673_3132_4901_A6F3_2F1D947E7895__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFC_OCLOCKView : public CView
{
protected: // create from serialization only
	CMFC_OCLOCKView();
	DECLARE_DYNCREATE(CMFC_OCLOCKView)

// Attributes
public:
	CMFC_OCLOCKDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_OCLOCKView)
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
	virtual ~CMFC_OCLOCKView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFC_OCLOCKView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFC_OCLOCKView.cpp
inline CMFC_OCLOCKDoc* CMFC_OCLOCKView::GetDocument()
   { return (CMFC_OCLOCKDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_OCLOCKVIEW_H__73BE9673_3132_4901_A6F3_2F1D947E7895__INCLUDED_)
