; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFgTeacherDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FgTeacher.h"

ClassCount=3
Class1=CFgTeacherApp
Class2=CFgTeacherDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_FGTEACHER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDR_TRAY_MENU

[CLS:CFgTeacherApp]
Type=0
HeaderFile=FgTeacher.h
ImplementationFile=FgTeacher.cpp
Filter=N

[CLS:CFgTeacherDlg]
Type=0
HeaderFile=FgTeacherDlg.h
ImplementationFile=FgTeacherDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDM_DRAY_START

[CLS:CAboutDlg]
Type=0
HeaderFile=FgTeacherDlg.h
ImplementationFile=FgTeacherDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC_IP,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FGTEACHER_DIALOG]
Type=1
Class=CFgTeacherDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[MNU:IDR_TRAY_MENU]
Type=1
Class=CFgTeacherDlg
Command1=IDM_DRAY_START
Command2=IDM_DRAY_STOP
Command3=IDM_DRAY_ABOUT
Command4=IDM_DRAY_EXIT
CommandCount=4

