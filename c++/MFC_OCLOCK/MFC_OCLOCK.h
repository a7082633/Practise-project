// MFC_OCLOCK.h : main header file for the MFC_OCLOCK application
//

#if !defined(AFX_MFC_OCLOCK_H__4B653935_D065_4B47_A79D_E79F3DBD5199__INCLUDED_)
#define AFX_MFC_OCLOCK_H__4B653935_D065_4B47_A79D_E79F3DBD5199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_OCLOCKApp:
// See MFC_OCLOCK.cpp for the implementation of this class
//

class CMFC_OCLOCKApp : public CWinApp
{
public:
	CMFC_OCLOCKApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_OCLOCKApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_OCLOCKApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_OCLOCK_H__4B653935_D065_4B47_A79D_E79F3DBD5199__INCLUDED_)
