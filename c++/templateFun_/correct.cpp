#include <iostream>
using namespace std;
//#pragma warning (disable : 4996)
//#pragma warning (disable : 4035)

#define dim(x) sizeof(x) / sizeof(x[0])

template<typename T>
void Swap(T& x, T& y)
{
	T t = x;
	x = y;
	y = t;
}

class CString
{
	//�ӷ�������. Ϊ��Ӧ str3 = "abc" + str2 �������, ��ʹ����Ԫ������ʽ
	friend CString operator+(const CString &s1, const CString &s2);
	friend ostream& operator<<(ostream &os, const CString &s);

private:
	char *m_pData;

public:
	//��������
	~CString()
	{
		delete m_pData;
		m_pData = NULL;
//		cout << "��������." << endl;
	}

	//Ĭ�Ϲ��캯��
	CString(const char *pBuf = NULL)
	{
		if (pBuf == NULL)
		{
			m_pData = new char[1];
			m_pData[0] = '\0';
		}
		else
		{
			m_pData = new char[strlen(pBuf) + 1];
			strcpy(m_pData, pBuf);
		}
	}

	//�������캯��
	CString(const CString &s)
	{
		m_pData = new char[strlen(s.m_pData) + 1];
		strcpy(m_pData, s.m_pData);
	}

	//��ֵ������=
	CString &operator=(const CString &s)
	{
		if (this != &s)
		{
			delete m_pData;
			m_pData = new char[strlen(s.m_pData) + 1];
			strcpy(m_pData, s.m_pData);
		}
		return (*this);
	}

	//size
	int GetLength() const 
	{
		return strlen(m_pData);
	}

	//�±�[]������
	char & operator[](unsigned int &i)
	{
	    if (i >= 0 && i <= strlen(m_pData))	//��֤�±겻Խ��
			return m_pData[i];
		else
			return m_pData[0];
	}

	////char *����ת��
	//operator char *() const 
	//{
	//	return m_pData;
	//}

	bool operator>(const CString& s) const
	{
		return (strcmp(this->m_pData, s.m_pData) > 0);
	}

	bool operator>=(const CString& s) const
	{
		return (strcmp(this->m_pData, s.m_pData) >= 0);
	}

	bool operator<=(const CString& s) const
	{
		return (strcmp(this->m_pData, s.m_pData) <= 0);
	}

	bool operator==(const CString& s) const
	{
		return (strcmp(this->m_pData, s.m_pData) == 0);
	}
};

//�ӷ�������
CString operator+(const CString &s1, const CString &s2)
{
	CString newStr;
	newStr.m_pData = new char[strlen(s1.m_pData) + strlen(s2.m_pData) + 1];
	strcpy(newStr.m_pData, s1.m_pData);
	strcat(newStr.m_pData, s2.m_pData);
	return newStr;
}

//<<������
ostream& operator<<(ostream &os, const CString &s)
{
	os << s.m_pData;
	return os;
}

template<typename T>
int Partition(T a[], int nMin, int nMax)
{
	//int nKey= MID(a[nMin], a[nMax], a[(nMin+nMax)>>1]);	//ƽ�����: ȡ��ֵ��ΪKey
	T nKey = a[nMin];	//49

	int i = nMin;
	int j = nMax;
	do
	{
		//�ɺ���ǰ�ҵ���һ����nKeyС��Ԫ��, ����a[i]����
		while (a[j] >= nKey && i < j)
		{
			j--;
		}
		if (i < j) Swap(a[i], a[j]);

		//��ǰ����ҵ���һ����nKey���Ԫ��, ����a[j]����
		while (a[i] <= nKey && i < j)
		{
			i++;
		}
		if (i < j) Swap(a[i], a[j]);

	} while (i < j);

	return j;
}

template<typename T>
void QuickSort(T a[], int nMin, int nMax)
{
	if (nMin >= nMax) return;
	if (nMin + 1 == nMax)	// ��ֻ������Ԫ��,ֱ�ӱȽ�
	{
		if (a[nMin] > a[nMax])
		{
			Swap(a[nMin], a[nMax]);
		}
		return;
	}

	int j = Partition(a, nMin, nMax);
	QuickSort(a, nMin, j - 1);	//left
	QuickSort(a, j + 1, nMax);	//right
}

int main()
{
	int x[] = {49, 38, 65, 97, 76, 13, 27};

	QuickSort(x, 0, dim(x) - 1);

	for (int i = 0; i < dim(x); i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;


	CString ss[] = {"zz", "ff", "cc", "bb"};
	QuickSort(ss, 0, dim(ss)-1);

	for (int i = 0; i < dim(ss); ++i)
	{
		cout << ss[i] << " ";
	}
	cout << endl;

	return 0;
}
