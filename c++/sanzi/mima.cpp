//#include<stdio.h>
//#include <conio.h>
//#define SIZE 20
//void main()
//{
//	int i=0;
//	printf("plz input your paswd:");
//	char pswd[SIZE]={0};
//	while(1)
//	{
//		char c=getch();
//		if(c==13)
//			break;
//		if(i!=0&&c==8)
//		{
//			printf("\b \b");
//			i=i-1;
//			if(i<SIZE)
//			{
//				pswd[i]=0;
//			}
//			continue;
//		}
//		if(i==0&&c==8)
//			continue;
//		if(i<SIZE)
//		{
//			pswd[i]=c;
//		}
//		i=i+1;
//		putchar('*');
//	}
//	printf("\n");
//	puts(pswd);
//}