/*************************************************************************************************************************************
**                  maxon motor ag, CH-6072 Sachseln
**************************************************************************************************************************************
**
** FILE:            EposPCmd_Drive.h
**
** Summary:         Exported Functions for Windows DLL "EposPCmd.dll" and "EposPCmd64.dll"
**                    - Drive Functions (Epos, Epos2)
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

#ifndef _H_WIN32_EPOSPCMD_DRIVE
#define _H_WIN32_EPOSPCMD_DRIVE

// INITIALISATION FUNCTIONS
    #define Drive_Initialisation_DllExport              extern "C" __declspec( dllexport )
    #define Drive_Search_DllExport                      extern "C" __declspec( dllexport )
// HELP FUNCTIONS
    #define Drive_VersionInfo_DllExport                 extern "C" __declspec( dllexport )
    #define Drive_HelpFunctions_DllExport               extern "C" __declspec( dllexport )
// CONFIGURATION FUNCTIONS
    #define Drive_Configuration_DllExport               extern "C" __declspec( dllexport )
// OPERATION FUNCTIONS
    #define Drive_Status_DllExport                      extern "C" __declspec( dllexport )
    #define Drive_StateMachine_DllExport                extern "C" __declspec( dllexport )
    #define Drive_ErrorHandling_DllExport               extern "C" __declspec( dllexport )
    #define Drive_MotionInfo_DllExport                  extern "C" __declspec( dllexport )
    #define Drive_ProfilePositionMode_DllExport         extern "C" __declspec( dllexport )
    #define Drive_ProfileVelocityMode_DllExport         extern "C" __declspec( dllexport )
    #define Drive_HomingMode_DllExport                  extern "C" __declspec( dllexport )
    #define Drive_InterpolatedPositionMode_DllExport    extern "C" __declspec( dllexport )
    #define Drive_PositionMode_DllExport                extern "C" __declspec( dllexport )
    #define Drive_VelocityMode_DllExport                extern "C" __declspec( dllexport )
    #define Drive_CurrentMode_DllExport                 extern "C" __declspec( dllexport )
    #define Drive_MasterEncoderMode_DllExport           extern "C" __declspec( dllexport )
    #define Drive_StepDirectionMode_DllExport           extern "C" __declspec( dllexport )
    #define Drive_InputsOutputs_DllExport               extern "C" __declspec( dllexport )
// DATA RECORDING FUNCTIONS
    #define Drive_DataRecording_DllExport               extern "C" __declspec( dllexport )

/*************************************************************************************************************************************
* INITIALISATION FUNCTIONS
*************************************************************************************************************************************/
//Drive
    Drive_Initialisation_DllExport HANDLE __stdcall VCM_OpenDrive(char* DeviceName, HANDLE CommunicationOrGatewayHandle, DWORD* pErrorCode);
    Drive_Initialisation_DllExport HANDLE __stdcall VCM_OpenDriveDlg(HANDLE CommunicationOrGatewayHandle, DWORD* pErrorCode);
    Drive_Initialisation_DllExport BOOL __stdcall VCM_SetDriveSettings(HANDLE DriveHandle, BYTE NodeId, DWORD* pErrorCode);
    Drive_Initialisation_DllExport BOOL __stdcall VCM_GetDriveSettings(HANDLE DriveHandle, BYTE* pNodeId, DWORD* pErrorCode);
    Drive_Initialisation_DllExport BOOL __stdcall VCM_CloseDrive(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_Initialisation_DllExport BOOL __stdcall VCM_CloseAllDrives(DWORD* pErrorCode);

//Search Functions
    Drive_Search_DllExport BOOL __stdcall VCM_FindDriveCommunicationSettings(HANDLE *pDriveHandle, HANDLE CommunicationOrGatewayHandle, char *pDeviceName, WORD SizeName, int DialogMode, DWORD *pErrorCode);
    Drive_Search_DllExport BOOL __stdcall VCM_FindCommunicationSettings(HANDLE *pDriveHandle, char *pDeviceName, char *pProtocolStackName, char *pInterfaceName, char *pPortName, WORD SizeName, HANDLE* pCommunicationHandle, int DialogMode, DWORD *pErrorCode);

/*************************************************************************************************************************************
* HELP FUNCTIONS
*************************************************************************************************************************************/
//Info Functions
    Drive_VersionInfo_DllExport BOOL __stdcall VCM_GetVersion(HANDLE DriveHandle, WORD* pHardwareVersion, WORD* pSoftwareVersion, WORD* pApplicationNumber, WORD* pApplicationVersion, DWORD* pErrorCode);
    Drive_HelpFunctions_DllExport BOOL __stdcall VCM_GetErrorInfo(DWORD ErrorCodeValue, char* pErrorInfo, WORD MaxStrSize);
//Advanced Functions
    Drive_HelpFunctions_DllExport BOOL __stdcall VCM_GetDriveDeviceNameSelection(BOOL StartOfSelection, char* pDeviceNameSel, WORD MaxStrSize, BOOL* pEndOfSelection, DWORD* pErrorCode);
    Drive_HelpFunctions_DllExport BOOL __stdcall VCM_GetDriveHandle(HANDLE CommunicationOrGatewayHandle, char* DeviceName, BYTE NodeId, HANDLE* pDriveHandle, DWORD* pErrorCode);
    Drive_HelpFunctions_DllExport BOOL __stdcall VCM_GetDeviceName(HANDLE DriveHandle, char* pDeviceName, WORD MaxStrSize, DWORD* pErrorCode);

/*************************************************************************************************************************************
* CONFIGURATION FUNCTIONS
*************************************************************************************************************************************/
//General
    Drive_Configuration_DllExport BOOL __stdcall VCM_ImportParameter(HANDLE DriveHandle, char *ParameterFileName, BOOL ShowDlg, BOOL ShowMsg, DWORD *pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_ExportParameter(HANDLE DriveHandle, char *ParameterFileName, char *BinaryFile, char *UserID, char *Comment, BOOL ShowDlg, BOOL ShowMsg, DWORD *pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetObject(HANDLE DriveHandle, WORD ObjectIndex, BYTE ObjectSubIndex, BYTE* pData, DWORD NbOfBytesToWrite, DWORD* pNbOfBytesWritten, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetObject(HANDLE DriveHandle, WORD ObjectIndex, BYTE ObjectSubIndex, BYTE* pData, DWORD NbOfBytesToRead, DWORD* pNbOfBytesRead, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_Restore(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_Store(HANDLE DriveHandle, DWORD* pErrorCode);

//Drive Configuration Functions
    //Motor
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetMotorType(HANDLE DriveHandle, WORD MotorType, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetDcMotorParameter(HANDLE DriveHandle, WORD NominalCurrent, WORD MaxOutputCurrent, WORD ThermalTimeConstant, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetEcMotorParameter(HANDLE DriveHandle, WORD NominalCurrent, WORD MaxOutputCurrent, WORD ThermalTimeConstant, BYTE NbOfPolePairs, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetMotorType(HANDLE DriveHandle, WORD* pMotorType, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetDcMotorParameter(HANDLE DriveHandle, WORD* pNominalCurrent, WORD* pMaxOutputCurrent, WORD* pThermalTimeConstant, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetEcMotorParameter(HANDLE DriveHandle, WORD* pNominalCurrent, WORD* pMaxOutputCurrent, WORD* pThermalTimeConstant, BYTE* pNbOfPolePairs, DWORD* pErrorCode);

    //Sensor
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetSensorType(HANDLE DriveHandle, WORD SensorType, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetIncEncoderParameter(HANDLE DriveHandle, DWORD EncoderResolution, BOOL InvertedPolarity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetHallSensorParameter(HANDLE DriveHandle, BOOL InvertedPolarity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetSsiAbsEncoderParameter(HANDLE DriveHandle, WORD DataRate, WORD NbOfMultiTurnDataBits, WORD NbOfSingleTurnDataBits, BOOL InvertedPolarity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetSensorType(HANDLE DriveHandle, WORD* pSensorType, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetIncEncoderParameter(HANDLE DriveHandle, DWORD* pEncoderResolution, BOOL* pInvertedPolarity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetHallSensorParameter(HANDLE DriveHandle, BOOL* pInvertedPolarity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetSsiAbsEncoderParameter(HANDLE DriveHandle, WORD* pDataRate, WORD* pNbOfMultiTurnDataBits, WORD* pNbOfSingleTurnDataBits, BOOL* pInvertedPolarity, DWORD* pErrorCode);

    //Safety
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetMaxFollowingError(HANDLE DriveHandle, DWORD MaxFollowingError, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetMaxFollowingError(HANDLE DriveHandle, DWORD* pMaxFollowingError, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetMaxProfileVelocity(HANDLE DriveHandle, DWORD MaxProfileVelocity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetMaxProfileVelocity(HANDLE DriveHandle, DWORD* pMaxProfileVelocity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetMaxAcceleration(HANDLE DriveHandle, DWORD MaxAcceleration, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetMaxAcceleration(HANDLE DriveHandle, DWORD* pMaxAcceleration, DWORD* pErrorCode);

    //Position Regulator
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetPositionRegulatorGain(HANDLE DriveHandle, WORD P, WORD I, WORD D, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetPositionRegulatorGain(HANDLE DriveHandle, WORD* pP, WORD* pI, WORD* pD, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetPositionRegulatorFeedForward(HANDLE DriveHandle, WORD VelocityFeedForward, WORD AccelerationFeedForward, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetPositionRegulatorFeedForward(HANDLE DriveHandle, WORD* pVelocityFeedForward, WORD* pAccelerationFeedForward, DWORD* pErrorCode);

    //Velocity Regulator
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetVelocityRegulatorGain(HANDLE DriveHandle, WORD P, WORD I, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetVelocityRegulatorGain(HANDLE DriveHandle, WORD* pP, WORD* pI, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetVelocityRegulatorFeedForward(HANDLE DriveHandle, WORD* pVelocityFeedForward, WORD* pAccelerationFeedForward, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetVelocityRegulatorFeedForward(HANDLE DriveHandle, WORD VelocityFeedForward, WORD AccelerationFeedForward, DWORD* pErrorCode);

    //Current Regulator
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetCurrentRegulatorGain(HANDLE DriveHandle, WORD P, WORD I, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetCurrentRegulatorGain(HANDLE DriveHandle, WORD* pP, WORD* pI, DWORD* pErrorCode);

    //Inputs/Outputs
    Drive_Configuration_DllExport BOOL __stdcall VCM_DigitalInputConfiguration(HANDLE DriveHandle, WORD DigitalInputNb, WORD Configuration, BOOL Mask, BOOL Polarity, BOOL ExecutionMask, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_DigitalOutputConfiguration(HANDLE DriveHandle, WORD DigitalOutputNb, WORD Configuration, BOOL State, BOOL Mask, BOOL Polarity, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_AnalogInputConfiguration(HANDLE DriveHandle, WORD AnalogInputNb, WORD Configuration, BOOL ExecutionMask, DWORD* pErrorCode);

    //Units
    Drive_Configuration_DllExport BOOL __stdcall VCM_SetVelocityUnits(HANDLE DriveHandle, BYTE VelDimension, char VelNotation, DWORD* pErrorCode);
    Drive_Configuration_DllExport BOOL __stdcall VCM_GetVelocityUnits(HANDLE DriveHandle, BYTE* pVelDimension, char* pVelNotation, DWORD* pErrorCode);

/*************************************************************************************************************************************
* OPERATION FUNCTIONS
*************************************************************************************************************************************/
//OperationMode
    Drive_Status_DllExport BOOL __stdcall VCM_SetOperationMode(HANDLE DriveHandle, __int8 OperationMode, DWORD* pErrorCode);
    Drive_Status_DllExport BOOL __stdcall VCM_GetOperationMode(HANDLE DriveHandle, __int8* pOperationMode, DWORD* pErrorCode);

//StateMachine
    Drive_StateMachine_DllExport BOOL __stdcall VCM_ResetDevice(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_SetState(HANDLE DriveHandle, WORD State, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_SetEnableState(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_SetDisableState(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_SetQuickStopState(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_ClearFault(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_GetState(HANDLE DriveHandle, WORD* pState, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_GetEnableState(HANDLE DriveHandle, BOOL* pIsEnabled, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_GetDisableState(HANDLE DriveHandle, BOOL* pIsDisabled, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_GetQuickStopState(HANDLE DriveHandle, BOOL* pIsQuickStopped, DWORD* pErrorCode);
    Drive_StateMachine_DllExport BOOL __stdcall VCM_GetFaultState(HANDLE DriveHandle, BOOL* pIsInFault, DWORD* pErrorCode);

//ErrorHandling
    Drive_ErrorHandling_DllExport BOOL __stdcall VCM_GetNbOfDeviceErrors(HANDLE DriveHandle, BYTE *pNbDeviceError, DWORD *pErrorCode);
    Drive_ErrorHandling_DllExport BOOL __stdcall VCM_GetDeviceErrorCode(HANDLE DriveHandle, BYTE ErrorNumber, DWORD *pDeviceErrorCode, DWORD *pErrorCode);
    Drive_ErrorHandling_DllExport BOOL __stdcall VCM_ClearDeviceErrors(HANDLE DriveHandle, DWORD *pErrorCode);

//Motion Info
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_GetMovementState(HANDLE DriveHandle, BOOL* pTargetReached, DWORD* pErrorCode);
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_GetPositionIs(HANDLE DriveHandle, long* pPositionIs, DWORD* pErrorCode);
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_GetVelocityIs(HANDLE DriveHandle, long* pVelocityIs, DWORD* pErrorCode);
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_GetVelocityIsAveraged(HANDLE DriveHandle, long* pVelocityIsAveraged, DWORD* pErrorCode);
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_GetCurrentIs(HANDLE DriveHandle, short* pCurrentIs, DWORD* pErrorCode);
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_GetCurrentIsAveraged(HANDLE DriveHandle, short* pCurrentIsAveraged, DWORD* pErrorCode);
    Drive_MotionInfo_DllExport BOOL __stdcall VCM_WaitForTargetReached(HANDLE DriveHandle, DWORD Timeout, DWORD* pErrorCode);

//Profile Position Mode
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_ActivateProfilePositionMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_SetPositionProfile(HANDLE DriveHandle, DWORD ProfileVelocity, DWORD ProfileAcceleration, DWORD ProfileDeceleration, DWORD* pErrorCode);
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_GetPositionProfile(HANDLE DriveHandle, DWORD* pProfileVelocity, DWORD* pProfileAcceleration, DWORD* pProfileDeceleration, DWORD* pErrorCode);
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_MoveToPosition(HANDLE DriveHandle, long TargetPosition, BOOL Absolute, BOOL Immediately, DWORD* pErrorCode);
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_GetTargetPosition(HANDLE DriveHandle, long* pTargetPosition, DWORD* pErrorCode);
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_HaltPositionMovement(HANDLE DriveHandle, DWORD* pErrorCode);

    //Advanced Functions
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_EnablePositionWindow(HANDLE DriveHandle, DWORD PositionWindow, WORD PositionWindowTime, DWORD* pErrorCode);
    Drive_ProfilePositionMode_DllExport BOOL __stdcall VCM_DisablePositionWindow(HANDLE DriveHandle, DWORD* pErrorCode);

//Profile Velocity Mode
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_ActivateProfileVelocityMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_SetVelocityProfile(HANDLE DriveHandle, DWORD ProfileAcceleration, DWORD ProfileDeceleration, DWORD* pErrorCode);
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_GetVelocityProfile(HANDLE DriveHandle, DWORD* pProfileAcceleration, DWORD* pProfileDeceleration, DWORD* pErrorCode);
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_MoveWithVelocity(HANDLE DriveHandle, long TargetVelocity, DWORD* pErrorCode);
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_GetTargetVelocity(HANDLE DriveHandle, long* pTargetVelocity, DWORD* pErrorCode);
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_HaltVelocityMovement(HANDLE DriveHandle, DWORD* pErrorCode);

    //Advanced Functions
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_EnableVelocityWindow(HANDLE DriveHandle, DWORD VelocityWindow, WORD VelocityWindowTime, DWORD* pErrorCode);
    Drive_ProfileVelocityMode_DllExport BOOL __stdcall VCM_DisableVelocityWindow(HANDLE DriveHandle, DWORD* pErrorCode);

//Homing Mode
    Drive_HomingMode_DllExport BOOL __stdcall VCM_ActivateHomingMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_SetHomingParameter(HANDLE DriveHandle, DWORD HomingAcceleration, DWORD SpeedSwitch, DWORD SpeedIndex, long HomeOffset, WORD CurrentTreshold, long HomePosition, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_GetHomingParameter(HANDLE DriveHandle, DWORD* pHomingAcceleration, DWORD* pSpeedSwitch, DWORD* pSpeedIndex, long* pHomeOffset, WORD* pCurrentTreshold, long* pHomePosition, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_FindHome(HANDLE DriveHandle, __int8 HomingMethod, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_StopHoming(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_DefinePosition(HANDLE DriveHandle, long HomePosition, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCS_WaitForHomingAttained(HANDLE DriveHandle, DWORD Timeout, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCS_GetHomingState(HANDLE DriveHandle, BOOL* pHomingAttained, BOOL* pHomingError, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_WaitForHomingAttained(HANDLE DriveHandle, DWORD Timeout, DWORD* pErrorCode);
    Drive_HomingMode_DllExport BOOL __stdcall VCM_GetHomingState(HANDLE DriveHandle, BOOL* pHomingAttained, BOOL* pHomingError, DWORD* pErrorCode);

//Interpolated Position Mode
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_ActivateInterpolatedPositionMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_SetIpmBufferParameter(HANDLE DriveHandle, WORD UnderflowWarningLimit, WORD OverflowWarningLimit, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_GetIpmBufferParameter(HANDLE DriveHandle, WORD* pUnderflowWarningLimit, WORD* pOverflowWarningLimit, DWORD* pMaxBufferSize, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_ClearIpmBuffer(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_GetFreeIpmBufferSize(HANDLE DriveHandle, DWORD* pBufferSize, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_AddPvtValueToIpmBuffer(HANDLE DriveHandle, long Position, long Velocity, BYTE Time, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_StartIpmTrajectory(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_StopIpmTrajectory(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_InterpolatedPositionMode_DllExport BOOL __stdcall VCM_GetIpmStatus(HANDLE DriveHandle, BOOL* pTrajectoryRunning, BOOL* pIsUnderflowWarning, BOOL* pIsOverflowWarning, BOOL* pIsVelocityWarning, BOOL* pIsAccelerationWarning, BOOL* pIsUnderflowError, BOOL* pIsOverflowError, BOOL* pIsVelocityError, BOOL* pIsAccelerationError, DWORD* pErrorCode);

//Position Mode
    Drive_PositionMode_DllExport BOOL __stdcall VCM_ActivatePositionMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_PositionMode_DllExport BOOL __stdcall VCM_SetPositionMust(HANDLE DriveHandle, long PositionMust, DWORD* pErrorCode);
    Drive_PositionMode_DllExport BOOL __stdcall VCM_GetPositionMust(HANDLE DriveHandle, long* pPositionMust, DWORD* pErrorCode);

    //Advanced Functions
    Drive_PositionMode_DllExport BOOL __stdcall VCM_ActivateAnalogPositionSetpoint(HANDLE DriveHandle, WORD AnalogInputNumber, float Scaling, long Offset, DWORD* pErrorCode);
    Drive_PositionMode_DllExport BOOL __stdcall VCM_DeactivateAnalogPositionSetpoint(HANDLE DriveHandle, WORD AnalogInputNumber, DWORD* pErrorCode);
    Drive_PositionMode_DllExport BOOL __stdcall VCM_EnableAnalogPositionSetpoint(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_PositionMode_DllExport BOOL __stdcall VCM_DisableAnalogPositionSetpoint(HANDLE DriveHandle, DWORD* pErrorCode);

//Velocity Mode
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_ActivateVelocityMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_SetVelocityMust(HANDLE DriveHandle, long VelocityMust, DWORD* pErrorCode);
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_GetVelocityMust(HANDLE DriveHandle, long* pVelocityMust, DWORD* pErrorCode);

    //Advanced Functions
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_ActivateAnalogVelocitySetpoint(HANDLE DriveHandle, WORD AnalogInputNumber, float Scaling, long Offset, DWORD* pErrorCode);
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_DeactivateAnalogVelocitySetpoint(HANDLE DriveHandle, WORD AnalogInputNumber, DWORD* pErrorCode);
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_EnableAnalogVelocitySetpoint(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_VelocityMode_DllExport BOOL __stdcall VCM_DisableAnalogVelocitySetpoint(HANDLE DriveHandle, DWORD* pErrorCode);

//Current Mode
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_ActivateCurrentMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_SetCurrentMust(HANDLE DriveHandle, short CurrentMust, DWORD* pErrorCode);
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_GetCurrentMust(HANDLE DriveHandle, short* pCurrentMust, DWORD* pErrorCode);

    //Advanced Functions
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_ActivateAnalogCurrentSetpoint(HANDLE DriveHandle, WORD AnalogInputNumber, float Scaling, short Offset, DWORD* pErrorCode);
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_DeactivateAnalogCurrentSetpoint(HANDLE DriveHandle, WORD AnalogInputNumber, DWORD* pErrorCode);
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_EnableAnalogCurrentSetpoint(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_CurrentMode_DllExport BOOL __stdcall VCM_DisableAnalogCurrentSetpoint(HANDLE DriveHandle, DWORD* pErrorCode);

//MasterEncoder Mode
    Drive_MasterEncoderMode_DllExport BOOL __stdcall VCM_ActivateMasterEncoderMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_MasterEncoderMode_DllExport BOOL __stdcall VCM_SetMasterEncoderParameter(HANDLE DriveHandle, WORD ScalingNumerator, WORD ScalingDenominator, BYTE Polarity, DWORD MaxVelocity, DWORD MaxAcceleration, DWORD* pErrorCode);
    Drive_MasterEncoderMode_DllExport BOOL __stdcall VCM_GetMasterEncoderParameter(HANDLE DriveHandle, WORD* pScalingNumerator, WORD* pScalingDenominator, BYTE* pPolarity, DWORD* pMaxVelocity, DWORD* pMaxAcceleration, DWORD* pErrorCode);

//StepDirection Mode
    Drive_StepDirectionMode_DllExport BOOL __stdcall VCM_ActivateStepDirectionMode(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_StepDirectionMode_DllExport BOOL __stdcall VCM_SetStepDirectionParameter(HANDLE DriveHandle, WORD ScalingNumerator, WORD ScalingDenominator, BYTE Polarity, DWORD MaxVelocity, DWORD MaxAcceleration, DWORD* pErrorCode);
    Drive_StepDirectionMode_DllExport BOOL __stdcall VCM_GetStepDirectionParameter(HANDLE DriveHandle, WORD* pScalingNumerator, WORD* pScalingDenominator, BYTE* pPolarity, DWORD* pMaxVelocity, DWORD* pMaxAcceleration, DWORD* pErrorCode);

//Inputs Outputs
    //General
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_GetAllDigitalInputs(HANDLE DriveHandle, WORD* pInputs, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_GetAllDigitalOutputs(HANDLE DriveHandle, WORD* pOutputs, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_SetAllDigitalOutputs(HANDLE DriveHandle, WORD Outputs, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_GetAnalogInput(HANDLE DriveHandle, WORD InputNumber, WORD* pAnalogValue, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_SetAnalogOutput(HANDLE DriveHandle, WORD OutputNumber, WORD AnalogValue, DWORD* pErrorCode);

    //Position Compare
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_SetPositionCompareParameter(HANDLE DriveHandle, BYTE OperationalMode, BYTE IntervalMode, BYTE DirectionDependency, WORD IntervalWidth, WORD IntervalRepetitions, WORD PulseWidth, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_GetPositionCompareParameter(HANDLE DriveHandle, BYTE* pOperationalMode, BYTE* pIntervalMode, BYTE* pDirectionDependency, WORD* pIntervalWidth, WORD* pIntervalRepetitions, WORD* pPulseWidth, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_ActivatePositionCompare(HANDLE DriveHandle, WORD DigitalOutputNumber, BOOL Polarity, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_DeactivatePositionCompare(HANDLE DriveHandle, WORD DigitalOutputNumber, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_EnablePositionCompare(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_DisablePositionCompare(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_SetPositionCompareReferencePosition(HANDLE DriveHandle, long ReferencePosition, DWORD* pErrorCode);

    //Position Marker
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_SetPositionMarkerParameter(HANDLE DriveHandle, BYTE PositionMarkerEdgeType, BYTE PositionMarkerMode, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_GetPositionMarkerParameter(HANDLE DriveHandle, BYTE* pPositionMarkerEdgeType, BYTE* pPositionMarkerMode, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_ActivatePositionMarker(HANDLE DriveHandle, WORD DigitalInputNumber, BOOL Polarity, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_DeactivatePositionMarker(HANDLE DriveHandle, WORD DigitalInputNumber, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_ReadPositionMarkerCounter(HANDLE DriveHandle, WORD* pCount, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_ReadPositionMarkerCapturedPosition(HANDLE DriveHandle, WORD CounterIndex, long* pCapturedPosition, DWORD* pErrorCode);
    Drive_InputsOutputs_DllExport BOOL __stdcall VCM_ResetPositionMarkerCounter(HANDLE DriveHandle, DWORD* pErrorCode);

/*************************************************************************************************************************************
* DATA RECORDING FUNCTIONS
*************************************************************************************************************************************/
//DataRecorder Setup
    Drive_DataRecording_DllExport BOOL __stdcall VCM_SetRecorderParameter(HANDLE DriveHandle, WORD SamplingPeriod, WORD NbOfPrecedingSamples, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_GetRecorderParameter(HANDLE DriveHandle, WORD* pSamplingPeriod, WORD* pNbOfPrecedingSamples, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_EnableTrigger(HANDLE DriveHandle, BYTE TriggerType, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_DisableAllTriggers(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ActivateChannel(HANDLE DriveHandle, BYTE ChannelNumber, WORD ObjectIndex, BYTE ObjectSubIndex, BYTE ObjectSize, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_DeactivateAllChannels(HANDLE DriveHandle, DWORD* pErrorCode);

//DataRecorder Status
    Drive_DataRecording_DllExport BOOL __stdcall VCM_StartRecorder(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_StopRecorder(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ForceTrigger(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_IsRecorderRunning(HANDLE DriveHandle, BOOL* pRunning, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_IsRecorderTriggered(HANDLE DriveHandle, BOOL* pTriggered, DWORD* pErrorCode);

//DataRecorder Data
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ReadChannelVectorSize(HANDLE DriveHandle, DWORD* pVectorSize, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ReadChannelDataVector(HANDLE DriveHandle, BYTE ChannelNumber, BYTE* pDataVector, DWORD VectorSize, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ShowChannelDataDlg(HANDLE DriveHandle, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ExportChannelDataToFile(HANDLE DriveHandle, char* FileName, DWORD* pErrorCode);

//Advanced Functions
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ReadDataBuffer(HANDLE DriveHandle, BYTE* pDataBuffer, DWORD BufferSizeToRead, DWORD* pBufferSizeRead, WORD* pVectorStartOffset, WORD* pMaxNbOfSamples, WORD* pNbOfRecordedSamples, DWORD* pErrorCode);
    Drive_DataRecording_DllExport BOOL __stdcall VCM_ExtractChannelDataVector(HANDLE DriveHandle, BYTE ChannelNumber, BYTE* pDataBuffer, DWORD BufferSize, BYTE* pDataVector, DWORD VectorSize, WORD VectorStartOffset, WORD MaxNbOfSamples, WORD NbOfRecordedSamples, DWORD* pErrorCode);

/*************************************************************************************************************************************
* TYPE DEFINITIONS
*************************************************************************************************************************************/
//Communication
    //Dialog Mode
    const int DDM_PROGRESS_DLG                      = 0;
    const int DDM_PROGRESS_AND_CONFIRM_DLG          = 1;
    const int DDM_CONFIRM_DLG                       = 2;
    const int DDM_NO_DLG                            = 3;

//Configuration
    //MotorType
    const WORD MT_DC_MOTOR                          = 1;
    const WORD MT_EC_SINUS_COMMUTATED_MOTOR         = 10;
    const WORD MT_EC_BLOCK_COMMUTATED_MOTOR         = 11;

    //SensorType
    const WORD ST_UNKNOWN                           = 0;
    const WORD ST_INC_ENCODER_3CHANNEL              = 1;
    const WORD ST_INC_ENCODER_2CHANNEL              = 2;
    const WORD ST_HALL_SENSORS                      = 3;
    const WORD ST_SSI_ABS_ENCODER_BINARY            = 4;
    const WORD ST_SSI_ABS_ENCODER_GREY              = 5;

//In- and outputs
    //Digital input configuration
    const WORD DIC_NEGATIVE_LIMIT_SWITCH            = 0;
    const WORD DIC_POSITIVE_LIMIT_SWITCH            = 1;
    const WORD DIC_HOME_SWITCH                      = 2;
    const WORD DIC_POSITION_MARKER                  = 3;
    const WORD DIC_DRIVE_ENABLE                     = 4;
    const WORD DIC_QUICK_STOP                       = 5;
    const WORD DIC_GENERAL_PURPOSE_J                = 6;
    const WORD DIC_GENERAL_PURPOSE_I                = 7;
    const WORD DIC_GENERAL_PURPOSE_H                = 8;
    const WORD DIC_GENERAL_PURPOSE_G                = 9;
    const WORD DIC_GENERAL_PURPOSE_F                = 10;
    const WORD DIC_GENERAL_PURPOSE_E                = 11;
    const WORD DIC_GENERAL_PURPOSE_D                = 12;
    const WORD DIC_GENERAL_PURPOSE_C                = 13;
    const WORD DIC_GENERAL_PURPOSE_B                = 14;
    const WORD DIC_GENERAL_PURPOSE_A                = 15;

    //Digital output configuration
    const WORD DOC_READY_FAULT                      = 0;
    const WORD DOC_POSITION_COMPARE                 = 1;
    const WORD DOC_GENERAL_PURPOSE_H                = 8;
    const WORD DOC_GENERAL_PURPOSE_G                = 9;
    const WORD DOC_GENERAL_PURPOSE_F                = 10;
    const WORD DOC_GENERAL_PURPOSE_E                = 11;
    const WORD DOC_GENERAL_PURPOSE_D                = 12;
    const WORD DOC_GENERAL_PURPOSE_C                = 13;
    const WORD DOC_GENERAL_PURPOSE_B                = 14;
    const WORD DOC_GENERAL_PURPOSE_A                = 15;

    //Analog input configuration
    const WORD AIC_ANALOG_CURRENT_SETPOINT          = 0;
    const WORD AIC_ANALOG_VELOCITY_SETPOINT         = 1;
    const WORD AIC_ANALOG_POSITION_SETPOINT         = 2;

//Units
    //VelocityDimension
    const BYTE VD_RPM                               = 0xA4;

    //VelocityNotation
    const char VN_STANDARD                          = 0;
    const char VN_DECI                              = -1;
    const char VN_CENTI                             = -2;
    const char VN_MILLI                             = -3;

//Operational mode
    const __int8 OMD_PROFILE_POSITION_MODE          = 1;
    const __int8 OMD_PROFILE_VELOCITY_MODE          = 3;
    const __int8 OMD_HOMING_MODE                    = 6;
    const __int8 OMD_INTERPOLATED_POSITION_MODE     = 7;
    const __int8 OMD_POSITION_MODE                  = -1;
    const __int8 OMD_VELOCITY_MODE                  = -2;
    const __int8 OMD_CURRENT_MODE                   = -3;
    const __int8 OMD_MASTER_ENCODER_MODE            = -5;
    const __int8 OMD_STEP_DIRECTION_MODE            = -6;

//States
    const WORD ST_DISABLED                          = 0;
    const WORD ST_ENABLED                           = 1;
    const WORD ST_QUICKSTOP                         = 2;
    const WORD ST_FAULT                             = 3;

//Homing mode
    //Homing method
    const __int8 HM_ACTUAL_POSITION                               = 35;
    const __int8 HM_NEGATIVE_LIMIT_SWITCH                         = 17;
    const __int8 HM_NEGATIVE_LIMIT_SWITCH_AND_INDEX               = 1;
    const __int8 HM_POSITIVE_LIMIT_SWITCH                         = 18;
    const __int8 HM_POSITIVE_LIMIT_SWITCH_AND_INDEX               = 2;
    const __int8 HM_HOME_SWITCH_POSITIVE_SPEED                    = 23;
    const __int8 HM_HOME_SWITCH_POSITIVE_SPEED_AND_INDEX          = 7;
    const __int8 HM_HOME_SWITCH_NEGATIVE_SPEED                    = 27;
    const __int8 HM_HOME_SWITCH_NEGATIVE_SPEED_AND_INDEX          = 11;
    const __int8 HM_CURRENT_THRESHOLD_POSITIVE_SPEED              = -3;
    const __int8 HM_CURRENT_THRESHOLD_POSITIVE_SPEED_AND_INDEX    = -1;
    const __int8 HM_CURRENT_THRESHOLD_NEGATIVE_SPEED              = -4;
    const __int8 HM_CURRENT_THRESHOLD_NEGATIVE_SPEED_AND_INDEX    = -2;
    const __int8 HM_INDEX_POSITIVE_SPEED                          = 34;
    const __int8 HM_INDEX_NEGATIVE_SPEED                          = 33;

//Input Output PositionMarker
    //PositionMarkerEdgeType
    const BYTE PET_BOTH_EDGES                       = 0;
    const BYTE PET_RISING_EDGE                      = 1;
    const BYTE PET_FALLING_EDGE                     = 2;

    //PositionMarkerMode
    const BYTE PM_CONTINUOUS                        = 0;
    const BYTE PM_SINGLE                            = 1;
    const BYTE PM_MULTIPLE                          = 2;

//Input Output PositionCompare
    //PositionCompareOperationalMode
    const BYTE PCO_SINGLE_POSITION_MODE             = 0;
    const BYTE PCO_POSITION_SEQUENCE_MODE           = 1;

    //PositionCompareIntervalMode
    const BYTE PCI_NEGATIVE_DIR_TO_REFPOS           = 0;
    const BYTE PCI_POSITIVE_DIR_TO_REFPOS           = 1;
    const BYTE PCI_BOTH_DIR_TO_REFPOS               = 2;

    //PositionCompareDirectionDependency
    const BYTE PCD_MOTOR_DIRECTION_NEGATIVE         = 0;
    const BYTE PCD_MOTOR_DIRECTION_POSITIVE         = 1;
    const BYTE PCD_MOTOR_DIRECTION_BOTH             = 2;

//Data recorder
    //Trigger type
    const WORD DR_MOVEMENT_START_TRIGGER            = 1;    //bit 1
    const WORD DR_ERROR_TRIGGER                     = 2;    //bit 2
    const WORD DR_DIGITAL_INPUT_TRIGGER             = 4;    //bit 3
    const WORD DR_MOVEMENT_END_TRIGGER              = 8;    //bit 4

#endif //_H_WIN32_EPOSPCMD_DRIVE

