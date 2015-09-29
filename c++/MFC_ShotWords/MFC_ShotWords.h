// MFC_ShotWords.h : main header file for the MFC_SHOTWORDS application
//

#if !defined(AFX_MFC_SHOTWORDS_H__7AA620DF_32E2_43FC_B836_502A30882A5C__INCLUDED_)
#define AFX_MFC_SHOTWORDS_H__7AA620DF_32E2_43FC_B836_502A30882A5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_ShotWordsApp:
// See MFC_ShotWords.cpp for the implementation of this class
//

class CMFC_ShotWordsApp : public CWinApp
{
public:
	CMFC_ShotWordsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_ShotWordsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFC_ShotWordsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SHOTWORDS_H__7AA620DF_32E2_43FC_B836_502A30882A5C__INCLUDED_)
