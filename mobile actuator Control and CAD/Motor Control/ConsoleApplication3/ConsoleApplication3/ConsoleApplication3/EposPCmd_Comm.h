/*************************************************************************************************************************************
**                  maxon motor ag, CH-6072 Sachseln
**************************************************************************************************************************************
**
** FILE:            EposPCmd_Comm.h
**
** Summary:         Exported Functions for Windows DLL "EposPCmd.dll" and "EposPCmd64.dll"
**                    - Communication Functions
**                    - CanLayer Functions
**
** Date:            23.04.2010
** Dev. Platform:   Microsoft Visual Studio 2010 (C++)
** Target:          Windows Operating System
** Written by:      maxon motor ag, CH-6072 Sachseln
** Copyright        © maxon motor ag.
**                  All rights reserved.
**
** Changes:         1.00.01.00  (23.04.10): Initial Version
**                  1.01.01.00  (30.08.10): New Parameter DialogMode for Findxxx Functions
**                  1.02.00.00  (22.12.10): Enlargement of 64-Bit operating systems
**                  1.02.02.00  (02.02.11): Detect properly LIN devices
**                  1.02.04.00  (17.12.13): New functions: VCM_GetHomingState, VCM_WaitForHomingAttained, VCM_GetVelocityIsAveraged,
**                                            VCM_GetCurrentIsAveraged
**                                          Replaced function: VCM_SendNMTService with VCM_SendNMTServiceEx
**
*************************************************************************************************************************************/

#ifndef _H_WIN32_EPOSPCMD_COMM
#define _H_WIN32_EPOSPCMD_COMM

// INITIALISATION FUNCTIONS
    #define Comm_Initialisation_DllExport       extern "C" __declspec( dllexport )
    #define Gateway_Initialisation_DllExport    extern "C" __declspec( dllexport )
    #define Gateway_Search_DllExport            extern "C" __declspec( dllexport )
// HELP FUNCTIONS
    #define DriverInfo_DllExport                extern "C" __declspec( dllexport )
    #define HelpFunctions_DllExport             extern "C" __declspec( dllexport )
// LOW LAYER FUNCTIONS
    #define CanLayer_DllExport                  extern "C" __declspec( dllexport )

/*************************************************************************************************************************************
* INITIALISATION FUNCTIONS
*************************************************************************************************************************************/
//Communication
    Comm_Initialisation_DllExport HANDLE __stdcall VCM_OpenCommunication(char* ProtocolStackName, char* InterfaceName, char* PortName, DWORD* pErrorCode);
    Comm_Initialisation_DllExport HANDLE __stdcall VCM_OpenCommunicationDlg(DWORD* pErrorCode);
    Comm_Initialisation_DllExport BOOL __stdcall VCM_SetProtocolStackSettings(HANDLE CommunicationHandle, DWORD Baudrate, DWORD Timeout, DWORD* pErrorCode);
    Comm_Initialisation_DllExport BOOL __stdcall VCM_GetProtocolStackSettings(HANDLE CommunicationHandle, DWORD* pBaudrate, DWORD* pTimeout, DWORD* pErrorCode);
    Comm_Initialisation_DllExport BOOL __stdcall VCM_CloseCommunication(HANDLE CommunicationHandle, DWORD* pErrorCode);
    Comm_Initialisation_DllExport BOOL __stdcall VCM_CloseAllCommunication(DWORD* pErrorCode);

//Gateway
    Gateway_Initialisation_DllExport HANDLE __stdcall VCM_OpenGateway(char* GatewayProtocolStackName, char* GatewayDeviceName, HANDLE CommunicationHandle, DWORD* pErrorCode);
    Gateway_Initialisation_DllExport HANDLE __stdcall VCM_OpenGatewayDlg(HANDLE CommunicationHandle, DWORD* pErrorCode);
    Gateway_Initialisation_DllExport BOOL __stdcall VCM_SetGatewaySettings(HANDLE GatewayHandle, BYTE NodeId, WORD RemoteNetworkId, DWORD* pErrorCode);
    Gateway_Initialisation_DllExport BOOL __stdcall VCM_GetGatewaySettings(HANDLE GatewayHandle, BYTE* pNodeId, WORD* pRemoteNetworkId, DWORD* pErrorCode);
    Gateway_Initialisation_DllExport BOOL __stdcall VCM_CloseGateway(HANDLE GatewayHandle, DWORD* pErrorCode);
    Gateway_Initialisation_DllExport BOOL __stdcall VCM_CloseAllGateways(HANDLE CommunicationHandle, DWORD* pErrorCode);

//Gateway Search
    Gateway_Initialisation_DllExport BOOL __stdcall VCM_FindGatewayCommunicationSettings(HANDLE *pGatewayHandle, char* pGatewayProtocolStackName, char *pGatewayName, char *pProtocolStackName, char *pInterfaceName, char *pPortName, WORD SizeName, HANDLE* pCommunicationHandle, int DialogMode, DWORD *pErrorCode);

/*************************************************************************************************************************************
* HELP FUNCTIONS
*************************************************************************************************************************************/

//Driver Info
    DriverInfo_DllExport BOOL __stdcall VCM_GetDriverInfo(char* pLibraryName, WORD MaxNameSize, char* pLibraryVersion, WORD MaxVersionSize, DWORD* pErrorCode);
    DriverInfo_DllExport BOOL __stdcall VCM_GetDriverErrorInfo(DWORD ErrorCodeValue, char* pErrorInfo, WORD MaxStrSize);

//Advanced Functions
    HelpFunctions_DllExport BOOL __stdcall VCM_GetProtocolStackNameSelection(BOOL StartOfSelection, char* pProtocolStackNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetInterfaceNameSelection(char* ProtocolStackName, BOOL StartOfSelection, char* pInterfaceNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetPortNameSelection(char* ProtocolStackName, char* InterfaceName, BOOL StartOfSelection, char* pPortNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetBaudrateSelection(char* ProtocolStackName, char* InterfaceName, char* PortName, BOOL StartOfSelection, DWORD* pBaudrateSel, BOOL* pEndOfSelection, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetGatewayProtocolStackNameSelection(BOOL StartOfSelection, char* pGatewayProtocolStackNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetGatewayNameSelection(char* GatewayProtocolStackName, BOOL StartOfSelection, char* pGatewayNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);

    HelpFunctions_DllExport BOOL __stdcall VCM_GetCommunicationHandle(char* ProtocolStackName, char* InterfaceName, char* PortName, HANDLE* pCommunicationHandle, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetGatewayHandle(char* ProtocolStackName, char* GatewayName, BYTE NodeId, HANDLE* pGatewayHandle, DWORD* pErrorCode);

    HelpFunctions_DllExport BOOL __stdcall VCM_GetDeviceCommunicationHandle(HANDLE PlcOrDriveOrGatewayHandle, HANDLE* pCommunicationHandle, DWORD *pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetDeviceGatewayHandle(HANDLE PlcOrDriveHandle, HANDLE* pGatewayHandle, DWORD *pErrorCode);

    HelpFunctions_DllExport BOOL __stdcall VCM_GetProtocolStackName(HANDLE CommunicationHandle, char* pProtocolStackName, WORD MaxStrSize, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetInterfaceName(HANDLE CommunicationHandle, char* pInterfaceName, WORD MaxStrSize, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetPortName(HANDLE CommunicationHandle, char* pPortName, WORD MaxStrSize, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetGatewayName(HANDLE GatewayHandle, char* pGatewayName, WORD MaxStrSize, DWORD* pErrorCode);
    HelpFunctions_DllExport BOOL __stdcall VCM_GetGatewayProtocolStackName(HANDLE GatewayHandle, char* pGatewayProtocolStackName, WORD MaxStrSize, DWORD* pErrorCode);

/*************************************************************************************************************************************
* LOW LAYER FUNCTIONS
*************************************************************************************************************************************/

//CanLayer Functions
    CanLayer_DllExport BOOL __stdcall VCM_SendCANFrame(HANDLE CommunicationOrGatewayHandle, WORD CobID, WORD Length, void* pData, DWORD* pErrorCode);
    CanLayer_DllExport BOOL __stdcall VCM_ReadCANFrame(HANDLE CommunicationOrGatewayHandle, WORD CobID, WORD Length, void* pData, DWORD Timeout, DWORD* pErrorCode);
    CanLayer_DllExport BOOL __stdcall VCM_RequestCANFrame(HANDLE CommunicationOrGatewayHandle, WORD CobID, WORD Length, void* pData, DWORD* pErrorCode);
    CanLayer_DllExport BOOL __stdcall VCM_SendNMTServiceEx(HANDLE CommunicationOrGatewayHandle, WORD NodeID, WORD CommandSpecifier, DWORD* pErrorCode);
    CanLayer_DllExport BOOL __stdcall VCM_SendNMTService(HANDLE CommunicationOrGatewayHandle, WORD CommandSpecifier, DWORD* pErrorCode);

/*************************************************************************************************************************************
* TYPE DEFINITIONS
*************************************************************************************************************************************/

//Communication
    //Dialog Mode
    const int CDM_PROGRESS_DLG                  = 0;
    const int CDM_PROGRESS_AND_CONFIRM_DLG      = 1;
    const int CDM_CONFIRM_DLG                   = 2;
    const int CDM_NO_DLG                        = 3;

//CanLayer Functions
    //Commmand Specifier
    const WORD NCS_START_REMOTE_NODE            = 1;
    const WORD NCS_STOP_REMOTE_NODE             = 2;
    const WORD NCS_ENTER_PRE_OPERATIONAL        = 128;
    const WORD NCS_RESET_NODE                   = 129;
    const WORD NCS_RESET_COMMUNICATION          = 130;

#endif //_H_WIN32_EPOSPCMD_COMM

