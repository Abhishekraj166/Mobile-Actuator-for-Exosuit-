/*************************************************************************************************************************************
**                  maxon motor ag, CH-6072 Sachseln
**************************************************************************************************************************************
**
** FILE:            EposPCmd_Plc.h
**
** Summary:         Exported Functions for Windows DLL "EposPCmd.dll" and "EposPCmd64.dll"
**                    - Plc Functions (Epos2 P)
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

#ifndef _H_WIN32_EPOSPCMD_PLC
#define _H_WIN32_EPOSPCMD_PLC

// INITIALISATION FUNCTIONS
    #define Plc_Initialisation_DllExport        extern "C" __declspec( dllexport )
    #define Plc_Search_DllExport                extern "C" __declspec( dllexport )
// HELP FUNCTIONS
    #define Plc_VersionInfo_DllExport           extern "C" __declspec( dllexport )
    #define Plc_HelpFunctions_DllExport         extern "C" __declspec( dllexport )
// CONFIGURATION FUNCTIONS
    #define Plc_Configuration_DllExport         extern "C" __declspec( dllexport )
// PROGRAM CONTROL FUNCTIONS
    #define Plc_ProgramDownload_DllExport       extern "C" __declspec( dllexport )
    #define Plc_ProgramStatus_DllExport         extern "C" __declspec( dllexport )
    #define Plc_ErrorHandling_DllExport         extern "C" __declspec( dllexport )
    #define Plc_VariableAccess_DllExport        extern "C" __declspec( dllexport )
    #define Plc_ProcessInputOutput_DllExport    extern "C" __declspec( dllexport )
    #define Plc_ProcessImage_DllExport          extern "C" __declspec( dllexport )

/*************************************************************************************************************************************
* INITIALISATION FUNCTIONS
*************************************************************************************************************************************/
//Plc
    Plc_Initialisation_DllExport HANDLE __stdcall VCM_OpenPlc(char* DeviceName, HANDLE CommunicationOrGatewayHandle, DWORD* pErrorCode);
    Plc_Initialisation_DllExport HANDLE __stdcall VCM_OpenPlcDlg(HANDLE CommunicationOrGatewayHandle, DWORD* pErrorCode);
    Plc_Initialisation_DllExport BOOL __stdcall VCM_SetPlcSettings(HANDLE PlcHandle, BYTE NodeId, DWORD* pErrorCode);
    Plc_Initialisation_DllExport BOOL __stdcall VCM_GetPlcSettings(HANDLE PlcHandle, BYTE* pNodeId, DWORD* pErrorCode);
    Plc_Initialisation_DllExport BOOL __stdcall VCM_ClosePlc(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_Initialisation_DllExport BOOL __stdcall VCM_CloseAllPlc(DWORD* pErrorCode);

//Search Functions
    Plc_Search_DllExport BOOL __stdcall VCM_FindPlcCommunicationSettings(HANDLE *pPlcHandle, HANDLE CommunicationOrGatewayHandle, char *pDeviceName, WORD SizeName, int DialogMode, DWORD *pErrorCode);
    Plc_Search_DllExport BOOL __stdcall VCM_FindCommunicationSettings(HANDLE *pPlcHandle, char *pDeviceName, char *pProtocolStackName, char *pInterfaceName, char *pPortName, WORD SizeName, HANDLE* pCommunicationHandle, int DialogMode, DWORD *pErrorCode);

/*************************************************************************************************************************************
* HELP FUNCTIONS
*************************************************************************************************************************************/
//Version Info
    Plc_VersionInfo_DllExport BOOL __stdcall VCM_GetVersion(HANDLE PlcHandle, WORD* pHardwareVersion, WORD* pSoftwareVersion, WORD* pApplicationNumber, WORD* pApplicationVersion, DWORD* pErrorCode);
    Plc_HelpFunctions_DllExport BOOL __stdcall VCM_GetErrorInfo(DWORD ErrorCodeValue, char* pErrorInfo, WORD MaxStrSize);

//Advanced Functions
    Plc_HelpFunctions_DllExport BOOL __stdcall VCM_GetPlcDeviceNameSelection(BOOL StartOfSelection, char* pDeviceNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);
    Plc_HelpFunctions_DllExport BOOL __stdcall VCM_GetPlcHandle(HANDLE CommunicationOrGatewayHandle, char* DeviceName, BYTE NodeId, HANDLE* pPlcHandle, DWORD* pErrorCode);
    Plc_HelpFunctions_DllExport BOOL __stdcall VCM_GetDeviceName(HANDLE PlcHandle, char* pDeviceName, WORD MaxStrSize, DWORD* pErrorCode);

/*************************************************************************************************************************************
* CONFIGURATION FUNCTIONS
*************************************************************************************************************************************/
//General
    Plc_Configuration_DllExport BOOL __stdcall VCM_ImportParameter(HANDLE PlcHandle, char *ParameterFileName, BOOL ShowDlg, BOOL ShowMsg, DWORD *pErrorCode);
    Plc_Configuration_DllExport BOOL __stdcall VCM_ExportParameter(HANDLE PlcHandle, char *ParameterFileName, char *BinaryFile, char *UserID, char *Comment, BOOL ShowDlg, BOOL ShowMsg, DWORD *pErrorCode);
    Plc_Configuration_DllExport BOOL __stdcall VCM_SetObject(HANDLE PlcHandle, WORD ObjectIndex, BYTE ObjectSubIndex, BYTE* pData, DWORD NbOfBytesToWrite, DWORD* pNbOfBytesWritten, DWORD* pErrorCode);
    Plc_Configuration_DllExport BOOL __stdcall VCM_GetObject(HANDLE PlcHandle, WORD ObjectIndex, BYTE ObjectSubIndex, BYTE* pData, DWORD NbOfBytesToRead, DWORD* pNbOfBytesRead, DWORD* pErrorCode);
    Plc_Configuration_DllExport BOOL __stdcall VCM_Restore(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_Configuration_DllExport BOOL __stdcall VCM_Store(HANDLE PlcHandle, DWORD* pErrorCode);

//Plc Configuration Functions
    //Bootup
    Plc_Configuration_DllExport BOOL __stdcall VCM_SetBootupBehavior(HANDLE PlcHandle, WORD ProgramControl, DWORD* pErrorCode);
    Plc_Configuration_DllExport BOOL __stdcall VCM_GetBootupBehavior(HANDLE PlcHandle, WORD* pProgramControl, DWORD* pErrorCode);

/*************************************************************************************************************************************
* PROGRAM CONTROL FUNCTIONS
*************************************************************************************************************************************/
//Program Download
    Plc_ProgramDownload_DllExport BOOL __stdcall VCM_DownloadProgram(HANDLE PlcHandle, char* ProjectPathFileName, DWORD* pErrorCode);

//Program Status
    Plc_ProgramStatus_DllExport BOOL __stdcall VCM_ColdstartPlc(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_ProgramStatus_DllExport BOOL __stdcall VCM_WarmstartPlc(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_ProgramStatus_DllExport BOOL __stdcall VCM_HotstartPlc(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_ProgramStatus_DllExport BOOL __stdcall VCM_StopPlc(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_ProgramStatus_DllExport BOOL __stdcall VCM_ClearPlcProgram(HANDLE PlcHandle, DWORD* pErrorCode);
    Plc_ProgramStatus_DllExport BOOL __stdcall VCM_GetPlcStatus(HANDLE PlcHandle, BOOL* pIsRunning, BOOL* pIsProgramAvailable, DWORD* pErrorCode);

//ErrorHandling
    Plc_ErrorHandling_DllExport BOOL __stdcall VCM_GetNbOfDeviceErrors(HANDLE PlcHandle, BYTE *pNbDeviceError, DWORD *pErrorCode);
    Plc_ErrorHandling_DllExport BOOL __stdcall VCM_GetDeviceErrorCode(HANDLE PlcHandle, BYTE ErrorNumber, DWORD *pDeviceErrorCode, DWORD *pErrorCode);
    Plc_ErrorHandling_DllExport BOOL __stdcall VCM_ClearDeviceErrors(HANDLE PlcHandle, DWORD *pErrorCode);

//Program Variable Access
    Plc_VariableAccess_DllExport BOOL __stdcall VCM_InitVariableTable(HANDLE PlcHandle, char* ProjectPathName, DWORD* pErrorCode);
    Plc_VariableAccess_DllExport BOOL __stdcall VCM_SetVariable(HANDLE PlcHandle, char* VariableName, BYTE* pData, DWORD NbOfBytesToWrite, DWORD* pNbOfBytesWritten, DWORD* pErrorCode);
    Plc_VariableAccess_DllExport BOOL __stdcall VCM_GetVariable(HANDLE PlcHandle, char* VariableName, BYTE* pData, DWORD NbOfBytesToRead, DWORD* pNbOfBytesRead, DWORD* pErrorCode);

//Process Input/Output Access
    Plc_ProcessInputOutput_DllExport BOOL __stdcall VCM_SetProcessInput(HANDLE PlcHandle, WORD ProcessInputType, BYTE ElementNumber, BYTE* pData, DWORD NbOfBytesToWrite, DWORD* pNbOfBytesWritten, DWORD* pErrorCode);
    Plc_ProcessInputOutput_DllExport BOOL __stdcall VCM_GetProcessOutput(HANDLE PlcHandle, WORD ProcessOutputType, BYTE ElementNumber, BYTE* pData, DWORD NbOfBytesToRead, DWORD* pNbOfBytesRead, DWORD* pErrorCode);

    Plc_ProcessInputOutput_DllExport BOOL __stdcall VCM_SetProcessInputBit(HANDLE PlcHandle, WORD ProcessInputType, BYTE ElementNumber, BYTE BitNumber, BYTE BitState, DWORD* pErrorCode);
    Plc_ProcessInputOutput_DllExport BOOL __stdcall VCM_GetProcessOutputBit(HANDLE PlcHandle, WORD ProcessOutputType, BYTE ElementNumber, BYTE BitNumber, BYTE* pBitState, DWORD* pErrorCode);

//Process Image Access
    Plc_ProcessImage_DllExport BOOL __stdcall VCM_SetProcessInputImage(HANDLE PlcHandle, BYTE* pProcessInputImage, DWORD* pErrorCode);
    Plc_ProcessImage_DllExport BOOL __stdcall VCM_GetProcessOutputImage(HANDLE PlcHandle, BYTE* pProcessOutputImage, DWORD* pErrorCode);

/******************************************************************************************************************************************************************
* TYPE DEFINITIONS
*******************************************************************************************************************************************************************/

//Communication
    //Dialog Mode
    const int PDM_PROGRESS_DLG                  = 0;
    const int PDM_PROGRESS_AND_CONFIRM_DLG      = 1;
    const int PDM_CONFIRM_DLG                   = 2;
    const int PDM_NO_DLG                        = 3;

//Bootup Behaviour
    //ProgramControl
    const WORD BOH_NOT_STARTED_AT_BOOTUP        = 0;
    const WORD BOH_COLD_START_AT_BOOTUP         = 1;
    const WORD BOH_WARM_START_AT_BOOTUP         = 2;
    const WORD BOH_HOT_START_AT_BOOTUP          = 3;

//Process Input/Output Access
    //Process Input Type
    const WORD PIT_PROCESS_INPUT_INT8           = 0;
    const WORD PIT_PROCESS_INPUT_UINT8          = 1;
    const WORD PIT_PROCESS_INPUT_INT16          = 2;
    const WORD PIT_PROCESS_INPUT_UINT16         = 3;
    const WORD PIT_PROCESS_INPUT_INT32          = 4;
    const WORD PIT_PROCESS_INPUT_UINT32         = 5;
    const WORD PIT_PROCESS_INPUT_INT64          = 6;
    const WORD PIT_PROCESS_INPUT_UINT64         = 7;

    //Process Output Type
    const WORD PIT_PROCESS_OUTPUT_INT8          = 0;
    const WORD PIT_PROCESS_OUTPUT_UINT8         = 1;
    const WORD PIT_PROCESS_OUTPUT_INT16         = 2;
    const WORD PIT_PROCESS_OUTPUT_UINT16        = 3;
    const WORD PIT_PROCESS_OUTPUT_INT32         = 4;
    const WORD PIT_PROCESS_OUTPUT_UINT32        = 5;
    const WORD PIT_PROCESS_OUTPUT_INT64         = 6;
    const WORD PIT_PROCESS_OUTPUT_UINT64        = 7;

//Process Image Access
struct SProcessInputImage
{
    signed __int8           ProcessInput_INT8[16];
    unsigned __int8         ProcessInput_UINT8[16];
    signed __int16          ProcessInput_INT16[16];
    unsigned __int16        ProcessInput_UINT16[16];
    signed __int32          ProcessInput_INT32[16];
    unsigned __int32        ProcessInput_UINT32[16];
};

struct SProcessOutputImage
{
    signed __int8           ProcessOutput_INT8[16];
    unsigned __int8         ProcessOutput_UINT8[16];
    signed __int16          ProcessOutput_INT16[16];
    unsigned __int16        ProcessOutput_UINT16[16];
    signed __int32          ProcessOutput_INT32[16];
    unsigned __int32        ProcessOutput_UINT32[16];
};

#endif //_H_WIN32_EPOSPCMD_PLC

