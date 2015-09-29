#include <Winsock2.h>
#include <stdio.h>
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
	skaddr.sin_port=0x1234;
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

	while(1)
	{
		//接受客户端连接请求	
		SOCKET sockConn;
		SOCKADDR_IN skafrmddr={0};
		int addrlen=sizeof(sockaddr);
		sockConn = accept(sockSrv,(sockaddr *)&skafrmddr,&addrlen); //阻塞


		::CreateThread(NULL, 0,ChatThread,(void*)sockConn, 0, NULL);

		if(INVALID_SOCKET==sockConn)
		{
			printf("接受客户请求失败！\n");
			closesocket(sockSrv);
			WSACleanup();
			return;
		}
	}



	//关闭服务端连接	
	closesocket(sockSrv);

	//释放套接字库资源	
	WSACleanup();
	
}

DWORD WINAPI ChatThread(void *p)
{
	printf("连接！");
	SOCKET sockConn=(SOCKET)p;
	printf("连接！");
	while(1)
	{
		//向客户端发送数据
		char bufsnd[20]={0};
			printf("连接！");
		printf("我说连接：");
		gets(bufsnd);
		if(SOCKET_ERROR==send(sockConn,bufsnd,strlen(bufsnd),0))
		{
			printf("发送失败！\n");
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
			printf("他说4：%s\n"/*,inet_ntoa(skafrmddr.sin_addr)*/,bufrev);  //数字转字符串 // inet_addr  字符串转数字
		}
	}
	//关闭客户端连接	
	closesocket(sockConn);
	return 0;
}