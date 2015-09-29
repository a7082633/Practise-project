// Sbody.h: interface for the CSbody class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SBODY_H__39323AAD_0A6B_4209_A1A3_CD8592716063__INCLUDED_)
#define AFX_SBODY_H__39323AAD_0A6B_4209_A1A3_CD8592716063__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
using namespace std;



struct SNode
{
	int No;
	int Nx;
	int Ny;
	SNode(int no=0,int x=0,int y=0):No(no),Nx(x),Ny(y){}
};
class CSbody  
{
	bool isEat;
	CPoint FoodPos;
public:
	BOOL IsHitBody(int &d);
	void ReStart(int &d);
	BOOL isFood(int d);
	void CreateFood(CDC*& pDC);
	void Move(int d);
	void DrawBody(CDC*& pDC);
	CSbody();
	virtual ~CSbody();
	list<SNode> Snake;
};

#endif // !defined(AFX_SBODY_H__39323AAD_0A6B_4209_A1A3_CD8592716063__INCLUDED_)
