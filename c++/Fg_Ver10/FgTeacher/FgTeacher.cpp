// FgTeacher.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "FgTeacher.h"
#include "FgTeacherDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFgTeacherApp

BEGIN_MESSAGE_MAP(CFgTeacherApp, CWinApp)
	//{{AFX_MSG_MAP(CFgTeacherApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFgTeacherApp construction

CFgTeacherApp::CFgTeacherApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFgTeacherApp object

CFgTeacherApp theApp;

#if (_MSC_VER == 1200)
GETCURSORINFO GetCursorInfo;
#endif	//(_MSC_VER == 1200)

/////////////////////////////////////////////////////////////////////////////
// CFgTeacherApp initialization

BOOL CFgTeacherApp::InitInstance()
{
	#if (_MSC_VER == 1200)
	HMODULE hDll = ::GetModuleHandle("user32.dll");
	if (!hDll) return FALSE;
	GetCursorInfo = (GETCURSORINFO)::GetProcAddress(hDll, "GetCursorInfo");
	if (!GetCursorInfo) return FALSE;
	#endif	//(_MSC_VER == 1200)

	//只允许启动一个进程。
	::CreateMutex(NULL, FALSE, "FgTeacher");
	if (GetLastError() == ERROR_ALREADY_EXISTS) return FALSE;

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

	CFgTeacherDlg dlg;
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
