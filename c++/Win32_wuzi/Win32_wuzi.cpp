// Win32_wuzi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
int Chess[15][15]={0};
int px;
int py;
BOOL BWho=false;
BOOL IsDone=false;
LRESULT CALLBACK WinProc(
	HWND hWnd,		// 窗口句柄
	UINT uMsg,		// 消息ID
	WPARAM wParam,	// 第1个消息参数
	LPARAM lParam	// 第2个消息参数
);
int Check(int x,int y)
{
	int count=0;
	int px=x,py=y;
	while(py-1>=0)//左横向
	{
		if(Chess[x][y]==Chess[px][py-1])
		{
			py--;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(py+1<15)//右横向
	{
		if(Chess[x][y]==Chess[px][py+1])
		{
			count++;
			py++;
		}
		else
			break;
	}
	if(count>=4)
	{
		//printf("%s win!",Chess[x][y]);
		return Chess[x][y];
		//exit(0);
	}
	px=x;
	py=y;
	count=0;
	///////////////////////////////纵向、//////////////
	while(px-1>=0)//上
	{
		if(Chess[x][y]==Chess[px-1][py])
		{
			px--;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(px+1<15)//下
	{
		if(Chess[x][y]==Chess[px+1][py])
		{
			count++;
			px++;
		}
		else
			break;
	}
	if(count>=4)
	{
		return Chess[x][y];
	}
	px=x;
	py=y;
	count=0;
	///////////////////////////////斜向一、//////////////
	while(px-1>=0&&py-1>=0)//左上
	{
		if(Chess[x][y]==Chess[px-1][py-1])
		{
			px--;
			py--;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(px+1<15&&py+1<15)//右下
	{
		if(Chess[x][y]==Chess[px+1][py+1])
		{
			count++;
			px++;
			py++;
		}
		else
			break;
	}
	if(count>=4)
	{
		return Chess[x][y];
	}
	px=x;
	py=y;
	count=0;
		///////////////////////////////斜向二、//////////////
	while(px-1>=0&&py+1<15)//右上
	{
		if(Chess[x][y]==Chess[px-1][py+1])
		{
			px--;
			py++;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(px+1<15&&py-1>=0)//左下
	{
		if(Chess[x][y]==Chess[px+1][py-1])
		{
			count++;
			px++;
			py--;
		}
		else
			break;
	}
	if(count>=4)
	{
		return Chess[x][y];
	}
	return 0;
}

void ClearChess()
{
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			Chess[i][j]=0;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	//1. 注册窗口
	WNDCLASS wc;	//定义并填充窗口类
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//CreateSolidBrush
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WinProc;	//重点：指定窗口消息的处理函数
	wc.lpszClassName = "2015";
	wc.lpszMenuName = "五子棋";
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&wc);		//注册窗口
 
	//2. 创建窗口
	HWND hWnd = CreateWindow(
		wc.lpszClassName,	//窗口类名称
		"五子棋",	//窗口标题
		/*WS_OVERLAPPEDWINDOW*/WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             
							 WS_MINIMIZEBOX
							 ,	//窗口风格，定义为普通型
		100,						//窗口位置的x坐标
		100,						//窗口位置的y坐标
		800,					//窗口的宽度
		530,					//窗口的高度
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
		if(!IsDone)
		{
			int x=LOWORD(lParam);
			int y=HIWORD(lParam);
			if(x<490&&y<490)
				if(BWho)
				{
					if(Chess[y/33][x/33]==0)
					{
						Chess[y/33][x/33]=1;
						BWho=!BWho;
						::InvalidateRect(hWnd, NULL, TRUE);
					}
				}
				else
				{
					if(Chess[y/33][x/33]==0)
					{
						Chess[y/33][x/33]=2;
						BWho=!BWho;
						::InvalidateRect(hWnd, NULL, TRUE);
					}
				}
			//::MessageBox(NULL,"TEST",NULL,MB_OK);
		}
		break;
	case WM_TIMER:
		::InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) ::PostQuitMessage(0);
		if (wParam==VK_F1)
		{
			ClearChess();
			IsDone=!IsDone;
			::InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_MOUSEMOVE:
		{
			int x=LOWORD(lParam);
			int y=HIWORD(lParam);
			char sz[10]={0};
			POINT pt;
			::GetCursorPos(&pt);
			sprintf(sz,"%d,%d",x,y);
			::SetWindowText(hWnd,sz);
		}
		break;
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			char sz[50]="游戏说明:\n\nF1重新开始\n\nESC退出游戏";
			RECT rt;
			rt.left=633-100;
			rt.top=30;
			rt.right=633+100;
			rt.bottom=140;
			::DrawText(hdc,sz,strlen(sz),&rt,DT_CENTER|DT_VCENTER);

			char sz2[50]="游戏状态:";
			rt.left=633-100;
			rt.top=150;
			rt.right=633+100;
			rt.bottom=200;
			::DrawText(hdc,sz2,strlen(sz2),&rt,DT_CENTER|DT_VCENTER);
			if(BWho)
			{
				HBRUSH hBrush=::CreateSolidBrush(0xff);
				HBRUSH OldBrush=(HBRUSH)::SelectObject(hdc,hBrush);
				::Ellipse(hdc,575-10,196-10,575+10,196+10);
				::SelectObject(hdc,OldBrush);
				::DeleteObject(hBrush);
			}
			else
			{
				HBRUSH hBrush=::CreateSolidBrush(0x0);
				HBRUSH OldBrush=(HBRUSH)::SelectObject(hdc,hBrush);
				::Ellipse(hdc,575-10,196-10,575+10,196+10);
				::SelectObject(hdc,OldBrush);
				::DeleteObject(hBrush);
			}
			char sz3[50]="正在下棋";
			rt.left=631-30;
			rt.top=187;
			rt.right=633+30;
			rt.bottom=250;
			::DrawText(hdc,sz3,strlen(sz3),&rt,DT_CENTER|DT_VCENTER);

			HPEN Pen=::CreatePen(PS_SOLID,1,0xff);
			HPEN OldPen=(HPEN)::SelectObject(hdc,Pen);
			int i , j;
			for(i=0;i<15;i++)
			{
				::MoveToEx(hdc,10,(i)*33+10,NULL);
				::LineTo(hdc,472,(i)*33+10);
			}
			for(i=0;i<15;i++)
			{
				::MoveToEx(hdc,(i)*33+10,10,NULL);
				::LineTo(hdc,(i)*33+10,472);
			}

			char *str="版本号:V1.0";
			::TextOut(hdc,590,388,str,strlen(str));
			str="作者:天生一指禅";
			::TextOut(hdc,590,420,str,strlen(str));
			//遍历棋盘
			int WhoWin=5;
			for(i=0;i<15;i++)
				for(j=0;j<15;j++)
				{
					if(Chess[i][j]==1)
					{
						if(0==i)	py=10;
						else		py=i*33+10;
						if(0==j)	px=10;
						else		px=j*33+10;
						HBRUSH hBrush=::CreateSolidBrush(0xff);
						HBRUSH OldBrush=(HBRUSH)::SelectObject(hdc,hBrush);
						::Ellipse(hdc,px-10,py-10,px+10,py+10);
						::SelectObject(hdc,OldBrush);
						::DeleteObject(hBrush);
						if(Check(i,j)==1)
						{
							WhoWin=1;
						}
					}
					if(Chess[i][j]==2)
					{
						if(0==i)	py=10;
						else		py=i*33+10;
						if(0==j)	px=10;
						else		px=j*33+10;
						HBRUSH hBrush=::CreateSolidBrush(0x0);
						HBRUSH OldBrush=(HBRUSH)::SelectObject(hdc,hBrush);
						::Ellipse(hdc,px-10,py-10,px+10,py+10);
						::SelectObject(hdc,OldBrush);
						::DeleteObject(hBrush);
						if(Check(i,j)==2)
						{
							WhoWin=2;
						}
					}
				}
			if(WhoWin==1)
			{
				if(IDYES==::MessageBox(hWnd,"红方胜利!不服？再来一次？","游戏结束!",MB_YESNO))
				{
					ClearChess();
					::InvalidateRect(hWnd, NULL, TRUE);
				}
				else
					IsDone=!IsDone;
			}
			if(WhoWin==2)
			{
				if(IDYES==::MessageBox(hWnd,"黑方胜利!不服？再来一次？","游戏结束!",MB_YESNO))
				{
					ClearChess();
					::InvalidateRect(hWnd, NULL, TRUE);
				}
				else
					IsDone=!IsDone;
			}
			::DeleteObject(Pen);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		//::KillTimer(hWnd, 110);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;	//return 1
}