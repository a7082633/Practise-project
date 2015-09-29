//#include <stdio.h>
//#include <string.h>
//
//#define dim(x) sizeof(x)/sizeof(x[0])
//
//void MyStrCpy(char *dest,const char *source)
//{
//	if(dest==NULL||source==NULL) return;
//	if(strlen(dest)<strlen(source)) return;
//	do
//	{
//		*dest=*source;
//		dest++;
//		source++;
//	}while(*(source-1));
//}
//
//void MyStrCat(char *dest,const char *source)
//{
//	char *p=dest;
//	while(*dest)
//	{
//		p++;
//		dest++;
//	}
//	while(*source)
//	{
//		*p=*source;
//		p++;
//		source++;
//	}
//}
//int MyStrCmp(char *first,char *second)
//{
//	char *p=first,*q=second;
//	int count=0,count2=0;
//	while(*p)
//	{
//		p++;
//		count++;
//	}
//	while(*q)
//	{
//		q++;
//		count2++;
//	}
//	if(count>=count2)
//	{
//		while(*first)
//		{
//			if(*first>*second)
//				return 1;
//			if(*first<*second)
//				return -1;
//			first++;
//			second++;
//		}
//	}else
//	{
//		while(*second)
//		{
//			if(*first>*second)
//				return 1;
//			if(*first<*second)
//				return -1;
//			first++;
//			second++;
//		}
//	}
//	
//	return 0;
//}
//int MyStrLen(char *str)
//{
//	int count=0;
//	while(*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//char* MyStrStr(char *str,char *v)
//{
//	int strvl=MyStrLen(v);
//	bool flag=false;
//	while(*str)
//	{
//		if(*str==*v)
//		{
//			str++;
//			v++;
//			flag=true;
//		}
//		else
//		{
//			str++;
//			flag=false;
//		}
//		if(flag&&!*v)
//			return str-strvl;
//	}
//	return false;
//}
//void MyStrUpr(char *str)
//{
//	while(*str)
//	{
//		if(*str>'a'&&*str<'z')
//			*str=*str-32;
//		str++;
//	}
//}
//void MyStrLwr(char *str)
//{
//	while(*str)
//	{
//		if(*str>'A'&&*str<'Z')
//			*str=*str+32;
//		str++;
//	}
//}
//void main()
//{//------------strcpy---------------
////	char a[10];
////	char b[]="hellobfhhh";
////	strcpy(a,b);
////	MyStrCpy(a,b);
////	printf("%s\n",a);
////------------strcat---------------
////	char a[10]="love";
////	char b[]="chinaldfggkdlgerg";
////	MyStrCat(a,b);
////	//strcat(a,b);
////	printf("%s\n",a);
////------------strcmp---------------
////	char a[10]="love";
////	char b[]="love";
////	printf("%d\n",MyStrStr(a,b));
////	printf("%d\n",strstr(a,b));
////------------strlen---------------
////	char a[10]="love0";
////	char b[]="lovo";
////	printf("%d\n",MyStrLen(a));
////	printf("%d\n",strlen(a));
////------------strstr---------------
////	char a[10]="lovechina";
////	char b[]="a";
////------------strupr---------------
////	char a[10]="lovechina";
////	MyStrUpr(a);
////------------strlwr---------------
////	char a[10]="LOvechina";
////	MyStrLwr(a);
////	printf("%s\n",_strlwr(a));
////	printf("%s\n",a);
//}