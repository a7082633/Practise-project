// MFC_DATABESE1.h : main header file for the MFC_DATABESE1 application
//

#if !defined(AFX_MFC_DATABESE1_H__F5D62D3E_8A36_4CC7_A529_3CA35B172322__INCLUDED_)
#define AFX_MFC_DATABESE1_H__F5D62D3E_8A36_4CC7_A529_3CA35B172322__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_DATABESE1App:
// See MFC_DATABESE1.cpp for the implementation of this class
//

class CMFC_DATABESE1App : public CWinApp
{
public:
	CMFC_DATABESE1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_DATABESE1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_DATABESE1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_DATABESE1_H__F5D62D3E_8A36_4CC7_A529_3CA35B172322__INCLUDED_)
