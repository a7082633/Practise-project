#include <Winsock2.h>
#include <stdio.h>
#pragma comment (lib,"Ws2_32.lib")
DWORD WINAPI ChatThread(void *p);
void main()
{
	//��ʼ���׽��ֿ�
	WSADATA WSAData;
	if(WSAStartup(1,&WSAData)!=0)
	{
		printf("��ʼ���׽��ֿ�ʧ�ܣ�\n");
		return;
	}
	//�����׽���
	SOCKET	sockSrv;
	sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == sockSrv)
	{
		printf("�����׽���ʧ�ܣ�\n");
		WSACleanup();
		return;
	}
	//���׽��ֵ��˿�
	SOCKADDR_IN skaddr={0};
	skaddr.sin_port=0x1234;
	skaddr.sin_addr.s_addr=0;         //htonl(INADDR_ANY);         
	skaddr.sin_family=AF_INET;
	if(SOCKET_ERROR==bind(sockSrv,(sockaddr *)&skaddr,sizeof(sockaddr)))
	{
		printf("���׽���ʧ�ܣ�\n");
		closesocket(sockSrv);
		WSACleanup();
		return;
	}
	//��ʼ�����ͻ���	
	if(SOCKET_ERROR==listen(sockSrv, 5))
	{
		printf("����ʧ�ܣ�\n");
		closesocket(sockSrv);
		WSACleanup();
		return;
	}

	while(1)
	{
		//���ܿͻ�����������	
		SOCKET sockConn;
		SOCKADDR_IN skafrmddr={0};
		int addrlen=sizeof(sockaddr);
		sockConn = accept(sockSrv,(sockaddr *)&skafrmddr,&addrlen); //����


		::CreateThread(NULL, 0,ChatThread,(void*)sockConn, 0, NULL);

		if(INVALID_SOCKET==sockConn)
		{
			printf("���ܿͻ�����ʧ�ܣ�\n");
			closesocket(sockSrv);
			WSACleanup();
			return;
		}
	}



	//�رշ��������	
	closesocket(sockSrv);

	//�ͷ��׽��ֿ���Դ	
	WSACleanup();
	
}

DWORD WINAPI ChatThread(void *p)
{
	printf("���ӣ�");
	SOCKET sockConn=(SOCKET)p;
	printf("���ӣ�");
	while(1)
	{
		//��ͻ��˷�������
		char bufsnd[20]={0};
			printf("���ӣ�");
		printf("��˵���ӣ�");
		gets(bufsnd);
		if(SOCKET_ERROR==send(sockConn,bufsnd,strlen(bufsnd),0))
		{
			printf("����ʧ�ܣ�\n");
			closesocket(sockConn);
			WSACleanup();
			return 0;
		}
		//���ܿͻ�������
		char bufrev[20]={0};
		int nstr=recv(sockConn,bufrev,sizeof(bufrev),0); //����
		if(nstr>0)
		{
			bufrev[nstr]='\0';
			printf("��˵4��%s\n"/*,inet_ntoa(skafrmddr.sin_addr)*/,bufrev);  //����ת�ַ��� // inet_addr  �ַ���ת����
		}
	}
	//�رտͻ�������	
	closesocket(sockConn);
	return 0;
}