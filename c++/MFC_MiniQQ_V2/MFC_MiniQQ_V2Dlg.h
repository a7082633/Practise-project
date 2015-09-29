// MFC_MiniQQ_V2Dlg.h : header file
//

#if !defined(AFX_MFC_MINIQQ_V2DLG_H__0C47B6F6_3603_4D05_AFE9_5195A5DF8F98__INCLUDED_)
#define AFX_MFC_MINIQQ_V2DLG_H__0C47B6F6_3603_4D05_AFE9_5195A5DF8F98__INCLUDED_

#include "MySocket.h"	// Added by ClassView
#include "ChatRoomDialog.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V2Dlg dialog

class CMFC_MiniQQ_V2Dlg : public CDialog
{
// Construction
public:
	SOCKET m_socketTCP;
	void DoRevReject(CString &addrFrom);
	CMenu m_TMenu;
	int h;
	int w;
	void DoOffLine(CString &addrFrom);
	void DoRevFile(CString &addrFrom);
	void DoRevFileMsg(CString &addrFrom);
	void DoRevRmMsg(CString &addrFrom,MESSAGEHEAD &msghead);
	void DoRevSgMsg(MESSAGEHEAD &msghead);
	void DoRevOnline(CString &addrFrom);
	void DoOnline(CString &addrFrom);
	BOOL m_isHide;
	CRect m_rect;
	CChatRoomDialog *m_pChatRoom;
	CPtrArray m_wndArray;
	void DoReceive();
	HICON icon;
	void TrayDelete();
	void TrayAdd();
	CMySocket m_hSocket;
	CImageList m_imageList;
	CMFC_MiniQQ_V2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_MiniQQ_V2Dlg)
	enum { IDD = IDD_MFC_MINIQQ_V2_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MiniQQ_V2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PostNcDestroy();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_MiniQQ_V2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnTrayNotify(WPARAM uID, LPARAM lEvent);
	afx_msg void OnClose();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnJoinchatrm();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnShowwd();
	afx_msg void OnExit();
	afx_msg void OnBtnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINIQQ_V2DLG_H__0C47B6F6_3603_4D05_AFE9_5195A5DF8F98__INCLUDED_)
