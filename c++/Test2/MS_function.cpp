
#include "MS_function.h"
#include "stdafx.h"
#include <stdlib.h>
//ÂÝÐý¾ØÕóº¯Êý
/*
1   2  3 4
10 11 12 5
 9  8  7 6
*/
void Get_Rectangle(int n)
{
	int j=0;
	int k=0;
	int i=1;
	char a[100][100]={0};
	a[0][0]=1;
	i=2;
	while(i<=(n*n))
	{
		while(a[j][k+1]==0&&(k+1)<n) 
			a[j][++k]=i++;
		while(a[j+1][k]==0&&(j+1)<n) 
			a[++j][k]=i++;
		while(a[j][k-1]==0&&(k-1)>=0) 
			a[j][--k]=i++;
		while(a[j-1][k]==0&&(j-1)>=0) 
			a[--j][k]=i++;
	}
	for(j=0;j<n;j++)
	{
		for(k=0;k<n;k++)
		{
			printf("%3d",a[j][k]);
		}
		printf("\r\n");
	}
	system("pause");
}
//µÝ¹é1+2+3+n
int digui1(int n)
{
	if(n==1)
		return 1;
	return n+digui1(n-1);
}
//µÝ¹é1*2*3*n
int digui2(int n)
{
	if(n==1)
		return 1;
	return n*digui2(n-1);
}
//ì³²¨ÄÇÆõ
int digui3(int n)
{
	if(n<=1)
		return 1;
	return digui3(n-1)+digui3(n-2);
}
void digui4(char *p,char *q)
{
	if(*p!=*q)
	{
		printf("no");
		return;
	}
	if(p>=q && *p==*q)
	{
		printf("yes");
		return;
	}
	digui4(p+1,q-1);
}
//Á´±í»ù±¾²Ù×÷
struct Node
{
	int Data;
	Node *next;
};
void AddToTail(Node *&head,int e)
{
	if(head==NULL)
	{
		head=(Node *)malloc(sizeof(Node));
		head->Data=e;
		head->next=NULL;
		return;
	}
	Node *p=head;
	while(p->next)
		p=p->next;
	Node *pNew=(Node *)malloc(sizeof(Node));
	pNew->Data=e;
	pNew->next=NULL;
	p->next=pNew;
	return;
}
void PrintList(Node *head)
{
	if(head==NULL)
	{
		return;
	}
	Node *p=head;
	while(p)
	{
		printf("%d\n",p->Data);
		p=p->next;
	}
	return;
}
void RecursionPrintList(Node *head)
{
	if(head==NULL)
		return;
	printf("%d\n",head->Data);
	RecursionPrintList(head->next);
	return;
}
void DeleteNode(Node *&head,int e)
{
	if(head==NULL)
		return;
	Node *temp=NULL;
	if(head->Data==e)
	{
		temp=head;
		head=head->next;
		free(temp);
		return;
	}
	Node *p=head;
	Node *q=head->next;
	while(q)
	{
		if(q->Data==e)
		{
			temp=q;
			p->next=q->next;
			free(temp);
			return;
		}
		p=p->next;
		q=q->next;
	}
	return;
}
void ReverseList(Node *&head)
{
	if(head==NULL||head->next==NULL)
		return;
	Node *p1=head;
	Node *p2=p1->next;
	Node *p3=p2->next;
	head->next=NULL;
	while(p2->next)
	{
		p2->next=p1;
		p1=p2;
		p2=p3;
		p3=p3->next;//
	}
	p2->next=p1;
	head=p2;
	return;
}