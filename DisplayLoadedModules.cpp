/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : DisplayLoadedModules.cpp
    $Header: E:\SandBox/DisplayLoadedModules/DisplayLoadedModules.cpp,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:55:10 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Implements the class behaviors for the application.

  ------------------------------ Modifications ------------------------------ 
    $Log: DisplayLoadedModules.cpp,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    œ‘ æ≥Ã–Ú“¿¿µƒ£øÈ
  
  =========================================================================== 
*/

#include "stdafx.h"
#include "DisplayLoadedModules.h"
#include "DisplayLoadedModulesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesApp

BEGIN_MESSAGE_MAP(CDisplayLoadedModulesApp, CWinApp)
	//{{AFX_MSG_MAP(CDisplayLoadedModulesApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesApp construction

CDisplayLoadedModulesApp::CDisplayLoadedModulesApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDisplayLoadedModulesApp object

CDisplayLoadedModulesApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesApp initialization

BOOL CDisplayLoadedModulesApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CDisplayLoadedModulesDlg dlg;
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
