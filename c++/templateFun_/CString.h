#include <iostream.h>
#include <string.h>
//using namespace std;
class CString
{
	friend CString operator+(const CString &s1,const CString &s2);
	friend ostream& operator<<(ostream &os,const CString &ss);
	char *str;
public:
	int GetLength();
	CString(char *sz="");
	CString(const CString& ss);
	~CString();
	CString& operator=(const CString& ss);
	bool operator>(const CString& s) const;
	char& operator[](const int n);
	operator char*();
	int Compare(CString &ss);
	bool operator>=(const CString& s) const;
	bool operator<=(const CString& s) const;
};