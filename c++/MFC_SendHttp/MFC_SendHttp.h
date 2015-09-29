// MFC_SendHttp.h : main header file for the MFC_SENDHTTP application
//

#if !defined(AFX_MFC_SENDHTTP_H__CE00047C_CA8E_456F_AF5B_E4053B8B1EAF__INCLUDED_)
#define AFX_MFC_SENDHTTP_H__CE00047C_CA8E_456F_AF5B_E4053B8B1EAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_SendHttpApp:
// See MFC_SendHttp.cpp for the implementation of this class
//

class CMFC_SendHttpApp : public CWinApp
{
public:
	CMFC_SendHttpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SendHttpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_SendHttpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SENDHTTP_H__CE00047C_CA8E_456F_AF5B_E4053B8B1EAF__INCLUDED_)
