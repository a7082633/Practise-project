// MFC_UDP_SYNC_CHATDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_UDP_SYNC_CHAT.h"
#include "MFC_UDP_SYNC_CHATDlg.h"

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
// CMFC_UDP_SYNC_CHATDlg dialog

CMFC_UDP_SYNC_CHATDlg::CMFC_UDP_SYNC_CHATDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_UDP_SYNC_CHATDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_UDP_SYNC_CHATDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_UDP_SYNC_CHATDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_UDP_SYNC_CHATDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_UDP_SYNC_CHATDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_UDP_SYNC_CHATDlg)
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(UM_SOCK,OnSock)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC_CHATDlg message handlers

BOOL CMFC_UDP_SYNC_CHATDlg::OnInitDialog()
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
	
	this->SetDlgItemText(IDC_EDIT_IP,"127.0.0.1");
	this->SetDlgItemText(IDC_EDIT_MSG,"HELLO GO");


	m_hSock=::WSASocket(AF_INET,SOCK_DGRAM,0,NULL,NULL,0);
	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=0x6789;//htons(7788);
	addr.sin_addr.S_un.S_addr=0;
	::bind(m_hSock,(SOCKADDR *)&addr,16);
	::WSAAsyncSelect(m_hSock,m_hWnd,UM_SOCK,FD_READ);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_UDP_SYNC_CHATDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_UDP_SYNC_CHATDlg::OnPaint() 
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
HCURSOR CMFC_UDP_SYNC_CHATDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_UDP_SYNC_CHATDlg::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	CString sMsg,sIP;
	this->GetDlgItemText(IDC_EDIT_IP,sIP);
	this->GetDlgItemText(IDC_EDIT_MSG,sMsg);
	WSABUF buf[1];
	buf[0].buf=new char[200];
	buf[0].len=200;
	strcpy(buf[0].buf,sMsg);
	DWORD nSent=0;
	SOCKADDR_IN addrTo={0};
	addrTo.sin_addr.S_un.S_addr=inet_addr(sIP);
	addrTo.sin_family=AF_INET;
	addrTo.sin_port=0x6789;//htons(7788);
	::WSASendTo(m_hSock,buf,1,&nSent,0,(SOCKADDR *)&addrTo,16,NULL,NULL);
	if(nSent>0)
	{
		m_list.AddString("我说："+sMsg);
		m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
	}
	delete []buf[0].buf;
}

void CMFC_UDP_SYNC_CHATDlg::OnSock(WPARAM w, LPARAM l)
{
	switch(LOWORD(l))
	{
	case FD_READ:
		{
			WSABUF buf[1];
			buf[0].buf=new char[200];
			buf[0].len=200;
			memset(buf[0].buf,0,200);
			DWORD nRev=0;
			SOCKADDR_IN addrFrm={0};
			int len=16;
			DWORD Flags=0;
			::WSARecvFrom(m_hSock,buf,1,&nRev,&Flags,(SOCKADDR *)&addrFrm,&len,NULL,NULL);
			if(nRev>0)
			{


				//HOSTENT *far= gethostbyaddr(inet_ntoa(addrFrm.sin_addr),4,AF_INET);

				HOSTENT *pHost = gethostbyaddr((char*)&addrFrm.sin_addr.S_un.S_addr, 4, AF_INET);
				////////////
				CString s;
				//s.Format("%s说：%s\n",inet_ntoa(addrFrm.sin_addr),buf[0].buf);
				s.Format("%s说：%s\n",pHost->h_name,buf[0].buf);
				m_list.AddString(s);
				m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
			}
			delete []buf[0].buf;
		}
		break;
	}
}

void CMFC_UDP_SYNC_CHATDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	::closesocket(m_hSock);
	CDialog::PostNcDestroy();
}
