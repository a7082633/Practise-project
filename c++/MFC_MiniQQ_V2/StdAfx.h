// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__9FF93D1C_E0F4_4E32_860B_3DD4A8967684__INCLUDED_)
#define AFX_STDAFX_H__9FF93D1C_E0F4_4E32_860B_3DD4A8967684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions
#define UM_TRAY_NOTIFY WM_USER+1
struct MESSAGEHEAD
{
	//1:离线
	//2:在线
	//3:回发信息 32:回发上线消息 37:回发在线
	//4:单聊信息
	//5:组聊
	//6:群聊
	//7:在线测试
	//8:文件发送
	int flag; 
	int iMsgLen; //信息长度
//	char 
};
struct FILEHEAD
{
	char FileName[200];
	DWORD FileLen;
};
struct TMSG
{
	void *pDlg;
	SOCKET m_hSocket;
};
#define CLASSBR "255.255.255.255"
#define MESSAGEPORT 1212
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__9FF93D1C_E0F4_4E32_860B_3DD4A8967684__INCLUDED_)
