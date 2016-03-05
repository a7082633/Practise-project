; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLoginDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_MINIQQ.h"

ClassCount=8
Class1=CMFC_MINIQQApp
Class2=CMFC_MINIQQDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_MFC_MINIQQ_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CLoginDlg
Resource4=IDD_DIALOG1
Class5=CChatDialog
Resource5=IDD_CHAT_DLG
Class6=CMyButton
Class7=CCCCCCCCCC
Class8=CMyWinThread
Resource6=IDR_MENU

[CLS:CMFC_MINIQQApp]
Type=0
HeaderFile=MFC_MINIQQ.h
ImplementationFile=MFC_MINIQQ.cpp
Filter=N

[CLS:CMFC_MINIQQDlg]
Type=0
HeaderFile=MFC_MINIQQDlg.h
ImplementationFile=MFC_MINIQQDlg.cpp
Filter=D
LastObject=IDC_LIST1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_MINIQQDlg.h
ImplementationFile=MFC_MINIQQDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_MINIQQ_DIALOG]
Type=1
Class=CMFC_MINIQQDlg
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631425

[DLG:IDD_DIALOG1]
Type=1
Class=CLoginDlg
ControlCount=16
Control1=IDC_EDIT_USERNAME,edit,1350631552
Control2=IDOK,button,1342242816
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_PASSWORD,edit,1350631584
Control7=IDC_STATIC_ERROR,static,1073872896
Control8=IDC_BTN_EXCHANGE,button,1342242816
Control9=IDC_RADIO_RED,button,1342177289
Control10=IDC_RADIO_GREEN,button,1342177289
Control11=IDC_RADIO_BLUE,button,1342177289
Control12=IDC_RADIO_OTHER,button,1342177289
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC_COLOR,button,1073741831
Control15=IDC_BUTTON_B1,button,1342242816
Control16=IDC_BUTTON_B2,button,1342242816

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=C
LastObject=IDC_BUTTON_B1
VirtualFilter=dWC

[DLG:IDD_CHAT_DLG]
Type=1
Class=CChatDialog
ControlCount=4
Control1=IDR_BTN_SEND,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_INFO,edit,1352728580
Control4=IDC_EDIT_MSG,edit,1350631552

[CLS:CChatDialog]
Type=0
HeaderFile=ChatDialog.h
ImplementationFile=ChatDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDD_MENU_ZI
VirtualFilter=dWC

[MNU:IDR_MENU]
Type=1
Class=?
Command1=IDD_MENU_ZI
Command2=IDD_MENU_TEST2
CommandCount=2

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

[CLS:CCCCCCCCCC]
Type=0
HeaderFile=CCCCCCCCC.h
ImplementationFile=CCCCCCCCC.cpp
BaseClass=CButton
Filter=W

[CLS:CMyWinThread]
Type=0
HeaderFile=MyWinThread.h
ImplementationFile=MyWinThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=IDD_MENU_ZI

