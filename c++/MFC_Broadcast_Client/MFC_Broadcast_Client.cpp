// MFC_Broadcast_Client.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_Broadcast_Client.h"
#include "MFC_Broadcast_ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ClientApp

BEGIN_MESSAGE_MAP(CMFC_Broadcast_ClientApp, CWinApp)
	//{{AFX_MSG_MAP(CMFC_Broadcast_ClientApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ClientApp construction

CMFC_Broadcast_ClientApp::CMFC_Broadcast_ClientApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFC_Broadcast_ClientApp object

CMFC_Broadcast_ClientApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFC_Broadcast_ClientApp initialization

BOOL CMFC_Broadcast_ClientApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
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

//	CMFC_Broadcast_ClientDlg dlg;
//	m_pMainWnd = &dlg;
//	int nResponse = dlg.DoModal();
//	if (nResponse == IDOK)
//	{
//		// TODO: Place code here to handle when the dialog is
//		//  dismissed with OK
//	}
//	else if (nResponse == IDCANCEL)
//	{
//		// TODO: Place code here to handle when the dialog is
//		//  dismissed with Cancel
//	}
//
//	// Since the dialog has been closed, return FALSE so that we exit the
//	//  application, rather than start the application's message pump.
//	return FALSE;
	CMFC_Broadcast_ClientDlg *dlg = new CMFC_Broadcast_ClientDlg;
	m_pMainWnd = dlg;
	return dlg->Create(IDD_MFC_BROADCAST_CLIENT_DIALOG);
}
