////��������û����ȫ����C���Ե��﷨��������
////�ļ�����Ϊ*.cpp��׺�ļ���, ��Ҫ������*.c�ġ�
//
////����C���԰�   ����QQ 93506222 ��2014.2.17
//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <time.h>
//
////�Ƿ�����
//#define IS_LEAP_YEAR(iYear) (((iYear) % 100 == 0) ? ((iYear) % 400 == 0) : ((iYear) % 4 == 0))
//
//int Calendar(int iYear, int iMonth);
//
//void main()
//{
//	//��ȡ���������
//	struct tm *today;
//	time_t ltime;
//	time(&ltime);
//	today = localtime(&ltime);
//
////	printf("%d-%02d-%02d %02d:%02d:%02d\n����%d �����%d��\n", 
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
//		case 80:	//�¼�ͷ
//			iMonth++;
//			if (iMonth > 12)
//			{
//				iYear++;
//				iMonth = 1;
//			}
//			break;
//		case 72:	//�ϼ�ͷ
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
////��ʾ�������µ�����
////����ֵΪ��ȡ���û�����, ��ȷ����һ���Ĳ���
//int Calendar(int iYear, int iMonth)
//{
//	int i, j, iDays;
//
//	//��ʼ������w��ֵΪ1��31
//	int w[31];
//	for (i = 0; i < 31; i++) w[i] = i+1;
//	
//	//��ȡ����������iDays��
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
//	//��ʾ ����ͷ
//	printf("\n    %d��%d�� ����\n\n", iYear, iMonth);
//	printf(" �� һ �� �� �� �� ��\n");
//	printf("----------------------\n");
//	
//
//	//��ȡ����ָ�����µĵ�һ�����ܼ���������firstday.tm_wday��
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
//	//����1��ǰ������
//	j = firstday.tm_wday;	//�ܼ�
//	for (i = 0; i < j; i++)
//	{
//		printf("   ");	//3���ո�
//	}
//	
//	//��ʾ��������
//	for (i = 0; i < iDays; i++)
//	{
//		printf("%3d", w[i]);
//		if (++j == 7)
//		{
//			printf("\n");//���߻���
//			j = 0;
//		}
//	}
//	if (j != 0) printf("\n");
//
//
//	//��ȡ��������
//	time(&ltime);
//	struct tm today = *localtime(&ltime);
//
//	//��ʾ ����β
//	printf("----------------------\n");
//	printf("������: %d��%d��%d��\n\n", today.tm_year + 1900, today.tm_mon + 1, today.tm_mday);
//
//	printf("��: ��һ��  ��: ��һ��\n");
//	printf("��: ��һ��  ��: ��һ��\n\n");
//	printf("Home: ����  Esc: �˳�\n");
//
//	//��ȡ�û����� (���ð��س���������)
//	fflush(stdin);
//	clearerr(stdin);
//
//	int c = getch();
//	if (c == 0xe0 || c == 0) c = getch();
//
//	return c;
//}