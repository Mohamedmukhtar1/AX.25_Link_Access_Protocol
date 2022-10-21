/*
 * AX25_Execute.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "AX25_Interface.h"

IframeControl_ut IframeControl;
SframeControl_ut SframeControl;
UframeControl_ut UframeControl;


u8 UframeSABM_CMD         =0x2F; // [CMD]
u8 UframeSABME_CMD        =0x6F; // [CMD]
u8 UframeDISC_CMD         =0x43; // [CMD]
u8 UframeXID_CMD          =0xAF; // [CMD]
u8 UframeXID_RES          =0xBF; // [RES]
u8 UframeTEST_CMD         =0xE3; // [CMD]
u8 UframeTEST_RES         =0xF3; // [RES]
u8 UframeUI_CMD           =0x03; // [CMD]
u8 UframeUI_RES           =0x13; // [RES]
u8 UframeUACK_RES         =0x73; // [RES]
u8 UframeFRMR_RES         =0x97; // [RES]
u8 UframeDM_RES           =0x1F; // [RES]


///////////////////////////////////////////<<<<<   GID   >>>>>  <<<<    SGID   >>>>*/
u8 STM32F427_TestInterface[8]    		= {0x00,0x11,0x11,0x11, 0x11,0x11,0x00,0x11};
u8 STM32F427_GetTime[8]          		= {0x00,0x11,0x11,0x11, 0x11,0x11,0x00,0x22};
u8 STM32F427_GetPowerRegister[8] 		= {0x00,0x11,0x11,0x11, 0x11,0x11,0x00,0x33};

/**    Flash Memory Commands _____________________________________________________________________
///////////////////////////////////////////<<<<<   GID   >>>>>  <<<<    SGID   >>>>*/
u8 Flash_TestInterface[8] 				= {0x00,0x22,0x22,0x22, 0x11,0x11,0x00,0x11};

/**    M-RAM Commands ____________________________________________________________________________
///////////////////////////////////////////<<<<<   GID   >>>>>  <<<<    SGID   >>>>*/
u8 TEST_M_RAM_INTERFACE[8] 				= {0x00,0x33,0x33,0x33, 0x11,0x11,0x00,0x11};

/**    Temperature Sensor Commands _______________________________________________________________
///////////////////////////////////////////<<<<<   GID   >>>>>  <<<<    SGID   >>>>*/
u8 TEST_T_Sensor_INTERFACE[8] 			= {0x00,0x44,0x44,0x44, 0x11,0x11,0x00,0x11};
u8 GET_STM32F427_Temprature[8] 			= {0x00,0x44,0x44,0x44, 0x11,0x11,0x00,0x22};

/**    Current Sensor Commands __________________________________________________________________
///////////////////////////////////////////<<<<<   GID   >>>>>  <<<<    SGID   >>>>*/
u8 TEST_C_Sensor_INTERFACE[8] 			= {0x00,0x55,0x55,0x55, 0x11,0x11,0x00,0x11};

void AXSystemControlConfiguration(void)
{
	IframeControl.ControlAccess.ISO8208X25PLP  =0X01;
	IframeControl.ControlAccess.COMTCPIPPCK    =0X06;
	IframeControl.ControlAccess.UNCOMTCPIPPCK  =0x07;
	IframeControl.ControlAccess.SEGFRAG        =0x08;
	IframeControl.ControlAccess.TEXDATAPROTOCOL=0xC3;
	IframeControl.ControlAccess.LINKQPROTOCOL  =0xC4;
	IframeControl.ControlAccess.APPLETALK      =0xCA;
	IframeControl.ControlAccess.APPLETALKARP   =0xC8;
	IframeControl.ControlAccess.APRAINPROTOCOL =0xCC;
	IframeControl.ControlAccess.APRAADDRESO    =0xCD;
	IframeControl.ControlAccess.FLEXNET        =0xCE;
	IframeControl.ControlAccess.NETROM         =0xCF;
	IframeControl.ControlAccess.NOL3PROTOCOL   =0xF0;
	IframeControl.ControlAccess.ESCC           =0xFF;





}

void AXExecute_vFrameAddress(AX25Information_ut *ExeInformation)
{
	if(0b1111 == ExeInformation->InformationAccess.UniteDevice)
	{
		printf("OKKKKKKKKKKKKKKKKKKKKKKK UniteDevice\n");
		if(0 != ExeInformation->InformationAccess.SourceDevice)
		{
			printf("OKKKKKKKKKKKKKKKKKKKKKKK SourceDevice\n");

		}
		else{
			//Undefined Device is ON CALL !!!
		}
	}
	else{
		printf("Nooooooooooooooooooooooo\n");
		//Neglect Exeution the unit isn't ON CALL !!!
	}
}
