// MFC_FILEC.h : main header file for the MFC_FILEC application
//

#if !defined(AFX_MFC_FILEC_H__1F9DC596_152F_4453_9B1F_1EB3311B2D6D__INCLUDED_)
#define AFX_MFC_FILEC_H__1F9DC596_152F_4453_9B1F_1EB3311B2D6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILECApp:
// See MFC_FILEC.cpp for the implementation of this class
//

class CMFC_FILECApp : public CWinApp
{
public:
	CMFC_FILECApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_FILECApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_FILECApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_FILEC_H__1F9DC596_152F_4453_9B1F_1EB3311B2D6D__INCLUDED_)
