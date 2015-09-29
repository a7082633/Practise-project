// Shape.cpp: implementation of the CShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC_RUSSIA.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define RAND() (srand((unsigned int)GetCpuCycle()), rand())
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CShape::CShape()
{
	m_ShapeId=-1;
	m_Shape=-1;
	point.x=0;
	point.y=4;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			m_nData[i][j]=0;
		}
}

CShape::~CShape()
{

}
CShape::operator=( const CShape &shape )
{
	Initial();
	m_ShapeId=shape.m_ShapeId;
	m_Shape=shape.m_Shape;
	point.x=shape.point.x;
	point.y=shape.point.y;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			m_nData[i][j]=shape.m_nData[i][j];
		}
}
void CShape::Initial()
{
	m_ShapeId=-1;
	m_Shape=-1;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			m_nData[i][j]=0;
		}
}

void CShape::NewShape()
{
	Initial();
	bool flag=true;
	while(flag)
	{
		m_Shape		= RAND() % 7;
		m_ShapeId	= RAND() % 4;
		switch(m_Shape)
		{
			case 0:
				if(m_ShapeId==0)
				{
					m_nData[0][0]=2;
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					flag=!flag;
				}
				else if(m_ShapeId==1)
				{
					m_nData[0][1]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[2][0]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
			case 1:
				if(m_ShapeId==0)
				{
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					m_nData[1][3]=2;
					flag=!flag;
				}
				else if(m_ShapeId==1)
				{
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[2][1]=2;
					m_nData[3][1]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
			case 2:
				if(m_ShapeId==0)
				{
					m_nData[0][1]=2;
					m_nData[0][2]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					flag=!flag;
				}
				else if(m_ShapeId==1)
				{
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					m_nData[2][2]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
			case 3:
				if(m_ShapeId==0)
				{
					m_nData[0][0]=2;
					m_nData[0][1]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
			case 4:
				if(m_ShapeId==0)
				{
					m_nData[0][1]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					flag=!flag;
				}
				else if(m_ShapeId==1)
				{
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					m_nData[2][1]=2;
					flag=!flag;
				}
				else if(m_ShapeId==2)
				{
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					m_nData[2][1]=2;
					flag=!flag;
				}
				else if(m_ShapeId==3)
				{
					m_nData[0][1]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[2][1]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
			case 5:
				if(m_ShapeId==0)
				{
					m_nData[0][0]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					flag=!flag;
				}
				else if(m_ShapeId==1)
				{
					m_nData[0][1]=2;
					m_nData[0][2]=2;
					m_nData[1][1]=2;
					m_nData[2][1]=2;
					flag=!flag;
				}
				else if(m_ShapeId==2)
				{
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					m_nData[2][2]=2;
					flag=!flag;
				}
				else if(m_ShapeId==3)
				{
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[2][0]=2;
					m_nData[2][1]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
			case 6:
				if(m_ShapeId==0)
				{
					m_nData[0][2]=2;
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					flag=!flag;
				}
				else if(m_ShapeId==1)
				{
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[2][1]=2;
					m_nData[2][2]=2;
					flag=!flag;
				}
				else if(m_ShapeId==2)
				{
					m_nData[1][0]=2;
					m_nData[1][1]=2;
					m_nData[1][2]=2;
					m_nData[2][0]=2;
					flag=!flag;
				}
				else if(m_ShapeId==3)
				{
					m_nData[0][0]=2;
					m_nData[0][1]=2;
					m_nData[1][1]=2;
					m_nData[2][1]=2;
					flag=!flag;
				}
				else
					flag=true;
				break;
		}
	}
}


void CShape::RotateShape(int data[16][10])
{
	int Shape=m_Shape;
	int ShapeId=m_ShapeId;
	CPoint tpoint=point;
	int buff[4][4]={0};
	memcpy(buff,m_nData,sizeof(m_nData));
	memset(m_nData,0,sizeof(m_nData));
	switch(m_Shape)
	{
	case 0:
		if(m_ShapeId+1>1)
		{
			m_ShapeId=0;
			GetShape(m_Shape,m_ShapeId);
		}
		else
		{
			GetShape(m_Shape,++m_ShapeId);
		}
		if(IsValidRotate(data))
		{
			memcpy(m_nData,buff,sizeof(m_nData));
			m_ShapeId=ShapeId;
		}
		break;
	case 1:
		if(m_ShapeId+1>1)
		{
			m_ShapeId=0;
			GetShape(m_Shape,m_ShapeId);
		}
		else
		{
			GetShape(m_Shape,++m_ShapeId);
		}
		if(IsValidRotate(data))
		{
			memcpy(m_nData,buff,sizeof(m_nData));
			m_ShapeId=ShapeId;
		}
		break;
	case 2:
		if(m_ShapeId+1>1)
		{
			m_ShapeId=0;
			GetShape(m_Shape,m_ShapeId);
		}
		else
		{
			GetShape(m_Shape,++m_ShapeId);
		}
		if(IsValidRotate(data))
		{
			memcpy(m_nData,buff,sizeof(m_nData));
			m_ShapeId=ShapeId;
		}
		break;
	case 3:
		GetShape(m_Shape,m_ShapeId);
		memcpy(m_nData,buff,sizeof(m_nData));
		break;
	case 4:
		if(m_ShapeId+1>3)
		{
			m_ShapeId=0;
			GetShape(m_Shape,m_ShapeId);
		}
		else
		{
			GetShape(m_Shape,++m_ShapeId);
		}
		if(IsValidRotate(data))
		{
			memcpy(m_nData,buff,sizeof(m_nData));
			m_ShapeId=ShapeId;
		}
		break;
	case 5:
		if(m_ShapeId+1>3)
		{
			m_ShapeId=0;
			GetShape(m_Shape,m_ShapeId);
		}
		else
		{
			GetShape(m_Shape,++m_ShapeId);
		}
		if(IsValidRotate(data))
		{
			memcpy(m_nData,buff,sizeof(m_nData));
			m_ShapeId=ShapeId;
		}
		break;
	case 6:
		if(m_ShapeId+1>3)
		{
			m_ShapeId=0;
			GetShape(m_Shape,m_ShapeId);
		}
		else
		{
			GetShape(m_Shape,++m_ShapeId);
		}
		if(IsValidRotate(data))
		{
			memcpy(m_nData,buff,sizeof(m_nData));
			m_ShapeId=ShapeId;
		}
		break;
	}
	return;
	//else memcpy(m_nData,buff,sizeof(m_nData));

}

BOOL CShape::GetShape(int m_Shape, int m_ShapeId)
{
	bool flag=false;
	switch(m_Shape)
	{
	case 0:
		if(m_ShapeId==0)
		{
			m_nData[0][0]=2;
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			flag=!flag;
		}
		else if(m_ShapeId==1)
		{
			m_nData[0][1]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[2][0]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
	case 1:
		if(m_ShapeId==0)
		{
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			m_nData[1][3]=2;
			flag=!flag;
		}
		else if(m_ShapeId==1)
		{
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[2][1]=2;
			m_nData[3][1]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
	case 2:
		if(m_ShapeId==0)
		{
			m_nData[0][1]=2;
			m_nData[0][2]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			flag=!flag;
		}
		else if(m_ShapeId==1)
		{
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			m_nData[2][2]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
	case 3:
		if(m_ShapeId==0)
		{
			m_nData[0][0]=2;
			m_nData[0][1]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
	case 4:
		if(m_ShapeId==0)
		{
			m_nData[0][1]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			flag=!flag;
		}
		else if(m_ShapeId==1)
		{
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			m_nData[2][1]=2;
			flag=!flag;
		}
		else if(m_ShapeId==2)
		{
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			m_nData[2][1]=2;
			flag=!flag;
		}
		else if(m_ShapeId==3)
		{
			m_nData[0][1]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[2][1]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
	case 5:
		if(m_ShapeId==0)
		{
			m_nData[0][0]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			flag=!flag;
		}
		else if(m_ShapeId==1)
		{
			m_nData[0][1]=2;
			m_nData[0][2]=2;
			m_nData[1][1]=2;
			m_nData[2][1]=2;
			flag=!flag;
		}
		else if(m_ShapeId==2)
		{
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			m_nData[2][2]=2;
			flag=!flag;
		}
		else if(m_ShapeId==3)
		{
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[2][0]=2;
			m_nData[2][1]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
	case 6:
		if(m_ShapeId==0)
		{
			m_nData[0][2]=2;
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			flag=!flag;
		}
		else if(m_ShapeId==1)
		{
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[2][1]=2;
			m_nData[2][2]=2;
			flag=!flag;
		}
		else if(m_ShapeId==2)
		{
			m_nData[1][0]=2;
			m_nData[1][1]=2;
			m_nData[1][2]=2;
			m_nData[2][0]=2;
			flag=!flag;
		}
		else if(m_ShapeId==3)
		{
			m_nData[0][0]=2;
			m_nData[0][1]=2;
			m_nData[1][1]=2;
			m_nData[2][1]=2;
			flag=!flag;
		}
		else
			flag=false;
		break;
		}
	return flag;
}

BOOL CShape::IsValidRotate(int data[][10])
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(m_nData[i][j]==2)
			{
				if(data[i+point.x][j+point.y]==1)
					return true;
				if(i+point.x>=16||j+point.y>=10||j+point.y<0)
					return true;
			}
		}
	return false;
}
