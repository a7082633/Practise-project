////#include <iostream>
////#include <string>
////#include "CStack.h"
////using namespace std;
////
//////template <typename T2,typename T3>
////int main()
////{
////	CStack stack;
////	stack.push(1);
////	stack.push(2);
////	stack.push(3);
////	stack.push(4);
////	cout<<stack.top()<<endl;
////	stack.pop();
////	cout<<stack.top()<<endl;
////	stack.pop();
////	cout<<stack.top()<<endl;
////	stack.pop();
////	return 0;
////}
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
//	#define N 3
//	T m_iData[N];
//	int m_iTop;
//public:
//	CStack()
//	{
//		for (int i = 0; i < N; i++)
//		{
//			m_iData[i] = (T)0;
//		}
//		m_iTop = 0;
//	}
//
//	void Push(T x)
//	{
//		if (m_iTop >= N) return;
//		m_iData[m_iTop++] = x;
//	}
//
//	void Pop()
//	{
//		if (m_iTop <= 0) return;
//		m_iData[--m_iTop] = (T)0;
//	}
//
//	T Top()
//	{
//		if (m_iTop <= 0) return (T)-1;
//		return m_iData[m_iTop-1]; 
//	}
//};
//
//template <>
//class CStack<char*>
//{
//private:
//	#define N 3
//	char* m_iData[N];
//	int m_iTop;
//
//public:
//	CStack()
//	{
//		for (int i = 0; i < N; i++)
//		{
//			m_iData[i] = NULL;
//		}
//		m_iTop = 0;
//	}
//
//	void Push(char* x)
//	{
//		if (m_iTop >= N) return;
//		m_iData[m_iTop]=new char[strlen(x)+1];
//		strcpy(m_iData[m_iTop++],x);
//	}
//
//	void Pop()
//	{
//		if (m_iTop <= 0) return;
//		delete m_iData[--m_iTop];
//		m_iData[m_iTop] = NULL;
//	}
//
//	char* Top()
//	{
//		if (m_iTop <= 0) return "<null>";
//		return m_iData[m_iTop-1]; 
//	}
//};
//
//void main()
//{
//	CStack<double> st;
//	st.Push(1.1);
//	st.Push(2.2);
//	st.Push(3.3);
//	st.Push(4.4);
//
//	cout << st.Top() << endl;
//
//	st.Pop();
//	cout << st.Top() << endl;
//
//	st.Pop();
//	cout << st.Top() << endl;
//	
//	st.Pop();
//	cout << st.Top() << endl;
//	
//	st.Pop();
//	cout << st.Top() << endl;
//
//	CStack<char*> sts;
//	sts.Push("AAA");
//	sts.Push("BBB");
//	sts.Push("CCC");
//	sts.Push("DDD");
//
//	cout << sts.Top() << endl;
//
//	sts.Pop();
//	cout << sts.Top() << endl;
//	
//	sts.Pop();
//	cout << sts.Top() << endl;
//	
//	sts.Pop();
//	cout << sts.Top() << endl;
//}
