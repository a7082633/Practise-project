// MFC_DIALOG.h : main header file for the MFC_DIALOG application
//

#if !defined(AFX_MFC_DIALOG_H__365868DA_1238_45C5_AF4D_9BECC21D9AAF__INCLUDED_)
#define AFX_MFC_DIALOG_H__365868DA_1238_45C5_AF4D_9BECC21D9AAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_DIALOGApp:
// See MFC_DIALOG.cpp for the implementation of this class
//

class CMFC_DIALOGApp : public CWinApp
{
public:
	CMFC_DIALOGApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DIALOGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_DIALOGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_DIALOG_H__365868DA_1238_45C5_AF4D_9BECC21D9AAF__INCLUDED_)
