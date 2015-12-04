// MFC_MiniCadView.cpp : implementation of the CMFC_MiniCadView class
//

#include "stdafx.h"
#include "MFC_MiniCad.h"

#include "MFC_MiniCadDoc.h"
#include "MFC_MiniCadView.h"
#include "Shape.h" 
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadView

IMPLEMENT_DYNCREATE(CMFC_MiniCadView, CView)

BEGIN_MESSAGE_MAP(CMFC_MiniCadView, CView)
	//{{AFX_MSG_MAP(CMFC_MiniCadView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_DRAW_NONE, OnDrawNone)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_COMMAND(ID_DRAW_EILL, OnDrawEill)
	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_WM_CONTEXTMENU()
	ON_UPDATE_COMMAND_UI(ID_DRAW_NONE, OnUpdateDrawNone)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, OnUpdateDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_EILL, OnUpdateDrawEill)
	ON_UPDATE_COMMAND_UI(ID_DRAW_COLOR, OnUpdateDrawColor)
	ON_COMMAND(ID_DRAW_COLOR, OnDrawColor)
	ON_WM_CREATE()
	ON_COMMAND(ID_BTN_L1, OnBtnL1)
	ON_COMMAND(ID_BTN_L2, OnBtnL2)
	ON_COMMAND(ID_BTN_L3, OnBtnL3)
	ON_UPDATE_COMMAND_UI(ID_BTN_L1, OnUpdateBtnL1)
	ON_UPDATE_COMMAND_UI(ID_BTN_L2, OnUpdateBtnL2)
	ON_UPDATE_COMMAND_UI(ID_BTN_L3, OnUpdateBtnL3)
	ON_COMMAND(ID_BTN_COLOR, OnBtnColor)
	ON_UPDATE_COMMAND_UI(ID_BTN_COLOR, OnUpdateBtnColor)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadView construction/destruction

CMFC_MiniCadView::CMFC_MiniCadView()
{
	// TODO: add construction code here
	m_nType=0;
	m_penw=1;
	m_color=0;
}

CMFC_MiniCadView::~CMFC_MiniCadView()
{
}

BOOL CMFC_MiniCadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadView drawing

void CMFC_MiniCadView::OnDraw(CDC* pDC)
{
	CMFC_MiniCadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	INT Count=pDoc->m_ObArray.GetSize();
	for(int i=0;i<Count;i++)
	{
		CShape *pNew=(CShape *)pDoc->m_ObArray[i];
		pNew->Draw(pDC);
	}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadView printing

BOOL CMFC_MiniCadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_MiniCadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_MiniCadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniCadView diagnostics

#ifdef _DEBUG
void CMFC_MiniCadView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_MiniCadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_MiniCadDoc* CMFC_MiniCadView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_MiniCadDoc)));
	return (CMFC_MiniCadDoc*)m_pDocument;
}
#endif //_DEBUG


void CMFC_MiniCadView::OnMouseMove(UINT nFlags, CPoint point) 
{
	//CWnd *parent=this->GetParent();

	CMainFrame *p=(CMainFrame *)this->GetParent();
	CString szNow;
	szNow.Format("%d,%d",point.x,point.y);
	p->m_wndStatusBar.SetPaneText(1,szNow);


	if((nFlags & MK_LBUTTON)==FALSE) return;

	CWindowDC dc(this);
	dc.SetROP2(R2_NOTXORPEN);
	CPen pen(PS_SOLID,m_penw,m_color);
	CPen *Oldpen=(CPen *)dc.SelectObject(pen);
	if(m_nType==2)
	{
		dc.Rectangle(m_pBegin.x,m_pBegin.y,point.x,point.y);
		dc.Rectangle(m_pBegin.x,m_pBegin.y,m_pEnd.x,m_pEnd.y);
	}
	else if(m_nType==1)
	{
		dc.MoveTo(m_pBegin);
		dc.LineTo(point);
		dc.MoveTo(m_pBegin);
		dc.LineTo(m_pEnd);
	}
	else if(m_nType==3)
	{
		dc.Ellipse(m_pBegin.x,m_pBegin.y,point.x,point.y);
		dc.Ellipse(m_pBegin.x,m_pBegin.y,m_pEnd.x,m_pEnd.y);
	}
	//dc.SelectObject(Oldpen);
	pen.DeleteObject();
	m_pEnd=point;
	CView::OnMouseMove(nFlags, point);
}


void CMFC_MiniCadView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_pBegin=point;
	m_pEnd=point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_MiniCadView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CMFC_MiniCadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->SetModifiedFlag();
	// TODO: Add your message handler code here and/or call default
	CShape *pNew=new CShape(m_pBegin,m_pEnd,m_nType,m_penw,m_color);
	pDoc->m_ObArray.Add(pNew);
	pNew=(CShape *)pDoc->m_ObArray.GetAt(pDoc->m_ObArray.GetSize()-1);
	int i=pNew->m_PenW;
	pDoc->iNew++;
	CView::OnLButtonUp(nFlags, point);
}

void CMFC_MiniCadView::OnDrawNone() 
{
	// TODO: Add your command handler code here
	m_nType=0;
	
}

void CMFC_MiniCadView::OnDrawLine() 
{
	// TODO: Add your command handler code here
	//this->MessageBox("line");
	m_nType=1;
}

void CMFC_MiniCadView::OnDrawEill() 
{
	// TODO: Add your command handler code here
	m_nType=3;
}

void CMFC_MiniCadView::OnDrawRect() 
{
	// TODO: Add your command handler code here
	m_nType=2;
}

void CMFC_MiniCadView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	this->GetParent()->GetMenu()->GetSubMenu(4)->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this->GetParent());
	//this->GetParent()->GetMenu()->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this->GetParent(),&rt);
	//this->GetParent()->GetMenu()->GetSubMenu(4)->GetSubMenu(3)->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this->GetParent());
}

void CMFC_MiniCadView::OnUpdateDrawNone(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==0);
}

void CMFC_MiniCadView::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==1);
}

void CMFC_MiniCadView::OnUpdateDrawRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==2);
}

void CMFC_MiniCadView::OnUpdateDrawEill(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==3);
}

void CMFC_MiniCadView::OnUpdateDrawColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nType==2);
	//this->MessageBox("test1");
	//this->MessageBox("nul");
}

void CMFC_MiniCadView::OnDrawColor() 
{
	// TODO: Add your command handler code here
	//this->MessageBox("test2");
}

int CMFC_MiniCadView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	//this->GetParent()->GetMenu()->GetSubMenu(4)->RemoveMenu(5,MF_BYPOSITION);
	return 0;
}

void CMFC_MiniCadView::OnBtnL1()
{
	// TODO: Add your command handler code here
	m_penw=1;
}

void CMFC_MiniCadView::OnBtnL2()
{
	// TODO: Add your command handler code here
	m_penw=2;
}

void CMFC_MiniCadView::OnBtnL3()
{
	// TODO: Add your command handler code here
	m_penw=3;
}

void CMFC_MiniCadView::OnUpdateBtnL1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_penw==1);
	
}

void CMFC_MiniCadView::OnUpdateBtnL2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_penw==2);
}

void CMFC_MiniCadView::OnUpdateBtnL3(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_penw==3);
}

void CMFC_MiniCadView::OnBtnColor() 
{
	// TODO: Add your command handler code here
	CMainFrame *p=(CMainFrame *)this->GetParent();
	CColorDialog cd;
	if(IDOK==cd.DoModal())
	{
		m_color=cd.GetColor();
	}
	
}

void CMFC_MiniCadView::OnUpdateBtnColor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_color!=0);
}
