#if !defined(AFX_CHATDIALOG_H__0EB9A58B_909B_4A50_8D68_218404B46A4D__INCLUDED_)
#define AFX_CHATDIALOG_H__0EB9A58B_909B_4A50_8D68_218404B46A4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatDialog dialog

class CChatDialog : public CDialog
{
// Construction
public:
	CString ToFilePath;
	CString FilePath;
	CString m_sName;
	void *m_parent;
	CString m_sIP;
	CChatDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChatDialog)
	enum { IDD = IDD_DIALOG_CHAT };
	CProgressCtrl	m_progress2;
	CProgressCtrl	m_progress;
	CButton	m_btnaccept;
	CButton	m_btnsentf;
	CButton	m_btnreject;
	CButton	m_btnbrowser;
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatDialog)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChatDialog)
	afx_msg void OnBtnSend();
	afx_msg void OnClose();
	virtual void OnOK();
	afx_msg void OnBtnBrowser();
	afx_msg void OnBtnSendf();
	afx_msg void OnBtnAccept();
	afx_msg void OnBtnReject();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATDIALOG_H__0EB9A58B_909B_4A50_8D68_218404B46A4D__INCLUDED_)
