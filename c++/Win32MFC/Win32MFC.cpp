#include "Win32MFC.h"

CMyApp theApp;

BEGIN_MESSAGE_MAP(CMyWnd,CFrameWnd)		//消息映射开始
ON_WM_PAINT()
ON_WM_CREATE()							//WM_PAINT消息映射宏
ON_WM_DESTROY()
ON_WM_TIMER()
END_MESSAGE_MAP()						//结束消息映射

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMyWnd;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMyWnd::CMyWnd()
{
	Create(NULL, "Win32 MFC Application");
}

//手工定义消息响应函数OnPaint()，并添加函数处理代码
void CMyWnd::OnPaint()
{
	CPaintDC dc(this);
	SYSTEMTIME tm;
	::GetLocalTime(&tm);
	char sz[20];
	sprintf(sz,"%.2d:%.2d:%.2d",tm.wHour,tm.wMinute,tm.wSecond);
	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(sz,strlen(sz),&rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

void CMyWnd::OnCreate()
{
	this->SetTimer(110,1000,NULL);
}

void CMyWnd::OnDestroy()
{
	this->KillTimer(110);
}

void CMyWnd::OnTimer()
{
	CRect rect;
	GetClientRect(&rect);
	this->InvalidateRect(&rect);
}