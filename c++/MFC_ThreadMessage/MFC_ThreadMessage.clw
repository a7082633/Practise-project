; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_ThreadMessageDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_ThreadMessage.h"

ClassCount=4
Class1=CMFC_ThreadMessageApp
Class2=CMFC_ThreadMessageDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_THREADMESSAGE_DIALOG

[CLS:CMFC_ThreadMessageApp]
Type=0
HeaderFile=MFC_ThreadMessage.h
ImplementationFile=MFC_ThreadMessage.cpp
Filter=N

[CLS:CMFC_ThreadMessageDlg]
Type=0
HeaderFile=MFC_ThreadMessageDlg.h
ImplementationFile=MFC_ThreadMessageDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_ThreadMessageDlg.h
ImplementationFile=MFC_ThreadMessageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_THREADMESSAGE_DIALOG]
Type=1
Class=CMFC_ThreadMessageDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_BTN_SEND,button,1342242816
Control3=IDC_BTN_QUIT,button,1342242816
Control4=IDC_BTN_CREATE,button,1342242816
Control5=IDC_EDIT1,edit,1350631552

