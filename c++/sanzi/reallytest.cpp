//#include<iostream>
//#include<stdio.h>
//using namespace std;
//void GetNext(char *str,int prefix[])
//{
//	prefix[0]=0;
//	int flag=0;
//	int i=0;
//	for(int j=1;j<strlen(str);j++)
//	{
//		if(str[i]==str[j])
//		{
//			prefix[j]=++flag;
//			i++;
//		}else
//		{
//			prefix[j]=0;
//			flag=0;
//			if(i)
//			{
//				--j;
//			}
//			i=0;
//		}
//	}
//}
//void main()
//{
//	char *str="abcdaabcab";
//	int *p=new int[strlen(str)];
//	GetNext(str,p);
//	for(int i=0;i<strlen(str);i++)
//	{
//		cout<<p[i]<<" ";
//	}
//	cout<<endl;
//}