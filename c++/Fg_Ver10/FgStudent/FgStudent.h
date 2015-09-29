// FgStudent.h : main header file for the FGSTUDENT application
//

#if !defined(AFX_FGSTUDENT_H__05571BC6_E56D_471A_922D_23ADB8D7C3B4__INCLUDED_)
#define AFX_FGSTUDENT_H__05571BC6_E56D_471A_922D_23ADB8D7C3B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFgStudentApp:
// See FgStudent.cpp for the implementation of this class
//

class CFgStudentApp : public CWinApp
{
public:
	CFgStudentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFgStudentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFgStudentApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FGSTUDENT_H__05571BC6_E56D_471A_922D_23ADB8D7C3B4__INCLUDED_)
