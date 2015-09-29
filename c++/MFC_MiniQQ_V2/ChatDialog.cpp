// ChatDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MiniQQ_V2.h"
#include "ChatDialog.h"
#include "MFC_MiniQQ_V2Dlg.h"
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
	m_sIP="255.255.255.255";
}


void CChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDialog)
	DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_BTN_ACCEPT, m_btnaccept);
	DDX_Control(pDX, IDC_BTN_SENDF, m_btnsentf);
	DDX_Control(pDX, IDC_BTN_REJECT, m_btnreject);
	DDX_Control(pDX, IDC_BTN_BROWSER, m_btnbrowser);
	DDX_Control(pDX, IDC_EDIT_OLDMSG, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChatDialog, CDialog)
	//{{AFX_MSG_MAP(CChatDialog)
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_BROWSER, OnBtnBrowser)
	ON_BN_CLICKED(IDC_BTN_SENDF, OnBtnSendf)
	ON_BN_CLICKED(IDC_BTN_ACCEPT, OnBtnAccept)
	ON_BN_CLICKED(IDC_BTN_REJECT, OnBtnReject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDialog message handlers

void CChatDialog::OnBtnSend() 
{
	CMFC_MiniQQ_V2Dlg *parent=(CMFC_MiniQQ_V2Dlg *)m_parent;
	MESSAGEHEAD sgmsghead;
	CString msg;
	this->GetDlgItemText(IDC_EDIT_NEWMSG,msg);
	//char *p=new char[msg.GetLength()+1];
	char *p=(char *)malloc(msg.GetLength()+1);
	//char p[msg.GetLength()+1];
	memset(p,0,msg.GetLength()+1);
	//p=msg.GetBuffer(msg.GetLength());
	strcpy(p,msg.GetBuffer(msg.GetLength()));
	sgmsghead.flag=4;
	sgmsghead.iMsgLen=msg.GetLength();
	if(parent->m_hSocket.SendTo(&sgmsghead,sizeof(MESSAGEHEAD),MESSAGEPORT,m_sIP)==SOCKET_ERROR)
		this->MessageBox("发送信息头失败！");
	int nSend=parent->m_hSocket.SendTo(p,msg.GetLength(),MESSAGEPORT,m_sIP);
	::Sleep(200);
	int n=parent->m_hSocket.GetLastError();
	if(nSend<0)
		this->MessageBox("发送信息失败！");
	else
	{
		m_list.AddString("我说:"+msg);
		m_list.PostMessage(WM_VSCROLL,SB_BOTTOM);
	}
	this->SetFocus();
	//::Sleep(1000);
	free(p);
	//delete []p;
}



void CChatDialog::OnClose() 
{
	this->ShowWindow(SW_HIDE);
//	CMFC_MiniQQ_V2Dlg *p=(CMFC_MiniQQ_V2Dlg *)m_parent;
//	for(int i=0;i<p->m_wndArray.GetSize();i++)
//	{
//		CChatDialog *pChat=(CChatDialog *)p->m_wndArray.GetAt(i);
//		if(pChat->m_sIP==m_sIP)
//		{
//			//delete pChat;
//			p->m_wndArray.RemoveAt(i);
//		}
//	}
	CDialog::OnClose();
}

void CChatDialog::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}




void CChatDialog::OnBtnBrowser() 
{
	//CString FilePath,FileName;
	CFileDialog fileOpen(true);
	if(IDOK==fileOpen.DoModal())
	{
		FilePath=fileOpen.GetPathName();
		this->SetDlgItemText(IDC_EDIT_SELECT,FilePath);
	}
}

void CChatDialog::OnBtnSendf() 
{
	MESSAGEHEAD msghead={0};
	msghead.flag=8;
	CMFC_MiniQQ_V2Dlg *parent=(CMFC_MiniQQ_V2Dlg *)m_parent;
	parent->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,m_sIP);
}
DWORD WINAPI RevFileThread(LPVOID p)
{
	TMSG *tmsg=(TMSG *)p;
	CChatDialog *pDlg=(CChatDialog *)tmsg->pDlg;
	SOCKET m_hSocket=tmsg->m_hSocket;
//	CChatDialog *pDlg=(CChatDialog *)p;
//	SOCKET m_hSocket=socket(AF_INET,SOCK_STREAM,0);
//	if (INVALID_SOCKET == m_hSocket)
//	{
//		::AfxMessageBox("创建套接字失败！");
//	}
//	SOCKADDR_IN addr={0};
//	addr.sin_family=AF_INET;
//	addr.sin_port=htons(7789);
//	addr.sin_addr.S_un.S_addr=0;
//	if(SOCKET_ERROR==bind(m_hSocket,(SOCKADDR *)&addr,sizeof(SOCKADDR)))
//	{
//		::AfxMessageBox("绑定套接字失败");
//	}
//	if(SOCKET_ERROR==listen(m_hSocket, 5))
//	{
//		::AfxMessageBox("监听失败！");
//	}

	 //接受客户端连接请求	
	SOCKET sockConn;
	SOCKADDR_IN skafrmddr={0};
	int addrlen=sizeof(sockaddr);
	sockConn = accept(m_hSocket,(sockaddr *)&skafrmddr,&addrlen); //阻塞
	FILEHEAD fh={0};
	recv(sockConn,(char *)&fh,sizeof(FILEHEAD),0);
	CString path;
	path.Format("%s\\%s",pDlg->ToFilePath,fh.FileName);
	CFile file(path,CFile::typeBinary|CFile::modeCreate|CFile::modeWrite);
	UINT nReceived = 0;
	pDlg->SetDlgItemText(IDC_EDIT_SELECT2,"正在接收文件至:"+path);
	while(nReceived<fh.FileLen)
	{
		char buf[1024]={0};
		int nRead=recv(sockConn,buf,1024,0);
		if(nRead>0)
		{
			file.Write(buf,nRead);
			nReceived+=nRead;
			int n=nReceived*1.0/fh.FileLen*100;
			pDlg->m_progress2.SetPos(n);
		}
	}
	pDlg->m_progress2.SetPos(0);
	pDlg->m_btnbrowser.ShowWindow(SW_SHOW);
	pDlg->m_btnsentf.ShowWindow(SW_SHOW);
	pDlg->m_btnaccept.ShowWindow(SW_HIDE);
	pDlg->m_btnreject.ShowWindow(SW_HIDE);
	//pDlg->MessageBox("接收完成!");
	pDlg->SetDlgItemText(IDC_EDIT_SELECT2,"接收完成!");
	file.Close();
	::closesocket(sockConn);
	delete []p;
	return 0;
}
void CChatDialog::OnBtnAccept() 
{
	///打开目录选择
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
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);   
    if(lp && SHGetPathFromIDList(lp, szPath))   
    {
		ToFilePath=szPath;
		//this->SetDlgItemText(IDC_EDIT_SELECT,ToFilePath); 
    }
    else
	{
        //AfxMessageBox("无效的目录，请重新选择");
		this->MessageBox("无效的目录，请重新选择");
		return;
	}
	//隐藏所有按钮
	m_btnbrowser.ShowWindow(SW_SHOW);
	m_btnsentf.ShowWindow(SW_SHOW);
	m_btnaccept.ShowWindow(SW_HIDE);
	m_btnreject.ShowWindow(SW_HIDE);
	////----------发送同意信息头
	MESSAGEHEAD msghead={0};
	msghead.flag=81;
	CMFC_MiniQQ_V2Dlg *parent=(CMFC_MiniQQ_V2Dlg *)m_parent;
	parent->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,m_sIP);

	//-----------建立套接字(server)
	TMSG *tmsg=new TMSG;
	tmsg->m_hSocket=parent->m_socketTCP;
	tmsg->pDlg=this;
	::CreateThread(NULL,0,RevFileThread,tmsg,0,NULL);
}

void CChatDialog::OnBtnReject() 
{
	m_btnbrowser.ShowWindow(SW_SHOW);
	m_btnsentf.ShowWindow(SW_SHOW);
	m_btnaccept.ShowWindow(SW_HIDE);
	m_btnreject.ShowWindow(SW_HIDE);
	MESSAGEHEAD msghead={0};
	msghead.flag=82;
	CMFC_MiniQQ_V2Dlg *parent=(CMFC_MiniQQ_V2Dlg *)m_parent;
	parent->m_hSocket.SendTo(&msghead,sizeof(MESSAGEHEAD),MESSAGEPORT,m_sIP);
}



BOOL CChatDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_btnaccept.ShowWindow(SW_HIDE);
	m_btnreject.ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
