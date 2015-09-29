// MFC_UDP_SYNC_CHATDlg.h : header file
//

#if !defined(AFX_MFC_UDP_SYNC_CHATDLG_H__33F50C73_B16E_4159_8304_F581B2AF5704__INCLUDED_)
#define AFX_MFC_UDP_SYNC_CHATDLG_H__33F50C73_B16E_4159_8304_F581B2AF5704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC_CHATDlg dialog

class CMFC_UDP_SYNC_CHATDlg : public CDialog
{
// Construction
public:
	SOCKET m_hSock;
	CMFC_UDP_SYNC_CHATDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_UDP_SYNC_CHATDlg)
	enum { IDD = IDD_MFC_UDP_SYNC_CHAT_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_UDP_SYNC_CHATDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_UDP_SYNC_CHATDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSend();
	afx_msg void OnSock(WPARAM w,LPARAM l);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_UDP_SYNC_CHATDLG_H__33F50C73_B16E_4159_8304_F581B2AF5704__INCLUDED_)
