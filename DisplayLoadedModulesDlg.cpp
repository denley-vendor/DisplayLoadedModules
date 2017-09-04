/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : DisplayLoadedModulesDlg.cpp
    $Header: E:\SandBox/DisplayLoadedModules/DisplayLoadedModulesDlg.cpp,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:55:46 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Implementation of the DisplayLoadedModulesDlg Dialog

  ------------------------------ Modifications ------------------------------ 
    $Log: DisplayLoadedModulesDlg.cpp,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    ÏÔÊ¾³ÌÐòÒÀÀµÄ£¿é
  
  =========================================================================== 
*/

#include "stdafx.h"
#include "DisplayLoadedModules.h"
#include "DisplayLoadedModulesDlg.h"
#include "BuildModuleList.h"
#include "BuildProcessList.h"
#include "FileVersion.h"
#include "CListCtrlEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesDlg dialog

CDisplayLoadedModulesDlg::CDisplayLoadedModulesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDisplayLoadedModulesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDisplayLoadedModulesDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDisplayLoadedModulesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisplayLoadedModulesDlg)
	DDX_Control(pDX, IDC_COMBO_PROCESS, m_ComboProcess);
	DDX_Control(pDX, IDC_LIST_DLL, m_ListOfDLLs);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDisplayLoadedModulesDlg, CDialog)
	//{{AFX_MSG_MAP(CDisplayLoadedModulesDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_REFRESH_PROCESS, OnRefreshProcess)
	ON_CBN_SELENDOK(IDC_COMBO_PROCESS, OnSelendokComboProcess)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesDlg message handlers

BOOL CDisplayLoadedModulesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_0),0);
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_1),1);
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_2),2);
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_3),3);
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_4),4);
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_5),5);
	m_ListOfDLLs.AddColumn(_T(DLLLIST_HEADER_COLUMN_6),6);

	DisplayProcessList();
	DisplayDLLList(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDisplayLoadedModulesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDisplayLoadedModulesDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDisplayLoadedModulesDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CDisplayLoadedModulesDlg::DisplayDLLList(DWORD nPID)
{
	CStringList ModuleList;
	int nRecords=0;
	int nFields=0;

	m_ListOfDLLs.DeleteAllItems();
	m_LoadedModules.RemoveAll();

	if (BuildModuleList(nPID, ModuleList)) {

		POSITION pos = ModuleList.GetHeadPosition();
		CFileVersion fileVersion;
		CString FileDescription;
		CString FileVersion;
		CString ProductName;
		CString ProductVersion;
		CString FileModificationDateString;
		CString FileSizeString;

		while( pos != NULL ){

			nFields=0;

			// Get file name
			CString FileName = ModuleList.GetNext(pos);

			// Get file version info
			if (fileVersion.Open(FileName)) {
				FileDescription = fileVersion.GetFileDescription();
				FileVersion = fileVersion.GetFileVersion();
				ProductName = fileVersion.GetProductName();
				ProductVersion = fileVersion.GetProductVersion();
				fileVersion.Close();
			} else {
				FileDescription = "";
				FileVersion = "";
				ProductName = "";
				ProductVersion = "";
			}
			// Get file size and date
			CFileStatus FileStatus;
			CTime FileModificationDate;
			LONG FileSize=0;
			if (CFile::GetStatus(FileName, FileStatus)) {
				FileModificationDate = FileStatus.m_mtime;
				FileModificationDateString = FileModificationDate.Format("%B %d, %Y %H:%M:%S" );
				FileSize = FileStatus.m_size;
				FileSizeString.Format("%d",FileSize);
			} else {
				// Error: can't get file status
				FileModificationDateString = "?";
				FileSizeString = "?";
			}

			// Log it in debug window
			TRACE1("Module File Name = \"%s\"\n", FileName);
			TRACE1(" File Version    = \"%s\"\n", FileVersion);
			TRACE1(" File Size       = %s bytes\n", FileSizeString);
			TRACE1(" File Date       = \"%s\"\n", FileModificationDateString);
			TRACE1(" File Descrition = \"%s\"\n", FileDescription);
			TRACE1(" Product Name    = \"%s\"\n", ProductName);
			TRACE1(" Product Version = \"%s\"\n", ProductVersion);

			// Add module to the listbox
			m_ListOfDLLs.AddItem(nRecords,0,_T(FileName));
			m_ListOfDLLs.AddItem(nRecords,1,_T(FileVersion));
			m_ListOfDLLs.AddItem(nRecords,2,_T(FileSizeString));
			m_ListOfDLLs.AddItem(nRecords,3,_T(FileModificationDateString));
			m_ListOfDLLs.AddItem(nRecords,4,_T(FileDescription));
			m_ListOfDLLs.AddItem(nRecords,5,_T(ProductName));
			m_ListOfDLLs.AddItem(nRecords,6,_T(ProductVersion));
			// Add module to the string array (used to save data)
			CString CurrentLine = FileName + "\t" +
								  FileVersion  + "\t" +
								  FileSizeString + "\t" +
								  FileModificationDateString + "\t" +
								  FileDescription + "\t" +
								  ProductName + "\t" +
								  ProductVersion + "\t";
			m_LoadedModules.SetAtGrow(nRecords,CurrentLine);
			nRecords++;
		}
	}
    m_LoadedModules.FreeExtra();
}

void CDisplayLoadedModulesDlg::DisplayProcessList()
{
	m_ComboProcess.ResetContent();

	CMapStringToString PIDNameMap;
	CString PIDString;
	DWORD nPID=0;
	DWORD nCurrentPID=::GetCurrentProcessId();
	POSITION pos = NULL;

	BuildProcessList(PIDNameMap);

	pos = PIDNameMap.GetStartPosition();
	while( pos != NULL ){
		CString ProcessName;
		CString PIDString;
        int effectivePosition = 0;
		// Get key ( PIDString ) and value ( ProcessName )
		PIDNameMap.GetNextAssoc( pos, PIDString, ProcessName );
		// Use PIDString and ProcessName
		effectivePosition = m_ComboProcess.AddString(ProcessName);
		// Convert PID to a number
		nPID = atol(PIDString);
		// Select the current process in the combo box
		if (nPID == nCurrentPID) {
			m_ComboProcess.SetCurSel(effectivePosition);
		}
		// Store the process ID in the item's associated data
		m_ComboProcess.SetItemData(effectivePosition, nPID);
	}

}

void CDisplayLoadedModulesDlg::OnOK() 
{
	CString InitialFileName;
	CString FileHeader;
	time_t osBinaryTime;     // C run-time time (defined in <time.h>)
	time( &osBinaryTime );   // Get the current time from the operating system.
	CTime Now( osBinaryTime );  // CTime from C run-time time
	CString NowString = Now.Format( "%A, %B %d, %Y" );
	char pHereString[MAX_COMPUTERNAME_LENGTH+1];
	DWORD nHereLength=sizeof(pHereString);
	if (!GetComputerName(pHereString, &nHereLength)) {
		// Error: put question mark
		strcpy(pHereString, "?");
	}


	int nCurrentSelection = m_ComboProcess.GetCurSel();

	if (nCurrentSelection>0) {

		m_ComboProcess.GetLBText(nCurrentSelection, InitialFileName);

		FileHeader.Format("LOADED MODULES DUMP FOR PROCESS %s\r\n\r\nDate: %s\r\nHost: %s\r\n\r\n",
						  InitialFileName,
						  NowString,
						  pHereString);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_0);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_1);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_2);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_3);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_4);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_5);
		FileHeader+=CString(DLLLIST_HEADER_COLUMN_6)+"\r\n\r\n";

		InitialFileName+=".txt";
		CFileDialog SaveFileDlg(FALSE, // save as...
								"*.txt", // default filename extension
								InitialFileName, // initial filename
								OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT , // options
								NULL, // no filters
								this);

		if ( SaveFileDlg.DoModal() == IDOK ) {
			CFile SaveFile;
			try {
				if (SaveFile.Open(SaveFileDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite )) {
					CString CurrentLine;
					CString RawLine;
					SaveFile.Write(FileHeader.GetBuffer(0), FileHeader.GetLength());
					for( int i = 0; i < m_LoadedModules.GetSize();i++ ) {
						RawLine = m_LoadedModules[i];
						CurrentLine.Format("%s\r\n", (LPCTSTR)RawLine);
						SaveFile.Write(CurrentLine.GetBuffer(0), CurrentLine.GetLength());
					}
					SaveFile.Flush();
					SaveFile.Close();
				}
			}
			catch (...) {
				SaveFile.Close();
				DeleteFile(SaveFileDlg.GetPathName());
			}
		}
	}

	CDialog::OnOK();
}

void CDisplayLoadedModulesDlg::OnRefreshProcess() 
{
	CWaitCursor wait;

	DisplayProcessList();
	DisplayDLLList(0);
}

void CDisplayLoadedModulesDlg::OnSelendokComboProcess() 
{
	CWaitCursor wait;
	int nCurrentSelection = m_ComboProcess.GetCurSel();
	if (nCurrentSelection>=0) {
		DWORD nPID = m_ComboProcess.GetItemData(nCurrentSelection);
		DisplayDLLList(nPID);
	}
}
