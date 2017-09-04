/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : BuildModuleList.cpp
    $Header: E:\SandBox/DisplayLoadedModules/BuildModuleList.cpp,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:52:56 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Implementation of the BuildModuleList function

  ------------------------------ Modifications ------------------------------ 
    $Log: BuildModuleList.cpp,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    ÏÔÊ¾³ÌÐòÒÀÀµÄ£¿é
  
  =========================================================================== 
*/

#include "stdafx.h"
#include "BuildModuleList.h"

#ifdef WIN98
// Windows 98 Implementation: Uses TOOLHELP32
BOOL BuildModuleList(DWORD nCurrentPID, CStringList &ModuleFileNameList)
{ 
    BOOL          bReturnCode = FALSE; 
    BOOL          bFound      = FALSE; 
    HANDLE        hModuleSnap = NULL; 
    MODULEENTRY32 me32        = {0}; 
 
	// Empty the list
	ModuleFileNameList.RemoveAll();

	if (nCurrentPID == 0) {
		// Get current process id
		nCurrentPID = GetCurrentProcessId();
    }

    // Take a snapshot of all modules in the specified process. 

    hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, nCurrentPID); 
    if (hModuleSnap == (HANDLE)-1) 
        return (FALSE); 
 
    // Fill the size of the structure before using it. 

    me32.dwSize = sizeof(MODULEENTRY32); 
 
    // Walk the module list of the process, and find the module of 
    // interest. Then copy the information to the buffer pointed 
    // to by lpMe32 so that it can be returned to the caller. 

    if (Module32First(hModuleSnap, &me32)) 
    { 
        do 
        { 
			// Fetch module file name
			CString cleanFileName;
            // Make the module UPPERCASE
            // Windows NT seems to use random cases for files...
            cleanFileName = me32.szExePath;
            cleanFileName.MakeUpper();
            // Insert module name in list, in alphabetical order
            printf("Inserting module: \"%s\"\n", cleanFileName);
            POSITION pos = ModuleFileNameList.GetHeadPosition();
            BOOL bInsertBefore = FALSE;
            while ( pos != NULL ) {
				CString FileName = ModuleFileNameList.GetNext(pos);
                //TRACE1("File at current pos: \"%s\"\n", FileName);
                if (FileName >= cleanFileName) {
                    printf("BEFORE \"%s\"\n", FileName);
                    bInsertBefore = TRUE;
                    // Go back one position (or go to last)
                    if (pos==NULL) {
                        pos = ModuleFileNameList.GetTailPosition();
                    } else {
                        ModuleFileNameList.GetPrev(pos);
                    }
                    break;
                }
            }
            if (bInsertBefore) {
                if (pos == NULL) {
                    ModuleFileNameList.AddHead(cleanFileName);
                } else {
                    ModuleFileNameList.InsertBefore(pos, cleanFileName);
                }
            } else {
                if (pos == NULL) {
                    ModuleFileNameList.AddTail(cleanFileName);
                } else {
                    ModuleFileNameList.AddHead(cleanFileName);
                }
            }

            // DUMP THE LIST
            pos = ModuleFileNameList.GetHeadPosition();
			bReturnCode=TRUE;
		}
        while (!bFound && Module32Next(hModuleSnap, &me32)); 
 
        bReturnCode = bFound;   // if this sets bRet to FALSE, dwModuleID 
                                // no longer exists in specified process 
    } 
    else 
        bReturnCode = FALSE;           // could not walk module list 
 
    // Do not forget to clean up the snapshot object. 

    CloseHandle (hModuleSnap); 
 
    return (bReturnCode); 
} 

#else
// NT Implementation: Uses PSAPI
BOOL BuildModuleList(DWORD nCurrentPID, CStringList &ModuleFileNameList) 
{
	BOOL bReturnCode = FALSE;
	HANDLE pProcessHandle = NULL;

	// Empty the list
	ModuleFileNameList.RemoveAll();

	if (nCurrentPID == 0) {
		// Get current process id
		nCurrentPID = GetCurrentProcessId();
		pProcessHandle = GetCurrentProcess();
	} else {
		// Open the process to get an HANDLE on it
		pProcessHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
									 FALSE, // not inherited
									 nCurrentPID);
	}

	if (pProcessHandle != NULL) {
		HMODULE pLoadedModules[4096];
		DWORD nLoadedBytes = 0;
		// Get array of loaded modules
		if (EnumProcessModules(pProcessHandle,
							   pLoadedModules,
							   (DWORD)sizeof(pLoadedModules),
							   &nLoadedBytes)) {
			// Compute effective number of modules
			int nNumberOfModules = nLoadedBytes/sizeof(HMODULE);
			// Loop on all modules
			for (int i=0; i<nNumberOfModules; i++) {
				// Fetch module file name
				char pFileName[_MAX_PATH];
				CString cleanFileName;
				if (GetModuleFileNameEx(pProcessHandle,
										pLoadedModules[i],
										pFileName,
										_MAX_PATH) > 0) {
                    // Make the module UPPERCASE
                    // Windows NT seems to use random cases for files...
                    cleanFileName=pFileName;
                    cleanFileName.MakeUpper();
                    // Insert module name in list, in alphabetical order
                    printf("Inserting module: \"%s\"\n", cleanFileName);
                    POSITION pos = ModuleFileNameList.GetHeadPosition();
                    BOOL bInsertBefore = FALSE;
                    while ( pos != NULL ) {
					    CString FileName = ModuleFileNameList.GetNext(pos);
                        //TRACE1("File at current pos: \"%s\"\n", FileName);
                        if (FileName >= cleanFileName) {
                            printf("BEFORE \"%s\"\n", FileName);
                            bInsertBefore = TRUE;
                            // Go back one position (or go to last)
                            if (pos==NULL) {
                                pos = ModuleFileNameList.GetTailPosition();
                            } else {
                                ModuleFileNameList.GetPrev(pos);
                            }
                            break;
                        }
                    }
                    if (bInsertBefore) {
                        if (pos == NULL) {
                            ModuleFileNameList.AddHead(cleanFileName);
                        } else {
                            ModuleFileNameList.InsertBefore(pos, cleanFileName);
                        }
                    } else {
                        if (pos == NULL) {
                            ModuleFileNameList.AddTail(cleanFileName);
                        } else {
                            ModuleFileNameList.AddHead(cleanFileName);
                        }
                    }

                    // DUMP THE LIST
                    pos = ModuleFileNameList.GetHeadPosition();

					bReturnCode=TRUE;
				}
			}
		}

		// Close process handle
		CloseHandle(pProcessHandle);

	} else {
		TRACE2("Can't open process %u: %d\n", nCurrentPID, GetLastError());
		bReturnCode=FALSE;
	}


	return(bReturnCode);
} 
#endif /* WIN98 */ 