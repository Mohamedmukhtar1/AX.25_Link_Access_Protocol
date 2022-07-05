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
	Frame->StartFlag = 0x7E;
	Frame->ControlField = Control;
	Frame->Protocol_ID = PID;
	for(i=0; i<=5; i++)
	{
		Frame->DestinAddress.C[i] = Destin[i];
		Frame->SourceAddress.C[i] = Source[i];
	}
	Frame->DestinAddress.SSID = Destin[i];
	Frame->SourceAddress.SSID = Source[i];
}

