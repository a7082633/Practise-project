// HttpRequest.cpp: implementation of the HttpRequest class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TEST.h"
#include "HttpRequest.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HttpRequest::HttpRequest()
{

}

HttpRequest::~HttpRequest()
{

}
CString HttpRequest::ConnectHttp(const CString sUrl)
{ 
	CString sResult;
	CInternetFile *hHttpFile=NULL;
	sResult="";
	hHttpFile=(CInternetFile *)m_session.OpenURL(sUrl);
	//得到文件指针
	if(hHttpFile)
	{ 
		CString sLine;
		while(hHttpFile->ReadString(sLine)) //读取Http服务器上的内容	
		sResult=sResult+sLine+"\r\n";
		hHttpFile->Close();		//关闭连接
	}
	else{
		sResult=sResult+"There are some errors in finding this Http sites";
	}
	CString gb2312 = Convert(sResult,CP_UTF8,936);
	return gb2312;
}
/*
utf-8转gb2312:
CString gb2312 = Convert(utf8,CP_UTF8,936);

gb2312转utf8
CString utf8 = Convert(gb2312,936,CP_UTF8)
*/
CString HttpRequest::Convert(CString str,int sourceCodepage, int targetCodepage)
{
	int len = str.GetLength();
	int unicodeLen = MultiByteToWideChar(sourceCodepage,0,str,-1,NULL,0);
	
	wchar_t *pUnicode;  
	pUnicode = new wchar_t[unicodeLen+1];
	memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t));
	MultiByteToWideChar(sourceCodepage,0,str,-1,(LPWSTR)pUnicode,unicodeLen);
	
	BYTE *pTargetData = NULL ;
	int targetLen = WideCharToMultiByte(targetCodepage,0,(LPWSTR)pUnicode,-1,(char*)pTargetData,0,NULL,NULL);
	
	pTargetData = new BYTE[targetLen+1];
	memset(pTargetData,0,targetLen+1);
	
	WideCharToMultiByte(targetCodepage,0,(LPWSTR)pUnicode,-1,(char*)pTargetData,targetLen,NULL,NULL);
	
	CString rt;
	rt.Format("%s",pTargetData);
	
	delete []pUnicode;
	delete []pTargetData;
	
	return rt ;
	
} 