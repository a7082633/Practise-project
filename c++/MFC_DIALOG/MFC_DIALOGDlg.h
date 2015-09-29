// MFC_DIALOGDlg.h : header file
//

#if !defined(AFX_MFC_DIALOGDLG_H__021130E7_EB9F_4B07_813A_CE2E1308F476__INCLUDED_)
#define AFX_MFC_DIALOGDLG_H__021130E7_EB9F_4B07_813A_CE2E1308F476__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_DIALOGDlg dialog

class CMFC_DIALOGDlg : public CDialog
{
// Construction
public:
	CMFC_DIALOGDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_DIALOGDlg)
	enum { IDD = IDD_MFC_DIALOG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DIALOGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_DIALOGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_DIALOGDLG_H__021130E7_EB9F_4B07_813A_CE2E1308F476__INCLUDED_)
