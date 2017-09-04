/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : BuildModuleList.h
    $Header: E:\SandBox/DisplayLoadedModules/BuildModuleList.h,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:53:29 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Declaration of the BuildModuleList function

  ------------------------------ Modifications ------------------------------ 
    $Log: BuildModuleList.h,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    œ‘ æ≥Ã–Ú“¿¿µƒ£øÈ
  
  =========================================================================== 
*/


#ifndef BUILD_MODULE_LIST_H
#define BUILD_MODULE_LIST_H

#include <afxwin.h>
#include <stdlib.h>
#ifdef WIN98
// Windows 98 Implementation: Uses TOOLHELP32
#include "tlhelp32.h"
#else
// NT Implementation: Uses PSAPI
#include "psapi.h"
#endif // WIN98

BOOL BuildModuleList(DWORD nCurrentPID, CStringList &ModuleFileNameList);

#endif // BUILD_MODULE_LIST_H

