// ChatDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MINIQQ.h"
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
	m_Old = _T("");
	m_New = _T("");
	//}}AFX_DATA_INIT
}


void CChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDialog)
	DDX_Text(pDX, IDC_EDIT_INFO, m_Old);
	DDX_Text(pDX, IDC_EDIT_MSG, m_New);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChatDialog, CDialog)
	//{{AFX_MSG_MAP(CChatDialog)
	ON_BN_CLICKED(IDR_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDialog message handlers

void CChatDialog::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	CString sNew,sOld;
	this->GetDlgItemText(IDC_EDIT_INFO,sOld);
	this->GetDlgItemText(IDC_EDIT_MSG,sNew);
	if(sNew!="")
	{
		sOld=sOld+sNew+"\r\n";
		this->SetDlgItemText(IDC_EDIT_INFO,sOld);
		this->SendDlgItemMessage(IDC_EDIT_INFO, WM_VSCROLL, SB_BOTTOM, NULL);
		this->SetDlgItemText(IDC_EDIT_MSG,"");
	}
	CWnd *p=this->GetDlgItem(IDC_EDIT_MSG);
	p->SetFocus();
}
