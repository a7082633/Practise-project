//#include<iostream>
//using namespace std;
//struct SqStack
//{
//	char c[9];
//	int top;
//}; 
//bool IsEmpty(SqStack *s)
//{
//	if(s->top==0) return true;
//	return false;
//}
//bool IsFull(SqStack *s)
//{
//	if(s->top==9) return true;
//	return false;
//}
//void Push(SqStack *s,char v)
//{
//	if(IsFull(s)) return;
//	s->c[s->top]=v;
//	s->top++;
//}
//void Pop(SqStack *s)
//{
//	if(IsEmpty(s)) return;
//	s->c[--s->top]=0;;
//}
//char Top(SqStack *s)
//{
//	if(IsEmpty(s)) return -1;
//	return s->c[s->top-1];
//}
//void main()
//{
//	SqStack a;
//	a.top = 0;
//	//strcpy(a.c,0);
//
//	Push(&a, 1);
//	Push(&a, 2);
//	Push(&a, 3);
//	cout<<"test!!!!!!"<<endl;
//	cout<<Top(&a)<<endl;
//	Pop(&a);
//	cout<<Top(&a)<<endl;
//	Pop(&a);
//	cout<<Top(&a)<<endl;
//	Pop(&a);
////	Print(&a);
////	Pop(&a);
////	Print(&a);
////	Pop(&a);
////	Print(&a);
//}