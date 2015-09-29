// MFC_MULTI_THREAD_BARDlg.cpp : implementation file
//

#include "stdafx.h"
#include <Windows.h>
#include <Winbase.h>
#include <stdio.h>
#include <stdlib.h>
#include "MFC_MULTI_THREAD_BAR.h"
#include "MFC_MULTI_THREAD_BARDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString ToFilePath;
CString FilePath;
CString FileName;
DWORD FileLen;

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
// CMFC_MULTI_THREAD_BARDlg dialog

CMFC_MULTI_THREAD_BARDlg::CMFC_MULTI_THREAD_BARDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_MULTI_THREAD_BARDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFC_MULTI_THREAD_BARDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_MULTI_THREAD_BARDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFC_MULTI_THREAD_BARDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFC_MULTI_THREAD_BARDlg, CDialog)
	//{{AFX_MSG_MAP(CMFC_MULTI_THREAD_BARDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_BTN_SELECTFILE, OnBtnSelectfile)
	ON_BN_CLICKED(IDC_BTN_SELECTPATH, OnBtnSelectpath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MULTI_THREAD_BARDlg message handlers

BOOL CMFC_MULTI_THREAD_BARDlg::OnInitDialog()
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

void CMFC_MULTI_THREAD_BARDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_MULTI_THREAD_BARDlg::OnPaint() 
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
HCURSOR CMFC_MULTI_THREAD_BARDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//copyex回调函数
DWORD CALLBACK CopyProgressRoutine(
  LARGE_INTEGER TotalFileSize,          // file size
  LARGE_INTEGER TotalBytesTransferred,  // bytes transferred
  LARGE_INTEGER StreamSize,             // bytes in stream
  LARGE_INTEGER StreamBytesTransferred, // bytes transferred for stream
  DWORD dwStreamNumber,                 // current stream
  DWORD dwCallbackReason,               // callback reason
  HANDLE hSourceFile,                   // handle to source file
  HANDLE hDestinationFile,              // handle to destination file
  LPVOID lpData                         // from CopyFileEx
  )
{
	CMFC_MULTI_THREAD_BARDlg *pDlg=(CMFC_MULTI_THREAD_BARDlg *)lpData;
	int t=TotalBytesTransferred.QuadPart/(double)FileLen*100;
	CString s,s2;
	s2.Format("%d",t);
	s.Format("%d",TotalBytesTransferred.QuadPart);
	//pDlg->MessageBox(s);
	::Sleep(100);
	pDlg->m_progress.SetPos(t);
	s.Format("%d MB / %d MB",FileLen/1024/1024,TotalBytesTransferred.QuadPart/1024/1024);
	pDlg->SetDlgItemText(IDC_STATIC,s+" 进度 : "+s2+"%");
	return PROGRESS_CONTINUE;
}

DWORD WINAPI ThreadFun1(LPVOID p)
{
	CMFC_MULTI_THREAD_BARDlg *pDlg=(CMFC_MULTI_THREAD_BARDlg *)p;
	//::MessageBox(NULL,ToFilePath,NULL,MB_OK);
	::CopyFileEx(FilePath,ToFilePath+FileName,CopyProgressRoutine,pDlg,false,COPY_FILE_FAIL_IF_EXISTS);
	DWORD err=GetLastError();
	if(err==ERROR_FILE_EXISTS)
		pDlg->MessageBox("File already exists!");
	else
		pDlg->MessageBox("Copy finished!");
	return 0;
}

void CMFC_MULTI_THREAD_BARDlg::OnStart() 
{
	ToFilePath="D:\\test\\";
	::CreateThread(NULL,0,ThreadFun1,this,0,NULL);

}

void CMFC_MULTI_THREAD_BARDlg::OnBtnSelectfile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fileOpen(true);
	if(IDOK ==fileOpen.DoModal())
	{
		FilePath=fileOpen.GetPathName();
		CFile file(FilePath,CFile::modeRead);
		FileLen=file.GetLength();
		FileName=file.GetFileName();
		this->SetDlgItemText(IDC_STATIC_ORIGIN,FilePath);
		//this->MessageBox(fileOpen.GetPathName());
		//this->MessageBox(FilePath);
	}
}

void CMFC_MULTI_THREAD_BARDlg::OnBtnSelectpath() 
{
    char szPath[MAX_PATH];     //存放选择的目录路径 
    CString str;
    ZeroMemory(szPath, sizeof(szPath));   
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = "请选择需要打包的目录：";   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //弹出选择目录对话框
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   
    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
		ToFilePath=szPath;
		this->SetDlgItemText(IDC_STATIC_DESTIN,ToFilePath);
//        str.Format("选择的目录为 %s",  szPath);
//        AfxMessageBox(str);   
    }
    else   
        AfxMessageBox("无效的目录，请重新选择");   
}
