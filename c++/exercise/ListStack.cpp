//#include <iostream>
//using namespace std;
//struct Lstack
//{
//	int data;
//	Lstack *next;
//};
//bool IsEmpty(Lstack *s)
//{
//	if(s->next==NULL) return true;
//	return false;
//}
//void Push(Lstack *s,int v)
//{
//	Lstack *snew=new Lstack;
//	snew->data=v;
//	snew->next=NULL;
//	if(s->next==NULL)
//	{
//		s->next=snew;
//	}
//	Lstack *t=s->next;
//	s->next=snew;
//	snew->next=t;
//}
//void Pop(Lstack *s)
//{
//	if(IsEmpty(s)) return;
//	Lstack *p=s;
//	p=s->next;
//	s->next=p->next;
//	delete p;
//}
//int GetTop(Lstack *s)
//{
//	return s->next->data;
//}
//void main()
//{
//	Lstack *st=new Lstack;
//	st->next=NULL;
//	st->data=0;
//	Push(st,1);
//	Push(st,2);
//	Push(st,3);
//	cout<<GetTop(st)<<endl;
//	Pop(st);
//	cout<<GetTop(st)<<endl;
//	Pop(st);
//	cout<<GetTop(st)<<endl;
//	Pop(st);
//	delete st;
//
//}