#if !defined(AFX_DIALOGSENDMSG_H__9030F2F9_C22A_4DD6_B5C6_674A37DE672F__INCLUDED_)
#define AFX_DIALOGSENDMSG_H__9030F2F9_C22A_4DD6_B5C6_674A37DE672F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogSendMSG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogSendMSG dialog

class CDialogSendMSG : public CDialog
{
// Construction
public:
	SOCKET m_hSocket;
	CString m_sIP,m_sHost;
	CDialogSendMSG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogSendMSG)
	enum { IDD = IDD_DIALOG_SENGMSG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogSendMSG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogSendMSG)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSENDMSG_H__9030F2F9_C22A_4DD6_B5C6_674A37DE672F__INCLUDED_)
