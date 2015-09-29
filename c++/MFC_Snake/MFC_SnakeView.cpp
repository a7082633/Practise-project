// MFC_SnakeView.cpp : implementation of the CMFC_SnakeView class
//

#include "stdafx.h"
#include "MFC_Snake.h"

#include "MFC_SnakeDoc.h"
#include "MFC_SnakeView.h"
CSbody gSnake;
int Speed=500;
int direct=4;
int n=0;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeView

IMPLEMENT_DYNCREATE(CMFC_SnakeView, CView)

BEGIN_MESSAGE_MAP(CMFC_SnakeView, CView)
	//{{AFX_MSG_MAP(CMFC_SnakeView)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeView construction/destruction

CMFC_SnakeView::CMFC_SnakeView()
{
	// TODO: add construction code here

}

CMFC_SnakeView::~CMFC_SnakeView()
{
}

BOOL CMFC_SnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.cx=400;
	cs.cy=500;
	cs.hMenu=NULL;
	cs.style &=~WS_MAXIMIZEBOX;
	cs.style &=~WS_SIZEBOX;
	cs.lpszName="贪吃蛇";
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeView drawing

void CMFC_SnakeView::OnDraw(CDC* pDC)
{
	CMFC_SnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rt;
	this->GetClientRect(&rt);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	//bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
	bmp.LoadBitmap(IDB_BITMAP1);
	memDC.SelectObject(bmp);
	memDC.FillSolidRect(0,0,rt.Width(),rt.Height(),0xffffff);
	OnDrawMem(&memDC);
	pDC->BitBlt(0,0,rt.Width(),rt.Height(),&memDC,0,0,SRCCOPY);

}

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeView printing

BOOL CMFC_SnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_SnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_SnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeView diagnostics

#ifdef _DEBUG
void CMFC_SnakeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_SnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_SnakeDoc* CMFC_SnakeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_SnakeDoc)));
	return (CMFC_SnakeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeView message handlers

void CMFC_SnakeView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd *cw=this->GetParent();
	::PostMessage(*cw,WM_NCLBUTTONDOWN,HTCAPTION,0);
	CView::OnLButtonDown(nFlags, point);
}

//DEL void CMFC_SnakeView::OnMouseMove(UINT nFlags, CPoint point) 
//DEL {
//DEL 	// TODO: Add your message handler code here and/or call default
//DEL 	CView::OnMouseMove(nFlags, point);
//DEL }

void CMFC_SnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==27) ::PostQuitMessage(0);
	if(nChar==VK_UP) 
	{
		if(direct!=2)
		{
			this->KillTimer(110);
			direct=1;
			this->SetTimer(110,Speed,NULL);
			this->Invalidate();
		}
	}
	if(nChar==VK_DOWN) 
	{
		if(direct!=1)
		{
			this->KillTimer(110);
			direct=2;
			this->SetTimer(110,Speed,NULL);
			this->Invalidate();
		}
	}
	if(nChar==VK_LEFT) 
	{
		if(direct!=4)
		{
			this->KillTimer(110);
			direct=3;
			this->SetTimer(110,Speed,NULL);
			this->Invalidate();
		}
	}
	if(nChar==VK_RIGHT) 
	{
		if(direct!=3)
		{
			this->KillTimer(110);
			direct=4;
			this->SetTimer(110,Speed,NULL);
			this->Invalidate();
		}
	}
	if(nChar==VK_F1) 
	{
		gSnake.ReStart(direct);
		this->SetTimer(110,Speed,NULL);
		this->SetFocus();
	}
	if(nChar==VK_F2)
	{
		Speed-=50;
		this->SetTimer(110,Speed,NULL);
		this->SetFocus();
	}
	if(nChar==VK_F3)
	{
		Speed+=50;
		this->SetTimer(110,Speed,NULL);
		this->SetFocus();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CMFC_SnakeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	this->SetFocus();
	this->CenterWindow();
	// TODO: Add your specialized creation code here
	this->SetTimer(110,Speed,NULL);
	return 0;
}

void CMFC_SnakeView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	this->KillTimer(110);
	
}

void CMFC_SnakeView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	this->Invalidate();
	CView::OnTimer(nIDEvent);
}

BOOL CMFC_SnakeView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE; //CView::OnEraseBkgnd(pDC);
}

void CMFC_SnakeView::OnDrawMem(CDC *pDC)
{
	pDC->Rectangle(10,10,250,450);
////////////////////绘出游戏///////////////
	gSnake.CreateFood(pDC);
	if(!gSnake.isFood(direct)) gSnake.Move(direct);
	if(gSnake.IsHitBody(direct)||gSnake.Snake.front().Nx+1>23||gSnake.Snake.front().Nx-1<0||gSnake.Snake.front().Ny+1>13||gSnake.Snake.front().Ny-1<0)
	{
		this->KillTimer(110);
		n=this->MessageBox("game over!would you like play again?","game over",MB_YESNO);
		if(n==IDYES)
		{
			gSnake.ReStart(direct);
			this->SetTimer(110,Speed,NULL);
			this->SetFocus();
		}
		else
			exit(0);
	}
	gSnake.DrawBody(pDC);
	CRect rt;
	rt.left=260;
	rt.top=20;
	rt.right=380;
	rt.bottom=200;
	CString s="游戏说明:\n\n方向键控制\n\nESC退出游戏\n\nF1重新开始\n\nF2加速\n\nF3减速";
	pDC->DrawText(s,&rt,DT_VCENTER|DT_CENTER);
	s.Empty();
	rt.left=260;
	rt.top=240;
	rt.right=380;
	rt.bottom=290;
	s="游戏状态:\n\n您当前得分:4";
	s.Format("游戏状态:\n\n您当前得分:%d",gSnake.Snake.size()-2);
	pDC->SetTextColor(RGB(255,0,255));
	pDC->DrawText(s,&rt,DT_VCENTER|DT_CENTER);
	rt.left=260;
	rt.top=340;
	rt.right=380;
	rt.bottom=390;
	s="版本号:1.0\n\n作者:天生一指禅";
	pDC->SetTextColor(RGB(255,0,0));
	pDC->DrawText(s,&rt,DT_VCENTER|DT_CENTER);
}
