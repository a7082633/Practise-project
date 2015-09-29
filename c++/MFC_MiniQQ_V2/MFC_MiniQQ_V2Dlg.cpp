// MFC_MiniQQ_V2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MiniQQ_V2.h"
#include "MFC_MiniQQ_V2Dlg.h"
#include "ChatDialog.h"
#include "ChatRoomDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct CTRMNODE
{
	char *p;
	void *socket;
	void *dlg;
	int len;
	int nRev;
};
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
// CMFC_MiniQQ_V2Dlg dialog

CMFC_MiniQQ_V2Dlg::CMFC_MiniQQ_V2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_MiniQQ_V2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_MiniQQ_V2Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	icon=::LoadIcon(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1));
}

void CMFC_MiniQQ_V2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_MiniQQ_V2Dlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_MiniQQ_V2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_MiniQQ_V2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_MESSAGE(UM_TRAY_NOTIFY,OnTrayNotify)
	ON_WM_CLOSE()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_JOINCHATRM, OnBtnJoinchatrm)
	ON_WM_MOVE()
	ON_COMMAND(IDR_SHOWWD, OnShowwd)
	ON_COMMAND(IDR_EXIT, OnExit)
	ON_BN_CLICKED(IDC_BTN_UPDATE, OnBtnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V2Dlg message handlers

BOOL CMFC_MiniQQ_V2Dlg::OnInitDialog()
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
	//this->ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);
	this->m_TMenu.LoadMenu(IDR_MENU);
	m_isHide=false;
	//////////////////////设置列表的属性
	m_imageList.Create(IDB_BITMAP1, 10, 1, RGB(0, 253, 0));
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.SetImageList(&m_imageList,LVSIL_SMALL);

	m_list.InsertColumn(0, "状态", LVCFMT_CENTER, 40);
	m_list.InsertColumn(1, "主机名", LVCFMT_LEFT, 75);
	m_list.InsertColumn(2, "IP地址", LVCFMT_LEFT, 100);
	//////////////////////初始化套接字
	m_socketTCP=::socket(AF_INET,SOCK_STREAM,0);
	int n=::WSAGetLastError();
	if (INVALID_SOCKET == m_socketTCP)
	{
		::AfxMessageBox("创建套接字失败！");
	}
	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=htons(7789);
	addr.sin_addr.S_un.S_addr=0;
	if(SOCKET_ERROR==bind(m_socketTCP,(SOCKADDR *)&addr,sizeof(SOCKADDR)))
	{
		::AfxMessageBox("绑定套接字失败");
	}
	if(SOCKET_ERROR==listen(m_socketTCP, 5))
	{
		::AfxMessageBox("监听失败！");
	}

	m_hSocket.Create(MESSAGEPORT,SOCK_DGRAM);
	m_hSocket.m_Param=this;
	//int timeout=1000;
	//m_hSocket.SetSockOpt(SO_SNDTIMEO,(char *)&timeout,sizeof(int));
	//m_hSocket.SetSockOpt(SO_RCVTIMEO,(char *)&timeout,sizeof(int));
	//////////////////////发上线通知/////////////////////
	MESSAGEHEAD msghead={0};
	msghead.flag=2;//上线
	int yes = 1;
	//setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST, (char *)&yes, sizeof(yes));
	m_hSocket.SetSockOpt(SO_BROADCAST,(char *)&yes,sizeof(yes),SOL_SOCKET);
	m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,CLASSBR);
	//////////////////////测试在线定时器////////////////////
	//this->SetTimer(110,3000,NULL);
	//////////////////////检测鼠标位置////////////////////
	this->SetTimer(110,100,NULL);
	//////////////////////测试////////////////////////////
//	m_list.InsertItem(0,"",0);
//	m_list.SetItemText(0,1,"无名一号");
//	m_list.SetItemText(0,2,"192.168.30.1");
//	//m_list.SetItem(0,0,RGB(0, 253, 0),"",1,0,0,0);
//
//	m_list.InsertItem(1,"",0);
//	m_list.SetItemText(1,1,"无名二号");
//	m_list.SetItemText(1,2,"192.168.0.2");
	////////////////////创建聊天室（隐藏）////////////////
	m_pChatRoom=new CChatRoomDialog;
	m_pChatRoom->Create(IDD_DIALOG_CHARROOM,this->GetDesktopWindow());
	m_pChatRoom->m_parent=this;
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_MiniQQ_V2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_MiniQQ_V2Dlg::OnPaint() 
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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_MiniQQ_V2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_MiniQQ_V2Dlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_hSocket.Close();
	CDialog::PostNcDestroy();
}

void CMFC_MiniQQ_V2Dlg::TrayAdd()
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,				//托盘号 
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		icon,
		"局域网传书"
	};
	int iErr = Shell_NotifyIcon(NIM_ADD, &nid);
}

void CMFC_MiniQQ_V2Dlg::TrayDelete()
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		icon,
		"局域网传书"
	};
	int iErr = Shell_NotifyIcon(NIM_DELETE, &nid);
}

int CMFC_MiniQQ_V2Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	//this->GetMenu()->RemoveMenu(0,MF_BYPOSITION);
	this->CenterWindow();
	CRect rt;
	this->GetWindowRect(&rt);
	w=rt.Width();
	h=rt.Height();
	TrayAdd();
	return 0;
}

void CMFC_MiniQQ_V2Dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	this->KillTimer(110);
	TrayDelete();
}

void CMFC_MiniQQ_V2Dlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if(nType==SIZE_MINIMIZED)
	{
		//this->MessageBox("aaa");
		this->KillTimer(110);
		this->ShowWindow(SW_HIDE);
	}
}
void CMFC_MiniQQ_V2Dlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	::closesocket(m_socketTCP);
	MESSAGEHEAD msghead={0};
	msghead.flag=1;//离线
	int yes = 1;
	//setsockopt(m_hSocket, SOL_SOCKET, SO_BROADCAST, (char *)&yes, sizeof(yes));
	m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,CLASSBR);
	::Sleep(1);
	this->CloseWindow();
	CDialog::OnClose();
}
LRESULT CMFC_MiniQQ_V2Dlg::OnTrayNotify(WPARAM uID, LPARAM lEvent)
{
	if(uID==100)
	{
		switch(lEvent)
		{
		case WM_LBUTTONDBLCLK:
			this->SetTimer(110,100,NULL);
			m_isHide=false;
			ShowWindow(SW_SHOWNOACTIVATE);
			SetForegroundWindow();
			this->SetWindowPos(NULL,m_rect.left,m_rect.top+1,w,h,SWP_SHOWWINDOW);
			break;
		case WM_RBUTTONDOWN:
			//m_TMenu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTBUTTON,0,0,this->GetDesktopWindow());
			CPoint point;
			::GetCursorPos(&point);
			this->SetForegroundWindow();
			m_TMenu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
			//this->GetMenu()->GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
			break;
		}
	}
	return 0;
}
void CMFC_MiniQQ_V2Dlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
//	LVNI_SELECTED;
//	m_list.GetSelectedCount();
//	m_list.GetNextSelectedItem();
	POSITION pos=m_list.GetFirstSelectedItemPosition();

	NMLISTVIEW * pNMListView = (NMLISTVIEW*)pNMHDR;
	int nItem = pNMListView->iItem;
	if (nItem == -1) return;
	CString hostname=m_list.GetItemText(nItem,1);
	CString ip=m_list.GetItemText(nItem,2);


	for(int i=0;i<m_wndArray.GetSize();i++)//检测是否有重复窗口
	{
		CChatDialog *p=(CChatDialog *)m_wndArray.GetAt(i);
		if(p->m_sIP==ip)
		{
			p->ShowWindow(SW_SHOW);
			p->SetForegroundWindow();
			return;
		}
	}
	CChatDialog *p=new CChatDialog;
	m_wndArray.Add(p);
	p->Create(IDD_DIALOG_CHAT,this->GetDesktopWindow());
	p->SetWindowText("你正在与["+hostname+"]聊天");
	p->ShowWindow(SW_SHOW);
	p->m_sIP=ip;
	p->m_sName=hostname;
	p->m_parent=this;
	*pResult = 0;
}


DWORD WINAPI SendFileThread(LPVOID p)
{
	CChatDialog *pChat=(CChatDialog *)p;

	SOCKET m_hSocketC = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == m_hSocketC)
	{
		::AfxMessageBox("创建套接字失败！\n");
	}
	//指明服务器
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=htons(7789);
	skaddr.sin_addr.s_addr=inet_addr(pChat->m_sIP);         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	while(SOCKET_ERROR==connect(m_hSocketC,(SOCKADDR *)&skaddr,sizeof(SOCKADDR_IN)))
	{
		//pChat->MessageBox("连接失败!");
	}
	pChat->MessageBox("连接成功!");
	FILEHEAD fh={0};
	CFile file(pChat->FilePath,CFile::typeBinary |CFile::modeRead |CFile::shareDenyRead);
	fh.FileLen=file.GetLength();
	strcpy(fh.FileName,file.GetFileName());
	DWORD nSend=::send(m_hSocketC,(char *)&fh,sizeof(FILEHEAD),0);//SOCKET_ERROR WSAENETDOWN
	int err=WSAGetLastError();
	if(nSend<0)
		pChat->MessageBox("发送文件信息头失败");
	DWORD nSent=0;
	DWORD nRead=0;
	CString s;
	s.Format("正在发送文件:%s",fh.FileName);
	pChat->SetDlgItemText(IDC_EDIT_SELECT,s);
	char buf[1024]={0};
	while((nRead=file.Read(buf,1024))>0)
	{
		int n=::send(m_hSocketC,buf,nRead,0);
		nSent+=n;
		int progress=nSent*1.0/fh.FileLen*100;
		pChat->m_progress.SetPos(progress);
	}
	pChat->m_progress.SetPos(0);
	pChat->FilePath="";
	pChat->SetDlgItemText(IDC_EDIT_SELECT,"发送完毕!");
	file.Close();
	::closesocket(m_hSocketC);
	return 0;
}


void CMFC_MiniQQ_V2Dlg::DoReceive()//接收信息头
{ 
	//SOCKET_ERROR  WSAENETDOWN
	MESSAGEHEAD msghead={0};
	CString addrFrom;
	UINT port=MESSAGEPORT;
	int iMsgHead=this->m_hSocket.ReceiveFrom(&msghead,sizeof(MESSAGEHEAD),addrFrom,port);
	switch(msghead.flag)
	{
	case 1://收到离线通知
		DoOffLine(addrFrom);
		break;
	case 2://收到上线通知
		//this->MessageBox("online");
		DoOnline(addrFrom);
		break;
	case 32://收到返回上线通知
		DoRevOnline(addrFrom);
		break;
	case 37://接到回发的测试在线
		{
			HOSTENT *pHost=new HOSTENT;
			in_addr ina;
			ina.S_un.S_addr = inet_addr(addrFrom); 
			pHost=::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
			int n=m_list.GetItemCount();
			m_list.InsertItem(n,"",0);
			m_list.SetItemText(n,1,pHost->h_name);
			m_list.SetItemText(n,2,addrFrom);
		}
		break;
	case 4://收到单聊消息
		DoRevSgMsg(msghead);
		break;
	case 6://收到群聊信息
		DoRevRmMsg(addrFrom,msghead);
		break;
	case 7://接到测试在线
		{
			MESSAGEHEAD msghead={0};
			msghead.flag=37;
			this->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,addrFrom);
		}
		break;
	case 8: //收到文件消息
		DoRevFileMsg(addrFrom);
		break;
	case 81://同意接收文件
		DoRevFile(addrFrom);
		break;
	case 82://拒绝接收文件
		DoRevReject(addrFrom);
		break;
	}
}





void CMFC_MiniQQ_V2Dlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CMFC_MiniQQ_V2Dlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CMFC_MiniQQ_V2Dlg::OnTimer(UINT nIDEvent) 
{
	CRect rt;
	this->GetWindowRect(&rt);
	CPoint pt;
	::GetCursorPos(&pt);
	if(rt.top<=0&&!m_isHide)
	{
		if(pt.x>rt.right||pt.x<rt.left||pt.y>rt.bottom)
		{
			m_isHide=true;
			m_rect=rt;
			this->SetWindowPos(NULL,rt.left,0,rt.Width(),1,SWP_SHOWWINDOW);
		}
	}
	if(rt.top<=0&&m_isHide)
	{
		if(pt.y<=0)
		{
			CString s2;
			s2.Format("坐标y:%d  坐标x:%d  rt.right:%d  rt.left:%d  rt.bottom:%d",pt.y,pt.x,m_rect.right,m_rect.left,m_rect.bottom);
			//this->MessageBox(s2);
			if(pt.x<m_rect.right&&pt.x>m_rect.left&&pt.y<=m_rect.bottom)
			{
				//this->MessageBox("ok");
				m_isHide=false;
				this->SetWindowPos(NULL,m_rect.left,m_rect.top,m_rect.Width(),h,SWP_SHOWWINDOW);
			
			}
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CMFC_MiniQQ_V2Dlg::OnBtnJoinchatrm() 
{
	if(!m_pChatRoom->IsWindowVisible())
		this->m_pChatRoom->ShowWindow(SW_SHOW);
}

void CMFC_MiniQQ_V2Dlg::DoOnline(CString &addrFrom)
{
	for(int i=0;i<m_list.GetItemCount();i++)
		if(m_list.GetItemText(i,2)==addrFrom) 
		{
			MESSAGEHEAD msghead={0};
			msghead.flag=32;
			this->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,addrFrom);
			return;
		}
		HOSTENT pHost;
		in_addr ina;
		ina.S_un.S_addr = inet_addr(addrFrom); 
		pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
		int n=m_list.GetItemCount();
		m_list.InsertItem(n,"",0);
		m_list.SetItemText(n,1,pHost.h_name);
		m_list.SetItemText(n,2,addrFrom);
		/////////////////返回上线通知
		MESSAGEHEAD msghead={0};
		msghead.flag=32;
		this->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,addrFrom);
}

void CMFC_MiniQQ_V2Dlg::DoRevOnline(CString &addrFrom)
{
	for(int i=0;i<m_list.GetItemCount();i++)
		if(m_list.GetItemText(i,2)==addrFrom) 	return;
	HOSTENT *pHost;
	in_addr ina;
	ina.S_un.S_addr = inet_addr(addrFrom); 
	pHost=::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
	int n=m_list.GetItemCount();
	m_list.InsertItem(n,"",0);
	m_list.SetItemText(n,1,pHost->h_name);
	m_list.SetItemText(n,2,addrFrom);
}

void CMFC_MiniQQ_V2Dlg::DoRevSgMsg(MESSAGEHEAD &msghead)
{
	//this->MessageBox("你有消息，是否打开聊天窗！");
	char *p=new char[msghead.iMsgLen+1];
	memset(p,0,msghead.iMsgLen+1);
	CString addrFrom;
	UINT port=MESSAGEPORT;
	int nRev=m_hSocket.ReceiveFrom(p,msghead.iMsgLen+1,addrFrom,port);
	if(nRev<0)
		this->MessageBox("接受单聊信息失败！");
	else
	{
		for(int i=0;i<m_wndArray.GetSize();i++)
		{
			CChatDialog *pChat=(CChatDialog *)m_wndArray.GetAt(i);
			if(pChat->m_sIP==addrFrom)
			{
				CString s;
				s.Format("[%s]说:%s",pChat->m_sName,p);
				pChat->m_list.AddString(s);
				pChat->m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
				
				if(!pChat->IsWindowVisible())//判断窗口是否隐藏
					pChat->ShowWindow(SW_SHOW);
				return;
			}
		}
		//强制打开窗口
		HOSTENT pHost;
		in_addr ina;
		ina.S_un.S_addr = inet_addr(addrFrom); 
		pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
		
		CChatDialog *pDlg=new CChatDialog;
		m_wndArray.Add(pDlg);
		pDlg->Create(IDD_DIALOG_CHAT,this->GetDesktopWindow());
		CString s;
		s.Format("你正在与[%s]聊天",pHost.h_name);
		pDlg->SetWindowText(s);
		pDlg->ShowWindow(SW_SHOW);
		pDlg->m_sIP=addrFrom;
		pDlg->m_sName=pHost.h_name;
		pDlg->m_parent=this;
		
		
		CString s2;
		s2.Format("[%s]说:%s",pHost.h_name,p);
		pDlg->m_list.AddString(s2);
		pDlg->m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
	}
	delete []p;
}

void CMFC_MiniQQ_V2Dlg::DoRevRmMsg(CString &addrFrom2, MESSAGEHEAD &msghead)
{
	//获取本机名
	char HostName[20]={0};
	::gethostname(HostName,sizeof(HostName));
	//获取信息源主机名
//	HOSTENT pHost;
//	in_addr ina;
//	ina.S_un.S_addr = inet_addr(addrFrom2); 
//	pHost=*gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);//罪魁祸首
//	if(strcmp(HostName,pHost.h_name)==0)
//		return;

	CString sOrigName;
	for(int i=0;i<m_list.GetItemCount();i++)
		if(m_list.GetItemText(i,2)==addrFrom2)
		{
			sOrigName=m_list.GetItemText(i,1);
		}

	char *p=new char[msghead.iMsgLen+1];
	memset(p,0,msghead.iMsgLen+1);
	CString addrFrom;
	UINT port=MESSAGEPORT;
	
	int nRev=m_hSocket.ReceiveFrom(p,msghead.iMsgLen,addrFrom,port);
	if(nRev>0)
	{
		CString s;
//		HOSTENT pHost;
//		in_addr ina;
//		ina.S_un.S_addr = inet_addr(addrFrom); 
//		pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);//罪魁祸首
		s.Format("%s说:%s",sOrigName,p);
		this->m_pChatRoom->m_list.AddString(s);
		this->m_pChatRoom->m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
	}
	delete []p;
}

void CMFC_MiniQQ_V2Dlg::DoRevFileMsg(CString &addrFrom)
{
	for(int i=0;i<m_wndArray.GetSize();i++)
	{
		CChatDialog *pChat=(CChatDialog *)m_wndArray.GetAt(i);
		if(pChat->m_sIP==addrFrom)
		{	
			pChat->m_btnbrowser.ShowWindow(SW_HIDE);
			pChat->m_btnsentf.ShowWindow(SW_HIDE);
			pChat->m_btnaccept.ShowWindow(SW_SHOW);
			pChat->m_btnreject.ShowWindow(SW_SHOW);
			HOSTENT pHost;
			in_addr ina;
			ina.S_un.S_addr = inet_addr(addrFrom); 
			pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
			CString s2;
			s2.Format("系统消息:[%s]给你发送了文件!",pHost.h_name);
			pChat->m_list.AddString(s2);
			pChat->m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
			if(!pChat->IsWindowVisible())//判断窗口是否隐藏
			{
				pChat->ShowWindow(SW_SHOW);
			}
			return;
		}
	}
	//强制打开窗口
	HOSTENT pHost;
	in_addr ina;
	ina.S_un.S_addr = inet_addr(addrFrom); 
	pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
	
	CChatDialog *pDlg=new CChatDialog;
	m_wndArray.Add(pDlg);
	pDlg->Create(IDD_DIALOG_CHAT,this->GetDesktopWindow());
	CString s;
	s.Format("你正在与[%s]聊天",pHost.h_name);
	pDlg->SetWindowText(s);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->m_sIP=addrFrom;
	pDlg->m_sName=pHost.h_name;
	pDlg->m_parent=this;
	//::Sleep(1000);
	pDlg->m_btnaccept.ShowWindow(SW_SHOW);
	pDlg->m_btnreject.ShowWindow(SW_SHOW);
	pDlg->m_btnbrowser.ShowWindow(SW_HIDE);
	pDlg->m_btnsentf.ShowWindow(SW_HIDE);
	
	CString s2;
	s2.Format("系统消息:[%s]给你发送了文件!",pHost.h_name);
	pDlg->m_list.AddString(s2);
	pDlg->m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
}

void CMFC_MiniQQ_V2Dlg::DoRevFile(CString &addrFrom)
{
	for (int i = 0;i < m_wndArray.GetSize();i++)
	{
		CChatDialog * pChat = (CChatDialog *)m_wndArray.GetAt(i);
		if (pChat->m_sIP == addrFrom)
		{
			::CreateThread(NULL, 0, SendFileThread,pChat, 0, NULL);
			CString s2;
			s2.Format("系统消息:对方已同意接受文件!");
			pChat->m_list.AddString(s2);
			pChat->m_list.PostMessage(WM_VSCROLL, SB_BOTTOM);
			return;
		}
	}
}

void CMFC_MiniQQ_V2Dlg::DoOffLine(CString &addrFrom)
{
	int n=m_list.GetItemCount();
	for(int i=0;i<n;i++)
	{
		CString s=m_list.GetItemText(i,2);
		if(s==addrFrom)
		{
			m_list.DeleteItem(i);
			break;
		}
	}
}



void CMFC_MiniQQ_V2Dlg::OnMove(int x, int y) 
{
	this->GetWindowRect(&m_rect);
	m_isHide=false;
	this->SetWindowPos(NULL,m_rect.left,m_rect.top,m_rect.Width(),400,SWP_SHOWWINDOW);
	CDialog::OnMove(x, y);	
}

BOOL CMFC_MiniQQ_V2Dlg::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CDialog::PreCreateWindow(cs);
}

void CMFC_MiniQQ_V2Dlg::OnShowwd() 
{
	this->SetTimer(110,100,NULL);
	m_isHide=false;
	ShowWindow(SW_SHOWNOACTIVATE);
	SetForegroundWindow();
	this->SetWindowPos(NULL,m_rect.left,m_rect.top+1,w,h,SWP_SHOWWINDOW);
}

void CMFC_MiniQQ_V2Dlg::OnExit() 
{
	OnClose();
	::PostQuitMessage(0);
}

void CMFC_MiniQQ_V2Dlg::DoRevReject(CString &addrFrom)
{
	for (int i = 0;i < m_wndArray.GetSize();i++)
	{
		CChatDialog * pChat = (CChatDialog *)m_wndArray.GetAt(i);
		if (pChat->m_sIP == addrFrom)
		{
			CString s2;
			s2.Format("系统消息:对方拒绝接受文件!");
			pChat->m_list.AddString(s2);
			pChat->m_list.PostMessage(WM_VSCROLL, SB_BOTTOM);
			return;
		}
	}
}

void CMFC_MiniQQ_V2Dlg::OnBtnUpdate() 
{
	int n=m_list.GetItemCount();
	MESSAGEHEAD msghead={0};
	msghead.flag=7;

//	char HostName[20]={0};
//	::gethostname(HostName,sizeof(HostName));
//	for(int i=0;i<n;i++)
//	{
//		if(HostName==m_list.GetItemText(i,1)) continue;
//		this->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,m_list.GetItemText(i,2));
//	}
	this->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,CLASSBR);
	m_list.DeleteAllItems();
}
