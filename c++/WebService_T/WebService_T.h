// WebService_T.h : main header file for the WEBSERVICE_T application
//

#if !defined(AFX_WEBSERVICE_T_H__48CC55A1_AAB4_4B55_9F30_5398E30CE5CE__INCLUDED_)
#define AFX_WEBSERVICE_T_H__48CC55A1_AAB4_4B55_9F30_5398E30CE5CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWebService_TApp:
// See WebService_T.cpp for the implementation of this class
//

class CWebService_TApp : public CWinApp
{
public:
	CWebService_TApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebService_TApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWebService_TApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBSERVICE_T_H__48CC55A1_AAB4_4B55_9F30_5398E30CE5CE__INCLUDED_)
