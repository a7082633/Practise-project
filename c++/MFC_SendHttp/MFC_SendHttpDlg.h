// MFC_SendHttpDlg.h : header file
//

#if !defined(AFX_MFC_SENDHTTPDLG_H__B34F9DEC_6D0D_4F06_954C_EB01BF097522__INCLUDED_)
#define AFX_MFC_SENDHTTPDLG_H__B34F9DEC_6D0D_4F06_954C_EB01BF097522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_SendHttpDlg dialog

class CMFC_SendHttpDlg : public CDialog
{
// Construction
public:
	CMFC_SendHttpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_SendHttpDlg)
	enum { IDD = IDD_MFC_SENDHTTP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SendHttpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_SendHttpDlg)
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

#endif // !defined(AFX_MFC_SENDHTTPDLG_H__B34F9DEC_6D0D_4F06_954C_EB01BF097522__INCLUDED_)
