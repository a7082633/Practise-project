// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__DD2FC691_BBF0_468E_9309_919FC6F2EBDF__INCLUDED_)
#define AFX_STDAFX_H__DD2FC691_BBF0_468E_9309_919FC6F2EBDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define _WIN32_WINNT 0x0500 
#define WINVER 0x0500
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include "quicklz.h"
#include <afxsock.h>		// MFC socket extensions
#define PH_START_BROADCAST 1
#define PH_STOP_BROADCAST  2
#define PH_SEND_FRAMEPART  3
#define PH_USER_ONLINE  4    //��������
#define PH_USER_OFFLINE  5    //��������
#define PH_USER_OLTEST	6	//��������
#define PH_USER_OLREPLY	7	//�ظ�����
#define PH_USER_MSG	8	//������Ϣ��
#define PACKSIZE 32768
#define UDP_PORT 7788
#define BRAOD_ADDR "192.168.1.255"
typedef struct tagPACKHEAD
{
	UINT nFlag;		//1��ʼ�㲥 2ֹͣ�㲥 3����֡Part
	UINT nFrame;	//֡��
	WORD nPartCnt;	//��ǰ֡���ּ���part����
	WORD nPartID;	//���ǵ�ǰ֡�ĵڼ���part
	BITMAPINFO biScreen;
}PACKHEAD, *PPACKHEAD;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__DD2FC691_BBF0_468E_9309_919FC6F2EBDF__INCLUDED_)
