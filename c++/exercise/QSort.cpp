#include <iostream>

using namespace std;
//#define swap(x, y) {(x) = (x) + (y); (y) = (x) - (y); (x) = (x) - (y);}
//
//
//void QuickSort(int a[],int numsize)/*a���������飬numsize��Ԫ�ظ���*/
//{
//	int i=0,j=numsize-1;
//	int val=a[0];/*ָ���ο�ֵval��С*/
//	if(numsize>1)/*ȷ�����鳤������Ϊ2��������������*/
//	{
//		while(i<j)/*ѭ����������*/
//		{
//			/*�Ӻ���ǰ������valС��Ԫ�أ��ҵ����a[i]�в�����ѭ��*/
//			for(;j>i;j--)
//				if(a[j]<val)
//				{
//					a[i++]=a[j];
//					break;
//				}
//			/*��ǰ����������val���Ԫ�أ��ҵ����a[j]�в�����ѭ��*/
//			for(;i<j;i++)
//				if(a[i]>val)
//				{
//					a[j--]=a[i];
//					break;
//				}
//		}
//		a[i]=val;/*��������val�е����ŵ�a[i]��*/
//		QuickSort(a,i);/*�ݹ飬��ǰi��������*/
//		QuickSort(a+i+1,numsize-i-1);/*��i+2��numsize��numsize-1-i��������*/
//	}
//}
void main()
{
	int i=0;
	while(++i<10)
		cout<<"1"<<endl;
//	int a[] = {49, 38, 65, 97, 76, 13, 27};
//	QuickSort(a,7);
//	for(int i=0;i<7;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
}
