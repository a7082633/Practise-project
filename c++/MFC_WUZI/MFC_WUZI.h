// MFC_WUZI.h : main header file for the MFC_WUZI application
//

#if !defined(AFX_MFC_WUZI_H__1A4570CA_D2A1_4B61_A037_864D60BD3B87__INCLUDED_)
#define AFX_MFC_WUZI_H__1A4570CA_D2A1_4B61_A037_864D60BD3B87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_WUZIApp:
// See MFC_WUZI.cpp for the implementation of this class
//

class CMFC_WUZIApp : public CWinApp
{
public:
	CMFC_WUZIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_WUZIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_WUZIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_WUZI_H__1A4570CA_D2A1_4B61_A037_864D60BD3B87__INCLUDED_)
