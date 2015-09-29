// MFC_MULTITHREADDlg.h : header file
//

#if !defined(AFX_MFC_MULTITHREADDLG_H__F5AE9B93_AAD3_4D9F_8B1C_E9AD5B59D5F9__INCLUDED_)
#define AFX_MFC_MULTITHREADDLG_H__F5AE9B93_AAD3_4D9F_8B1C_E9AD5B59D5F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_MULTITHREADDlg dialog

class CMFC_MULTITHREADDlg : public CDialog
{
// Construction
public:
	CMFC_MULTITHREADDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_MULTITHREADDlg)
	enum { IDD = IDD_MFC_MULTITHREAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MULTITHREADDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_MULTITHREADDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnCreate1();
	afx_msg void OnBtnSuspend1();
	afx_msg void OnBtnResum1();
	afx_msg void OnBtnExit();
	afx_msg void OnBtnCreate2();
	afx_msg void OnBtnSuspend2();
	afx_msg void OnBtnResum2();
	afx_msg void OnBtnExit2();
	afx_msg void OnBtnExitthread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MULTITHREADDLG_H__F5AE9B93_AAD3_4D9F_8B1C_E9AD5B59D5F9__INCLUDED_)
