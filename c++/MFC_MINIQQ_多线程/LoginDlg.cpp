// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_MINIQQ.h"
#include "LoginDlg.h"
#include "MyButton.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_username = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_BUTTON_B2, m_b2);
	DDX_Control(pDX, IDC_BUTTON_B1, m_b1);
	DDX_Control(pDX, IDC_STATIC_ERROR, m_static_error);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_username);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDCANCEL, OnBtnCancel)
	ON_BN_CLICKED(IDOK, OnBtnOk)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_EXCHANGE, OnBtnExchange)
	ON_BN_CLICKED(IDC_RADIO_RED, OnRadioRed)
	ON_BN_CLICKED(IDC_RADIO_GREEN, OnRadioGreen)
	ON_BN_CLICKED(IDC_RADIO_BLUE, OnRadioBlue)
	ON_BN_CLICKED(IDC_RADIO_OTHER, OnRadioOther)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDD_MENU_ZI, OnMenuZi)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnBtnCancel() 
{
	// TODO: Add your control notification handler code here
	//this->OnBtnCancel();
	//this->CloseWindow();
	CDialog::OnCancel();
}

void CLoginDlg::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	//this->UpdateData(FALSE);
	CString s1,s2;
	this->GetDlgItemText(IDC_EDIT_USERNAME,s1);
	this->GetDlgItemText(IDC_EDIT_PASSWORD,s2);
	//if(m_password=="123" && m_password=="123")
	if(s1=="123" && s2=="123")
	{
		this->isvalid=TRUE;
		CDialog::OnOK();

	}
	else
	{
		CWnd *p= this->GetDlgItem(IDC_STATIC_ERROR);
		p->ShowWindow(SW_SHOW);
		this->SetTimer(110,3000,NULL);
		this->isvalid=FALSE;
	}

//	CDialog::OnOK();
}

void CLoginDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	this->KillTimer(110);
	CWnd *p= this->GetDlgItem(IDC_STATIC_ERROR);
	p->ShowWindow(SW_HIDE);
	CDialog::OnTimer(nIDEvent);
}

int CLoginDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	m_brush.CreateSolidBrush(RGB(255,0,0));

	CMenu menu;
	menu.LoadMenu(IDR_MENU);
	this->SetMenu(&menu);

	m_b1.m_other=&m_b2;
	m_b2.m_other=&m_b1;
	return 0;
}


HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO: Change any attributes of the DC here
	if(pWnd->m_hWnd==m_static_error.m_hWnd)
		pDC->SetTextColor(RGB(255,0,0));
	if(CTLCOLOR_STATIC==nCtlColor)
	{
		hbr = (HBRUSH)::GetStockObject(NULL_BRUSH);
		pDC->SetBkMode(TRANSPARENT);
	}
	if(CTLCOLOR_DLG==nCtlColor)
	{
		pDC->SetBkColor(0xff);
		pDC->SetBkMode(TRANSPARENT);
		hbr = ::CreateSolidBrush(RGB(255,255,0));
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CLoginDlg::OnBtnExchange() 
{
	// TODO: Add your control notification handler code here
	CString username,password,t;
	this->GetDlgItemText(IDC_EDIT_USERNAME,username);
	this->GetDlgItemText(IDC_EDIT_PASSWORD,password);
	this->SetDlgItemText(IDC_EDIT_USERNAME,password);
	this->SetDlgItemText(IDC_EDIT_PASSWORD,username);
	this->UpdateData(TRUE);
}

void CLoginDlg::OnRadioRed() 
{
//	CWnd *pWnd=this->GetDlgItem(IDC_STATIC_COLOR);
//	CRect rt;
//	pWnd->GetWindowRect(&rt);
//	this->ScreenToClient(&rt);
//	CClientDC dc(this);
//	dc.FillSolidRect(&rt,RGB(255,0,0));
	CWnd *pWnd=this->GetDlgItem(IDC_STATIC_COLOR);
	CRect rt;
	pWnd->GetWindowRect(&rt);
	CWindowDC dc(pWnd);
	pWnd->SetWindowText("hahaa");
	dc.FillSolidRect(0,0,50,50,RGB(255,0,0));
	CBrush brush(RGB(255,0,0));
	dc.FillRect(&rt,&brush);


	pWnd->ShowWindow(SW_SHOW);
	this->ScreenToClient(&rt);

}

void CLoginDlg::OnRadioGreen() 
{
	// TODO: Add your control notification handler code here
	CWnd *pWnd=this->GetDlgItem(IDC_STATIC_COLOR);
	CRect rt;
	pWnd->GetWindowRect(&rt);
	this->ScreenToClient(&rt);
	CClientDC dc(this);
	dc.FillSolidRect(&rt,RGB(0,255,0));
}

void CLoginDlg::OnRadioBlue() 
{
	// TODO: Add your control notification handler code here
	CWnd *pWnd=this->GetDlgItem(IDC_STATIC_COLOR);
	CRect rt;
	pWnd->GetWindowRect(&rt);
	this->ScreenToClient(&rt);
	CClientDC dc(this);
	dc.FillSolidRect(&rt,RGB(0,0,255));
}

void CLoginDlg::OnRadioOther() 
{
	// TODO: Add your control notification handler code here
	CWnd *pWnd=this->GetDlgItem(IDC_STATIC_COLOR);
	CRect rt;
	pWnd->GetWindowRect(&rt);
	this->ScreenToClient(&rt);
	CClientDC dc(this);

	CColorDialog color;
	COLORREF f;
	if(IDOK==color.DoModal())
	{
		f=color.GetColor();
	}
	dc.FillSolidRect(&rt,f);
	
}

void CLoginDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	//this->MessageBox("test");
	this->GetMenu()->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
}

void CLoginDlg::OnMenuZi()
{
	// TODO: Add your command handler code here
	this->MessageBox("×Ó²Ëµ¥");
	
}

