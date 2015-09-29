#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

char *chess[3][3]={
		"  ","  ","  ",
		"  ","  ","  ",
		"  ","  ","  ",
};

void ShowChess()
{
	system("cls");
	printf("  ┌───────────┐\r\n");
	printf("  │****   XO三子棋   ****│\r\n");
	printf("  └───────────┘\r\n");
	printf("      1       2       3     \r\n");
	printf("  ┌───┬───┬───┐\r\n");
	printf("  │      │      │      │\r\n");
	printf(" 1│  %s  │  %s  │  %s  │\r\n", chess[0][0], chess[0][1], chess[0][2]);
	printf("  │      │      │      │\r\n");
	printf("  ├───┼───┼───┤\r\n");
	printf("  │      │      │      │\r\n");
	printf(" 2│  %s  │  %s  │  %s  │\r\n", chess[1][0], chess[1][1], chess[1][2]);
	printf("  │      │      │      │\r\n");
	printf("  ├───┼───┼───┤\r\n");
	printf("  │      │      │      │\r\n");
	printf(" 3│  %s  │  %s  │  %s  │\r\n", chess[2][0], chess[2][1], chess[2][2]);
	printf("  │      │      │      │\r\n");
	printf("  └───┴───┴───┘\r\n");
}

char *Check()
{
	int i, j;
	for(i = 0;i < 3; i++)
	{
		if(chess[i][0] == chess[i][1]&&chess[i][0] == chess[i][2]) return chess[i][0];
	}
	for(i = 0;i < 3;i++)
	{
		if(chess[0][i] == chess[1][i]&&chess[0][i] == chess[2][i]) return chess[0][i];
	}
	if(chess[0][0] == chess[1][1]&&chess[0][0] == chess[2][2]) return chess[1][1];
	if(chess[2][0] == chess[1][1]&&chess[2][0] == chess[0][2]) return chess[1][1];

	bool bDone=true;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(chess[i][j] == "  ")
			{
				bDone=false;
				break;
			}
		}
	}

	return bDone ? "平了" :"  ";
}

void Move(char * sWho)
{
	int x, y, m;
	while (1)
	{
		fflush(stdin);
		clearerr(stdin);
		x = -1, y = -1, m = -1;

		printf("请%s方输入落子坐标(00退出): ",sWho);
		scanf("%d", &m);
		if(m == 0) exit(0);

		x = m / 10;
		y = m - 10 * x;

		if (chess[x-1][y-1] != "  ") continue;
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) break;
	}
	x--; y--;
	chess[x][y] = sWho;

	char *done = Check();
	if (done == "平了")
	{
		ShowChess();
		printf("平了\n");
		exit(0);
	}
	else if (done !="  ")
	{
		ShowChess();
		printf("%s赢了\n", done);
		exit(0);
	}
}

void main()
{
//	while (1)
//	{
//		ShowChess();
//		Move("ｘ");
//
//		ShowChess();
//		Move("ｏ");
//	}
//	system("pause");
	int a = 4;
	(++a)+=(a++);
	cout << a;
}