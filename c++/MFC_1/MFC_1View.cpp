// MFC_1View.cpp : implementation of the CMFC_1View class
//

#include "stdafx.h"
#include "MFC_1.h"

#include "MFC_1Doc.h"
#include "MFC_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_1View

IMPLEMENT_DYNCREATE(CMFC_1View, CView)

BEGIN_MESSAGE_MAP(CMFC_1View, CView)
	//{{AFX_MSG_MAP(CMFC_1View)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_1View construction/destruction

CMFC_1View::CMFC_1View()
{
	// TODO: add construction code here

}

CMFC_1View::~CMFC_1View()
{
	
}

BOOL CMFC_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs9

	
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_1View drawing

void CMFC_1View::OnDraw(CDC* pDC)
{
	CMFC_1Doc* pDoc = GetDocument();
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	char sz[20];
	sprintf(sz,"%.2d:%.2d:%.2d",tm.wHour,tm.wMinute,tm.wSecond);
	CRect rt;
	this->GetClientRect(&rt);
	pDC->DrawText(sz,&rt,DT_SINGLELINE | DT_CENTER | DT_VCENTER);


	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_1View printing

BOOL CMFC_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_1View diagnostics

#ifdef _DEBUG
void CMFC_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_1Doc* CMFC_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_1Doc)));
	return (CMFC_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFC_1View message handlers

void CMFC_1View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rt;
	this->GetClientRect(&rt);
	//this->InvalidateRect(&rt);
	this->RedrawWindow();
	CView::OnTimer(nIDEvent);
}

//DEL void CMFC_1View::OnPaint() 
//DEL {
//DEL 	CPaintDC dc(this); // device context for painting
//DEL 	SYSTEMTIME tm;
//DEL 	GetLocalTime(&tm);
//DEL 	char sz[20];
//DEL 	sprintf(sz,"%.2d:%.2d:%.2d",tm.wHour,tm.wMinute,tm.wSecond);
//DEL 	RECT rt;
//DEL 	this->GetClientRect(&rt);
//DEL 	dc.DrawText(sz,strlen(sz),&rt,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//DEL }

int CMFC_1View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	this->SetTimer(110,1000,NULL);
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CMFC_1View::OnDestroy() 
{
	CView::OnDestroy();
	this->KillTimer(110);
	// TODO: Add your message handler code here
	
}
