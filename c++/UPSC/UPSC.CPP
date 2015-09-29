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
	//创建套接字	sockSvr = socket(SOCK_DGRAM)
	SOCKET	sockClient;
	sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == sockClient)
	{
		printf("创建套接字失败！\n");
		WSACleanup();
		return;
	}
	//绑定套接字到端口	bind(6001)
	SOCKADDR_IN addr={0};
	addr.sin_family=AF_INET;
	addr.sin_port=0x1234;
	addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	//发数据到客户端
	char bufSend[100]={0};
	printf("我说：");
	gets(bufSend);
	sendto(sockClient,bufSend,strlen(bufSend),0,(sockaddr *)&addr,sizeof(SOCKADDR_IN));
	//接受客户端数据
	char bufRev[100]={0};
	SOCKADDR_IN addrfrm={0};
	addrfrm.sin_family=AF_INET;
	addrfrm.sin_port=0x1234;
	addrfrm.sin_addr.S_un.S_addr=0;
	int len=sizeof(SOCKADDR_IN);
	int nstr=recvfrom(sockClient,bufRev,sizeof(bufRev),0,(sockaddr *)&addr,&len);
	if(nstr>0)
	{
		bufRev[nstr]='\0';
		printf("%s说: %s\n",inet_ntoa(addrfrm.sin_addr),bufRev);
	}
	//关闭套接字	
	closesocket(sockClient);
	//释放套接字库资源	
	WSACleanup();

}