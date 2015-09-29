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
	pChat=new CChatDialog;
	pChat->parent=parent;
	pChat->Sname=Sname;
	pChat->Create(IDD_CHAT_DLG,CWnd::GetDesktopWindow());
	pChat->SetWindowText("你正在与["+Sname+"]聊天");
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

BOOL CMyWinThread::OnIdle(LONG lCount) 
{
	// TODO: Add your specialized code here and/or call the base class
	//::AfxMessageBox("test");
	return CWinThread::OnIdle(lCount);
}

void CMyWinThread::SetWindowFront()
{
	pChat->ShowWindow(SW_SHOWNOACTIVATE);
	pChat->SetForegroundWindow();
}
