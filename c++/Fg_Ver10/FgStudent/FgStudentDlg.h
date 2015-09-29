// FgStudentDlg.h : header file
//

#if !defined(AFX_FGSTUDENTDLG_H__916F08EF_6D1C_4FBD_8818_B60A6F71A8D7__INCLUDED_)
#define AFX_FGSTUDENTDLG_H__916F08EF_6D1C_4FBD_8818_B60A6F71A8D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFgStudentDlg dialog

class CFgStudentDlg : public CDialog
{
// Construction
public:
	void DoRecvFramePart();
	void DoStopBroadcast();
	void DoStartBroadcast();
	void RecvScreen();
	void MallocMem();
	static DWORD WINAPI RecvProc(LPVOID p);

	SOCKET m_hSock;
	HANDLE m_hThread;
	BYTE m_bufRecv[PACKSIZE];
	DWORD m_nReceivedSum;

	BYTE *m_pBufEncode;
	UINT m_nFrame;
	WORD m_nPartCnt;
	WORD m_nPartID;

	BYTE *m_pBufMemNow1;
	BYTE *m_pBufMemNow2;
	BYTE *m_pBufMemOld;

	CDC *m_pDC;
	BITMAPINFO m_biScreen;
	int w, h;
	int m_nImageSize;
	CDC m_dcMemNow;
	CDC m_dcMemOld;
	CBitmap m_bmpMemNow;
	CBitmap m_bmpMemOld;

	BOOL m_bIsRunning;

	CFgStudentDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFgStudentDlg)
	enum { IDD = IDD_FGSTUDENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFgStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFgStudentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnNcPaint();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	BOOL IsWindowMaximize(void);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FGSTUDENTDLG_H__916F08EF_6D1C_4FBD_8818_B60A6F71A8D7__INCLUDED_)
