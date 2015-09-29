// MFC_FILESDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FILES.h"
#include "MFC_FILESDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
DWORD WINAPI AcceptThread(LPVOID p);
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
// CMFC_FILESDlg dialog

CMFC_FILESDlg::CMFC_FILESDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_FILESDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_FILESDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_FILESDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_FILESDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_FILESDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_FILESDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILESDlg message handlers

BOOL CMFC_FILESDlg::OnInitDialog()
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

	m_hSocket=socket(AF_INET,SOCK_STREAM,0);
	if (INVALID_SOCKET == m_hSocket)
	{
		::AfxMessageBox("创建套接字失败！");
	}
	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=0x7788;
	addr.sin_addr.S_un.S_addr=0;
	if(SOCKET_ERROR==bind(m_hSocket,(SOCKADDR *)&addr,sizeof(SOCKADDR)))
	{
		::AfxMessageBox("绑定套接字失败");
	}
	if(SOCKET_ERROR==listen(m_hSocket, 5))
	{
		::AfxMessageBox("监听失败！");
	}
	::CreateThread(NULL,0,AcceptThread,(void *)m_hSocket,0,NULL);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_FILESDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_FILESDlg::OnPaint() 
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
HCURSOR CMFC_FILESDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_FILESDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	closesocket(m_hSocket);
	CDialog::PostNcDestroy();
}
DWORD WINAPI SendFileThread(LPVOID p)
{
	SOCKET sockConn=(SOCKET)p;
	DWORD FileLen;
	CFile file("D:\\test\\video.exe",CFile::typeBinary |CFile::modeRead);
	FileLen=file.GetLength();
	if(SOCKET_ERROR==::send(sockConn,(char *)&FileLen,sizeof(DWORD),0))
	{
		::AfxMessageBox("发送文件大小失败!");
	}
	char bufSend[1024]={0};
	int nRead;
	while((nRead=file.Read(bufSend,1024))>0)
	{
		::send(sockConn,bufSend,nRead,0);
	}
	file.Close();
	return 0;
}
DWORD WINAPI AcceptThread(LPVOID p)
{
	SOCKET server=(SOCKET)p;
 	while(1)
	{
 		//接受客户端连接请求	
 		SOCKET sockConn;
		SOCKADDR_IN skafrmddr={0};
		int addrlen=sizeof(sockaddr);
		sockConn = accept(server,(sockaddr *)&skafrmddr,&addrlen); //阻塞
		::CreateThread(NULL, 0,SendFileThread,(void*)sockConn, 0, NULL);
 		::AfxMessageBox("有人连接！");
	}
 	return 0;
}
