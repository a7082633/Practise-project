#if !defined(AFX_CHATDIALOG_H__91EE0943_D413_44EB_BDD5_5802FD34A75C__INCLUDED_)
#define AFX_CHATDIALOG_H__91EE0943_D413_44EB_BDD5_5802FD34A75C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatDialog.h : header file
//
#include "MFC_MINIQQDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CChatDialog dialog

class CChatDialog : public CDialog
{
// Construction
public:
	CString Sname;
	CMFC_MINIQQDlg *parent;
	CString m_sName;
	CChatDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDialog)
	enum { IDD = IDD_CHAT_DLG };
	CString	m_Old;
	CString	m_New;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChatDialog)
	afx_msg void OnBtnSend();
	afx_msg void OnClose();
	afx_msg void OnClosew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDIALOG_H__91EE0943_D413_44EB_BDD5_5802FD34A75C__INCLUDED_)
