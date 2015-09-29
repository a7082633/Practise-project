// Shape.cpp: implementation of the CShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC_MiniCad.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CShape,CObject,2)
CShape::CShape(CPoint m_PtrBegin,CPoint m_PtrEnd,UINT m_Type,int m_PenW,COLORREF m_color)
{
	this->m_color=m_color;
	this->m_PenW=m_PenW;
	this->m_PtrBegin=m_PtrBegin;
	this->m_PtrEnd=m_PtrEnd;
	this->m_Type=m_Type;
}

CShape::~CShape()
{

}

void CShape::Draw(CDC *pDC)
{
	//CBrush brush;
	//brush.CreateStockObject(NULL_BRUSH);
	//pDC->SelectObject(brush);
	CPen pen(PS_SOLID,m_PenW,m_color);
	pDC->SelectObject(pen);
	int i=m_PenW;
	switch(m_Type)
	{
	case 1:
		pDC->MoveTo(m_PtrBegin);
		pDC->LineTo(m_PtrEnd);
		break;
	case 2:
		pDC->Rectangle(m_PtrBegin.x,m_PtrBegin.y,m_PtrEnd.x,m_PtrEnd.y);
		break;
	case 3:
		pDC->Ellipse(m_PtrBegin.x,m_PtrBegin.y,m_PtrEnd.x,m_PtrEnd.y);
		break;
	}
}

void CShape::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
	{
		ar<<this->m_PtrBegin<<this->m_PtrEnd<<this->m_Type<<this->m_PenW<<this->m_color;
	}
	else
	{
		ar>>this->m_PtrBegin>>this->m_PtrEnd>>this->m_Type>>this->m_PenW>>this->m_color;
	}
}
