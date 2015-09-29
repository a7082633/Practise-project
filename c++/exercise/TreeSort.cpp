//#include <iostream>
//using namespace std;
//
//#define dim(x) (sizeof(x)/sizeof(x[0]))
//struct NODE
//{
//	int data;
//	NODE *lchil;
//	NODE *rchil;
//};
//
//void MidOrder(NODE *root)
//{
//	if(root!=NULL)
//	{
//		MidOrder(root->lchil);
//		cout<<root->data<<" ";
//		MidOrder(root->rchil);
//	}
//}
//void TreeSort(int a[],int n)
//{
//	NODE *Tree= new NODE[n];
//	for(int i=0;i<n;i++)
//	{
//		Tree[i].data=0;
//		Tree[i].lchil=NULL;
//		Tree[i].rchil=NULL;
//	}
//	Tree[0].data=a[0];
//	NODE *root=&Tree[0];
//	for(i=1;i<n;i++)
//	{
//		root=&Tree[0];
//		bool bGo = true;
//		while(bGo)
//		{
//			while(bGo && a[i]<root->data)
//			{
//				if(root->lchil==NULL)
//				{
//					Tree[i].data=a[i];
//					root->lchil=&Tree[i];
//					bGo = false;
//					break;
//				}
//				root=root->lchil;
//			}
//			while(bGo && a[i]>=root->data)
//			{
//				if(root->rchil==NULL)
//				{
//					Tree[i].data=a[i];
//					root->rchil=&Tree[i];
//					bGo = false;
//					break;
//				}
//				root=root->rchil;
//			}
//		}
//	}
//	MidOrder(Tree);
//}
//
//
//void main()
//{
//	int a[] = {1,1,9,1,1,1};
//	//int a[] = {7,6,5,4,9};
//	TreeSort(a,dim(a));
//	cout<<endl;
//
//}
