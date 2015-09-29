// MFC_MULTI_THREAD_BARDlg.h : header file
//

#if !defined(AFX_MFC_MULTI_THREAD_BARDLG_H__CD720462_35C0_4F32_85F5_08C4744DAB1E__INCLUDED_)
#define AFX_MFC_MULTI_THREAD_BARDLG_H__CD720462_35C0_4F32_85F5_08C4744DAB1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_MULTI_THREAD_BARDlg dialog

class CMFC_MULTI_THREAD_BARDlg : public CDialog
{
// Construction
public:
	CMFC_MULTI_THREAD_BARDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_MULTI_THREAD_BARDlg)
	enum { IDD = IDD_MFC_MULTI_THREAD_BAR_DIALOG };
	CProgressCtrl	m_progress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MULTI_THREAD_BARDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_MULTI_THREAD_BARDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	afx_msg void OnBtnSelectfile();
	afx_msg void OnBtnSelectpath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MULTI_THREAD_BARDLG_H__CD720462_35C0_4F32_85F5_08C4744DAB1E__INCLUDED_)
