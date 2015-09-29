// MFC_ThreadMessage.h : main header file for the MFC_THREADMESSAGE application
//

#if !defined(AFX_MFC_THREADMESSAGE_H__31C44C42_009B_4FF3_8587_A58F9D1DD5F7__INCLUDED_)
#define AFX_MFC_THREADMESSAGE_H__31C44C42_009B_4FF3_8587_A58F9D1DD5F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_ThreadMessageApp:
// See MFC_ThreadMessage.cpp for the implementation of this class
//

class CMFC_ThreadMessageApp : public CWinApp
{
public:
	CMFC_ThreadMessageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ThreadMessageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_ThreadMessageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_THREADMESSAGE_H__31C44C42_009B_4FF3_8587_A58F9D1DD5F7__INCLUDED_)
