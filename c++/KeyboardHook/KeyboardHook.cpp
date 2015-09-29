// KeyboardHook.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#include "KeyboardHook.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#pragma data_seg("mydata")
      HHOOK glhHook=NULL;         //安装的鼠标勾子句柄 
      HINSTANCE glhInstance=NULL; //DLL实例句柄
#pragma data_seg()

static AFX_EXTENSION_MODULE KeyboardHookDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	glhInstance=hInstance;//插入保存DLL实例句柄
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("KEYBOARDHOOK.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(KeyboardHookDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(KeyboardHookDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("KEYBOARDHOOK.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(KeyboardHookDLL);
	}
	return 1;   // ok
}

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam)
{
      char ch=0;
      if( ((DWORD)lParam&0x40000000) && (HC_ACTION==nCode) ) //有键按下
      {
            if( (wParam==VK_SPACE)||(wParam==VK_RETURN)||(wParam>=0x2f ) &&(wParam<=0x100) )
            {
				if(VK_F1==wParam)
				{
					AfxMessageBox("THIS IS F1");
					return 0;
				}
            }
      }
      return CallNextHookEx( glhHook, nCode, wParam, lParam ); 
}

CKeyboardHook::CKeyboardHook()
{
}

CKeyboardHook::~CKeyboardHook()
{
      if(glhHook)
            UnhookWindowsHookEx(glhHook);
}

//安装钩子并设定接收显示窗口句柄
BOOL CKeyboardHook::StartHook()
{ 
      BOOL bResult=FALSE;
      glhHook=SetWindowsHookEx(WH_KEYBOARD,KeyboardProc,glhInstance,0);
      /*============================================================
      HHOOK SetWindowsHookEx( int idHook,HOOKPROC lpfn, INSTANCE hMod,DWORD dwThreadId )
      参数idHook表示钩子类型，它是和钩子函数类型一一对应的。
      比如，WH_KEYBOARD表示安装的是键盘钩子，WH_MOUSE表示是鼠标钩子等等。 

      Lpfn是钩子函数的地址。 

      HMod是钩子函数所在的实例的句柄。对于线程钩子，该参数为NULL；对于系统钩子，
      该参数为钩子函数所在的DLL句柄。 

      dwThreadId 指定钩子所监视的线程的线程号。对于全局钩子，该参数为NULL。 

      SetWindowsHookEx返回所安装的钩子句柄。
      值得注意的是线程钩子和系统钩子的钩子函数的位置有很大的差别。
      线程钩子一般在当前线程或者当前线程派生的线程内，
      而系统钩子必须放在独立的动态链接库中，实现起来要麻烦一些。
      ===========================================================*/
      if(glhHook!=NULL)
      bResult=TRUE;
      return bResult; 
}
//卸载钩子
BOOL CKeyboardHook::StopHook() 
{
      BOOL bResult=FALSE;
      if(glhHook)
      {
            bResult= UnhookWindowsHookEx(glhHook);
            if(bResult)
                  glhHook=NULL;
      }
      return bResult;
}
