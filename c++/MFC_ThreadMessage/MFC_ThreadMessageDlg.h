// MFC_ThreadMessageDlg.h : header file
//

#if !defined(AFX_MFC_THREADMESSAGEDLG_H__A6BFA592_CA1C_4BD2_A2A4_A77EC971008A__INCLUDED_)
#define AFX_MFC_THREADMESSAGEDLG_H__A6BFA592_CA1C_4BD2_A2A4_A77EC971008A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_ThreadMessageDlg dialog

class CMFC_ThreadMessageDlg : public CDialog
{
// Construction
public:
	static DWORD WINAPI ThreadFun(LPVOID p);
	DWORD m_dwThreaId;
	HANDLE m_handle;
	CMFC_ThreadMessageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_ThreadMessageDlg)
	enum { IDD = IDD_MFC_THREADMESSAGE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ThreadMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_ThreadMessageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnCreate();
	afx_msg void OnBtnSend();
	afx_msg void OnBtnQuit();
	afx_msg void OnClock();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_THREADMESSAGEDLG_H__A6BFA592_CA1C_4BD2_A2A4_A77EC971008A__INCLUDED_)
