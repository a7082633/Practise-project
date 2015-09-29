// KeyHookDlg.h : header file
//

#if !defined(AFX_KEYHOOKDLG_H__8ABD0270_CDBF_477A_80ED_36CA6B897E02__INCLUDED_)
#define AFX_KEYHOOKDLG_H__8ABD0270_CDBF_477A_80ED_36CA6B897E02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CKeyHookDlg dialogzzzzzzzzz

class CKeyHookDlg : public CDialog
{
// Construction
private:
	CKeyboardHook m_hook;//加入钩子类作为数据成员
public:
	CKeyHookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CKeyHookDlg)
	enum { IDD = IDD_KEYHOOK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyHookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKeyHookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHook();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYHOOKDLG_H__8ABD0270_CDBF_477A_80ED_36CA6B897E02__INCLUDED_)
