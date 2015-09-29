; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_FILESDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_FILES.h"

ClassCount=4
Class1=CMFC_FILESApp
Class2=CMFC_FILESDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_FILES_DIALOG

[CLS:CMFC_FILESApp]
Type=0
HeaderFile=MFC_FILES.h
ImplementationFile=MFC_FILES.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMFC_FILESDlg]
Type=0
HeaderFile=MFC_FILESDlg.h
ImplementationFile=MFC_FILESDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_FILESDlg.h
ImplementationFile=MFC_FILESDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_FILES_DIALOG]
Type=1
Class=CMFC_FILESDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

