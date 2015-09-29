#include "CString.h"
#include "stdio.h"
//#define SWAP(x, y) {(x) = (x) + (y); (y) = (x) - (y); (x) = (x) - (y);}
#define dim(a) (sizeof(a)/sizeof(a[0]))

ostream& operator<<(ostream &os,const CString &ss)
{
	os<<ss.str;
	return os;
}
template <typename T>
void SWAP(T &str,T &str2)
{
	T temp=str;
	str=str2;
	str2=temp;
}

template <typename T>
int Partition(T a[], int nMin, int nMax)
{
	//int nKey= MID(a[nMin], a[nMax], a[(nMin+nMax)>>1]);	//平衡快排: 取中值做为Key
	T nKey= a[nMin];	//49

	int i = nMin;
	int j = nMax;
	do
	{
		//由后向前找到第一个比nKey小的元素, 并与a[i]交换
		while (a[j] >= nKey && i < j)
		{
			j--;
		}
		if (i < j) SWAP(a[i], a[j]);

		//由前向后找到第一个比nKey大的元素, 并与a[j]交换
		while (a[i] <= nKey && i < j)
		{
			i++;
		}
		if (i < j) SWAP(a[i], a[j]);

	} while (i < j);

	return j;
}
template <typename T>
void QuickSort(T a[], int nMin, int nMax)
{
	if (nMin >= nMax) return;
	if (nMin + 1 == nMax)	// 若只有两个元素,直接比较
	{
		if (a[nMin] > a[nMax]) SWAP(a[nMin], a[nMax]);
		return;
	}

	int j = Partition(a, nMin, nMax);
	QuickSort(a, nMin, j - 1);	//left
	QuickSort(a, j + 1, nMax);	//right
}
int main()
{
	int i=0;
	int x[] = {49, 38, 65, 97, 76, 13, 27};

	QuickSort(x, 0, dim(x) - 1);

	for (i = 0; i < dim(x); i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;


	CString ss[] = {"zz", "ff", "cc", "bb"};
	QuickSort(ss, 0, dim(ss)-1);
	for (i = 0; i < dim(ss); ++i)
	{
		cout << ss[i] << " ";
	}
	cout << endl;
	return 0;
}