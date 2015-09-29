//#include <iostream>
//
//using namespace std;
//#define SIZE 8
//#define swap(x, y) {(x) = (x) + (y); (y) = (x) - (y); (x) = (x) - (y);}
//void main()
//{
//	int a[8]={ 76 , 81 , 60 , 22 , 98 , 33 , 12 , 79 };
////	int a[SIZE]={ 6 , 5, 4 , 3 , 2};
//	int i=SIZE/2;
//	int count=0;
//	while(i)
//	{
//		for(int j=0;j<i;j++)
//		{
//			//int p=j;
//			for(int m=j+i;m<SIZE;m=m+i)
//			{
//				//int p=m;
//				for(int n=j;n<m;n=n+i)
//				{
//					int p=n;
//					if(a[m]<a[n])
//					{
//						int t=a[m];
//						for(int k=m;k>n;k=k-i)
//							a[k]=a[k-i];
//						a[p]=t;
//					}
//				}
//			}
//		}                                                                    
//		i=i/2;
//	}
//	for(i=0;i<SIZE;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	cout<<count<<endl;
//}
//
////	while(i)
////	{
////		for(j=0;j<=SIZE-i;j++)
////		{
////			int p=j;
////			for(int k=j+1;k<j+i;k++)
////			{
////				for(int m=j;m<k;m++)
////				{
////					if(a[k]<a[m])
////					{
////						int t=a[k];
////						for(int n=k;n>=m;n--)
////							a[n]=a[n-1];
////						a[p]=t;
////					}
////				}
////			}
////		}
////		i=i/2;
////	}
////////////////////////////////////
////	while(k>0)
////	{
////		for(i=k;i<SIZE;i++)
////		{
////			t=a[i];
////			j=i-k;
////			while(j>=0&&t<a[j])
////			{
////				a[j+k]=a[j];
////				j=j-k;
////			}
////			a[j+k]=t;
////		}'
////		k/=2;
////	}