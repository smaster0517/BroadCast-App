; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIOCPDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "iocp.h"
LastPage=0

ClassCount=5
Class1=CHistoryEdit
Class2=CIOCPApp
Class3=CIOCPDlg
Class4=IOCPSettingsDlg
Class5=MyListCtrl

ResourceCount=2
Resource1=IDD_IOCP_DIALOG (Neutral)
Resource2=IDD_SETTINGS (Neutral)

[CLS:CHistoryEdit]
Type=0
BaseClass=CEdit
HeaderFile=HistoryEdit.h
ImplementationFile=HistoryEdit.cpp
LastObject=CHistoryEdit

[CLS:CIOCPApp]
Type=0
BaseClass=CWinApp
HeaderFile=IOCP.h
ImplementationFile=IOCP.cpp

[CLS:CIOCPDlg]
Type=0
BaseClass=CDialog
HeaderFile=IOCPDlg.h
ImplementationFile=IOCPDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CIOCPDlg

[CLS:IOCPSettingsDlg]
Type=0
BaseClass=CDialog
HeaderFile=IOCPSettingsDlg.h
ImplementationFile=IOCPSettingsDlg.cpp

[CLS:MyListCtrl]
Type=0
BaseClass=CListCtrl
HeaderFile=MyListCtrl.h
ImplementationFile=MyListCtrl.cpp

[DLG:IDD_IOCP_DIALOG]
Type=1
Class=CIOCPDlg

[DLG:IDD_SETTINGS]
Type=1
Class=IOCPSettingsDlg

[DLG:IDD_IOCP_DIALOG (Neutral)]
Type=1
Class=CIOCPDlg
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDC_CLIENTLIST,SysListView32,1350633485
Control3=IDC_ADRESS,edit,1350631552
Control4=IDC_DISCONNECTALL,button,1342242816
Control5=IDC_DISCONNECT,button,1342242816
Control6=IDC_SEND,button,1342242816
Control7=IDC_SENDTXT,edit,1350632644
Control8=IDC_RECEIVEDTXT,edit,1350634692
Control9=IDC_STATIC,static,1342308352
Control10=IDC_FLOOD,button,1342242819
Control11=IDC_LOGG,edit,1352731716
Control12=IDC_MSGPERSEC,edit,1342244992
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STOPSTART,button,1342242816
Control15=IDC_Settings,button,1476460544
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_SENDFILE,button,1342242816
Control19=IDC_RANDOMDISCONNECT,button,1342242819

[DLG:IDD_SETTINGS (Neutral)]
Type=1
Class=?
ControlCount=19
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_PORTNR,edit,1350631552
Control4=IDC_MAXNUMOFCONNECTION,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_NROFIOWORKERS,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_NROFLOGICWORKERS,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_NROFFREEBUFF,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_NROFFREECONTEXT,edit,1350631552
Control14=IDC_RECEIVEDORDERED,button,1342251011
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_SENDORDERED,button,1342242819
Control18=IDC_NRPENDLINGREAD,edit,1350631552
Control19=IDC_STATIC,static,1342308352

