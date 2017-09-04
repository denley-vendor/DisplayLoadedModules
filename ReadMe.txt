========================================================================
               MFC APPLICATION : DisplayLoadedModules v1.5
========================================================================

			(C) Emmanuel KARTMANN 1998-1999
========================================================================

Have you ever experienced an error while loading a DLL when you start an application?
Invalid DLL version? Entry point @XXXX not found? 

If the answer is yes, then this application is for you!

On you LAN, there may be thousands of versions of a DLL! Which version are you using? 
Which DLL has effectively been loaded by your application? You must check the PATH, the 
current working directory of your process, etc...

This small application, called "DisplayLoadedModules", connects to a running process, get the list of DLLs 
loaded by the process, and display the following information for every DLL:

	* Module File Path (e.g. "C:\WINNT4\System32\WS2_32.dll")

	* Module Description (e.g. "Windows Socket 2.0 32-Bit DLL")

	* Module File Version (e.g. "4.00")

	* Associated Product Name (e.g. "Microsoft(R) Windows NT(TM) Operating System")

	* Associated Product Version (e.g. "4.00")

	* Module File Size (e.g. "59664 bytes")

	* Module Creation Date (e.g. "October 14, 1996 03:38:00")



On Windows NT, the executable uses one additional DLL/Lib: PSAPI.DLL
For more on these APIs, please refer to MSDN Platform SDK:
	Process Status Helper (PSAPI)
		http://msdn.microsoft.com/library/sdkdoc/winbase/psapi_25ki.htm
	OpenProcess
		http://msdn.microsoft.com/library/sdkdoc/winbase/prothred_478z.htm
	EnumProcessModules
		http://msdn.microsoft.com/library/sdkdoc/winbase/psapi_1wz7.htm
	GetModuleFileNameEx
		http://msdn.microsoft.com/library/sdkdoc/winbase/psapi_8x88.htm

On Windows 98, the executable uses the ToolHelp32 library.
For more on this APIs, please refer to MSDN Platform SDK:
	ToolHelp Library
		http://msdn.microsoft.com/library/sdkdoc/winbase/toolhelp_5pfd.htm
	Taking a Snapshot and Viewing Processes
		http://msdn.microsoft.com/library/sdkdoc/winbase/toolhelp_99rn.htm
	Traversing the Module List
		http://msdn.microsoft.com/library/sdkdoc/winbase/toolhelp_4t6c.htm


The version info is fetched via the CFileVersion class by Manuel Laflamme (also posted in Codeguru).

