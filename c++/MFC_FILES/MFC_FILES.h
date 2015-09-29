// MFC_FILES.h : main header file for the MFC_FILES application
//

#if !defined(AFX_MFC_FILES_H__29BA26E1_AAC1_42A0_A9C2_CFA9853195ED__INCLUDED_)
#define AFX_MFC_FILES_H__29BA26E1_AAC1_42A0_A9C2_CFA9853195ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILESApp:
// See MFC_FILES.cpp for the implementation of this class
//

class CMFC_FILESApp : public CWinApp
{
public:
	CMFC_FILESApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_FILESApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_FILESApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_FILES_H__29BA26E1_AAC1_42A0_A9C2_CFA9853195ED__INCLUDED_)
