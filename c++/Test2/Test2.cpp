// Test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdio.h"
#include <iostream>
#include <errno.h>
//#include <afx.h>
#define N 3  
#define Y(n) ((N+1)*n)
using namespace std;
void fn(int *b)
{   
	std::cout<<(*b)++;
}
int main()
{
	char a[2]={0x90,0x80};
	char b[10]={0};
	sprintf(b,"%c",a[0]);
	sprintf(b,"%02X",a[1]);
	return 0;
}
