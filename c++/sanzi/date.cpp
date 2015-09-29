////求任意2个日期之间相差的天数. Kou Conghua. 2011.11.01
//#include <stdio.h>
//#define LEAPYEAR(iYear) (iYear % 100 == 0) ? (iYear % 400 == 0) : (iYear % 4 == 0)
//
////判断给定年是否闰年
//bool IsLeapYear(int iYear)
//{
//	if (iYear % 100 == 0)
//		return ((iYear % 400 == 0));
//	else
//		return ((iYear % 4 == 0));
//}
//
////判断给定日期是否合法
//bool IsValidDate(int iYear, int iMonth, int iDay)
//{
//	if (iYear < 0 || iYear > 9999) return false;
//	switch (iMonth)
//	{
//	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//		return (iDay >= 1 && iDay <= 31);
//		break;
//	case 4: case 6: case 9: case 11:
//		return (iDay >= 1 && iDay <= 30);
//		break;
//	case 2:
//		return (iDay >= 1 && iDay <= (IsLeapYear(iYear) ? 29 : 
//
//28));
//		break;
//	default:
//		return false;
//	}
//}
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
//		iDays += (IsLeapYear(i) ? 366 : 365);
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
//			iDays -= (IsLeapYear(iYear1) ? 29 : 28);
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
//			iDays += (IsLeapYear(iYear2) ? 29 : 28);
//			break;
//		}
//	}
//	//加上iYear2年iMonth2月前iDay2的天数
//	iDays += (iDay2 - 1);
//	
//	return iDays;
//}
//
//void main2()
//{
//	int iYear1 = 1999, iMonth1 = 12, iDay1 = 31;
//	int iYear2 = 2001, iMonth2 = 1, iDay2 = 1;
//
//	printf("计算两个日期之间相差的天数.\r\n\r\n");
////
////	printf("请输入第一个日期(yyyy-mm-dd): ");
////	scanf("%d-%d-%d", &iYear1, &iMonth1, &iDay1);
////
////	fflush(stdin);
////
////	printf("请输入第二个日期(yyyy-mm-dd): ");
////	scanf("%d-%d-%d", &iYear2, &iMonth2, &iDay2);
//
//	if (!IsValidDate(iYear1, iMonth1, iDay1))
//	{
//		printf("%.4d-%.2d-%.2d不是合法的日期\r\n", iYear1, iMonth1, iDay1);
//		return;
//	}
//
//	if (!IsValidDate(iYear2, iMonth2, iDay2))
//	{
//		printf("%.4d-%.2d-%.2d不是合法的日期\r\n", iYear2, iMonth2, iDay2);
//		return;
//	}
//
//	int iDays = GetDays(iYear1, iMonth1, iDay1, iYear2, iMonth2, iDay2);
//	printf("%.4d-%.2d-%.2d与%.4d-%.2d-%.2d相差%d天\r\n", iYear1, iMonth1, iDay1, iYear2, iMonth2, iDay2, iDays);
//}
//
