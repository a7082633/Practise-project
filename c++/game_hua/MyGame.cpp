#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 3
int fram[SIZE][SIZE]={1,2,3,4,5,6,7,8,0};
char *f[SIZE][SIZE]={0};
#define RAND() (srand((unsigned int)GetCpuCycle()), rand())
//获得CPU自上电以来的时间周期数
__declspec (naked) unsigned __int64 GetCpuCycle()
{
	_asm
	{
		rdtsc
		ret
	}
}
void mix_fram()
{
	for(int i=0;i<200;i++)
	{
		for(int j=0;j<SIZE;j++)
			for(int k=0;k<SIZE;k++)
			{
				if(fram[j][k]==0&&RAND()%4==0&&(j+1)<SIZE)//下
				{
					fram[j][k]=fram[j+1][k];
					fram[j+1][k]=0;
					//goto aa;
					break;
				}
				if(fram[j][k]==0&&RAND()%4==1&&(k+1)<SIZE)//右
				{
					fram[j][k]=fram[j][k+1];
					fram[j][k+1]=0;
					//goto aa;
					//break;
				}
				if(fram[j][k]==0&&RAND()%4==2&&(k-1)>0)
				{
					fram[j][k]=fram[j][k-1];
					fram[j][k-1]=0;
					//goto aa;
					break;
				}
				if(fram[j][k]==0&&RAND()%4==3&&(j-1)>0)
				{
					fram[j][k]=fram[j-1][k];
					fram[j-1][k]=0;
					//goto aa;
					break;
				}
			}
		i++;
	}
}
void move(char ch)
{
	for(int j=0;j<SIZE;j++)
		for(int k=0;k<SIZE;k++)
		{
			if(ch==75&&fram[j][k]==0&&(k-1)>=0)
			{
				fram[j][k]=fram[j][k-1];
				fram[j][k-1]=0;
				return;
			}
			if(ch==77&&fram[j][k]==0&&(k+1)<SIZE)
			{
				fram[j][k]=fram[j][k+1];
				fram[j][k+1]=0;
				return;
			}
			if(ch==80&&fram[j][k]==0&&(j+1)<SIZE)
			{
				fram[j][k]=fram[j+1][k];
				fram[j+1][k]=0;
				return;
			}
			if(ch==72&&fram[j][k]==0&&(j-1)>=0)
			{
				fram[j][k]=fram[j-1][k];
				fram[j-1][k]=0;
				return;
			}
		}
}
bool IsWin()
{
	int i=1;
	bool flag=false;
	for(int j=0;j<SIZE;j++)
		for(int k=0;k<SIZE;k++)
		{
			if(i==9) return flag;
			if(fram[j][k]==i)
			{
				flag=true;
			}
			else
			{
				return false;
			}
			i++;
		}
	return flag;
}
void PrintFram()
{
	system("cls");
	printf("  ┌───┬───┬───┐\r\n");
	printf("  │      │      │      │\r\n");
	printf("  │  %d   │  %d   │  %d   │\r\n", fram[0][0], fram[0][1], fram[0][2]);
	printf("  │      │      │      │\r\n");
	printf("  ├───┼───┼───┤\r\n");
	printf("  │      │      │      │\r\n");
	printf("  │  %d   │  %d   │  %d   │\r\n", fram[1][0], fram[1][1], fram[1][2]);
	printf("  │      │      │      │\r\n");
	printf("  ├───┼───┼───┤\r\n");
	printf("  │      │      │      │\r\n");
	printf("  │  %d   │  %d   │  %d   │\r\n", fram[2][0], fram[2][1], fram[2][2]);
	printf("  │      │      │      │\r\n");
	printf("  └───┴───┴───┘\r\n");
	printf("      说明 : 0代表空块\n\n");
	printf("      ←: 左  →: 右\n");
	printf("      ↑: 上  ↓: 下\n");
	printf("      0 : 退出\n\n");
}
void main()
{
	mix_fram();
	PrintFram();
	char c=0;
	while(c=getch())
	{
		switch(c)
		{
			case 48:
				exit(0);
			case 75://左
				move(75);
				PrintFram();
				if(IsWin())
				{
					printf("you win!");
					exit(0);
				}
				break;
			case 77://右
				move(77);
				PrintFram();
				if(IsWin())
				{
					printf("you win!");
					exit(0);
				}
				break;
			case 80://下
				move(80);
				PrintFram();
				if(IsWin())
				{
					printf("you win!");
					exit(0);
				}
				break;
			case 72://上
				move(72);
				PrintFram();
				if(IsWin())
				{
					printf("you win!");
					exit(0);
				}
				break;
		}
	}
}