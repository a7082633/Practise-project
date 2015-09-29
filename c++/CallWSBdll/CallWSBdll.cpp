// CallWSBdll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Windows.h"


typedef int(__stdcall *FXN)();
typedef int(__stdcall *FXN2)(HANDLE,char*);
typedef int(__stdcall *FXN3)(HANDLE,char*,char*,char*,char*,char*);
int main(int argc, char* argv[])
{
	HMODULE hModule=::LoadLibrary("WSB_RWInterface.dll");
	FXN OpenPort=(FXN)::GetProcAddress(hModule,"iDOpenPort");
	FXN ClosePort=(FXN)::GetProcAddress(hModule,"iDClosePort");
	FXN2 iVerifyPIN=(FXN2)::GetProcAddress(hModule,"iVerifyPIN");
	FXN3 iR_DDF1EF06Info=(FXN3)::GetProcAddress(hModule,"iR_DDF1EF06Info");
	int i=OpenPort();
	HANDLE hDev;
	i=iVerifyPIN(hDev,"1234");
	char XM[50]={0};
	char XB[50]={0};
	char MZ[50]={0};
	char CSRQ[50]={0};
	char SFZH[50]={0};
	i=iR_DDF1EF06Info(hDev,XM,XB,MZ,CSRQ,SFZH);
	ClosePort();
	return 0;
}

