// ChatDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MiniQQ_V1.h"
#include "ChatDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatDialog dialog


CChatDialog::CChatDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDialog)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChatDialog, CDialog)
	//{{AFX_MSG_MAP(CChatDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDialog message handlers
