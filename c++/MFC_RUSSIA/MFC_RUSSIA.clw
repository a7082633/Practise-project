; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_RUSSIA.h"
LastPage=0

ClassCount=5
Class1=CMFC_RUSSIAApp
Class2=CMFC_RUSSIADoc
Class3=CMFC_RUSSIAView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_GAMETOOLBAR
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX

[CLS:CMFC_RUSSIAApp]
Type=0
HeaderFile=MFC_RUSSIA.h
ImplementationFile=MFC_RUSSIA.cpp
Filter=N

[CLS:CMFC_RUSSIADoc]
Type=0
HeaderFile=MFC_RUSSIADoc.h
ImplementationFile=MFC_RUSSIADoc.cpp
Filter=N

[CLS:CMFC_RUSSIAView]
Type=0
HeaderFile=MFC_RUSSIAView.h
ImplementationFile=MFC_RUSSIAView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_GAME_SSPEED


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_RUSSIA.cpp
ImplementationFile=MFC_RUSSIA.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_GAME_NEW
Command2=ID_GAME_EXIT
Command3=ID_GAME_RESTART
Command4=ID_GAME_PAUSE
Command5=ID_GAME_RESUME
Command6=ID_GAME_ASPEED
Command7=ID_GAME_SSPEED
Command8=ID_VIEW_STATUS_BAR
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_GAMETOOLBAR]
Type=1
Class=?
Command1=ID_GAME_NEW
Command2=ID_GAME_EXIT
CommandCount=2

