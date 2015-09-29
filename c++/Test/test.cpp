
#include "des.h"
//#include <afx.h>

int main()
{
	int a=248, b=4;
	int const c=21;
	const int *d=&a;
	int *const e=&b;
//	int const *f const =&a;
//	e=32;
//	3DES
//	char strKey[100]={"11111111111111111111111111111111"};
//	char strSrc[100]={"11111111111111112222222222222222"};
//	char strDest[100]={0};
//	Do_3DES(strSrc,strKey,strDest,'D');
//	const char *s = "1|2|3|4";
//	int ch='|';
//	char *where = strchr(s,ch);
//	substr
//	
//	
//字符串截取
//	const char *s = "http://www.baidu.com:1234";
//    char protocol[32] = { 0 };
//    char host[128] = { 0 };
//    char port[8] = { 0 };
//    sscanf(s,"%[^:]://%[^:]:%[1-9]",protocol,host,port);
//
//    printf("protocol: %s\n",protocol);
//    printf("host: %s\n",host);
//    printf("port: %s\n",port);
//	发送http请求
//	CInternetSession m_session("Webservice32");
//	CString HttpResponse;
//	try
//	{
//		CString strData;
//		char *requestUrl="http:221.176.197.13:8011/Api!DeviceIdentify.do?account=test&password=111111&macno=000011&samno=123456";
//		CHttpFile *pFile;
//		pFile = (CHttpFile *) m_session.OpenURL(requestUrl);
//		DWORD Code;
//		pFile->QueryInfoStatusCode(Code);
//		if(Code!=200)
//		{
//			printf("找不到主页!");
//			return 0;
//		}
//		char ch;
//		while(pFile->Read(&ch,1))
//		{
//			printf("%c",ch);
//		}
//		while(pFile->ReadString(strData))
//			HttpResponse+=strData;
//		pFile->Close();
//	}
//	catch(CInternetException* e)  捕获异常
//	{
//		TCHAR pszError[200];
//		e->GetErrorMessage(pszError, 200);
//		e->Delete();
//		printf("异常!");
//		return 0;
//	}
//	m_session.Close();
	return 0;
}