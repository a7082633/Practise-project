; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_MULTITHREADDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_MULTITHREAD.h"

ClassCount=4
Class1=CMFC_MULTITHREADApp
Class2=CMFC_MULTITHREADDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_MULTITHREAD_DIALOG

[CLS:CMFC_MULTITHREADApp]
Type=0
HeaderFile=MFC_MULTITHREAD.h
ImplementationFile=MFC_MULTITHREAD.cpp
Filter=N

[CLS:CMFC_MULTITHREADDlg]
Type=0
HeaderFile=MFC_MULTITHREADDlg.h
ImplementationFile=MFC_MULTITHREADDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_MULTITHREADDlg.h
ImplementationFile=MFC_MULTITHREADDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_MULTITHREAD_DIALOG]
Type=1
Class=CMFC_MULTITHREADDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_BTN_CREATE1,button,1342242816
Control3=IDC_BTN_SUSPEND1,button,1342242816
Control4=IDC_BTN_RESUM1,button,1342242816
Control5=IDC_BTN_EXIT,button,1342242816
Control6=IDC_BTN_CREATE2,button,1342242816
Control7=IDC_BTN_SUSPEND2,button,1342242816
Control8=IDC_BTN_RESUM2,button,1342242816
Control9=IDC_BTN_EXIT2,button,1342242816
Control10=IDC_BTN_EXITTHREAD,button,1342242816

