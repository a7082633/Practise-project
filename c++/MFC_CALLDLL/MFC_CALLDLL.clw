; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_CALLDLLDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_CALLDLL.h"

ClassCount=4
Class1=CMFC_CALLDLLApp
Class2=CMFC_CALLDLLDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_CALLDLL_DIALOG

[CLS:CMFC_CALLDLLApp]
Type=0
HeaderFile=MFC_CALLDLL.h
ImplementationFile=MFC_CALLDLL.cpp
Filter=N

[CLS:CMFC_CALLDLLDlg]
Type=0
HeaderFile=MFC_CALLDLLDlg.h
ImplementationFile=MFC_CALLDLLDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_CALLDLLDlg.h
ImplementationFile=MFC_CALLDLLDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_CALLDLL_DIALOG]
Type=1
Class=CMFC_CALLDLLDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BTN_MAX,button,1342242816
Control4=IDC_BTN_MIN,button,1342242816

