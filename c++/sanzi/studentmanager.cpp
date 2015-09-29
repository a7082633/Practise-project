//#include <stdio.h>
//#include <iostream>
//#include <conio.h>
//#include <stdlib.h>
//using namespace std;
//struct strStudent
//{
//	int SID;
//	char SName[10];
//	float fScore;
//    struct strStudent* pStudent;
//};
//struct SNODE{
//	struct strStudent stu;
//	SNODE *next;
//};
//void Show(SNODE* p)
//{
//	if(p==NULL||p->next==NULL) return;
//	SNODE* pOld = p;
//	p=p->next;
//	cout<<"===================="<<endl;
//	cout<<"学号    姓名    分数"<<endl;
//	cout<<"===================="<<endl;
//	while (p)
//	{
//		cout << p->stu.SID<<"\t"<< p->stu.SName<< "\t" << p->stu.fScore<<endl;
//		p = p->next;
//		if (p == pOld) break;
//	}
//	cout<<"===================="<<endl;
//}
//void addNode(SNODE *p,strStudent stu)
//{
//	SNODE *pnew=new SNODE;
//	pnew->next=NULL;
//	SNODE *q=p;
//	pnew->stu=stu;
//	if(p==NULL) return;
//	if(p->next==NULL)
//	{
//		p->next=pnew;
//		return;
//	}
//	p=p->next;
//	while(p)
//	{
//		if(p->stu.SID>stu.SID)
//		{
//			q->next=pnew;
//			pnew->next=p;
//			return;
//		}
//		q=q->next;
//		p=p->next;
//	}
//	q->next=pnew;
//}
//void addToHead(SNODE *p)
//{
//	SNODE *pnew=new SNODE;
//	strStudent stu;
//	do
//	{
//		cin.clear();
//		cin.sync();
//		cout <<"plz input id:";
//		cin>>stu.SID;
//	}while(cin.fail());
//	do
//	{
//		cin.clear();
//		cin.sync();
//		cout <<"plz input name:";
//		cin>>stu.SName;
//	}while(cin.fail());
//	do
//	{
//		cin.clear();
//		cin.sync();
//		cout <<"plz input score:";
//		cin>>stu.fScore;
//	}while(cin.fail()||stu.fScore<0||stu.fScore>100);
//	pnew->stu=stu;
//	pnew->next=NULL;
//	if(p->next==NULL)
//	{
//		p->next=pnew;
//	}else
//	{
//		SNODE *t=p->next;
//		p->next=pnew;
//		pnew->next=t;
//	}
//}
//void update(SNODE *p,int iNo)
//{
//	strStudent stu;
//	while(p)
//	{
//		if(p->stu.SID==iNo)
//		{
//			char c=1;
//			char str[20]={0};
//			sprintf(str,"%d",p->stu.SID);
//			int i=strlen(str);
//			cout <<"plz input id:"<<p->stu.SID;
//			while(c=getch())
//			{
//				if(c==13&&strlen(str)!=0)
//				{
//					cout<<endl;
//					break;
//				}
//				if(c>=48&&c<=57&&i>=0&&i<5)
//				{
//					putchar(c);
//					str[i++]=c;
//				}
//				if(c==8&&i>0)
//				{
//					printf("\b \b");
//					if(i>0) str[--i]=0;
//				}
//			}
//			stu.SID=atoi(str);
//			////////////////////////////////////////////////
//			c=1;
//			memset(str,0,20);
//			strcpy(str,p->stu.SName);
//			i=strlen(str);
//			cout <<"plz input name:"<<p->stu.SName;
//			while(c=getch())
//			{
//				if(c==13&&strlen(str)!=0)
//				{
//					cout<<endl;
//					break;
//				}
//				if(c>=65&&c<=90&&i>=0&&i<5)
//				{
//					putchar(c);
//					str[i++]=c;
//				}
//				if(c>=97&&c<=122&&i>=0&&i<5)
//				{
//					putchar(c);
//					str[i++]=c;
//				}
//				if(c==8&&i>0)
//				{
//					printf("\b \b");
//					if(i>0) str[--i]=0;
//				}
//			}
//			strcpy(stu.SName,str);
//			////////////////////////////////////////////////
//			c=1;
//			memset(str,0,20);
//			sprintf(str,"%d",(int)p->stu.fScore);
//			i=strlen(str);
//			cout <<"plz input score:"<<p->stu.fScore;
//			while(c=getch())
//			{
//				if(c==13&&strlen(str)!=0)
//				{
//					cout<<endl;
//					break;
//				}
//				if(c>=48&&c<=57&&i>=0&&i<2)
//				{
//					putchar(c);
//					str[i++]=c;
//				}
//				if(c==8&&i>0)
//				{
//					printf("\b \b");
//					if(i>0) str[--i]=0;
//				}
//			}
//			stu.fScore=(float)atoi(str);
//			p->stu=stu;
//			return;
//		}
//		p=p->next;
//	}
//	cout <<"cant find this student!"<<endl;
//}
//void deleteN(SNODE *p)
//{
//	if(p==NULL||p->next==NULL)
//	{
//		cout <<"The LinkList is empty!"<<endl;
//		return;
//	}
//	int iNo=-1;
//	do
//	{
//		cout <<"plz input the no u want del(id):";
//		cin.sync();
//		cin.clear();
//		cin>>iNo;
//	}while(iNo<0||cin.fail());
//	SNODE *p1=p;
//	p=p->next;
//	while(p)
//	{
//		if(p->stu.SID==iNo&&p->next!=NULL)
//		{
//			cout <<"this is the student u delete:";
//		    cout<<"===================="<<endl;
//			cout<<"学号    姓名    分数"<<endl;
//		    cout<<"===================="<<endl;
//			cout << p->stu.SID<<"\t"<< p->stu.SName<< "\t" << p->stu.fScore<<endl;
//			p1->next=p->next;
//			free(p);
//			return;
//		}
//		if(p->stu.SID==iNo&&p->next==NULL)
//		{
//			cout <<"this is the student u delete:"<<endl;
//			cout<<"===================="<<endl;
//			cout<<"学号    姓名    分数"<<endl;
//		    cout<<"===================="<<endl;
//			cout << p->stu.SID<<"\t"<< p->stu.SName<< "\t" << p->stu.fScore<<endl;
//			SNODE *t=p;
//			free(t);
//			p1->next=NULL;
//			return;
//		}
//		p1=p1->next;
//		p=p->next;
//	}
//	cout <<"cant find this student!"<<endl;
//}
//void FindS(SNODE *p,int iNo)
//{
//	p=p->next;
//	while(p)
//	{
//		if(p->stu.SID==iNo)
//		{
//			cout<<"学号    姓名    分数"<<endl;
//			cout<<"===================="<<endl;
//			cout << p->stu.SID<<"\t"<< p->stu.SName<< "\t" << p->stu.fScore<<endl;
//			break;
//		}
//		p=p->next;
//	}
//}
//void Free(SNODE* p)
//{
//	SNODE*  pOld = p;
//	while (p)
//	{
//		SNODE*  pTmp = p->next;
//		delete p;
//		p = pTmp;
//		if (p == pOld) break;
//	}
//}
//void sortLink(SNODE *Head)
//{
//	SNODE *unsort,*sorted,*p,*q,*m;
//	if(Head==NULL||Head->next==NULL)
//		return;
//	Head=Head->next;
//	if(Head==NULL)
//		return;
//	unsort=Head->next;
//	sorted=Head;
//	while(unsort)
//	{
//		p=sorted;
//		q=unsort;
//		m=p;
//		while(q)
//		{
//			if(p->stu.SID>q->stu.SID)
//				m=q;
//			q=q->next;
//		}
//		strStudent temp=p->stu;
//		p->stu=m->stu;
//		m->stu=temp;
//		sorted=sorted->next;
//		unsort=unsort->next;
//	}
//}
//void MySave(SNODE *Head)
//{
//	FILE *fp=fopen("db.dat","rb+");
//	fp = fopen("db.dat","w");  
//	if(fp==NULL)     
//		return;  
//	fclose(fp); 
//	fp=fopen("db.dat","rb+");
//	if(fp==NULL)
//	{
//		fp=fopen("db.dat","wb+");
//		if(fp==NULL)
//		{
//			cout<<"cant open the file"<<endl;
//			return;
//		}
//	}
//	Head=Head->next;
//	while(Head)
//	{
//		fwrite(&Head->stu,sizeof(strStudent),1,fp);
//		//fseek(fp,0,SEEK_END);
//		Head=Head->next;
//	}
//	fclose(fp);
//}
//void MyRead(SNODE *Head)
//{
//	FILE *fp=fopen("db.dat","rb+");
//	if(fp==NULL)
//	{
//		fp=fopen("db.dat","wb+");
//		if(fp==NULL)
//		{
//			cout<<"cant open the file"<<endl;
//			return;
//		}
//	}
//	strStudent tstu;
//	while(fread(&tstu,sizeof(strStudent),1,fp))
//	{
//		addNode(Head,tstu);
//	}
//	fclose(fp);
//}
//int  ShowMenu()
//{
//	system("cls");
//	cout<<"==============学生信息管理系统=============="<<endl;
//	cout<<"              1.增加学生信息                "<<endl;
//	cout<<"              2.删除学生信息                "<<endl;
//	cout<<"              3.修改学生信息                "<<endl;
//	cout<<"              4.查询学生信息                "<<endl;
//	cout<<"              5.遍历学生信息                "<<endl;
//	cout<<"              6.排序                        "<<endl;
//	cout<<"              0.退出                        "<<endl;
//	cout<<"============================================"<<endl;
//	int nChoose=-1;
//	do
//	{
//		cout<<"请选择:";
//		cin.sync();
//		cin.clear();
//		cin>>nChoose;
//	}while(nChoose<0||nChoose>6);
//	return nChoose;
//}
//void main()
//{
//	SNODE *Head=new SNODE;
//	Head->next=NULL;
//	strStudent stu;
//	int iNo=-1;
//	MyRead(Head);
//	while(1)
//	{
//		cin.clear();
//		switch(ShowMenu())
//		{
//		case 0:
//			 MySave(Head);
//			 exit(0);
//			 break;
//		case 1:
//			do
//			{
//				cin.clear();
//				cin.sync();
//				cout <<"plz input id:";
//				cin>>stu.SID;
//			}while(cin.fail());
//			do
//			{
//				cin.clear();
//				cin.sync();
//				cout <<"plz input name:";
//				cin>>stu.SName;
//			}while(cin.fail());
//			do
//			{
//				cin.clear();
//				cin.sync();
//				cout <<"plz input score:";
//				cin>>stu.fScore;
//			}while(cin.fail()||stu.fScore<0||stu.fScore>100);
//			addNode(Head,stu);
//			system("pause");
//			break;
//		case 2:
//			Show(Head);
//			deleteN(Head);
//			system("pause");
//			break;
//		case 3:
//			Show(Head);
//			iNo=-1;
//			do
//			{
//				cin.sync();
//				cin.clear();
//				cout<<"plz input the no u want modify:";
//				cin>>iNo;
//			}while(iNo<0);
//			update(Head,iNo);
//			cout<<"                    "<<endl;
//			cout<<"=====after modify==="<<endl;
//			Show(Head);
//			system("pause");
//			break;
//		case 4:
//			iNo=-1;
//			do
//			{
//				cin.sync();
//				cin.clear();
//				cout<<"plz input the no that u want show:";
//				cin>>iNo;
//			}while(iNo<0||cin.fail());
//			FindS(Head,iNo);
//			system("pause");
//			break;
//		case 5:
//			Show(Head);
//			system("pause");
//			break;
//		case 6:
//			sortLink(Head);
//			Show(Head);
//			system("pause");
//			break;
//		default:
//			break;
//		}
//	}
//	free(Head);
//	cout<<"yes!"<<endl;
//}