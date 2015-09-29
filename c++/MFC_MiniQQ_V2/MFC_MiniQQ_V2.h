// MFC_MiniQQ_V2.h : main header file for the MFC_MINIQQ_V2 application
//

#if !defined(AFX_MFC_MINIQQ_V2_H__3DBB28AA_0D21_4A65_8ACA_75490B2DFEF1__INCLUDED_)
#define AFX_MFC_MINIQQ_V2_H__3DBB28AA_0D21_4A65_8ACA_75490B2DFEF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V2App:
// See MFC_MiniQQ_V2.cpp for the implementation of this class
//

class CMFC_MiniQQ_V2App : public CWinApp
{
public:
	CMFC_MiniQQ_V2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MiniQQ_V2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_MiniQQ_V2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINIQQ_V2_H__3DBB28AA_0D21_4A65_8ACA_75490B2DFEF1__INCLUDED_)
