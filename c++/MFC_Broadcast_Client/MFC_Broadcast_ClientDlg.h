// MFC_Broadcast_ClientDlg.h : header file
//

#if !defined(AFX_MFC_BROADCAST_CLIENTDLG_H__07F0EBD0_9E94_4290_9645_1203DBE4B7E1__INCLUDED_)
#define AFX_MFC_BROADCAST_CLIENTDLG_H__07F0EBD0_9E94_4290_9645_1203DBE4B7E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ClientDlg dialog

class CMFC_Broadcast_ClientDlg : public CDialog
{
// Construction
public:
	void DoReVMSG();
	void DoReplyOL();
	void TrayDelete();
	void TrayAdd();
	void DoStopBroadCast();
	void DoStartRevBroad();
	void DoReceivBroadCast();
	CDC *m_pDC;
	int m_nImageSize;
	int h;
	int w;
	BYTE *m_pBufMemNow1;
	BYTE *m_pBufMemNow2;
	BYTE *m_pBufMemOld;
	DWORD m_nReceivedSum;
	UINT m_nFrame;
	WORD m_nPartCnt;
	WORD m_nPartID;
	BOOL IsInitialAll;
	BYTE m_bufRecv[PACKSIZE];
	CDC m_dcMemNow,m_dcMemOld;
	CBitmap m_bmpMemNow,m_bmpMemOld;
	BYTE *m_pBufScreen;
	BITMAPINFO m_biScreen;
	SOCKET m_hSocketC;
	BYTE *m_pBufEncode;	//接收到的压缩数据Xor
	HICON m_TrayhIcon;
	CMenu m_TMenu;      //托盘菜单
	static DWORD WINAPI ReceiveThread(LPVOID p);
	void InitialAll();
	void DoReceive();
	CMFC_Broadcast_ClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_Broadcast_ClientDlg)
	enum { IDD = IDD_MFC_BROADCAST_CLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_Broadcast_ClientDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_Broadcast_ClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAcceptb();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMenuExit();
	afx_msg LRESULT OnTrayNotify(WPARAM uID, LPARAM lEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_BROADCAST_CLIENTDLG_H__07F0EBD0_9E94_4290_9645_1203DBE4B7E1__INCLUDED_)
