//#include<iostream>
//#include<string.h>
//using namespace std;
//void main(int argc,char *argv[])
//{
//	FILE *fp=fopen(argv[1],"rb+");
//	if(fp==NULL)
//	{
//		fp=fopen(argv[1],"wb+");
//		if(fp==NULL)
//		{
//			cout<<"cant open first file"<<endl;
//			return;
//		}
//	}
//	cout<<argv[1]<<endl;
//
//
//	int l=strlen(argv[2]);
//	char *str=argv[2];
//	if(str[l-1]=='\\')
//	{
//		strcat(argv[2],"test.txt");
//	}
//
//
//	FILE *fp2=fopen(argv[2],"rb+");
//	if(fp2==NULL)
//	{
//		fp2=fopen(argv[2],"wb+");
//		if(fp2==NULL)
//		{
//			cout<<"cant open second file"<<endl;
//			return;
//		}
//	}
//	cout<<argv[2]<<endl;
//	fseek(fp,0,SEEK_END);
//	int m=ftell(fp);
//	fseek(fp,0,SEEK_SET);
//	char *p=new char[m];
//	fread(p,1,m,fp);
//	fwrite(p,1,m,fp2);
//	fclose(fp2);
//	fclose(fp);
////	cout<<'\\'<<endl;
//}