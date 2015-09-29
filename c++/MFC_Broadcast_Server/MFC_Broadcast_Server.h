// MFC_Broadcast_Server.h : main header file for the MFC_BROADCAST_SERVER application
//

#if !defined(AFX_MFC_BROADCAST_SERVER_H__FADAAB09_8F90_4AE6_A5AF_578E220CE8D0__INCLUDED_)
#define AFX_MFC_BROADCAST_SERVER_H__FADAAB09_8F90_4AE6_A5AF_578E220CE8D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ServerApp:
// See MFC_Broadcast_Server.cpp for the implementation of this class
//

class CMFC_Broadcast_ServerApp : public CWinApp
{
public:
	CMFC_Broadcast_ServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_Broadcast_ServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_Broadcast_ServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_BROADCAST_SERVER_H__FADAAB09_8F90_4AE6_A5AF_578E220CE8D0__INCLUDED_)
