// MFC_FILEC.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_FILEC.h"
#include "MFC_FILECDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILECApp

BEGIN_MESSAGE_MAP(CMFC_FILECApp, CWinApp)
	//{{AFX_MSG_MAP(CMFC_FILECApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILECApp construction

CMFC_FILECApp::CMFC_FILECApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFC_FILECApp object

CMFC_FILECApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFC_FILECApp initialization

BOOL CMFC_FILECApp::InitInstance()
{
	WSADATA wd;
	if(WSAStartup(1,&wd)!=0)
	{
		::AfxMessageBox("³õÊ¼»¯Ì×½Ó×Ö¿âÊ§°Ü");
		return false;
	}
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMFC_FILECDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CMFC_FILECApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	::WSACleanup();
	return CWinApp::ExitInstance();
}
