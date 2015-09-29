//#include "CString.h"
//#include <stdlib.h>
//
//CString operator+(const CString &s1,const CString &s2)
//{
//	char *t=new char[strlen(s1.str)+strlen(s2.str)+1];
//	strcpy(t,s1.str);
//	strcat(t,s2.str);
//	return CString(t);
//}
//ostream &operator<<(ostream &os,const CString &ss)
//{
//	os<<ss.str;
//	return os;
//}
//void main()
//{
//	CString str1 = "everyone,";
//	str1[0] = 'E';
//
//	CString str2;
//	str2 = str1;
//	str2 = "C++";
//
//	CString str3 = "Hello!" + str1 + "welcome to " + str2 + " world!";
//	str3[5] = ',';
//	cout << str3 << endl;
//	str3 = "12345";
//
//	if (str3.GetLength() > 0)
//	{
//		CString str4 = str3;
//		cout << atoi(str4) << endl;
//	}
//}