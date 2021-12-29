// DlgTestAudio.cpp : implementation file
//

/*/
	written for E-MED INNOVATIONS INC. by E-MED INNOVATIONS INC.
						08/2001
				http://www.e-medsounds.com
				mailto://pcanthelou@e-medsounds.com
/*/

#include "stdafx.h"
#include "..\IOCP.h"
#include "DlgTestAudio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDlgTestAudio dialog
CString g_strStatus[] = { _T("Now idle!"),_T("Now playing!") ,_T("Now playing puased!") ,_T("Now recording!") ,_T("Now recording paused!") };

CDlgTestAudio::CDlgTestAudio(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTestAudio::IDD, pParent)
	, m_nowStrStatus(_T(""))
{
	//{{AFX_DATA_INIT(CDlgTestAudio)
	m_fileName = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_isPropDevice = FALSE;
	
	m_brBckColor.CreateSolidBrush(RGB(29, 28, 31));
}

void CDlgTestAudio::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTestAudio)
	DDX_Control(pDX, IDC_COMBO_DEVICES, m_comboDevices);
	DDX_Text(pDX, IDC_FILENAME, m_fileName);
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDITSTATUS, m_nowStrStatus);
}

BEGIN_MESSAGE_MAP(CDlgTestAudio, CDialog)
	//{{AFX_MSG_MAP(CDlgTestAudio)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PLAYSINE, OnButtonPlaysine)
	ON_BN_CLICKED(IDC_BUTTON_PLAYPAUSE, OnButtonPlaypause)
	ON_BN_CLICKED(IDC_BUTTON_PLAYCONTINUE, OnButtonPlaycontinue)
	ON_BN_CLICKED(IDC_BUTTON_PLAYSTOP, OnButtonPlaystop)
	ON_BN_CLICKED(IDC_BUTTON_RECORD, OnButtonRecord)
	ON_BN_CLICKED(IDC_BUTTON_RECPAUSE, OnButtonRecpause)
	ON_BN_CLICKED(IDC_BUTTON_RECCONTINUE, OnButtonReccontinue)
	ON_BN_CLICKED(IDC_BUTTON_RECSTOP, OnButtonRecstop)
	ON_BN_CLICKED(IDC_CHANGEFILE, OnChangefile)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CDlgTestAudio::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDlgTestAudio::OnBnClickedCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTestAudio message handlers

BOOL CDlgTestAudio::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	//ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	//ASSERT(IDM_ABOUTBOX < 0xF000);

	//CMenu* pSysMenu = GetSystemMenu(FALSE);
	//if (pSysMenu != NULL)
	//{
	//	CString strAboutMenu;
	//	strAboutMenu.LoadString(IDS_ABOUTBOX);
	//	if (!strAboutMenu.IsEmpty())
	//	{
	//		pSysMenu->AppendMenu(MF_SEPARATOR);
	//		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	//	}
	//}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_btnRecord.SubclassDlgItem(IDC_BUTTON_RECORD, this);
	m_btnRecord.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnRecord.SetButtonText("Record");
	//m_btnRecord.SetFont("Arial", 16);
	m_btnRecord.SetTextColor(RGB(0, 255, 0), RGB(255, 0, 0));
	
	m_btnPlay.SubclassDlgItem(IDC_BUTTON_PLAY, this);
	//m_btnPlay.SetButtonImg(IDB_PLAYU, IDB_PLAYD, IDB_PLAYX);
	//m_btnPlay.SubclassDlgItem(IDC_BUTTON_PLAY, this);
	m_btnPlay.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnPlay.SetButtonText("Play");
	//m_btnPlay.SetFont("Arial", 16);
	m_btnPlay.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	
	m_btnPlayContinue.SubclassDlgItem(IDC_BUTTON_PLAYCONTINUE, this);
	//m_btnPlayContinue.SetButtonImg(IDB_STRTU, IDB_STRTD, IDB_STRTX);
	m_btnPlayContinue.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnPlayContinue.SetButtonText("Continue");
	//m_btnPlayContinue.SetFont("Arial", 14);
	//m_btnPlayContinue.SetTextPosition(7, 3);
	m_btnPlayContinue.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	m_btnPlayContinue.EnableWindow(FALSE);
	
	m_btnRecordContinue.SubclassDlgItem(IDC_BUTTON_RECCONTINUE, this);
	//m_btnRecordContinue.SetButtonImg(IDB_STRTU, IDB_STRTD, IDB_STRTX);
	m_btnRecordContinue.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnRecordContinue.SetButtonText("Continue");
	//m_btnRecordContinue.SetFont("Arial", 14);
	//m_btnRecordContinue.SetTextPosition(7, 3);
	m_btnRecordContinue.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	m_btnRecordContinue.EnableWindow(FALSE);
	
	m_btnPlayPause.SubclassDlgItem(IDC_BUTTON_PLAYPAUSE, this);
	m_btnPlayPause.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnPlayPause.SetButtonText("Pause");
	//m_btnPlayPause.SetFont("Arial", 16);
	m_btnPlayPause.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	m_btnPlayPause.EnableWindow(FALSE);
	
	m_btnRecordPause.SubclassDlgItem(IDC_BUTTON_RECPAUSE, this);
	m_btnRecordPause.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnRecordPause.SetButtonText("Pause");
	//m_btnRecordPause.SetFont("Arial", 16);
	m_btnRecordPause.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	m_btnRecordPause.EnableWindow(FALSE);
	
	m_btnPlayStop.SubclassDlgItem(IDC_BUTTON_PLAYSTOP, this);
	m_btnPlayStop.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnPlayStop.SetButtonText("Stop");
	//m_btnPlayStop.SetFont("Arial", 16);
	m_btnPlayStop.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	m_btnPlayStop.EnableWindow(0);
	
	m_btnRecordStop.SubclassDlgItem(IDC_BUTTON_RECSTOP, this);
	m_btnRecordStop.SetButtonImg(IDB_OKU, IDB_OKD);
	m_btnRecordStop.SetButtonText("Stop");
	//m_btnRecordStop.SetFont("Arial", 16);
	m_btnRecordStop.SetTextColor(RGB(0, 255, 0), RGB(129, 129, 129));
	m_btnRecordStop.EnableWindow(0);
	
	m_nStatus = NOW_IDLE;//m_isRecorded = FALSE;
	m_nowStrStatus = g_strStatus[m_nStatus]; //_T("Now idle!");
	UpdateData(FALSE);

	UINT i = 0;
	for (i = 0; i < CWaveInterface::GetWaveInCount(); i++) {
		if (!CWaveInterface::GetWaveInName(i).IsEmpty())
			m_comboDevices.AddString(CWaveInterface::GetWaveInName(i));
	}
	for (i = 0; i < CWaveInterface::GetWaveOutCount(); i++) {
		if (!CWaveInterface::GetWaveOutName(i).IsEmpty())
			m_comboDevices.AddString(CWaveInterface::GetWaveOutName(i));
	}
	Faire();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgTestAudio::OnSysCommand(UINT nID, LPARAM lParam)
{
	//if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	//{
	//	CAboutDlg dlgAbout;
	//	dlgAbout.DoModal();
	//}
	//else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgTestAudio::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		CRect rectArea;
		GetClientRect(&rectArea);
		dc.FillRect(rectArea.operator LPRECT(), &m_brBckColor);
		//CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgTestAudio::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgTestAudio::Faire()
{
}


void CDlgTestAudio::OnButtonPlaysine() 
{
	UpdateData();
	if (m_nStatus == NOW_RECORDING || m_nStatus == NOW_RECORDING_PAUSED)
	{
		AfxMessageBox("Now recording! Please stop recording and save it first!");
		return;
	}
	//else if (m_nStatus == NOW_PLAYING || m_nStatus == NOW_PLAYING_PAUSED)
	//{
	//	AfxMessageBox("Now playing! Please stop playing!");
	//	return;
	//}

	if ( m_fileName.GetLength() > 0 )
	{
		if ( waveOut.IsPlaying() ) {
			if ( !waveOut.Close() ) {
				AfxMessageBox( waveOut.GetError() );
				return;
			}
		}
		monWave.Load( m_fileName );
		if ( !monDevice.IsOutputFormat(monWave) ) {
			AfxMessageBox("Format not supported!");
			return;
		}
		waveOut.SetWave(monWave);
		waveOut.SetDevice(monDevice);
		if ( !waveOut.Open() ) {
			AfxMessageBox( waveOut.GetError() );
			return;
		}
		if ( !waveOut.Play() ) {
			AfxMessageBox( waveOut.GetError() );
			return;
		}
	}
	else {
		AfxMessageBox("Select an audio file first!");
		return;
	}
	m_nStatus = NOW_PLAYING;
	m_nowStrStatus = g_strStatus[m_nStatus];
	//m_btnPlay.SetTextColor(RGB(255, 0, 0), RGB(129, 129, 129));

	m_btnPlay.EnableWindow(1);
	m_btnPlayPause.EnableWindow(1);
	m_btnPlayStop.EnableWindow(1);
	m_btnPlayContinue.EnableWindow(0);

	/*m_btnRecord.EnableWindow(0);
	m_btnRecordPause.EnableWindow(0);
	m_btnRecordContinue.EnableWindow(0);
	m_btnRecordStop.EnableWindow(0);*/
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonPlaypause() 
{
	UpdateData();
	if (m_nStatus != NOW_PLAYING)
	{
		AfxMessageBox("Nothing playing!");
		return;
	}

	if ( !waveOut.Pause() ) {
		AfxMessageBox( waveOut.GetError() );
	}

	m_nStatus = NOW_PLAYING_PAUSED;
	m_nowStrStatus = g_strStatus[m_nStatus];
	m_btnPlay.EnableWindow(1);
	m_btnPlayPause.EnableWindow(0);
	m_btnPlayContinue.EnableWindow(1);
	m_btnPlayStop.EnableWindow(1);
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonPlaycontinue() 
{
	UpdateData();
	if (m_nStatus != NOW_PLAYING_PAUSED)
	{
		AfxMessageBox("Nothing playing paused!");
		return;
	}

	if ( !waveOut.Continue() ) {
		AfxMessageBox( waveOut.GetError() );
	}

	m_nStatus = NOW_PLAYING;
	m_nowStrStatus = g_strStatus[m_nStatus];
	m_btnPlay.EnableWindow(1);
	m_btnPlayPause.EnableWindow(1);
	m_btnPlayContinue.EnableWindow(0);
	m_btnPlayStop.EnableWindow(1);
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonPlaystop() 
{
	UpdateData();
	if (m_nStatus != NOW_PLAYING_PAUSED && m_nStatus != NOW_PLAYING)
	{
		AfxMessageBox("Nothing playing or paused!");
		return;
	}

	if ( !waveOut.Close() ) {
		AfxMessageBox( waveOut.GetError() );
	}

	m_nStatus = NOW_IDLE;
	m_nowStrStatus = g_strStatus[m_nStatus];
	m_btnPlay.EnableWindow(1);
	m_btnPlayPause.EnableWindow(0);
	m_btnPlayContinue.EnableWindow(0);
	m_btnPlayStop.EnableWindow(0);

	/*m_btnRecord.EnableWindow(1);
	m_btnRecordPause.EnableWindow(0);
	m_btnRecordContinue.EnableWindow(0);
	m_btnRecordStop.EnableWindow(0);*/
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonRecord() 
{
	UpdateData();
	if (m_nStatus == NOW_RECORDING || m_nStatus == NOW_RECORDING_PAUSED)
	{
		AfxMessageBox("Now recording. Stop recording and save it first!");		
		return;
	}
	//else if (m_nStatus == NOW_PLAYING || m_nStatus == NOW_PLAYING_PAUSED)
	//{
	//	AfxMessageBox("Now playing! Please stop playing!");
	//	return;
	//}

	if ( waveOut.IsPlaying() ) {
		if ( !waveOut.Close() ) {
			AfxMessageBox( waveOut.GetError() );
			return;
		}
	}
	monWave.BuildFormat(1, 8000, 16);
	if ( !monDevice.IsInputFormat(monWave) ) {
		AfxMessageBox("Format not supported!");
		m_isPropDevice = FALSE;
		return;
	}
	waveIn.SetWaveFormat( monWave.GetFormat() );
	waveIn.SetDevice(monDevice);
	if ( !waveIn.Open() ) {
		AfxMessageBox( waveIn.GetError() );
		return;
	}
	m_isPropDevice = TRUE;
	if ( !waveIn.Record() ) {
		AfxMessageBox( waveIn.GetError() );
		return;
	}
	//m_isRecorded = TRUE;

	m_nStatus = NOW_RECORDING;
	m_nowStrStatus = g_strStatus[m_nStatus];

	m_btnPlay.EnableWindow(0);
	m_btnPlayPause.EnableWindow(0);
	m_btnPlayContinue.EnableWindow(0);
	m_btnPlayStop.EnableWindow(0);

	m_btnRecord.EnableWindow(0);
	m_btnRecordPause.EnableWindow(1);
	m_btnRecordContinue.EnableWindow(0);
	m_btnRecordStop.EnableWindow(1);
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonRecpause() 
{
	UpdateData();
	if (m_nStatus != NOW_RECORDING)
	{
		AfxMessageBox("Nothing recording!");
		return;
	}

	if ( !waveIn.Pause() ) {
		AfxMessageBox( waveIn.GetError() );
		return;
	}
	m_nStatus = NOW_RECORDING_PAUSED;
	m_nowStrStatus = g_strStatus[m_nStatus];

	m_btnRecord.EnableWindow(0);
	m_btnRecordPause.EnableWindow(0);
	m_btnRecordContinue.EnableWindow(1);
	m_btnRecordStop.EnableWindow(1);
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonReccontinue() 
{
	UpdateData();
	if (m_nStatus != NOW_RECORDING_PAUSED)
	{
		AfxMessageBox("Nothing recording paused!");
		return;
	}

	if ( !waveIn.Continue() ) {
		AfxMessageBox( waveIn.GetError() );
		return;
	}

	m_nStatus = NOW_RECORDING;
	m_nowStrStatus = g_strStatus[m_nStatus];

	m_btnRecord.EnableWindow(0);
	m_btnRecordPause.EnableWindow(1);
	m_btnRecordContinue.EnableWindow(0);
	m_btnRecordStop.EnableWindow(1);
	UpdateData(FALSE);
}

void CDlgTestAudio::OnButtonRecstop() 
{
	UpdateData();
	if (m_nStatus != NOW_RECORDING_PAUSED && m_nStatus != NOW_RECORDING)
	{
		AfxMessageBox("Nothing recording or paused!");
		return;
	}
	/*if(!m_isRecorded)
	{
		AfxMessageBox("Record an audio first!");
		return;
	}*/

	if ( !waveIn.Close() ) {
		AfxMessageBox( waveIn.GetError() );
		return;
	}
	if (!m_isPropDevice) {
		AfxMessageBox("Select proper recording device first!");
		return;
	}
	
	monWave = waveIn.MakeWave();
	//CString newFileName;
	CFileDialog fileDlg(
		FALSE,
		_T("wav"),
		0,
		OFN_OVERWRITEPROMPT | OFN_CREATEPROMPT,
		_T("Wave Files (*.wav)|*.wav||")
		);
	if (fileDlg.DoModal() == IDOK)
	{
		m_fileName = fileDlg.GetPathName();//GetFileName();
		UpdateData(FALSE);
	}
	else {
		AfxMessageBox("Enter a correct file name!");
		return;
	}
		

	monWave.Save(m_fileName);//"Ade.wav");
	AfxMessageBox("Saved as " + m_fileName +/*Ade.wav*/ "succesfully!");
	
	m_nStatus = NOW_IDLE;
	m_nowStrStatus = g_strStatus[m_nStatus];

	m_btnRecord.EnableWindow(1);
	m_btnRecordPause.EnableWindow(0);
	m_btnRecordContinue.EnableWindow(0);
	m_btnRecordStop.EnableWindow(0);

	m_btnPlay.EnableWindow(1);
	m_btnPlayPause.EnableWindow(0);
	m_btnPlayContinue.EnableWindow(0);
	m_btnPlayStop.EnableWindow(0);

	UpdateData(FALSE);

	//m_isRecorded = FALSE;
}

void CDlgTestAudio::OnChangefile() 
{
	CFileDialog fileDlg(
		TRUE,
		_T("wav"),
		0,
		OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST,
		_T("Wave Files (*.wav)|*.wav||")
		);
	if ( fileDlg.DoModal() == IDOK )
	{
		m_fileName = fileDlg.GetFileName();
		UpdateData(FALSE);
	}
}


void CDlgTestAudio::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (m_nStatus == NOW_RECORDING_PAUSED || m_nStatus == NOW_RECORDING)
	{
		AfxMessageBox("Now recording! Stop recroding and save first!");
		return;
	}
	CDialog::OnOK();
}


void CDlgTestAudio::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	if (m_nStatus == NOW_RECORDING_PAUSED || m_nStatus == NOW_RECORDING)
	{
		AfxMessageBox("Now recording! Stop recroding and save first!");
		return;
	}
	CDialog::OnCancel();
}
