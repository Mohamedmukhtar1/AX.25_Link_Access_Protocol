/*
 * AX25_Build.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "AX25_Interface.h"

u8 IframeControlData[14]={0X01,0X06,0x07,0x08,0xC3,0xC4,0xCA,0xC8,0xCC,0xCD,0xCE,0xCF,0xF0,0xFF};
u8 SframeControlData[4] ={0x01,0x05,0x09,0x0D};
u8 UframeControlData[12] ={0x2F,0x6F,0x43,0xAF,0xBF,0xE3,0xF3,0x03,0x13,0x73,0x97,0x1F};

AX25_Header_ut *AXAllocate_axheaderFrame(void)
{
	AX25_Header_ut *ptr_Allocator = (AX25_Header_ut *)calloc(1 , sizeof(AX25_Header_ut));
	if(NULL == ptr_Allocator)
	{
		ptr_Allocator = NULL; // Killing Memory Allocation Fetal Errors
	}
	else{
		// System Manged to allocate space in the .Heap
	}
	return ptr_Allocator;
}

void AXDelete_vAllocatedFrame(AX25_Header_ut *Frame)
{
	free(Frame);
}

void AXConfig_vFrame(AX25_Header_ut *Frame, u8 *Destin, u8 *Source, u8 Control, u8 PID)
{
	u8 i=0;
	Frame->HeaderAccess.StartFlag = 0x7E;
	Frame->HeaderAccess.ControlField = Control;
	Frame->HeaderAccess.Protocol_ID = PID;
	for(i=0; i<=5; i++)
	{
		Frame->HeaderAccess.DestinAddress.C[i] = Destin[i];
		Frame->HeaderAccess.SourceAddress.C[i] = Source[i];
	}
	Frame->HeaderAccess.DestinAddress.SSID = Destin[i];
	Frame->HeaderAccess.SourceAddress.SSID = Source[i];
}

void AXStructe_vFrame(AX25_Header_ut *FrameHeader, u8 *Buffer)
{
	u8 i =0;
	if(FrameHeader != NULL)
	{
		for(i=0; i<=16; i++)
		{
			FrameHeader->BufferAccess[i] = Buffer[i];
		}
	}
	else{/*ERROR*/}
}

//void AXStructe_vFrame(AX25_Header_ut *FrameHeader, u8 *Buffer)
