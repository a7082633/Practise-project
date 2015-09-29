// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_UDP_SYNC2_CHAT.h"
#include "MySocket.h"
#include "MFC_UDP_SYNC2_CHATDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySocket

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CMySocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CMySocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CMySocket member functions

void CMySocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	CMFC_UDP_SYNC2_CHATDlg *pDlg=(CMFC_UDP_SYNC2_CHATDlg *)m_Param;
	pDlg->DoReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}
