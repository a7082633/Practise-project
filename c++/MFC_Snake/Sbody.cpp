// Sbody.cpp: implementation of the CSbody class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC_Snake.h"
#include "Sbody.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define RAND() (srand((unsigned int)GetCpuCycle()), rand())
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}

CSbody::CSbody()
{
	FoodPos.x=6000;
	FoodPos.y=6000;
	isEat=false;
	SNode t(1,1,2);
	Snake.push_back(t);
	t.No=0;
	t.Nx=1;
	t.Ny=1;
	Snake.push_back(t);
}

CSbody::~CSbody()
{

}

void CSbody::DrawBody(CDC*& pDC)
{
	list<SNode>::iterator it=Snake.begin();
	for(;it!=Snake.end();it++)
	{
		if((*it).No==1)
		{
			CRect rt;
			rt.left=10+((*it).Ny-1)*NODESIZE;
			rt.top=10+((*it).Nx-1)*NODESIZE;
			rt.right=10+(*it).Ny*NODESIZE;
			rt.bottom=10+((*it).Nx)*NODESIZE;
			CBrush bru(0xffff);
			CBrush *Oldbru=pDC->SelectObject(&bru);
			pDC->FillRect(&rt,&bru);
			pDC->Rectangle(&rt);
			bru.DeleteObject();
		}
		else
		{
			CRect rt;
			rt.left=10+((*it).Ny-1)*NODESIZE;
			rt.top=10+((*it).Nx-1)*NODESIZE;
			rt.right=10+(*it).Ny*NODESIZE;
			rt.bottom=10+((*it).Nx)*NODESIZE;
			CBrush bru(RGB(0,0,0));
			pDC->FillRect(&rt,&bru);
			pDC->Rectangle(&rt);
			bru.DeleteObject();

			bru.CreateSolidBrush(RGB(255,0,0));
			CRgn rg;
			rg.CreateEllipticRgn(rt.left+2,rt.top+2,rt.right-2,rt.bottom-2);
			pDC->FillRgn(&rg,&bru);
			bru.DeleteObject();
		}
	}
}


void CSbody::Move(int d)
{
	list<SNode>::iterator it;
	SNode ht;
	Snake.front().No=0;
	ht=Snake.front();
	Snake.back().No=1;
	switch(d)
	{
	case 1:
		Snake.back().Nx=--ht.Nx;
		Snake.back().Ny=ht.Ny;
		break;
	case 2:
		Snake.back().Nx=++ht.Nx;
		Snake.back().Ny=ht.Ny;
		break;
	case 3:
		Snake.back().Nx=ht.Nx;
		Snake.back().Ny=--ht.Ny;
		break;
	case 4:
		Snake.back().Nx=ht.Nx;
		Snake.back().Ny=++ht.Ny;
		break;
	default:
		return;
		break;
	}
	it=Snake.begin();
	Snake.insert(it,Snake.back());
	it=Snake.end();
	Snake.erase(--it);
}

void CSbody::CreateFood(CDC*& pDC)
{
	CBrush bru(0xffff);
	CRgn crgn;
	if(!isEat)
	{
		int x,y;
		list<SNode>::iterator it;
		bool flag=false;
		while(!flag)
		{
			x=RAND()%21;
			y=RAND()%11;
			if(0==x||0==y)
				continue;
			it=Snake.begin();
			for(;it!=Snake.end();it++)
			{
				if((*it).Nx==x&&(*it).Ny==y)
				{
					break;
				}
			}
			if(it==Snake.end())
				flag=true;
		}
		FoodPos.x=x;
		FoodPos.y=y;
		CRect rt;
		rt.left=10+(FoodPos.y-1)*NODESIZE;
		rt.top=10+(FoodPos.x-1)*NODESIZE;
		rt.right=10+FoodPos.y*NODESIZE;
		rt.bottom=10+FoodPos.x*NODESIZE;
		pDC->Ellipse(&rt);
		crgn.CreateEllipticRgn(rt.left+1,rt.top+1,rt.right,rt.bottom);
		pDC->FillRgn(&crgn,&bru);
		isEat=true;
	}else
	{
		CRect rt;
		rt.left=10+(FoodPos.y-1)*NODESIZE;
		rt.top=10+(FoodPos.x-1)*NODESIZE;
		rt.right=10+FoodPos.y*NODESIZE;
		rt.bottom=10+FoodPos.x*NODESIZE;
		pDC->Ellipse(&rt);
		crgn.CreateEllipticRgn(rt.left+1,rt.top+1,rt.right,rt.bottom);
		pDC->FillRgn(&crgn,&bru);
	}
}

BOOL CSbody::isFood(int d)
{
	switch(d)
	{
	case 1:
		if(Snake.front().Nx-1==FoodPos.x&&Snake.front().Ny==FoodPos.y)
		{
			//::MessageBox(NULL,"TEST","",MB_OK);
			Snake.front().No=0;
			SNode t(1,Snake.front().Nx-1,Snake.front().Ny);
			Snake.push_front(t);
			isEat=!isEat;
			return true;
		}
		return false;
	case 2:
		if(Snake.front().Nx+1==FoodPos.x&&Snake.front().Ny==FoodPos.y)
		{
			Snake.front().No=0;
			SNode t(1,Snake.front().Nx+1,Snake.front().Ny);
			Snake.push_front(t);
			isEat=!isEat;
			return true;
		}
		return false;
	case 3:
		if(Snake.front().Nx==FoodPos.x&&Snake.front().Ny-1==FoodPos.y)
		{
			Snake.front().No=0;
			SNode t(1,Snake.front().Nx,Snake.front().Ny-1);
			Snake.push_front(t);
			isEat=!isEat;
			return true;
		}
		return false;
	case 4:
		if(Snake.front().Nx==FoodPos.x&&Snake.front().Ny+1==FoodPos.y)
		{
			Snake.front().No=0;
			SNode t(1,Snake.front().Nx,Snake.front().Ny+1);
			Snake.push_front(t);
			isEat=!isEat;
			return true;
		}
		return false;
	default:
		return false;
	}
}

void CSbody::ReStart(int &d)
{
	FoodPos.x=6000;
	FoodPos.y=6000;
	isEat=false;
	Snake.clear();
	SNode t(1,1,2);
	Snake.push_back(t);
	t.No=0;
	t.Nx=1;
	t.Ny=1;
	Snake.push_back(t);
	d=4;
}

BOOL CSbody::IsHitBody(int &d)
{
	list<SNode>::iterator it=Snake.begin();
	it++;
	switch(d)
	{
	case 1:
		for(;it!=Snake.end();it++)
		{
			if(Snake.front().Nx-1==(*it).Nx-1&&Snake.front().Ny==(*it).Ny)
				return true;
		}
		return false;
	case 2:
		for(;it!=Snake.end();it++)
		{
			if(Snake.front().Nx+1==(*it).Nx+1&&Snake.front().Ny==(*it).Ny)
				return true;
		}
		return false;
	case 3:
		for(;it!=Snake.end();it++)
		{
			if(Snake.front().Nx==(*it).Nx&&Snake.front().Ny-1==(*it).Ny-1)
				return true;
		}
		return false;
	case 4:
		for(;it!=Snake.end();it++)
		{
			if(Snake.front().Nx==(*it).Nx&&Snake.front().Ny+1==(*it).Ny+1)
				return true;
		}
		return false;
	default:
		return false;
	}
}
