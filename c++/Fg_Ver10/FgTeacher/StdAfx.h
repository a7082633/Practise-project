// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__971AD12F_F464_4368_81FF_017D36453268__INCLUDED_)
#define AFX_STDAFX_H__971AD12F_F464_4368_81FF_017D36453268__INCLUDED_

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

#pragma warning (disable:4996)

#include <afxsock.h>		// MFC socket extensions

#define UM_TRAY_NOTIFY WM_USER + 1

#define UDP_PORT 7788
#define PACKSIZE 32768

#define PH_START_BROADCAST 1
#define PH_STOP_BROADCAST  2
#define PH_SEND_FRAMEPART  3

typedef struct tagPACKHEAD
{
	UINT nFlag;		//1开始广播 2停止广播 3发送帧Part
	UINT nFrame;	//帧号
	WORD nPartCnt;	//当前帧共分几个part发送
	WORD nPartID;	//这是当前帧的第几个part
	BITMAPINFO biScreen;
}PACKHEAD, *PPACKHEAD;

#if (_MSC_VER == 1200)

typedef struct tagCURSORINFO
{
    DWORD   cbSize;
    DWORD   flags;
    HCURSOR hCursor;
    POINT   ptScreenPos;
} CURSORINFO, *PCURSORINFO, *LPCURSORINFO;

typedef BOOL (WINAPI *GETCURSORINFO)(PCURSORINFO pci);

#endif	//(_MSC_VER == 1200)

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__971AD12F_F464_4368_81FF_017D36453268__INCLUDED_)
