// IOCP.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "IOCP.h"
#include "IOCPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIOCPApp

BEGIN_MESSAGE_MAP(CIOCPApp, CWinApp)
	//{{AFX_MSG_MAP(CIOCPApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIOCPApp construction

CIOCPApp::CIOCPApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CIOCPApp object

CIOCPApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CIOCPApp initialization

BOOL CIOCPApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	SetRegistryKey(_T("Ade's broadcast software - server"));
	

	try {
		HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, 0, (LPCSTR)"Ade's server");// Try to open the mutex.

		if (!hMutex)
			hMutex = CreateMutex(0, 0, (LPCSTR)"Ade's server");// Mutex doesn’t exist. This is the first instance so create the mutex.
		else
			return 0;// The mutex exists so this is the the second instance so return.

		ReleaseMutex(hMutex);
		AfxThrowUserException();
	}
	catch (CException* e) {
		//messagebox if needed: e->GetErrorMessage()		
		e->Delete();
	}

	CIOCPDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
