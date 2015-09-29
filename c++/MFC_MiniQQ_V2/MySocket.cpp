// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MiniQQ_V2.h"
#include "MySocket.h"
#include "MFC_MiniQQ_V2Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//HANDLE hMutex;
/////////////////////////////////////////////////////////////////////////////
// CMySocket

CMySocket::CMySocket()
{
//	hMutex = ::CreateMutex(NULL, FALSE, NULL);
//	::ReleaseMutex(hMutex);
}

CMySocket::~CMySocket()
{
//	::CloseHandle(hMutex);
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
	CMFC_MiniQQ_V2Dlg *pDlg=(CMFC_MiniQQ_V2Dlg *)m_Param;
	//::CreateThread(NULL,0,ReceiveThread,pDlg,0,NULL);
	pDlg->DoReceive();
	CAsyncSocket::OnReceive(nErrorCode);
}

DWORD WINAPI CMySocket::ReceiveThread(LPVOID p)
{
//	CMFC_MiniQQ_V2Dlg *pD=(CMFC_MiniQQ_V2Dlg *)p;
//	::WaitForSingleObject(hMutex, INFINITE);
//	pD->DoReceive();
//	::ReleaseMutex(hMutex);	
	return 0;
}
