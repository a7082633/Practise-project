// Shape.h: interface for the CShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHAPE_H__1486E28D_5B33_41B3_81EE_E059BA0F628D__INCLUDED_)
#define AFX_SHAPE_H__1486E28D_5B33_41B3_81EE_E059BA0F628D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CShape  
{
public:
	int m_ShapeId;
	int m_Shape;
	int	m_nData[4][4];
	CPoint point;
public:
	BOOL IsValidRotate(int data[16][10]);
	BOOL GetShape(int shape,int shapeid);
	void RotateShape(int data[16][10]);
	operator=( const CShape &shape );
	void NewShape();
	void Initial();
	CShape();
	virtual ~CShape();
};

#endif // !defined(AFX_SHAPE_H__1486E28D_5B33_41B3_81EE_E059BA0F628D__INCLUDED_)
