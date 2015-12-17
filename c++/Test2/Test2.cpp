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
//	char a[2]={0x90,0x80};
//	char b[10]={0};
//	sprintf(b,"%c",a[0]);
//	sprintf(b,"%02X",a[1]);
//×Ö·û´®½ØÈ¡
//	const char *s = "http://www.baidu.com/1234";
//	const char *s = "http://www.wifijy.com/forum-49-1.html";
	const char *s = "http://www.wifijy.com/45678-1";
//	const char *s = "www.baidu.com:1234";
    char protocol[32] = { 0 };
    char host[128] = { 0 };
    char port[100] = { 0 };
    sscanf(s,"%[^:]://%[^/]%s",protocol,host,port);

	char temp[100]={0};
	char api[100]={0};
	sscanf(s,"%*[^:]://%[^/]",temp);
	sscanf(s,"%*[^:]://%*[^/]%s",api);

    printf("protocol: %s\n",protocol);
    printf("host: %s\n",host);
    printf("port: %s\n",port);
	printf("temp: %s\n",temp);
	printf("api: %s\n",api);
	return 0;
}
