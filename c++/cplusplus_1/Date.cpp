//#include <iostream>
//#include "Date.h"
//using namespace std;
//#define Isleap(a) (a%100 == 0)?((a%400 == 0)?(true):(false)):((a%4 == 0)?(true):(false))
//
////获取2个日期之间相差的天数
//int GetDays(int iYear1, int iMonth1, int iDay1, int iYear2, int iMonth2, int iDay2)
//{
//	//1. 确保 日期1 < 日期2
//	unsigned int iDate1 = iYear1 * 10000 + iMonth1 * 100 + iDay1;
//	unsigned int iDate2 = iYear2 * 10000 + iMonth2 * 100 + iDay2;
//	if (iDate1 > iDate2)
//	{
//		iYear1 = iYear1 + iYear2 - (iYear2 = iYear1);
//		iMonth1 = iMonth1 + iMonth2 - (iMonth2 = iMonth1);
//		iDay1 = iDay1 + iDay2 - (iDay2 = iDay1);
//	}
//	
//	//2. 开始计算天数
//	//计算 从 iYear1年1月1日 到 iYear2年1月1日前一天 之间的天数
//	int iDays = 0;
//	for (int i = iYear1; i < iYear2; i++)
//	{
//		iDays += (Isleap(i) ? 366 : 365);
//	}
//	
//	//减去iYear1年前iMonth1月的天数
//	for (i = 1; i < iMonth1; i++)
//	{
//		switch (i)
//		{
//		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//			iDays -= 31;
//			break;
//		case 4: case 6: case 9: case 11:
//			iDays -= 30;
//			break;
//		case 2:
//			iDays -= (Isleap(iYear1) ? 29 : 28);
//			break;
//		}
//	}
//	//减去iYear1年iMonth1月前iDay1的天数
//	iDays -= (iDay1 - 1);
//	
//	//加上iYear2年前iMonth2月的天数
//	for (i = 1; i < iMonth2; i++)
//	{
//		switch (i)
//		{
//		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//			iDays += 31;
//			break;
//		case 4: case 6: case 9: case 11:
//			iDays += 30;
//			break;
//		case 2:
//			iDays += (Isleap(iYear2) ? 29 : 28);
//			break;
//		}
//	}
//	//加上iYear2年iMonth2月前iDay2的天数
//	iDays += (iDay2 - 1);
//	
//	return iDays;
//}
//
//Date::Date(int year,int month,int day):m_iYear(year),m_iMonth(month),m_iDay(day)
//{
//}
//
//void Date::show()
//{
//	cout<<m_iYear<<"."<<m_iMonth<<"."<<m_iDay<<endl;
//}
//
//void Date::AddDay()
//{
//		switch(m_iMonth)
//		{
//		case 1:		case 3:		case 5:		case 7:		case 8:		case 10:		case 12:
//			{
//				(m_iDay+1>31)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				break;
//			}
//		case 4:		case 6:		case 9: 	case 11:
//			{
//				(m_iDay+1>30)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				break;
//			}
//		case 2:
//			{
//				if(Isleap(m_iYear))
//					(m_iDay+1>29)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				else
//					(m_iDay+1>28)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				break;
//			}
//		default:
//			break;
//		}
//}
//
//Date::~Date()
//{
//}
//
//Date &Date::operator=(Date &date)
//{
//	if(this!=&date)
//	{
//		m_iYear=date.m_iYear;
//		m_iMonth=date.m_iMonth;
//		m_iDay=date.m_iDay;
//	}
//	return *this;
//}
//
//Date &Date::operator++()
//{
//		switch(m_iMonth)
//		{
//		case 1:		case 3:		case 5:		case 7:		case 8:		case 10:		case 12:
//			{
//				(m_iDay+1>31)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				break;
//			}
//		case 4:		case 6:		case 9: 	case 11:
//			{
//				(m_iDay+1>30)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				break;
//			}
//		case 2:
//			{
//				if(Isleap(m_iYear))
//					(m_iDay+1>29)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				else
//					(m_iDay+1>28)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//				break;
//			}
//		default:
//			break;
//		}
//		return *this;
//}
//Date &Date::operator++(int)
//{
//	Date t=*this;
//	switch(m_iMonth)
//	{
//	case 1:		case 3:		case 5:		case 7:		case 8:		case 10:		case 12:
//		{
//			(m_iDay+1>31)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//			break;
//		}
//	case 4:		case 6:		case 9: 	case 11:
//		{
//			(m_iDay+1>30)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//			break;
//		}
//	case 2:
//		{
//			if(Isleap(m_iYear))
//				(m_iDay+1>29)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//			else
//				(m_iDay+1>28)?(((m_iMonth+1>12)?(++m_iYear,m_iMonth=1):(++m_iMonth)),m_iDay=1):(++m_iDay);
//			break;
//		}
//	default:
//		break;
//	}
//		return t;
//}
//
//Date &Date::operator--()
//{
//	switch(m_iMonth)
//	{
//	case 1:		case 3:		case 5:		case 7:		case 8:		case 10:		case 12:
//		{
//			(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=31):(--m_iDay);
//			break;
//		}
//	case 4:		case 6:		case 9: 	case 11:
//		{
//			(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=30):(--m_iDay);
//			break;
//		}
//	case 2:
//		{
//			if(Isleap(m_iYear))
//				(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=29):(--m_iDay);
//			else
//				(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=28):(--m_iDay);
//			break;
//		}
//	default:
//		break;
//	}
//	return *this;
//}
//
//Date &Date::operator--(int)
//{
//	Date t=*this;
//	switch(m_iMonth)
//	{
//	case 1:		case 3:		case 5:		case 7:		case 8:		case 10:		case 12:
//		{
//			(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=31):(--m_iDay);
//			break;
//		}
//	case 4:		case 6:		case 9: 	case 11:
//		{
//			(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=30):(--m_iDay);
//			break;
//		}
//	case 2:
//		{
//			if(Isleap(m_iYear))
//				(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=29):(--m_iDay);
//			else
//				(m_iDay-1<1)?(((m_iMonth-1<1)?(--m_iYear,m_iMonth=12):(--m_iMonth)),m_iDay=28):(--m_iDay);
//			break;
//		}
//	default:
//		break;
//	}
//	return t;
//}
//
//void Date::operator+=(const Date &date)
//{
//	m_iYear+=date.m_iYear;
//	m_iMonth+=date.m_iMonth;
//	m_iDay+=date.m_iDay;
//}
//void Date::operator-=(const Date &date)
//{
//	m_iYear+=date.m_iYear;
//	m_iMonth+=date.m_iMonth;
//	m_iDay+=date.m_iDay;
//}
//
//int Date::operator-(const Date &date)
//{
//	return GetDays(m_iYear,m_iMonth,m_iDay,date.m_iYear,date.m_iMonth,date.m_iDay);
//}
//
//Date::operator int()//强转整形
//{
//	return m_iYear;
//}
//Date::operator float()
//{
//	return (float)m_iMonth;
//}
