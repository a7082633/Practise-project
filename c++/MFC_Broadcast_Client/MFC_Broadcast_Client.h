// MFC_Broadcast_Client.h : main header file for the MFC_BROADCAST_CLIENT application
//

#if !defined(AFX_MFC_BROADCAST_CLIENT_H__40B34C1E_4871_4EC5_AB4A_572275950719__INCLUDED_)
#define AFX_MFC_BROADCAST_CLIENT_H__40B34C1E_4871_4EC5_AB4A_572275950719__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ClientApp:
// See MFC_Broadcast_Client.cpp for the implementation of this class
//

class CMFC_Broadcast_ClientApp : public CWinApp
{
public:
	CMFC_Broadcast_ClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_Broadcast_ClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_Broadcast_ClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_BROADCAST_CLIENT_H__40B34C1E_4871_4EC5_AB4A_572275950719__INCLUDED_)
