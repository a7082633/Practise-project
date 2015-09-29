#include <iostream>
#include <windows.h>
#include <conio.h>
#include <list>
#include <stdio.h>
using namespace std;
#define H 15
#define L 15
int Speed=250;
bool isEat=false;
class CSbody;
#define RAND() (srand((unsigned int)GetCpuCycle()), rand())
char *wall[H][L]=	   {"©°", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©´",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¦", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "©¦",
						"©¸", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¤", "©¼",};
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}
struct SNode
{
	int No;
	int Nx;
	int Ny;
	SNode(int no=0,int x=0,int y=0):No(no),Nx(x),Ny(y){}
};

class CSbody
{
public:
	list<SNode> Snake;
	CSbody()
	{
		SNode t(1,1,2);
		Snake.push_back(t);
		t.No=0;
		t.Nx=1;
		t.Ny=1;
		Snake.push_back(t);
	}
};
void CreateFood(CSbody &s)
{
	int x,y;
	list<SNode>::iterator it;
	bool flag=false;
	while(!flag)
	{
		x=RAND()%14;
		y=RAND()%14;
		it=s.Snake.begin();
		if(wall[x][y]!="  ") continue;
		for(;it!=s.Snake.end();it++)
		{
			if((*it).Nx==x&&(*it).Ny==y)
				break;
		}
		flag=true;
	}
	if(wall[x][y]=="  ") wall[x][y]="¡î";
	isEat=true;
}
void DrawGame( CSbody &s)
{
	list<SNode>::iterator it=s.Snake.begin();
	for(;it!=s.Snake.end();it++)
	{
		if((*it).No==1)
			wall[(*it).Nx][(*it).Ny]="¡ö";
		else
			wall[(*it).Nx][(*it).Ny]="¡õ";
	}
	system("cls");
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<H;j++)
		{
			cout<<wall[i][j];
		}
		cout<<endl;
	}
	cout<<"©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´"<<endl;
	cout<<"  your score is:"<<(s.Snake.size()-2)<<endl;
	cout<<"©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼"<<endl;
	cout<<"©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´"<<endl;
	cout<<"  press space pause the game"<<endl;
	cout<<"©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼"<<endl;
}
void Move(CSbody &s,int d)
{
	list<SNode>::iterator it;
	SNode ht;
	wall[s.Snake.back().Nx][s.Snake.back().Ny]="  ";
	s.Snake.front().No=0;
	ht=s.Snake.front();
	s.Snake.back().No=1;
	switch(d)
	{
	case 1:
		s.Snake.back().Nx=--ht.Nx;
		s.Snake.back().Ny=ht.Ny;
		break;
	case 2:
		s.Snake.back().Nx=++ht.Nx;
		s.Snake.back().Ny=ht.Ny;
		break;
	case 3:
		s.Snake.back().Nx=ht.Nx;
		s.Snake.back().Ny=--ht.Ny;
		break;
	case 4:
		s.Snake.back().Nx=ht.Nx;
		s.Snake.back().Ny=++ht.Ny;
		break;
	default:
		return;
		break;
	}
	it=s.Snake.begin();
	s.Snake.insert(it,s.Snake.back());
	it=s.Snake.end();
	s.Snake.erase(--it);
}
int JudgeDrec(char m,const int &dire)
{
	switch(m)
	{
	case 75:
		return 3;
	case 77:
		return 4;
	case 80:
		return 2;
	case 72:
		return 1;
	default:
		return dire;
	}
}
bool isFood(CSbody &s,int d)
{
	switch(d)
	{
	case 1:
		if(wall[s.Snake.front().Nx-1][s.Snake.front().Ny]=="¡î")
		{
			s.Snake.front().No=0;
			SNode t(1,s.Snake.front().Nx-1,s.Snake.front().Ny);
			s.Snake.push_front(t);
			isEat=false;
			//Speed-=500;
			return true;
		}
		return false;
	case 2:
		if(wall[s.Snake.front().Nx+1][s.Snake.front().Ny]=="¡î")
		{
			s.Snake.front().No=0;
			SNode t(1,s.Snake.front().Nx+1,s.Snake.front().Ny);
			s.Snake.push_front(t);
			isEat=false;
			//Speed-=500;
			return true;
		}
		return false;
	case 3:
		if(wall[s.Snake.front().Nx][s.Snake.front().Ny-1]=="¡î")
		{
			s.Snake.front().No=0;
			SNode t(1,s.Snake.front().Nx,s.Snake.front().Ny-1);
			s.Snake.push_front(t);
			isEat=false;
			//Speed-=500;
			return true;
		}
		return false;
	case 4:
		if(wall[s.Snake.front().Nx][s.Snake.front().Ny+1]=="¡î")
		{
			s.Snake.front().No=0;
			SNode t(1,s.Snake.front().Nx,s.Snake.front().Ny+1);
			s.Snake.push_front(t);
			isEat=false;
//			Speed-=500;
			return true;
		}
		return false;
	default:
		return false;
	}
}
void main()
{
	CSbody Snake;
	Snake.Snake.clear()
	DrawGame(Snake);
	int dire=4;
	char m;
	while(1)
	{
		while(!kbhit())
		{
			if(!isEat) CreateFood(Snake);
			if(!isFood(Snake,dire)) Move(Snake,dire);
			if(Snake.Snake.front().Nx+1>14||Snake.Snake.front().Nx-1<0||Snake.Snake.front().Ny+1>14||Snake.Snake.front().Ny-1<0)
				system("pause");
			DrawGame(Snake);
			Sleep(Speed);
		}
		m=getch();
		m=getch();
		dire=JudgeDrec(m,dire);
	}
	system("pause");
}
