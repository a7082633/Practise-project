// MiniMFC.h: interface for the CMyWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MINIMFC_H__7ECB504F_2ECD_49AC_83EB_3CBE8020BC52__INCLUDED_)
#define AFX_MINIMFC_H__7ECB504F_2ECD_49AC_83EB_3CBE8020BC52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef LRESULT(*FXN)(HWND, UINT, WPARAM, LPARAM);
#define dim(x) sizeof(x)/sizeof(x[0])

class CMyWnd  
{
public:

	struct tagMESSAGEMAP
	{
		UINT Code; //消息
		FXN pFun;//响应函数
	};

	void UpdateWindow();
	void ShowWindow();
	void Create();
	CMyWnd();
	virtual ~CMyWnd();

	//声明窗口回调函数
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 
	//消息响应函数的宏
	MESSAGE_DECLEAR();
public:
	
	HWND m_hWnd;
	//消息映射数组
	const static tagMESSAGEMAP MessageMaps[];  //记住成员函数不能直接赋初值，而且数组必须写明大小。但是定为 静态后，可以在类外初始化，就
	                                     //解决了赋值、数组可以不写大小（初始化后会自己计算）的问题。
};
// tagMESSAGEMAP 要访问 结构体，就要在前边加限定符了，因为结构体包含在了 CMyWnd类中了
//消息映射的数组  的宏
	MESSAGE_MAP();

//程序入口
int WINAPI WinMain(
				   HINSTANCE hInstance,		// 当前实例句柄
				   HINSTANCE hPrevInstance,	// 前一实例句柄
				   LPSTR lpCmdLine,		// 命令行参数
				   int nCmdShow			// 窗口显示方式
				   )
{
	
		return 0;
}

//窗口回调函数，由操作系统调用，程序员
//不要调用，但程序员需要编写其实现代码
LRESULT CALLBACK CMyWnd::WinProc(
						 HWND hWnd,		// 窗口句柄
						 UINT uMsg,		// 消息ID
						 WPARAM wParam,	// 第1个消息参数
						 LPARAM lParam	// 第2个消息参数
						 )
{
	for(int i=0;i<dim(MessageMaps);i++)//回调 接到消息，然后进入for循环，
	{
		if(uMsg == MessageMaps[i].Code) //如果消息符合，
		{
			FXN fun = MessageMaps[i].pFun;  //就调用对应的函数。用定义好的函数指针指向 要调用的函数。
			return fun(hWnd,uMsg,wParam,lParam);
		}

	}
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}


//////////////////////////////////////////////////////////////////////
// CMyWnd Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyWnd::CMyWnd()
{
	m_hWnd = NULL;
}

CMyWnd::~CMyWnd()
{

}

void CMyWnd::Create()
{
	//1. 注册窗口
	WNDCLASS wndcls;	//定义并填充窗口类
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = NULL;
	wndcls.lpfnWndProc = WinProc;	//重点：指定窗口消息的处理函数
	wndcls.lpszClassName = "Itjob2010";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);		//注册窗口
	
	//2. 创建窗口
	//这是Win32 函数
	m_hWnd = CreateWindow(
		wndcls.lpszClassName,	//窗口类名称
		"一个简单的Win32程序",	//窗口标题
		WS_OVERLAPPEDWINDOW,	//窗口风格，定义为普通型
		0,						//窗口位置的x坐标
		0,						//窗口位置的y坐标
		600,					//窗口的宽度
		400,					//窗口的高度
		NULL,					//父窗口句柄
		NULL,					//菜单句柄
		NULL,				//应用程序实例句柄
		NULL);					//窗口创建数据指针
}

void CMyWnd::ShowWindow()
{
	//3. 显示窗口
	::ShowWindow(m_hWnd, SW_SHOWNORMAL); //重名了 所以必须加 双冒号，表全局  这是Win32 函数
}

void CMyWnd::UpdateWindow()
{
	//4. 更新窗口
	::UpdateWindow(m_hWnd);//重名了 所以必须加 双冒号，表全局，这是Win32 函数
}


class CMyApp  
{
public:
	void Run();
	void InitInstance();
	CMyApp();
	virtual ~CMyApp();
	CMyWnd* m_pMainWnd;
	CMyWnd* m_pMainWnd1;
};


//////////////////////////////////////////////////////////////////////
// CMyApp Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyApp::CMyApp()
{
	m_pMainWnd = NULL;
	m_pMainWnd1 = NULL;
	InitInstance();
	Run();
	
}

CMyApp::~CMyApp()
{
	delete[] m_pMainWnd;
	delete[] m_pMainWnd1;
}

void CMyApp::InitInstance()
{
	//一。实例化窗口
	m_pMainWnd = new CMyWnd;
	m_pMainWnd->Create();
	m_pMainWnd->ShowWindow();
	m_pMainWnd->UpdateWindow();

	m_pMainWnd1 = new CMyWnd;
	m_pMainWnd1->Create();
	m_pMainWnd1->ShowWindow();
	m_pMainWnd1->UpdateWindow();
}

void CMyApp::Run()
{
		//二。 消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);		//把虚键消息翻译成字符消息(WM_CHAR)，
		//再把WM_CHAR消息放到消息队列中去
		DispatchMessage(&msg);		//指示操作系统把这条消息发送到窗口
		//过程WinProc进行处理
	}
}

#endif // !defined(AFX_MINIMFC_H__7ECB504F_2ECD_49AC_83EB_3CBE8020BC52__INCLUDED_)
