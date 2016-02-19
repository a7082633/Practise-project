
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