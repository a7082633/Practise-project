// MFCTest.h : main header file for the MFCTEST application
//

#if !defined(AFX_MFCTEST_H__7B640205_183E_4A1B_A66D_2849073BF5D1__INCLUDED_)
#define AFX_MFCTEST_H__7B640205_183E_4A1B_A66D_2849073BF5D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCTestApp:
// See MFCTest.cpp for the implementation of this class
//

class CMFCTestApp : public CWinApp
{
public:
	CMFCTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCTestApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTEST_H__7B640205_183E_4A1B_A66D_2849073BF5D1__INCLUDED_)
