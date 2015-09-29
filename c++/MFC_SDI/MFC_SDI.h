// MFC_SDI.h : main header file for the MFC_SDI application
//

#if !defined(AFX_MFC_SDI_H__CF98B8E2_55F9_4A02_BD77_25A7F6096CFB__INCLUDED_)
#define AFX_MFC_SDI_H__CF98B8E2_55F9_4A02_BD77_25A7F6096CFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_SDIApp:
// See MFC_SDI.cpp for the implementation of this class
//

class CMFC_SDIApp : public CWinApp
{
public:
	CMFC_SDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_SDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SDI_H__CF98B8E2_55F9_4A02_BD77_25A7F6096CFB__INCLUDED_)
