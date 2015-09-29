// MFC_FILESDlg.h : header file
//

#if !defined(AFX_MFC_FILESDLG_H__19772717_E9BF_44C6_BAB2_730BEE41E6B6__INCLUDED_)
#define AFX_MFC_FILESDLG_H__19772717_E9BF_44C6_BAB2_730BEE41E6B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILESDlg dialog

class CMFC_FILESDlg : public CDialog
{
// Construction
public:
	SOCKET m_hSocket;
	CMFC_FILESDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_FILESDlg)
	enum { IDD = IDD_MFC_FILES_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_FILESDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_FILESDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_FILESDLG_H__19772717_E9BF_44C6_BAB2_730BEE41E6B6__INCLUDED_)
