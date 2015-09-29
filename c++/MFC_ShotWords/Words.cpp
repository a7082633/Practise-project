// Words.cpp: implementation of the CWords class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFC_ShotWords.h"
#include "Words.h"

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

CWords::CWords()
{
	score=0;
}

CWords::~CWords()
{

}

void CWords::CreateNewWord(int w,int h)
{
	Word t;
	t.w=RAND()%24+65;
	t.x=RAND()%(w-20);
	t.y=0;
	m_Words.push_back(t);
}

void CWords::ShotWord(char c)
{
	vector<Word>::iterator it=m_Words.begin();
	for(;it!=m_Words.end();it++)
		if((*it).w==c)
		{
			m_Words.erase(it);
			score++;
			return;
		}
}

void CWords::Move()
{
	vector<Word>::iterator it=m_Words.begin();
	for(;it!=m_Words.end();it++)
		it->y+=1;
}
