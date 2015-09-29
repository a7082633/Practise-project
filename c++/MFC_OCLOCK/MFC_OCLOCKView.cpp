// MFC_OCLOCKView.cpp : implementation of the CMFC_OCLOCKView class
//

#include "stdafx.h"
#include "MFC_OCLOCK.h"
#include <math.h>

#include "MFC_OCLOCKDoc.h"
#include "MFC_OCLOCKView.h"
#pragma warning (disable:4244)
#define PI 3.1415926535
BOOL isMenuCom=false;
BOOL isFixTime=false;
SYSTEMTIME tm;
#define RAND() (srand((unsigned int)GetCpuCycle()), rand())
#define dim(x) (sizeof(x) / sizeof(x[0]))

//获得CPU自上电以来的时间周期数
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}
int Color=900;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKView

IMPLEMENT_DYNCREATE(CMFC_OCLOCKView, CView)

BEGIN_MESSAGE_MAP(CMFC_OCLOCKView, CView)
	//{{AFX_MSG_MAP(CMFC_OCLOCKView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKView construction/destruction

CMFC_OCLOCKView::CMFC_OCLOCKView()
{
	// TODO: add construction code here

}

CMFC_OCLOCKView::~CMFC_OCLOCKView()
{
}

BOOL CMFC_OCLOCKView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKView drawing

void CMFC_OCLOCKView::OnDraw(CDC* pDC)
{
	//this->MessageBox("test");
	CMFC_OCLOCKDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CRect rt;
	this->GetClientRect(&rt);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
	memDC.SelectObject(bmp);
	OnDrawMem(&memDC);
	pDC->BitBlt(0,0,rt.Width(),rt.Height(),&memDC,0,0,SRCCOPY);
	memDC.DeleteDC();
	bmp.DeleteObject();
	//////===================================

}

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKView printing

BOOL CMFC_OCLOCKView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_OCLOCKView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_OCLOCKView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKView diagnostics

#ifdef _DEBUG
void CMFC_OCLOCKView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_OCLOCKView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_OCLOCKDoc* CMFC_OCLOCKView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_OCLOCKDoc)));
	return (CMFC_OCLOCKDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKView message handlers

int CMFC_OCLOCKView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	::GetLocalTime(&tm);
	this->SetTimer(110, 1000, NULL);
	//HRGN hRgn = ::CreateEllipticRgn(0, 0,301,301);
	//this->SetWindowRgn(hRgn, TRUE);
	
	return 0;
}

void CMFC_OCLOCKView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd *Parent=this->GetParent();
 	//this->PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	::PostMessage(*Parent,WM_NCLBUTTONDOWN, HTCAPTION, 0);
 	CView::OnLButtonDown(nFlags, point);
}


void CMFC_OCLOCKView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Color=RAND();
	this->InvalidateRect(NULL, TRUE);
	CView::OnRButtonDown(nFlags, point);
}

void CMFC_OCLOCKView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	this->KillTimer(110);
	
}

void CMFC_OCLOCKView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//this->InvalidateRect(NULL, TRUE);
	this->Invalidate();
	CView::OnTimer(nIDEvent);
}

void CMFC_OCLOCKView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == VK_ESCAPE) ::PostQuitMessage(0);
	if (nChar == VK_F1)
	{
		isMenuCom=!isMenuCom;
		this->InvalidateRect(NULL, TRUE);
	}
	if (nChar == VK_F3)
	{
		::GetLocalTime(&tm);
		isFixTime=false;
		this->InvalidateRect(NULL, TRUE);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CMFC_OCLOCKView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
	isFixTime=true;
	if((int)zDelta>0)
	{
		//	::MessageBox(NULL,sz,"NULL",MB_OK);
		if(tm.wSecond==0)
		{
			tm.wSecond=0;
			tm.wMinute-=1;
		}
		else
			tm.wSecond-=1;
	}
	else
	{
		if(tm.wSecond+1>59)
		{
			tm.wSecond=0;
			tm.wMinute+=1;
		}
		else
			tm.wSecond+=1;
	}
	this->InvalidateRect(NULL, TRUE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void CMFC_OCLOCKView::OnDrawMem(CDC *pDC)
{
	char szNow[] = "23:59:59";
	RECT rt;
	RECT rt2;
	this->GetClientRect(&rt);
	if(!isFixTime)
		::GetLocalTime(&tm);
	float fSecond = tm.wSecond;
	float fMinute = tm.wMinute + fSecond / 60.0f;
	float fHour = tm.wHour % 12+ fMinute / 60.0f;
	sprintf(szNow, "%02d:%02d:%02d", tm.wHour, tm.wMinute, tm.wSecond);
	//HRGN hRgn = ::CreateEllipticRgn(0, 0,300,300);
	CBrush Cbrush;
	Cbrush.CreateSolidBrush(Color);

	pDC->SetBkColor(Color);
	int x = rt.right / 2;
	int y = rt.bottom / 2;
	int r = min(x, y);
	r = r;
	pDC->Ellipse(x-r, y-r, x+r, y+r);

	CRgn hRgn;
	hRgn.CreateEllipticRgn(x-r, y-r,x+r,y+r);
	pDC->FillRgn(&hRgn,&Cbrush);
	int i,count=12;
	for (i = 0; i < 60; i = i + 5)   //时刻表!!!
	{
		POINT pt0, pt1;
		pt0.x = x + r * sin( PI/30 * i) * 0.92f;
		pt0.y = y - r * cos( PI/30 * i) * 0.92f;
		pt1.x = x + r * sin( PI/30 * i) * 1.00f;
		pt1.y = y - r * cos( PI/30 * i) * 1.00f;

//		pDC->MoveTo(pt0);
//		pDC->LineTo(pt1);

		MoveToEx(pDC->operator HDC(),pt0.x,pt0.y,(LPPOINT)NULL);
		LineTo(pDC->operator HDC(),pt1.x,pt1.y);

		char sz[5]={0};
		if(count>12) count=1;
		sprintf(sz,"%d",count++);
		rt2.left=x + r * sin( PI/30 * i) * 0.8f;
		rt2.top=y - r * cos( PI/30 * i) * 0.8f;
		rt2.right=x + r * sin( PI/30 * i) * 0.9f;
		rt2.bottom=y - r * cos( PI/30 * i) * 0.9f;
		//::TextOut(hdc,pt0.x,pt0.y,sz,strlen(sz));
		pDC->DrawText(sz, strlen(sz), &rt2, DT_NOCLIP | DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	}
	for (i = 0; i < 60; i++)   //秒刻表!!!
	{
		POINT pt0, pt1;
		pt0.x = x + r * sin( PI/30 * i) * 0.96f;
		pt0.y = y - r * cos( PI/30 * i) * 0.96f;
		pt1.x = x + r * sin( PI/30 * i) * 1.00f;
		pt1.y = y - r * cos( PI/30 * i) * 1.00f;
		pDC->MoveTo(pt0);
		pDC->LineTo(pt1);
	}
	POINT pt,pt3;										//画秒针
	pt.x = x + r * sin( PI/30 * tm.wSecond) * 0.9f;
	pt.y = y - r * cos( PI/30 * tm.wSecond) * 0.9f;
	pt3.x=x;
	pt3.y=y;
	pDC->MoveTo(pt3);
	pDC->LineTo(pt);
	
	
	pt.x = x + r * sin( PI/30 * fMinute) * 0.85f; //画分针
	pt.y = y - r * cos( PI/30 * fMinute) * 0.85f;
	pt3.x=x;
	pt3.y=y;
	pDC->MoveTo(pt3);
	pDC->LineTo(pt);
	
	CPen pen;
	//pen.CreatePen(PS_SOLID,4,0x0);
	//pen.CreatePen(PS_SOLID,4,0x0);
	LOGBRUSH logBrush;
	logBrush.lbStyle = BS_SOLID;
	logBrush.lbColor = RGB(255,0,0);
	//pen.CreatePen(PS_SOLID, 4,&logBrush);
	pen.CreatePen(PS_SOLID, 4,0xff0000);

	
	CPen *OldPen=pDC->SelectObject(&pen);
	pt.x = x + r * sin( PI/6 * (fHour)) * 0.7f; //画时针
	pt.y = y - r * cos( PI/6 * (fHour)) * 0.7f;
	pt3.x=x;
	pt3.y=y;
	pDC->MoveTo(pt3);
	pDC->LineTo(pt);
	pDC->SelectObject(OldPen);
	//::SelectObject(pDC,OldPen);
	pen.DeleteObject();
	//::DeleteObject(pen);
	//::DeleteObject(OldPen);
	OldPen->DeleteObject();
	
	rt2.left=x-60;
	rt2.top=y;
	rt2.right=x+60;
	rt2.bottom=y+60;
	//this->DrawText(szNow, strlen(szNow), &rt2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDC->DrawText(szNow,&rt2,DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	rt2.left=x-60;
	rt2.top=y-80;
	rt2.right=x+60;
	rt2.bottom=y;
	if(!isMenuCom)
		pDC->DrawText("F1呼出帮助\nLB改背景色\nF3校准时间",strlen("F1呼出帮助\nLB改背景色\nF3校准时间"),&rt2,DT_CENTER);
}

BOOL CMFC_OCLOCKView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}
