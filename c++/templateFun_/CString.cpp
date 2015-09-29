#include "CString.h"

CString::CString(char *sz)
{
	str=new char[strlen(sz)+1];
	strcpy(str,sz);
}
CString::CString(const CString& ss)
{
	str=new char[strlen(ss.str)+1];
	strcpy(str,ss.str);
}
CString::~CString()
{
	if(str)
		delete []str;
}
CString& CString::operator=(const CString& ss)
{
	if(this!=&ss)
	{
		delete []str;
		str=new char[strlen(ss.str)+1];
		strcpy(str,ss.str);
	}
	return *this;
}

char& CString::operator[](const int n)
{
	return str[n];
}

int CString::GetLength()
{
	return strlen(str);
}
CString::operator char*()
{
	return str;
}
int CString::Compare(CString &ss)
{
	return strcmp(str,ss.str);
}
bool CString::operator>(const CString& s) const
{
	return (strcmp(this->str, s.str) > 0);
}
bool CString::operator>=(const CString& s) const
{
	return (strcmp(this->str, s.str) >= 0);
}

bool CString::operator<=(const CString& s) const
{
	return (strcmp(this->str, s.str) <= 0);
}