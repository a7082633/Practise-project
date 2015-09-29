// MFC_Broadcast_ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Broadcast_Client.h"
#include "MFC_Broadcast_ClientDlg.h"

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
// CMFC_Broadcast_ClientDlg dialog

CMFC_Broadcast_ClientDlg::CMFC_Broadcast_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_Broadcast_ClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_Broadcast_ClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_TrayhIcon = AfxGetApp()->LoadIcon(IDI_ICN_TRAY);
	m_pBufMemNow1=NULL;
	m_pBufMemNow2=NULL;
	m_pBufMemOld=NULL;
}

void CMFC_Broadcast_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_Broadcast_ClientDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_Broadcast_ClientDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_Broadcast_ClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ACCEPTB, OnBtnAcceptb)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDC_MENU_EXIT, OnMenuExit)
	ON_MESSAGE(UM_TRAY_NOTIFY,OnTrayNotify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ClientDlg message handlers

BOOL CMFC_Broadcast_ClientDlg::OnInitDialog()
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
	::SetWindowLong(m_hWnd, GWL_STYLE, WS_POPUP);
	// TODO: Add extra initialization here
	//检测程序是否多开
	HANDLE hMutex = CreateMutex(NULL, FALSE, "CLIENT"); //创建互斥体
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		// 如果已有互斥量存在则释放句柄并复位互斥量
		CloseHandle(hMutex);
		hMutex = NULL;
		AfxMessageBox("程序已经启动！");
		// 程序退出
		exit(0);
		ExitProcess(0);
		PostQuitMessage(0);//会启动然后再关闭
	}
	//初始化套接字
	m_hSocketC=socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(7788);
	addr.sin_addr.S_un.S_addr=0;
	bind(m_hSocketC,(SOCKADDR *)&addr,16);
	BOOL optval; 
	optval=TRUE;
	setsockopt(m_hSocketC,SOL_SOCKET,SO_BROADCAST,(char FAR *)&optval,sizeof(optval));
	int nSendBuf=PACKSIZE*10;//设置为80K
	setsockopt(m_hSocketC,SOL_SOCKET,SO_SNDBUF,(const char*)&nSendBuf,sizeof(int));

	memset(&m_biScreen,0,sizeof(BITMAPINFO));

	LONG style=::GetWindowLong(m_hWnd,GWL_STYLE); 
	style&=~WS_CAPTION; 
	::SetWindowLong(m_hWnd,GWL_STYLE,style); 

	IsInitialAll=FALSE; //初始化DC还有位图标记

	TrayAdd(); //添加托盘

	m_TMenu.LoadMenu(IDR_MENU1); //加载菜单

	//发上线通知 //PH_USER_OFFLINE
	PACKHEAD ph={0};
	ph.nFlag=PH_USER_ONLINE;
	SOCKADDR_IN m_addrTo={0};
	m_addrTo.sin_family = AF_INET;
	m_addrTo.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");//htonl(INADDR_BROADCAST); //设置ip为广播地址 即: 192.168.0.255
	m_addrTo.sin_port = htons(UDP_PORT);
	int n=::sendto(m_hSocketC, (char *)&ph,sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));

	::CreateThread(NULL,0,ReceiveThread,this,0,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_Broadcast_ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_Broadcast_ClientDlg::OnPaint() 
{
	CClientDC dc(this); // device context for painting
	//CPaintDC dc(this); // device context for painting
	//2. 获取当前绘图区的宽度和高度
	int nWidth = dc.GetDeviceCaps(HORZRES);
	int nHeight= dc.GetDeviceCaps(VERTRES);	
	dc.BitBlt(0, 0, nWidth, nHeight, &m_dcMemOld, 0, 0, SRCCOPY);
	//dc.StretchBlt(0,0,nWidth,nHeight,&m_dcMemOld,0,0,m_biScreen.bmiHeader.biWidth,m_biScreen.bmiHeader.biHeight,SRCCOPY);
	CDialog::OnPaint();
//	dc.Ellipse(0,0,50,50);
//	if (IsIconic())
//	{
//		CPaintDC dc(this); // device context for painting
//
//		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
//
//		// Center icon in client rectangle
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// Draw the icon
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//	{
////		CPaintDC dc(this);
////		int nWidth = dc.GetDeviceCaps(HORZRES);
////		int nHeight= dc.GetDeviceCaps(VERTRES);	
////		dc.BitBlt(0, 0, nWidth, nHeight, &m_dcMemNow, 0, 0, SRCCOPY);
//		CDialog::OnPaint();
//	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_Broadcast_ClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_Broadcast_ClientDlg::OnBtnAcceptb() 
{
	::CreateThread(NULL,0,ReceiveThread,this,0,NULL);
}


DWORD WINAPI CMFC_Broadcast_ClientDlg::ReceiveThread(LPVOID p)
{
	CMFC_Broadcast_ClientDlg *pDlg=(CMFC_Broadcast_ClientDlg *)p;
	while(1)
	{
		pDlg->DoReceivBroadCast();
	}
	return 0;
}

void CMFC_Broadcast_ClientDlg::DoReceive()
{

	//检测是否隐藏了窗口
	if(!IsWindowVisible())
	{
		SetForegroundWindow();
		ShowWindow(SW_MAXIMIZE);
	}
	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocketC, (char *)m_bufRecv, PACKSIZE,0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}
	InitialAll();
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
		if (m_nFrame % 60 == 0)
		{
			m_dcMemOld.FillSolidRect(0, 0, w, h, 0x00000000);
		}

		//XOR还原
		m_dcMemOld.BitBlt(0, 0, w, h, &m_dcMemNow, 0, 0, SRCINVERT);

		this->Invalidate();
	}
}



BOOL CMFC_Broadcast_ClientDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_F2)
		{
			this->MessageBox("test");
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CMFC_Broadcast_ClientDlg::InitialAll()
{
	if (!IsInitialAll)	//只做一次
	{
		IsInitialAll = TRUE;
		
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


void CMFC_Broadcast_ClientDlg::DoReceivBroadCast()
{
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocketC, (char *)m_bufRecv, PACKSIZE,MSG_PEEK, (SOCKADDR *)&addrFrom, &nLen);
	PACKHEAD *pHead = (PACKHEAD *)m_bufRecv;
	switch(pHead->nFlag)
	{
	case PH_START_BROADCAST:
		DoStartRevBroad();
		break;
	case PH_SEND_FRAMEPART:
		DoReceive();
		break;
	case PH_STOP_BROADCAST:
		DoStopBroadCast();
		break;
	case PH_USER_OLTEST:
		DoReplyOL();
		break;
	case PH_USER_MSG:
		DoReVMSG();
		break;
	default:
		::recvfrom(m_hSocketC, (char *)m_bufRecv, PACKSIZE,0, (SOCKADDR *)&addrFrom, &nLen);
		break;
	}
}

void CMFC_Broadcast_ClientDlg::DoStartRevBroad()
{
	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocketC, (char *)m_bufRecv, PACKSIZE,
		0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}
	InitialAll();
}

void CMFC_Broadcast_ClientDlg::DoStopBroadCast()
{
	::Sleep(100);
	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocketC, (char *)m_bufRecv, PACKSIZE,
		0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}
	this->ShowWindow(SW_HIDE);
}

BOOL CMFC_Broadcast_ClientDlg::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;
}

void CMFC_Broadcast_ClientDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	this->SendMessage(WM_NCLBUTTONDOWN, HTCAPTION);
	CDialog::OnLButtonDown(nFlags, point);
}

void CMFC_Broadcast_ClientDlg::TrayAdd()
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,				//托盘号 
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		m_TrayhIcon,
		"迷你鸽子"
	};
	int iErr = Shell_NotifyIcon(NIM_ADD, &nid);
}

void CMFC_Broadcast_ClientDlg::TrayDelete()
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		m_TrayhIcon,
		"迷你鸽子"
	};
	int iErr = Shell_NotifyIcon(NIM_DELETE, &nid);
}
LRESULT CMFC_Broadcast_ClientDlg::OnTrayNotify(WPARAM uID, LPARAM lEvent)
{
	if(uID==100)
	{
		switch(lEvent)
		{
		case WM_RBUTTONDOWN:
			CPoint point;
			::GetCursorPos(&point);
			this->SetForegroundWindow();
			m_TMenu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
			break;
		}
	}
	return 0;
}
void CMFC_Broadcast_ClientDlg::OnMenuExit() 
{
	OnClose();
	//发送离线消息
	PACKHEAD ph={0};
	ph.nFlag=PH_USER_OFFLINE;
	SOCKADDR_IN m_addrTo={0};
	m_addrTo.sin_family = AF_INET;
	m_addrTo.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");//htonl(INADDR_BROADCAST); //设置ip为广播地址 即: 192.168.0.255
	m_addrTo.sin_port = htons(UDP_PORT);
	int n=::sendto(m_hSocketC, (char *)&ph,sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));

	TrayDelete();
	::closesocket(m_hSocketC);
	if(m_pBufMemNow1!=NULL) delete[]m_pBufMemNow1;
	if(m_pBufMemNow2!=NULL) delete[]m_pBufMemNow2;
	if(m_pBufMemOld!=NULL) delete[]m_pBufMemOld;
	m_dcMemNow.DeleteDC();
	m_bmpMemNow.DeleteObject();
	
	m_dcMemOld.DeleteDC();
	m_bmpMemOld.DeleteObject();
	::PostQuitMessage(0);
}

void CMFC_Broadcast_ClientDlg::DoReplyOL()
{
	::Sleep(100);
	//实际接收
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocketC, (char *)m_bufRecv, sizeof(PACKHEAD), 0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("接收错误, 错误代码为: %d\r\n", GetLastError());
		return;
	}

	//发送回复“我仍然在线”
	PACKHEAD ph={0};
	ph.nFlag=PH_USER_OLREPLY;
	int n=::sendto(m_hSocketC, (char *)&ph,sizeof(PACKHEAD), 0, (SOCKADDR *)&addrFrom, sizeof(SOCKADDR));
//	this->MessageBox("客户端在线");
}

void CMFC_Broadcast_ClientDlg::DoReVMSG()
{
	char m_bufRecv[PACKSIZE]={0};
	SOCKADDR_IN addrFrom={0};
	int nLen=sizeof(SOCKADDR);
	::recvfrom(m_hSocketC, (char *)m_bufRecv, PACKSIZE,0, (SOCKADDR *)&addrFrom, &nLen);
	this->MessageBox(m_bufRecv+sizeof(PACKHEAD));
}
