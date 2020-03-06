
#include <string>
//#include <tchar.h>
#include <Windows.h>
//#include <chrono>
//#include <iomanip>
//#include <chrono>
//#include <math.h>
//#include <ostream>
//#include <ctime>
#include <fstream>
#include <iostream>
#include "EposPCmd_Comm.h"
//#include "EposPCmd_Plc.h"
#include "EposPCmd_Drive.h"
#include <chrono>

using namespace std;
HANDLE pDriveHandle;
//char pDeviceName[8] = "EPOS2 P";
char protocol[16] = "MAXON SERIAL V2";
DWORD ErrorCode=0;
char ErrorInfo[255];
WORD MaxStrSize = 1000;
//DWORD DeviceErrorCode = 0;
BYTE ErrorNumber = 1;
char GatewayDeviceName[] = "EPOS2 P";
DWORD ErrorCodeValue =1;
HANDLE GatewayHandle;
HANDLE CommunicationHandle;
WORD MotorType;
char GatewayProtocolStackName[] = "CANopen";
DWORD Baudrate = 1000000;
DWORD Timeout = 500;
char ProtocolStackName[] = "MAXON SERIAL V2";
char InterfaceName[] = "USB";
char PortName[]="USB0";
int DialogMode = 1; //2;//3;
BOOL StartOfSelection = TRUE;
//char GatewayNameSel;
char pDriveDeviceNameSel;
BOOL pEndOfSelection;
//char GatewayName[]="EPOS2 P";
//HANDLE PlcHandle;
char DriveDeviceNameSel;
char DeviceName[]="EPOS2";    //////
WORD NodeID = 1;
BYTE NodeId = 1;
WORD State =0;
__int8 Mode = 3;
//HANDLE pDriveHandleis;
//char pDeviceName;       //////
WORD SizeName = 100;
WORD InputNumber=1;
WORD AnalogValue;
long TargetVelocity = 2000;
/*WORD SamplingPeriod= 2;
WORD NbOfPrecedingSamples= 11;*/
/*BYTE ChannelNumber = 1;
WORD ObjectIndex;
BYTE ObjectSubIndex;
BYTE ObjectSize;*/
long VelocityMust = 500;
WORD AnalogInputNumber = 1;
float Scaling= 1000;
long Offset= 0;
/*WORD ScalingNumerator=500;
WORD ScalingDenominator=500;
BYTE Polarity = 1;
DWORD MaxVelocity=1000;
DWORD MaxAcceleration=1000;*/
/*BYTE TriggerType = 1;*/
DWORD pVectorSize;
/*BYTE pDataVector;
BOOL pRunning;
BOOL pTriggered;*/
WORD OutputNumber;
long pVelocityIs;
DWORD ProfileVelocity = 500;
DWORD ProfileAcceleration=500;
DWORD ProfileDeceleration=500;
/*WORD Configuration = 1;
WORD AnalogInputNb ;
BOOL ExecutionMask=1;*/
long TargetPosition = 2000;
BOOL Absolute = FALSE;
BOOL Immediately = TRUE;
DWORD PositionWindow;
WORD PositionWindowTime;
WORD SamplingPeriod = 2;
WORD NbOfPrecedingSamples = 1;
BYTE TriggerType = 1;
BYTE ChannelNumber = 1;
WORD ObjectIndex;
BYTE ObjectSubIndex;
BYTE ObjectSize;
BOOL pRunning = 1;
BOOL pTriggered = 1;
BYTE pDataVector;
DWORD VectorSize;
char FileName[] = "C:\\Users\\Aniket\\Desktop\\abcd\\e.txt";
BYTE RemoteNetworkId = 1;

int main()
{	
	//auto start = chrono::steady_clock::now();
	/*CommunicationHandle = (VCM_OpenCommunicationDlg(&ErrorCode));*/
	CommunicationHandle = (VCM_OpenCommunication(ProtocolStackName, InterfaceName, PortName, &ErrorCode));
	if (CommunicationHandle == 0)
	{	
		
		cout << "Opencommunicationfail\n";
	}
	else
	{

		cout << "Opencommunicationsuccess\n";
		
	};
	auto start = chrono::steady_clock::now();
	//auto start = chrono::steady_clock::now();
	VCM_GetProtocolStackSettings(CommunicationHandle, &Baudrate, &Timeout, &ErrorCode);
		cout << "Baudrate:" << Baudrate << ".\n";
		cout << "Timeout:" << Timeout << ".\n";

	/*if (VCM_FindCommunicationSettings(&pDriveHandle, &pDeviceName, ProtocolStackName, InterfaceName, PortName, SizeName, &CommunicationHandle, DialogMode, &ErrorCode))
	{
		cout << "success";
		cout << "DriveHandle" << pDriveHandle << ".\n";
		cout << "ProtocolStackName" << ProtocolStackName << ".\n"f;
		cout << "devicename" << DeviceName << ".\n";
		cout << "Interfacename" << InterfaceName << ".\n";
		cout << "PortName" << PortName << ".\n"; 
	}
	else
	{
		cout << "fails";	
	}*/
		
	GatewayHandle = VCM_OpenGateway(GatewayProtocolStackName, GatewayDeviceName, CommunicationHandle, &ErrorCode);
	/*GatewayHandle = VCM_OpenGatewayDlg(CommunicationHandle, &ErrorCode);
	if (GatewayHandle == 0)
	{
		cout << "Fail\n";
	}
	else
	{
		cout << "Success\n";
		//cout << "DRRR" << DriveHandle << ".\n";
	};*/
	VCM_SetGatewaySettings(GatewayHandle, NodeId, RemoteNetworkId, &ErrorCode);
	/*pDriveHandle = VCM_OpenDriveDlg(GatewayHandle, &ErrorCode);*/
	pDriveHandle = VCM_OpenDrive(DeviceName, GatewayHandle, &ErrorCode);
	if (pDriveHandle == 0)
	{
		cout << "Fail\n";
	}
	else
	{
		cout << "Success pDriveHandle\n";
		//cout << "DRRR" << DriveHandle << ".\n";
	};
	VCM_SetDriveSettings(pDriveHandle, NodeId, &ErrorCode);
	if(VCM_GetDriveDeviceNameSelection(StartOfSelection, &pDriveDeviceNameSel, MaxStrSize, &pEndOfSelection, &ErrorCode));
	{
		cout << "pDriveDeviceNameSel::" << pDriveDeviceNameSel << "\n";
	}
	/*auto end = chrono::steady_clock::now();
	cout << "Delay is : "
		<< chrono::duration_cast<chrono::milliseconds>(end-start).count()
		<< " ms" << endl;*/
	//auto start = chrono::steady_clock::now();
	/*if (VCM_FindDriveCommunicationSettings(&pDriveHandle, GatewayHandle, &pDeviceName, SizeName, DialogMode, &ErrorCode))
	{
		cout << "Success\n";
		cout << "devicename" << pDeviceName << ".\n";
	}
	else
	{
		cout << "Fail\n";
		
	}*/
	/*if (VCM_GetDriveHandle(GatewayHandle, DeviceName, NodeId, &pDriveHandle, &ErrorCode))
	{
		cout << "DriveHandle" << pDriveHandle << ".\n";
	}
	else
	{
		cout << "Fail\n";
	};
	if (VCM_GetDeviceName(pDriveHandle, &pDeviceName, MaxStrSize, &ErrorCode))
	{
		cout << "devicename is:" << pDeviceName << ".\n";
	}
	else
	{
		cout << "getdvname fail \n";
	};
	if (VCM_SetDriveSettings(pDriveHandle, NodeId, &ErrorCode))
	{
		cout << "Success\n";
	}
	else
	{
		cout << "Fail\n";
	}
	if (VCM_GetDriveSettings(pDriveHandle, &NodeId, &ErrorCode))
	{
		cout << "Success\n";
	}
	else
	{
		cout << "Fail\n";
	}*/
	/*if (VCM_FindDriveCommunicationSettings(&pDriveHandle, GatewayHandle, &pDeviceName, SizeName, DialogMode, &ErrorCode))
	{
		cout << "Success\n";
		cout << "devicename" << pDeviceName << ".\n";
	}
	else
	{
		cout << "Fail\n";

	}*/
	if (VCM_SetEnableState(pDriveHandle, &ErrorCode))
	{
		cout << "Set Enable Works\n";
		auto end = chrono::steady_clock::now();
		cout << "Delay is : "
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< " ms" << endl;
	}
	else
	{
		cout << "Set Enable Does not work";

	}
	if (VCM_SetOperationMode(pDriveHandle, Mode, &ErrorCode))
	{
		cout << "OperationModeWorks";
	}
	/*if (VCM_SetRecorderParameter(pDriveHandle, SamplingPeriod, NbOfPrecedingSamples, &ErrorCode));
	{
		cout << "SetRecorderParameters are Set\n";
	}
	if (VCM_EnableTrigger(pDriveHandle, TriggerType, &ErrorCode))
	{
		cout << "Trigger is Enabled\n";
	}
	if (VCM_ActivateChannel(pDriveHandle, ChannelNumber, ObjectIndex, ObjectSubIndex, ObjectSize, &ErrorCode))
	{
		cout << "Channels are activated  "<<ChannelNumber<<".\n";
		cout << "ObjectIndex" << ObjectIndex << ".\n";
		cout << "ObjectSubIndex" << ObjectSubIndex << ".\n";
	}
	if (VCM_StartRecorder(pDriveHandle, &ErrorCode))
	{
		cout << "StartRecording\n";
	}
	if (VCM_IsRecorderRunning(pDriveHandle, &pRunning, &ErrorCode))
	{
		cout << "Running\n";
	}
	if (VCM_IsRecorderTriggered(pDriveHandle, &pTriggered, &ErrorCode))
	{
		cout << "Triggered\n";
	}
	if (VCM_ActivateProfilePositionMode(pDriveHandle, &ErrorCode))
	{
		if (VCM_SetPositionProfile(pDriveHandle, ProfileVelocity, ProfileAcceleration, ProfileDeceleration, &ErrorCode))
		{
			cout << "ActivateProfilePositionworks\n";
		}
	}
	else
	{
		cout << "ActivateProfilePositiondoesnotwork";
	}
	if (VCM_MoveToPosition(pDriveHandle, TargetPosition, Absolute, Immediately, &ErrorCode))
	{
		cout << "MovestotargetPosition" << TargetPosition << ".\n";
	}
	
	if (VCM_GetTargetPosition(pDriveHandle, &TargetPosition, &ErrorCode))
	{
		cout << "TargetPosition" << TargetPosition << ".\n";
	}
	if (VCM_ReadChannelVectorSize(pDriveHandle, &pVectorSize, &ErrorCode))
	{
		cout << "ReadChannelWorks\n";
	}
	if (VCM_ReadChannelDataVector(pDriveHandle, ChannelNumber, &pDataVector, VectorSize, &ErrorCode))
	{
		cout << "ChannelDATAVectorWorks\n";
	}
	else
	{
		cout << "ChannelDataVectorFails\n";
	}

	if (VCM_ShowChannelDataDlg(pDriveHandle, &ErrorCode))
	{
		cout << "ChannelDATADLGOPENS\n";
	}
	else
	{
		cout << "ChannelDATADLGOPENSFails\n";
	}
	if(VCM_ExportChannelDataToFile(pDriveHandle, FileName, &ErrorCode))
	{
		cout << "DataExportedtoChannel\n";
	}
	else
	{
		cout << "DataExportingFail";
	}
	if (VCM_StopRecorder(pDriveHandle, &ErrorCode))
	{
		cout << "Recording Stop\n";
	}*/

	

	/*if (VCM_SetOperationMode(pDriveHandle, Mode, &ErrorCode))
	{
		cout << "Success\n";
	}
	else
	{
		cout << "It fails";
	};*/

	/*if (VCM_ActivateVelocityMode(pDriveHandle, &ErrorCode))
	{
		cout << "Activate Velocity Mode Success\n";
		//VCM_MoveWithVelocity(pDriveHandle,TargetVelocity, &ErrorCode);
		//VCM_GetTargetVelocity(pDriveHandle, &TargetVelocity, &ErrorCode);
		//VCM_GetVelocityIs(pDriveHandle, &pVelocityIs, &ErrorCode);
		//cout << "Velocityis" << pVelocityIs << ".\n";
		
	}
	else
	{
		cout << "Its not working\n";
	}

	if (VCM_GetAnalogInput(pDriveHandle, InputNumber, &AnalogValue, &ErrorCode))
	{
		cout << "GetAnalogInputWorking\n";
		cout << "AnalogValue" << AnalogValue << ".\n";
		cout << "InputNumber" << InputNumber << ".\n";
	}
	if (VCM_SetAnalogOutput(pDriveHandle,OutputNumber,AnalogValue, &ErrorCode))
	{
		cout << "SetAnalogOutputWorks";
		cout << "Output Number" << OutputNumber << ".\n";
	}
	else
	{
		cout << "SetAnalogOutputStops\n";
	}
	*/

	if (VCM_StartRecorder(pDriveHandle, &ErrorCode))
	{
		cout << "StartRecording\n";
	}
	if (VCM_ReadChannelVectorSize(pDriveHandle, &pVectorSize, &ErrorCode))
	{
		cout << "ReadChannelWorks\n";
	}
	if (VCM_ReadChannelDataVector(pDriveHandle, ChannelNumber, &pDataVector, VectorSize, &ErrorCode))
	{
		cout << "ChannelDATAVectorWorks\n";
	}
	else
	{
		cout << "ChannelDataVectorFails\n";
	}
	/*if (VCM_ActivateChannel(pDriveHandle, ChannelNumber, ObjectIndex, ObjectSubIndex, ObjectSize, &ErrorCode))
	{
		cout << "Channels are activated  " << ChannelNumber << ".\n";
		cout << "ObjectIndex" << ObjectIndex << ".\n";
		cout << "ObjectSubIndex" << ObjectSubIndex << ".\n";*/
	/*if (VCM_ShowChannelDataDlg(pDriveHandle, &ErrorCode))
	{
		cout << "ChannelDATADLGOPENS\n";
	}
	else
	{
		cout << "ChannelDATADLGOPENSFails\n";
	}*/
	if (VCM_EnableAnalogVelocitySetpoint(pDriveHandle, &ErrorCode))
	{
		cout << "EnableAnalogVelocitySetpoint Success\n";
	}
	else
	{
		cout << "EnableAnalogvelocity Fails";
	}

	if (VCM_ActivateVelocityMode(pDriveHandle, &ErrorCode))
	{
		cout << "Activate Velocity Mode Success\n";
		/*auto end = chrono::steady_clock::now();
		cout << "Elapsed time in milliseconds : "
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< " ms" << endl;*/
	}
	else
	{
		cout << "Its not working\n";
	}

	if (VCM_SetEnableState(pDriveHandle, &ErrorCode))
	{
		cout << "Set Enable Works\n";
	}
	else
	{
		cout << "Set Enable Does not work";
	}

	/*if (VCM_SetVelocityMust(pDriveHandle, VelocityMust, &ErrorCode));
	{
		cout << "VelocityMust" << VelocityMust << ".\n";
	}

	VCM_GetVelocityIs(pDriveHandle, &pVelocityIs, &ErrorCode);
	cout << "Velocityis" << pVelocityIs << ".\n";*/

	if (VCM_ActivateAnalogVelocitySetpoint(pDriveHandle, AnalogInputNumber, Scaling, Offset, &ErrorCode))
	{
		cout << "AnalogInputNumber" << AnalogInputNumber << ".\n";
		cout << "Scaling" << Scaling << ".\n";
		cout << "Offset" << Offset << ".\n";
	}
	else
	{ 
		cout << "AnalogInputNumber" << AnalogInputNumber << ".\n";
		cout << "Scaling" << Scaling << ".\n";
		cout << "Offset" << Offset << ".\n";
	}
	if (VCM_ExportChannelDataToFile(pDriveHandle, FileName, &ErrorCode))
	{
		cout << "DataExportedtoChannel\n";
	}
	else
	{
		cout << "DataExportingFail";
	}
	/*if (VCM_StopRecorder(pDriveHandle, &ErrorCode))
	{
		cout << "Recording Stop\n";
	}*/
	

	return 0;
};




