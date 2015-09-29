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
      HHOOK glhHook=NULL;         //��װ����깴�Ӿ�� 
      HINSTANCE glhInstance=NULL; //DLLʵ�����
#pragma data_seg()

static AFX_EXTENSION_MODULE KeyboardHookDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	glhInstance=hInstance;//���뱣��DLLʵ�����
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
      if( ((DWORD)lParam&0x40000000) && (HC_ACTION==nCode) ) //�м�����
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

//��װ���Ӳ��趨������ʾ���ھ��
BOOL CKeyboardHook::StartHook()
{ 
      BOOL bResult=FALSE;
      glhHook=SetWindowsHookEx(WH_KEYBOARD,KeyboardProc,glhInstance,0);
      /*============================================================
      HHOOK SetWindowsHookEx( int idHook,HOOKPROC lpfn, INSTANCE hMod,DWORD dwThreadId )
      ����idHook��ʾ�������ͣ����Ǻ͹��Ӻ�������һһ��Ӧ�ġ�
      ���磬WH_KEYBOARD��ʾ��װ���Ǽ��̹��ӣ�WH_MOUSE��ʾ����깳�ӵȵȡ� 

      Lpfn�ǹ��Ӻ����ĵ�ַ�� 

      HMod�ǹ��Ӻ������ڵ�ʵ���ľ���������̹߳��ӣ��ò���ΪNULL������ϵͳ���ӣ�
      �ò���Ϊ���Ӻ������ڵ�DLL����� 

      dwThreadId ָ�����������ӵ��̵߳��̺߳š�����ȫ�ֹ��ӣ��ò���ΪNULL�� 

      SetWindowsHookEx��������װ�Ĺ��Ӿ����
      ֵ��ע������̹߳��Ӻ�ϵͳ���ӵĹ��Ӻ�����λ���кܴ�Ĳ��
      �̹߳���һ���ڵ�ǰ�̻߳��ߵ�ǰ�߳��������߳��ڣ�
      ��ϵͳ���ӱ�����ڶ����Ķ�̬���ӿ��У�ʵ������Ҫ�鷳һЩ��
      ===========================================================*/
      if(glhHook!=NULL)
      bResult=TRUE;
      return bResult; 
}
//ж�ع���
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
