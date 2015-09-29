//#include <iostream>
//using namespace std;
//struct QNode
//{
//	int data;
//	QNode *next;
//};
//bool IsEmpty(QNode *f,QNode *t)
//{
//	if(f==t) return true;
//	return false;
//}
//void push(QNode *f,QNode *&t,QNode *q,int v)
//{
//	QNode *pnew=new QNode;
//	pnew->next=NULL;
//	pnew->data=v;
//	t->next=pnew;
//	t=t->next;
//}
//void pop(QNode *&f,QNode *&t,QNode *q)
//{
//	if(IsEmpty(f,t)) return;
//	q=q->next;
//	if(q==t) t=f;
//	f->next=q->next;
//	delete q;
//}
//int GetTop(QNode *f,QNode *t,QNode *q)
//{
//	if(IsEmpty(f,t)) return -1;
//	return f->next->data;
//}
//int GetTail(QNode *f,QNode *t)
//{
//	if(IsEmpty(f,t)) return -1;
//	return t->data;
//}
//void main()
//{
//	QNode *q=new QNode;
//	QNode *f=q;
//	QNode *t=q;
//	q->next=NULL;
//
//	push(f,t,q,1);
//	push(f,t,q,2);
//	push(f,t,q,3);
//	cout<<"my tail!"<<endl;
//	cout<<GetTail(f,t)<<endl;
//	cout<<GetTop(f,t,q)<<endl;
//	pop(f,t,q);
//	cout<<GetTop(f,t,q)<<endl;
//	pop(f,t,q);
//	cout<<GetTop(f,t,q)<<endl;
//	pop(f,t,q);
//	cout<<GetTop(f,t,q)<<endl;
//	pop(f,t,q);
//}