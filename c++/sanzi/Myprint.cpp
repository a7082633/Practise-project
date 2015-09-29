//#include<stdio.h>
//
//void printInt(int a)
//{
//	if(a/10==0)
//	{
//		putchar(a+48);
//		return;
//	}
//	printInt(a/10);
//	putchar(a%10+48);
//
//}
//void printfl(double f)
//{
//	int shi=(int)f;
//	printInt(shi);
//	putchar('.');
//	double t=(f-shi)*1000000;
//	int xiaoshu=t;
//	printInt(xiaoshu);
//}
//void printstr(char *str)
//{
//	while(*str!='\0')
//		putchar(*str++);
//}
//void MyPrinf(char *str,...)
//{
//	int count=1;
//	while(*str!='\0')
//	{
//		int *p=(int*)&str;
//		if(*str=='%')
//		{
//			str++;
//			switch(*str)
//			{
//				case'c':
//					putchar(*(p+count++));
//					break;
//				case'd':
//					printInt(*(p+count++));
//					break;
//				case'f':
//					printfl(*(double *)(p+count++));
//					break;
//				case's':
//					count++;
//					printstr((char*)(*(p+count++)));
//					break;
//				default:
//					putchar(*--str);
//			}
//			str++;
//		}
//		putchar(*str);
//		str++;
//	}
//}
//void main()
//{
//	char *s="hello!";
//	int a=5000;
//	MyPrinf(" just%%%%% %ooo test: %c  %d %f %s",'d',a,3.1415926,"hello world!");
//	printf("\n");
//	printf(" %%%%%q %d",3);
//	//test("abcde",1,2,3);
//}