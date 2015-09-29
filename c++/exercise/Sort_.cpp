//#include <stdio.h>
//
//#define dim(x) sizeof(x) / sizeof(x[0])
//#define swap(x, y) {(x) = (x) + (y); (y) = (x) - (y); (x) = (x) - (y);}
//#define MID(x, y, z) (y < x && x < z) ? x : (x < y && y < z ? y : z)
//
////直接插入排序
////1.定义
////    直接插入排序(straight insertion sort)是一种最简单的排序方法。
////它的基本操作是将一个记录插入到一个长度为 m (假设)的有序表中，
////使之仍保持有序，从而得到一个新的长度为 m + 1 的有序表。
////2.算法思路
////　　设有一组关键字｛ K1 ， K2 ，…， Kn ｝；排序开始就认为
////K1 是一个有序序列；让 K2 插入上述表长为 1 的有序序列，使之
////成为一个表长为 2 的有序序列；然后让 K3 插入上述表长为 2 的有
////序序列，使之成为一个表长为 3 的有序序列；依次类推，最后让 Kn 
////插入上述表长为 n-1 的有序序列，得一个表长为 n 的有序序列。
//
////49, 38, 65, 97, 76, 13, 27
////{49, 38, 65, 97, 76, 13, 27};
////38, 49, 65, 97, 76, 13, 27
////38, 49, 65, 97, 76, 13, 27
////38, 49, 65, 76, 97, 13, 27
////13, 38, 49, 65, 76, 97, 27
////13, 27, 38, 49, 65, 76, 97
//
//void StraightInsertSort (int a[], int n)
//{
//	for(int i=1;i<n;i++)
//	{
//		for(int j=0;j<i;j++)
//		{
//			if(a[i]<a[j])
//			{
//				int t=a[i];
//				for(int k=i;k>=j;k--)
//				{
//					a[k]=a[k-1];
//				}
//				a[j]=t;
//			}
//		}
//	}
//}
//
//int BiLessSearch(int pSource[], int iTarget, int iLeft, int iRight)
//{
//	return 0;
//}
//void BinaryInsertSort (int a[], int n)
//{
//	int mid=0;
//	for(int i=1;i<n;i++)
//	{
//		mid=i/2;
//		while(1)
//		{
//			if(a[i]<a[mid])
//			{
//				int t=a[i];
//				for(int k=i;k>=j;k--)
//				{
//					a[k]=a[k-1];
//				}
//				a[j]=t;
//			}
//		}
//	}
//}
//
//void main()
//{
//	int a[] = {49, 38, 65, 97, 76, 13, 27};
//	StraightInsertSort(a,dim(a));
//	for (int i = 0; i < dim(a); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\r\n");
//}
