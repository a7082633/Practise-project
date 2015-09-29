// WebService_TDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WebService_T.h"
#include "WebService_TDlg.h"


#include <afxinet.h>


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
// CWebService_TDlg dialog

CWebService_TDlg::CWebService_TDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWebService_TDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWebService_TDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWebService_TDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebService_TDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWebService_TDlg, CDialog)
	//{{AFX_MSG_MAP(CWebService_TDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebService_TDlg message handlers

BOOL CWebService_TDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWebService_TDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWebService_TDlg::OnPaint() 
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
HCURSOR CWebService_TDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWebService_TDlg::OnSend() 
{	
//
//	int nRet;
//	void *hSession;
//	const char* szAccept = "*/*";
//	hSession = InternetOpen("http",INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0);
//	if (NULL == hSession) 
//	{
//		nRet = -1;
//	}
//	void *hConnect = InternetConnect(hSession,
//								"221.176.197.13",
//								8011,
//								NULL,
//								NULL,
//								INTERNET_SERVICE_HTTP,
//								0,
//								0);
//	if (NULL == hConnect) 
//	{
//		nRet = -2;
//	}
//	void *hRequest = HttpOpenRequest(hConnect,
//								"GET",
//								"/Api!CardIdentify.do?account=123&password=123",
//								"HTTP/1.1",
//								NULL,
//								&szAccept,
//								INTERNET_FLAG_RELOAD,
//								0);
//	if (NULL == hRequest) 
//	{
//		nRet = -3;
//	}
//	if (!HttpSendRequest(hRequest, NULL, 0, NULL, 0)) 
//	{
//		nRet = -4;
//	}
//	char dwBytesToRead[100]={0};
//	unsigned long dwBufLen=100;
//	if (!HttpQueryInfo(hRequest,HTTP_QUERY_STATUS_CODE| HTTP_QUERY_FLAG_NUMBER,dwBytesToRead, &dwBufLen, NULL))
//	{
//		nRet = -5;
//	}
	//HTTP_QUERY_CONTENT_LENGTH |




//	//初始化套接字库	WSAStartup(1,1)
//	WSADATA WSAData;
//	if(WSAStartup(1,&WSAData)!=0)
//	{
//		printf("初始化套接字库失败！\n");
//		return;
//	}
//	struct sockaddr_in serverAddr;	
//	ZeroMemory(&serverAddr, sizeof(serverAddr));
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(8011);
//	serverAddr.sin_addr.S_un.S_addr = inet_addr("221.176.197.13");
//
//	//创建套接字	sockClient = socket(SOCK_STREAM)
//	SOCKET	sock;
//	sock = socket(AF_INET, SOCK_STREAM, 0);
//	if (INVALID_SOCKET == sock)
//	{
//		printf("创建套接字失败！\n");
//		WSACleanup();
//		return;
//	}
//
//
//	int nRet = connect(sock, (const struct sockaddr*)&serverAddr, sizeof(serverAddr));
//	if (SOCKET_ERROR == nRet) 
//	{
//		return;
//	}	
//	char szSend[4096] = {0};
//	_snprintf(szSend, 4095, "GET /Api!CardIdentify.do?account=123&&password=123 HTTP/1.1\r\n"
//							"Accept: */*\r\n"							
//							"Pragma: no-cache\r\n"
//							"Cache-Control: no-cache\r\n"
//							"Connection: Keep-Alive\r\n"
//							"\r\n");
//	char buf[100]={0};
//	recv(sock,buf,4,0);
//	closesocket(sock);
//	//释放套接字库资源	
//	WSACleanup();

	CInternetSession m_session;
	CString strData;
	char *requestUrl="http://221.176.197.13:8011/Api!CardIdentify.do?account=123&&password=123";
	CHttpFile *pFile = (CHttpFile *) m_session.OpenURL(requestUrl, 1, 
	INTERNET_FLAG_TRANSFER_ASCII|INTERNET_FLAG_RELOAD);
	char ch;
	while (pFile->Read(&ch, sizeof(TCHAR)))
	{
		strData += ch;
	}
	pFile->Close();
	m_session.Close();
}
