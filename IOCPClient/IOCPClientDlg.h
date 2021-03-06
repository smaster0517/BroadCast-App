// IOCPClientDlg.h : header file
//

#if !defined(AFX_IOCPCLIENTDLG_H__4D989A18_3849_4786_B4FD_102DDDDAEA09__INCLUDED_)
#define AFX_IOCPCLIENTDLG_H__4D989A18_3849_4786_B4FD_102DDDDAEA09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIOCPClientDlg dialog
#include "MyListCtrl.h"
#include "HistoryEdit.h"
#include "MyIOCP.h"
#include "..\Tray\trayicon.h"
#include "IOCPSettingsDlg.h"

#define IniFileName "config.ini"
#define SECTION_NAME "ServerSection"
#define ADDRESS_FIELD "Address"
#define PORT_FIELD "Port"
#define NICKNAME_FIELD "NickName"
class CIOCPClientDlg : public CDialog
{
// Construction
public:
	CIOCPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIOCPClientDlg)
	enum { IDD = IDD_IOCPCLIENT_DIALOG };
	CHistoryEdit	m_CtrlLogg;
	MyListCtrl	m_CtrlClientList;
	CString	m_Adress;
	CString	m_sReceivedTxt;
	CString	m_sSendTxt;
	BOOL	m_bFlood;
	int		m_MsgPerSec;
	CString m_sDownloadFilePath;
	BOOL	m_bAutoReconnect;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIOCPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	MyIOCP m_iocp;
	IOCPSettingsDlg m_ConfigDlg;
	// Generated message map functions
	//{{AFX_MSG(CIOCPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnConnect();
	afx_msg void OnDestroy();
	afx_msg void OnDisconnectall();
	afx_msg void OnSend();
	afx_msg void OnDisconnect();
	afx_msg void OnClickClientlist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFlood();
	afx_msg void OnStopstart();
	afx_msg void OnSettings();
	afx_msg void OnAutoreconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdateClientData();
	void UpdateList();
	void EnableClientPanel();
	void DisableClientPanel();
	void DisableAllPanels();
	void EnableAllPanels();
	void StartTheSystem();
	LRESULT OnNewClient(WPARAM wParam, LPARAM lParam);
	LRESULT OnAppendLog(WPARAM wParam, LPARAM lParam);
	LRESULT OnClientDisconnected(WPARAM wParam, LPARAM lParam);
	LRESULT OnFileReceived(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnTrayNotification(WPARAM wp, LPARAM lp); //s_m
	static UINT TryConnectingThreadProc(LPVOID pParam);
	int m_ihTimer;
	int m_iCurrentClientID;
	CTrayIcon			m_tray;	//s_m

	// We put all the Context String2Pointer HashMap copy of ContextMapLock
	// used to update user info about the clients. 
	CCriticalSection m_GUIListLock;
	//CMapStringToPtr m_GUIContextMap;
	// The path which we download the file into. 	
public:
	// The port number to use when connecting 
	int m_iPort;
	// //NickName
	CString m_strNickName;
	afx_msg void OnMenuRestore();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnBnClickedOk();
	virtual void OnCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IOCPCLIENTDLG_H__4D989A18_3849_4786_B4FD_102DDDDAEA09__INCLUDED_)
