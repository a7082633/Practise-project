#include <Windows.h>
#include <stdio.h>
#include <vector>
using namespace std;
HWND ChWndList;
HWND PhWndList;
HINSTANCE ghInstance;
void CreateChilWin();
LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SIZE:
		{
			RECT rt;
			::GetClientRect(hWnd,&rt);
			int wx=rt.right-rt.left;
			int wy=rt.bottom-rt.top;
			::SetWindowPos(ChWndList,NULL,0,0,wx,wy,SWP_SHOWWINDOW);
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			int a=strcmp("b","°¡");
			char sz[10];
			sprintf(sz,"%d",a);
			HDC hdc=::BeginPaint(hWnd,&ps);
			::TextOut(hdc,0,0,sz,strlen(sz));
			::EndPaint(hWnd,&ps);
		}
		break;
	case WM_CHAR:
		{
			HDC hdc=::GetDC(hWnd);
			char sz[10];
			sprintf(sz,"%c",wParam);
			::TextOut(hdc,0,0,sz,strlen(sz));
			::ReleaseDC(hWnd,hdc);
		}
		break;
	case WM_RBUTTONDOWN:
		CreateChilWin();
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		::PostQuitMessage(0);
		break;
	default:
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WinProcChild(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		::SetTimer(hWnd,110,1000,NULL);
		break;
	case WM_TIMER:
		::InvalidateRect(hWnd,NULL,TRUE);
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			char *str="²»";
			int a=strcmp("°©","²»");
			char sz[10];
			sprintf(sz,"%d",a);
			HDC hdc=::BeginPaint(hWnd,&ps);
			::TextOut(hdc,0,0,sz,strlen(sz));
			::EndPaint(hWnd,&ps);
		}
		break;
	case WM_KEYUP:
		{
			HDC hdc=::GetDC(hWnd);
			char sz[10];
			sprintf(sz,"%c",wParam);
			::TextOut(hdc,0,0,sz,strlen(sz));
			::ReleaseDC(hWnd,hdc);
		}
		break;
	case WM_RBUTTONDOWN:
		{
			HDC hdc=::GetDC(hWnd);
			char sz[20];
			int x=LOWORD(lParam);
			int y=HIWORD(lParam);
			sprintf(sz,"%d,%d",x,y);
			::TextOut(hdc,x,y,sz,strlen(sz));
			::ReleaseDC(hWnd,hdc);
		}
		break;
	case WM_CLOSE:
		::KillTimer(hWnd,110);
		DestroyWindow(hWnd);
		ChWndList=NULL;
		break;
	default:
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
void CreateChilWin()
{
	MSG msg = {0};
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = ::CreateSolidBrush(0xffffff);
	wc.hCursor = ::LoadCursor(NULL,IDC_ARROW);
	wc.hIcon = ::LoadIcon(NULL,IDI_INFORMATION);
	wc.hInstance = ghInstance;
	wc.lpfnWndProc = WinProcChild;
	wc.lpszClassName = "lawa2";
	wc.lpszMenuName = NULL;
	wc.style = CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW;
	ATOM aTom = ::RegisterClass(&wc);

	//if(!aTom) return NULL;
	HWND ChWnd=CreateWindow(wc.lpszClassName, NULL ,WS_CHILD, 0 , 0 , 150 , 150 , PhWndList , NULL , ghInstance , NULL);
	ChWndList=ChWnd;
	//if(!hWnd) return NULL;
	::ShowWindow(ChWnd,SW_MAXIMIZE);
	::UpdateWindow(ChWnd);
}

void CreateParenWin()
{
	MSG msg = {0};
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground =::CreateSolidBrush(0x0);
	wc.hCursor = ::LoadCursor(NULL,IDC_ARROW);
	wc.hIcon = ::LoadIcon(NULL,IDI_INFORMATION);
	wc.hInstance = ghInstance;
	wc.lpfnWndProc = WinProc;
	wc.lpszClassName = "lawa";
	wc.lpszMenuName = "lawa";
	wc.style = CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW;
	ATOM aTom = ::RegisterClass(&wc);
	HWND ChWnd=CreateWindow(wc.lpszClassName, "lawa" ,WS_OVERLAPPEDWINDOW, 0 , 0 , 300 , 300 , NULL , NULL , ghInstance , NULL);
	PhWndList=ChWnd;
	::ShowWindow(PhWndList,SW_SHOW);
	::UpdateWindow(PhWndList);
}
int WINAPI WinMain(  HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow )
{

	MSG msg = {0};
	ghInstance=hInstance;
	CreateParenWin();
	CreateChilWin();
	while(::GetMessage(&msg,NULL,0,0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	return 0;
}
