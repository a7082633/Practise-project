// MFC_UDP_CHATDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_UDP_CHAT.h"
#include "MFC_UDP_CHATDlg.h"

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
// CMFC_UDP_CHATDlg dialog

CMFC_UDP_CHATDlg::CMFC_UDP_CHATDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_UDP_CHATDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_UDP_CHATDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_UDP_CHATDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_UDP_CHATDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_UDP_CHATDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_UDP_CHATDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_CHATDlg message handlers

BOOL CMFC_UDP_CHATDlg::OnInitDialog()
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
	m_hSocket=socket(AF_INET,SOCK_DGRAM,0);
	if (INVALID_SOCKET == m_hSocket)
	{
		::AfxMessageBox("创建套接字失败！");
	}
	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=0x1234;
	addr.sin_addr.S_un.S_addr=0;
	if(SOCKET_ERROR==bind(m_hSocket,(SOCKADDR *)&addr,sizeof(SOCKADDR)))
	{
		::AfxMessageBox("绑定套接字失败");
	}
	::CreateThread(NULL,0,ReceivMsgThread,this,0,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_UDP_CHATDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_UDP_CHATDlg::OnPaint() 
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
HCURSOR CMFC_UDP_CHATDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_UDP_CHATDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	closesocket(m_hSocket);
	WSACleanup();
	CDialog::PostNcDestroy();
}

DWORD WINAPI CMFC_UDP_CHATDlg::ReceivMsgThread(LPVOID p)
{
	CMFC_UDP_CHATDlg *pDlg=(CMFC_UDP_CHATDlg *)p;
	pDlg->DoReceive();
	return 0;
}

void CMFC_UDP_CHATDlg::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	CString ip,msg,str;
	this->GetDlgItemText(IDC_EDIT_IP,ip);
	this->GetDlgItemText(IDC_EDIT_MSG,msg);
	SOCKADDR_IN sockto={0};
	sockto.sin_family=AF_INET;
	sockto.sin_port=0x1234;
	sockto.sin_addr.S_un.S_addr=inet_addr(ip);
	::sendto(m_hSocket,msg,msg.GetLength(),0,(SOCKADDR *)&sockto,sizeof(SOCKADDR));
	str.Format("我说：%s",msg);
	m_list.AddString(str);
	m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
}

void CMFC_UDP_CHATDlg::DoReceive()
{
	while(1)
	{
		char bufRev[100]={0};
		SOCKADDR_IN sockfrm={0};
		int len=sizeof(SOCKADDR);
		::recvfrom(m_hSocket,bufRev,sizeof(bufRev),0,(SOCKADDR *)&sockfrm,&len);
		CString s;
		s.Format("%s 说: %s",inet_ntoa(sockfrm.sin_addr),bufRev);
		m_list.AddString(s);
		m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
	}
}
