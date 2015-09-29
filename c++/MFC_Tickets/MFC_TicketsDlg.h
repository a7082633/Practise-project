// MFC_TicketsDlg.h : header file
//

#if !defined(AFX_MFC_TICKETSDLG_H__376FCC01_00C6_452E_88BF_A0412ECAAF0B__INCLUDED_)
#define AFX_MFC_TICKETSDLG_H__376FCC01_00C6_452E_88BF_A0412ECAAF0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_TicketsDlg dialog

class CMFC_TicketsDlg : public CDialog
{
// Construction
public:
	CMFC_TicketsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_TicketsDlg)
	enum { IDD = IDD_MFC_TICKETS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_TicketsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_TicketsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_TICKETSDLG_H__376FCC01_00C6_452E_88BF_A0412ECAAF0B__INCLUDED_)
