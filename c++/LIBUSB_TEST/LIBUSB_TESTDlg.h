// LIBUSB_TESTDlg.h : header file
//

#if !defined(AFX_LIBUSB_TESTDLG_H__B00EFABA_638A_4C38_8D17_DAB599873862__INCLUDED_)
#define AFX_LIBUSB_TESTDLG_H__B00EFABA_638A_4C38_8D17_DAB599873862__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLIBUSB_TESTDlg dialog

class CLIBUSB_TESTDlg : public CDialog
{
// Construction
public:
	CLIBUSB_TESTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLIBUSB_TESTDlg)
	enum { IDD = IDD_LIBUSB_TEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLIBUSB_TESTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLIBUSB_TESTDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBUSB_TESTDLG_H__B00EFABA_638A_4C38_8D17_DAB599873862__INCLUDED_)
