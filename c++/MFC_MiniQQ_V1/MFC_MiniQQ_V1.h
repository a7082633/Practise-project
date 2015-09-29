// MFC_MiniQQ_V1.h : main header file for the MFC_MINIQQ_V1 application
//

#if !defined(AFX_MFC_MINIQQ_V1_H__9B4EB624_73B6_4D2B_8E26_BCB9E6693B50__INCLUDED_)
#define AFX_MFC_MINIQQ_V1_H__9B4EB624_73B6_4D2B_8E26_BCB9E6693B50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V1App:
// See MFC_MiniQQ_V1.cpp for the implementation of this class
//

class CMFC_MiniQQ_V1App : public CWinApp
{
public:
	CMFC_MiniQQ_V1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MiniQQ_V1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_MiniQQ_V1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINIQQ_V1_H__9B4EB624_73B6_4D2B_8E26_BCB9E6693B50__INCLUDED_)
