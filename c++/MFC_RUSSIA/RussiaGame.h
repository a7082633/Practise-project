// RussiaGame.h: interface for the CRussiaGame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUSSIAGAME_H__78339D70_1B7E_4B3B_8265_709FBDAD3027__INCLUDED_)
#define AFX_RUSSIAGAME_H__78339D70_1B7E_4B3B_8265_709FBDAD3027__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Shape.h"
#define COL 10  //ÁÐ
#define ROW 16	//ÐÐ
#define PX 30	//ÐÐ
class CRussiaGame  
{
public:
	int m_Data[ROW][COL];
public:
	void ReStartGame(CShape &shape);
	BOOL IsGameOver();
	int Score;
	void CheckLine(CShape &shape);
	BOOL IsShapeLeft(CShape &shape);
	BOOL IsShapeRight(CShape &shape);
	BOOL IsWallLeft(CShape &shape);
	BOOL IsWallRight(CShape &shape);
	void PutDataIn(CShape &shape);
	BOOL isLandOrShape(CShape &shape);
	void ClearOldShape();
	CRussiaGame();
	virtual ~CRussiaGame();

};

#endif // !defined(AFX_RUSSIAGAME_H__78339D70_1B7E_4B3B_8265_709FBDAD3027__INCLUDED_)
