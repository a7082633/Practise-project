//#include<stdio.h>
////#include<windows.h>
//typedef int (*PF)(int,int);
//#define dim(x) (sizeof(x)/sizeof(x[0]))
//int add(int x,int y)
//{
//	return x+y;
//}
//int sub(int x,int y)
//{
//	return x-y;
//}
//int mul(int x,int y)
//{
//	return x*y;
//}
//int div(int x,int y)
//{
//	if(y==0) return -1;
//	return x/y;
//}
//struct BB
//{
//	char c;
//	PF  pFun;
//};
//void main()
//{
//	BB ff[]={'+',add,'-',sub,'*',mul,'/',div};
//	int a = 3;
//	int b = 4;
//	char c = '*';
//	for(int i = 0;i < dim(ff);i++)
//	{
//		if(c == ff[i].c)
//		{
//			PF fun = ff[i].pFun;
//			printf("%d\n",fun(a,b));
//			break;
//		}
//	}
//}