; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChatDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_MiniQQ_V2.h"

ClassCount=7
Class1=CMFC_MiniQQ_V2App
Class2=CMFC_MiniQQ_V2Dlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_MFC_MINIQQ_V2_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_CHAT
Class4=CLoginDialog
Class5=CMySocket
Resource4=IDD_DIALOG_LOGIN
Class6=CChatDialog
Resource5=IDD_ABOUTBOX
Class7=CChatRoomDialog
Resource6=IDD_DIALOG_CHARROOM
Resource7=IDR_MENU

[CLS:CMFC_MiniQQ_V2App]
Type=0
HeaderFile=MFC_MiniQQ_V2.h
ImplementationFile=MFC_MiniQQ_V2.cpp
Filter=N

[CLS:CMFC_MiniQQ_V2Dlg]
Type=0
HeaderFile=MFC_MiniQQ_V2Dlg.h
ImplementationFile=MFC_MiniQQ_V2Dlg.cpp
Filter=D
LastObject=IDR_EXIT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_MiniQQ_V2Dlg.h
ImplementationFile=MFC_MiniQQ_V2Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_MINIQQ_V2_DIALOG]
Type=1
Class=CMFC_MiniQQ_V2Dlg
ControlCount=3
Control1=IDC_LIST,SysListView32,1350631425
Control2=IDC_BTN_UPDATE,button,1342242816
Control3=IDC_BTN_JOINCHATRM,button,1342242816

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CLoginDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342243584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_HOSTNAME,static,1342308352
Control6=IDC_STATIC_HOSTIP,static,1342308352

[CLS:CLoginDialog]
Type=0
HeaderFile=LoginDialog.h
ImplementationFile=LoginDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[CLS:CMySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q

[DLG:IDD_DIALOG_CHAT]
Type=1
Class=CChatDialog
ControlCount=11
Control1=IDC_EDIT_NEWMSG,edit,1352728580
Control2=IDC_BTN_SEND,button,1342242816
Control3=IDC_EDIT_OLDMSG,listbox,1352728833
Control4=IDC_BTN_BROWSER,button,1342242816
Control5=IDC_BTN_SENDF,button,1342242816
Control6=IDC_BTN_ACCEPT,button,1342242816
Control7=IDC_BTN_REJECT,button,1342242816
Control8=IDC_EDIT_SELECT,edit,1476462596
Control9=IDC_PROGRESS,msctls_progress32,1350565888
Control10=IDC_EDIT_SELECT2,edit,1476462596
Control11=IDC_PROGRESS2,msctls_progress32,1350565888

[CLS:CChatDialog]
Type=0
HeaderFile=ChatDialog.h
ImplementationFile=ChatDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_SELECT

[DLG:IDD_DIALOG_CHARROOM]
Type=1
Class=CChatRoomDialog
ControlCount=3
Control1=IDC_BTN_SEND,button,1342242817
Control2=IDC_EDIT_NEWMSG,edit,1352728580
Control3=IDC_EDIT_OLDMSG,listbox,1352728833

[CLS:CChatRoomDialog]
Type=0
HeaderFile=ChatRoomDialog.h
ImplementationFile=ChatRoomDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_OLDMSG
VirtualFilter=dWC

[MNU:IDR_MENU]
Type=1
Class=?
Command1=IDR_SHOWWD
Command2=IDR_EXIT
CommandCount=2

