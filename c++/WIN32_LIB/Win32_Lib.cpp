#include <windows.h>
#include <stdio.h>


typedef LRESULT(*FXN)(HWND, UINT, WPARAM, LPARAM);
#define dim(x) (sizeof(x)/sizeof(x[0]))


//�������ڻص�����
LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);

//LRESULT OnChar(HWND, UINT, WPARAM, LPARAM);
//LRESULT OnLButtonDown(HWND, UINT, WPARAM, LPARAM);
//LRESULT OnPaint(HWND, UINT, WPARAM, LPARAM);
//LRESULT OnDestroy(HWND, UINT, WPARAM, LPARAM);


struct tagMESSAGEMAP
{
	UINT uMsg;	//��Ϣ
	FXN pFun;	//��Ӧ����
}; 
//�����ڻص�����
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
//������Ϣ��Ӧ����
LRESULT OnChar(HWND, UINT, WPARAM, LPARAM);
LRESULT OnLButtonDown(HWND, UINT, WPARAM, LPARAM);
LRESULT OnPaint(HWND, UINT, WPARAM, LPARAM);
LRESULT OnDestroy(HWND, UINT, WPARAM, LPARAM);

//��Ϣӳ������
tagMESSAGEMAP MessageMaps[] = {
	WM_CHAR, OnChar, 
	WM_LBUTTONDOWN, OnLButtonDown, 
	WM_PAINT, OnPaint, 
	WM_DESTROY, OnDestroy, 
};


//�������
int WINAPI WinMain(
	HINSTANCE hInstance,		// ��ǰʵ�����
	HINSTANCE hPrevInstance,	// ǰһʵ�����
	LPSTR lpCmdLine,		// �����в���
	int nCmdShow			// ������ʾ��ʽ
)
{
	//1. ע�ᴰ��
	WNDCLASS wndcls;	//���岢��䴰����
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinProc;	//�ص㣺ָ��������Ϣ�Ĵ�����
	wndcls.lpszClassName = "Itjob2010";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);		//ע�ᴰ��
 
	//2. ��������
	HWND hWnd;
	hWnd = CreateWindow(
		wndcls.lpszClassName,	//����������
		"һ���򵥵�Win32����",	//���ڱ���
		WS_OVERLAPPEDWINDOW,	//���ڷ�񣬶���Ϊ��ͨ��
		0,						//����λ�õ�x����
		0,						//����λ�õ�y����
		600,					//���ڵĿ��
		400,					//���ڵĸ߶�
		NULL,					//�����ھ��
		NULL,					//�˵����
		hInstance,				//Ӧ�ó���ʵ�����
		NULL);					//���ڴ�������ָ��

	//3. ��ʾ����
	ShowWindow(hWnd, SW_SHOWNORMAL);

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
	return 0;
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
	for(int i=0;i<dim(MessageMaps);i++)
	{
		if(uMsg==MessageMaps[i].uMsg)
		{
			FXN fun=MessageMaps[i].pFun;
			return fun(hWnd,uMsg,wParam,lParam);
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



//////////////////////////////
LRESULT OnChar(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	char szChar[20];
	sprintf(szChar, "char is %c", (char)wParam);
	MessageBox(hWnd, szChar, "OnChar", 0);
	return 0;
}

//��Ϣ��Ӧ����: ����������
LRESULT OnLButtonDown(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	TextOut(hdc, 0, 50, "��������������ѵ", strlen("��������������ѵ"));
	ReleaseDC(hWnd, hdc);
	return 0;
}

//��Ϣ��Ӧ�������ػ洰��
LRESULT OnPaint(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
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

	static char stime[] = "23:59:59";
	SYSTEMTIME tm;
	::GetLocalTime(&tm);
	sprintf(stime, "%.2d:%.2d:%.2d", tm.wHour, tm.wMinute, tm.wSecond);
	::TextOut(hdc, 10, 10,(LPCSTR)stime, strlen(stime));

	EndPaint(hWnd, &ps);
	return 0;
}

//��Ϣ��Ӧ����: ���ٴ���
LRESULT OnDestroy(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}
