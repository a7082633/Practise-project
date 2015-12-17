// MFC_GetFreeFromWebsiteDlg.h : header file
//

#if !defined(AFX_MFC_GETFREEFROMWEBSITEDLG_H__784FF6CE_49D2_4089_A101_7C2E523F5487__INCLUDED_)
#define AFX_MFC_GETFREEFROMWEBSITEDLG_H__784FF6CE_49D2_4089_A101_7C2E523F5487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_GetFreeFromWebsiteDlg dialog

class CMFC_GetFreeFromWebsiteDlg : public CDialog
{
// Construction
public:
	SOCKET m_sockServer;
	static bool isThreadRun;
	static DWORD WINAPI ScanThread(LPVOID lpParameter);
	CMFC_GetFreeFromWebsiteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_GetFreeFromWebsiteDlg)
	enum { IDD = IDD_MFC_GETFREEFROMWEBSITE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_GetFreeFromWebsiteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_GetFreeFromWebsiteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBtnScan();
	afx_msg void OnBtnStopscan();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HANDLE m_hThread;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_GETFREEFROMWEBSITEDLG_H__784FF6CE_49D2_4089_A101_7C2E523F5487__INCLUDED_)
