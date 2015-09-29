; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMySocket
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_UDP_SYNC2_CHAT.h"

ClassCount=4
Class1=CMFC_UDP_SYNC2_CHATApp
Class2=CMFC_UDP_SYNC2_CHATDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMySocket
Resource3=IDD_MFC_UDP_SYNC2_CHAT_DIALOG

[CLS:CMFC_UDP_SYNC2_CHATApp]
Type=0
HeaderFile=MFC_UDP_SYNC2_CHAT.h
ImplementationFile=MFC_UDP_SYNC2_CHAT.cpp
Filter=N

[CLS:CMFC_UDP_SYNC2_CHATDlg]
Type=0
HeaderFile=MFC_UDP_SYNC2_CHATDlg.h
ImplementationFile=MFC_UDP_SYNC2_CHATDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_UDP_SYNC2_CHATDlg.h
ImplementationFile=MFC_UDP_SYNC2_CHATDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_UDP_SYNC2_CHAT_DIALOG]
Type=1
Class=CMFC_UDP_SYNC2_CHATDlg
ControlCount=4
Control1=IDC_BTN_SEND,button,1342242817
Control2=IDC_LIST1,listbox,1352728833
Control3=IDC_EDIT_IP,edit,1350631552
Control4=IDC_EDIT_MSG,edit,1350631552

[CLS:CMySocket]
Type=0
HeaderFile=MySocket.h
ImplementationFile=MySocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q

