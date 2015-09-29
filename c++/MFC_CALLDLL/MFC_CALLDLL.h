// MFC_CALLDLL.h : main header file for the MFC_CALLDLL application
//

#if !defined(AFX_MFC_CALLDLL_H__B8CA3E71_C01D_4493_A8CF_9D1AC44565A0__INCLUDED_)
#define AFX_MFC_CALLDLL_H__B8CA3E71_C01D_4493_A8CF_9D1AC44565A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_CALLDLLApp:
// See MFC_CALLDLL.cpp for the implementation of this class
//

class CMFC_CALLDLLApp : public CWinApp
{
public:
	CMFC_CALLDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CALLDLLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_CALLDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CALLDLL_H__B8CA3E71_C01D_4493_A8CF_9D1AC44565A0__INCLUDED_)
