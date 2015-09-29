// MFC_MiniQQ_V1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_MiniQQ_V1.h"
#include "MFC_MiniQQ_V1Dlg.h"
#include "ChatDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V1App

BEGIN_MESSAGE_MAP(CMFC_MiniQQ_V1App, CWinApp)
	//{{AFX_MSG_MAP(CMFC_MiniQQ_V1App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V1App construction

CMFC_MiniQQ_V1App::CMFC_MiniQQ_V1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFC_MiniQQ_V1App object

CMFC_MiniQQ_V1App theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFC_MiniQQ_V1App initialization

BOOL CMFC_MiniQQ_V1App::InitInstance()
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

	CMFC_MiniQQ_V1Dlg dlg;
	m_pMainWnd = &dlg;
	int n=dlg.DoModal();
	if (n == IDOK)
	{
		::MessageBox(NULL,"test","",MB_OK);
		CChatDialog ChatDlg;
		m_pMainWnd = &ChatDlg;
		if (ChatDlg.DoModal() == IDOK)
		{
		}
	}
	else if (n == IDCANCEL)
	{
		::MessageBox(NULL,"test","",MB_OK);
	}




	////////////////////////////////////////////ÆäËû
//	CLoginDlg log;
//	if(log.DoModal()==IDOK)
//	{
//		CMFC_MINIQQDlg dlg;
//		m_pMainWnd = &dlg;
//		int nResponse = dlg.DoModal();
//		if (nResponse == IDOK)
//		{
//		}
//		else if (nResponse == IDCANCEL)
//		{
//		}
//	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
