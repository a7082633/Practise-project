// MFC_Broadcast_ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Broadcast_Server.h"
#include "MFC_Broadcast_ServerDlg.h"
#include "DialogSendMSG.h"
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
// CMFC_Broadcast_ServerDlg dialog

CMFC_Broadcast_ServerDlg::CMFC_Broadcast_ServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_Broadcast_ServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_Broadcast_ServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Broadcast_ServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_Broadcast_ServerDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_Broadcast_ServerDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_Broadcast_ServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTB_START, OnBtbStart)
	ON_BN_CLICKED(IDC_BTB_STOP, OnBtbStop)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_FLUSH, OnBtnFlush)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList)
	ON_COMMAND(IDC_MENU_SENDMSG, OnMenuSendmsg)
	ON_COMMAND(IDC_MENU_SEESCREEN, OnMenuSeescreen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ServerDlg message handlers

BOOL CMFC_Broadcast_ServerDlg::OnInitDialog()
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
	//�������Ƿ�࿪
	HANDLE hMutex = CreateMutex(NULL, FALSE, "SERVER"); //����������
	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		// ������л������������ͷž������λ������
		CloseHandle(hMutex);
		hMutex = NULL;
		AfxMessageBox("�����Ѿ�������");
		// �����˳�
		exit(0);
		ExitProcess(0);
		PostQuitMessage(0);//������Ȼ���ٹر�
	}
	//���ز˵�
	m_LRMenu.LoadMenu(IDR_MENU_LIST);
	//��ʼ��List
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, "������", LVCFMT_LEFT, 75);
	m_list.InsertColumn(1, "IP��ַ", LVCFMT_LEFT, 110);
	//��ʼ���׽���
	m_hSocket=::socket(AF_INET,SOCK_DGRAM,0);
	SOCKADDR_IN in={0};
	in.sin_addr.S_un.S_addr=0;
	in.sin_family=AF_INET;
	in.sin_port=htons(7788);
	::bind(m_hSocket,(SOCKADDR *)&in,16);
	bool opt=true;   //���ø��׽���Ϊ�㲥���ͣ�   
	setsockopt(m_hSocket,SOL_SOCKET,SO_BROADCAST,(char FAR *)&opt,sizeof(opt));
	int nSendBuf=PACKSIZE*10;//����Ϊ80K
	setsockopt(m_hSocket,SOL_SOCKET,SO_SNDBUF,(const char*)&nSendBuf,sizeof(int));
	setsockopt(m_hSocket,SOL_SOCKET,SO_RCVBUF,(const char*)&nSendBuf,sizeof(int));
	//��ȡ��Ļ��С��px��
	m_hDcScreen=CDC::FromHandle(::GetDC(NULL));
	m_Screenw=m_hDcScreen->GetDeviceCaps(HORZRES);
	m_Screenh=m_hDcScreen->GetDeviceCaps(VERTRES);
	//��ʼ��λͼ��Ϣͷ
	DWORD nImageSize = m_Screenw * m_Screenh * 2;
	memset(&m_biScreen,0,sizeof(m_biScreen));
	m_biScreen.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_biScreen.bmiHeader.biWidth = m_Screenw;
	m_biScreen.bmiHeader.biHeight = m_Screenh;
	m_biScreen.bmiHeader.biBitCount = 16;
	m_biScreen.bmiHeader.biCompression = BI_RGB;
	m_biScreen.bmiHeader.biPlanes = 1;
	m_biScreen.bmiHeader.biSizeImage = nImageSize;
	//��ȡ��Ļ������
	m_bmpMemNow.CreateCompatibleBitmap(m_hDcScreen, m_Screenw, m_Screenh);
	m_dcMemNow.CreateCompatibleDC(m_hDcScreen);
	m_dcMemNow.SelectObject(&m_bmpMemNow);

	m_bmpMemOld.CreateCompatibleBitmap(m_hDcScreen, m_Screenw, m_Screenh);
	m_dcMemOld.CreateCompatibleDC(m_hDcScreen);
	m_dcMemOld.SelectObject(&m_bmpMemOld);

	m_pBufScreen=new BYTE[nImageSize];
	memset(m_pBufScreen, 0,m_biScreen.bmiHeader.biSizeImage);

	m_pBufEncode1 = new BYTE[m_biScreen.bmiHeader.biSizeImage];
	memset(m_pBufEncode1, 0, m_biScreen.bmiHeader.biSizeImage);

	m_pBufEncode2 = new BYTE[m_biScreen.bmiHeader.biSizeImage];
	memset(m_pBufEncode2, 0,m_biScreen.bmiHeader.biSizeImage);

	memset(&m_addrTo, 0, sizeof(SOCKADDR_IN));
	m_addrTo.sin_family = AF_INET;
	m_addrTo.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");//htonl(INADDR_BROADCAST); //����ipΪ�㲥��ַ ��: 192.168.0.255
	m_addrTo.sin_port = htons(UDP_PORT);  

	m_hThread=NULL;

	m_hThreadRev=::CreateThread(NULL,0,ReceiveThread,this,0,NULL); //���������߳�
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_Broadcast_ServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_Broadcast_ServerDlg::OnPaint() 
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
HCURSOR CMFC_Broadcast_ServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CMFC_Broadcast_ServerDlg::OnBtbStart() 
{
	// ֪ͨѧ���˴򿪴��ڣ�׼����ʼ����
	PACKHEAD head = {0};
	head.nFlag = PH_START_BROADCAST;		//1��ʼ�㲥
	head.biScreen = m_biScreen;

	memset(m_bufSend, 0, PACKSIZE);
	memcpy(m_bufSend, &head, sizeof(PACKHEAD));

	int nSent = ::sendto(m_hSocket, (char *)m_bufSend, PACKSIZE, 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
	if (nSent == SOCKET_ERROR)
	{
		CString sMsg;
		sMsg.Format("���ܿ�ʼ�㲥, �������Ϊ: %d", GetLastError());
		this->MessageBox(sMsg);
		return;
	}
	::Sleep(100);

	if(m_hThread==NULL)
	{
		m_hThread=::CreateThread(NULL,0,SendThread,this,0,NULL);
		IsThreadRuning=TRUE;
	}
	else
	{
		if(IsThreadRuning==FALSE)
		{
			::ResumeThread(m_hThread);
			IsThreadRuning=TRUE;
		}
	}


}

DWORD WINAPI CMFC_Broadcast_ServerDlg::SendThread(LPVOID p)
{
	CMFC_Broadcast_ServerDlg *pDlg=(CMFC_Broadcast_ServerDlg *)p;
	while(1)
	{
		pDlg->DoSend();
	}
	::Sleep(10);
	return 0;
}

void CMFC_Broadcast_ServerDlg::DoSend()
{
	SYSTEMTIME tm0, tm1;
	::GetLocalTime(&tm0);
	//��ȡ��Ļ
	m_dcMemNow.BitBlt(0, 0, m_Screenw, m_Screenh, m_hDcScreen, 0, 0, SRCCOPY);//��ȡ��Ļλͼ
	
	//�������
	CURSORINFO ci = {0};
	ci.cbSize = sizeof(CURSORINFO);
	GetCursorInfo(&ci);
	ICONINFO ii = {0};
	GetIconInfo(ci.hCursor, &ii);
	m_dcMemNow.DrawIcon(ci.ptScreenPos.x-ii.xHotspot, ci.ptScreenPos.y-ii.yHotspot, ci.hCursor);
	::DeleteObject(ii.hbmColor);
	::DeleteObject(ii.hbmMask);
	
	//ÿ30֡������֡
	static UINT nFrame = -1;
	nFrame++;
	if (nFrame % 60 == 0)	//ÿ��30֡�ʹ�һ������֡��ѧ����
	{
		m_dcMemOld.FillSolidRect(0, 0,m_Screenw,m_Screenh, 0x00000000);	//��ɫ
	}
	//�� ��ǰ�� �� ��һ�� �������, �������m_dcMemOld��m_bmpMemOld��
	//  ��ʱ��m_dcMemOld�б������ǵ�ǰͼ���Ϸ�ͼ��ͬ�Ĳ���, ��ͬ����ȫ����0
	//m_dcMemOld.BitBlt(0, 0,m_Screenw,m_Screenh, &m_dcMemNow, 0, 0, SRCCOPY);
	m_dcMemOld.BitBlt(0, 0,m_Screenw,m_Screenh, &m_dcMemNow, 0, 0,SRCINVERT);
	
	//�����֮���λͼ���ݱ��浽��Ļ����m_pBufScreen
	GetDIBits(m_dcMemOld,m_bmpMemOld,0,m_Screenh,m_pBufScreen,(LPBITMAPINFO)&m_biScreen,DIB_RGB_COLORS);
	
	//���浱ǰ����m_pDCMemOld
	m_dcMemOld.BitBlt(0, 0,m_Screenw,m_Screenh, &m_dcMemNow, 0, 0, SRCCOPY);

	//ѹ������
	//1��ѹ�� m_pBufNow --> m_pBufEncode1
	qlz_state_compress *qsc = NULL;
	memset(m_pBufEncode1, 0,m_biScreen.bmiHeader.biSizeImage);
	qsc = (qlz_state_compress *)malloc(sizeof(qlz_state_compress));
	DWORD dwEncodedSize1 = qlz_compress((char*)m_pBufScreen, (char*)m_pBufEncode1,m_biScreen.bmiHeader.biSizeImage, qsc);
	free(qsc);
	
	//2��ѹ�� m_pBufEncode1 --> m_pBufEncode2
	memset(m_pBufEncode2, 0, m_biScreen.bmiHeader.biSizeImage);
	qsc = (qlz_state_compress *)malloc(sizeof(qlz_state_compress));
	DWORD dwEncodedSize2 = qlz_compress((char*)m_pBufEncode1, (char*)m_pBufEncode2,dwEncodedSize1, qsc);
	free(qsc);
	//������Ϣͷ
	PACKHEAD head = {0};	//3����֡PACKSIZE =32768
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
		
		DWORD nSent = ::sendto(m_hSocket, (char *)m_bufSend,
			nWill + sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
		::Sleep(5);
		if (nSent > 0)
		{
			nSentSum += (nSent - sizeof(PACKHEAD));
		}
		else
		{
			TRACE("���͵� %d ֡ �� �� %d of %d ����ʱ����, �������Ϊ: %d",
				head.nFrame, head.nPartID, head.nPartCnt, GetLastError());
			break;
		}
		TRACE("Frame %d : Part %d of %d\r\n", head.nFrame, head.nPartID, head.nPartCnt);
	}
	//8. ��ʱ(���10֡/s = 1000 / 100)
	::GetLocalTime(&tm1);
	int ms = 1000 * (tm1.wSecond - tm0.wSecond) + (tm1.wMilliseconds - tm0.wMilliseconds);
	if (ms < 100 && ms > 0)	//�ش�bug����: Ҫ���� && ms > 0, ����ms < 0ʱ, ��ʱ��ǳ��ã��û��о���������
		::Sleep(100 - ms);
}

void CMFC_Broadcast_ServerDlg::OnBtbStop() 
{
	// ֪ͨѧ�������ش���
	PACKHEAD head = {0};
	head.nFlag = PH_STOP_BROADCAST;		//ֹͣ�㲥

	memset(m_bufSend, 0, PACKSIZE);
	memcpy(m_bufSend, &head, sizeof(PACKHEAD));

	int nSent = ::sendto(m_hSocket, (char *)m_bufSend, PACKSIZE, 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
	if (nSent == SOCKET_ERROR)
	{
		CString sMsg;
		sMsg.Format("���ܿ�ʼ�㲥, �������Ϊ: %d", GetLastError());
		this->MessageBox(sMsg);
		return;
	}
	::Sleep(10);

	if(IsThreadRuning==TRUE)
	{
		::SuspendThread(m_hThread);
		IsThreadRuning=FALSE;
	}
}

DWORD WINAPI CMFC_Broadcast_ServerDlg::ReceiveThread(LPVOID p)
{
	CMFC_Broadcast_ServerDlg *pDlg=(CMFC_Broadcast_ServerDlg *)p;
	while(1)
	{
		pDlg->DoReceive();
	}
	return 0;
}

void CMFC_Broadcast_ServerDlg::DoReceive()
{
	memset(m_bufRecv, 0, PACKSIZE);
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocket, (char *)m_bufRecv,sizeof(PACKHEAD),MSG_PEEK, (SOCKADDR *)&addrFrom, &nLen);
	int err=::WSAGetLastError(); //10022  WSANOTINITIALISED
	PACKHEAD *pHead = (PACKHEAD *)m_bufRecv;
	switch(pHead->nFlag)
	{
	case PH_USER_ONLINE:
		DoUserOnline();
		break;
	case PH_USER_OFFLINE:
		DoUserOffline();
		break;
	case PH_USER_OLTEST:
		::recvfrom(m_hSocket, (char *)m_bufRecv,sizeof(PACKHEAD),0, (SOCKADDR *)&addrFrom, &nLen);
		break;
	case PH_USER_OLREPLY:
		DoUserOLReply();
		break;
	default:
		::recvfrom(m_hSocket, (char *)m_bufRecv,PACKSIZE,0, (SOCKADDR *)&addrFrom, &nLen);
		break;
	}
}

void CMFC_Broadcast_ServerDlg::DoUserOnline()
{
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocket, (char *)m_bufRecv,PACKSIZE,0, (SOCKADDR *)&addrFrom, &nLen);
	HOSTENT pHost;
	in_addr ina;
	ina.S_un.S_addr = addrFrom.sin_addr.S_un.S_addr;
	pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
	CString sIP;
	sIP.Format("%s",inet_ntoa(ina));
	int n=m_list.GetItemCount();
	for(int i=0;i<n;i++)
		if(m_list.GetItemText(i,1)==sIP)
			return;
	m_list.InsertItem(n,pHost.h_name);
	m_list.SetItemText(n,1,inet_ntoa(ina));
	UpdateListNOH();
}

void CMFC_Broadcast_ServerDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	::TerminateThread(m_hThreadRev,0);
	m_dcMemNow.DeleteDC();
	m_dcMemOld.DeleteDC();
	m_bmpMemNow.DeleteObject();
	m_bmpMemOld.DeleteObject();
	delete[] m_pBufScreen;
	delete[] m_pBufEncode1;
	delete[] m_pBufEncode2;
	::closesocket(m_hSocket);	
}

void CMFC_Broadcast_ServerDlg::DoUserOffline()
{
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocket, (char *)m_bufRecv,PACKSIZE,0, (SOCKADDR *)&addrFrom, &nLen);
	CString sIP;
	sIP.Format("%s",inet_ntoa(addrFrom.sin_addr));
	int n=m_list.GetItemCount();
	for(int i=0;i<n;i++)
		if(m_list.GetItemText(i,1)==sIP)
		{
			m_list.DeleteItem(i);
			UpdateListNOH();
		}
}

void CMFC_Broadcast_ServerDlg::OnBtnFlush() 
{
	m_list.DeleteAllItems();
	//�������߲���
	PACKHEAD ph={0};
	ph.nFlag=PH_USER_OLTEST;
	SOCKADDR_IN m_addrTo={0};
	m_addrTo.sin_family = AF_INET;
	m_addrTo.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");//htonl(INADDR_BROADCAST); //����ipΪ�㲥��ַ ��: 192.168.0.255
	m_addrTo.sin_port = htons(UDP_PORT);
	int n=::sendto(m_hSocket, (char *)&ph,sizeof(PACKHEAD), 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
}

void CMFC_Broadcast_ServerDlg::DoUserOLReply()
{
	::Sleep(100);
	//ʵ�ʽ���
	SOCKADDR_IN addrFrom = {0};
	int nLen = sizeof(SOCKADDR);
	int nRecv = ::recvfrom(m_hSocket, (char *)m_bufRecv, sizeof(PACKHEAD), 0, (SOCKADDR *)&addrFrom, &nLen);
	if (nRecv == SOCKET_ERROR)
	{
		TRACE("���մ���, �������Ϊ: %d\r\n", GetLastError());
		return;
	}
	HOSTENT pHost;
	in_addr ina;
	ina.S_un.S_addr = addrFrom.sin_addr.S_un.S_addr;
	pHost=*::gethostbyaddr((char *)&ina.S_un.S_addr,4,AF_INET);
	CString sIP;
	sIP.Format("%s",inet_ntoa(ina));
	int n=m_list.GetItemCount();
	for(int i=0;i<n;i++)
		if(m_list.GetItemText(i,1)==sIP)
			return;
	m_list.InsertItem(n,pHost.h_name);
	m_list.SetItemText(n,1,inet_ntoa(ina));
	UpdateListNOH();
}


void CMFC_Broadcast_ServerDlg::UpdateListNOH()
{
	CString s;
	s.Format("����������:%d",m_list.GetItemCount());
	//this->MessageBox(s);
	this->SetDlgItemText(IDC_STATIC_NOH,s);
}

void CMFC_Broadcast_ServerDlg::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NMLISTVIEW * pNMListView = (NMLISTVIEW*)pNMHDR;
	int nItem = pNMListView->iItem;
	if (nItem == -1) return;
	sRClckHost=m_list.GetItemText(nItem,0);
	sRClckIP=m_list.GetItemText(nItem,1);

	CPoint point;
	::GetCursorPos(&point);
	this->SetForegroundWindow();
	this->m_LRMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
	*pResult = 0;
}

void CMFC_Broadcast_ServerDlg::OnMenuSendmsg() 
{
	CDialogSendMSG DlgMsg;
	DlgMsg.m_sIP=sRClckIP;
	DlgMsg.m_sHost=sRClckHost;
	DlgMsg.m_hSocket=m_hSocket;
	DlgMsg.DoModal();
}

void CMFC_Broadcast_ServerDlg::OnMenuSeescreen() 
{	
}
