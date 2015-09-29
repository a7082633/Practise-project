//#include <stdio.h>
//#include <string.h>
//
//int Add(short x, ...)
//{
//	int *px = (int*)((char*)&x + 4);
//	int iSum = 0;
//	while (x > 0)
//	{
//		iSum += *px;
//		px++;
//		x--;
//	}
//	return iSum;
//}
//
//
//int Add2(int x, ...)
//{
//	int *px = (int*)((char*)&x);
//	int iSum = 0;
//	while (*px!=-1)
//	{
//		iSum += *px;
//		px++;
//		x--;
//	}
//	return iSum;
//}
//
//void main()
//{
//	int a = Add2(1,3,4,5,-1);
//	int b = 0;
//	printf("%d\n",a);
//	//printf("%d %s", 34, "af");
//}