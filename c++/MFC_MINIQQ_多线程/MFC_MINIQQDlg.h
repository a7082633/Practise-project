// MFC_MINIQQDlg.h : header file
//

#if !defined(AFX_MFC_MINIQQDLG_H__B2586D9D_5766_4F6A_B8A3_BAACC5A7A703__INCLUDED_)
#define AFX_MFC_MINIQQDLG_H__B2586D9D_5766_4F6A_B8A3_BAACC5A7A703__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxcoll.h>
/////////////////////////////////////////////////////////////////////////////
// CMFC_MINIQQDlg dialog

class CMFC_MINIQQDlg : public CDialog
{
// Construction
public:
	CPtrArray m_ptrarr;
	CWinThread *m_ChatThread;
	CString m_sName;
	CImageList m_imageList;
	CMFC_MINIQQDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_MINIQQDlg)
	enum { IDD = IDD_MFC_MINIQQ_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MINIQQDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_MINIQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCloseThread(WPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINIQQDLG_H__B2586D9D_5766_4F6A_B8A3_BAACC5A7A703__INCLUDED_)
