// DialogSendMSG.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Broadcast_Server.h"
#include "DialogSendMSG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogSendMSG dialog


CDialogSendMSG::CDialogSendMSG(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSendMSG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogSendMSG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogSendMSG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogSendMSG)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogSendMSG, CDialog)
	//{{AFX_MSG_MAP(CDialogSendMSG)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogSendMSG message handlers

void CDialogSendMSG::OnOK() 
{
	BYTE m_bufSend[PACKSIZE]={0};
	PACKHEAD ph={0};
	ph.nFlag=PH_USER_MSG;
	SOCKADDR_IN m_addrTo={0};
	m_addrTo.sin_family = AF_INET;
	m_addrTo.sin_addr.S_un.S_addr = inet_addr(m_sIP);
	m_addrTo.sin_port = htons(UDP_PORT);

	CString Smsg;
	GetDlgItemText(IDC_EDIT_MSG,Smsg);
	memcpy(m_bufSend,&ph,sizeof(PACKHEAD));
	memcpy(m_bufSend+sizeof(PACKHEAD),Smsg,Smsg.GetLength());

	int n=::sendto(m_hSocket, (char *)m_bufSend,PACKSIZE, 0, (SOCKADDR *)&m_addrTo, sizeof(SOCKADDR));
	CDialog::OnOK();
}
