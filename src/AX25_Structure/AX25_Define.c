/*
 * AX25_Define.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "AX25_Interface.h"

void AXStructed_vFrame(AX25_Header *FrameHeader, u8 *Buffer)
{
	u8 i =0;
	u8 j =0;
	if(FrameHeader != NULL)
	{
		FrameHeader->StartFlag = Buffer[0];
		for(i=1; i<=7; i++,j++)
		{
			if(j<6)
			{
				FrameHeader->DestinAddress.C[i-1] = Buffer[i];
			}
			else{
				FrameHeader->DestinAddress.SSID =Buffer[i];
			}
		}
		for(i=8; i<=14; i++,j++)
		{
			if(j<13)
			{
				FrameHeader->SourceAddress.C[i-8] = Buffer[i];
			}
			else{
				FrameHeader->SourceAddress.SSID =Buffer[i];
			}
		}
		j++;
		FrameHeader->ControlField = Buffer[j];
		j++;
		FrameHeader->Protocol_ID = Buffer[j];
	}
	else{/*ERROR*/}
}
