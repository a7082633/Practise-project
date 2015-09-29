// MFC_MINIQQ.h : main header file for the MFC_MINIQQ application
//

#if !defined(AFX_MFC_MINIQQ_H__9EC681C0_33F8_4B7A_92A0_CDCB752FF4B8__INCLUDED_)
#define AFX_MFC_MINIQQ_H__9EC681C0_33F8_4B7A_92A0_CDCB752FF4B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_MINIQQApp:
// See MFC_MINIQQ.cpp for the implementation of this class
//

class CMFC_MINIQQApp : public CWinApp
{
public:
	CMFC_MINIQQApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_MINIQQApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_MINIQQApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_MINIQQ_H__9EC681C0_33F8_4B7A_92A0_CDCB752FF4B8__INCLUDED_)
