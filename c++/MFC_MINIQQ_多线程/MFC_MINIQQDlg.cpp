// MFC_MINIQQDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MINIQQ.h"
#include "MFC_MINIQQDlg.h"
#include "ChatDialog.h"
#include "MyWinThread.h"
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
// CMFC_MINIQQDlg dialog

CMFC_MINIQQDlg::CMFC_MINIQQDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_MINIQQDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_MINIQQDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_MINIQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_MINIQQDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_MINIQQDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_MINIQQDlg)
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(6789,OnCloseThread)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MINIQQDlg message handlers

BOOL CMFC_MINIQQDlg::OnInitDialog()
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
	m_imageList.Create(IDB_BITMAP1, 10, 1, RGB(0, 253, 0));
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_list.SetImageList(&m_imageList,LVSIL_SMALL);

	m_list.InsertColumn(0, "状态", LVCFMT_CENTER, 50);
	m_list.InsertColumn(1, "姓名", LVCFMT_LEFT, 75);
	m_list.InsertColumn(2, "IP地址", LVCFMT_LEFT, 80);

	m_list.InsertItem(0,"",0);
	m_list.SetItemText(0,1,"李刚");
	m_list.SetItemText(0,2,"192.168.0.1");

	m_list.InsertItem(1,"",0);
	m_list.SetItemText(1,1,"李小刚");
	m_list.SetItemText(1,2,"192.168.0.3");

	m_list.InsertItem(2,"",1);
	m_list.SetItemText(2,1,"奥巴马");
	m_list.SetItemText(2,2,"192.168.0.2");

	m_list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_MINIQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_MINIQQDlg::OnPaint() 
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
HCURSOR CMFC_MINIQQDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFC_MINIQQDlg::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NMLISTVIEW * pNMListView = (NMLISTVIEW*)pNMHDR;
	int nItem = pNMListView->iItem;
	if (nItem == -1) return;


	for(int i=0;i<m_ptrarr.GetSize();i++) //判断是否已经存在相同聊天窗
	{
		CMyWinThread *p=(CMyWinThread *)m_ptrarr[i];
		if(p->Sname==m_list.GetItemText(nItem,1))
		{
			p->SetWindowFront();
			return;
		}
	}

	m_ChatThread=(CMyWinThread *)::AfxBeginThread(RUNTIME_CLASS(CMyWinThread),NULL,0,0);
	m_ptrarr.Add(m_ChatThread);

	CMyWinThread *p=(CMyWinThread *)m_ChatThread;
	p->Sname=m_list.GetItemText(nItem,1);
	p->parent=this;


}

void CMFC_MINIQQDlg::OnCloseThread(WPARAM lParam) //根据子线程传回的名字删除子线程的句柄
{
	CString name=*(CString *)lParam;
	for(int i=0;i<m_ptrarr.GetSize();i++)
	{
		CMyWinThread *p=(CMyWinThread *)m_ptrarr[i];
		if(p->Sname==name)
		{
			m_ptrarr.RemoveAt(i);
			return;
		}
	}
}
