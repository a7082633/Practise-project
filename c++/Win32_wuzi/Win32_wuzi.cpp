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
	HWND hWnd,		// ���ھ��
	UINT uMsg,		// ��ϢID
	WPARAM wParam,	// ��1����Ϣ����
	LPARAM lParam	// ��2����Ϣ����
);
int Check(int x,int y)
{
	int count=0;
	int px=x,py=y;
	while(py-1>=0)//�����
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
	while(py+1<15)//�Һ���
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
	///////////////////////////////����//////////////
	while(px-1>=0)//��
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
	while(px+1<15)//��
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
	///////////////////////////////б��һ��//////////////
	while(px-1>=0&&py-1>=0)//����
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
	while(px+1<15&&py+1<15)//����
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
		///////////////////////////////б�����//////////////
	while(px-1>=0&&py+1<15)//����
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
	while(px+1<15&&py-1>=0)//����
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
	//1. ע�ᴰ��
	WNDCLASS wc;	//���岢��䴰����
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//CreateSolidBrush
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WinProc;	//�ص㣺ָ��������Ϣ�Ĵ�����
	wc.lpszClassName = "2015";
	wc.lpszMenuName = "������";
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&wc);		//ע�ᴰ��
 
	//2. ��������
	HWND hWnd = CreateWindow(
		wc.lpszClassName,	//����������
		"������",	//���ڱ���
		/*WS_OVERLAPPEDWINDOW*/WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             
							 WS_MINIMIZEBOX
							 ,	//���ڷ�񣬶���Ϊ��ͨ��
		100,						//����λ�õ�x����
		100,						//����λ�õ�y����
		800,					//���ڵĿ��
		530,					//���ڵĸ߶�
		NULL,					//�����ھ��
		NULL,					//�˵����
		hInstance,				//Ӧ�ó���ʵ�����
		NULL);					//���ڴ�������ָ��
	if (hWnd == NULL) return 0;

	//3. ��ʾ����
	ShowWindow(hWnd, SW_SHOW);

	//4. ���´���
	UpdateWindow(hWnd);
	//5. ��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);		//�������Ϣ������ַ���Ϣ(WM_CHAR)��
									//�ٰ�WM_CHAR��Ϣ�ŵ���Ϣ������ȥ
		DispatchMessage(&msg);		//ָʾ����ϵͳ��������Ϣ���͵�����
									//����WinProc���д���
	}

	return msg.wParam;
}



LRESULT CALLBACK WinProc(
	HWND hWnd,		// ���ھ��
	UINT uMsg,		// ��ϢID
	WPARAM wParam,	// ��1����Ϣ����
	LPARAM lParam	// ��2����Ϣ����
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
			char sz[50]="��Ϸ˵��:\n\nF1���¿�ʼ\n\nESC�˳���Ϸ";
			RECT rt;
			rt.left=633-100;
			rt.top=30;
			rt.right=633+100;
			rt.bottom=140;
			::DrawText(hdc,sz,strlen(sz),&rt,DT_CENTER|DT_VCENTER);

			char sz2[50]="��Ϸ״̬:";
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
			char sz3[50]="��������";
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

			char *str="�汾��:V1.0";
			::TextOut(hdc,590,388,str,strlen(str));
			str="����:����һָ��";
			::TextOut(hdc,590,420,str,strlen(str));
			//��������
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
				if(IDYES==::MessageBox(hWnd,"�췽ʤ��!����������һ�Σ�","��Ϸ����!",MB_YESNO))
				{
					ClearChess();
					::InvalidateRect(hWnd, NULL, TRUE);
				}
				else
					IsDone=!IsDone;
			}
			if(WhoWin==2)
			{
				if(IDYES==::MessageBox(hWnd,"�ڷ�ʤ��!����������һ�Σ�","��Ϸ����!",MB_YESNO))
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