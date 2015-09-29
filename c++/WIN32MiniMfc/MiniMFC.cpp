#include <windows.h>
#include <stdio.h>
#define MESSAGE_DECLARE()
	static LRESULT OnChar(HWND, UINT, WPARAM, LPARAM);          \
	static LRESULT OnLButtonDown (HWND, UINT, WPARAM, LPARAM);  \
	static LRESULT OnPaint (HWND, UINT, WPARAM, LPARAM);        \
	static LRESULT OnDestroy (HWND, UINT, WPARAM, LPARAM);      \
	static LRESULT OnCreate (HWND, UINT, WPARAM, LPARAM);       \
	static LRESULT OnTime (HWND, UINT, WPARAM, LPARAM);         \

#define MESSAGE_MAP()                                 \
const CMyWnd::tagMESSAGEMAP CMyWnd::MessageMaps[] = { \
		    WM_CHAR,OnChar,                           \
			WM_LBUTTONDOWN,OnLButtonDown,             \
			WM_PAINT,OnPaint,                         \
			WM_DESTROY,OnDestroy,                     \
			WM_TIMER,OnTime,                          \
			WM_CREATE,OnCreate,                       \
	};                                                \


#include "MiniMFC.h"

CMyApp App;


LRESULT CMyWnd::OnTime(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rt;
	::GetClientRect(hWnd,&rt);
	::InvalidateRect(hWnd,&rt,true);
	return 0;
}
LRESULT CMyWnd::OnCreate(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	::SetTimer(hWnd,110,1000,NULL);
	return 0;
}
LRESULT CMyWnd::OnChar(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	char szChar[20];
	sprintf(szChar, "char is %c", (char)wParam);
	MessageBox(hWnd, szChar, "OnChar", 0);
	return 0;
}

//��Ϣ��Ӧ����: ����������
LRESULT CMyWnd::OnLButtonDown(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	TextOut(hdc, 0, 50, "��������������ѵ", strlen("��������������ѵ"));
	ReleaseDC(hWnd, hdc);
	return 0;
}

//��Ϣ��Ӧ�������ػ洰��
LRESULT CMyWnd::OnPaint(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	RECT rc;
	GetClientRect(hWnd, &rc);
	int iR = min(rc.right - rc.left, rc.bottom - rc.top) / 2;
	iR = iR * 4 / 5;
	POINT pt;
	pt.x = (rc.right + rc.left) / 2;
	pt.y = (rc.bottom + rc.top) / 2;

	HDC hdc;
	PAINTSTRUCT ps;
	hdc = BeginPaint(hWnd, &ps);

	::Ellipse(hdc, pt.x - iR, pt.y - iR, pt.x + iR, pt.y + iR);
	MoveToEx(hdc, pt.x, pt.y,(LPPOINT)NULL);
	LineTo(hdc, pt.x + iR, pt.y);

	char stime[] = "23:59:59";
	SYSTEMTIME tm;
	::GetLocalTime(&tm);
	sprintf(stime, "%.2d:%.2d:%.2d", tm.wHour, tm.wMinute, tm.wSecond);
	::TextOut(hdc, 10, 10,(LPCSTR)stime, strlen(stime));

	EndPaint(hWnd, &ps);
	return 0;
}

//��Ϣ��Ӧ����: ���ٴ���
LRESULT CMyWnd::OnDestroy(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	::KillTimer(hWnd,110);
	PostQuitMessage(0);
	return 0;
}

;
/////////////////////
//LRESULT CMyWnd::OnChar(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
//{
//	if(wParam == 27) ::PostQuitMessage(0);
//	char szChar[20];
//	sprintf(szChar, "�㰴����%c��", (char)wParam);
//	MessageBox(hWnd, szChar, "WM_CHAR", 0);	
//	return 0;
//}
//LRESULT CMyWnd::OnLButtonDown(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
//{
//	HDC hdc;
//	hdc = GetDC(hWnd);
//	TextOut(hdc, 0, 50, "��������������ѵ", strlen("��������������ѵ"));
//	ReleaseDC(hWnd, hdc);	
//	return 0;
//}
//LRESULT CMyWnd::OnPaint(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
//{
//	
//	PAINTSTRUCT ps;
//	RECT rt;
//	::GetClientRect(hWnd,&rt);
//	HDC	hdc = BeginPaint(hWnd, &ps);
//	SYSTEMTIME time;
//	::GetLocalTime(&time);
//	char sz[20];
//	sprintf(sz,"%d:%d:%d",time.wHour,time.wMinute,time.wSecond);
//	::DrawText(hdc,sz,strlen(sz),&rt,DT_CENTER);
//
//	EndPaint(hWnd, &ps);	
//	return 0;
//}
//LRESULT CMyWnd::OnDestroy(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
//{
//	::KillTimer(hWnd,110);
//	PostQuitMessage(0);	
//	return 0;
//}
//LRESULT CMyWnd::OnCreate(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
//{
//	::SetTimer(hWnd,110,1000,NULL);����ʱ�Ӻ� �ᷢ��WM_TIMER ��Ϣ��
//	
//	
//	return 0;
//}
//LRESULT CMyWnd::OnTimer(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
//{
//	::InvalidateRect(hWnd,NULL,true); --> WM_PAINT
//	return 0;
//}
