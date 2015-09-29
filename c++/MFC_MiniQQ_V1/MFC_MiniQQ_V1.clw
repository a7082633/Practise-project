; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChatDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_MiniQQ_V1.h"

ClassCount=4
Class1=CMFC_MiniQQ_V1App
Class2=CMFC_MiniQQ_V1Dlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MFC_MINIQQ_V1_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CChatDialog
Resource4=IDD_FRIENDDIALOG

[CLS:CMFC_MiniQQ_V1App]
Type=0
HeaderFile=MFC_MiniQQ_V1.h
ImplementationFile=MFC_MiniQQ_V1.cpp
Filter=N

[CLS:CMFC_MiniQQ_V1Dlg]
Type=0
HeaderFile=MFC_MiniQQ_V1Dlg.h
ImplementationFile=MFC_MiniQQ_V1Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_MiniQQ_V1Dlg.h
ImplementationFile=MFC_MiniQQ_V1Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_MINIQQ_V1_DIALOG]
Type=1
Class=CMFC_MiniQQ_V1Dlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_HOSTNAME,static,1342308352
Control6=IDC_STATIC_HOSTIP,static,1342308352

[DLG:IDD_FRIENDDIALOG]
Type=1
Class=CChatDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST,listbox,1352728833

[CLS:CChatDialog]
Type=0
HeaderFile=ChatDialog.h
ImplementationFile=ChatDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST

