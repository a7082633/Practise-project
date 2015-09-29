////变量定义没有完全按照C语言的语法规则来。
////文件命名为*.cpp后缀的即可, 不要命名成*.c的。
//
////日历C语言版   作者QQ 93506222 于2014.2.17
//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <time.h>
//
////是否闰年
//#define IS_LEAP_YEAR(iYear) (((iYear) % 100 == 0) ? ((iYear) % 400 == 0) : ((iYear) % 4 == 0))
//
//int Calendar(int iYear, int iMonth);
//
//void main()
//{
//	//获取今天的日期
//	struct tm *today;
//	time_t ltime;
//	time(&ltime);
//	today = localtime(&ltime);
//
////	printf("%d-%02d-%02d %02d:%02d:%02d\n星期%d 当年第%d天\n", 
////		today->tm_year + 1900, today->tm_mon + 1, today->tm_mday, 
////		today->tm_hour, today->tm_min, today->tm_sec, today->tm_wday, today->tm_yday);
//
//	int iYear = today->tm_year + 1900;
//	int iMonth = today->tm_mon + 1;
//
//	do {
//		system("cls");
//
//		int ch = Calendar(iYear, iMonth);
//		if (ch == 27) break;
//
//		switch (ch)
//		{
//		case 75:	//<--
//			iYear--;
//			break;
//		case 77:	//-->
//			iYear++;
//			break;
//		case 80:	//下箭头
//			iMonth++;
//			if (iMonth > 12)
//			{
//				iYear++;
//				iMonth = 1;
//			}
//			break;
//		case 72:	//上箭头
//			iMonth--;
//			if (iMonth < 1)
//			{
//				iYear--;
//				iMonth = 12;
//			}
//			break;
//		case 71:	//Home
//			iYear = today->tm_year + 1900;
//			iMonth = today->tm_mon + 1;
//			break;
//		}
//	} while (1);
//}
//
////显示给定年月的日历
////返回值为获取的用户按键, 以确定下一步的操作
//int Calendar(int iYear, int iMonth)
//{
//	int i, j, iDays;
//
//	//初始化数组w的值为1至31
//	int w[31];
//	for (i = 0; i < 31; i++) w[i] = i+1;
//	
//	//获取本月天数于iDays中
//	switch (iMonth)
//	{
//	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//		iDays = 31;
//		break;
//	case 4: case 6: case 9: case 11:
//		iDays = 30;
//		break;
//	case 2:
//		iDays = IS_LEAP_YEAR(iYear) ? 29 : 28;
//		break;
//	}
//	
//	//显示 日历头
//	printf("\n    %d年%d月 日历\n\n", iYear, iMonth);
//	printf(" 日 一 二 三 四 五 六\n");
//	printf("----------------------\n");
//	
//
//	//获取参数指定年月的第一天是周几。保存在firstday.tm_wday中
//	struct tm firstday = {0};
//	firstday.tm_year = iYear - 1900;
//	firstday.tm_mon = iMonth - 1;
//	firstday.tm_mday = 1;
//
//	time_t ltime;
//	ltime = mktime(&firstday);
//
//	firstday = *localtime(&ltime);
//
//	//处理1号前的留空
//	j = firstday.tm_wday;	//周几
//	for (i = 0; i < j; i++)
//	{
//		printf("   ");	//3个空格
//	}
//	
//	//显示日历正文
//	for (i = 0; i < iDays; i++)
//	{
//		printf("%3d", w[i]);
//		if (++j == 7)
//		{
//			printf("\n");//逢七换行
//			j = 0;
//		}
//	}
//	if (j != 0) printf("\n");
//
//
//	//获取今天日期
//	time(&ltime);
//	struct tm today = *localtime(&ltime);
//
//	//显示 日历尾
//	printf("----------------------\n");
//	printf("今天是: %d年%d月%d日\n\n", today.tm_year + 1900, today.tm_mon + 1, today.tm_mday);
//
//	printf("←: 上一年  →: 下一年\n");
//	printf("↑: 上一月  ↓: 下一月\n\n");
//	printf("Home: 今天  Esc: 退出\n");
//
//	//获取用户按键 (不用按回车立即返回)
//	fflush(stdin);
//	clearerr(stdin);
//
//	int c = getch();
//	if (c == 0xe0 || c == 0) c = getch();
//
//	return c;
//}
