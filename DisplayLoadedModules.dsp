# Microsoft Developer Studio Project File - Name="DisplayLoadedModules" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DisplayLoadedModules - Win32 Windows 98 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DisplayLoadedModules.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DisplayLoadedModules.mak" CFG="DisplayLoadedModules - Win32 Windows 98 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DisplayLoadedModules - Win32 Windows NT Release" (based on "Win32 (x86) Application")
!MESSAGE "DisplayLoadedModules - Win32 Windows NT Debug" (based on "Win32 (x86) Application")
!MESSAGE "DisplayLoadedModules - Win32 Windows 98 Release" (based on "Win32 (x86) Application")
!MESSAGE "DisplayLoadedModules - Win32 Windows 98 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DisplayLoadedModules - Win32 Windows NT Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "DisplayLoadedModules___Win32_Windows_NT_Release"
# PROP BASE Intermediate_Dir "DisplayLoadedModules___Win32_Windows_NT_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Windows_NT_Release"
# PROP Intermediate_Dir "Windows_NT_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib psapi.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib psapi.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "DisplayLoadedModules - Win32 Windows NT Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DisplayLoadedModules___Win32_Windows_NT_Debug"
# PROP BASE Intermediate_Dir "DisplayLoadedModules___Win32_Windows_NT_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Windows_NT_Debug"
# PROP Intermediate_Dir "Windows_NT_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib psapi.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib psapi.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ELSEIF  "$(CFG)" == "DisplayLoadedModules - Win32 Windows 98 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "DisplayLoadedModules___Win32_Windows_98_Release"
# PROP BASE Intermediate_Dir "DisplayLoadedModules___Win32_Windows_98_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Windows_98_Release"
# PROP Intermediate_Dir "Windows_98_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "WIN98" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL" /d "WIN98"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib psapi.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "DisplayLoadedModules - Win32 Windows 98 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DisplayLoadedModules___Win32_Windows_98_Debug"
# PROP BASE Intermediate_Dir "DisplayLoadedModules___Win32_Windows_98_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Windows_98_Debug"
# PROP Intermediate_Dir "Windows_98_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "WIN98" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL" /d "WIN98"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib psapi.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "DisplayLoadedModules - Win32 Windows NT Release"
# Name "DisplayLoadedModules - Win32 Windows NT Debug"
# Name "DisplayLoadedModules - Win32 Windows 98 Release"
# Name "DisplayLoadedModules - Win32 Windows 98 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BuildModuleList.cpp
# End Source File
# Begin Source File

SOURCE=.\BuildProcessList.cpp
# End Source File
# Begin Source File

SOURCE=.\CListCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=.\DisplayLoadedModules.cpp
# End Source File
# Begin Source File

SOURCE=.\DisplayLoadedModules.rc
# End Source File
# Begin Source File

SOURCE=.\DisplayLoadedModulesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FileVersion.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BuildModuleList.h
# End Source File
# Begin Source File

SOURCE=.\BuildProcessList.h
# End Source File
# Begin Source File

SOURCE=.\CListCtrlEx.h
# End Source File
# Begin Source File

SOURCE=.\DisplayLoadedModules.h
# End Source File
# Begin Source File

SOURCE=.\DisplayLoadedModulesDlg.h
# End Source File
# Begin Source File

SOURCE=.\FileVersion.h
# End Source File
# Begin Source File

SOURCE=.\pdh.h
# End Source File
# Begin Source File

SOURCE=.\psapi.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\DisplayLoadedModules.ico
# End Source File
# Begin Source File

SOURCE=.\res\DisplayLoadedModules.rc2
# End Source File
# Begin Source File

SOURCE=.\version.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\pdh.Dll
# End Source File
# Begin Source File

SOURCE=.\psapi.Dll
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\psapi.Lib
# End Source File
# End Target
# End Project
