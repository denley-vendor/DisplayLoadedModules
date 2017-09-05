/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : DisplayLoadedModules.h
    $Header: E:\SandBox/DisplayLoadedModules/DisplayLoadedModules.h,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:57:46 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Main header file for the DisplayLoadedModules application

  ------------------------------ Modifications ------------------------------ 
    $Log: DisplayLoadedModules.h,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    显示程序依赖模块
  
  =========================================================================== 
*/

#if !defined(AFX_DISPLAYLOADEDMODULES_H__2525C7A6_5D14_11D2_8009_00E02924E982__INCLUDED_)
#define AFX_DISPLAYLOADEDMODULES_H__2525C7A6_5D14_11D2_8009_00E02924E982__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDisplayLoadedModulesApp:
// See DisplayLoadedModules.cpp for the implementation of this class
//

class CDisplayLoadedModulesApp : public CWinApp
{
public:
	CDisplayLoadedModulesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayLoadedModulesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDisplayLoadedModulesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPLAYLOADEDMODULES_H__2525C7A6_5D14_11D2_8009_00E02924E982__INCLUDED_)
