// RussiaGame.cpp: implementation of the CRussiaGame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC_RUSSIA.h"
#include "RussiaGame.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRussiaGame::CRussiaGame()
{
	Score=0;
	for(int i=0;i<COL;i++)
		for(int j=0;j<ROW;j++)
			m_Data[i][j]=0;

}

CRussiaGame::~CRussiaGame()
{

}

void CRussiaGame::ClearOldShape()
{
	int i=0,j=0;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			if(m_Data[i][j]==2)
			{
				m_Data[i][j]=0;
			}
		}
	}
}

BOOL CRussiaGame::isLandOrShape(CShape &shape)
{
	int x,y;
	int i=0,j=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(shape.m_nData[i][j]==2)
			{
				x=i;
				y=j;
			}
	x=x+shape.point.x;
	if(x+1>=ROW)
		return TRUE;
	/////////碰方块///////////
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(shape.m_nData[i][j]==2)
			{
				if(m_Data[i+shape.point.x+1][j+shape.point.y]==1)
					return true;
			}
	return FALSE;
}

void CRussiaGame::PutDataIn(CShape &shape)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(shape.m_nData[i][j]==2)
				m_Data[i+shape.point.x][j+shape.point.y]=1;
		}
}

BOOL CRussiaGame::IsWallLeft(CShape &shape)
{
	int i=0,j=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(shape.m_nData[i][j]==2)
			{
				if(j+shape.point.y-1<0)
					return TRUE;
			}
		}
	return FALSE;
}
BOOL CRussiaGame::IsWallRight(CShape &shape)
{
	int i=0,j=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(shape.m_nData[i][j]==2)
			{
				if(j+shape.point.y+1>=COL)
					return TRUE;
			}
		}
	return FALSE;
}

BOOL CRussiaGame::IsShapeLeft(CShape &shape)
{
	int i=0,j=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(shape.m_nData[i][j]==2)
			{
				if(m_Data[i+shape.point.x][j+shape.point.y-1]==1)
					return true;
			}
	return FALSE;
}

BOOL CRussiaGame::IsShapeRight(CShape &shape)
{
	int i=0,j=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(shape.m_nData[i][j]==2)
			{
				if(m_Data[i+shape.point.x][j+shape.point.y+1]==1)
					return true;
			}
	return FALSE;
}

void CRussiaGame::CheckLine(CShape &shape)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(shape.m_nData[i][j]==2)
			{
				int count=0;
				for(int k=0;k<COL;k++)
				{
					if(this->m_Data[i+shape.point.x][k]!=1)
					{
						break;
					}
					else
						count++;
				}
				if(count>=COL)
				{
					Score+=10;
					for(k=0;k<COL;k++)       //消行
						m_Data[i+shape.point.x][k]=0;
					for(k=i+shape.point.x;k>0;k--)  //下移
					{
						for(int m=0;m<COL;m++)
						{
							m_Data[k][m]=m_Data[k-1][m];
						}
					}
				}
			}
		}
}

BOOL CRussiaGame::IsGameOver()
{
	for(int i=0;i<10;i++)
		if(m_Data[0][i]==1)
			return true;
	return false;
}

void CRussiaGame::ReStartGame(CShape &shape)
{
	shape.point.x=0;
	shape.point.y=4;
	memset(m_Data,0,sizeof(m_Data));
	Score=0;
}
