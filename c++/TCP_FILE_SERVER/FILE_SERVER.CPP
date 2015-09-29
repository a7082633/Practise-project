#include <Winsock2.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#pragma comment (lib,"Ws2_32.lib")
DWORD WINAPI ChatThread(void *p);
void main()
{
	//初始化套接字库
	WSADATA WSAData;
	if(WSAStartup(1,&WSAData)!=0)
	{
		printf("初始化套接字库失败！\n");
		return;
	}
	//创建套接字
	SOCKET	sockSrv;
	sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockSrv)
	{
		printf("创建套接字失败！\n");
		WSACleanup();
		return;
	}
	//绑定套接字到端口
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=0xff98;
	skaddr.sin_addr.s_addr=0;         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	if(SOCKET_ERROR==bind(sockSrv,(sockaddr *)&skaddr,sizeof(sockaddr)))
	{
		printf("绑定套接字失败！\n");
		closesocket(sockSrv);
		WSACleanup();
		return;
	}
	//开始监听客户端	
	if(SOCKET_ERROR==listen(sockSrv, 5))
	{
		printf("监听失败！\n");
		closesocket(sockSrv);
		WSACleanup();
		return;
	}

//	while(1)
//	{
//		//接受客户端连接请求	
//		SOCKADDR_IN skafrmddr={0};
//		int addrlen=sizeof(sockaddr);
//		sockConn = accept(sockSrv,(sockaddr *)&skafrmddr,&addrlen); //阻塞
//		if(INVALID_SOCKET==sockConn)
//		{
//			//printf("接受客户请求失败！\n");
//			continue;
//		}
//		::CreateThread(NULL, 0,ChatThread,(void*)sockConn, 0, NULL);
//	}
	while(1)
	{
		//接受客户端连接请求	
		SOCKET sockConn;
		SOCKADDR_IN skafrmddr={0};
		int addrlen=sizeof(sockaddr);
		sockConn = accept(sockSrv,(sockaddr *)&skafrmddr,&addrlen); //阻塞


		::CreateThread(NULL, 0,ChatThread,(void*)sockConn, 0, NULL);

	}


	//关闭服务端连接	
	closesocket(sockSrv);

	//释放套接字库资源	
	WSACleanup();
	
}

DWORD WINAPI ChatThread(void *p)
{
	SOCKET sockConn=(SOCKET)p;

	char str[2000]={0};
	FILE *fp=fopen("D:\\test\\aaa.bmp","r+");
	if(fp==NULL)
	{
		printf("打开文件失败！");
		return 0;
	}

	//while(1)
	//{
		//向客户端发送数据
		char bufsnd[2000]={0};
		size_t n=fread(bufsnd,1,2000,fp);
		int err=ferror(fp);
		int nSend=send(sockConn,bufsnd,sizeof(bufsnd),0);
		if(nSend>0)
		{
			printf("读大小：%d\n",n);
			printf("发送大小：%d\n",nSend);
			closesocket(sockConn);
			WSACleanup();
			return 0;
		}

		//接受客户端数据
		char bufrev[20]={0};
		int nstr=recv(sockConn,bufrev,sizeof(bufrev),0); //阻塞
		if(nstr>0)
		{
			bufrev[nstr]='\0';
			printf("他说：%s\n"/*,inet_ntoa(skafrmddr.sin_addr)*/,bufrev);  //数字转字符串 // inet_addr  字符串转数字
		}
	//}
	//关闭客户端连接	
	closesocket(sockConn);
	fclose(fp);
	return 0;
}