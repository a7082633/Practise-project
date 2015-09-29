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
		UINT Code; //��Ϣ
		FXN pFun;//��Ӧ����
	};

	void UpdateWindow();
	void ShowWindow();
	void Create();
	CMyWnd();
	virtual ~CMyWnd();

	//�������ڻص�����
	static LRESULT CALLBACK WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 
	//��Ϣ��Ӧ�����ĺ�
	MESSAGE_DECLEAR();
public:
	
	HWND m_hWnd;
	//��Ϣӳ������
	const static tagMESSAGEMAP MessageMaps[];  //��ס��Ա��������ֱ�Ӹ���ֵ�������������д����С�����Ƕ�Ϊ ��̬�󣬿����������ʼ������
	                                     //����˸�ֵ��������Բ�д��С����ʼ������Լ����㣩�����⡣
};
// tagMESSAGEMAP Ҫ���� �ṹ�壬��Ҫ��ǰ�߼��޶����ˣ���Ϊ�ṹ��������� CMyWnd������
//��Ϣӳ�������  �ĺ�
	MESSAGE_MAP();

//�������
int WINAPI WinMain(
				   HINSTANCE hInstance,		// ��ǰʵ�����
				   HINSTANCE hPrevInstance,	// ǰһʵ�����
				   LPSTR lpCmdLine,		// �����в���
				   int nCmdShow			// ������ʾ��ʽ
				   )
{
	
		return 0;
}

//���ڻص��������ɲ���ϵͳ���ã�����Ա
//��Ҫ���ã�������Ա��Ҫ��д��ʵ�ִ���
LRESULT CALLBACK CMyWnd::WinProc(
						 HWND hWnd,		// ���ھ��
						 UINT uMsg,		// ��ϢID
						 WPARAM wParam,	// ��1����Ϣ����
						 LPARAM lParam	// ��2����Ϣ����
						 )
{
	for(int i=0;i<dim(MessageMaps);i++)//�ص� �ӵ���Ϣ��Ȼ�����forѭ����
	{
		if(uMsg == MessageMaps[i].Code) //�����Ϣ���ϣ�
		{
			FXN fun = MessageMaps[i].pFun;  //�͵��ö�Ӧ�ĺ������ö���õĺ���ָ��ָ�� Ҫ���õĺ�����
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
	//1. ע�ᴰ��
	WNDCLASS wndcls;	//���岢��䴰����
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndcls.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndcls.hInstance = NULL;
	wndcls.lpfnWndProc = WinProc;	//�ص㣺ָ��������Ϣ�Ĵ�����
	wndcls.lpszClassName = "Itjob2010";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);		//ע�ᴰ��
	
	//2. ��������
	//����Win32 ����
	m_hWnd = CreateWindow(
		wndcls.lpszClassName,	//����������
		"һ���򵥵�Win32����",	//���ڱ���
		WS_OVERLAPPEDWINDOW,	//���ڷ�񣬶���Ϊ��ͨ��
		0,						//����λ�õ�x����
		0,						//����λ�õ�y����
		600,					//���ڵĿ��
		400,					//���ڵĸ߶�
		NULL,					//�����ھ��
		NULL,					//�˵����
		NULL,				//Ӧ�ó���ʵ�����
		NULL);					//���ڴ�������ָ��
}

void CMyWnd::ShowWindow()
{
	//3. ��ʾ����
	::ShowWindow(m_hWnd, SW_SHOWNORMAL); //������ ���Ա���� ˫ð�ţ���ȫ��  ����Win32 ����
}

void CMyWnd::UpdateWindow()
{
	//4. ���´���
	::UpdateWindow(m_hWnd);//������ ���Ա���� ˫ð�ţ���ȫ�֣�����Win32 ����
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
	//һ��ʵ��������
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
		//���� ��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);		//�������Ϣ������ַ���Ϣ(WM_CHAR)��
		//�ٰ�WM_CHAR��Ϣ�ŵ���Ϣ������ȥ
		DispatchMessage(&msg);		//ָʾ����ϵͳ��������Ϣ���͵�����
		//����WinProc���д���
	}
}

#endif // !defined(AFX_MINIMFC_H__7ECB504F_2ECD_49AC_83EB_3CBE8020BC52__INCLUDED_)
