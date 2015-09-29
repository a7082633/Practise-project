//#include <stdio.h>
//#include <memory.h>
//#include <string.h>
//#include <iostream>
//using namespace std;
//#define dim(x) sizeof(x) / sizeof(x[0])
//struct NODE
//{
//	char iData;
//	NODE* pChild[5];
//};
//struct SqStack
//{
//	char c[9];
//	NODE *p[9];
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
//void Push(SqStack *s,NODE *p)
//{
//	if(IsFull(s)) return;
//	s->p[s->top]=p;
//	s->top++;
//}
//void Pop(SqStack *s)
//{
//	if(IsEmpty(s)) return;
//	cout<<s->p[--s->top]->iData<<" ";
//	//s->c[--s->top]=0;;
//}
//char Top(SqStack *s)
//{
//	if(IsEmpty(s)) return -1;
//	return s->c[s->top-1];
//}
//
///******************************************************************
//                A
//              *   *
//            B       C
//          *  *    *  *
//        D      E F	   G
//     *  *  *
//   H    I   J
//
//设树T的根为n, 其子树从左到右依次为T1,T2,..,Tk, 那么有:
//前序遍历: 先访问树根n,然后依次前序遍历T1, T2, .., Tk
//中序遍历: 先中序遍历T1, 然后访问树根n，接着依次对T2, T3, .., Tk进行中序遍历
//后序遍历: 先依次对T1, T2, .., Tk进行后序遍历, 最后访问树根n
//******************************************************************/
//void PreOrder(NODE *root)
//{
//	if(root!=NULL)
//		cout<<root->iData<<" ";
//	else
//		return;
//	PreOrder(root->pChild[0]);
//	PreOrder(root->pChild[1]);
//	PreOrder(root->pChild[2]);
//	PreOrder(root->pChild[3]);
//	PreOrder(root->pChild[4]);
//
//}
//void MidOrder(NODE *root)
//{
//	if(root!=NULL)
//	{
//		MidOrder(root->pChild[0]);
//		cout<<root->iData<<" ";
//		MidOrder(root->pChild[1]);
//		MidOrder(root->pChild[2]);
//		MidOrder(root->pChild[3]);
//		MidOrder(root->pChild[4]);
//	}
//
//}
//void PostOrder(NODE *root)
//{
//	if(root!=NULL)
//	{
//		PostOrder(root->pChild[0]);
//		PostOrder(root->pChild[1]);
//		PostOrder(root->pChild[2]);
//		PostOrder(root->pChild[3]);
//		PostOrder(root->pChild[4]);	
//		cout<<root->iData<<" ";
//	}
//
//}
//
//int GetTreeNumOfN(NODE *root)
//{
//	if(root==NULL) return 0;
//	return GetTreeNumOfN(root->pChild[0])+
//		GetTreeNumOfN(root->pChild[1])+
//		GetTreeNumOfN(root->pChild[2])+
//		GetTreeNumOfN(root->pChild[3])+
//		GetTreeNumOfN(root->pChild[4])+1;
//}
//
//int GetTreeDepth(NODE *root)
//{
//	if(root==NULL) return 0;
//	int a=GetTreeDepth(root->pChild[0]);
//	int b=GetTreeDepth(root->pChild[1]);
//	int c=GetTreeDepth(root->pChild[2]);
//	int d=GetTreeDepth(root->pChild[3]);
//	int e=GetTreeDepth(root->pChild[4]);
//	a=a>b?a:b;
//	a=a>c?a:c;
//	a=a>d?a:d;
//	a=a>e?a:e;
//	return a+1;
//
//}
//
//void StackOrder(NODE *root,SqStack *sta)
//{
//	if(root==NULL) return;
//	Push(sta,root);
//	while(root||sta->top)
//	{
//		if(root->pChild[0]!=NULL)
//		{
//			Push(sta,root->pChild[0]);
//			root=root->pChild[0];
//		}
//		else if(root->pChild[1]!=NULL)
//		{
//			Push(sta,root->pChild[1]);
//			root=root->pChild[1];
//		}
//		else if(root->pChild[2]!=NULL)
//		{
//			Push(sta,root->pChild[2]);
//			root=root->pChild[2];
//		}
//		else if(root->pChild[3]!=NULL)
//		{
//			Push(sta,root->pChild[3]);
//			root=root->pChild[3];
//		}
//		else// if(root->pChild[4]!=NULL)
//		{
//			root=sta->p[sta->top];
//			Pop(sta);
//			root=root->pChild[4];
////			Push(sta,root->pChild[4]);
////			root=root->pChild[4];
//		}
//	}
//	
//}
//
//void main()
//{
//	//1. 产生树tree, 其根为root
//	//tree[]       t0    t1 
//	char data[] = {'A',  'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
//	char pid[]  = {NULL, 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'D'};
//	NODE* root = NULL;
//	NODE* tree[10];
//	SqStack sta={0};
//	//2. 创建10个子节点本身
//	for (int i = 0; i < dim(data); i++)
//	{
//		tree[i] = new NODE;
//		memset(tree[i], 0, sizeof(NODE));
//		tree[i]->iData = data[i];
//	}
////	for(i=0;i<dim(data),i++)
////	{
////		if(pid[i]==NULL)
////		{
////			root=data[i];
////		}
////		tree[i]->pChild[k]=tree[i];
////		tree[0]->pChild[k] = tree[i];
////	}
//	//3. 建立10个子节点之间的关系
//	for (i = 0; i < dim(data); i++)
//	{
//		if (pid[i] == NULL)
//		{
//			root = tree[i];
//			continue;
//		}
//		//tree[0]->pChild[k] = tree[i];
//		for (int j = 0; j < dim(data); j++)
//		{
//			if (pid[i] == data[j])
//			{
//				for (int k = 0; k < 5; k++)
//				{
//					if (tree[j]->pChild[k] == NULL)
//					{
//						tree[j]->pChild[k] = tree[i];
//						break;
//					}
//				}
//				break;
//			}
//		}
//	}
//	PreOrder(root);
//	cout<<endl;
//	MidOrder(root);
//	cout<<endl;
//	PostOrder(root);
//	cout<<endl;
//	cout<<GetTreeNumOfN(root)<<endl;
//	cout<<GetTreeDepth(root)<<endl;
//	StackOrder(root,&sta);
//
//
//}
