// ChatRoomDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MiniQQ_V2.h"
#include "ChatRoomDialog.h"
#include "MFC_MiniQQ_V2Dlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatRoomDialog dialog


CChatRoomDialog::CChatRoomDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CChatRoomDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatRoomDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChatRoomDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatRoomDialog)
	DDX_Control(pDX, IDC_EDIT_OLDMSG, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChatRoomDialog, CDialog)
	//{{AFX_MSG_MAP(CChatRoomDialog)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatRoomDialog message handlers

void CChatRoomDialog::OnClose() 
{
	this->ShowWindow(SW_HIDE);
	//CDialog::OnClose();
}

void CChatRoomDialog::OnBtnSend() 
{
	CMFC_MiniQQ_V2Dlg *parent=(CMFC_MiniQQ_V2Dlg *)m_parent;
	MESSAGEHEAD msghead={0};
	msghead.flag=6;
	CString msg;
	this->GetDlgItemText(IDC_EDIT_NEWMSG,msg);
	msghead.iMsgLen=msg.GetLength();
	char *p=new char[msg.GetLength()+1];
	memset(p,0,msg.GetLength()+1);
	//p=msg.GetBuffer(msg.GetLength());
	strcpy(p,msg.GetBuffer(msg.GetLength()));
	if(SOCKET_ERROR==parent->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,CLASSBR))
		this->MessageBox("发送信息头失败");
	if(SOCKET_ERROR==parent->m_hSocket.SendTo(p,msg.GetLength(),MESSAGEPORT,CLASSBR))
		this->MessageBox("发送信息失败!");
//	else
//	{
//		m_list.AddString("我说:"+msg);
//		m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
//	}
	delete []p;
}
