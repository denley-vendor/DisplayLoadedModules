/*=========================================================================== 
    (c) Copyright 1999, SITA, all rights reserved                 
  =========================================================================== 
    File           : DisplayLoadedModulesDlg.h
    $Header: E:\SandBox/DisplayLoadedModules/DisplayLoadedModulesDlg.h,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : SITA
    Creation       : Friday 9/24/99 4:59:12 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Header file for DisplayLoadedModules Dialog

  ------------------------------ Modifications ------------------------------ 
    $Log: DisplayLoadedModulesDlg.h,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    显示程序依赖模块
  
  =========================================================================== 
*/

#if !defined(AFX_DISPLAYLOADEDMODULESDLG_H__2525C7A8_5D14_11D2_8009_00E02924E982__INCLUDED_)
#define AFX_DISPLAYLOADEDMODULESDLG_H__2525C7A8_5D14_11D2_8009_00E02924E982__INCLUDED_

#include "CListCtrlEx.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define DLLLIST_HEADER_COLUMN_0 "Module Path                                            "
#define DLLLIST_HEADER_COLUMN_1 "File Version               "
#define DLLLIST_HEADER_COLUMN_2 "File Size (bytes)    "
#define DLLLIST_HEADER_COLUMN_3 "File Modification Date   "
#define DLLLIST_HEADER_COLUMN_4 "Description                     "
#define DLLLIST_HEADER_COLUMN_5 "Product Name       "
#define DLLLIST_HEADER_COLUMN_6 "Product Version  "
/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesDlg dialog

class CDisplayLoadedModulesDlg : public CDialog
{
// Construction
public:
	void DisplayProcessList(void);
	void DisplayDLLList(DWORD nPID);
	CDisplayLoadedModulesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDisplayLoadedModulesDlg)
	enum { IDD = IDD_DISPLAYLOADEDMODULES_DIALOG };
	CComboBox	m_ComboProcess;
	CListCtrlEx	m_ListOfDLLs;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayLoadedModulesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CStringArray m_LoadedModules;

	// Generated message map functions
	//{{AFX_MSG(CDisplayLoadedModulesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnRefreshProcess();
	afx_msg void OnSelendokComboProcess();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPLAYLOADEDMODULESDLG_H__2525C7A8_5D14_11D2_8009_00E02924E982__INCLUDED_)
