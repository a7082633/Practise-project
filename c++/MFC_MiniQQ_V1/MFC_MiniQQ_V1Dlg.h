// MFC_MiniQQ_V1Dlg.h : header file
//

#if !defined(AFX_MFC_MINIQQ_V1DLG_H__9CFFA0AB_F357_45FA_8ACE_3A0FCD162A1A__INCLUDED_)
#define AFX_MFC_MINIQQ_V1DLG_H__9CFFA0AB_F357_45FA_8ACE_3A0FCD162A1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V1Dlg dialog

class CMFC_MiniQQ_V1Dlg : public CDialog
{
// Construction
public:
	CMFC_MiniQQ_V1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_MiniQQ_V1Dlg)
	enum { IDD = IDD_MFC_MINIQQ_V1_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MiniQQ_V1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_MiniQQ_V1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnLogin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINIQQ_V1DLG_H__9CFFA0AB_F357_45FA_8ACE_3A0FCD162A1A__INCLUDED_)
