#include "CStack.h"
#define dim(a) (sizeof(a)/sizeof(a[0]))
CStack::CStack()
{
	for(int i=0;i<dim(m_iData);i++)
		m_iData[i]=0;
	m_top=0;
}
void CStack::push(int a)
{
	if(IsFull()) return;
	m_iData[m_top]=a;
	m_top++;
}
bool CStack::IsFull()
{
	if(m_top==9) return true;
	return false;
}
void CStack::pop()
{
	if(IsEmpty()) return;
	m_iData[--m_top]=0;
}
bool CStack::IsEmpty()
{
	if(m_top==0) return true;
	return false;
}
int CStack::top()
{
	if(IsEmpty()) return -1;
	return m_iData[m_top-1];
}