#include <windows.h>
#include <stdio.h>
#include <math.h>
#pragma warning (disable:4244)
#define PI 3.1415926535
BOOL isMenuCom=false;
BOOL isFixTime=false;
SYSTEMTIME tm;
#define RAND() (srand((unsigned int)GetCpuCycle()), rand())
#define dim(x) (sizeof(x) / sizeof(x[0]))

//获得CPU自上电以来的时间周期数
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}
int Color=190;
//声明窗口回调函数
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

//程序入口
int WINAPI WinMain(
	HINSTANCE hInstance,		// 当前实例句柄
	HINSTANCE hPrevInstance,	// 前一实例句柄
	LPSTR lpCmdLine,			// 命令行参数
	int nCmdShow				// 窗口显示方式
)
{
	//1. 注册窗口
	WNDCLASS wc;	//定义并填充窗口类
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);	//CreateSolidBrush
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WinProc;	//重点：指定窗口消息的处理函数
	wc.lpszClassName = "Itjob2010";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&wc);		//注册窗口
 
	//2. 创建窗口
	HWND hWnd = CreateWindow(
		wc.lpszClassName,	//窗口类名称
		"My first clock",	//窗口标题
		/*WS_OVERLAPPEDWINDOW*/WS_POPUPWINDOW,	//窗口风格，定义为普通型
		0,						//窗口位置的x坐标
		0,						//窗口位置的y坐标
		300,					//窗口的宽度
		300,					//窗口的高度
		NULL,					//父窗口句柄
		NULL,					//菜单句柄
		hInstance,				//应用程序实例句柄
		NULL);					//窗口创建数据指针
	if (hWnd == NULL) return 0;

	//3. 显示窗口
	ShowWindow(hWnd, SW_SHOW);

	//4. 更新窗口
	UpdateWindow(hWnd);
	//5. 消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);		//把虚键消息翻译成字符消息(WM_CHAR)，
									//再把WM_CHAR消息放到消息队列中去
		DispatchMessage(&msg);		//指示操作系统把这条消息发送到窗口
									//过程WinProc进行处理
	}

	return msg.wParam;
}

//窗口回调函数，由操作系统调用，程序员
//不要调用，但程序员需要编写其实现代码
LRESULT CALLBACK WinProc(
	HWND hWnd,		// 窗口句柄
	UINT uMsg,		// 消息ID
	WPARAM wParam,	// 第1个消息参数
	LPARAM lParam	// 第2个消息参数
)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		::PostMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, 0);
		break;
	case WM_RBUTTONDOWN:
		Color=RAND();
		::InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_CREATE:	
		{
		::GetLocalTime(&tm);
		::SetTimer(hWnd, 110, 1000, NULL);
		HRGN hRgn = ::CreateEllipticRgn(0, 0,301,301);
		::SetWindowRgn(hWnd, hRgn, TRUE);
		}
		break;
	case WM_TIMER:
		::InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) ::PostQuitMessage(0);
		if (wParam == VK_F1)
		{
			isMenuCom=!isMenuCom;
			::InvalidateRect(hWnd, NULL, TRUE);
		}
		if (wParam == VK_F3)
		{
			::GetLocalTime(&tm);
			isFixTime=false;
			::InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case 0x020A:
		{
			isFixTime=true;
			char sz[10]={0};
			sprintf(sz,"%d",wParam);
			if((int)wParam>0)
			{
			//	::MessageBox(NULL,sz,"NULL",MB_OK);
				if(tm.wSecond==0)
				{
					tm.wSecond=0;
					tm.wMinute-=1;
				}
				else
					tm.wSecond-=1;
			}
			else
			{
				if(tm.wSecond+1>59)
				{
					tm.wSecond=0;
					tm.wMinute+=1;
				}
				else
					tm.wSecond+=1;
			}
			::InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_PAINT:
		{
		char szNow[] = "23:59:59";
		RECT rt;
		RECT rt2;
		::GetClientRect(hWnd, &rt);
		if(!isFixTime)
			::GetLocalTime(&tm);
		float fSecond = tm.wSecond;
		float fMinute = tm.wMinute + fSecond / 60.0f;
		float fHour = tm.wHour % 12+ fMinute / 60.0f;
		sprintf(szNow, "%02d:%02d:%02d", tm.wHour, tm.wMinute, tm.wSecond);
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HRGN hRgn = ::CreateEllipticRgn(0, 0,300,300);


		::SetBkColor(hdc,Color);
		int x = rt.right / 2;
		int y = rt.bottom / 2;
		int r = min(x, y);
		r = r;

		::Ellipse(hdc, x-r, y-r, x+r, y+r);
		::FillRgn(hdc,hRgn,::CreateSolidBrush(Color));
		int i,count=12;
		for (i = 0; i < 60; i = i + 5)   //时刻表!!!
		{
			POINT pt0, pt1;
			pt0.x = x + r * sin( PI/30 * i) * 0.92f;
			pt0.y = y - r * cos( PI/30 * i) * 0.92f;
			pt1.x = x + r * sin( PI/30 * i) * 1.00f;
			pt1.y = y - r * cos( PI/30 * i) * 1.00f;
			MoveToEx(hdc,pt0.x,pt0.y, (LPPOINT)NULL);
			LineTo(hdc, pt1.x, pt1.y);
			char sz[5]={0};
			if(count>12) count=1;
			sprintf(sz,"%d",count++);
			rt2.left=x + r * sin( PI/30 * i) * 0.8f;
			rt2.top=y - r * cos( PI/30 * i) * 0.8f;
			rt2.right=x + r * sin( PI/30 * i) * 0.9f;
			rt2.bottom=y - r * cos( PI/30 * i) * 0.9f;
			//::TextOut(hdc,pt0.x,pt0.y,sz,strlen(sz));
			::DrawText(hdc, sz, strlen(sz), &rt2, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		}
		for (i = 0; i < 60; i++)   //秒刻表!!!
		{
			POINT pt0, pt1;
			pt0.x = x + r * sin( PI/30 * i) * 0.96f;
			pt0.y = y - r * cos( PI/30 * i) * 0.96f;
			pt1.x = x + r * sin( PI/30 * i) * 1.00f;
			pt1.y = y - r * cos( PI/30 * i) * 1.00f;
			MoveToEx(hdc,pt0.x,pt0.y, (LPPOINT)NULL);
			LineTo(hdc, pt1.x, pt1.y);
		}
		POINT pt,pt1,pt2;										//画秒针
		pt.x = x + r * sin( PI/30 * tm.wSecond) * 0.9f;
		pt.y = y - r * cos( PI/30 * tm.wSecond) * 0.9f;
		MoveToEx(hdc,x,y, (LPPOINT)NULL);
		LineTo(hdc, pt.x, pt.y);


		pt.x = x + r * sin( PI/30 * fMinute) * 0.85f; //画分针
		pt.y = y - r * cos( PI/30 * fMinute) * 0.85f;
		MoveToEx(hdc,x,y, (LPPOINT)NULL);
		LineTo(hdc, pt.x, pt.y);

		HPEN pen=::CreatePen(PS_SOLID,4,0x0);
		HPEN OldPen=(HPEN)::SelectObject(hdc,pen);
		pt.x = x + r * sin( PI/6 * (fHour)) * 0.7f; //画时针
		pt.y = y - r * cos( PI/6 * (fHour)) * 0.7f;
		MoveToEx(hdc,x,y, (LPPOINT)NULL);
		LineTo(hdc, pt.x, pt.y);
		::SelectObject(hdc,OldPen);
		::DeleteObject(pen);
		::DeleteObject(OldPen);

		rt2.left=x-60;
		rt2.top=y;
		rt2.right=x+60;
		rt2.bottom=y+60;
		::DrawText(hdc, szNow, strlen(szNow), &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		rt2.left=x-60;
		rt2.top=y-80;
		rt2.right=x+60;
		rt2.bottom=y;
		if(!isMenuCom)
			::DrawText(hdc,"F1呼出帮助\nLB改背景色\nF3校准时间",strlen("F1呼出帮助\nLB改背景色\nF3校准时间"),&rt2,DT_CENTER);
		EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		::KillTimer(hWnd, 110);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;	//return 1
}

//1. GetWindowRect / GetClientRect
//2. SetWindowRgn
//3. MoveToEx / LineTo
