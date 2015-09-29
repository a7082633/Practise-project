; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_FILECDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_FILEC.h"

ClassCount=3
Class1=CMFC_FILECApp
Class2=CMFC_FILECDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_FILEC_DIALOG

[CLS:CMFC_FILECApp]
Type=0
HeaderFile=MFC_FILEC.h
ImplementationFile=MFC_FILEC.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMFC_FILECDlg]
Type=0
HeaderFile=MFC_FILECDlg.h
ImplementationFile=MFC_FILECDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PROGRESS1

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_FILECDlg.h
ImplementationFile=MFC_FILECDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_FILEC_DIALOG]
Type=1
Class=CMFC_FILECDlg
ControlCount=2
Control1=IDC_BTN_START,button,1342242817
Control2=IDC_PROGRESS1,msctls_progress32,1350565888

