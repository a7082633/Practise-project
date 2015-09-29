// MFCRandSeat.h : main header file for the MFCRANDSEAT application
//

#if !defined(AFX_MFCRANDSEAT_H__9A97C240_8A52_4238_AC08_5A6C2DDD68D3__INCLUDED_)
#define AFX_MFCRANDSEAT_H__9A97C240_8A52_4238_AC08_5A6C2DDD68D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCRandSeatApp:
// See MFCRandSeat.cpp for the implementation of this class
//

class CMFCRandSeatApp : public CWinApp
{
public:
	CMFCRandSeatApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCRandSeatApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCRandSeatApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCRANDSEAT_H__9A97C240_8A52_4238_AC08_5A6C2DDD68D3__INCLUDED_)
