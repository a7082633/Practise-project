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

//���CPU���ϵ�������ʱ��������
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}
int Color=190;
//�������ڻص�����
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

//�������
int WINAPI WinMain(
	HINSTANCE hInstance,		// ��ǰʵ�����
	HINSTANCE hPrevInstance,	// ǰһʵ�����
	LPSTR lpCmdLine,			// �����в���
	int nCmdShow				// ������ʾ��ʽ
)
{
	//1. ע�ᴰ��
	WNDCLASS wc;	//���岢��䴰����
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);	//CreateSolidBrush
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WinProc;	//�ص㣺ָ��������Ϣ�Ĵ�����
	wc.lpszClassName = "Itjob2010";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&wc);		//ע�ᴰ��
 
	//2. ��������
	HWND hWnd = CreateWindow(
		wc.lpszClassName,	//����������
		"My first clock",	//���ڱ���
		/*WS_OVERLAPPEDWINDOW*/WS_POPUPWINDOW,	//���ڷ�񣬶���Ϊ��ͨ��
		0,						//����λ�õ�x����
		0,						//����λ�õ�y����
		300,					//���ڵĿ��
		300,					//���ڵĸ߶�
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

//���ڻص��������ɲ���ϵͳ���ã�����Ա
//��Ҫ���ã�������Ա��Ҫ��д��ʵ�ִ���
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
		for (i = 0; i < 60; i = i + 5)   //ʱ�̱�!!!
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
		for (i = 0; i < 60; i++)   //��̱�!!!
		{
			POINT pt0, pt1;
			pt0.x = x + r * sin( PI/30 * i) * 0.96f;
			pt0.y = y - r * cos( PI/30 * i) * 0.96f;
			pt1.x = x + r * sin( PI/30 * i) * 1.00f;
			pt1.y = y - r * cos( PI/30 * i) * 1.00f;
			MoveToEx(hdc,pt0.x,pt0.y, (LPPOINT)NULL);
			LineTo(hdc, pt1.x, pt1.y);
		}
		POINT pt,pt1,pt2;										//������
		pt.x = x + r * sin( PI/30 * tm.wSecond) * 0.9f;
		pt.y = y - r * cos( PI/30 * tm.wSecond) * 0.9f;
		MoveToEx(hdc,x,y, (LPPOINT)NULL);
		LineTo(hdc, pt.x, pt.y);


		pt.x = x + r * sin( PI/30 * fMinute) * 0.85f; //������
		pt.y = y - r * cos( PI/30 * fMinute) * 0.85f;
		MoveToEx(hdc,x,y, (LPPOINT)NULL);
		LineTo(hdc, pt.x, pt.y);

		HPEN pen=::CreatePen(PS_SOLID,4,0x0);
		HPEN OldPen=(HPEN)::SelectObject(hdc,pen);
		pt.x = x + r * sin( PI/6 * (fHour)) * 0.7f; //��ʱ��
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
			::DrawText(hdc,"F1��������\nLB�ı���ɫ\nF3У׼ʱ��",strlen("F1��������\nLB�ı���ɫ\nF3У׼ʱ��"),&rt2,DT_CENTER);
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
