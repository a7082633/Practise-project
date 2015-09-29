// MFC_FILECDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_FILEC.h"
#include "MFC_FILECDlg.h"

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
// CMFC_FILECDlg dialog

CMFC_FILECDlg::CMFC_FILECDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_FILECDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_FILECDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_FILECDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_FILECDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_FILECDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_FILECDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILECDlg message handlers

BOOL CMFC_FILECDlg::OnInitDialog()
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
	m_hSocketC = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == m_hSocketC)
	{
		::AfxMessageBox("创建套接字失败！\n");
	}
	//指明服务器	SOCKADDR_IN addrSrv=IP:6001
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=0x7788;
	skaddr.sin_addr.s_addr=inet_addr("127.0.0.1");         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	if(SOCKET_ERROR==connect(m_hSocketC,(SOCKADDR *)&skaddr,sizeof(SOCKADDR_IN)))
	{
		::AfxMessageBox("连接失败！");
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_FILECDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_FILECDlg::OnPaint() 
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
HCURSOR CMFC_FILECDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_FILECDlg::OnBtnStart() 
{
	//this->MessageBox("haha");
	DWORD nFileLen = -1;
	DWORD TransFileLen =0;
	int nstr = ::recv(m_hSocketC, (char *)&nFileLen,sizeof(DWORD), 0);
	if(nstr>0)
	{
		CString s;
		s.Format("%d",nFileLen);
		this->MessageBox(s);
	}
	CFile file("D:\\test\\aaa.exe",CFile::modeWrite |CFile::typeBinary |CFile::modeCreate);
	
	while(TransFileLen<nFileLen)
	{
		char bufRev[1024]={0};
		int nFile=::recv(m_hSocketC,bufRev,sizeof(bufRev), 0);
		TransFileLen+=nFile;
		int n=TransFileLen*1.0/nFileLen*100;
		m_progress.SetPos(n);
		//::Sleep(1000);
		file.Write(bufRev,nFile);
	}
	this->MessageBox("接受完成！");
	file.Close();
}

void CMFC_FILECDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	::closesocket(m_hSocketC);
	CDialog::PostNcDestroy();
}
