//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <conio.h>
//
//#define Isleap(a) (a%100 == 0)?((a%400 == 0)?(true):(false)):((a%4 == 0)?(true):(false))
//#define dim(x) sizeof(x)/sizeof(x[0])
//int Get_f_w(int day,int w_day)
//{
//	switch((day-(w_day+1))%7)
//	{
//	case 1:	case -6:
//		{return 6;break;}
//	case 2:	case -5:
//		{return 5;break;}
//	case 3:	case -4:
//		{return 4;break;}
//	case 4:	case -3:
//		{return 3;break;}
//	case 5:	case -2:
//		{return 2;break;}
//	case 6:	case -1:
//		{return 1;break;}
//	case 0:
//		{return 0;break;}
//	default:
//		return 7;
//		break;
//	};
//}
//int cacudays(int year,int month)
//{
//		switch(month)
//		{
//		case 1:		case 3:		case 5:		case 7:		case 8:		case 10:		case 12:
//			{
//				return 31;
//				break;
//			}
//		case 4:		case 6:		case 9: 	case 11:
//			{
//				return 30;
//				break;
//			}
//		case 2:
//			{
//				if(Isleap(year))
//					return 29;
//				else
//					return 28;
//				break;
//			}
//		default:
//			break;
//		}
//		return 0;
//}
//void Myprint(tm *today,int DYear,int DMonth,int DDay)
//{
//	int ToYear=today->tm_year + 1900;
//	int ToMonth= today->tm_mon + 1;
//	int ToDay=today->tm_mday;
//	printf("----------------------\n");
//	printf("     %d��%d��         \n",DYear,DMonth);
//	printf("----------------------\n");
//	//��ӡ����
//	printf(" �� һ �� �� �� �� ��\n");
//	printf("----------------------\n"); 
//	struct tm  dayinfo = {0};
//	dayinfo.tm_year = DYear-1900; // ����ע�⣬���Ҫ��ȥ1900
//	dayinfo.tm_mon = DMonth-1; // �·ݴ�0��ʼ�㣬 ����10�²���д10Ҫд9
//	dayinfo.tm_mday =1; //����������д��
//	mktime(&dayinfo);
//	int j=dayinfo.tm_wday;
//	//printf("%d %d %d\n",DYear,DMonth-1,j);
//	for (int i = 0; i < j; i++)
//	{
//		printf("   ");
//	}
//	int days=cacudays(DYear,DMonth);
//	int flag=j;
//	for(int k=1;k<=days;k++)
//	{
//		if(6==j)
//		{
//			printf("%3d\n",k);
//			j=0;
//		}else
//		{
//			printf("%3d",k);
//			j++;
//		}
//	}
//	printf("\n");
//	printf("----------------------\n");
//	printf("������: %d��%d��%d��\n\n",ToYear,ToMonth,ToDay);
//	printf("\n");
//	printf("��: ��һ��  ��: ��һ��\n");
//	printf("��: ��һ��  ��: ��һ��\n\n");
//	printf("Home: ����  Esc: �˳�\n");
//}
//void main()
//{
//	struct tm *today;
//	time_t ltime;
//	time(&ltime);
//	today = localtime(&ltime);
//	int DYear=today->tm_year + 1900;
//	int DMonth= today->tm_mon + 1;
//	int DDay=today->tm_mday;
//	Myprint(today,DYear,DMonth,DDay);
//	while(1)
//	{
//		time_t ltime;
//		time(&ltime);
//		today = localtime(&ltime);
//		fflush(stdin);
//		clearerr(stdin);
//		char ch;
//		ch=getch();
//		switch(ch)
//		{
//		case 75:	//<-
//			{
//			DYear--;
//			system("cls");
//			Myprint(today,DYear,DMonth,DDay);
//			break;
//			}
//		case 77:	//->
//			{
//			DYear++;
//			system("cls");
//			Myprint(today,DYear,DMonth,DDay);
//			break;
//			}
//		case 80:	//��
//			DMonth++;
//			if (DMonth > 12)
//			{
//				DYear++;
//				DMonth = 1;
//				system("cls");
//				Myprint(today,DYear,DMonth,DDay);
//			}
//			else
//			{
//				system("cls");
//				Myprint(today,DYear,DMonth,DDay);
//			}
//			break;
//		case 72:	//��
//			DMonth--;
//			if (DMonth < 1)
//			{
//				DYear--;
//				DMonth = 12;
//				system("cls");
//				Myprint(today,DYear,DMonth,DDay);
//			}
//			else
//			{
//				system("cls");
//				Myprint(today,DYear,DMonth,DDay);
//			}
//			break;
//		case 71:	//Home
//			DYear = today->tm_year + 1900;
//			DMonth = today->tm_mon + 1;
//			system("cls");
//			Myprint(today,DYear,DMonth,DDay);
//			break;
//		case 27:	//Esc
//			exit(0);
//			break;
//		}
//	}
//	//printf("%d\n",Get_f_w(1,0));
//}
