// MFC_UDP_SYNC_CHAT.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_UDP_SYNC_CHAT.h"
#include "MFC_UDP_SYNC_CHATDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC_CHATApp

BEGIN_MESSAGE_MAP(CMFC_UDP_SYNC_CHATApp, CWinApp)
	//{{AFX_MSG_MAP(CMFC_UDP_SYNC_CHATApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC_CHATApp construction

CMFC_UDP_SYNC_CHATApp::CMFC_UDP_SYNC_CHATApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFC_UDP_SYNC_CHATApp object

CMFC_UDP_SYNC_CHATApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_SYNC_CHATApp initialization

BOOL CMFC_UDP_SYNC_CHATApp::InitInstance()
{
	WSADATA wd;
	::WSAStartup(0x0202,&wd);
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

	CMFC_UDP_SYNC_CHATDlg dlg;
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

int CMFC_UDP_SYNC_CHATApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	::WSACleanup();
	return CWinApp::ExitInstance();
}
