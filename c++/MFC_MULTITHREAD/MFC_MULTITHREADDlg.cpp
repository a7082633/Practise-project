// MFC_MULTITHREADDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MULTITHREAD.h"
#include "MFC_MULTITHREADDlg.h"

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
// CMFC_MULTITHREADDlg dialog

CMFC_MULTITHREADDlg::CMFC_MULTITHREADDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_MULTITHREADDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_MULTITHREADDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_MULTITHREADDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_MULTITHREADDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_MULTITHREADDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_MULTITHREADDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CREATE1, OnBtnCreate1)
	ON_BN_CLICKED(IDC_BTN_SUSPEND1, OnBtnSuspend1)
	ON_BN_CLICKED(IDC_BTN_RESUM1, OnBtnResum1)
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)
	ON_BN_CLICKED(IDC_BTN_CREATE2, OnBtnCreate2)
	ON_BN_CLICKED(IDC_BTN_SUSPEND2, OnBtnSuspend2)
	ON_BN_CLICKED(IDC_BTN_RESUM2, OnBtnResum2)
	ON_BN_CLICKED(IDC_BTN_EXIT2, OnBtnExit2)
	ON_BN_CLICKED(IDC_BTN_EXITTHREAD, OnBtnExitthread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MULTITHREADDlg message handlers

BOOL CMFC_MULTITHREADDlg::OnInitDialog()
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

void CMFC_MULTITHREADDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_MULTITHREADDlg::OnPaint() 
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
HCURSOR CMFC_MULTITHREADDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HANDLE handle1=NULL;
HANDLE handle2=NULL;

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	CBrush bsh(0xff);
	CMFC_MULTITHREADDlg *p=(CMFC_MULTITHREADDlg *)lpParameter;
	CClientDC dc(p);
	dc.SelectObject(&bsh);
	RECT rt={11,11,111,111};
	while(1)
	{
		dc.Ellipse(&rt);
		::Sleep(100);
		p->InvalidateRect(&rt);
		::Sleep(100);
	}
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	CBrush bsh(0xffff);
	CMFC_MULTITHREADDlg *p=(CMFC_MULTITHREADDlg *)lpParameter;
	CClientDC dc(p);
	dc.SelectObject(&bsh);
	RECT rt={131,11,231,111};
	while(1)
	{
		dc.Ellipse(&rt);
		::Sleep(100);
		p->InvalidateRect(&rt);
		::Sleep(100);
	}
	return 0;
}

void CMFC_MULTITHREADDlg::OnBtnCreate1() 
{
	// TODO: Add your control notification handler code here
	if(handle1==NULL)
		handle1=::CreateThread(NULL,0,ThreadProc1,this,0,NULL);
	
}

void CMFC_MULTITHREADDlg::OnBtnSuspend1() 
{
	// TODO: Add your control notification handler code here
	::SuspendThread(handle1);
}

void CMFC_MULTITHREADDlg::OnBtnResum1() 
{
	// TODO: Add your control notification handler code here
	::ResumeThread(handle1);
}

void CMFC_MULTITHREADDlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here
	::TerminateThread(handle1,0);
	handle1=NULL;
}

void CMFC_MULTITHREADDlg::OnBtnCreate2() 
{
	// TODO: Add your control notification handler code here
	if(handle2==NULL)
		handle2=::CreateThread(NULL,0,ThreadProc2,this,0,NULL);
}

void CMFC_MULTITHREADDlg::OnBtnSuspend2() 
{
	// TODO: Add your control notification handler code here
	::SuspendThread(handle2);
}

void CMFC_MULTITHREADDlg::OnBtnResum2() 
{
	// TODO: Add your control notification handler code here
	::ResumeThread(handle2);
}

void CMFC_MULTITHREADDlg::OnBtnExit2() 
{
	// TODO: Add your control notification handler code here
	::TerminateThread(handle2,0);
	handle2=NULL;
}

void CMFC_MULTITHREADDlg::OnBtnExitthread() 
{
	// TODO: Add your control notification handler code here
	::TerminateThread(handle1,0);
	::TerminateThread(handle2,0);
	::ExitThread(0);
}
