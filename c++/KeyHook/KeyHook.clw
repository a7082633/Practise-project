; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKeyHookDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "KeyHook.h"

ClassCount=4
Class1=CKeyHookApp
Class2=CKeyHookDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_KEYHOOK_DIALOG

[CLS:CKeyHookApp]
Type=0
HeaderFile=KeyHook.h
ImplementationFile=KeyHook.cpp
Filter=N

[CLS:CKeyHookDlg]
Type=0
HeaderFile=KeyHookDlg.h
ImplementationFile=KeyHookDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=KeyHookDlg.h
ImplementationFile=KeyHookDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_KEYHOOK_DIALOG]
Type=1
Class=CKeyHookDlg
ControlCount=3
Control1=ID_HOOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

