// MFC_TicketsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Tickets.h"
#include "MFC_TicketsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CRITICAL_SECTION cs;
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
// CMFC_TicketsDlg dialog

CMFC_TicketsDlg::CMFC_TicketsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_TicketsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_TicketsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_TicketsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_TicketsDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_TicketsDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_TicketsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_TicketsDlg message handlers

BOOL CMFC_TicketsDlg::OnInitDialog()
{
	::InitializeCriticalSection(&cs);
	::CreateMutex(NULL,FALSE,"tickets");
	DWORD err=::GetLastError();
	if(err==ERROR_ALREADY_EXISTS)
	{
		HWND handle=::FindWindow(NULL,"MFC_Tickets");
		::SetForegroundWindow(handle);
		return false;
	}

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

void CMFC_TicketsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_TicketsDlg::OnPaint() 
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
HCURSOR CMFC_TicketsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//HANDLE hMutex;
HANDLE hEvent;
int nTickets=30;
DWORD WINAPI ThreadFun1(LPVOID p)
{
	CMFC_TicketsDlg *pDlg=(CMFC_TicketsDlg *)p;
	CString sOld,sNew;
	while(nTickets>0)
	{
		//::WaitForSingleObject(hEvent,-1);
		::EnterCriticalSection(&cs);
		if(nTickets>0)
		{
			pDlg->GetDlgItemText(IDC_EDIT1,sOld);
			sNew.Format("%d",nTickets);
			sNew=sNew+"\r\n"+sOld;
			pDlg->SetDlgItemText(IDC_EDIT1,sNew);
			nTickets--;
		}
		::LeaveCriticalSection(&cs);
		//::SetEvent(hEvent);
		//::ReleaseMutex(hEvent);
	}
	return 0;
}

DWORD WINAPI ThreadFun2(LPVOID p)
{
	CMFC_TicketsDlg *pDlg=(CMFC_TicketsDlg *)p;
	CString sOld,sNew;
	while(nTickets>0)
	{
		//::WaitForSingleObject(hEvent,-1);
		::EnterCriticalSection(&cs);
		if(nTickets>0)
		{
			pDlg->GetDlgItemText(IDC_EDIT2,sOld);
			sNew.Format("%d",nTickets);
			sNew=sNew+"\r\n"+sOld;
			pDlg->SetDlgItemText(IDC_EDIT2,sNew);
			nTickets--;
		}
		::LeaveCriticalSection(&cs);
		//::SetEvent(hEvent);
		//::ReleaseMutex(hEvent);
	}
	return 0;
}
void CMFC_TicketsDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	this->SetDlgItemText(IDC_EDIT1,"");
	this->SetDlgItemText(IDC_EDIT2,"");
	nTickets=30;
	//hMutex=::CreateMutex(NULL,false,NULL);
	//hEvent=::CreateEvent(NULL,false,TRUE,NULL);
	//::ReleaseMutex(hMutex);
	::CreateThread(NULL,0,ThreadFun1,this,0,NULL);
	::CreateThread(NULL,0,ThreadFun2,this,0,NULL);

	//::InitializeCriticalSection(CRITICAL_SECTION)
}
