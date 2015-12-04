// SocketSendHttp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Winsock2.h>
#include <stdio.h>
#pragma comment (lib,"Ws2_32.lib")

int main(int argc, char* argv[])
{
	//��ʼ���׽��ֿ�
	WSADATA WSAData;
	if(WSAStartup(1,&WSAData)!=0)
	{
		printf("��ʼ���׽��ֿ�ʧ�ܣ�\n");
		return 0;
	}
	//�����׽���
	SOCKET	sockClient;
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockClient)
	{
		printf("�����׽���ʧ�ܣ�\n");
		WSACleanup();
		return 0;
	}
	//ָ��������
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=htons((unsigned short)8080);
	skaddr.sin_addr.s_addr=inet_addr("127.0.0.1");         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	//������������	connect(sockClient, addrSrv)
	if(SOCKET_ERROR==connect(sockClient,(SOCKADDR *)&skaddr,sizeof(SOCKADDR_IN)))
	{
		printf("����ʧ�ܣ�\n");
		closesocket(sockClient);
		WSACleanup();
		return 0;
	}
    //��ʼ��������Ϣ
    char send_str[2048] = {0};
	char parameters[100]="test=456";
    //ͷ��Ϣ
    strcat(send_str, "POST ");
    strcat(send_str, "/sell_dan/test/testdemopost");
    strcat(send_str, " HTTP/1.1\r\n");
    strcat(send_str, "Host: ");
    strcat(send_str, "127.0.0.1");
    strcat(send_str, "\r\n");
    strcat(send_str, "Connection: keep-alive\r\n");

    char content_header[100];
    sprintf(content_header,"Content-Length: %d\r\n", strlen(parameters));

    strcat(send_str, content_header);
//   strcat(send_str, "User-Agent: Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/15.0.849.0 Safari/535.1\r\n");
    strcat(send_str, "Content-Type: application/x-www-form-urlencoded\r\n");
//  strcat(send_str, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n");
//  strcat(send_str, "Accept-Language: zh-CN,zh;q=0.8\r\n"); zh. runing the program 
    //������Ϣ
    strcat(send_str, "\r\n");
    strcat(send_str, parameters);
//	strcat(send_str, "\r\n");


    if (send(sockClient, send_str, strlen(send_str),0) == -1)
    {
        printf("����ʧ��!");
        return -101;
    }
	char buf[4000]={0};
	int nNetTimeout=3000;//1�룬
	setsockopt(sockClient,SOL_SOCKET,SO_RCVTIMEO, (char *)&nNetTimeout,sizeof(int));
	int n=::recv(sockClient,buf,sizeof(buf),0);
	return 0;
}
