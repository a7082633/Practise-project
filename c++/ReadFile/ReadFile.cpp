// ReadFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <memory.h>

int main(int argc, char* argv[])
{
	FILE *pFile=fopen("test.txt","r");
	if(pFile==NULL)
	{
		printf("打开文件失败!");
		return 0;
	}
	char *pBuf; 
	rewind(pFile);
	pBuf=new char[100]; 
	fread(pBuf,1,50,pFile);
	int i=0;
	memcpy(&i,pBuf+17,4);
	printf("%d\n",i);
	delete []pBuf;
	return 0;
}
