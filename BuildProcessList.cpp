/*=========================================================================== 
    (c) Copyright 1999, Emmanuel KARTMANN, all rights reserved                 
  =========================================================================== 
    File           : BuildProcessList.cpp
    $Header: E:\SandBox/DisplayLoadedModules/BuildProcessList.cpp,v 1.1.1.1 2007/06/17 14:19:31 xdl Exp $
    Author         : Emmanuel KARTMANN
    Creation       : Friday 9/24/99 4:54:10 PM
    Remake         : 
  ------------------------------- Description ------------------------------- 

           Implementation of the BuildProcessList function

  ------------------------------ Modifications ------------------------------ 
    $Log: BuildProcessList.cpp,v $
    Revision 1.1.1.1  2007/06/17 14:19:31  xdl
    显示程序依赖模块
  
  =========================================================================== 
*/


#include "stdafx.h"
#include "BuildProcessList.h"

#define PN_PROCESS_ID                       TEXT("ID Process") 

#ifdef WIN98
// Windows 98 Implementation: Uses TOOLHELP32
BOOL BuildProcessList(CMapStringToString &ProcessPIDNameMap)
{ 
    HANDLE         hProcessSnap = NULL; 
    BOOL           bRet      = FALSE; 
    PROCESSENTRY32 pe32      = {0}; 

    // Reset list/map
	ProcessPIDNameMap.RemoveAll();
 
    //  Take a snapshot of all processes in the system. 

    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 

    if (hProcessSnap == (HANDLE)-1) 
        return (FALSE); 
 
    //  Fill in the size of the structure before using it. 

    pe32.dwSize = sizeof(PROCESSENTRY32); 
 
    //  Walk the snapshot of the processes, and for each process, 
    //  display information. 

    if (Process32First(hProcessSnap, &pe32)) 
    { 
//        DWORD         dwPriorityClass; 
        BOOL          bGotModule = FALSE; 
        MODULEENTRY32 me32       = {0}; 
 
        do 
        { 
//            bGotModule = GetProcessModule(pe32.th32ProcessID, 
//                pe32.th32ModuleID, &me32, sizeof(MODULEENTRY32)); 
//            if (bGotModule) 
//            { 
//                HANDLE hProcess; 
// 
//                // Get the actual priority class. 
//                hProcess = OpenProcess (PROCESS_ALL_ACCESS, 
//                    FALSE, pe32.th32ProcessID); 
//                dwPriorityClass = GetPriorityClass (hProcess); 
//                CloseHandle (hProcess); 
//
//                // Print the process's information. 
//                printf( "\nPriority Class Base\t%d\n", 
//                    pe32.pcPriClassBase); 
//                printf( "PID\t\t\t%d\n", pe32.th32ProcessID);
//                printf( "Thread Count\t\t%d\n", pe32.cntThreads);
//                printf( "Module Name\t\t%s\n", me32.szModule);
//                printf( "Full Path\t\t%s\n\n", me32.szExePath);
//            } 
			CString MapKey;
			MapKey.Format("%u", pe32.th32ProcessID);
			ProcessPIDNameMap.SetAt(MapKey, me32.szModule);
        } 
        while (Process32Next(hProcessSnap, &pe32)); 
        bRet = TRUE; 
    } 
    else 
        bRet = FALSE;    // could not walk the list of processes 
 
    // Do not forget to clean up the snapshot object. 

    CloseHandle (hProcessSnap); 
    return (bRet); 
} 


#else
// NT Implementation: Uses Registry Performance Data
BOOL BuildProcessList(CMapStringToString &ProcessPIDNameMap)
{
	// Reset list/map
	ProcessPIDNameMap.RemoveAll();

	//This following was coded using the tlist example

	bool						 bErrorOccured=false;
	DWORD                        rc;
    HKEY                         hKeyNames;
    DWORD                        dwType;
    DWORD                        dwSize;
    LPBYTE                       buf = NULL;
    TCHAR                        szSubKey[1024];
    LANGID                       lid;
    LPSTR                        p;
    LPSTR                        p2;
    PPERF_DATA_BLOCK             pPerf;
    PPERF_OBJECT_TYPE            pObj;
    PPERF_INSTANCE_DEFINITION    pInst;
    PPERF_COUNTER_BLOCK          pCounter;
	PPERF_COUNTER_DEFINITION     pCounterDef;
    DWORD                        i;
    DWORD                        dwProcessIdTitle; 
    DWORD                        dwProcessIdCounter; 
    TCHAR                        szProcessName[MAX_PATH];
    DWORD                        dwLimit = 256;
	DWORD dwNumTasks;
    lid = MAKELANGID(LANG_ENGLISH, SUBLANG_NEUTRAL);
    _stprintf( szSubKey, _T("%s\\%03x"), REGKEY_PERF, lid );
    rc = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                       szSubKey,
                       0,
                       KEY_READ,
                       &hKeyNames
                     );
    if (rc != ERROR_SUCCESS)
	{
		bErrorOccured=true;
//		m_strLastError=_T("Could not open performance registry key");
        goto exit;

    }

    //
    // get the buffer size for the counter names
    //
    rc = RegQueryValueEx(hKeyNames,
                          REGSUBKEY_COUNTERS,
                          NULL,
                          &dwType,
                          NULL,
                          &dwSize
                        );

    if (rc != ERROR_SUCCESS)
	{
		bErrorOccured=true;
//		m_strLastError=_T("Could not open counter registry key");
        goto exit;
    }

    //
    // allocate the counter names buffer
    //
    buf = (LPBYTE) malloc(dwSize);
    if (buf == NULL)
	{
		bErrorOccured=true;
//		m_strLastError=_T("Out of Memory");
        goto exit;
    }
    memset(buf, 0, dwSize);

    //
    // read the counter names from the registry
    //
    rc = RegQueryValueEx( hKeyNames,
                          REGSUBKEY_COUNTERS,
                          NULL,
                          &dwType,
                          buf,
                          &dwSize
                        );

    if (rc != ERROR_SUCCESS) 
	{
		bErrorOccured=true;
//		m_strLastError=_T("Could Not Read the counter Names");
        goto exit;
    }

    //
    // now loop thru the counter names looking for the "Process" counters:
    // the buffer contains multiple null terminated strings and then
    // finally null terminated at the end.  the strings are in pairs of
    // counter number and counter name.
    //

    p =(LPSTR) buf;
    while (*p) 
	{
        if (p > (LPSTR)buf) 
		{
            for( p2=p-2; _istdigit(*p2); p2--)
						;
        }
        if (_tcsicmp(p, PROCESS_COUNTER) == 0)
		{
            // look backwards for the counter number
            for(p2=p-2; _istdigit(*p2); p2--) 
						;
            _tcscpy(szSubKey, p2+1);
        } else {
			if (stricmp(p, PROCESSID_COUNTER) == 0) {
				// 
				// look backwards for the counter number
				//
				for( p2=p-2; isdigit(*p2); p2--) 
					; 
				dwProcessIdTitle = atol( p2+1 );
			}
		}
        //
		// next string
		// 
        p += (_tcslen(p) + 1);
    }


    // free the counter names buffer
    free(buf);


    // allocate the initial buffer for the performance data

    dwSize = INITIAL_SIZE;
    buf = (LPBYTE)malloc( dwSize );
    if (buf == NULL)
	{
		bErrorOccured=true;
//		m_strLastError=_T("Out of Memory");
        goto exit;
    }
    memset(buf, 0, dwSize);
    while (true)
	{

        rc = RegQueryValueEx( HKEY_PERFORMANCE_DATA,
                              szSubKey,
                              NULL,
                              &dwType,
                              buf,
                              &dwSize
                            );

        pPerf = (PPERF_DATA_BLOCK) buf;

        // check for success and valid perf data block signature

        if ((rc == ERROR_SUCCESS) &&
            (dwSize > 0) &&
            (pPerf)->Signature[0] == (WCHAR)'P' &&
            (pPerf)->Signature[1] == (WCHAR)'E' &&
            (pPerf)->Signature[2] == (WCHAR)'R' &&
            (pPerf)->Signature[3] == (WCHAR)'F' )
		{
            break;
        }

        // if buffer is not big enough, reallocate and try again

        if (rc == ERROR_MORE_DATA)
		{
            dwSize += EXTEND_SIZE;
            buf = (LPBYTE)realloc( buf, dwSize );
            memset( buf, 0, dwSize );
        }
        else 
		{
			bErrorOccured=true;
//			m_strLastError=_T("Could Not Obtain Performance Data");
			goto exit;
        }
    }

    // set the perf_object_type pointer

    pObj = (PPERF_OBJECT_TYPE) ((DWORD)pPerf + pPerf->HeaderLength);

    // 
    // loop thru the performance counter definition records looking 
    // for the process id counter and then save its offset 
    // 
    pCounterDef = (PPERF_COUNTER_DEFINITION) ((DWORD)pObj + pObj->HeaderLength); 
    for (i=0; i<(DWORD)pObj->NumCounters; i++) { 
        if (pCounterDef->CounterNameTitleIndex == dwProcessIdTitle) { 
            dwProcessIdCounter = pCounterDef->CounterOffset; 
            break; 
        } 
        pCounterDef++; 
    } 

    dwNumTasks = min( dwLimit, (DWORD)pObj->NumInstances );
    pInst = (PPERF_INSTANCE_DEFINITION) ((DWORD)pObj + pObj->DefinitionLength);

    // loop thru the performance instance data extracting each process name

    for (i=0; i<dwNumTasks; i++)
	{
        //
        // pointer to the process name
        //
        p = (LPSTR) ((DWORD)pInst + pInst->NameOffset);

        //
        // convert it to ascii
        //
        rc = WideCharToMultiByte( CP_ACP,
                                  0,
                                  (LPCWSTR)p,
                                  -1,
                                  szProcessName,
                                  sizeof(szProcessName),
                                  NULL,
                                  NULL
                                );

		if (rc)
		{
   				//m_strArray.Add(szProcessName);
				TRACE1("%s\t", szProcessName);
		}
        // get the process id
        pCounter = (PPERF_COUNTER_BLOCK) ((DWORD)pInst + pInst->ByteLength);
        DWORD nProcessId = *((LPDWORD) ((DWORD)pCounter + dwProcessIdCounter));
		TRACE1("%u\n", nProcessId);
		// Do not add the _Total instance: it's NOT a process
		if (strcmp("_Total", szProcessName) && nProcessId) {
			CString MapKey;
			MapKey.Format("%u", nProcessId);
			ProcessPIDNameMap.SetAt(MapKey, szProcessName);
		}
        // next process
        pInst = (PPERF_INSTANCE_DEFINITION) ((DWORD)pCounter + pCounter->ByteLength);
    }

exit:
    if (buf) 
	{
        free(buf);
    }

    RegCloseKey(hKeyNames);
    RegCloseKey(HKEY_PERFORMANCE_DATA);
	return !bErrorOccured;

}
#endif // WIN98
