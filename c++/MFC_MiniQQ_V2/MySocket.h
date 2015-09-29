#if !defined(AFX_MYSOCKET_H__DC75DD5A_25F5_4385_9B72_DF78CA4E4C41__INCLUDED_)
#define AFX_MYSOCKET_H__DC75DD5A_25F5_4385_9B72_DF78CA4E4C41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CMySocket command target

class CMySocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CMySocket();
	virtual ~CMySocket();

// Overrides
public:
	static DWORD WINAPI ReceiveThread(LPVOID p);
	void * m_Param;
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

#endif // !defined(AFX_MYSOCKET_H__DC75DD5A_25F5_4385_9B72_DF78CA4E4C41__INCLUDED_)
