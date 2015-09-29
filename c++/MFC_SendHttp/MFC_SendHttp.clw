; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_SendHttpDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_SendHttp.h"

ClassCount=4
Class1=CMFC_SendHttpApp
Class2=CMFC_SendHttpDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_SENDHTTP_DIALOG

[CLS:CMFC_SendHttpApp]
Type=0
HeaderFile=MFC_SendHttp.h
ImplementationFile=MFC_SendHttp.cpp
Filter=N

[CLS:CMFC_SendHttpDlg]
Type=0
HeaderFile=MFC_SendHttpDlg.h
ImplementationFile=MFC_SendHttpDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_SendHttpDlg.h
ImplementationFile=MFC_SendHttpDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_SENDHTTP_DIALOG]
Type=1
Class=CMFC_SendHttpDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_ADDR,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_DATA,edit,1350631552
Control5=IDC_BTN_SEND,button,1342242816

