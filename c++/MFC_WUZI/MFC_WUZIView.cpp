// MFC_WUZIView.cpp : implementation of the CMFC_WUZIView class
//

#include "stdafx.h"
#include "MFC_WUZI.h"

#include "MFC_WUZIDoc.h"
#include "MFC_WUZIView.h"
//#include "Wuzi.h"

int Chess[15][15]={0};
int px;
int py;
BOOL BWho=false;
BOOL IsDone=false;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIView

IMPLEMENT_DYNCREATE(CMFC_WUZIView, CView)

BEGIN_MESSAGE_MAP(CMFC_WUZIView, CView)
	//{{AFX_MSG_MAP(CMFC_WUZIView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIView construction/destruction

CMFC_WUZIView::CMFC_WUZIView()
{
	// TODO: add construction code here

}

CMFC_WUZIView::~CMFC_WUZIView()
{
}

BOOL CMFC_WUZIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	//cs.lpszName="五子棋";
	cs.style &=~WS_MAXIMIZEBOX;
	cs.style &=~WS_SIZEBOX;
	//cs.lpszClass="aaaaaaaaa";
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIView drawing

void CMFC_WUZIView::OnDraw(CDC* pDC)
{
	CMFC_WUZIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rt;
	this->GetClientRect(&rt);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
//	bmp.LoadBitmap(IDB_BITMAP1);
	memDC.SelectObject(bmp);
	memDC.FillSolidRect(&rt,0xffffff);
	OnDrawMem(&memDC);
	pDC->BitBlt(0,0,rt.Width(),rt.Height(),&memDC,0,0,SRCCOPY);
	memDC.DeleteDC();
	bmp.DeleteObject();



	// TODO: add draw code for native data hereW
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIView printing

BOOL CMFC_WUZIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_WUZIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_WUZIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIView diagnostics

#ifdef _DEBUG
void CMFC_WUZIView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_WUZIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_WUZIDoc* CMFC_WUZIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_WUZIDoc)));
	return (CMFC_WUZIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIView message handlers

void CMFC_WUZIView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!IsDone)
	{
//		int x=LOWORD(lParam);
//		int y=HIWORD(lParam);
		int x=point.x;
		int y=point.y;
		if(x<490&&y<490)
			if(BWho)
			{
				if(Chess[y/33][x/33]==0)
				{
					Chess[y/33][x/33]=1;
					BWho=!BWho;
					this->Invalidate();
				}
			}
			else
			{
				if(Chess[y/33][x/33]==0)
				{
					Chess[y/33][x/33]=2;
					BWho=!BWho;
					this->Invalidate();
				}
			}
			//::MessageBox(NULL,"TEST",NULL,MB_OK);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMFC_WUZIView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	this->Invalidate();
	CView::OnTimer(nIDEvent);
}

void CMFC_WUZIView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == VK_ESCAPE) ::PostQuitMessage(0);
	if (nChar == VK_F1)
	{
		ClearChess();
		IsDone=!IsDone;
		this->Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CMFC_WUZIView::Check(int x, int y)
{
	int count=0;
	int px=x,py=y;
	while(py-1>=0)//左横向
	{
		if(Chess[x][y]==Chess[px][py-1])
		{
			py--;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(py+1<15)//右横向
	{
		if(Chess[x][y]==Chess[px][py+1])
		{
			count++;
			py++;
		}
		else
			break;
	}
	if(count>=4)
	{
		//printf("%s win!",Chess[x][y]);
		return Chess[x][y];
		//exit(0);
	}
	px=x;
	py=y;
	count=0;
	///////////////////////////////纵向、//////////////
	while(px-1>=0)//上
	{
		if(Chess[x][y]==Chess[px-1][py])
		{
			px--;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(px+1<15)//下
	{
		if(Chess[x][y]==Chess[px+1][py])
		{
			count++;
			px++;
		}
		else
			break;
	}
	if(count>=4)
	{
		return Chess[x][y];
	}
	px=x;
	py=y;
	count=0;
	///////////////////////////////斜向一、//////////////
	while(px-1>=0&&py-1>=0)//左上
	{
		if(Chess[x][y]==Chess[px-1][py-1])
		{
			px--;
			py--;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(px+1<15&&py+1<15)//右下
	{
		if(Chess[x][y]==Chess[px+1][py+1])
		{
			count++;
			px++;
			py++;
		}
		else
			break;
	}
	if(count>=4)
	{
		return Chess[x][y];
	}
	px=x;
	py=y;
	count=0;
		///////////////////////////////斜向二、//////////////
	while(px-1>=0&&py+1<15)//右上
	{
		if(Chess[x][y]==Chess[px-1][py+1])
		{
			px--;
			py++;
			count++;
		}
		else
			break;
	}
	px=x;
	py=y;
	while(px+1<15&&py-1>=0)//左下
	{
		if(Chess[x][y]==Chess[px+1][py-1])
		{
			count++;
			px++;
			py--;
		}
		else
			break;
	}
	if(count>=4)
	{
		return Chess[x][y];
	}
	return 0;
}

void CMFC_WUZIView::ClearChess()
{
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			Chess[i][j]=0;
}

int CMFC_WUZIView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	//this->SetWindowText("五子棋");
	//::SetTitle("五子棋");
	return 0;
}



void CMFC_WUZIView::OnDrawMem(CDC *pDC)
{
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	//bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
	bmp.LoadBitmap(IDB_BITMAP1);
	memDC.SelectObject(bmp);
	pDC->BitBlt(10,10,463,463,&memDC,0,0,SRCCOPY);

	char sz[50]="游戏说明:\n\nF1重新开始\n\nESC退出游戏";
	RECT rt;
	rt.left=633-100;
	rt.top=30;
	rt.right=633+100;
	rt.bottom=140;
	pDC->DrawText(sz,strlen(sz),&rt,DT_CENTER|DT_VCENTER);
	
	char sz2[50]="游戏状态:";
	rt.left=633-100;
	rt.top=150;
	rt.right=633+100;
	rt.bottom=200;
	pDC->DrawText(sz2,strlen(sz2),&rt,DT_CENTER|DT_VCENTER);
	if(BWho)
	{
		HBRUSH hBrush=::CreateSolidBrush(0xff);
		HBRUSH OldBrush=(HBRUSH)pDC->SelectObject(hBrush);
		pDC->Ellipse(575-10,196-10,575+10,196+10);
		pDC->SelectObject(OldBrush);
		::DeleteObject(hBrush);
	}
	else
	{
		HBRUSH hBrush=::CreateSolidBrush(0x0);
		HBRUSH OldBrush=(HBRUSH)pDC->SelectObject(hBrush);
		pDC->Ellipse(575-10,196-10,575+10,196+10);
		pDC->SelectObject(OldBrush);
		::DeleteObject(hBrush);
	}
	char sz3[50]="正在下棋";
	rt.left=631-30;
	rt.top=187;
	rt.right=633+30;
	rt.bottom=250;
	pDC->DrawText(sz3,strlen(sz3),&rt,DT_CENTER|DT_VCENTER);
	
	HPEN Pen=::CreatePen(PS_SOLID,1,0xff);
	HPEN OldPen=(HPEN)pDC->SelectObject(Pen);
	int i , j;
	for(i=0;i<15;i++)
	{
		pDC->MoveTo(10,(i)*33+10);
		pDC->LineTo(472,(i)*33+10);
	}
	for(i=0;i<15;i++)
	{
		pDC->MoveTo((i)*33+10,10);
		pDC->LineTo((i)*33+10,472);
	}
	
	char *str="版本号:V1.0";
	pDC->TextOut(590,388,str,strlen(str));
	str="作者:天生一指禅";
	pDC->TextOut(590,420,str,strlen(str));
	//遍历棋盘
	int WhoWin=5;
	for(i=0;i<15;i++)
		for(j=0;j<15;j++)
		{
			if(Chess[i][j]==1)
			{
				if(0==i)	py=10;
				else		py=i*33+10;
				if(0==j)	px=10;
				else		px=j*33+10;
				HBRUSH hBrush=::CreateSolidBrush(0xff);
				HBRUSH OldBrush=(HBRUSH)pDC->SelectObject(hBrush);
				pDC->Ellipse(px-10,py-10,px+10,py+10);
				pDC->SelectObject(OldBrush);
				::DeleteObject(hBrush);
				if(Check(i,j)==1)
				{
					WhoWin=1;
				}
			}
			if(Chess[i][j]==2)
			{
				if(0==i)	py=10;
				else		py=i*33+10;
				if(0==j)	px=10;
				else		px=j*33+10;
				HBRUSH hBrush=::CreateSolidBrush(0x0);
				HBRUSH OldBrush=(HBRUSH)pDC->SelectObject(hBrush);
				pDC->Ellipse(px-10,py-10,px+10,py+10);
				pDC->SelectObject(OldBrush);
				::DeleteObject(hBrush);
				if(Check(i,j)==2)
				{
					WhoWin=2;
				}
			}
		}
		if(!IsDone)
		{
			if(WhoWin==1)
			{
				if(IDYES==this->MessageBox("红方胜利!不服？再来一次？","游戏结束!",MB_YESNO))
				{
					ClearChess();
					this->Invalidate();
				}
				else	IsDone=!IsDone;
			}
			if(WhoWin==2)
			{
				if(IDYES==this->MessageBox("黑方胜利!不服？再来一次？","游戏结束!",MB_YESNO))
				{
					ClearChess();
					this->Invalidate();
				}
				else	IsDone=!IsDone;
			}
		}
		::DeleteObject(Pen);
}

BOOL CMFC_WUZIView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}
