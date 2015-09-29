// MFC_Snake.h : main header file for the MFC_SNAKE application
//

#if !defined(AFX_MFC_SNAKE_H__85B3DBDE_5065_4FE4_98DA_1130CCE5A7ED__INCLUDED_)
#define AFX_MFC_SNAKE_H__85B3DBDE_5065_4FE4_98DA_1130CCE5A7ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_SnakeApp:
// See MFC_Snake.cpp for the implementation of this class
//

class CMFC_SnakeApp : public CWinApp
{
public:
	CMFC_SnakeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_SnakeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_SnakeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SNAKE_H__85B3DBDE_5065_4FE4_98DA_1130CCE5A7ED__INCLUDED_)
