// FgTeacherDlg.h : header file
//

#if !defined(AFX_FGTEACHERDLG_H__3C26DA92_1416_4A94_8384_ADE5CEB61296__INCLUDED_)
#define AFX_FGTEACHERDLG_H__3C26DA92_1416_4A94_8384_ADE5CEB61296__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFgTeacherDlg dialog

class CFgTeacherDlg : public CDialog
{
// Construction
public:
	CString GetBroadcastIP();

	void SendScreen();
	static DWORD WINAPI SendProc(LPVOID p);
	CFgTeacherDlg(CWnd* pParent = NULL);	// standard constructor

	SOCKET m_hSock;
    SOCKADDR_IN m_addrTo;
	HANDLE m_hThread;

	CDC *m_pDCScreen;
	CDC m_dcMemNow;
	CDC m_dcMemOld;

	CBitmap m_bmpMemNow;
	CBitmap m_bmpMemOld;

	BITMAPINFO m_biScreen;
	int w, h;
	int m_nImageSize;
	BYTE *m_pBufNow;
	BYTE *m_pBufEncode1;
	BYTE *m_pBufEncode2;
	BYTE m_bufSend[PACKSIZE];

	void TrayAdd();
	void TrayDelete();
	afx_msg LRESULT OnTrayNotify(WPARAM uID, LPARAM lEvent);

// Dialog Data
	//{{AFX_DATA(CFgTeacherDlg)
	enum { IDD = IDD_FGTEACHER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFgTeacherDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFgTeacherDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnDrayStart();
	afx_msg void OnDrayStop();
	afx_msg void OnDrayExit();
	afx_msg void OnNcPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrayAbout();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FGTEACHERDLG_H__3C26DA92_1416_4A94_8384_ADE5CEB61296__INCLUDED_)
