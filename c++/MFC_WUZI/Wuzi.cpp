// Wuzi.cpp: implementation of the CWuzi class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC_WUZI.h"
#include "Wuzi.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWuzi::CWuzi()
{
	BOOL BWho=false;
	BOOL IsDone=false;
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			Chess[i][j]=0;
}

CWuzi::~CWuzi()
{

}

int CWuzi::Check(int x, int y)
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

void CWuzi::ClearChess()
{
	for(int i=0;i<15;i++)
		for(int j=0;j<15;j++)
			Chess[i][j]=0;
}
