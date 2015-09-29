#include<iostream>
#include<string.h>
using namespace std;
//void main()
//{
//	char str[20]={0};
//	FILE *fp=fopen("D:\\test.txt","r+");
//	if(fp==NULL)
//	{
//		fp=fopen("D:\\test.txt","w+");
//		if(fp==NULL)
//			return;
//	}
//	FILE *fp2=fopen("D:\\test2.txt","r+");
//	if(fp==NULL)
//	{
//		fp=fopen("D:\\test2.txt","w+");
//		if(fp==NULL)
//			return;
//	}
//	
//	char c=0;
//	while(c!=-1)
//	{
//		c=fgetc(fp2);
//		fprintf(fp,"%c",c);
//	}
//	//cout<<str<<endl;
//	fclose(fp2);
//	fclose(fp);
//}

//1、从键盘输入一个字符串，将其中的小写字母全部转换为大写字母，然后输出到一个磁盘文件test中保存。输入的字符串以!结束。

//void main()
//{
//	char str[20]={0};
//	FILE *fp=fopen("D:\\test.txt","r+");
//	if(fp==NULL)
//	{
//		fp=fopen("D:\\test.txt","w+");
//		if(fp==NULL)
//			return;
//	}
//	cout<<"plz input string:";
//	cin>>str;
//	int i=0;
//	while(str[i++])
//	{
//		if(str[i]=='!')
//			str[i]='\0';
//	}
//	_strupr(str);
//	fprintf(fp,"%s",str);
//	fclose(fp);
//}
//2、有两个磁盘文件"A"和"B"，各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件"c"中。
//void main()
//{
//	char str[20]={0};
//	FILE *fp=fopen("D:\\a.txt","r+");
//	if(fp==NULL)
//	{
//		fp=fopen("D:\\a.txt","w+");
//		if(fp==NULL)
//			return;
//	}
//	FILE *fp2=fopen("D:\\b.txt","r+");
//	if(fp==NULL)
//	{
//		fp2=fopen("D:\\b.txt","w+");
//		if(fp2==NULL)
//			return;
//	}
//	FILE *fp3=fopen("D:\\c.txt","r+");
//	if(fp3==NULL)
//	{
//		fp3=fopen("D:\\c.txt","w+");
//		if(fp3==NULL)
//			return;
//	}
//	int i=0;
//	char c=0;
//	while(-1!=(c=fgetc(fp)))
//	{
//		str[i++]=c;
//	}
//	c=0;
//	while(-1!=(c=fgetc(fp2)))
//	{
//		str[i++]=c;
//	}
//	cout<<"orginal str:"<<str<<endl;
//	int strl=strlen(str);
//	for(i=0;i<strl-1;i++)
//	{
//		for(int j=i+1;j<strl;j++)
//		{
//			if(str[i]>str[j])
//			{
//				char t=str[i];
//				str[i]=str[j];
//				str[j]=t;
//			}
//		}
//	}
//	cout<<"after sort str:"<<str<<endl;
//	fprintf(fp3,"%s",str);
//	fclose(fp3);
//	fclose(fp2);
//	fclose(fp);
//}

//3、从键盘输入若干行字符（每行长度不等），输入后把它们存储到一磁盘文件中。再从该文件中读入这些数据，将其中小写字母转换为大写字母后在屏幕上输出。

//void main()
//{
//	char str[100]={0};
//	char str2[100]={0};
//	char str3[100]={0};
//	FILE *fp=fopen("D:\\test.txt","r+");
//	if(fp==NULL)
//	{
//		fp=fopen("D:\\test.txt","w+");
//		if(fp==NULL)
//			return;
//	}
//	cout<<"plz input str:"<<endl;
//	int m=0;
//	int strl=0;
//	while(cin>>str2)
//	{
//		strl=strlen(str);
//		strcat(str,str2);
//		if(strl!=0)
//		{
//			str[strl]='\n';
//		}
//	}
//	fprintf(fp,"%s",str);
//	fseek(fp,0,SEEK_END);
//	int m=ftell(fp);
//	fseek(fp,0,SEEK_SET);
//	fread(str3,1,m,fp);
//	_strupr(str3);
//	cout<<str3;
////	fseek(fp,0,SEEK_END);f
////	int m=ftell(fp);
//	fclose(fp);
//}