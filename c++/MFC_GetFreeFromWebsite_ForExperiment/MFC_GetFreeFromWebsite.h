// MFC_GetFreeFromWebsite.h : main header file for the MFC_GETFREEFROMWEBSITE application
//

#if !defined(AFX_MFC_GETFREEFROMWEBSITE_H__CFA4F352_F9CE_4326_94E6_B013FB3AA5D7__INCLUDED_)
#define AFX_MFC_GETFREEFROMWEBSITE_H__CFA4F352_F9CE_4326_94E6_B013FB3AA5D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_GetFreeFromWebsiteApp:
// See MFC_GetFreeFromWebsite.cpp for the implementation of this class
//

class CMFC_GetFreeFromWebsiteApp : public CWinApp
{
public:
	CMFC_GetFreeFromWebsiteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_GetFreeFromWebsiteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_GetFreeFromWebsiteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_GETFREEFROMWEBSITE_H__CFA4F352_F9CE_4326_94E6_B013FB3AA5D7__INCLUDED_)
