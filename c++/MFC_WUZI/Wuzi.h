// Wuzi.h: interface for the CWuzi class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WUZI_H__CBC2B8AC_9B7B_45DB_9E8C_381DE2ECBBCC__INCLUDED_)
#define AFX_WUZI_H__CBC2B8AC_9B7B_45DB_9E8C_381DE2ECBBCC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWuzi  
{
public:
	int Chess[15][15];
	int px;
	int py;
	BOOL BWho;
	BOOL IsDone;
public:
	void ClearChess();
	int Check(int,int);
	CWuzi();
	virtual ~CWuzi();

};

#endif // !defined(AFX_WUZI_H__CBC2B8AC_9B7B_45DB_9E8C_381DE2ECBBCC__INCLUDED_)
