#include <Winsock2.h>
#include <stdio.h>
#pragma comment (lib,"Ws2_32.lib")
void main()
{
	//初始化套接字库	WSAStartup(1,1)
	WSADATA WSAData;
	if(WSAStartup(1,&WSAData)!=0)
	{
		printf("初始化套接字库失败！\n");
		return;
	}
	//创建套接字	sockClient = socket(SOCK_STREAM)
	SOCKET	sockClient;
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockClient)
	{
		printf("创建套接字失败！\n");
		WSACleanup();
		return;
	}
	//指明服务器	SOCKADDR_IN addrSrv=IP:6001
	//
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=0x1234;
	skaddr.sin_addr.s_addr=inet_addr("127.0.0.1");         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	//发出连接请求	connect(sockClient, addrSrv)
	if(SOCKET_ERROR==connect(sockClient,(SOCKADDR *)&skaddr,sizeof(SOCKADDR_IN)))
	{
		printf("连接失败！\n");
		closesocket(sockClient);
		WSACleanup();
		return;
	}
	//接受服务端数据	recv(sockClient) 阻塞
	while(1)
	{
		char bufrev[20]={0};
		int nstr=::recv(sockClient,bufrev,sizeof(bufrev),0);
		if(nstr>0)
		{
			bufrev[nstr]='\0';
			printf("服务器说：%s\n",bufrev);  //数字转字符串 // inet_addr  字符串转数字
		}
		//发数据到服务端	send(sockClient)
		char bufsnd[20]={0};
		printf("我说：");
		gets(bufsnd);
		if(SOCKET_ERROR==send(sockClient,bufsnd,strlen(bufsnd),0))
		{
			printf("发送失败！\n");
			closesocket(sockClient);
			WSACleanup();
			return;
		}
	}
	//关闭连接	
	closesocket(sockClient);
	//释放套接字库资源	
	WSACleanup();

}