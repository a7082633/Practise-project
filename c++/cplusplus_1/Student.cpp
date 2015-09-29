//#include "Student.h"
//#include <string.h>
//
//CStu::CStu(int no,int age, bool sex,char *name)
//{
//	SName=new char[strlen(name)+1];
//	strcpy(SName,name);
//	iNo=no;
//	iAge=age;
//	BSex=sex;
//}
//
//CStu::CStu(const CStu &s)
//{
//	SName=new char[strlen(s.SName)+1];
//	strcpy(SName,s.SName);
//	iNo=s.iNo;
//	iAge=s.iAge;
//	BSex=s.BSex;
//}
//
//char *CStu::GetName()
//{
//	return SName;
//}
//
//void CStu::GetV()
//{
//	cout<<iNo<<" "<<SName<<" "<<iAge<<" "<<(BSex?"ÄÐ":"Å®")<<endl;
//	//date.show();
//}
//
//CStu::~CStu()
//{
//	if(SName)
//		delete []SName;
//}
//
//void CStu::TFriend(const Date &date)
//{
//	cout<<date.m_iYear<<","<<date.m_iMonth<<","<<date.m_iDay<<endl;
//}
//
//CStu CStu::operator+(const CStu &s1)
//{
//	return CStu(112,iAge+s1.iAge,true);
////	return t;
//}
//CStu CStu::operator-(const CStu &s1)
//{
//	return CStu(113,iAge-s1.iAge,true);
////	return t;
//}
//
//CStu CStu::operator++()
//{
//	return CStu(114,++iAge,true);
////	return t;
//}
//
//CStu CStu::operator--()
//{
//	return CStu(115,--iAge,true);
////	return t;
//}
//CStu CStu::operator++(int x)
//{
//	CStu p=*this;
//	iAge++;
//	return p;
//}
//
//CStu CStu::operator--(int x)
//{
//	CStu p=*this;
//	iAge--;
//	return p;
//}
//
//CStu& CStu::operator=(const CStu &s)
//{
//	if(this!=&s)
//	{
//		iNo=s.iNo;
//		iAge=s.iAge;
//		strcpy(SName,s.SName);
//	}
//	return *this;
//}
