// FgStudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FgStudent.h"
#include "FgStudentDlg.h"

#include "quicklz.h"
// Remember to define QLZ_COMPRESSION_LEVEL and QLZ_STREAMING_MODE to the same values for the compressor and decompressor

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

/////////////////////////////////////////////////////////////////////////////
// CFgStudentDlg dialog

CFgStudentDlg::CFgStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFgStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFgStudentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hThread = NULL;
	m_nFrame = 0;
	m_nPartCnt = 0;
	m_nPartID = 0;

	m_pBufEncode = NULL;
	m_pBufMemNow1 = NULL;
	m_pBufMemNow2 = NULL;
	m_pBufMemOld = NULL;

	m_bIsRunning = FALSE;
}

void CFgStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFgStudentDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFgStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CFgStudentDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCPAINT()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFgStudentDlg message handlers

void CFgStudentDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFgStudentDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFgStudentDlg::OnOK() 
{
//	CDialog::OnOK();
}

void CFgStudentDlg::OnCancel()
{
	CDialog::OnCancel();
}

void CFgStudentDlg::OnPaint()
{
	CPaintDC dc(this);
	if (m_bIsRunning)
	{
		dc.BitBlt(0, 0, w, h, &m_dcMemOld, 0, 0, SRCCOPY);
		dc.SetBkMode(TRANSPARENT);
		dc.SetTextColor(RGB(234, 24, 234));
		dc.TextOut(10, 10, "Author QQ: 93506222");
	}
	
	CDialog::OnPaint();
}

BOOL CFgStudentDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;	//CDialog::OnEraseBkgnd(pDC);
}

void CFgStudentDlg::OnNcPaint()
{
	static int i = 2;
	if (i > 0)
	{
		i--;
	//	this->ShowWindow(SW_HIDE);
	}
}

BOOL CFgStudentDlg::OnInitDialog()
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
	//1. 去除主窗口的标题栏
	::SetWindowLong(m_hWnd, GWL_STYLE, WS_POPUP);

	//2. 创建套接字 并绑定
	m_hSock = ::socket(AF_INET, SOCK_DGRAM, 0);
    int nBufSize = PACKSIZE * 10;	//接收缓冲区设为80K, 但每次最多接收8K, 这样可以缓冲10次
	setsockopt(m_hSock, SOL_SOCKET, SO_RCVBUF, (char FAR *)&nBufSize, sizeof(nBufSize));

	SOCKADDR_IN addrThis = {0};
	addrThis.sin_family = AF_INET;
	addrThis.sin_port = htons(UDP_PORT);
	addrThis.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	int nCode = ::bind(m_hSock, (SOCKADDR *)&addrThis, sizeof(SOCKADDR));
	if (nCode != 0)
	{
		CString sMsg;
		sMsg.Format("绑定套接字失败, 错误代码为: %d", GetLastError());
		this->MessageBox(sMsg);
		CDialog::OnOK();
		return TRUE;
	}

	//3. 创建接收线程
	if (m_hThread == NULL)
	{
		m_hThread = ::CreateThread(NULL, 0, RecvProc, this, 0, NULL);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFgStudentDlg::OnDestroy()
{
	CDialog::OnDestroy();

	if (m_hThread)
	{
		::TerminateThread(m_hThread, 0);
		m_hThread = NULL;
	}
	::closesocket(m_hSock);

	//释放内存
	if (m_pBufMemNow1)
	{
		delete[] m_pBufMemNow1;
		m_pBufMemNow1 = NULL;
	}
	if (m_pBufMemNow2)
	{
		delete[] m_pBufMemNow2;
		m_pBufMemNow2 = NULL;
	}
	if (m_pBufMemOld)
	{
		delete[] m_pBufMemOld;
		m_pBufMemOld = NULL;
	}

	m_bmpMemNow.DeleteObject();
	m_bmpMemOld.DeleteObject();
}

DWORD WINAPI CFgStudentDlg::RecvProc(LPVOID p)
{
	::Sleep(100);
	CFgStudentDlg *pDlg = (CFgStudentDlg *)p;
	while (1)
	{
		pDlg->RecvScreen();
	}
	return 0;
}

void CFgStudentDlg::RecvScreen()
{
	//1. 假接收 MSG_PEEK
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSock, (char *)m_bufRecv, PACKSIZE,
		MSG_PEEK, (SOCKADDR *)&addrFrom, &nLen);

	if (nRecv == SOCKET_ERROR)
	{
		CString sMsg;
		sMsg.Format("接收错误, 错误代码为: %d", GetLastError());
		this->MessageBox(sMsg);
		return;
	}

	//2. 根据头部判断信息类型
	PACKHEAD *pHead = (PACKHEAD *)m_bufRecv;
	switch (pHead->nFlag)
	{
	case PH_START_BROADCAST:	//1教师端开始广播
		DoStartBroadcast();
		break;
	case PH_STOP_BROADCAST:		//2教师端停止广播
		DoStopBroadcast();
		break;
	case PH_SEND_FRAMEPART:		//3教师端发送帧Part
		DoRecvFramePart();
		break;
	}
}

//分配内存, 只做一次
void CFgStudentDlg::MallocMem()
{
	static BOOL bDone = FALSE;
	if (!bDone)	//只做一次
	{
		bDone = TRUE;

		//分配内存等
		PACKHEAD *pHead = (PACKHEAD *)m_bufRecv;
		w = pHead->biScreen.bmiHeader.biWidth;
		h = pHead->biScreen.bmiHeader.biHeight;
		m_biScreen = pHead->biScreen;
		m_nImageSize = pHead->biScreen.bmiHeader.biSizeImage;

		m_pBufMemNow1 = new BYTE[m_nImageSize];
		m_pBufMemNow2 = new BYTE[m_nImageSize];
		m_pBufMemOld = new BYTE[m_nImageSize];
		m_pBufEncode = NULL;

		//获取DC等
		m_pDC = CDC::FromHandle(::GetDC(this->m_hWnd));

		m_dcMemNow.CreateCompatibleDC(m_pDC);
		m_bmpMemNow.CreateCompatibleBitmap(m_pDC, w, h);
		m_dcMemNow.SelectObject(&m_bmpMemNow);

		m_dcMemOld.CreateCompatibleDC(m_pDC);
		m_bmpMemOld.CreateCompatibleBitmap(m_pDC, w, h);
		m_dcMemOld.SelectObject(&m_bmpMemOld);
	}
}

//1教师端开始广播
void CFgStudentDlg::DoStartBroadcast()
{
	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSock, (char *)m_bufRecv, PACKSIZE,
		0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}

	//分配内存
	MallocMem();

	//显示窗口
//	this->ShowWindow(MYSHOW);	//SW_MAXIMIZE  SW_SHOW
//	this->SetForegroundWindow();
//
//	this->ShowWindow(MYSHOW);	//SW_MAXIMIZE  SW_SHOW
//	this->SetForegroundWindow();

	m_bIsRunning = TRUE;
}

//2教师端停止广播
void CFgStudentDlg::DoStopBroadcast()
{
	m_bIsRunning = FALSE;

	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSock, (char *)m_bufRecv, PACKSIZE,
		0, (SOCKADDR *)&addrFrom, &nLen);

	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}

	//隐藏窗口
	this->ShowWindow(SW_HIDE);
}

#define AAAA GetLocalTime(&tma);
#define BBBB(s) GetLocalTime(&tmb);	ms = 1000 * (tmb.wSecond - tma.wSecond) + (tmb.wMilliseconds - tma.wMilliseconds);	TRACE("Frame %d  %s 耗时 %d\n", pHead->nFrame, s, ms);

BOOL CFgStudentDlg::IsWindowMaximize()
{
	return this->GetStyle() & WS_MAXIMIZE;
}

//3教师端发送帧Part
void CFgStudentDlg::DoRecvFramePart()
{
	//处理迟到的学生端
	if (IsWindowVisible() == FALSE/* || IsWindowMaximize() == FALSE*/)
	{
		MallocMem();

		//显示窗口
		this->ShowWindow(MYSHOW);	//SW_MAXIMIZE  SW_SHOW
		this->SetForegroundWindow();

		this->ShowWindow(MYSHOW);	//SW_MAXIMIZE  SW_SHOW
		this->SetForegroundWindow();

		m_bIsRunning = TRUE;
	}

	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSock, (char *)m_bufRecv, PACKSIZE,
		0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}

	//分析处理接收到的Part
	PACKHEAD *pHead = (PACKHEAD *)m_bufRecv;
	TRACE("Frame %d : Part %d of %d\r\n", pHead->nFrame, pHead->nPartID, pHead->nPartCnt);

	if (pHead->nPartID == 1)
	{
		m_nPartID = pHead->nPartID;
		m_nFrame = pHead->nFrame;
		m_nPartCnt = pHead->nPartCnt;

		int nSize = m_nPartCnt * (PACKSIZE - sizeof(PACKHEAD));
		if (m_pBufEncode) delete[] m_pBufEncode;
		m_pBufEncode = new BYTE[nSize];
		memset(m_pBufEncode, 0, nSize);

		memcpy(m_pBufEncode, m_bufRecv + sizeof(PACKHEAD), nRecv - sizeof(PACKHEAD));

		m_nReceivedSum = nRecv - sizeof(PACKHEAD);
	}
	else
	{
		if (pHead->nFrame != m_nFrame ||
			pHead->nPartCnt != m_nPartCnt ||
			pHead->nPartID != (m_nPartID + 1))
		{
			::Beep(123, 20);	//警告: 丢包了
			return;
		}

		m_nPartID = pHead->nPartID;
		m_nFrame = pHead->nFrame;
		m_nPartCnt = pHead->nPartCnt;

		memcpy(m_pBufEncode + m_nReceivedSum, m_bufRecv + sizeof(PACKHEAD), nRecv - sizeof(PACKHEAD));
		m_nReceivedSum += nRecv - sizeof(PACKHEAD);
	}

	//如果是最后一个Part, 则解压到m_pBufMemNow1
	if (pHead->nPartID == m_nPartCnt) 
	{
		qlz_state_decompress* qsd;
		
		//1次解压 m_pBufEncode --> m_pBufMemNow1
		memset(m_pBufMemNow1, 0, m_nImageSize);
		qsd = (qlz_state_decompress *)malloc(sizeof(qlz_state_decompress));
		qlz_decompress((char *)m_pBufEncode, (char *)m_pBufMemNow1, qsd);
		free(qsd);

		//2次解压 m_pBufMemNow1 --> m_pBufMemNow2
		memset(m_pBufMemNow2, 0, m_nImageSize);
		qsd = (qlz_state_decompress *)malloc(sizeof(qlz_state_decompress));
		qlz_decompress((char *)m_pBufMemNow1, (char *)m_pBufMemNow2, qsd);
		free(qsd);

		//将 m_pBufMemNow2 赋值给 m_dcMemNow, 这也将影响 m_bmpMemNow
		::SetDIBits(m_dcMemNow.m_hDC, (HBITMAP)m_bmpMemNow.m_hObject,
			0, h, m_pBufMemNow2, &m_biScreen, DIB_RGB_COLORS);

		//如果是完整帧，则将m_dcMemOld清零(黑屏)
		if (m_nFrame % 30 == 0)
		{
			m_dcMemOld.FillSolidRect(0, 0, w, h, 0x00000000);
		}

		//XOR还原
		m_dcMemOld.BitBlt(0, 0, w, h, &m_dcMemNow, 0, 0, SRCINVERT);

		this->Invalidate();
	}
}

BOOL CFgStudentDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	#if MYSHOW == SW_MAXIMIZE
	cs.style &= WS_MAXIMIZE;
	#endif

	return CDialog::PreCreateWindow(cs);
}

void CFgStudentDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	this->SendMessage(WM_NCLBUTTONDOWN, HTCAPTION);
	
	CDialog::OnLButtonDown(nFlags, point);
}
