//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#define max(a,b) (a>b?a:b)
//#define min(a,b) (a<=b?a:b)
//#define MAX_SIZE 500
////1 1 2 3 5 8
//void strRev(char *s)
//{
//    char temp, *end = s + strlen(s) - 1;
//    while( end > s)
//    {
//        temp = *s;
//        *s = *end;
//        *end = temp;
//        --end;
//        ++s;
//    }
//}
//void add(char *a,char *b,char *result)
//{
//	int lenA=strlen(a);
//	int lenB=strlen(b);
//	int min=min(lenA,lenB);
//	int max=max(lenA,lenB);
//	char *pmax,*pmin;
//	if(strlen(a)>=strlen(b))
//	{
//		pmax=a;
//		pmin=b;
//	}else
//	{
//		pmax=b;
//		pmin=a;
//	}
//	int jin=0;
//	int t=0;
//	while(min)
//	{
//		int q=a[lenA-1]-48;
//		int w=b[lenB-1]-48;
//		if(jin==0)
//		{
//			t=q+w;
//		}else
//		{
//			t=q+w+jin;
//			jin=0;
//		}
//		if(t/10!=0)
//			jin=1;
//		*result=t%10+48;
//		result++;
//		lenA--;
//		lenB--;
//		min--;
//		max--;
//	}
//	while(jin!=0||max>0)
//	{	
//		if(max<=0)
//		{
//			t=jin;
//			jin=0;
//			*result=t%10+48;
//			return;
//		}else
//		{
//			t=pmax[max-1]-48+jin;
//			jin=0;
//		}
//		if(t/10!=0)
//			jin=1;
//		*result=t%10+48;
//		result++;
//		max--;
//	}
//}
//void ff(int x)
//{
//	if(x==1||x==2) 
//	{
//		printf("%d\n",1);
//		return;
//	}
//	char *first=(char*)malloc(MAX_SIZE);
//	char *second=(char*)malloc(MAX_SIZE);
//	char *p=(char*)malloc(MAX_SIZE);
//	char *pf=first;
//	char *ps=second;
//	char *pp=p;
//	for(int j=0;j<MAX_SIZE;j++)
//	{
//		*pf++=0x00;
//		*ps++=0x00;
//		*pp++=0x00;
//	}
//	*first='1';
//	*second='1';
//	*p='0';
//	for(int i=3;i<=x;i++)
//	{
//		add(first,second,p);
//		strRev(p);
//	//	p=first+second;
//		strcpy(first,second);
//	//	first=second;
//		strcpy(second,p);
//	//	second=p;	
//	}
//	printf("%s\n",p);
//	free(first);
//	free(second);
//	free(p);
//}
//void ff2(int x)
//{
//	if(x==1||x==2) 
//	{
//		printf("%d\n",1);
//		return;
//	}
//	int first=1;
//	int second=1;
//	int p=0;
//	for(int i=3;i<=x;i++)
//	{
//		p=first+second;
//		first=second;
//		second=p;	
//	}
//	printf("%d\n",p);
//}
//int jiecheng(int x)
//{
//	if(x<=0) return 0;
//	return jiecheng(x)+jiecheng(x-1);
//}
//
//int Fibonacci(int n)
//{
// if( n == 1 || n == 2)
//  return 1;
// else
//  return Fibonacci(n-1)+Fibonacci(n-2);
//}
//
//
//
//
//void main()
//{
//	char p[20]={0};
//	add("0000","00001",p);
//	int len=strlen(p);
//	strRev(p);
//	printf("%s",p);
//	printf("\n");
//	printf("%d\n",0000+00001);
//	printf("\n");
////	int n=1000;
////	ff(n);
////	ff2(n);
//}