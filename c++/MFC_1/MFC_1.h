// MFC_1.h : main header file for the MFC_1 application
//

#if !defined(AFX_MFC_1_H__506BE122_9BA7_4780_B382_6F42A6C29F37__INCLUDED_)
#define AFX_MFC_1_H__506BE122_9BA7_4780_B382_6F42A6C29F37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_1App:
// See MFC_1.cpp for the implementation of this class
//

class CMFC_1App : public CWinApp
{
public:
	CMFC_1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_1_H__506BE122_9BA7_4780_B382_6F42A6C29F37__INCLUDED_)
