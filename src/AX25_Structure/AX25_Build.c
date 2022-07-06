/*
 * AX25_Build.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "AX25_Interface.h"

AX25_Header *AXAllocate_axheaderFrame(void)
{
	AX25_Header *ptr_Allocator = (AX25_Header *)calloc(1 , sizeof(AX25_Header));
	if(NULL == ptr_Allocator)
	{
		ptr_Allocator = NULL; // Killing Memory Allocation Fetal Errors
	}
	else{
		// System Manged to allocate space in the .Heap
	}
	return ptr_Allocator;
}

void AXDelete_vAllocatedFrame(AX25_Header *Frame)
{
	free(Frame);
}

void AXConfig_vFrame(AX25_Header *Frame, u8 *Destin, u8 *Source, u8 Control, u8 PID)
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

void AXStructe_vFrame(AX25_Header *FrameHeader, u8 *Buffer)
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
