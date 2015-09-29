// HttpRequest.h: interface for the HttpRequest class.
//
//////////////////////////////////////////////////////////////////////
#include "afxinet.h"
#include "wininet.h"

#if !defined(AFX_HTTPREQUEST_H__8BB6A433_06AA_4BFF_A117_2FAEA81F7534__INCLUDED_)
#define AFX_HTTPREQUEST_H__8BB6A433_06AA_4BFF_A117_2FAEA81F7534__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class HttpRequest  
{
public:
	HttpRequest();
	CString ConnectHttp(const CString sUrl);
	CString Convert(CString str,int sourceCodepage, int targetCodepage);
	virtual ~HttpRequest();
private:
	CInternetSession m_session;	  //建立Internet会话
};

#endif // !defined(AFX_HTTPREQUEST_H__8BB6A433_06AA_4BFF_A117_2FAEA81F7534__INCLUDED_)
