; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLIBUSB_TESTDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LIBUSB_TEST.h"

ClassCount=4
Class1=CLIBUSB_TESTApp
Class2=CLIBUSB_TESTDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LIBUSB_TEST_DIALOG

[CLS:CLIBUSB_TESTApp]
Type=0
HeaderFile=LIBUSB_TEST.h
ImplementationFile=LIBUSB_TEST.cpp
Filter=N

[CLS:CLIBUSB_TESTDlg]
Type=0
HeaderFile=LIBUSB_TESTDlg.h
ImplementationFile=LIBUSB_TESTDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=LIBUSB_TESTDlg.h
ImplementationFile=LIBUSB_TESTDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIBUSB_TEST_DIALOG]
Type=1
Class=CLIBUSB_TESTDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816

