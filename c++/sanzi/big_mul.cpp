//#include <iostream>
//using namespace std;
//#define max(a,b) (a>b?a:b);
//#define min(a,b) (a<=b?a:b);
//#define MAX_SIZE 700
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
//void mul(char *a,char *b,char *result)
//{
//	int lenA=strlen(a);
//	int lenB=strlen(b);
//	char *temp=(char*)malloc(MAX_SIZE);
//	char *temp2=(char*)malloc(MAX_SIZE);
//	char *r=(char*)malloc(MAX_SIZE);
//	memset(temp,0,MAX_SIZE);
//	memset(temp2,0,MAX_SIZE);
//	memset(r,0,MAX_SIZE);
//	int mulj=0;
//	int resul=0;
//	int flag=0;
//	int k=0;
//	for(int i=lenA-1;i>=0;i--,k++)
//	{
//		for(int j=lenB-1;j>=0;j--)
//		{
//			int a1=a[i]-48;
//			int b1=b[j]-48;
//			if(mulj) resul=a1*b1+mulj;
//			else     resul=a1*b1;
//			mulj=resul/10;
//			temp[flag++]=resul%10+48;
//		}
//		if(mulj) temp[flag++]=mulj+48;
//		mulj=0;
//		strRev(temp);
//		if(i==(lenA-1))
//		{
//			strcpy(temp2,temp);
//		}else
//		{
//			for(int n=0;n<k;n++)
//			{
//				temp[flag++]='0';
//			}
//			add(temp,temp2,r);
//			memset(temp2,0,MAX_SIZE);
//			strcpy(temp2,r);
//			memset(r,0,MAX_SIZE);
//			strRev(temp2);
//		}
//		flag=0;
//		memset(temp,0,MAX_SIZE);
//	}
//	strcpy(result,temp2);
//}
//void main()
//{
//	char *first=(char*)malloc(MAX_SIZE);
//	char *second=(char*)malloc(MAX_SIZE);
//	char *p=(char*)malloc(MAX_SIZE);
//	memset(first,0,MAX_SIZE);
//	memset(second,0,MAX_SIZE);
//	memset(p,0,MAX_SIZE);
//	mul("233429991444444442444444444444444444444444444444444444444428090000000000000000000000000000000000000000005388888888888888888888888888888888888888888888888888888888","34599999999999999999999999924444444444444444444444444444444444444444555555555555555555555456784",p);
//	cout<<p<<endl;
//	printf("%d\n",23342*456784);
//
//}