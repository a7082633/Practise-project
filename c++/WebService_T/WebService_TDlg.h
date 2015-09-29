// WebService_TDlg.h : header file
//

#if !defined(AFX_WEBSERVICE_TDLG_H__715007A7_5EBC_409F_AAE2_DCBCC98A1809__INCLUDED_)
#define AFX_WEBSERVICE_TDLG_H__715007A7_5EBC_409F_AAE2_DCBCC98A1809__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWebService_TDlg dialog

class CWebService_TDlg : public CDialog
{
// Construction
public:
	CWebService_TDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWebService_TDlg)
	enum { IDD = IDD_WEBSERVICE_T_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebService_TDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWebService_TDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBSERVICE_TDLG_H__715007A7_5EBC_409F_AAE2_DCBCC98A1809__INCLUDED_)
