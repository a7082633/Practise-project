#if !defined(AFX_MYSOCKET_H__AFA49594_C335_49A9_8692_81B81B7E15F8__INCLUDED_)
#define AFX_MYSOCKET_H__AFA49594_C335_49A9_8692_81B81B7E15F8__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySocket.h : header file
//
//#include "MFC_UDP_SYNC2_CHATDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CMySocket command target

class CMySocket : public CAsyncSocket
{
// Attributes
public:
	void * m_Param;
// Operations
public:
	CMySocket();
	virtual ~CMySocket();

// Overrides
public:
	//CMFC_UDP_SYNC2_CHATDlg m_Param;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMySocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOCKET_H__AFA49594_C335_49A9_8692_81B81B7E15F8__INCLUDED_)
