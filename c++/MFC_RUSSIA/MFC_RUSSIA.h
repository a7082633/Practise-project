// MFC_RUSSIA.h : main header file for the MFC_RUSSIA application
//

#if !defined(AFX_MFC_RUSSIA_H__7D68E9FF_4643_4FC8_A6BD_7010F80A02A5__INCLUDED_)
#define AFX_MFC_RUSSIA_H__7D68E9FF_4643_4FC8_A6BD_7010F80A02A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_RUSSIAApp:
// See MFC_RUSSIA.cpp for the implementation of this class
//

class CMFC_RUSSIAApp : public CWinApp
{
public:
	CMFC_RUSSIAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_RUSSIAApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_RUSSIAApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_RUSSIA_H__7D68E9FF_4643_4FC8_A6BD_7010F80A02A5__INCLUDED_)
