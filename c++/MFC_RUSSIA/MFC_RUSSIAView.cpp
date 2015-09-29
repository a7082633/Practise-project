// MFC_RUSSIAView.cpp : implementation of the CMFC_RUSSIAView class
//

#include "stdafx.h"
#include "MFC_RUSSIA.h"

#include "MainFrm.h"
#include "MFC_RUSSIADoc.h"
#include "MFC_RUSSIAView.h"
#include "Shape.h"
#include "RussiaGame.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CShape shape;
CShape newshape;
int Speed=500;
BOOL isPause=false;
int rof=0;
/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAView

IMPLEMENT_DYNCREATE(CMFC_RUSSIAView, CView)

BEGIN_MESSAGE_MAP(CMFC_RUSSIAView, CView)
	//{{AFX_MSG_MAP(CMFC_RUSSIAView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_RBUTTONDOWN()
	ON_WM_SIZE()
	ON_COMMAND(ID_GAME_ASPEED, OnGameAspeed)
	ON_COMMAND(ID_GAME_EXIT, OnGameExit)
	ON_COMMAND(ID_GAME_NEW, OnGameNew)
	ON_COMMAND(ID_GAME_PAUSE, OnGamePause)
	ON_COMMAND(ID_GAME_RESTART, OnGameRestart)
	ON_COMMAND(ID_GAME_RESUME, OnGameResume)
	ON_COMMAND(ID_GAME_SSPEED, OnGameSspeed)
	//}}AFX_MSG_MAP
	// Standard printing commands
	{UM_TRAY_NOTIFY, 0, 0, 0,AfxSig_vwp,(AFX_PMSG)(AFX_PMSGW)(void (AFX_MSG_CALL CWnd::*)(WPARAM,LPARAM))&OnTrayNotify},
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAView construction/destruction

CMFC_RUSSIAView::CMFC_RUSSIAView()
{
	// TODO: add construction code here
	//icon=::LoadIcon(NULL,MAKEINTRESOURCE(IDR_ICON1));
	//icon=AfxGetApp()->LoadIcon(IDR_ICON1);
	icon=::LoadIcon(::AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_ICON1));
}

CMFC_RUSSIAView::~CMFC_RUSSIAView()
{
}

BOOL CMFC_RUSSIAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAView drawing

void CMFC_RUSSIAView::OnDraw(CDC* pDC)
{
	CMFC_RUSSIADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rt;
	this->GetClientRect(&rt);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
	memDC.SelectObject(bmp);
	memDC.FillSolidRect(&rt,RGB(255,255,255));

	OnDrawMem(&memDC);

	pDC->BitBlt(0,0,rt.Width(),rt.Height(),&memDC,0,0,SRCCOPY);
	memDC.DeleteDC();
	bmp.DeleteObject();


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAView printing

BOOL CMFC_RUSSIAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_RUSSIAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_RUSSIAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAView diagnostics

#ifdef _DEBUG
void CMFC_RUSSIAView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_RUSSIAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_RUSSIADoc* CMFC_RUSSIAView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_RUSSIADoc)));
	return (CMFC_RUSSIADoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAView message handlers

void CMFC_RUSSIAView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame *p=(CMainFrame *)this->GetParent();
	CString szNow;
	szNow.Format("%d,%d",point.x,point.y);
	p->m_wndStatusBar.SetPaneText(1,szNow);
	CView::OnMouseMove(nFlags, point);
}

void CMFC_RUSSIAView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd *parent=this->GetParent();
	::PostMessage(parent->m_hWnd,WM_NCLBUTTONDOWN,HTCAPTION,0);
	CView::OnLButtonDown(nFlags, point);
}

void CMFC_RUSSIAView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==27) ::PostQuitMessage(0);
	if(nChar==VK_UP) 
	{
		Game.ClearOldShape();
		shape.RotateShape(Game.m_Data);
		this->Invalidate();
	}
	if(nChar==VK_DOWN) 
	{
		if(Game.isLandOrShape(shape)) return;
		Game.ClearOldShape();
		shape.point.x+=1;
		this->Invalidate();
	}
	if(nChar==VK_LEFT) 
	{
		if(Game.IsWallLeft(shape))	return;
		if(Game.IsShapeLeft(shape)) return;
		Game.ClearOldShape();
		shape.point.y-=1;
		this->Invalidate();
	}
	if(nChar==VK_RIGHT) 
	{
		if(Game.IsWallRight(shape))	return;
		if(Game.IsShapeRight(shape)) return;
		Game.ClearOldShape();
		shape.point.y+=1;
		this->Invalidate();
	}
	if(nChar==VK_SPACE)
	{
		if(!isPause)
		{
			this->KillTimer(110);
			isPause=!isPause;
		}
		else
		{
			this->SetTimer(110,Speed,NULL);
			isPause=!isPause;
		}
	}
	if(nChar==VK_F1)
	{
		shape.NewShape();
		newshape.NewShape();
		this->SetTimer(110,Speed,NULL);
		this->SetTimer(111,50,NULL);
	}
	if(nChar==VK_F2)
	{
		shape.NewShape();
		newshape.NewShape();
		Game.ReStartGame(shape);
		this->SetTimer(110,Speed,NULL);
	}
	if(nChar==VK_F3)
	{
		Speed-=50;
		this->SetTimer(110,Speed,NULL);
	}
	if(nChar==VK_F4)
	{
		Speed+=50;
		this->SetTimer(110,Speed,NULL);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CMFC_RUSSIAView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	TrayAdd();
	m_imageList.Create(IDB_BITMAP2,30,4,RGB(255,255,0));
	return 0;
}

void CMFC_RUSSIAView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==111)
	{
		this->Invalidate();
		return;
	}
	if(Game.isLandOrShape(shape))
	{
		Game.PutDataIn(shape);
		if(Game.IsGameOver())
		{
			this->KillTimer(110);
			if(IDYES==this->MessageBox("GameOver!would you like play again","游戏提示",MB_YESNO))
			{
				Speed=500;
				shape.NewShape();
				newshape.NewShape();
				Game.ReStartGame(shape);
				this->SetTimer(110,Speed,NULL);
				return;
			}
			else
			{
				return;
			}
		}
		Game.CheckLine(shape);
		CMainFrame  *parent=(CMainFrame *)this->GetParent();
		CString s;
		s.Format("得分：%d",Game.Score);
		parent->m_wndStatusBar.SetPaneText(2,s);
		shape=newshape;
		newshape.NewShape(); 
	}
	else
	{
		Game.ClearOldShape();
		shape.point.x+=1;
	}
	this->Invalidate();
	CView::OnTimer(nIDEvent);
}

void CMFC_RUSSIAView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	TrayDelete();
	this->KillTimer(110);
	this->KillTimer(111);
}


BOOL CMFC_RUSSIAView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}

void CMFC_RUSSIAView::OnDrawMem(CDC *pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	memDC.SelectObject(bmp);


	/////////////////画出框框
	CRect rt;
	rt.left=10;
	rt.top=10;
	rt.right=470;
	rt.bottom=490;
	pDC->Rectangle(&rt);

	int i=0;
	int j=0;
	////////////////////////////画游戏区
	rt.left=10; rt.top=10; rt.right=310; rt.bottom=490;
	pDC->Rectangle(&rt);
	////////////////////////////画下一方块区
	rt.left=310; rt.top=10; rt.right=470; rt.bottom=250;
	pDC->FillSolidRect(&rt,RGB(0,128,255));
	rt.left=310; rt.top=180; rt.right=470; rt.bottom=240;
	pDC->DrawText("下一个方块",&rt,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
	////////////////////////////画游戏提示区
	rt.left=310; rt.top=250; rt.right=470; rt.bottom=490;
	pDC->FillSolidRect(&rt,RGB(255,255,0));
	rt.left=310; rt.top=270; rt.right=470; rt.bottom=490;
	pDC->DrawText("F1开始游戏\n\n F2重新开始\n\n F3游戏加速\n\n F4游戏减速\n\n Space暂停游戏 \n\n ↓加快下滑\n\n <-->控制方向",&rt,DT_CENTER | DT_VCENTER);
//	for(i=0;i<ROW;i++)
//	{
//		for(j=0;j<COL;j++)
//		{
//			rt.left=10+j*30;
//			rt.top=10+i*30;
//			rt.right=10+(j+1)*30;
//			rt.bottom=10+(i+1)*30;
//			pDC->Rectangle(&rt);
//		}
//	}
	////////////////////////画下一方块
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(newshape.m_nData[i][j]==2)
			{
				CBrush brush(RGB(255,0,0));
				CBrush *oldbrush=(CBrush *)pDC->SelectObject(brush);
				rt.left=340+j*30;
				rt.top=50+i*30;
				rt.right=340+(j+1)*30;
				rt.bottom=50+(i+1)*30;
				pDC->Rectangle(&rt);
				pDC->SelectObject(&oldbrush);
				brush.DeleteObject();
				CPoint p;
				p.x=338+j*30;
				p.y=48+i*30;
				if(rof>3) rof=0;
				//m_imageList.Draw(pDC,rof,p,ILD_NORMAL);
				m_imageList.DrawIndirect(pDC,rof,p,CSize(28,28),CPoint(0,0));
				//pDC->BitBlt(338+j*30,48+i*30,28,28,&memDC,0,0,SRCCOPY);
			}
	////////////////////////////画当前游戏方块
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(shape.m_nData[i][j]==2)
			{
				Game.m_Data[i+shape.point.x][j+shape.point.y]=2;
			}
		}
	}
//////////////////////////////遍历棋盘
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(Game.m_Data[i][j]==1||Game.m_Data[i][j]==2)
			{
				CBrush brush(RGB(255,0,0));
				CBrush *oldbrush=(CBrush *)pDC->SelectObject(brush);
				rt.left=10+j*30;
				rt.top=10+i*30;
				rt.right=10+(j+1)*30;
				rt.bottom=10+(i+1)*30;
				pDC->Rectangle(&rt);
				pDC->SelectObject(&oldbrush);
				brush.DeleteObject();
				//pDC->BitBlt(rt.left-2,rt.top-2,28,28,&memDC,0,0,SRCCOPY);
				CPoint p;
				p.x=rt.left-2;
				p.y=rt.top-2;
				if(rof>3) rof=0;
				//m_imageList.Draw(pDC,rof,p,ILD_NORMAL);
				m_imageList.DrawIndirect(pDC,rof,p,CSize(28,28),CPoint(0,0));
			}
		}
	}
	rof++;
}

void CMFC_RUSSIAView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//this->ShowWindow(SW_HIDE);
	CView::OnRButtonDown(nFlags, point);
}

void CMFC_RUSSIAView::TrayAdd()  //注册托盘
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,				//托盘号 
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		icon,
		"俄罗斯方块"
	};
	int iErr = Shell_NotifyIcon(NIM_ADD, &nid);
}

void CMFC_RUSSIAView::TrayDelete() //删除托盘
{
	NOTIFYICONDATA nid =
	{
		sizeof(NOTIFYICONDATA),
		this->m_hWnd,
		100,
		NIF_MESSAGE | NIF_ICON | NIF_TIP,
		UM_TRAY_NOTIFY,
		icon,
		"俄罗斯方块"
	};
	int iErr = Shell_NotifyIcon(NIM_DELETE, &nid);
}

LRESULT CMFC_RUSSIAView::OnTrayNotify(WPARAM uID, LPARAM lEvent)
{
	if(uID==100)
	{
		switch(lEvent)
		{
		case WM_LBUTTONDBLCLK:
			{
			ShowMyWindow();
//			CWnd *parent=this->GetParent();
//			this->SetFocus();
//			parent->SetActiveWindow();
//			parent->SetFocus();
			}
			break;
		case WM_RBUTTONDOWN:
			CMainFrame *parent=(CMainFrame *)this->GetParent();
			CPoint point;
			::GetCursorPos(&point);
			parent->GetMenu()->GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
			break;
		}
	}
	return 0;
}

void CMFC_RUSSIAView::HideWindow()
{
	CWnd *parent=this->GetParent();
	parent->ShowWindow(SW_HIDE);
}

void CMFC_RUSSIAView::ShowMyWindow()
{
	CWnd *parent=this->GetParent();
	parent->ShowWindow(SW_SHOWNOACTIVATE);
	parent->SetForegroundWindow();
}




void CMFC_RUSSIAView::OnGameAspeed() 
{
	// TODO: Add your command handler code here
	Speed-=50;
	this->SetTimer(110,Speed,NULL);
}

void CMFC_RUSSIAView::OnGameExit() 
{
	// TODO: Add your command handler code here
	this->KillTimer(110);
	::PostQuitMessage(0);
	
}

void CMFC_RUSSIAView::OnGameNew() 
{
	// TODO: Add your command handler code here
	shape.NewShape();
	newshape.NewShape();
	Game.ReStartGame(shape);
	this->SetTimer(110,Speed,NULL);
	
}

void CMFC_RUSSIAView::OnGamePause() 
{
	// TODO: Add your command handler code here
	this->KillTimer(110);
	
}

void CMFC_RUSSIAView::OnGameRestart() 
{
	// TODO: Add your command handler code here
	shape.NewShape();
	newshape.NewShape();
	Game.ReStartGame(shape);
	this->SetTimer(110,Speed,NULL);
	
}

void CMFC_RUSSIAView::OnGameResume() 
{
	// TODO: Add your command handler code here
	this->SetTimer(110,Speed,NULL);
}

void CMFC_RUSSIAView::OnGameSspeed() 
{
	// TODO: Add your command handler code here
	Speed-=50;
	this->SetTimer(110,Speed,NULL);
}
