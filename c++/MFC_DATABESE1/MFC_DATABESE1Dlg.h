// MFC_DATABESE1Dlg.h : header file
//

#if !defined(AFX_MFC_DATABESE1DLG_H__72FAB704_933A_4965_8033_D50306E38FE9__INCLUDED_)
#define AFX_MFC_DATABESE1DLG_H__72FAB704_933A_4965_8033_D50306E38FE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_DATABESE1Dlg dialog

class CMFC_DATABESE1Dlg : public CDialog
{
// Construction
public:
	CMFC_DATABESE1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_DATABESE1Dlg)
	enum { IDD = IDD_MFC_DATABESE1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DATABESE1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_DATABESE1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_DATABESE1DLG_H__72FAB704_933A_4965_8033_D50306E38FE9__INCLUDED_)
