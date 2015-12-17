// MFC_GetFreeFromWebsiteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_GetFreeFromWebsite.h"
#include "MFC_GetFreeFromWebsiteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

bool CMFC_GetFreeFromWebsiteDlg::isThreadRun=false;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
char* U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len+1];
	memset(wstr, 0, len+1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len+1];
	memset(str, 0, len+1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if(wstr) delete[] wstr;
	return str;
}
void log_append_to_file(char* filename,char* str,int len,char* sourceFile,int fileLine)
{
    time_t t;
    time(&t);
    struct tm* tp= localtime(&t);
    printf("%x\n",tp);
    char now_str[100];
    strftime(now_str, 100, "%Y-%m-%d %H:%M:%S", tp);
 

	//先获取配置文件路径
    FILE *fo;
    fo = fopen(filename, "a");
    if (fo == 0) {  
        return;
    }
 
    fprintf(fo, "\r\n%s %s(:%d):\r\n",now_str,sourceFile,fileLine);
	::fwrite(str,1,len,fo);
    fclose(fo);
}
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
// CMFC_GetFreeFromWebsiteDlg dialog

CMFC_GetFreeFromWebsiteDlg::CMFC_GetFreeFromWebsiteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_GetFreeFromWebsiteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_GetFreeFromWebsiteDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_GetFreeFromWebsiteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_GetFreeFromWebsiteDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_GetFreeFromWebsiteDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_GetFreeFromWebsiteDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SCAN, OnBtnScan)
	ON_BN_CLICKED(IDC_BTN_STOPSCAN, OnBtnStopscan)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_GetFreeFromWebsiteDlg message handlers

BOOL CMFC_GetFreeFromWebsiteDlg::OnInitDialog()
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
	m_hThread=NULL;
	this->SetDlgItemText(IDC_EDIT_WEBSITE,"http://www.wifijy.com/forum-49-1.html");
	this->SetDlgItemText(IDC_EDIT_PORT,"80");
	this->SetDlgItemText(IDC_EDIT_SCANTIME,"5000");
	//初始化套接字库
	WSADATA WSAData;
	if(WSAStartup(1,&WSAData)!=0)
	{
		this->MessageBox("初始化套接字库失败!");
		return 0;
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_GetFreeFromWebsiteDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_GetFreeFromWebsiteDlg::OnPaint() 
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
HCURSOR CMFC_GetFreeFromWebsiteDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_GetFreeFromWebsiteDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CMFC_GetFreeFromWebsiteDlg::OnBtnScan() 
{
	if(m_hThread==NULL)
	{
		this->isThreadRun=true;
		m_hThread=CreateThread(NULL,0,ScanThread,this,0,NULL);
	}
}

DWORD WINAPI CMFC_GetFreeFromWebsiteDlg::ScanThread(LPVOID lpParameter)
{
	CMFC_GetFreeFromWebsiteDlg *pDlg=(CMFC_GetFreeFromWebsiteDlg *)lpParameter;
	CString sPort,sAddr,sFindStr,sScanTime,sException;
	pDlg->GetDlgItemText(IDC_EDIT_WEBSITE,sAddr);
	pDlg->GetDlgItemText(IDC_EDIT_PORT,sPort);
	pDlg->GetDlgItemText(IDC_EDIT_SCANSTR,sFindStr);
	pDlg->GetDlgItemText(IDC_EDIT_SCANTIME,sScanTime);
	int iScanTime=atoi(sScanTime);
	unsigned short port=atoi(sPort);
	char IP[100]={0};
	//格式化网址
	//	const char *s = "http://www.wifijy.com/forum-49-1.html";
    char protocol[32]={0};
    char host[128]={0};
    char api[200]={0};
	int nFormat=sscanf(sAddr,"%[^:]://%[^/]%s",protocol,host,api);
	//网址转IP
	struct hostent *remoteHost; 
	struct in_addr addr;  
	remoteHost=gethostbyname(host);
	if(remoteHost == NULL)
	{
		pDlg->SetDlgItemText(IDC_STATIC_STATE,"域名转IP失败!");
        return 0;
	}
	else
	{
		addr.s_addr = *(u_long*)remoteHost->h_addr_list[0]; 
		sprintf(IP,"%s",inet_ntoa(addr)); /* inet_ntoa() 函数将网络地址转成二进制的数字相关函数：inet_aton, inet_ntoa */
	}
	//创建套接字
	pDlg->m_sockServer = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == pDlg->m_sockServer)
	{
		pDlg->SetDlgItemText(IDC_STATIC_STATE,"创建套接字失败!");
		pDlg->isThreadRun=false;
		pDlg->m_hThread=NULL;
		return 0;
	}
	//指明服务器
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=htons((unsigned short)port);
	skaddr.sin_addr.s_addr=inet_addr(IP);         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	//发出连接请求	connect(sockClient, addrSrv)
	if(SOCKET_ERROR==connect(pDlg->m_sockServer,(SOCKADDR *)&skaddr,sizeof(SOCKADDR_IN)))
	{
		pDlg->SetDlgItemText(IDC_STATIC_STATE,"连接失败!");
		pDlg->isThreadRun=false;
		pDlg->m_hThread=NULL;
		closesocket(pDlg->m_sockServer);
		return 0;
	}
	char send_str[4000]={0};
	char parameters[2048]="hahahaha";
    //头信息
    strcat(send_str, "GET ");
	strcat(send_str, api);
    strcat(send_str, " HTTP/1.1\r\n");
    strcat(send_str, "Host: ");
	strcat(send_str, host);
    strcat(send_str, "\r\n");
    strcat(send_str, "Connection: keep-alive\r\n");
	strcat(send_str,"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\r\n");
	strcat(send_str,"Upgrade-Insecure-Requests: 1\r\n");
	strcat(send_str,"User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.80 Safari/537.36\r\n");
	strcat(send_str, "Accept-Encoding: gzip, deflate, sdch\r\n");
	strcat(send_str, "Accept-Language: zh-CN,zh;q=0.8\r\n");
	strcat(send_str, "Content-Type: text/html;charset=UTF-8\r\n");
//    char content_header[100];
//    sprintf(content_header,"Content-Length: %d\r\n", strlen(parameters));
//
//    strcat(send_str, content_header);
    //内容信息
    strcat(send_str, "\r\n");
    //strcat(send_str, parameters);
	CString temp;
	int i=1;
	char Rcvbuf[RECEIVE_BUFFER_LEN]={0};//接收缓冲
	unsigned char UnCompressBuffer[UNCOMPRESS_BUFFER_LEN]={0};//解压缓冲
	while(pDlg->isThreadRun)
	{
		//发送数据包
		if (send(pDlg->m_sockServer, send_str, strlen(send_str),0) == -1)
		{
			pDlg->SetDlgItemText(IDC_STATIC_STATE,"发送数据失败!");
			break;
		}
		//接收数据
		int nNetTimeout=5000;//5秒，
		memset(Rcvbuf,0,RECEIVE_BUFFER_LEN);
		setsockopt(pDlg->m_sockServer,SOL_SOCKET,SO_RCVTIMEO, (char *)&nNetTimeout,sizeof(int));
		int n=recv(pDlg->m_sockServer,Rcvbuf,sizeof(Rcvbuf),0);
		if(n<=0)
		{
			pDlg->SetDlgItemText(IDC_STATIC_STATE,"接收数据失败!");
			break;
		}
		//判断是否GZIP
		char *pTemp=strstr(Rcvbuf,"Content-Encoding: gzip");
		if(pTemp!=NULL)
		{
			memset(UnCompressBuffer,0,UNCOMPRESS_BUFFER_LEN);
			unsigned long len=UNCOMPRESS_BUFFER_LEN;
			char *p=strstr(Rcvbuf,"utf-8");
			char *pStart=strstr(Rcvbuf,"Content-Length");
			pStart+=15;
			char *pEnd=strstr(pStart,"\r\n");
			string s;
			s.append(pStart,pEnd-pStart);
			int LenOfCompress=atoi(s.c_str());
			//GZIP解压
			z_stream strm;
			strm.zalloc = Z_NULL;
			strm.zfree = Z_NULL;
			strm.opaque = Z_NULL;
			strm.avail_in = LenOfCompress;
			strm.next_in = (unsigned char *)p+9;
			strm.avail_out = len;
			strm.next_out = (unsigned char * ) UnCompressBuffer;
			int ret= inflateInit2(&strm, 47);
			if(ret!=0)
			{
				pDlg->SetDlgItemText(IDC_STATIC_STATE,"解压数据失败1!");
				break;
			}
			ret = inflate(&strm, Z_NO_FLUSH);
			//Z_STREAM_ERROR
			if(ret!=1)
			{
				sException.Format("解压数据失败2-接收数据:%d-实际数据:%d",n,LenOfCompress);
				pDlg->SetDlgItemText(IDC_STATIC_STATE,sException);
				break;
			}
			inflateEnd(&strm); 
		}else   //不是GZIP
		{
			pDlg->SetDlgItemText(IDC_STATIC_STATE,"暂时不支持次格式!");
			break;
		}
		//UTF-8转GBK
		char *pGB=U2G((const char *)UnCompressBuffer);
//		log_append_to_file("Reader.log",pGB,strlen(pGB),"接收:\r\n",1);
		//搜索字符串chinanet免费账号2015.12.9
		pTemp=strstr(pGB,sFindStr);
		if(pTemp!=NULL)
		{
			pDlg->MessageBox("找到了!");
			delete []pGB;
			break;
		}
		//显示扫描次数
		temp.Format("扫描次数%d",i++);
		pDlg->SetDlgItemText(IDC_STATIC_STATE,temp);
		delete []pGB;
		::Sleep(iScanTime);
	}//end while
	pDlg->m_hThread=NULL;
	closesocket(pDlg->m_sockServer);
	::MessageBox(NULL,"线程结束!",NULL,MB_OK);
	//pDlg->SetDlgItemText(IDC_STATIC_STATE,"已停止扫描!");
	return 0;
}

void CMFC_GetFreeFromWebsiteDlg::OnBtnStopscan() 
{
	this->isThreadRun=false;
}

void CMFC_GetFreeFromWebsiteDlg::OnClose() 
{
	closesocket(m_sockServer);
	WSACleanup();
	CDialog::OnClose();
}
