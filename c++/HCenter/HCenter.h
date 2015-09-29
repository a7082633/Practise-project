// HCenter.h : main header file for the HCENTER application
//

#if !defined(AFX_HCENTER_H__36372678_36EE_4969_AE97_875B77723F2E__INCLUDED_)
#define AFX_HCENTER_H__36372678_36EE_4969_AE97_875B77723F2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHCenterApp:
// See HCenter.cpp for the implementation of this class
//

class CHCenterApp : public CWinApp
{
public:
	CHCenterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHCenterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHCenterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HCENTER_H__36372678_36EE_4969_AE97_875B77723F2E__INCLUDED_)
