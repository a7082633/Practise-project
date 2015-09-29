//#include<iostream>
//using namespace std;
//struct Que
//{
//	int data[4];
//	int head;
//	int tail;
//};
//bool IsEmpty(Que *q)
//{
//	if(q->head==q->tail) return true;
//	return false;
//}
//bool IsFull(Que *q)
//{
//	if(q->tail==4) return true;
//	return false;
//}
//void In(Que *q,int v)
//{
//	if(IsFull(q)) return;
//	q->data[q->tail++]=v;
//}
//void out(Que *q)
//{
//	if(IsEmpty(q)) return;
//	q->data[q->head++]=0;
//}
//int GetHead(Que *q)
//{
//	if(IsEmpty(q)) return -1;
//	return q->data[q->head];
//}
//void main()
//{
//	Que q={0};
//	In(&q,1);
//	In(&q,2);
//	In(&q,3);
//	In(&q,4);
//	In(&q,5);
//
//	cout<<"test!!!!!!!!"<<endl;
//	cout<<GetHead(&q)<<endl;
//	out(&q);
//	cout<<GetHead(&q)<<endl;
//	out(&q);
//	cout<<GetHead(&q)<<endl;
//	out(&q);
//	cout<<GetHead(&q)<<endl;
//	out(&q);
//	cout<<GetHead(&q)<<endl;
//}