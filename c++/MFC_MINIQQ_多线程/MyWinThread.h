#if !defined(AFX_MYWINTHREAD_H__F0EDDCDB_97D2_4D4F_BE79_AEAB9E7B0EE4__INCLUDED_)
#define AFX_MYWINTHREAD_H__F0EDDCDB_97D2_4D4F_BE79_AEAB9E7B0EE4__INCLUDED_

#include "ChatDialog.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyWinThread.h : header file
//

#include "MFC_MINIQQDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CMyWinThread thread

class CMyWinThread : public CWinThread
{
	DECLARE_DYNCREATE(CMyWinThread)
protected:
	CMyWinThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	void SetWindowFront();
	CMFC_MINIQQDlg *parent;
	CChatDialog *pChat;
	CString Sname;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWinThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyWinThread();

	// Generated message map functions
	//{{AFX_MSG(CMyWinThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWINTHREAD_H__F0EDDCDB_97D2_4D4F_BE79_AEAB9E7B0EE4__INCLUDED_)
