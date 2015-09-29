#include <windows.h>
#include <stdio.h>


typedef LRESULT(*FXN)(HWND, UINT, WPARAM, LPARAM);
#define dim(x) (sizeof(x)/sizeof(x[0]))


//声明窗口回调函数
LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);

//LRESULT OnChar(HWND, UINT, WPARAM, LPARAM);
//LRESULT OnLButtonDown(HWND, UINT, WPARAM, LPARAM);
//LRESULT OnPaint(HWND, UINT, WPARAM, LPARAM);
//LRESULT OnDestroy(HWND, UINT, WPARAM, LPARAM);


struct tagMESSAGEMAP
{
	UINT uMsg;	//消息
	FXN pFun;	//响应函数
}; 
//主窗口回调函数
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
//声明消息响应函数
LRESULT OnChar(HWND, UINT, WPARAM, LPARAM);
LRESULT OnLButtonDown(HWND, UINT, WPARAM, LPARAM);
LRESULT OnPaint(HWND, UINT, WPARAM, LPARAM);
LRESULT OnDestroy(HWND, UINT, WPARAM, LPARAM);

//消息映射数组
tagMESSAGEMAP MessageMaps[] = {
	WM_CHAR, OnChar, 
	WM_LBUTTONDOWN, OnLButtonDown, 
	WM_PAINT, OnPaint, 
	WM_DESTROY, OnDestroy, 
};


//程序入口
int WINAPI WinMain(
	HINSTANCE hInstance,		// 当前实例句柄
	HINSTANCE hPrevInstance,	// 前一实例句柄
	LPSTR lpCmdLine,		// 命令行参数
	int nCmdShow			// 窗口显示方式
)
{
	//1. 注册窗口
	WNDCLASS wndcls;	//定义并填充窗口类
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinProc;	//重点：指定窗口消息的处理函数
	wndcls.lpszClassName = "Itjob2010";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);		//注册窗口
 
	//2. 创建窗口
	HWND hWnd;
	hWnd = CreateWindow(
		wndcls.lpszClassName,	//窗口类名称
		"一个简单的Win32程序",	//窗口标题
		WS_OVERLAPPEDWINDOW,	//窗口风格，定义为普通型
		0,						//窗口位置的x坐标
		0,						//窗口位置的y坐标
		600,					//窗口的宽度
		400,					//窗口的高度
		NULL,					//父窗口句柄
		NULL,					//菜单句柄
		hInstance,				//应用程序实例句柄
		NULL);					//窗口创建数据指针

	//3. 显示窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);

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
	return 0;
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

//消息响应函数: 鼠标左键按下
LRESULT OnLButtonDown(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	TextOut(hdc, 0, 50, "计算机编程语言培训", strlen("计算机编程语言培训"));
	ReleaseDC(hWnd, hdc);
	return 0;
}

//消息响应函数：重绘窗口
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

//消息响应函数: 销毁窗口
LRESULT OnDestroy(HWND hWnd, UINT wMsg, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}
