// Words.h: interface for the CWords class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORDS_H__E3E1462A_46B0_43B5_9556_084C9DEFE878__INCLUDED_)
#define AFX_WORDS_H__E3E1462A_46B0_43B5_9556_084C9DEFE878__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<vector>
using namespace std;
struct Word
{
	char w;
	int x;
	int y;
	Word(char ww=0,int xx=0,int yy=0):w(ww),x(xx),y(yy)
	{
	}
};
class CWords  
{
public:
	vector<Word> m_Words;
public:
	int score;
	void Move();
	void ShotWord(char c);
	void CreateNewWord(int,int);
	CWords();
	virtual ~CWords();

};

#endif // !defined(AFX_WORDS_H__E3E1462A_46B0_43B5_9556_084C9DEFE878__INCLUDED_)
