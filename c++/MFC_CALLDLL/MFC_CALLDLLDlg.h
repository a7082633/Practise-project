// MFC_CALLDLLDlg.h : header file
//

#if !defined(AFX_MFC_CALLDLLDLG_H__56597897_7A4A_4FA3_9D22_DA4F3F9EB1D2__INCLUDED_)
#define AFX_MFC_CALLDLLDLG_H__56597897_7A4A_4FA3_9D22_DA4F3F9EB1D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_CALLDLLDlg dialog

class CMFC_CALLDLLDlg : public CDialog
{
// Construction
public:
	CMFC_CALLDLLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_CALLDLLDlg)
	enum { IDD = IDD_MFC_CALLDLL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CALLDLLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_CALLDLLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnMax();
	afx_msg void OnBtnMin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CALLDLLDLG_H__56597897_7A4A_4FA3_9D22_DA4F3F9EB1D2__INCLUDED_)
