#include <Winsock2.h>
#include <stdio.h>
#pragma comment (lib,"Ws2_32.lib")
void main()
{
	//��ʼ���׽��ֿ�	WSAStartup(1,1)
	WSADATA WSAData;
	if(WSAStartup(1,&WSAData)!=0)
	{
		printf("��ʼ���׽��ֿ�ʧ�ܣ�\n");
		return;
	}
	//�����׽���	sockClient = socket(SOCK_STREAM)
	SOCKET	sockClient;
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockClient)
	{
		printf("�����׽���ʧ�ܣ�\n");
		WSACleanup();
		return;
	}
	//ָ��������	SOCKADDR_IN addrSrv=IP:6001
	//
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=0x1234;
	skaddr.sin_addr.s_addr=inet_addr("127.0.0.1");         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	//������������	connect(sockClient, addrSrv)
	if(SOCKET_ERROR==connect(sockClient,(SOCKADDR *)&skaddr,sizeof(SOCKADDR_IN)))
	{
		printf("����ʧ�ܣ�\n");
		closesocket(sockClient);
		WSACleanup();
		return;
	}
	//���ܷ��������	recv(sockClient) ����
	while(1)
	{
		char bufrev[20]={0};
		int nstr=::recv(sockClient,bufrev,sizeof(bufrev),0);
		if(nstr>0)
		{
			bufrev[nstr]='\0';
			printf("������˵��%s\n",bufrev);  //����ת�ַ��� // inet_addr  �ַ���ת����
		}
		//�����ݵ������	send(sockClient)
		char bufsnd[20]={0};
		printf("��˵��");
		gets(bufsnd);
		if(SOCKET_ERROR==send(sockClient,bufsnd,strlen(bufsnd),0))
		{
			printf("����ʧ�ܣ�\n");
			closesocket(sockClient);
			WSACleanup();
			return;
		}
	}
	//�ر�����	
	closesocket(sockClient);
	//�ͷ��׽��ֿ���Դ	
	WSACleanup();

}