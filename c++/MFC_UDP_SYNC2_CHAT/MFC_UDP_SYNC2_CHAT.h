// MFC_UDP_SYNC2_CHAT.h : main header file for the MFC_UDP_SYNC2_CHAT application
//

#if !defined(AFX_MFC_UDP_SYNC2_CHAT_H__00233BBE_4DDC_4747_A914_89510FC3307A__INCLUDED_)
#define AFX_MFC_UDP_SYNC2_CHAT_H__00233BBE_4DDC_4747_A914_89510FC3307A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC2_CHATApp:
// See MFC_UDP_SYNC2_CHAT.cpp for the implementation of this class
//

class CMFC_UDP_SYNC2_CHATApp : public CWinApp
{
public:
	CMFC_UDP_SYNC2_CHATApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_UDP_SYNC2_CHATApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_UDP_SYNC2_CHATApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_UDP_SYNC2_CHAT_H__00233BBE_4DDC_4747_A914_89510FC3307A__INCLUDED_)