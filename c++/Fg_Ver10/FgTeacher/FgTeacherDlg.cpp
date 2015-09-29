// FgTeacherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FgTeacher.h"
#include "FgTeacherDlg.h"

#include "quicklz.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//获取本机IP
	char szName[128] = {0};
	::gethostname(szName, strlen(szName));
	HOSTENT *pHost = gethostbyname(szName);
	IN_ADDR ip = *(in_addr *)*pHost->h_addr_list;

	CString szIP;
	szIP.Format("本机IP: %s", inet_ntoa(ip));

	this->SetDlgItemText(IDC_STATIC_IP, szIP);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

/////////////////////////////////////////////////////////////////////////////
// CFgTeacherDlg dialog

CFgTeacherDlg::CFgTeacherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFgTeacherDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFgTeacherDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_hThread = NULL;
}

void CFgTeacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFgTeacherDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFgTeacherDlg, CDialog)
	//{{AFX_MSG_MAP(CFgTeacherDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_COMMAND(IDM_DRAY_START, OnDrayStart)
	ON_COMMAND(IDM_DRAY_STOP, OnDrayStop)
	ON_COMMAND(IDM_DRAY_EXIT, OnDrayExit)
	ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
	ON_MESSAGE(UM_TRAY_NOTIFY, OnTrayNotify)
	ON_COMMAND(IDM_DRAY_ABOUT, OnDrayAbout)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFgTeacherDlg message handlers

void CFgTeacherDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFgTeacherDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

void CFgTeacherDlg::OnNcPaint() 
{
	static int i = 2;
	if (i > 0)
	{
		i--;
		this->ShowWindow(SW_HIDE);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFgTeacherDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

CString CFgTeacherDlg::GetBroadcastIP()
{
	//获取本机广播IP: 192.168.0.255
	char szName[128] = {0};
	::gethostname(szName, strlen(szName));
	HOSTENT *pHost = gethostbyname(szName);
	IN_ADDR ip = *(in_addr *)*pHost->h_addr_list;

	ip.S_un.S_un_b.s_b4 = 255;

	return inet_ntoa(ip);
}

BOOL CFgTeacherDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//1. 添加托盘
	TrayAdd();

	//隐藏this窗口在任务栏的图标
	this->ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);

	//2. 创建并设置套接字, 教师端做客户端，只发送数据, 不需要bind
	m_hSock = socket(AF_INET, SOCK_DGRAM, 0);
	bool opt = true;
	setsockopt(m_hSock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));

	int nBufSize = PACKSIZE * 10;	//发送缓冲区设为80K, 但每次最多发送8K, 这样可以缓冲10次
	setsockopt(m_hSock, SOL_SOCKET, SO_SNDBUF, (char FAR *)&nBufSize, sizeof(nBufSize));

	//3.设置广播地址和端口
	memset(&m_addrTo, 0, sizeof(SOCKADDR_IN));
	m_addrTo.sin_family = AF_INET;
	m_addrTo.sin_addr.S_un.S_addr = inet_addr(GetBroadcastIP());//htonl(INADDR_BROADCAST); //设置ip为广播地址 即: 192.168.0.255
	m_addrTo.sin_port = htons(UDP_PORT);             //端口号

	//4. 初始化变量
	m_pDCScreen = CDC::FromHandle(::GetDC(NULL));
	w = m_pDCScreen->GetDeviceCaps(HORZRES);
	h = m_pDCScreen->GetDeviceCaps(VERTRES);

	m_dcMemNow.CreateCompatibleDC(m_pDCScreen);
	m_bmpMemNow.CreateCompatibleBitmap(m_pDCScreen, w, h);
	m_dcMemNow.SelectObject(&m_bmpMemNow);

	m_dcMemOld.CreateCompatibleDC(m_pDCScreen);
	m_bmpMemOld.CreateCompatibleBitmap(m_pDCScreen, w, h);
	m_dcMemOld.SelectObject(&m_bmpMemOld);

	int nBitsPixel = m_pDCScreen->GetDeviceCaps(BITSPIXEL);
	if (nBitsPixel == 32) nBitsPixel = 16;	//将32位色改成16位色进行传输，可省50%传输量

	m_nImageSize = w * h * nBitsPixel / 8;

	memset(&m_biScreen, 0, sizeof(m_biScreen));
	m_biScreen.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_biScreen.bmiHeader.biWidth = w;
	m_biScreen.bmiHeader.biHeight = h;
	m_biScreen.bmiHeader.biBitCount = nBitsPixel;
	m_biScreen.bmiHeader.biCompression = BI_RGB;
	m_biScreen.bmiHeader.biPlanes = 1;
	m_biScreen.bmiHeader.biSizeImage = m_nImageSize;

	m_pBufNow = new BYTE[m_nImageSize];
	memset(m_pBufNow, 0, m_nImageSize);

	m_pBufEncode1 = new BYTE[m_nImageSize];
	memset(m_pBufEncode1, 0, m_nImageSize);

	m_pBufEncode2 = new BYTE[m_nImageSize];
	memset(m_pBufEncode2, 0, m_nImageSize);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFgTeacherDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	TrayDelete();

	m_bmpMemNow.DeleteObject();
	m_bmpMemOld.DeleteObject();
	delete[] m_pBufNow;
	delete[] m_pBufEncode1;
	delete[] m_pBufEncode2;
	::closesocket(m_hSock);
}

//注册托盘
void CFgTeacherDlg::TrayAdd()
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,				//托盘号 
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		this->m_hIcon,
		"屏幕广播"
	};
	int iErr = Shell_NotifyIcon(NIM_ADD, &nid);
}

//销毁托盘
void CFgTeacherDlg::TrayDelete()
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		m_hIcon,
		"屏幕广播"
	};
	int iErr = Shell_NotifyIcon(NIM_DELETE, &nid);
}

//托盘消息
LRESULT CFgTeacherDlg::OnTrayNotify(WPARAM uID, LPARAM lEvent)
{
	//自定义消息函数，处理点击托盘消息
	if (uID == 100)
	{
		switch (lEvent)
		{
		case WM_RBUTTONUP:
			{
			CPoint pt;
			GetCursorPos(&pt);

			CMenu trayMenu;
			trayMenu.LoadMenu(IDR_TRAY_MENU);
			
			trayMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
				pt.x, pt.y, this);
			break;
			}
		}
	}
	return 0;
}

//#define PH_START_BROADCAST 1
//#define PH_STOP_BROADCAST  2
//#define PH_SEND_FRAMEPART  3
void CFgTeacherDlg::OnDrayStart()
{
	//1. 通知学生端打开窗口，准备开始接收
	PACKHEAD head = {0};
	head.nFlag = PH_START_BROADCAST;		//1开始广播
	head.biScreen = m_biScreen;

	memset(m_bufSend, 0, PACKSIZE);
	memcpy(m_bufSend, &head, sizeof(PACKHEAD));

	int nSent = ::sendto(m_hSock, (char *)m_bufSend, PACKSIZE, 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
	if (nSent == SOCKET_ERROR)
	{
		CString sMsg;
		sMsg.Format("不能开始广播, 错误代码为: %d", GetLastError());
		this->MessageBox(sMsg);
		return;
	}
	::Sleep(10);

//	//
//	::sendto(m_hSock, (char *)m_bufSend, sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
//	::Sleep(10);
//	::sendto(m_hSock, (char *)m_bufSend, sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
//	::Sleep(10);

	//2. 新开一个线程，准备发送
	if (m_hThread == NULL)
	{
		m_hThread = ::CreateThread(NULL, 0, SendProc, this, 0, NULL);
	}
}

void CFgTeacherDlg::OnDrayStop()
{
	//2. 终止线程. 此步骤提前，否则要2次才能停止广播
	if (m_hThread)
	{
		::TerminateThread(m_hThread, 0);
		m_hThread = NULL;
	}

	//1. 通知学生端隐藏窗口，停止接收
	PACKHEAD head = {0};
	head.nFlag = PH_STOP_BROADCAST;		//2停止广播
	head.biScreen = m_biScreen;

	memset(m_bufSend, 0, PACKSIZE);
	memcpy(m_bufSend, &head, sizeof(PACKHEAD));

	int nSent = ::sendto(m_hSock, (char *)m_bufSend, PACKSIZE, 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR_IN));
	if (nSent == SOCKET_ERROR)
	{
		CString sMsg;
		sMsg.Format("不能停止广播, 错误代码为: %d", GetLastError());
		this->MessageBox(sMsg);
		return;
	}
	::Sleep(10);
}

void CFgTeacherDlg::OnDrayAbout() //关于
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CFgTeacherDlg::OnDrayExit() //退出
{
	OnDrayStop();
	CDialog::OnOK();
}

DWORD WINAPI CFgTeacherDlg::SendProc(LPVOID p)
{
	CFgTeacherDlg *pDlg = (CFgTeacherDlg *)p;
	while (1)
	{
		pDlg->SendScreen();
	}
	return 0;
}

#if (_MSC_VER == 1200)
extern GETCURSORINFO GetCursorInfo;
#endif	//(_MSC_VER == 1200) 

void CFgTeacherDlg::SendScreen()
{
	SYSTEMTIME tm0, tm1;
	::GetLocalTime(&tm0);

	//1. 获取当前屏幕
	m_dcMemNow.BitBlt(0, 0, w, h, m_pDCScreen, 0, 0, SRCCOPY);

	//2. 绘制鼠标
	CURSORINFO ci = {0};
	ci.cbSize = sizeof(CURSORINFO);
	GetCursorInfo(&ci);

	ICONINFO ii = {0};
	GetIconInfo(ci.hCursor, &ii);

	m_dcMemNow.DrawIcon(ci.ptScreenPos.x-ii.xHotspot, ci.ptScreenPos.y-ii.yHotspot, ci.hCursor);

	//Bug 修正, 加以下语句，否则几万屏后会死在这里
	::DeleteObject(ii.hbmColor);
	::DeleteObject(ii.hbmMask);

	//3. Xor
	static UINT nFrame = -1;
	nFrame++;
	if (nFrame % 30 == 0)	//每隔30帧就传一个完整帧给学生端
	{
		m_dcMemOld.FillSolidRect(0, 0, w, h, 0x00000000);	//黑色
	}
	m_dcMemOld.BitBlt(0, 0, w, h, &m_dcMemNow, 0, 0, SRCINVERT);

	//4. 将异或后的m_dcMemOld的位图数据提取到m_pBufNow中
	memset(m_pBufNow, 0, m_nImageSize);
	::GetDIBits(m_dcMemOld.m_hDC, (HBITMAP)m_bmpMemOld.m_hObject,
		0, h, m_pBufNow, &m_biScreen, DIB_RGB_COLORS);

	//5. 保存当前屏于m_pDCMemOld
	m_dcMemOld.BitBlt(0, 0, w, h, &m_dcMemNow, 0, 0, SRCCOPY);

	//6. 1次压缩 m_pBufNow --> m_pBufEncode1
	qlz_state_compress *qsc = NULL;

	memset(m_pBufEncode1, 0, m_nImageSize);
	qsc = (qlz_state_compress *)malloc(sizeof(qlz_state_compress));
	DWORD dwEncodedSize1 = qlz_compress((char*)m_pBufNow, (char*)m_pBufEncode1,
		m_nImageSize, qsc);
	free(qsc);

	//6. 2次压缩 m_pBufEncode1 --> m_pBufEncode2
	memset(m_pBufEncode2, 0, m_nImageSize);
	qsc = (qlz_state_compress *)malloc(sizeof(qlz_state_compress));
	DWORD dwEncodedSize2 = qlz_compress((char*)m_pBufEncode1, (char*)m_pBufEncode2,
		dwEncodedSize1, qsc);
	free(qsc);

	//7. 传输 m_pBufEncode2
	PACKHEAD head = {0};	//3发送帧
	head.nFlag = PH_SEND_FRAMEPART;
	head.nFrame = nFrame;
	head.nPartCnt = WORD((dwEncodedSize2 + PACKSIZE - sizeof(PACKHEAD) - 1) / (PACKSIZE - sizeof(PACKHEAD)));
	head.biScreen = m_biScreen;

	DWORD nSentSum = 0;
	while (nSentSum < dwEncodedSize2)
	{
		DWORD nWill = dwEncodedSize2 - nSentSum;
		nWill = min(nWill, PACKSIZE - sizeof(PACKHEAD));

		head.nPartID++;
		memcpy(m_bufSend, &head, sizeof(PACKHEAD));
		memcpy(m_bufSend + sizeof(PACKHEAD), m_pBufEncode2 + nSentSum, nWill);

		DWORD nSent = ::sendto(m_hSock, (char *)m_bufSend,
			nWill + sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
		if (nSent > 0)
		{
			nSentSum += (nSent - sizeof(PACKHEAD));
		}
		else
		{
			TRACE("发送第 %d 帧 的 第 %d of %d 部分时出错, 错误代码为: %d",
				head.nFrame, head.nPartID, head.nPartCnt, GetLastError());
			break;
		}
		TRACE("Frame %d : Part %d of %d\r\n", head.nFrame, head.nPartID, head.nPartCnt);
	}

	//8. 延时(最多10帧/s = 1000 / 100)
	::GetLocalTime(&tm1);
	int ms = 1000 * (tm1.wSecond - tm0.wSecond) + (tm1.wMilliseconds - tm0.wMilliseconds);
	if (ms < 100 && ms > 0)	//重大bug修正: 要加上 && ms > 0, 否则当ms < 0时, 延时会非常久，用户感觉是死机了
		::Sleep(100 - ms);
}
