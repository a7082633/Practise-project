// MFC_MULTITHREAD.h : main header file for the MFC_MULTITHREAD application
//

#if !defined(AFX_MFC_MULTITHREAD_H__E45E10F7_F48F_44C3_8A79_4A5EEBB3E06B__INCLUDED_)
#define AFX_MFC_MULTITHREAD_H__E45E10F7_F48F_44C3_8A79_4A5EEBB3E06B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_MULTITHREADApp:
// See MFC_MULTITHREAD.cpp for the implementation of this class
//

class CMFC_MULTITHREADApp : public CWinApp
{
public:
	CMFC_MULTITHREADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MULTITHREADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_MULTITHREADApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MULTITHREAD_H__E45E10F7_F48F_44C3_8A79_4A5EEBB3E06B__INCLUDED_)
