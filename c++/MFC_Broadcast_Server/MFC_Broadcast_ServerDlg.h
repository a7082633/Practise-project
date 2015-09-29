// MFC_Broadcast_ServerDlg.h : header file
//

#if !defined(AFX_MFC_BROADCAST_SERVERDLG_H__7ADD61CE_AEF4_4852_ACBA_8C277180B4B2__INCLUDED_)
#define AFX_MFC_BROADCAST_SERVERDLG_H__7ADD61CE_AEF4_4852_ACBA_8C277180B4B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ServerDlg dialog

class CMFC_Broadcast_ServerDlg : public CDialog
{
// Construction
public:
	void UpdateListNOH();
	void DoUserOLReply();
	void DoUserOffline();
	void DoUserOnline();
	void DoReceive();
	static DWORD WINAPI ReceiveThread(LPVOID p);
	BOOL IsThreadRuning;
	HANDLE m_hThread,m_hThreadRev;
	SOCKADDR_IN m_addrTo;
	BYTE m_bufSend[PACKSIZE];			//套接字发送数据缓冲区
	BYTE m_bufRecv[PACKSIZE];		//套接字接收数据缓冲区
	BYTE *m_pBufScreen;
	BYTE *m_pBufEncode1,*m_pBufEncode2;  //压缩1、2次的缓冲区
	CDC m_dcMemNow,m_dcMemOld;
	CDC *m_hDcScreen;
	BITMAPINFO m_biScreen;
	UINT m_Screenw;						//本机屏幕像素宽
	UINT m_Screenh;
	SOCKET m_hSocket;
	CBitmap m_bmpMemNow,m_bmpMemOld;
	CMenu m_LRMenu;                     //列表右键菜单
	CString sRClckIP,sRClckHost;
	void DoSend();
	static DWORD WINAPI SendThread(LPVOID p);
	CMFC_Broadcast_ServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_Broadcast_ServerDlg)
	enum { IDD = IDD_MFC_BROADCAST_SERVER_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_Broadcast_ServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_Broadcast_ServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtbStart();
	afx_msg void OnBtbStop();
	afx_msg void OnDestroy();
	afx_msg void OnBtnFlush();
	afx_msg void OnRclickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuSendmsg();
	afx_msg void OnMenuSeescreen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_BROADCAST_SERVERDLG_H__7ADD61CE_AEF4_4852_ACBA_8C277180B4B2__INCLUDED_)
