#if !defined(AFX_LOGINDLG_H__7B50084B_CA95_4AC9_BFE1_6D29D7D9EE11__INCLUDED_)
#define AFX_LOGINDLG_H__7B50084B_CA95_4AC9_BFE1_6D29D7D9EE11__INCLUDED_

#include "MyButton.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	CFont m_font;
	CBrush m_brush;
	BOOL isvalid;
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_DIALOG1 };
	CMyButton	m_b2;
	CMyButton	m_b1;
	CStatic	m_static_error;
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	afx_msg void OnBtnCancel();
	afx_msg void OnBtnOk();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnExchange();
	afx_msg void OnRadioRed();
	afx_msg void OnRadioGreen();
	afx_msg void OnRadioBlue();
	afx_msg void OnRadioOther();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMenuZi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__7B50084B_CA95_4AC9_BFE1_6D29D7D9EE11__INCLUDED_)
