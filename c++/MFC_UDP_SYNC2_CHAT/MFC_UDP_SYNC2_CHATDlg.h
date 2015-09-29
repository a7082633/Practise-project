// MFC_UDP_SYNC2_CHATDlg.h : header file
//

#if !defined(AFX_MFC_UDP_SYNC2_CHATDLG_H__F11D24A5_EE88_4B8C_9C11_6AB3D4D412B0__INCLUDED_)
#define AFX_MFC_UDP_SYNC2_CHATDLG_H__F11D24A5_EE88_4B8C_9C11_6AB3D4D412B0__INCLUDED_

#include "MySocket.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC2_CHATDlg dialog

class CMFC_UDP_SYNC2_CHATDlg : public CDialog
{
// Construction
public:
	void DoReceive();
	CMySocket m_hSocket;
	CMFC_UDP_SYNC2_CHATDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_UDP_SYNC2_CHATDlg)
	enum { IDD = IDD_MFC_UDP_SYNC2_CHAT_DIALOG };
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_UDP_SYNC2_CHATDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_UDP_SYNC2_CHATDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_UDP_SYNC2_CHATDLG_H__F11D24A5_EE88_4B8C_9C11_6AB3D4D412B0__INCLUDED_)
