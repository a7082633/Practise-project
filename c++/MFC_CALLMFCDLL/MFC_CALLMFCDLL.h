// MFC_CALLMFCDLL.h : main header file for the MFC_CALLMFCDLL DLL
//

#if !defined(AFX_MFC_CALLMFCDLL_H__7C676D9C_9987_4553_93DE_82B79B9B466E__INCLUDED_)
#define AFX_MFC_CALLMFCDLL_H__7C676D9C_9987_4553_93DE_82B79B9B466E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_CALLMFCDLLApp
// See MFC_CALLMFCDLL.cpp for the implementation of this class
//

class CMFC_CALLMFCDLLApp : public CWinApp
{
public:
	CMFC_CALLMFCDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_CALLMFCDLLApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMFC_CALLMFCDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_CALLMFCDLL_H__7C676D9C_9987_4553_93DE_82B79B9B466E__INCLUDED_)
