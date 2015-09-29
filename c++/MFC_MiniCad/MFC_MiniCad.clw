; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_MiniCad.h"
LastPage=0

ClassCount=5
Class1=CMFC_MiniCadApp
Class2=CMFC_MiniCadDoc
Class3=CMFC_MiniCadView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDR_TOOLBAR1
Resource3=IDD_ABOUTBOX

[CLS:CMFC_MiniCadApp]
Type=0
HeaderFile=MFC_MiniCad.h
ImplementationFile=MFC_MiniCad.cpp
Filter=N

[CLS:CMFC_MiniCadDoc]
Type=0
HeaderFile=MFC_MiniCadDoc.h
ImplementationFile=MFC_MiniCadDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMFC_MiniCadDoc

[CLS:CMFC_MiniCadView]
Type=0
HeaderFile=MFC_MiniCadView.h
ImplementationFile=MFC_MiniCadView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_BTN_COLOR


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_OPEN
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_MiniCad.cpp
ImplementationFile=MFC_MiniCad.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_DRAW_NONE
Command18=ID_DRAW_LINE
Command19=ID_DRAW_RECT
Command20=ID_DRAW_EILL
Command21=ID_DRAW_COLOR
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_DRAW_LINE
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_PRINT
Command6=ID_FILE_SAVE
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_DRAW_NONE
Command2=ID_DRAW_LINE
Command3=ID_DRAW_RECT
Command4=ID_DRAW_EILL
Command5=ID_DRAW_COLOR
Command6=ID_BTN_L1
Command7=ID_BTN_L2
Command8=ID_BTN_L3
Command9=ID_BTN_COLOR
CommandCount=9

