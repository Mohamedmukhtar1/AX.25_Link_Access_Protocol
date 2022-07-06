/*
 * AX25_Define.c
 *
 *  Created on: Jul 5, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "AX25_Interface.h"

u8 AXDefineFlags_u8Validation(u8 *Buffer, u8 Lu8ActualLength)
{
	s8 Ls16FrameFlag =0;
	if((0x7E == Buffer[0]))
	{
		Ls16FrameFlag++;
		if(0x7E == Buffer[Lu8ActualLength-1])
		{
			Ls16FrameFlag++;
		}else{	}
	}
	else{
		Ls16FrameFlag =9;
	}
	return Ls16FrameFlag;
}

u8 AXDestinationAddress_u8Validation(AX25_Header *FrameHeader, u8 *DestinAddress)
{
	u8 i =0;
	u8 Lu8CheckOkay =0;
	if(FrameHeader != NULL)
	{
		if(FrameHeader->HeaderAccess.DestinAddress.SSID == DestinAddress[6])
		{
			for(i=0; i<=5; i++)
			{
				if(FrameHeader->HeaderAccess.DestinAddress.C[i] == DestinAddress[i])
				{
					Lu8CheckOkay =1;
				}
				else{
					Lu8CheckOkay =0;
					break;
				}
			}
		}
	}
	else{/*ERROR*/}
	return Lu8CheckOkay;
}

u8 AXSourceAddress_u8Validation(AX25_Header *FrameHeader, u8 *SourceAddress)
{
	u8 i =0;
	u8 Lu8CheckOkay =0;
	if(FrameHeader != NULL)
	{
		if(FrameHeader->HeaderAccess.SourceAddress.SSID == SourceAddress[6])
		{
			for(i=0; i<=5; i++)
			{
				if(FrameHeader->HeaderAccess.SourceAddress.C[i] == SourceAddress[i])
				{
					Lu8CheckOkay =1;
				}
				else{
					Lu8CheckOkay =0;
					break;
				}
			}
		}
	}
	else{/*ERROR*/}
	return Lu8CheckOkay;
}
