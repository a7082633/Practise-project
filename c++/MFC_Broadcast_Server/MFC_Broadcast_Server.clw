; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_Broadcast_ServerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_Broadcast_Server.h"

ClassCount=4
Class1=CMFC_Broadcast_ServerApp
Class2=CMFC_Broadcast_ServerDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG_SENGMSG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_MFC_BROADCAST_SERVER_DIALOG
Class4=CDialogSendMSG
Resource5=IDR_MENU_LIST

[CLS:CMFC_Broadcast_ServerApp]
Type=0
HeaderFile=MFC_Broadcast_Server.h
ImplementationFile=MFC_Broadcast_Server.cpp
Filter=N

[CLS:CMFC_Broadcast_ServerDlg]
Type=0
HeaderFile=MFC_Broadcast_ServerDlg.h
ImplementationFile=MFC_Broadcast_ServerDlg.cpp
Filter=C
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_Broadcast_ServerDlg.h
ImplementationFile=MFC_Broadcast_ServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_BROADCAST_SERVER_DIALOG]
Type=1
Class=CMFC_Broadcast_ServerDlg
ControlCount=5
Control1=IDC_BTB_STOP,button,1342242817
Control2=IDC_BTB_START,button,1342242816
Control3=IDC_STATIC_NOH,static,1342308352
Control4=IDC_LIST,SysListView32,1350631425
Control5=IDC_BTN_FLUSH,button,1342242816

[MNU:IDR_MENU_LIST]
Type=1
Class=?
Command1=IDC_MENU_SENDMSG
Command2=IDC_MENU_SEESCREEN
CommandCount=2

[DLG:IDD_DIALOG_SENGMSG]
Type=1
Class=CDialogSendMSG
ControlCount=2
Control1=IDC_EDIT_MSG,edit,1350631552
Control2=IDOK,button,1342242817

[CLS:CDialogSendMSG]
Type=0
HeaderFile=DialogSendMSG.h
ImplementationFile=DialogSendMSG.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogSendMSG
VirtualFilter=dWC

