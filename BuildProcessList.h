/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : BuildProcessList.h
    $Header: E:\SandBox/DisplayLoadedModules/BuildProcessList.h,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:57:06 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Declaration of the BuildProcessList function

  ------------------------------ Modifications ------------------------------ 
    $Log: BuildProcessList.h,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    œ‘ æ≥Ã–Ú“¿¿µƒ£øÈ
  
  =========================================================================== 
*/

#ifndef BUILD_PROCESS_LIST_H
#define BUILD_PROCESS_LIST_H

#include <afxwin.h>
#ifdef WIN98
    // Windows 98 Implementation: Uses TOOLHELP32
#   include "tlhelp32.h"

#else
    // NT Implementation: Uses PSAPI

#   include <winperf.h>
#   include <malloc.h>
#   include <stdio.h>
#   include <tchar.h>

#   define INITIAL_SIZE        51200
#   define EXTEND_SIZE         25600
#   define REGKEY_PERF         _T("software\\microsoft\\windows nt\\currentversion\\perflib")
#   define REGSUBKEY_COUNTERS  _T("Counters")
#   define PROCESS_COUNTER     _T("process")
#   define PROCESSID_COUNTER   _T("id process") 

#endif // WIN98

BOOL BuildProcessList(CMapStringToString &ProcessPIDNameMap);

#endif // BUILD_PROCESS_LIST_H
