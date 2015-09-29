//#include <iostream>
//using namespace std;
//
//struct STUDENT
//{
//	int iNo;
//	char szName[8];
//	STUDENT* pNext;
//};
//
//void Show(STUDENT* p)
//{
//	STUDENT* pOld = p;
//	while (p)
//	{
//		cout << p->iNo << "\t" << p->szName << endl;
//		p = p->pNext;
//
//		if (p == pOld) break;
//	}
//}
//
//STUDENT* Create()
//{
//	STUDENT* pNew1 = new STUDENT;
//	pNew1->iNo = 101;
//	strcpy(pNew1->szName, "s1");
//	pNew1->pNext = NULL;
//
//	STUDENT* pNew2 = new STUDENT;
//	pNew2->iNo = 102;
//	strcpy(pNew2->szName, "s2");
//	pNew2->pNext = pNew1;
//
//	STUDENT* pNew3 = new STUDENT;
//	pNew3->iNo = 103;
//	strcpy(pNew3->szName, "s3");
//	pNew3->pNext = pNew2;
//
//	STUDENT* pNew4 = new STUDENT;
//	pNew4->iNo = 104;
//	strcpy(pNew4->szName, "s4");
//	pNew4->pNext = pNew3;
//
//	STUDENT* pNew5 = new STUDENT;
//	pNew5->iNo = 105;
//	strcpy(pNew5->szName, "s5");
//	pNew5->pNext = pNew4;
//
//	//pNew1->pNext = pNew5;	//单向循环链表
//	STUDENT *p=pNew5;
//	return p;
//}
//
//void Free(STUDENT* p)
//{
//	STUDENT* pOld = p;
//	while (p)
//	{
//		STUDENT* pTmp = p->pNext;
//		delete p;
//		p = pTmp;
//
//		if (p == pOld) break;
//	}
//}
//
//bool IsLoop(STUDENT *p)
//{
//	if (p == NULL) return false;
//	STUDENT *p1 = p;
//	STUDENT *p2 = p;
//
//	while (1)
//	{
//		p1 = p1->pNext;
//		if (p2->pNext == NULL) return false;
//		p2 = p2->pNext->pNext;
//
//		if (p2 == NULL) return false;
//		if (p2 == p1) return true;
//	}
//
//	return false;
//}
////void RevNode(STUDENT*&pNode)
////{
////	if (pNode == NULL || pNode->pNext == NULL) return;
////
////	STUDENT*p1 = pNode;
////	STUDENT*p2 = p1->pNext;
////	STUDENT*p3 = NULL;
////
////	if (p2->pNext == NULL)
////	{
////		p1->pNext = NULL;
////		p2->pNext = p1;
////		pNode = p2;
////		return;
////	}
////
////	p3 = p2->pNext;
////
////	p1->pNext = NULL;
////
////	while (p3 != NULL)
////	{
////		p2->pNext = p1;	//!!!!!
////
////		p1 = p2;
////		p2 = p3;
////		p3 = p2->pNext;
////	}
////	p2->pNext = p1;
////	pNode = p2;
////}
//void MyRevNode(STUDENT*&pNode)
//{
//	STUDENT *p1=pNode;
//	STUDENT *p2=pNode->pNext;
//	STUDENT *p3=p2->pNext;
//	p1->pNext=NULL;
//	while(p3)
//	{
//		p2->pNext=p1;
//		p1=p2;
//		p2=p3;
//		p3=p3->pNext;
//	}
//	p2->pNext=p1;
//	pNode=p2;
//}
//void MyHRevNode(STUDENT*&pNode)
//{
//	STUDENT *pnew=new STUDENT;
//	pnew->pNext=pNode;
//	pNode=pnew;
//	STUDENT *p=pNode->pNext;
//	pNode->pNext = NULL;
//	while(p)
//	{
//		STUDENT *t=p->pNext;
//		p->pNext=pNode->pNext;
//		pNode->pNext = p;
//		p=t;
//	}
//}
//
////头插法 反转
////void InversionNode(STUDENT* head) {
////	STUDENT p,t,q;
////	p = NULL;
////	t = head->next;
////	q = t->next;
////	if(t == NULL || q == NULL) return; // 空表和仅有一个结点的链表不用倒置
////	while(q) {
////		t->next = p; // 倒置结点
////		p = t;       // p指向新倒置的结点
////		t = q;       // 前进一个结点
////		q = q->next;
////	}
////	t->next = p;     // 处理最后一个结点
////	head->next = t;  // head指向倒置后的链表
////}
//void AddNode(STUDENT*& head)
//{
//	STUDENT *newnode=new STUDENT;
//	newnode->iNo=11;
//	newnode->pNext=NULL;
//	strcpy(newnode->szName,"haha");
//	STUDENT *p=head;
//	if(p==NULL)
//	{
//		head=newnode;
//		return;
//	}
//	while(p->pNext!=NULL)
//	{
//		p=p->pNext;
//	}
//	newnode->pNext=p->pNext;
//	p->pNext=newnode;
//}
//void DelTopNode(STUDENT*& head)
//{
//	STUDENT *p=head;
//	head=head->pNext;
//	delete p;
//}
//void main()
//{
//	STUDENT *pHead = Create();
//	//STUDENT *pHead=NULL;
//	//cout<<pHead->iNo<<endl;
//	AddNode(pHead);
//	Show(pHead);
//	DelTopNode(pHead);
//	Show(pHead);
////	MyRevNode(pHead);
////	cout<<"reverse!"<<endl;
////	Show(pHead);
//	Free(pHead);
//}
