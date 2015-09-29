// MFC_UDP_CHAT.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFC_UDP_CHAT.h"
#include "MFC_UDP_CHATDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_CHATApp

BEGIN_MESSAGE_MAP(CMFC_UDP_CHATApp, CWinApp)
	//{{AFX_MSG_MAP(CMFC_UDP_CHATApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_CHATApp construction

CMFC_UDP_CHATApp::CMFC_UDP_CHATApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFC_UDP_CHATApp object

CMFC_UDP_CHATApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFC_UDP_CHATApp initialization

BOOL CMFC_UDP_CHATApp::InitInstance()
{
	WSADATA wd;
	if(WSAStartup(1,&wd)!=0)
	{
		::AfxMessageBox("��ʼ���׽��ֿ�ʧ��");
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

	CMFC_UDP_CHATDlg dlg;
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
