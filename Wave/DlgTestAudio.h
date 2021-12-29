// DlgTestAudio.h : header file
//

/*/
	written for E-MED INNOVATIONS INC. by E-MED INNOVATIONS INC.
						08/2001
				http://www.e-medsounds.com
				mailto://pcanthelou@e-medsounds.com
/*/

#if !defined(AFX_DLGTESTAUDIO_H__2F932D88_7872_45E7_8410_A5C532CFD9FF__INCLUDED_)
#define AFX_DLGTESTAUDIO_H__2F932D88_7872_45E7_8410_A5C532CFD9FF__INCLUDED_

#include "Wave.h"	// Added by ClassView
#include "WaveDevice.h"	// Added by ClassView
#include "../ImageButton/ImageTextButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgTestAudio dialog

#include "Wave.h"
#include "WaveDevice.h"
#include "WaveInterface.h"
#include "WaveOut.h"
#include "WaveIn.h"

class CDlgTestAudio : public CDialog
{
// Construction
public:
	CWaveIn waveIn;
	CWaveOut waveOut;
	CWaveDevice monDevice;
	CWave monWave;
	CDlgTestAudio(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTestAudio)
	enum { IDD = IDD_TESTAUDIO_DIALOG };
	CComboBox	m_comboDevices;
	CString	m_fileName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTestAudio)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgTestAudio)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonPlaysine();
	afx_msg void OnButtonPlaypause();
	afx_msg void OnButtonPlaycontinue();
	afx_msg void OnButtonPlaystop();
	afx_msg void OnButtonRecord();
	afx_msg void OnButtonRecpause();
	afx_msg void OnButtonReccontinue();
	afx_msg void OnButtonRecstop();
	afx_msg void OnChangefile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Faire();

	CImageTextButton	m_btnRecord;
	CImageTextButton	m_btnPlay;
	CImageTextButton	m_btnRecordPause;
	CImageTextButton	m_btnPlayPause;
	CImageTextButton	m_btnPlayContinue;
	CImageTextButton	m_btnRecordContinue;
	CImageTextButton	m_btnRecordStop;
	CImageTextButton	m_btnPlayStop;
	CBrush				m_brBckColor;

	enum { NOW_IDLE = 0, NOW_PLAYING , NOW_PLAYING_PAUSED, NOW_RECORDING, NOW_RECORDING_PAUSED };

	BOOL m_isPropDevice;
	int m_nStatus;
	CString m_nowStrStatus;
public:
	afx_msg void OnBnClickedOk();	
	afx_msg void OnBnClickedCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTESTAUDIO_H__2F932D88_7872_45E7_8410_A5C532CFD9FF__INCLUDED_)
