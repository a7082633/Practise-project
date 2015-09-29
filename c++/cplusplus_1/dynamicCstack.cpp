//#include <iostream>
//#include <string>
//using namespace std;
//
//#define dim(x) sizeof(x) / sizeof(x[0])
//
//template <typename T>
//class CStack
//{
//private:
//	struct Lstack
//	{
//		T data;
//		Lstack *next;
//	};
//	Lstack *top;
//	int size;
//public:
//	CStack()
//	{
//		size=0;
//		top=NULL;
//	}
//	void Push(T x)
//	{
//		Lstack *pNew = new Lstack;
//		pNew->data=x;
//		pNew->next=NULL;
//
//		if (top == NULL)
//		{
//			top = pNew;
//			size++;
//		}
//		else
//		{
//			pNew->next = top;
//			top = pNew;
//			size++;
//		}
//	}
//
//	void Pop(T &data)
//	{
//		Lstack *temp=top;
//		data=top->data;
//		top=top->next;
//		size--;
//		delete temp;
//	}
//
//	T Top()
//	{
//		if(top==NULL) return NULL;
//		return top->data;
//	}
//	int Size()
//	{
//		return size;
//	}
//	bool IsNotEmpty()
//	{
//		if(top==NULL) return false;
//		return true;
//	}
//};
//
//
//template <>
//class CStack<char *>
//{
//private:
//	struct Lstack
//	{
//		char * data;
//		Lstack *next;
//	};
//	Lstack *top;
//	int size;
//public:
//	CStack()
//	{
//		size=0;
//		top=NULL;
//	}
//	void Push(char * x)
//	{
//		Lstack *pNew = new Lstack;
//		pNew->data=new char[strlen(x)+1];
//		strcpy(pNew->data,x);
//		pNew->next=NULL;
//
//		if (top == NULL)
//		{
//			top = pNew;
//			size++;
//		}
//		else
//		{
//			pNew->next = top;
//			top = pNew;
//			size++;
//		}
//	}
//
//	void Pop(char * &data)
//	{
//		if(!IsNotEmpty()) return;
//		Lstack *temp=top;
//		data=top->data;
//		top=top->next;
//		size--;
//		delete temp->data;
//		delete temp;
//	}
//
//	char * Top()
//	{
//		if(top==NULL) return NULL;
//		return top->data;
//	}
//	int Size()
//	{
//		return size;
//	}
//	bool IsNotEmpty()
//	{
//		if(top==NULL) return false;
//		return true;
//	}
//};
//int main()
//{
//	//调用普通模版
//	int i;
//	CStack<int> stInt;
//	for (i = 1; i <= 20; i++)
//	{
//		stInt.Push(i);
//	}
//	cout << "调用CStack<int>普通模版, 元素个数为: " << stInt.Size() << endl;
//	while (stInt.IsNotEmpty())
//	{
//		int iData;
//		stInt.Pop(iData);
//		cout << iData << " ";
//	}
//	cout << endl << endl;
//	//调用特化模版
//	CStack<char *> stCharP;
//	for (i = 1; i <= 15; i++)
//	{
//		char sz[10];
//		sprintf(sz, "s%d", i);
//		stCharP.Push(sz);
//	}
//	cout << "调用CStack<char *>特化模版, 元素个数为: " << stCharP.Size() << endl;
//	while (stCharP.IsNotEmpty())
//	{
//		char * pData;
//		cout << stCharP.Top() << " ";
//		stCharP.Pop(pData);
//	}
//	cout << endl << endl;
//	//返回
//	system("pause");
//	return 0;
//}
