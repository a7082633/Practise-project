// MyWinThread.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MINIQQ.h"
#include "MyWinThread.h"
#include "ChatDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWinThread

IMPLEMENT_DYNCREATE(CMyWinThread, CWinThread)

CMyWinThread::CMyWinThread()
{
}

CMyWinThread::~CMyWinThread()
{
}

BOOL CMyWinThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	CChatDialog *pChat=new CChatDialog;
	pChat->Create(IDD_CHAT_DLG,CWnd::GetDesktopWindow());
	//pChat->SetWindowText("aaaaaaa");
	pChat->ShowWindow(SW_SHOW);
	return TRUE;
}

int CMyWinThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyWinThread, CWinThread)
	//{{AFX_MSG_MAP(CMyWinThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWinThread message handlers
