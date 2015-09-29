// Shape.h: interface for the CShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__FB9AFFDA_9708_4E68_8737_D5CC7564934B__INCLUDED_)
#define AFX_SHAPE_H__FB9AFFDA_9708_4E68_8737_D5CC7564934B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CShape  :public CObject
{

	DECLARE_SERIAL(CShape);
public:
	COLORREF m_color;
	int m_PenW;
	virtual void Serialize(CArchive& ar);
	void Draw(CDC * pDC);
	CPoint m_PtrBegin;
	CPoint m_PtrEnd;
	UINT m_Type;
	CShape(CPoint m_PtrBegin=0,CPoint m_PtrEnd=0,UINT m_Type=0,int m_PenW=0,COLORREF m_color=0);
	virtual ~CShape();

};

#endif // !defined(AFX_SHAPE_H__FB9AFFDA_9708_4E68_8737_D5CC7564934B__INCLUDED_)
