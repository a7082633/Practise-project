// LoginDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MiniQQ_V2.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog


CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	//{{AFX_MSG_MAP(CLoginDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog message handlers



BOOL CLoginDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//////////////获取本地主机名
	char HostName[20]={0};
	::gethostname(HostName,sizeof(HostName));
	this->SetDlgItemText(IDC_STATIC_HOSTNAME,HostName);
	//////////////获取本地IP
	HOSTENT *pHost=::gethostbyname(HostName);
	struct in_addr addr;
	addr.s_addr = *(u_long *) pHost->h_addr_list[0];
    printf("\tFirst IP Address: %s\n", inet_ntoa(addr));
	this->SetDlgItemText(IDC_STATIC_HOSTIP,inet_ntoa(addr));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


