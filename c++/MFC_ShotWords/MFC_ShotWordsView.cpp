// MFC_ShotWordsView.cpp : implementation of the CMFC_ShotWordsView class
//

#include "stdafx.h"
#include "MFC_ShotWords.h"

#include "MFC_ShotWordsDoc.h"
#include "MFC_ShotWordsView.h"
#include "Words.h"
#include "MainFrm.h"
CWords word;
int flag=15;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsView

IMPLEMENT_DYNCREATE(CMFC_ShotWordsView, CView)

BEGIN_MESSAGE_MAP(CMFC_ShotWordsView, CView)
	//{{AFX_MSG_MAP(CMFC_ShotWordsView)
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsView construction/destruction

CMFC_ShotWordsView::CMFC_ShotWordsView()
{
	// TODO: add construction code here

}

CMFC_ShotWordsView::~CMFC_ShotWordsView()
{
}

BOOL CMFC_ShotWordsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsView drawing

void CMFC_ShotWordsView::OnDraw(CDC* pDC)
{
	CMFC_ShotWordsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap bmp;
	CRect rt;
	this->GetClientRect(&rt);
	bmp.CreateCompatibleBitmap(pDC,rt.Width(),rt.Height());
	memDC.SelectObject(&bmp);
	memDC.FillSolidRect(0,0,rt.Width(),rt.Height(),RGB(2,0,254));
	OnDrawMem(&memDC);
	pDC->BitBlt(0,0,rt.Width(),rt.Height(),&memDC,0,0,SRCCOPY);
	////////////////////

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsView printing

BOOL CMFC_ShotWordsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_ShotWordsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_ShotWordsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsView diagnostics

#ifdef _DEBUG
void CMFC_ShotWordsView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_ShotWordsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_ShotWordsDoc* CMFC_ShotWordsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_ShotWordsDoc)));
	return (CMFC_ShotWordsDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsView message handlers

void CMFC_ShotWordsView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd *p=this->GetParent();
	//::PostMessage(p->m_hWnd,WM_MOUSEMOVE,0,0);
	CView::OnMouseMove(nFlags, point);
}

int CMFC_ShotWordsView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	this->SetTimer(110,15,NULL);
	return 0;
}

void CMFC_ShotWordsView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rt;
	this->GetClientRect(&rt);
	if(flag>=60)
	{
		word.CreateNewWord(rt.Width(),rt.Height());
		flag=0;
	}
	flag++;
	CMainFrame *p=(CMainFrame *)this->GetParent();
	CString s;
	s.Format("µÃ·Ö£º%d",word.score);
	p->m_wndStatusBar.SetPaneText(1,s);
	this->Invalidate();
	word.Move();
	CView::OnTimer(nIDEvent);
}

void CMFC_ShotWordsView::OnDrawMem(CDC *pDC)
{
	vector<Word>::iterator it=word.m_Words.begin();

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	memDC.SelectObject(bmp);
	pDC->SetTextColor(RGB(255,0,0));
	for(;it!=word.m_Words.end();it++)
	{
		pDC->BitBlt(it->x-25,it->y-10,it->x+60,it->y+47,&memDC,0,0,SRCCOPY);
		CString s;
		s.Format("%c",it->w);
		pDC->TextOut(it->x,it->y,s);

		CRect rt;
		this->GetClientRect(&rt);
		//pDC->DrawText(s,rt,DT_CENTER|DT_VCENTER);
		int c=word.m_Words.size();
	}
//	pDC->SelectObject(pOld);
//	pen.DeleteObject();
}

void CMFC_ShotWordsView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	word.ShotWord(nChar);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CMFC_ShotWordsView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}

void CMFC_ShotWordsView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}
