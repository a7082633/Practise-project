; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLogin
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_DIALOG.h"

ClassCount=4
Class1=CMFC_DIALOGApp
Class2=CMFC_DIALOGDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_MFC_DIALOG_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CLogin
Resource4=IDD_DIALOG1

[CLS:CMFC_DIALOGApp]
Type=0
HeaderFile=MFC_DIALOG.h
ImplementationFile=MFC_DIALOG.cpp
Filter=N

[CLS:CMFC_DIALOGDlg]
Type=0
HeaderFile=MFC_DIALOGDlg.h
ImplementationFile=MFC_DIALOGDlg.cpp
Filter=D
LastObject=CMFC_DIALOGDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_DIALOGDlg.h
ImplementationFile=MFC_DIALOGDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_DIALOG_DIALOG]
Type=1
Class=CMFC_DIALOGDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG1]
Type=1
Class=CLogin
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

