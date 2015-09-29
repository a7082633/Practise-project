//#include <stdio.h>
//#include <stdlib.h>
//
//char *chess[15][15] = {
//	"┌", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┬", "┐",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "·", "┼", "┼", "┼", "·", "┼", "┼", "┼", "·", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "·", "┼", "┼", "┼", "·", "┼", "┼", "┼", "·", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "·", "┼", "┼", "┼", "·", "┼", "┼", "┼", "·", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"├", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┼", "┤",
//	"└", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┴", "┘",
//};
//void ShowChess()
//{
//	system("cls");
//	printf("  ┌───────────────────────────┐\r\n");
//	printf("  │**** **** ****        五  子  棋       **** ****  ****│\r\n");
//	printf("  └───────────────────────────┘\r\n");
//	printf("   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\r\n");
//	printf(" 1%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[0][0], chess[0][1], chess[0][2], chess[0][3], chess[0][4], chess[0][5], chess[0][6], chess[0][7], chess[0][8], chess[0][9], chess[0][10], chess[0][11], chess[0][12], chess[0][13], chess[0][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 2%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[1][0], chess[1][1], chess[1][2], chess[1][3], chess[1][4], chess[1][5], chess[1][6], chess[1][7], chess[1][8], chess[1][9], chess[1][10], chess[1][11], chess[1][12], chess[1][13], chess[1][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 3%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[2][0], chess[2][1], chess[2][2], chess[2][3], chess[2][4], chess[2][5], chess[2][6], chess[2][7], chess[2][8], chess[2][9], chess[2][10], chess[2][11], chess[2][12], chess[2][13], chess[2][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 4%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[3][0], chess[3][1], chess[3][2], chess[3][3], chess[3][4], chess[3][5], chess[3][6], chess[3][7], chess[3][8], chess[3][9], chess[3][10], chess[3][11], chess[3][12], chess[3][13], chess[3][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 5%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[4][0], chess[4][1], chess[4][2], chess[4][3], chess[4][4], chess[4][5], chess[4][6], chess[4][7], chess[4][8], chess[4][9], chess[4][10], chess[4][11], chess[4][12], chess[4][13], chess[4][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 6%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[5][0], chess[5][1], chess[5][2], chess[5][3], chess[5][4], chess[5][5], chess[5][6], chess[5][7], chess[5][8], chess[5][9], chess[5][10], chess[5][11], chess[5][12], chess[5][13], chess[5][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 7%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[6][0], chess[6][1], chess[6][2], chess[6][3], chess[6][4], chess[6][5], chess[6][6], chess[6][7], chess[6][8], chess[6][9], chess[6][10], chess[6][11], chess[6][12], chess[6][13], chess[6][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 8%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[7][0], chess[7][1], chess[7][2], chess[7][3], chess[7][4], chess[7][5], chess[7][6], chess[7][7], chess[7][8], chess[7][9], chess[7][10], chess[7][11], chess[7][12], chess[7][13], chess[7][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf(" 9%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[8][0], chess[8][1], chess[8][2], chess[8][3], chess[8][4], chess[8][5], chess[8][6], chess[8][7], chess[8][8], chess[8][9], chess[8][10], chess[8][11], chess[8][12], chess[8][13], chess[8][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf("10%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[9][0], chess[9][1], chess[9][2], chess[9][3], chess[9][4], chess[9][5], chess[9][6], chess[9][7], chess[9][8], chess[9][9], chess[9][10], chess[9][11], chess[9][12], chess[9][13], chess[9][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf("11%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[10][0], chess[10][1], chess[10][2], chess[10][3], chess[10][4], chess[10][5], chess[10][6], chess[10][7], chess[10][8], chess[10][9], chess[10][10], chess[10][11], chess[10][12], chess[10][13], chess[10][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf("12%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[11][0], chess[11][1], chess[11][2], chess[11][3], chess[11][4], chess[11][5], chess[11][6], chess[11][7], chess[11][8], chess[11][9], chess[11][10], chess[11][11], chess[11][12], chess[11][13], chess[11][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf("13%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[12][0], chess[12][1], chess[12][2], chess[12][3], chess[12][4], chess[12][5], chess[12][6], chess[12][7], chess[12][8], chess[12][9], chess[12][10], chess[12][11], chess[12][12], chess[12][13], chess[12][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf("14%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[13][0], chess[13][1], chess[13][2], chess[13][3], chess[13][4], chess[13][5], chess[13][6], chess[13][7], chess[13][8], chess[13][9], chess[13][10], chess[13][11], chess[13][12], chess[13][13], chess[13][14]);
//	printf("  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │\r\n");
//	printf("15%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s─%s\r\n", chess[14][0], chess[14][1], chess[14][2], chess[14][3], chess[14][4], chess[14][5], chess[14][6], chess[14][7], chess[14][8], chess[14][9], chess[14][10], chess[14][11], chess[14][12], chess[14][13], chess[14][14]);
//	printf("   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\r\n");
//	printf("\r\n");
//}
//void Check(int x,int y)
//{
//	int count=0;
//	int px=x,py=y;
//	while(py-1>=0)//左横向
//	{
//		if(chess[x][y]==chess[px][py-1])
//		{
//			py--;
//			count++;
//		}
//		else
//			break;
//	}
//	px=x;
//	py=y;
//	while(py+1<15)//右横向
//	{
//		if(chess[x][y]==chess[px][py+1])
//		{
//			count++;
//			py++;
//		}
//		else
//			break;
//	}
//	if(count>=4)
//	{
//		printf("%s win!",chess[x][y]);
//		exit(0);
//	}
//	px=x;
//	py=y;
//	count=0;
//	///////////////////////////////纵向、//////////////
//	while(px-1>=0)//上
//	{
//		if(chess[x][y]==chess[px-1][py])
//		{
//			px--;
//			count++;
//		}
//		else
//			break;
//	}
//	px=x;
//	py=y;
//	while(px+1<15)//下
//	{
//		if(chess[x][y]==chess[px+1][py])
//		{
//			count++;
//			px++;
//		}
//		else
//			break;
//	}
//	if(count>=4)
//	{
//		printf("%s win!",chess[x][y]);
//		exit(0);
//	}
//	px=x;
//	py=y;
//	count=0;
//	///////////////////////////////斜向一、//////////////
//	while(px-1>=0&&py-1>=0)//左上
//	{
//		if(chess[x][y]==chess[px-1][py-1])
//		{
//			px--;
//			py--;
//			count++;
//		}
//		else
//			break;
//	}
//	px=x;
//	py=y;
//	while(px+1<15&&py+1<15)//右下
//	{
//		if(chess[x][y]==chess[px+1][py+1])
//		{
//			count++;
//			px++;
//			py++;
//		}
//		else
//			break;
//	}
//	if(count>=4)
//	{
//		printf("%s win!",chess[x][y]);
//		exit(0);
//	}
//	px=x;
//	py=y;
//	count=0;
//		///////////////////////////////斜向二、//////////////
//	while(px-1>=0&&py+1<15)//右上
//	{
//		if(chess[x][y]==chess[px-1][py+1])
//		{
//			px--;
//			py++;
//			count++;
//		}
//		else
//			break;
//	}
//	px=x;
//	py=y;
//	while(px+1<15&&py-1>=0)//左下
//	{
//		if(chess[x][y]==chess[px+1][py-1])
//		{
//			count++;
//			px++;
//			py--;
//		}
//		else
//			break;
//	}
//	if(count>=4)
//	{
//		printf("%s win!",chess[x][y]);
//		exit(0);
//	}
//}
//void main()
//{
//	bool Who=true;
//	int a;
//	char b;
//	int x,y;
//	int count=0;
//	while(1)
//	{
//		ShowChess();
//		printf("plz %s input:",Who?"☆":"○");
//		scanf("%d%c",&a,&b);
//		x=a-1;
//		y=b-65;
//		if(chess[x][y]=="☆"||chess[x][y]=="○")
//			continue;
//		chess[x][y]=Who?"☆":"○";
//		if(++count==225)
//		{
//			printf("Nobody win this game!\n");
//			exit(0);
//		}
//		Check(x,y);
//		Who=!Who;
//	}
//}