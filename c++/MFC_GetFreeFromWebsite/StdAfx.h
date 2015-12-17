// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__607DF3C7_8111_4BC8_9526_350047F00982__INCLUDED_)
#define AFX_STDAFX_H__607DF3C7_8111_4BC8_9526_350047F00982__INCLUDED_

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

#define UNCOMPRESS_BUFFER_LEN 100000
#define RECEIVE_BUFFER_LEN 40000
#define UM_TRAY_NOTIFY WM_USER+1
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#include <Winsock2.h>
#pragma comment (lib,"Ws2_32.lib")
#include "zlib.h"
#include "zconf.h"
#pragma comment (lib,"zdll.lib")
#include <string>
using namespace std;
#endif // !defined(AFX_STDAFX_H__607DF3C7_8111_4BC8_9526_350047F00982__INCLUDED_)
