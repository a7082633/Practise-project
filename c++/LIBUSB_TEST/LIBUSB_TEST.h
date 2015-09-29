// LIBUSB_TEST.h : main header file for the LIBUSB_TEST application
//

#if !defined(AFX_LIBUSB_TEST_H__A68633CA_BD3A_4F20_AC1B_CEB186A81D0C__INCLUDED_)
#define AFX_LIBUSB_TEST_H__A68633CA_BD3A_4F20_AC1B_CEB186A81D0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLIBUSB_TESTApp:
// See LIBUSB_TEST.cpp for the implementation of this class
//

class CLIBUSB_TESTApp : public CWinApp
{
public:
	CLIBUSB_TESTApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLIBUSB_TESTApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLIBUSB_TESTApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBUSB_TEST_H__A68633CA_BD3A_4F20_AC1B_CEB186A81D0C__INCLUDED_)
