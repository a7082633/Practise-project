#if !defined(AFX_CHATROOMDIALOG_H__E22EB38D_D055_4C22_94F0_75B3E25CD2DF__INCLUDED_)
#define AFX_CHATROOMDIALOG_H__E22EB38D_D055_4C22_94F0_75B3E25CD2DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatRoomDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChatRoomDialog dialog

class CChatRoomDialog : public CDialog
{
// Construction
public:
	void *m_parent;
	CChatRoomDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChatRoomDialog)
	enum { IDD = IDD_DIALOG_CHARROOM };
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChatRoomDialog)
	afx_msg void OnClose();
	afx_msg void OnBtnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMDIALOG_H__E22EB38D_D055_4C22_94F0_75B3E25CD2DF__INCLUDED_)
