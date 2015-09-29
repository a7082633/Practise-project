// KeyHook.h : main header file for the KEYHOOK application
//

#if !defined(AFX_KEYHOOK_H__755D359C_1852_4529_BB28_4693D865AC99__INCLUDED_)
#define AFX_KEYHOOK_H__755D359C_1852_4529_BB28_4693D865AC99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKeyHookApp:
// See KeyHook.cpp for the implementation of this class
//

class CKeyHookApp : public CWinApp
{
public:
	CKeyHookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyHookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CKeyHookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYHOOK_H__755D359C_1852_4529_BB28_4693D865AC99__INCLUDED_)
