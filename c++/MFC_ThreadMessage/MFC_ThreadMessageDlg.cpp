// MFC_ThreadMessageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_ThreadMessage.h"
#include "MFC_ThreadMessageDlg.h"

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
// CMFC_ThreadMessageDlg dialog

CMFC_ThreadMessageDlg::CMFC_ThreadMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_ThreadMessageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_ThreadMessageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_handle=NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_ThreadMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_ThreadMessageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_ThreadMessageDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_ThreadMessageDlg)
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(UM_CLOCK,OnClock)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CREATE, OnBtnCreate)
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	ON_BN_CLICKED(IDC_BTN_QUIT, OnBtnQuit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_ThreadMessageDlg message handlers

BOOL CMFC_ThreadMessageDlg::OnInitDialog()
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

void CMFC_ThreadMessageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_ThreadMessageDlg::OnPaint() 
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
HCURSOR CMFC_ThreadMessageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_ThreadMessageDlg::OnBtnCreate() 
{
	if(m_handle==NULL)
		m_handle=::CreateThread(NULL,0,ThreadFun,this,0,&m_dwThreaId);
}

void CMFC_ThreadMessageDlg::OnBtnSend() 
{
	CString *pNew=new CString;
	this->GetDlgItemText(IDC_EDIT1,*pNew);
	::PostThreadMessage(this->m_dwThreaId,UM_STR,WPARAM(pNew),0);
}

void CMFC_ThreadMessageDlg::OnBtnQuit() 
{
	::PostThreadMessage(m_dwThreaId,WM_QUIT,0,0);
	//if(m_handle!=NULL)
	m_handle=NULL;
}

DWORD WINAPI CMFC_ThreadMessageDlg::ThreadFun(LPVOID p)
{
	CMFC_ThreadMessageDlg *pDlg=(CMFC_ThreadMessageDlg *)p;
	while(1)
	{
		MSG msg;
		while(false==::PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
		{
			::Sleep(1);
			::PostMessage(pDlg->m_hWnd,UM_CLOCK,0,0);
		}

		::GetMessage(&msg,NULL,0,0);
		switch(msg.message)
		{
		case WM_QUIT:
			return msg.wParam;
			break;
		case UM_STR:
			::AfxMessageBox(*(CString *)msg.wParam);
			break;
		}
	}
	return 0;
}

 void CMFC_ThreadMessageDlg::OnClock()
 {
	 SYSTEMTIME tm;
	 ::GetLocalTime(&tm);
	 CString s;
	 s.Format("%02d:%02d:%02d: %03d",tm.wHour,tm.wMinute,tm.wSecond,tm.wMilliseconds);
	 CClientDC dc(this);
	 dc.TextOut(10,10,s);
 }
