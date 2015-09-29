// MFC_UDP_SYNC_CHAT.h : main header file for the MFC_UDP_SYNC_CHAT application
//

#if !defined(AFX_MFC_UDP_SYNC_CHAT_H__153F3724_7BE0_4759_BC82_53F9FFF3ED0F__INCLUDED_)
#define AFX_MFC_UDP_SYNC_CHAT_H__153F3724_7BE0_4759_BC82_53F9FFF3ED0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC_CHATApp:
// See MFC_UDP_SYNC_CHAT.cpp for the implementation of this class
//

class CMFC_UDP_SYNC_CHATApp : public CWinApp
{
public:
	CMFC_UDP_SYNC_CHATApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_UDP_SYNC_CHATApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFC_UDP_SYNC_CHATApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_UDP_SYNC_CHAT_H__153F3724_7BE0_4759_BC82_53F9FFF3ED0F__INCLUDED_)
