// MFC_MULTI_THREAD_BAR.h : main header file for the MFC_MULTI_THREAD_BAR application
//

#if !defined(AFX_MFC_MULTI_THREAD_BAR_H__2D00F8BF_A3DA_4286_8B0B_0B442380FC95__INCLUDED_)
#define AFX_MFC_MULTI_THREAD_BAR_H__2D00F8BF_A3DA_4286_8B0B_0B442380FC95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_MULTI_THREAD_BARApp:
// See MFC_MULTI_THREAD_BAR.cpp for the implementation of this class
//

class CMFC_MULTI_THREAD_BARApp : public CWinApp
{
public:
	CMFC_MULTI_THREAD_BARApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MULTI_THREAD_BARApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_MULTI_THREAD_BARApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MULTI_THREAD_BAR_H__2D00F8BF_A3DA_4286_8B0B_0B442380FC95__INCLUDED_)
