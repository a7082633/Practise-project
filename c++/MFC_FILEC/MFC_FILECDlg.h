// MFC_FILECDlg.h : header file
//

#if !defined(AFX_MFC_FILECDLG_H__49159391_7EAD_4B6E_80E3_5E5E25CDA76C__INCLUDED_)
#define AFX_MFC_FILECDLG_H__49159391_7EAD_4B6E_80E3_5E5E25CDA76C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILECDlg dialog

class CMFC_FILECDlg : public CDialog
{
// Construction
public:
	SOCKET m_hSocketC;
	CMFC_FILECDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_FILECDlg)
	enum { IDD = IDD_MFC_FILEC_DIALOG };
	CProgressCtrl	m_progress;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_FILECDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_FILECDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_FILECDLG_H__49159391_7EAD_4B6E_80E3_5E5E25CDA76C__INCLUDED_)
